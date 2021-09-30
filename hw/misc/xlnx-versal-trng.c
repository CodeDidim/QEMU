/*
 * QEMU model of the TRNG True Random Number Generator
 *
 * Copyright (c) 2017-2020 Xilinx Inc.
 *
 * Partially utogenerated by xregqemu.py 2020-02-05.
 * Written by Edgar E. Iglesias <edgar.iglesias@xilinx.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "qemu/osdep.h"
#include "hw/sysbus.h"
#include "hw/register.h"
#include "qemu/bitops.h"
#include "qemu/log.h"
#include "migration/vmstate.h"
#include "hw/qdev-properties.h"
#include "hw/irq.h"

#ifndef XILINX_TRNG_ERR_DEBUG
#define XILINX_TRNG_ERR_DEBUG 0
#endif

#define TYPE_XILINX_TRNG "xlnx.versal-trng"

#define XILINX_TRNG(obj) \
     OBJECT_CHECK(TRNG, (obj), TYPE_XILINX_TRNG)

REG32(INT_CTRL, 0x0)
    FIELD(INT_CTRL, CERTF_RST, 5, 1)
    FIELD(INT_CTRL, DTF_RST, 4, 1)
    FIELD(INT_CTRL, DONE_RST, 3, 1)
    FIELD(INT_CTRL, CERTF_EN, 2, 1)
    FIELD(INT_CTRL, DTF_EN, 1, 1)
    FIELD(INT_CTRL, DONE_EN, 0, 1)
REG32(STATUS, 0x4)
    FIELD(STATUS, QCNT, 9, 3)
    FIELD(STATUS, EAT, 4, 5)
    FIELD(STATUS, CERTF, 3, 1)
    FIELD(STATUS, QERTF, 2, 1)
    FIELD(STATUS, DFT, 1, 1)
    FIELD(STATUS, DONE, 0, 1)
REG32(CTRL, 0x8)
    FIELD(CTRL, PERSODISABLE, 10, 1)
    FIELD(CTRL, SINGLEGENMODE, 9, 1)
    FIELD(CTRL, EUMODE, 8, 1)
    FIELD(CTRL, PRNGMODE, 7, 1)
    FIELD(CTRL, TSTMODE, 6, 1)
    FIELD(CTRL, PRNGSTART, 5, 1)
    FIELD(CTRL, EATAU, 4, 1)
    FIELD(CTRL, PRNGXS, 3, 1)
    FIELD(CTRL, TRSSEN, 2, 1)
    FIELD(CTRL, QERTUEN, 1, 1)
    FIELD(CTRL, PRNGSRST, 0, 1)
REG32(CTRL_2, 0xc)
    FIELD(CTRL_2, REPCOUNTTESTCUTOFF, 8, 9)
    FIELD(CTRL_2, RESERVED_7_5, 5, 3)
    FIELD(CTRL_2, DIT, 0, 5)
REG32(CTRL_3, 0x10)
    FIELD(CTRL_3, ADAPTPROPTESTCUTOFF, 8, 10)
    FIELD(CTRL_3, DLEN, 0, 8)
REG32(CTRL_4, 0x14)
    FIELD(CTRL_4, SINGLEBITRAW, 0, 1)
REG32(EXT_SEED_0, 0x40)
REG32(EXT_SEED_1, 0x44)
REG32(EXT_SEED_2, 0x48)
REG32(EXT_SEED_3, 0x4c)
REG32(EXT_SEED_4, 0x50)
REG32(EXT_SEED_5, 0x54)
REG32(EXT_SEED_6, 0x58)
REG32(EXT_SEED_7, 0x5c)
REG32(EXT_SEED_8, 0x60)
REG32(EXT_SEED_9, 0x64)
REG32(EXT_SEED_10, 0x68)
REG32(EXT_SEED_11, 0x6c)
REG32(PER_STRNG_0, 0x80)
REG32(PER_STRNG_1, 0x84)
REG32(PER_STRNG_2, 0x88)
REG32(PER_STRNG_3, 0x8c)
REG32(PER_STRNG_4, 0x90)
REG32(PER_STRNG_5, 0x94)
REG32(PER_STRNG_6, 0x98)
REG32(PER_STRNG_7, 0x9c)
REG32(PER_STRNG_8, 0xa0)
REG32(PER_STRNG_9, 0xa4)
REG32(PER_STRNG_10, 0xa8)
REG32(PER_STRNG_11, 0xac)
REG32(CORE_OUTPUT, 0xc0)
REG32(RESET, 0xd0)
    FIELD(RESET, VAL, 0, 1)
REG32(OSC_EN, 0xd4)
    FIELD(OSC_EN, VAL, 0, 1)
REG32(TRNG_ISR, 0xe0)
    FIELD(TRNG_ISR, SLVERR, 1, 1)
    FIELD(TRNG_ISR, CORE_INT, 0, 1)
REG32(TRNG_IMR, 0xe4)
    FIELD(TRNG_IMR, SLVERR, 1, 1)
    FIELD(TRNG_IMR, CORE_INT, 0, 1)
REG32(TRNG_IER, 0xe8)
    FIELD(TRNG_IER, SLVERR, 1, 1)
    FIELD(TRNG_IER, CORE_INT, 0, 1)
REG32(TRNG_IDR, 0xec)
    FIELD(TRNG_IDR, SLVERR, 1, 1)
    FIELD(TRNG_IDR, CORE_INT, 0, 1)
REG32(SLV_ERR_CTRL, 0xf0)
    FIELD(SLV_ERR_CTRL, ENABLE, 0, 1)

#define R_MAX (R_SLV_ERR_CTRL + 1)

typedef struct TRNG {
    SysBusDevice parent_obj;
    MemoryRegion iomem;
    qemu_irq irq_int_imr;

    /* Specs say we have 256bits but there's only max 7 words
     * to be indicated in the status reg.  */
    uint32_t out[7];
    uint32_t count;
    unsigned int seed;

    uint64_t tst_seed[2];

    uint32_t regs[R_MAX];
    RegisterInfo regs_info[R_MAX];
} TRNG;

