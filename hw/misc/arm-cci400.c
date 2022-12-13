/*
 * QEMU model of the CCI400, the CCI-400 Cache Coherent Interconnect.
 *
 * Copyright (c) 2015 Xilinx Inc.
 *
 * Partially autogenerated by xregqemu.py 2015-10-30.
 * Written by Edgar E. Iglesias
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
#include "qapi/error.h"
#include "migration/vmstate.h"
#include "hw/qdev-properties.h"
#include "hw/fdt_generic_util.h"

#ifndef ARM_CCI400_ERR_DEBUG
#define ARM_CCI400_ERR_DEBUG 0
#endif

#define TYPE_ARM_CCI400 "arm,cci-400"
#define TYPE_ARM_CCI400_IOMMU_MEMORY_REGION "arm,cci-400-iommu-memory-region"

#define ARM_CCI400(obj) \
     OBJECT_CHECK(CCI, (obj), TYPE_ARM_CCI400)

REG32(CONTROL_OVERRIDE_REGISTER, 0x0)
    FIELD(CONTROL_OVERRIDE_REGISTER, DISABLE_RETRY_REDUCTION_BUFFERS, 5, 1)
    FIELD(CONTROL_OVERRIDE_REGISTER, DISABLE_PRIORITY_PROMOTION, 4, 1)
    FIELD(CONTROL_OVERRIDE_REGISTER, TERMINATE_BARRIERS, 3, 1)
    FIELD(CONTROL_OVERRIDE_REGISTER, DISABLE_SPECULATIVE_FETCHES, 2, 1)
    FIELD(CONTROL_OVERRIDE_REGISTER, DVM_MESSAGE_DISABLE, 1, 1)
    FIELD(CONTROL_OVERRIDE_REGISTER, SNOOP_DISABLE, 0, 1)
REG32(SPECULATION_CONTROL_REGISTER, 0x4)
    FIELD(SPECULATION_CONTROL_REGISTER, DISABLE_SPECULATIVE_FETCHES_S4, 20, 1)
    FIELD(SPECULATION_CONTROL_REGISTER, DISABLE_SPECULATIVE_FETCHES_S3, 19, 1)
    FIELD(SPECULATION_CONTROL_REGISTER, DISABLE_SPECULATIVE_FETCHES_S2, 18, 1)
    FIELD(SPECULATION_CONTROL_REGISTER, DISABLE_SPECULATIVE_FETCHES_S1, 17, 1)
    FIELD(SPECULATION_CONTROL_REGISTER, DISABLE_SPECULATIVE_FETCHES_S0, 16, 1)
    FIELD(SPECULATION_CONTROL_REGISTER, DISABLE_SPECULATIVE_FETCHES_M2, 2, 1)
    FIELD(SPECULATION_CONTROL_REGISTER, DISABLE_SPECULATIVE_FETCHES_M1, 1, 1)
    FIELD(SPECULATION_CONTROL_REGISTER, DISABLE_SPECULATIVE_FETCHES_M0, 0, 1)
REG32(SECURE_ACCESS_REGISTER, 0x8)
    FIELD(SECURE_ACCESS_REGISTER, SECURE_ACCESS_CONTROL, 0, 1)
REG32(STATUS_REGISTER, 0xc)
    FIELD(STATUS_REGISTER, CCI_STATUS, 0, 1)
REG32(IMPRECISE_ERROR_REGISTER, 0x10)
    FIELD(IMPRECISE_ERROR_REGISTER, IMP_ERR_S4, 20, 1)
    FIELD(IMPRECISE_ERROR_REGISTER, IMP_ERR_S3, 19, 1)
    FIELD(IMPRECISE_ERROR_REGISTER, IMP_ERR_S2, 18, 1)
    FIELD(IMPRECISE_ERROR_REGISTER, IMP_ERR_S1, 17, 1)
    FIELD(IMPRECISE_ERROR_REGISTER, IMP_ERR_S0, 16, 1)
    FIELD(IMPRECISE_ERROR_REGISTER, IMP_ERR_M2, 2, 1)
    FIELD(IMPRECISE_ERROR_REGISTER, IMP_ERR_M1, 1, 1)
    FIELD(IMPRECISE_ERROR_REGISTER, IMP_ERR_M0, 0, 1)
REG32(PERFORMANCE_MONITOR_CONTROL_REGISTER, 0x100)
    FIELD(PERFORMANCE_MONITOR_CONTROL_REGISTER, PMU_COUNT_NUM, 11, 5)
    FIELD(PERFORMANCE_MONITOR_CONTROL_REGISTER, DP, 5, 1)
    FIELD(PERFORMANCE_MONITOR_CONTROL_REGISTER, EX, 4, 1)
    FIELD(PERFORMANCE_MONITOR_CONTROL_REGISTER, CCD, 3, 1)
    FIELD(PERFORMANCE_MONITOR_CONTROL_REGISTER, CCR, 2, 1)
    FIELD(PERFORMANCE_MONITOR_CONTROL_REGISTER, RST, 1, 1)
    FIELD(PERFORMANCE_MONITOR_CONTROL_REGISTER, CEN, 0, 1)
REG32(PERIPHERAL_ID4, 0xfd0)
    FIELD(PERIPHERAL_ID4, PERIPH_ID_4, 0, 8)
REG32(PERIPHERAL_ID5, 0xfd4)
    FIELD(PERIPHERAL_ID5, PERIPH_ID_5, 0, 8)
REG32(PERIPHERAL_ID6, 0xfd8)
    FIELD(PERIPHERAL_ID6, PERIPH_ID_6, 0, 8)
REG32(PERIPHERAL_ID7, 0xfdc)
    FIELD(PERIPHERAL_ID7, PERIPH_ID_7, 0, 8)
REG32(PERIPHERAL_ID0, 0xfe0)
    FIELD(PERIPHERAL_ID0, PERIPHERAL_ID0, 0, 8)
REG32(PERIPHERAL_ID1, 0xfe4)
    FIELD(PERIPHERAL_ID1, PERIPHERAL_ID1, 0, 8)
REG32(PERIPHERAL_ID2, 0xfe8)
    FIELD(PERIPHERAL_ID2, PERIPH_ID_2, 0, 8)
REG32(PERIPHERAL_ID3, 0xfec)
    FIELD(PERIPHERAL_ID3, REV_AND, 4, 4)
    FIELD(PERIPHERAL_ID3, CUST_MOD_NUM, 0, 4)
REG32(COMPONENT_ID0, 0xff0)
    FIELD(COMPONENT_ID0, COMPONENT_ID0, 0, 8)
REG32(COMPONENT_ID1, 0xff4)
    FIELD(COMPONENT_ID1, COMPONENT_ID1, 0, 8)
REG32(COMPONENT_ID2, 0xff8)
    FIELD(COMPONENT_ID2, COMPONENT_ID2, 0, 8)
REG32(COMPONENT_ID3, 0xffc)
    FIELD(COMPONENT_ID3, COMPONENT_ID3, 0, 8)
REG32(SNOOP_CONTROL_REGISTER_S0, 0x1000)
    FIELD(SNOOP_CONTROL_REGISTER_S0, SUPPORT_DVMS, 31, 1)
    FIELD(SNOOP_CONTROL_REGISTER_S0, SUPPORT_SNOOPS, 30, 1)
    FIELD(SNOOP_CONTROL_REGISTER_S0, ENABLE_DVMS, 1, 1)
REG32(SHAREABLE_OVERRIDE_REGISTER_S0, 0x1004)
    FIELD(SHAREABLE_OVERRIDE_REGISTER_S0, AXDOMAIN_OVERRIDE, 0, 2)
REG32(READ_QOS_OVERRIDE_REGISTER_S0, 0x1100)
    FIELD(READ_QOS_OVERRIDE_REGISTER_S0, ARQOS_OVERRIDE_READBACK, 8, 4)
    FIELD(READ_QOS_OVERRIDE_REGISTER_S0, ARQOS_VALUE, 0, 4)
REG32(WRITE_QOS_OVERRIDE_REGISTER_S0, 0x1104)
    FIELD(WRITE_QOS_OVERRIDE_REGISTER_S0, AWQOS_OVERRIDE_READBACK, 8, 4)
    FIELD(WRITE_QOS_OVERRIDE_REGISTER_S0, AWQOS_VALUE, 0, 4)
REG32(QOS_CONTROL_REGISTER_S0, 0x110c)
    FIELD(QOS_CONTROL_REGISTER_S0, QOS_REGULATION_DISABLED, 31, 1)
    FIELD(QOS_CONTROL_REGISTER_S0, BANDWIDTH_REGULATION_MODE, 21, 1)
    FIELD(QOS_CONTROL_REGISTER_S0, ARQOS_REGULATION_MODE, 20, 1)
    FIELD(QOS_CONTROL_REGISTER_S0, AWQOS_REGULATION_MODE, 16, 1)
    FIELD(QOS_CONTROL_REGISTER_S0, AR_OT_REGULATION, 3, 1)
    FIELD(QOS_CONTROL_REGISTER_S0, AW_OT_REGULATION, 2, 1)
    FIELD(QOS_CONTROL_REGISTER_S0, ARQOS_REGULATION, 1, 1)
    FIELD(QOS_CONTROL_REGISTER_S0, AWQOS_REGULATION, 0, 1)
REG32(MAX_OT_REGISTER_S0, 0x1110)
    FIELD(MAX_OT_REGISTER_S0, INT_OT_AR, 24, 6)
    FIELD(MAX_OT_REGISTER_S0, FRAC_OT_AR, 16, 8)
    FIELD(MAX_OT_REGISTER_S0, INT_OT_AW, 8, 6)
    FIELD(MAX_OT_REGISTER_S0, FRAC_OT_AW, 0, 8)
REG32(TARGET_LATENCY_REGISTER_S0, 0x1130)
    FIELD(TARGET_LATENCY_REGISTER_S0, AR_LAT, 16, 12)
    FIELD(TARGET_LATENCY_REGISTER_S0, AW_LAT, 0, 12)
REG32(LATENCY_REGULATION_REGISTER_S0, 0x1134)
    FIELD(LATENCY_REGULATION_REGISTER_S0, AR_SCALE_FACT, 8, 3)
    FIELD(LATENCY_REGULATION_REGISTER_S0, AW_SCALE_FACT, 0, 3)
REG32(QOS_RANGE_REGISTER_S0, 0x1138)
    FIELD(QOS_RANGE_REGISTER_S0, MAX_ARQOS, 24, 4)
    FIELD(QOS_RANGE_REGISTER_S0, MIN_ARQOS, 16, 4)
    FIELD(QOS_RANGE_REGISTER_S0, MAX_AWQOS, 8, 4)
    FIELD(QOS_RANGE_REGISTER_S0, MIN_AWQOS, 0, 4)
REG32(SNOOP_CONTROL_REGISTER_S1, 0x2000)
    FIELD(SNOOP_CONTROL_REGISTER_S1, SUPPORT_DVMS, 31, 1)
    FIELD(SNOOP_CONTROL_REGISTER_S1, SUPPORT_SNOOPS, 30, 1)
    FIELD(SNOOP_CONTROL_REGISTER_S1, ENABLE_DVMS, 1, 1)
REG32(SHAREABLE_OVERRIDE_REGISTER_S1, 0x2004)
    FIELD(SHAREABLE_OVERRIDE_REGISTER_S1, AXDOMAIN_OVERRIDE, 0, 2)
REG32(READ_QOS_OVERRIDE_REGISTER_S1, 0x2100)
    FIELD(READ_QOS_OVERRIDE_REGISTER_S1, ARQOS_OVERRIDE_READBACK, 8, 4)
    FIELD(READ_QOS_OVERRIDE_REGISTER_S1, ARQOS_VALUE, 0, 4)
REG32(WRITE_QOS_OVERRIDE_REGISTER_S1, 0x2104)
    FIELD(WRITE_QOS_OVERRIDE_REGISTER_S1, AWQOS_OVERRIDE_READBACK, 8, 4)
    FIELD(WRITE_QOS_OVERRIDE_REGISTER_S1, AWQOS_VALUE, 0, 4)
REG32(QOS_CONTROL_REGISTER_S1, 0x210c)
    FIELD(QOS_CONTROL_REGISTER_S1, QOS_REGULATION_DISABLED, 31, 1)
    FIELD(QOS_CONTROL_REGISTER_S1, BANDWIDTH_REGULATION_MODE, 21, 1)
    FIELD(QOS_CONTROL_REGISTER_S1, ARQOS_REGULATION_MODE, 20, 1)
    FIELD(QOS_CONTROL_REGISTER_S1, AWQOS_REGULATION_MODE, 16, 1)
    FIELD(QOS_CONTROL_REGISTER_S1, AR_OT_REGULATION, 3, 1)
    FIELD(QOS_CONTROL_REGISTER_S1, AW_OT_REGULATION, 2, 1)
    FIELD(QOS_CONTROL_REGISTER_S1, ARQOS_REGULATION, 1, 1)
    FIELD(QOS_CONTROL_REGISTER_S1, AWQOS_REGULATION, 0, 1)
REG32(MAX_OT_REGISTER_S1, 0x2110)
    FIELD(MAX_OT_REGISTER_S1, INT_OT_AR, 24, 6)
    FIELD(MAX_OT_REGISTER_S1, FRAC_OT_AR, 16, 8)
    FIELD(MAX_OT_REGISTER_S1, INT_OT_AW, 8, 6)
    FIELD(MAX_OT_REGISTER_S1, FRAC_OT_AW, 0, 8)
REG32(TARGET_LATENCY_REGISTER_S1, 0x2130)
    FIELD(TARGET_LATENCY_REGISTER_S1, AR_LAT, 16, 12)
    FIELD(TARGET_LATENCY_REGISTER_S1, AW_LAT, 0, 12)
REG32(LATENCY_REGULATION_REGISTER_S1, 0x2134)
    FIELD(LATENCY_REGULATION_REGISTER_S1, AR_SCALE_FACT, 8, 3)
    FIELD(LATENCY_REGULATION_REGISTER_S1, AW_SCALE_FACT, 0, 3)
REG32(QOS_RANGE_REGISTER_S1, 0x2138)
    FIELD(QOS_RANGE_REGISTER_S1, MAX_ARQOS, 24, 4)
    FIELD(QOS_RANGE_REGISTER_S1, MIN_ARQOS, 16, 4)
    FIELD(QOS_RANGE_REGISTER_S1, MAX_AWQOS, 8, 4)
    FIELD(QOS_RANGE_REGISTER_S1, MIN_AWQOS, 0, 4)
REG32(SNOOP_CONTROL_REGISTER_S2, 0x3000)
    FIELD(SNOOP_CONTROL_REGISTER_S2, SUPPORT_DVMS, 31, 1)
    FIELD(SNOOP_CONTROL_REGISTER_S2, SUPPORT_SNOOPS, 30, 1)
    FIELD(SNOOP_CONTROL_REGISTER_S2, ENABLE_DVMS, 1, 1)
REG32(SHAREABLE_OVERRIDE_REGISTER_S2, 0x3004)
    FIELD(SHAREABLE_OVERRIDE_REGISTER_S2, AXDOMAIN_OVERRIDE, 0, 2)
REG32(READ_QOS_OVERRIDE_REGISTER_S2, 0x3100)
    FIELD(READ_QOS_OVERRIDE_REGISTER_S2, ARQOS_OVERRIDE_READBACK, 8, 4)
    FIELD(READ_QOS_OVERRIDE_REGISTER_S2, ARQOS_VALUE, 0, 4)
REG32(WRITE_QOS_OVERRIDE_REGISTER_S2, 0x3104)
    FIELD(WRITE_QOS_OVERRIDE_REGISTER_S2, AWQOS_OVERRIDE_READBACK, 8, 4)
    FIELD(WRITE_QOS_OVERRIDE_REGISTER_S2, AWQOS_VALUE, 0, 4)
REG32(QOS_CONTROL_REGISTER_S2, 0x310c)
    FIELD(QOS_CONTROL_REGISTER_S2, QOS_REGULATION_DISABLED, 31, 1)
    FIELD(QOS_CONTROL_REGISTER_S2, BANDWIDTH_REGULATION_MODE, 21, 1)
    FIELD(QOS_CONTROL_REGISTER_S2, ARQOS_REGULATION_MODE, 20, 1)
    FIELD(QOS_CONTROL_REGISTER_S2, AWQOS_REGULATION_MODE, 16, 1)
    FIELD(QOS_CONTROL_REGISTER_S2, AR_OT_REGULATION, 3, 1)
    FIELD(QOS_CONTROL_REGISTER_S2, AW_OT_REGULATION, 2, 1)
    FIELD(QOS_CONTROL_REGISTER_S2, ARQOS_REGULATION, 1, 1)
    FIELD(QOS_CONTROL_REGISTER_S2, AWQOS_REGULATION, 0, 1)
REG32(MAX_OT_REGISTER_S2, 0x3110)
    FIELD(MAX_OT_REGISTER_S2, INT_OT_AR, 24, 6)
    FIELD(MAX_OT_REGISTER_S2, FRAC_OT_AR, 16, 8)
    FIELD(MAX_OT_REGISTER_S2, INT_OT_AW, 8, 6)
    FIELD(MAX_OT_REGISTER_S2, FRAC_OT_AW, 0, 8)
REG32(TARGET_LATENCY_REGISTER_S2, 0x3130)
    FIELD(TARGET_LATENCY_REGISTER_S2, AR_LAT, 16, 12)
    FIELD(TARGET_LATENCY_REGISTER_S2, AW_LAT, 0, 12)
REG32(LATENCY_REGULATION_REGISTER_S2, 0x3134)
    FIELD(LATENCY_REGULATION_REGISTER_S2, AR_SCALE_FACT, 8, 3)
    FIELD(LATENCY_REGULATION_REGISTER_S2, AW_SCALE_FACT, 0, 3)
REG32(QOS_RANGE_REGISTER_S2, 0x3138)
    FIELD(QOS_RANGE_REGISTER_S2, MAX_ARQOS, 24, 4)
    FIELD(QOS_RANGE_REGISTER_S2, MIN_ARQOS, 16, 4)
    FIELD(QOS_RANGE_REGISTER_S2, MAX_AWQOS, 8, 4)
    FIELD(QOS_RANGE_REGISTER_S2, MIN_AWQOS, 0, 4)
REG32(SNOOP_CONTROL_REGISTER_S3, 0x4000)
    FIELD(SNOOP_CONTROL_REGISTER_S3, SUPPORT_DVMS, 31, 1)
    FIELD(SNOOP_CONTROL_REGISTER_S3, SUPPORT_SNOOPS, 30, 1)
    FIELD(SNOOP_CONTROL_REGISTER_S3, ENABLE_DVMS, 1, 1)
    FIELD(SNOOP_CONTROL_REGISTER_S3, ENABLE_SNOOPS, 0, 1)
REG32(READ_QOS_OVERRIDE_REGISTER_S3, 0x4100)
    FIELD(READ_QOS_OVERRIDE_REGISTER_S3, ARQOS_OVERRIDE_READBACK, 8, 4)
    FIELD(READ_QOS_OVERRIDE_REGISTER_S3, ARQOS_VALUE, 0, 4)
REG32(WRITE_QOS_OVERRIDE_REGISTER_S3, 0x4104)
    FIELD(WRITE_QOS_OVERRIDE_REGISTER_S3, AWQOS_OVERRIDE_READBACK, 8, 4)
    FIELD(WRITE_QOS_OVERRIDE_REGISTER_S3, AWQOS_VALUE, 0, 4)
REG32(QOS_CONTROL_REGISTER_S3, 0x410c)
    FIELD(QOS_CONTROL_REGISTER_S3, QOS_REGULATION_DISABLED, 31, 1)
    FIELD(QOS_CONTROL_REGISTER_S3, BANDWIDTH_REGULATION_MODE, 21, 1)
    FIELD(QOS_CONTROL_REGISTER_S3, ARQOS_REGULATION_MODE, 20, 1)
    FIELD(QOS_CONTROL_REGISTER_S3, AWQOS_REGULATION_MODE, 16, 1)
    FIELD(QOS_CONTROL_REGISTER_S3, ARQOS_REGULATION, 1, 1)
    FIELD(QOS_CONTROL_REGISTER_S3, AWQOS_REGULATION, 0, 1)
REG32(TARGET_LATENCY_REGISTER_S3, 0x4130)
    FIELD(TARGET_LATENCY_REGISTER_S3, AR_LAT, 16, 12)
    FIELD(TARGET_LATENCY_REGISTER_S3, AW_LAT, 0, 12)
REG32(LATENCY_REGULATION_REGISTER_S3, 0x4134)
    FIELD(LATENCY_REGULATION_REGISTER_S3, AR_SCALE_FACT, 8, 3)
    FIELD(LATENCY_REGULATION_REGISTER_S3, AW_SCALE_FACT, 0, 3)
REG32(QOS_RANGE_REGISTER_S3, 0x4138)
    FIELD(QOS_RANGE_REGISTER_S3, MAX_ARQOS, 24, 4)
    FIELD(QOS_RANGE_REGISTER_S3, MIN_ARQOS, 16, 4)
    FIELD(QOS_RANGE_REGISTER_S3, MAX_AWQOS, 8, 4)
    FIELD(QOS_RANGE_REGISTER_S3, MIN_AWQOS, 0, 4)
REG32(SNOOP_CONTROL_REGISTER_S4, 0x5000)
    FIELD(SNOOP_CONTROL_REGISTER_S4, SUPPORT_DVMS, 31, 1)
    FIELD(SNOOP_CONTROL_REGISTER_S4, SUPPORT_SNOOPS, 30, 1)
    FIELD(SNOOP_CONTROL_REGISTER_S4, ENABLE_DVMS, 1, 1)
    FIELD(SNOOP_CONTROL_REGISTER_S4, ENABLE_SNOOPS, 0, 1)
REG32(READ_QOS_OVERRIDE_REGISTER_S4, 0x5100)
    FIELD(READ_QOS_OVERRIDE_REGISTER_S4, ARQOS_OVERRIDE_READBACK, 8, 4)
    FIELD(READ_QOS_OVERRIDE_REGISTER_S4, ARQOS_VALUE, 0, 4)
REG32(WRITE_QOS_OVERRIDE_REGISTER_S4, 0x5104)
    FIELD(WRITE_QOS_OVERRIDE_REGISTER_S4, AWQOS_OVERRIDE_READBACK, 8, 4)
    FIELD(WRITE_QOS_OVERRIDE_REGISTER_S4, AWQOS_VALUE, 0, 4)
REG32(QOS_CONTROL_REGISTER_S4, 0x510c)
    FIELD(QOS_CONTROL_REGISTER_S4, QOS_REGULATION_DISABLED, 31, 1)
    FIELD(QOS_CONTROL_REGISTER_S4, BANDWIDTH_REGULATION_MODE, 21, 1)
    FIELD(QOS_CONTROL_REGISTER_S4, ARQOS_REGULATION_MODE, 20, 1)
    FIELD(QOS_CONTROL_REGISTER_S4, AWQOS_REGULATION_MODE, 16, 1)
    FIELD(QOS_CONTROL_REGISTER_S4, ARQOS_REGULATION, 1, 1)
    FIELD(QOS_CONTROL_REGISTER_S4, AWQOS_REGULATION, 0, 1)
REG32(TARGET_LATENCY_REGISTER_S4, 0x5130)
    FIELD(TARGET_LATENCY_REGISTER_S4, AR_LAT, 16, 12)
    FIELD(TARGET_LATENCY_REGISTER_S4, AW_LAT, 0, 12)
REG32(LATENCY_REGULATION_REGISTER_S4, 0x5134)
    FIELD(LATENCY_REGULATION_REGISTER_S4, AR_SCALE_FACT, 8, 3)
    FIELD(LATENCY_REGULATION_REGISTER_S4, AW_SCALE_FACT, 0, 3)
REG32(QOS_RANGE_REGISTER_S4, 0x5138)
    FIELD(QOS_RANGE_REGISTER_S4, MAX_ARQOS, 24, 4)
    FIELD(QOS_RANGE_REGISTER_S4, MIN_ARQOS, 16, 4)
    FIELD(QOS_RANGE_REGISTER_S4, MAX_AWQOS, 8, 4)
    FIELD(QOS_RANGE_REGISTER_S4, MIN_AWQOS, 0, 4)
REG32(CYCLE_COUNTER, 0x9004)
REG32(CYCLE_COUNTER_CONTROL, 0x9008)
    FIELD(CYCLE_COUNTER_CONTROL, CCNT_EN, 0, 1)
REG32(CYCLE_COUNT_OVERFLOW, 0x900c)
    FIELD(CYCLE_COUNT_OVERFLOW, CCNT_OVERFLOW, 0, 1)
REG32(ESR0, 0xa000)
    FIELD(ESR0, EVT_IF0, 5, 3)
    FIELD(ESR0, EVT_CNT0, 0, 5)
REG32(EVENT_COUNTER0, 0xa004)
REG32(EVENT_COUNTER0_CONTROL, 0xa008)
    FIELD(EVENT_COUNTER0_CONTROL, CNT0_EN, 0, 1)
REG32(EVENT_COUNTER0_OVERFLOW, 0xa00c)
    FIELD(EVENT_COUNTER0_OVERFLOW, CNT0_OVERFLOW, 0, 1)
REG32(ESR1, 0xb000)
    FIELD(ESR1, EVT_IF1, 5, 3)
    FIELD(ESR1, EVT_CNT1, 0, 5)
REG32(EVENT_COUNTER1, 0xb004)
REG32(EVENT_COUNTER1_CONTROL, 0xb008)
    FIELD(EVENT_COUNTER1_CONTROL, CNT1_EN, 0, 1)
REG32(EVENT_COUNTER1_OVERFLOW, 0xb00c)
    FIELD(EVENT_COUNTER1_OVERFLOW, CNT1_OVERFLOW, 0, 1)
REG32(ESR2, 0xc000)
    FIELD(ESR2, EVT_IF2, 5, 3)
    FIELD(ESR2, EVT_CNT2, 0, 5)
REG32(EVENT_COUNTER2, 0xc004)
REG32(EVENT_COUNTER2_CONTROL, 0xc008)
    FIELD(EVENT_COUNTER2_CONTROL, CNT2_EN, 0, 1)
REG32(EVENT_COUNTER2_OVERFLOW, 0xc00c)
    FIELD(EVENT_COUNTER2_OVERFLOW, CNT2_OVERFLOW, 0, 1)
REG32(ESR3, 0xd000)
    FIELD(ESR3, EVT_IF3, 5, 3)
    FIELD(ESR3, EVT_CNT3, 0, 5)
REG32(EVENT_COUNTER3, 0xd004)
REG32(EVENT_COUNTER3_CONTROL, 0xd008)
    FIELD(EVENT_COUNTER3_CONTROL, CNT3_EN, 0, 1)
REG32(EVENT_COUNTER3_OVERFLOW, 0xd00c)
    FIELD(EVENT_COUNTER3_OVERFLOW, CNT3_OVERFLOW, 0, 1)

#define CCI400_R_MAX (R_EVENT_COUNTER3_OVERFLOW + 1)

typedef struct CCI {
    SysBusDevice parent_obj;
    MemoryRegion iomem;
    IOMMUMemoryRegion iommu;

    struct {
        uint64_t stripe_granule_sz;
    } cfg;

    /* The CCI has three down-stream Master ports.  */
    AddressSpace *as[3];
    MemoryRegion *M[3];

    uint32_t regs[CCI400_R_MAX];
    RegisterInfo regs_info[CCI400_R_MAX];

    uint64_t enable_mask;
} CCI;

