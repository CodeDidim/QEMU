/*
 *  Model Change of CPU Run-State by Wire
 *
 *  Copyright (c) 2019 Xilinx Inc
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */
#include "qemu/osdep.h"
#include "qemu/main-loop.h"
#include "qemu/timer.h"
#include "qemu/log.h"
#include "sysemu/tcg.h"
#include "hw/irq.h"

#include "cpu.h"
#include "hw/core/cpu-exec-gpio.h"

static void cpu_exec_ack(CPUState *cpu, run_on_cpu_data arg)
{
    /* Do nothing; just to get vCPU out of tb-exec loop */
}

static void cpu_exec_pin_update(CPUState *cpu, bool reset_pin)
{
    bool val = reset_pin || cpu->halt_pin || cpu->arch_halt_pin;

    if (val) {
        cpu_interrupt(cpu, CPU_INTERRUPT_HALT);
    } else {
        cpu_reset_interrupt(cpu, CPU_INTERRUPT_HALT);
        cpu_interrupt(cpu, CPU_INTERRUPT_EXITTB);
    }

    cpu->exception_index = -1;
}

static void cpu_exec_pin_sync(CPUState *cpu, bool reset_pin)
{
    /*
     * Wire actors external to the targeted vCPU must wait for
     * the wire-action to be visible to the vCPU to ensure that
     * the vCPU has abandoned all staled translation buffers.
     *
     * The possibility that the target vCPU may not be ready to
     * process async-work makes the wait non-trivial, because:
     * 1. run_on_cpu() API does not provide timeout, and
     * 2. async_run_on_cpu() API does not provide cancel, thus
     *    could lead to memory leak if the vCPU is indeed not
     *    ready to process async work.
     *
     * The solution is to initially poll for kick acknowledge,
     * and switching to use run_on_cpu() after vCPU can indeed
     * acknowledge kicking.
     */
    static uint64_t can_run_on_cpu;

    uint64_t cpu_mask;
    int cpu_index;

    cpu_exec_pin_update(cpu, reset_pin);

    if (cpu == current_cpu) {
        return; /* self-acting */
    }

    cpu_index = cpu->cpu_index;
    assert(cpu_index >= 0 && cpu_index < 64);

    cpu_mask = (uint64_t)1 << cpu_index;

    if ((can_run_on_cpu & cpu_mask) != 0) {
        run_on_cpu(cpu, cpu_exec_ack, RUN_ON_CPU_NULL);
    } else {
        qemu_cpu_kick(cpu);
        can_run_on_cpu |= cpu_mask;
    }
}

static bool ensure_iothread_lock(void)
{
    bool is_unlocked = !qemu_mutex_iothread_locked();

    if (is_unlocked) {
        qemu_mutex_lock_iothread();
    }

    return is_unlocked;
}

static void deref_iothread_lock(bool was_unlocked)
{
    if (was_unlocked) {
        qemu_mutex_unlock_iothread();
    }
}

#ifdef TARGET_ARM
static void cpu_arch_update_halt(CPUState *cs)
{
    ARMCPU *cpu = ARM_CPU(cs);

    cpu->power_state = cs->halt_pin ? PSCI_OFF : PSCI_ON;
}

static void cpu_reset_pin_activated(CPUState *cs)
{
    ARMCPU *arm_cpu = ARM_CPU(cs);

    arm_cpu->is_in_wfi = false;
    qemu_set_irq(arm_cpu->wfi, 0);
}
#else
static void cpu_arch_update_halt(CPUState *cs)
{

}

static inline void cpu_reset_pin_activated(CPUState *cs)
{
    /* A stub */
}
#endif

void cpu_reset_gpio(void *opaque, int irq, int level)
{
    CPUState *cpu = CPU(opaque);
    bool iolock;
    static int lock_count;

    iolock = ensure_iothread_lock();

    g_assert(lock_count == 0);
    lock_count++;
    if (level == cpu->reset_pin) {
        goto done;
    }

    /*
     * On hardware when the reset pin is asserted the CPU resets and stays
     * in reset until the pin is lowered. As we don't have a reset state, we
     * do it a little differently. If the reset_pin is being set high then
     * cpu_halt_update() will halt the CPU, but it isn't reset. Once the pin
     * is lowered we reset the CPU and then let it run, as long as no halt pin
     * is set. This avoids us having to double reset, which can cause issues
     * with MTTCG.
     *
     * On reset assert, must update, to io-domain, all those outputs
     * derived from the vCPU state, to satisfy assumption of CPU I/O
     * devices' assumption.
     *
     * Also, order of pin-state update is asymmetrical, depending on
     * assert of deassert.
     */

    if (level) {
        cpu->reset_pin = true;
        cpu_exec_pin_sync(cpu, true);
        cpu_reset_pin_activated(cpu);
    } else {
        cpu_reset(cpu);
        cpu_exec_pin_sync(cpu, false);
        cpu->reset_pin = false;
    }

done:
    lock_count--;
    deref_iothread_lock(iolock);
}

void cpu_halt_gpio(void *opaque, int irq, int level)
{
    CPUState *cpu = CPU(opaque);
    bool iolock;

    iolock = ensure_iothread_lock();

    cpu->halt_pin = level;
    cpu_arch_update_halt(cpu);
    cpu_exec_pin_update(cpu, cpu->reset_pin); /* TBD: _sync not working */

    deref_iothread_lock(iolock);
}

void cpu_halt_update(CPUState *cpu)
{
    bool iolock;

    iolock = ensure_iothread_lock();

    cpu_exec_pin_update(cpu, cpu->reset_pin); /* TBD: _sync not working */

    deref_iothread_lock(iolock);
}