static void trng_imr_update_irq(TRNG *s)
{
    bool pending = s->regs[R_TRNG_ISR] & ~s->regs[R_TRNG_IMR];
    qemu_set_irq(s->irq_int_imr, pending);
}

static void trng_isr_postw(RegisterInfo *reg, uint64_t val64)
{
    TRNG *s = XILINX_TRNG(reg->opaque);
    trng_imr_update_irq(s);
}

static uint64_t trng_ier_prew(RegisterInfo *reg, uint64_t val64)
{
    TRNG *s = XILINX_TRNG(reg->opaque);
    uint32_t val = val64;

    s->regs[R_TRNG_IMR] &= ~val;
    trng_imr_update_irq(s);
    return 0;
}

static void trng_reset(DeviceState *dev)
{
    TRNG *s = XILINX_TRNG(dev);
    unsigned int i;

    for (i = 0; i < ARRAY_SIZE(s->regs_info); ++i) {
        register_reset(&s->regs_info[i]);
    }

    trng_imr_update_irq(s);
}

static void trng_int_ctrl_postw(RegisterInfo *reg, uint64_t val64)
{
    TRNG *s = XILINX_TRNG(reg->opaque);
    uint32_t mask;

    /* DONE and DFT are aligned.  */
    mask = val64 >> 3;
    mask &= 3;
    s->regs[R_STATUS] &= ~mask;

    /* CERTF is off by one bit.  */
    mask = val64 >> 2;
    mask &= 1 << 3;
    s->regs[R_STATUS] &= ~mask;

    trng_imr_update_irq(s);
}

static void trng_done(TRNG *s)
{
    ARRAY_FIELD_DP32(s->regs, STATUS, DONE, true);
    trng_imr_update_irq(s);
}

static inline void trng_reseed(TRNG *s, bool ext)
{
    bool pers_disabled = ARRAY_FIELD_EX32(s->regs, CTRL, PERSODISABLE);
    bool tst = ARRAY_FIELD_EX32(s->regs, CTRL, TSTMODE);
    int i;

    /* Accumulate the seed regs and the personalization string.  */
    s->seed = 0;

    for (i = 0; !pers_disabled && i < 12; i++) {
        s->seed += s->regs[R_PER_STRNG_0 + i];
    }

    if (ext) {
        for (i = 0; i < 12; i++) {
            s->seed += s->regs[R_EXT_SEED_0 + i];
        }
    }

    if (tst) {
            uint64_t tst;

            /* Fold the 64-bit test seed into 32 bits.  */
            tst = s->tst_seed[0] + s->tst_seed[1];
            tst = tst ^ (tst >> 32);
            tst &= UINT32_MAX;

            /* Add it into the mix.  */
            s->seed += (uint32_t) tst;
    }

    srand(s->seed);
}