static const RegisterAccessInfo cci400_regs_info[] = {
    {   .name = "CONTROL_OVERRIDE_REGISTER",
        .addr = A_CONTROL_OVERRIDE_REGISTER,
    },{ .name = "SPECULATION_CONTROL_REGISTER",
        .addr = A_SPECULATION_CONTROL_REGISTER,
    },{ .name = "SECURE_ACCESS_REGISTER",  .addr = A_SECURE_ACCESS_REGISTER,
    },{ .name = "STATUS_REGISTER",  .addr = A_STATUS_REGISTER,
        .ro = 0x1,
    },{ .name = "IMPRECISE_ERROR_REGISTER",  .addr = A_IMPRECISE_ERROR_REGISTER,
        .w1c = 0x1f0007,
    },{ .name = "PERFORMANCE_MONITOR_CONTROL_REGISTER",
        .addr = A_PERFORMANCE_MONITOR_CONTROL_REGISTER,
        .reset = 0x2000,
        .ro = 0xf800,
    },{ .name = "PERIPHERAL_ID4",  .addr = A_PERIPHERAL_ID4,
        .reset = 0x44,
        .ro = 0xff,
    },{ .name = "PERIPHERAL_ID5",  .addr = A_PERIPHERAL_ID5,
        .ro = 0xff,
    },{ .name = "PERIPHERAL_ID6",  .addr = A_PERIPHERAL_ID6,
        .ro = 0xff,
    },{ .name = "PERIPHERAL_ID7",  .addr = A_PERIPHERAL_ID7,
        .ro = 0xff,
    },{ .name = "PERIPHERAL_ID0",  .addr = A_PERIPHERAL_ID0,
        .reset = 0x20,
        .ro = 0xff,
    },{ .name = "PERIPHERAL_ID1",  .addr = A_PERIPHERAL_ID1,
        .reset = 0xb4,
        .ro = 0xff,
    },{ .name = "PERIPHERAL_ID2",  .addr = A_PERIPHERAL_ID2,
        .reset = 0x9b,
        .ro = 0xff,
    },{ .name = "PERIPHERAL_ID3",  .addr = A_PERIPHERAL_ID3,
        .ro = 0xff,
    },{ .name = "COMPONENT_ID0",  .addr = A_COMPONENT_ID0,
        .reset = 0xd,
        .ro = 0xff,
    },{ .name = "COMPONENT_ID1",  .addr = A_COMPONENT_ID1,
        .reset = 0xf0,
        .ro = 0xff,
    },{ .name = "COMPONENT_ID2",  .addr = A_COMPONENT_ID2,
        .reset = 0x5,
        .ro = 0xff,
    },{ .name = "COMPONENT_ID3",  .addr = A_COMPONENT_ID3,
        .reset = 0xb1,
        .ro = 0xff,
    },{ .name = "SNOOP_CONTROL_REGISTER_S0",
        .addr = A_SNOOP_CONTROL_REGISTER_S0,
        .reset = 0x80000000,
        .ro = 0xc0000000,
    },{ .name = "SHAREABLE_OVERRIDE_REGISTER_S0",
        .addr = A_SHAREABLE_OVERRIDE_REGISTER_S0,
    },{ .name = "READ_QOS_OVERRIDE_REGISTER_S0",
        .addr = A_READ_QOS_OVERRIDE_REGISTER_S0,
        .ro = 0xf00,
    },{ .name = "WRITE_QOS_OVERRIDE_REGISTER_S0",
        .addr = A_WRITE_QOS_OVERRIDE_REGISTER_S0,
        .ro = 0xf00,
    },{ .name = "QOS_CONTROL_REGISTER_S0",  .addr = A_QOS_CONTROL_REGISTER_S0,
        .ro = 0x80000000,
    },{ .name = "MAX_OT_REGISTER_S0",  .addr = A_MAX_OT_REGISTER_S0,
    },{ .name = "TARGET_LATENCY_REGISTER_S0",
        .addr = A_TARGET_LATENCY_REGISTER_S0,
    },{ .name = "LATENCY_REGULATION_REGISTER_S0",
        .addr = A_LATENCY_REGULATION_REGISTER_S0,
    },{ .name = "QOS_RANGE_REGISTER_S0",  .addr = A_QOS_RANGE_REGISTER_S0,
    },{ .name = "SNOOP_CONTROL_REGISTER_S1",
        .addr = A_SNOOP_CONTROL_REGISTER_S1,
        .ro = 0xc0000002,
    },{ .name = "SHAREABLE_OVERRIDE_REGISTER_S1",
        .addr = A_SHAREABLE_OVERRIDE_REGISTER_S1,
    },{ .name = "READ_QOS_OVERRIDE_REGISTER_S1",
        .addr = A_READ_QOS_OVERRIDE_REGISTER_S1,
        .ro = 0xf00,
    },{ .name = "WRITE_QOS_OVERRIDE_REGISTER_S1",
        .addr = A_WRITE_QOS_OVERRIDE_REGISTER_S1,
        .ro = 0xf00,
    },{ .name = "QOS_CONTROL_REGISTER_S1",  .addr = A_QOS_CONTROL_REGISTER_S1,
        .ro = 0x80000000,
    },{ .name = "MAX_OT_REGISTER_S1",  .addr = A_MAX_OT_REGISTER_S1,
    },{ .name = "TARGET_LATENCY_REGISTER_S1",
        .addr = A_TARGET_LATENCY_REGISTER_S1,
    },{ .name = "LATENCY_REGULATION_REGISTER_S1",
        .addr = A_LATENCY_REGULATION_REGISTER_S1,
    },{ .name = "QOS_RANGE_REGISTER_S1",  .addr = A_QOS_RANGE_REGISTER_S1,
    },{ .name = "SNOOP_CONTROL_REGISTER_S2",
        .addr = A_SNOOP_CONTROL_REGISTER_S2,
        .ro = 0xc0000002,
    },{ .name = "SHAREABLE_OVERRIDE_REGISTER_S2",
        .addr = A_SHAREABLE_OVERRIDE_REGISTER_S2,
    },{ .name = "READ_QOS_OVERRIDE_REGISTER_S2",
        .addr = A_READ_QOS_OVERRIDE_REGISTER_S2,
        .ro = 0xf00,
    },{ .name = "WRITE_QOS_OVERRIDE_REGISTER_S2",
        .addr = A_WRITE_QOS_OVERRIDE_REGISTER_S2,
        .ro = 0xf00,
    },{ .name = "QOS_CONTROL_REGISTER_S2",  .addr = A_QOS_CONTROL_REGISTER_S2,
        .ro = 0x80000000,
    },{ .name = "MAX_OT_REGISTER_S2",  .addr = A_MAX_OT_REGISTER_S2,
    },{ .name = "TARGET_LATENCY_REGISTER_S2",
        .addr = A_TARGET_LATENCY_REGISTER_S2,
    },{ .name = "LATENCY_REGULATION_REGISTER_S2",
        .addr = A_LATENCY_REGULATION_REGISTER_S2,
    },{ .name = "QOS_RANGE_REGISTER_S2",  .addr = A_QOS_RANGE_REGISTER_S2,
    },{ .name = "SNOOP_CONTROL_REGISTER_S3",
        .addr = A_SNOOP_CONTROL_REGISTER_S3,
        .reset = 0xc0000000,
        .ro = 0xc0000000,
    },{ .name = "READ_QOS_OVERRIDE_REGISTER_S3",
        .addr = A_READ_QOS_OVERRIDE_REGISTER_S3,
        .ro = 0xf00,
    },{ .name = "WRITE_QOS_OVERRIDE_REGISTER_S3",
        .addr = A_WRITE_QOS_OVERRIDE_REGISTER_S3,
        .ro = 0xf00,
    },{ .name = "QOS_CONTROL_REGISTER_S3",  .addr = A_QOS_CONTROL_REGISTER_S3,
        .ro = 0x80000000,
    },{ .name = "TARGET_LATENCY_REGISTER_S3",
        .addr = A_TARGET_LATENCY_REGISTER_S3,
    },{ .name = "LATENCY_REGULATION_REGISTER_S3",
        .addr = A_LATENCY_REGULATION_REGISTER_S3,
    },{ .name = "QOS_RANGE_REGISTER_S3",  .addr = A_QOS_RANGE_REGISTER_S3,
    },{ .name = "SNOOP_CONTROL_REGISTER_S4",
        .addr = A_SNOOP_CONTROL_REGISTER_S4,
        .reset = 0xc0000000,
        .ro = 0xc0000000,
    },{ .name = "READ_QOS_OVERRIDE_REGISTER_S4",
        .addr = A_READ_QOS_OVERRIDE_REGISTER_S4,
        .ro = 0xf00,
    },{ .name = "WRITE_QOS_OVERRIDE_REGISTER_S4",
        .addr = A_WRITE_QOS_OVERRIDE_REGISTER_S4,
        .ro = 0xf00,
    },{ .name = "QOS_CONTROL_REGISTER_S4",  .addr = A_QOS_CONTROL_REGISTER_S4,
        .ro = 0x80000000,
    },{ .name = "TARGET_LATENCY_REGISTER_S4",
        .addr = A_TARGET_LATENCY_REGISTER_S4,
    },{ .name = "LATENCY_REGULATION_REGISTER_S4",
        .addr = A_LATENCY_REGULATION_REGISTER_S4,
    },{ .name = "QOS_RANGE_REGISTER_S4",  .addr = A_QOS_RANGE_REGISTER_S4,
    },{ .name = "CYCLE_COUNTER",  .addr = A_CYCLE_COUNTER,
    },{ .name = "CYCLE_COUNTER_CONTROL",  .addr = A_CYCLE_COUNTER_CONTROL,
    },{ .name = "CYCLE_COUNT_OVERFLOW",  .addr = A_CYCLE_COUNT_OVERFLOW,
        .w1c = 0x1,
    },{ .name = "ESR0",  .addr = A_ESR0,
    },{ .name = "EVENT_COUNTER0",  .addr = A_EVENT_COUNTER0,
    },{ .name = "EVENT_COUNTER0_CONTROL",  .addr = A_EVENT_COUNTER0_CONTROL,
    },{ .name = "EVENT_COUNTER0_OVERFLOW",  .addr = A_EVENT_COUNTER0_OVERFLOW,
        .w1c = 0x1,
    },{ .name = "ESR1",  .addr = A_ESR1,
    },{ .name = "EVENT_COUNTER1",  .addr = A_EVENT_COUNTER1,
    },{ .name = "EVENT_COUNTER1_CONTROL",  .addr = A_EVENT_COUNTER1_CONTROL,
    },{ .name = "EVENT_COUNTER1_OVERFLOW",  .addr = A_EVENT_COUNTER1_OVERFLOW,
        .w1c = 0x1,
    },{ .name = "ESR2",  .addr = A_ESR2,
    },{ .name = "EVENT_COUNTER2",  .addr = A_EVENT_COUNTER2,
    },{ .name = "EVENT_COUNTER2_CONTROL",  .addr = A_EVENT_COUNTER2_CONTROL,
    },{ .name = "EVENT_COUNTER2_OVERFLOW",  .addr = A_EVENT_COUNTER2_OVERFLOW,
        .w1c = 0x1,
    },{ .name = "ESR3",  .addr = A_ESR3,
    },{ .name = "EVENT_COUNTER3",  .addr = A_EVENT_COUNTER3,
    },{ .name = "EVENT_COUNTER3_CONTROL",  .addr = A_EVENT_COUNTER3_CONTROL,
    },{ .name = "EVENT_COUNTER3_OVERFLOW",  .addr = A_EVENT_COUNTER3_OVERFLOW,
        .w1c = 0x1,
    }
};

static void cci400_reset(DeviceState *dev)
{
    CCI *s = ARM_CCI400(dev);
    unsigned int i;

    for (i = 0; i < ARRAY_SIZE(s->regs_info); ++i) {
        register_reset(&s->regs_info[i]);
    }
}

static const MemoryRegionOps cci400_ops = {
    .read = register_read_memory,
    .write = register_write_memory,
    .endianness = DEVICE_LITTLE_ENDIAN,
    .valid = {
        .min_access_size = 4,
        .max_access_size = 4,
    },
};

static int cci_attrs_to_index(IOMMUMemoryRegion *iommu, MemTxAttrs attrs)
{
    return attrs.secure;
}

static int cci_num_indexes(IOMMUMemoryRegion *iommu)
{
    return 2;
}

static IOMMUTLBEntry cci_translate(IOMMUMemoryRegion *mr, hwaddr addr,
                                   IOMMUAccessFlags flags, int iommu_idx)
{
    CCI *s = container_of(mr, CCI, iommu);;
    IOMMUTLBEntry ret = {
        .iova = addr,
        .translated_addr = addr,
        .addr_mask = s->cfg.stripe_granule_sz - 1,
        .perm = IOMMU_RW,
    };
    MemTxAttrs attr = { .secure = iommu_idx & 1 };
    unsigned int i, mi = 0;
    bool valid = false;

    /* Is there anything backing this address on M1 or M2?  */
    for (i = 1; i < ARRAY_SIZE(s->as); i++) {
        bool t;
        t = address_space_access_valid(s->as[i], addr, 4, false, attr);
        if (i > 1) {
            assert(valid == t);
        }
        valid = t;
    }
    if (valid) {
        unsigned int stripe_idx = !!(addr & s->cfg.stripe_granule_sz);
        /* M0 is for devs. M1 and M2 are the memory ports with striping.  */
        mi = 1 + stripe_idx;
    }

    ret.target_as = s->as[mi];
    return ret;
}