static inline void trng_regen(TRNG *s)
{
    int i;

    /* Re-gen.  */
    for (i = 0; i < ARRAY_SIZE(s->out); i++) {
        s->out[i] = rand();
    }

    s->count = ARRAY_SIZE(s->out);
    ARRAY_FIELD_DP32(s->regs, STATUS, QCNT, s->count);
}

static void trng_ctrl_postw(RegisterInfo *reg, uint64_t val64)
{
    TRNG *s = XILINX_TRNG(reg->opaque);
    bool start = FIELD_EX32(val64, CTRL, PRNGSTART);
    bool mode = FIELD_EX32(val64, CTRL, PRNGMODE);
    bool ext = FIELD_EX32(val64, CTRL, PRNGXS);
    bool rst = FIELD_EX32(val64, CTRL, PRNGSRST);

    if (rst) {
        trng_reset(DEVICE(s));
        return;
    }

    if (start) {
        if (mode) {
            trng_regen(s);
        } else {
            trng_reseed(s, ext);
        }
        trng_done(s);
    }
}

static void trng_ctrl4_postw(RegisterInfo *reg, uint64_t val64)
{
    TRNG *s = XILINX_TRNG(reg->opaque);

    /* Shift in a single bit.  */
    s->tst_seed[1] <<= 1;
    s->tst_seed[1] |= s->tst_seed[0] >> 63;
    s->tst_seed[0] <<= 1;
    s->tst_seed[0] |= val64 & 1;
}

static uint64_t trng_core_out_postr(RegisterInfo *reg, uint64_t val)
{
    TRNG *s = XILINX_TRNG(reg->opaque);
    uint32_t r = s->out[0];
    bool oneshot = ARRAY_FIELD_EX32(s->regs, CTRL, SINGLEGENMODE);
    bool start = ARRAY_FIELD_EX32(s->regs, CTRL, PRNGSTART);
    bool rst = ARRAY_FIELD_EX32(s->regs, CTRL, PRNGSRST);

    if (rst) {
        qemu_log_mask(LOG_GUEST_ERROR, "trng: reading while in reset!\n");
        return 0xbad;
    }

    if (s->count == 0) {
        qemu_log_mask(LOG_GUEST_ERROR, "trng: reading when unavailable!\n");
        return 0xbad;
    }

    /* Shift.  */
    memmove(&s->out[0], &s->out[1], sizeof s->out - sizeof s->out[0]);
    s->count--;
    ARRAY_FIELD_DP32(s->regs, STATUS, QCNT, s->count);

    /* Automatic mode regenerates new entropy when half the output reg
     * is empty.  */
    if (!oneshot && start && s->count <= 3) {
        trng_regen(s);
    }
    return r;
}

static uint64_t trng_idr_prew(RegisterInfo *reg, uint64_t val64)
{
    TRNG *s = XILINX_TRNG(reg->opaque);
    uint32_t val = val64;

    s->regs[R_TRNG_IMR] |= val;
    trng_imr_update_irq(s);
    return 0;
}

static RegisterAccessInfo trng_regs_info[] = {
    {   .name = "INT_CTRL",  .addr = A_INT_CTRL,
        .post_write = trng_int_ctrl_postw,
    },{ .name = "STATUS",  .addr = A_STATUS,
        .ro = 0xfff,
    },{ .name = "CTRL",  .addr = A_CTRL,
        .post_write = trng_ctrl_postw,
    },{ .name = "CTRL_2",  .addr = A_CTRL_2,
        .reset = 0x210c,
    },{ .name = "CTRL_3",  .addr = A_CTRL_3,
        .reset = 0x26f09,
    },{ .name = "CTRL_4",  .addr = A_CTRL_4,
        .post_write = trng_ctrl4_postw,
    },{ .name = "EXT_SEED_0",  .addr = A_EXT_SEED_0,
    },{ .name = "EXT_SEED_1",  .addr = A_EXT_SEED_1,
    },{ .name = "EXT_SEED_2",  .addr = A_EXT_SEED_2,
    },{ .name = "EXT_SEED_3",  .addr = A_EXT_SEED_3,
    },{ .name = "EXT_SEED_4",  .addr = A_EXT_SEED_4,
    },{ .name = "EXT_SEED_5",  .addr = A_EXT_SEED_5,
    },{ .name = "EXT_SEED_6",  .addr = A_EXT_SEED_6,
    },{ .name = "EXT_SEED_7",  .addr = A_EXT_SEED_7,
    },{ .name = "EXT_SEED_8",  .addr = A_EXT_SEED_8,
    },{ .name = "EXT_SEED_9",  .addr = A_EXT_SEED_9,
    },{ .name = "EXT_SEED_10",  .addr = A_EXT_SEED_10,
    },{ .name = "EXT_SEED_11",  .addr = A_EXT_SEED_11,
    },{ .name = "PER_STRNG_0",  .addr = A_PER_STRNG_0,
    },{ .name = "PER_STRNG_1",  .addr = A_PER_STRNG_1,
    },{ .name = "PER_STRNG_2",  .addr = A_PER_STRNG_2,
    },{ .name = "PER_STRNG_3",  .addr = A_PER_STRNG_3,
    },{ .name = "PER_STRNG_4",  .addr = A_PER_STRNG_4,
    },{ .name = "PER_STRNG_5",  .addr = A_PER_STRNG_5,
    },{ .name = "PER_STRNG_6",  .addr = A_PER_STRNG_6,
    },{ .name = "PER_STRNG_7",  .addr = A_PER_STRNG_7,
    },{ .name = "PER_STRNG_8",  .addr = A_PER_STRNG_8,
    },{ .name = "PER_STRNG_9",  .addr = A_PER_STRNG_9,
    },{ .name = "PER_STRNG_10",  .addr = A_PER_STRNG_10,
    },{ .name = "PER_STRNG_11",  .addr = A_PER_STRNG_11,
    },{ .name = "CORE_OUTPUT",  .addr = A_CORE_OUTPUT,
        .ro = 0xffffffff,
        .post_read = trng_core_out_postr,
    },{ .name = "RESET",  .addr = A_RESET,
        .reset = 0x1,
    },{ .name = "OSC_EN",  .addr = A_OSC_EN,
    },{ .name = "TRNG_ISR",  .addr = A_TRNG_ISR,
        .w1c = 0x3,
        .post_write = trng_isr_postw,
    },{ .name = "TRNG_IMR",  .addr = A_TRNG_IMR,
        .reset = 0x3,
        .ro = 0x3,
    },{ .name = "TRNG_IER",  .addr = A_TRNG_IER,
        .pre_write = trng_ier_prew,
    },{ .name = "TRNG_IDR",  .addr = A_TRNG_IDR,
        .pre_write = trng_idr_prew,
    },{ .name = "SLV_ERR_CTRL",  .addr = A_SLV_ERR_CTRL,
    }
};

static const MemoryRegionOps trng_ops = {
    .read = register_read_memory,
    .write = register_write_memory,
    .endianness = DEVICE_LITTLE_ENDIAN,
    .valid = {
        .min_access_size = 4,
        .max_access_size = 4,
    },
};

static void trng_realize(DeviceState *dev, Error **errp)
{
    /* Delete this if not necessary */
}

static void trng_init(Object *obj)
{
    TRNG *s = XILINX_TRNG(obj);
    SysBusDevice *sbd = SYS_BUS_DEVICE(obj);
    RegisterInfoArray *reg_array;

    memory_region_init(&s->iomem, obj, TYPE_XILINX_TRNG, R_MAX * 4);

    reg_array =
        register_init_block32(DEVICE(obj), trng_regs_info,
                              ARRAY_SIZE(trng_regs_info),
                              s->regs_info, s->regs,
                              &trng_ops,
                              XILINX_TRNG_ERR_DEBUG,
                              R_MAX * 4);
    memory_region_add_subregion(&s->iomem, 0x0, &reg_array->mem);
    sysbus_init_mmio(sbd, &s->iomem);
    sysbus_init_irq(sbd, &s->irq_int_imr);
}

static const VMStateDescription vmstate_trng = {
    .name = TYPE_XILINX_TRNG,
    .version_id = 1,
    .minimum_version_id = 1,
    .minimum_version_id_old = 1,
    .fields = (VMStateField[]) {
        VMSTATE_UINT32_ARRAY(out, TRNG, 7),
        VMSTATE_UINT32_ARRAY(regs, TRNG, R_MAX),
        VMSTATE_END_OF_LIST(),
    }
};

static void trng_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = trng_reset;
    dc->realize = trng_realize;
    dc->vmsd = &vmstate_trng;
}

static const TypeInfo trng_info = {
    .name          = TYPE_XILINX_TRNG,
    .parent        = TYPE_SYS_BUS_DEVICE,
    .instance_size = sizeof(TRNG),
    .class_init    = trng_class_init,
    .instance_init = trng_init,
};

static void trng_register_types(void)
{
    type_register_static(&trng_info);
}

type_init(trng_register_types)