static void cci400_realize(DeviceState *dev, Error **errp)
{
    CCI *s = ARM_CCI400(dev);
    unsigned int i;

    for (i = 0; i < ARRAY_SIZE(s->M); i++) {
        s->as[i] = address_space_init_shareable(s->M[i], NULL);
        assert(s->M[i]);
        assert(s->as[i]);
    }
}

static void sig_handler(void *opaque, int n, int level)
{
    CCI *s = ARM_CCI400(opaque);
    uint64_t level64 = level;

    s->enable_mask &= ~(1ULL << n);
    s->enable_mask |= level64 << n;
    memory_region_set_enabled(MEMORY_REGION(&s->iommu), !!s->enable_mask);
}

static void cci400_init(Object *obj)
{
    CCI *s = ARM_CCI400(obj);
    SysBusDevice *sbd = SYS_BUS_DEVICE(obj);
    RegisterInfoArray *reg_array;
    unsigned int i;

    memory_region_init(&s->iomem, obj, TYPE_ARM_CCI400, CCI400_R_MAX * 4);
    reg_array =
        register_init_block32(DEVICE(obj), cci400_regs_info,
                              ARRAY_SIZE(cci400_regs_info),
                              s->regs_info, s->regs,
                              &cci400_ops,
                              ARM_CCI400_ERR_DEBUG,
                              CCI400_R_MAX * 4);
    memory_region_add_subregion(&s->iomem,
                                0x0,
                                &reg_array->mem);

    sysbus_init_mmio(sbd, &s->iomem);

    memory_region_init_iommu(&s->iommu, sizeof(s->iommu),
                             TYPE_ARM_CCI400_IOMMU_MEMORY_REGION,
                             OBJECT(s),
                             "cci-iommu", UINT64_MAX);
    sysbus_init_mmio(sbd, MEMORY_REGION(&s->iommu));

    for (i = 0; i < ARRAY_SIZE(s->M); i++) {
        char *name = g_strdup_printf("M%d", i);
        object_property_add_link(obj, name, TYPE_MEMORY_REGION,
                             (Object **)&s->M[i],
                             qdev_prop_allow_set_link_before_realize,
                             OBJ_PROP_LINK_STRONG);
        g_free(name);
    }

    qdev_init_gpio_in_named(DEVICE(sbd), sig_handler, "enable", 16);

    /* We don't support configurable sizes yet.  */
    s->cfg.stripe_granule_sz = 4096;
}

static const VMStateDescription vmstate_cci400 = {
    .name = TYPE_ARM_CCI400,
    .version_id = 1,
    .minimum_version_id = 1,
    .fields = (VMStateField[]) {
        VMSTATE_UINT32_ARRAY(regs, CCI, CCI400_R_MAX),
        VMSTATE_END_OF_LIST(),
    }
};

static const FDTGenericGPIOSet gpio_sets[] = {
    {
      .names = &fdt_generic_gpio_name_set_gpio,
      .gpios = (FDTGenericGPIOConnection[]) {
        { .name = "enable", .fdt_index = 0, .range = 16 },
        { },
      },
    },
    { },
};

static void cci400_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    FDTGenericGPIOClass *fggc = FDT_GENERIC_GPIO_CLASS(klass);

    dc->reset = cci400_reset;
    dc->realize = cci400_realize;
    dc->vmsd = &vmstate_cci400;
    fggc->controller_gpios = gpio_sets;
}

static void cci400_iommu_memory_region_class_init(ObjectClass *klass,
                                                   void *data)
{
    IOMMUMemoryRegionClass *imrc = IOMMU_MEMORY_REGION_CLASS(klass);

    imrc->translate = cci_translate;
    imrc->attrs_to_index = cci_attrs_to_index;
    imrc->num_indexes = cci_num_indexes;
}

static const TypeInfo cci400_info = {
    .name          = TYPE_ARM_CCI400,
    .parent        = TYPE_SYS_BUS_DEVICE,
    .instance_size = sizeof(CCI),
    .class_init    = cci400_class_init,
    .instance_init = cci400_init,
    .interfaces    = (InterfaceInfo[]) {
        { TYPE_FDT_GENERIC_GPIO },
        { }
    },
};

static const TypeInfo cci400_iommu_memory_region_info = {
    .name = TYPE_ARM_CCI400_IOMMU_MEMORY_REGION,
    .parent = TYPE_IOMMU_MEMORY_REGION,
    .class_init = cci400_iommu_memory_region_class_init,
};

static void cci400_register_types(void)
{
    type_register_static(&cci400_info);
    type_register_static(&cci400_iommu_memory_region_info);
}

type_init(cci400_register_types)
