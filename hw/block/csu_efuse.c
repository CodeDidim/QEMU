/*
 * QEMU model of the EFUSE eFuse
 *
 * Copyright (c) 2015 Xilinx Inc.
 *
 * Written by Edgar E. Iglesias <edgari@xilinx.com>
 * Partially autogenerated by xregqemu.py 2015-01-02.
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
#include "hw/hw.h"
#include "hw/block/flash.h"
#include "qapi/error.h"
#include "qemu/timer.h"
#include "exec/address-spaces.h"
#include "qemu/host-utils.h"
#include "hw/sysbus.h"
#include "hw/register-dep.h"
#include "sysemu/blockdev.h"
#include "qemu/bitops.h"
#include "qemu/error-report.h"
#include "qemu/log.h"
#include "qemu/main-loop.h"

#include "sysemu/block-backend.h"
#include "hw/zynqmp_aes_key.h"
#include "hw/block/xlnx-efuse.h"

#ifndef ZYNQMP_EFUSE_ERR_DEBUG
#define ZYNQMP_EFUSE_ERR_DEBUG 0
#endif

#define TYPE_ZYNQMP_EFUSE "xlnx.zynqmp-efuse"
#define TYPE_ZYNQ3_EFUSE "xlnx.versal-efuse"

#define ZYNQMP_EFUSE(obj) \
     OBJECT_CHECK(ZynqMPEFuse, (obj), TYPE_ZYNQMP_EFUSE)

#define ZYNQ3_EFUSE(obj) \
     OBJECT_CHECK(Zynq3EFuse, (obj), TYPE_ZYNQ3_EFUSE)


DEP_REG32(WR_LOCK, 0x0)
    DEP_FIELD(WR_LOCK, LOCK, 16, 0)
DEP_REG32(CFG, 0x4)
    DEP_FIELD(CFG, SLVERR_ENABLE, 1, 5)
    DEP_FIELD(CFG, MARGIN_RD, 2, 2)
    DEP_FIELD(CFG, PGM_EN, 1, 1)
    DEP_FIELD(CFG, EFUSE_CLK_SEL, 1, 0)
DEP_REG32(STATUS, 0x8)
    DEP_FIELD(STATUS, AES_CRC_PASS, 1, 7)
    DEP_FIELD(STATUS, AES_CRC_DONE, 1, 6)
    DEP_FIELD(STATUS, CACHE_DONE, 1, 5)
    DEP_FIELD(STATUS, CACHE_LOAD, 1, 4)
    DEP_FIELD(STATUS, EFUSE_3_TBIT, 1, 2)
    DEP_FIELD(STATUS, EFUSE_2_TBIT, 1, 1)
    DEP_FIELD(STATUS, EFUSE_0_TBIT, 1, 0)
DEP_REG32(EFUSE_PGM_ADDR, 0xc)
    DEP_FIELD(EFUSE_PGM_ADDR, EFUSE, 2, 11)
    DEP_FIELD(EFUSE_PGM_ADDR, ROW, 6, 5)
    DEP_FIELD(EFUSE_PGM_ADDR, COLUMN, 5, 0)
DEP_REG32(EFUSE_RD_ADDR, 0x10)
    DEP_FIELD(EFUSE_RD_ADDR, EFUSE, 2, 11)
    DEP_FIELD(EFUSE_RD_ADDR, ROW, 6, 5)
DEP_REG32(EFUSE_RD_DATA, 0x14)
DEP_REG32(TPGM, 0x18)
    DEP_FIELD(TPGM, VALUE, 16, 0)
DEP_REG32(TRD, 0x1c)
    DEP_FIELD(TRD, VALUE, 8, 0)
DEP_REG32(TSU_H_PS, 0x20)
    DEP_FIELD(TSU_H_PS, VALUE, 8, 0)
DEP_REG32(TSU_H_PS_CS, 0x24)
    DEP_FIELD(TSU_H_PS_CS, VALUE, 8, 0)
DEP_REG32(TSU_H_CS, 0x2c)
    DEP_FIELD(TSU_H_CS, VALUE, 4, 0)
DEP_REG32(EFUSE_ISR, 0x30)
    DEP_FIELD(EFUSE_ISR, APB_SLVERR, 1, 31)
    DEP_FIELD(EFUSE_ISR, CACHE_ERROR, 1, 4)
    DEP_FIELD(EFUSE_ISR, RD_ERROR, 1, 3)
    DEP_FIELD(EFUSE_ISR, RD_DONE, 1, 2)
    DEP_FIELD(EFUSE_ISR, PGM_ERROR, 1, 1)
    DEP_FIELD(EFUSE_ISR, PGM_DONE, 1, 0)
DEP_REG32(EFUSE_IMR, 0x34)
    DEP_FIELD(EFUSE_IMR, APB_SLVERR, 1, 31)
    DEP_FIELD(EFUSE_IMR, CACHE_ERROR, 1, 4)
    DEP_FIELD(EFUSE_IMR, RD_ERROR, 1, 3)
    DEP_FIELD(EFUSE_IMR, RD_DONE, 1, 2)
    DEP_FIELD(EFUSE_IMR, PGM_ERROR, 1, 1)
    DEP_FIELD(EFUSE_IMR, PGM_DONE, 1, 0)
DEP_REG32(EFUSE_IER, 0x38)
    DEP_FIELD(EFUSE_IER, APB_SLVERR, 1, 31)
    DEP_FIELD(EFUSE_IER, CACHE_ERROR, 1, 4)
    DEP_FIELD(EFUSE_IER, RD_ERROR, 1, 3)
    DEP_FIELD(EFUSE_IER, RD_DONE, 1, 2)
    DEP_FIELD(EFUSE_IER, PGM_ERROR, 1, 1)
    DEP_FIELD(EFUSE_IER, PGM_DONE, 1, 0)
DEP_REG32(EFUSE_IDR, 0x3c)
    DEP_FIELD(EFUSE_IDR, APB_SLVERR, 1, 31)
    DEP_FIELD(EFUSE_IDR, CACHE_ERROR, 1, 4)
    DEP_FIELD(EFUSE_IDR, RD_ERROR, 1, 3)
    DEP_FIELD(EFUSE_IDR, RD_DONE, 1, 2)
    DEP_FIELD(EFUSE_IDR, PGM_ERROR, 1, 1)
    DEP_FIELD(EFUSE_IDR, PGM_DONE, 1, 0)
DEP_REG32(EFUSE_CACHE_LOAD, 0x40)
    DEP_FIELD(EFUSE_CACHE_LOAD, LOAD, 1, 0)
DEP_REG32(EFUSE_PGM_LOCK, 0x44)
    DEP_FIELD(EFUSE_PGM_LOCK, SPK_ID_LOCK, 1, 0)
DEP_REG32(EFUSE_AES_CRC, 0x48)
DEP_REG32(DNA_0, 0x100c)
DEP_REG32(DNA_1, 0x1010)
DEP_REG32(DNA_2, 0x1014)
DEP_REG32(IPDISABLE, 0x1018)
    DEP_FIELD(IPDISABLE, VCU_DIS, 1, 8)
    DEP_FIELD(IPDISABLE, GPU_DIS, 1, 5)
    DEP_FIELD(IPDISABLE, APU3_DIS, 1, 3)
    DEP_FIELD(IPDISABLE, APU2_DIS, 1, 2)
    DEP_FIELD(IPDISABLE, APU1_DIS, 1, 1)
    DEP_FIELD(IPDISABLE, APU0_DIS, 1, 0)
DEP_REG32(SYSOSC_CTRL, 0x101c)
    DEP_FIELD(SYSOSC_CTRL, SYSOSC_EN, 1, 0)
DEP_REG32(USER_0, 0x1020)
DEP_REG32(USER_1, 0x1024)
DEP_REG32(USER_2, 0x1028)
DEP_REG32(USER_3, 0x102c)
DEP_REG32(USER_4, 0x1030)
DEP_REG32(USER_5, 0x1034)
DEP_REG32(USER_6, 0x1038)
DEP_REG32(USER_7, 0x103c)
DEP_REG32(MISC_USER_CTRL, 0x1040)
    DEP_FIELD(MISC_USER_CTRL, FPD_SC_EN_0, 1, 14)
    DEP_FIELD(MISC_USER_CTRL, LPD_SC_EN_0, 1, 11)
    DEP_FIELD(MISC_USER_CTRL, LBIST_EN, 1, 10)
    DEP_FIELD(MISC_USER_CTRL, USR_WRLK_7, 1, 7)
    DEP_FIELD(MISC_USER_CTRL, USR_WRLK_6, 1, 6)
    DEP_FIELD(MISC_USER_CTRL, USR_WRLK_5, 1, 5)
    DEP_FIELD(MISC_USER_CTRL, USR_WRLK_4, 1, 4)
    DEP_FIELD(MISC_USER_CTRL, USR_WRLK_3, 1, 3)
    DEP_FIELD(MISC_USER_CTRL, USR_WRLK_2, 1, 2)
    DEP_FIELD(MISC_USER_CTRL, USR_WRLK_1, 1, 1)
    DEP_FIELD(MISC_USER_CTRL, USR_WRLK_0, 1, 0)
DEP_REG32(ROM_RSVD, 0x1044)
    DEP_FIELD(ROM_RSVD, PBR_BOOT_ERROR, 3, 0)
DEP_REG32(PUF_MISC, 0x1054)
    DEP_FIELD(PUF_MISC, REGISTER_DIS, 1, 31)
    DEP_FIELD(PUF_MISC, SYN_WRLK, 1, 30)
    DEP_FIELD(PUF_MISC, SYN_INVLD, 1, 29)
    DEP_FIELD(PUF_MISC, TEST2_DIS, 1, 28)
    DEP_FIELD(PUF_MISC, UNUSED27, 1, 27)
    DEP_FIELD(PUF_MISC, UNUSED26, 1, 26)
    DEP_FIELD(PUF_MISC, UNUSED25, 1, 25)
    DEP_FIELD(PUF_MISC, UNUSED24, 1, 24)
    DEP_FIELD(PUF_MISC, AUX, 24, 0)
DEP_REG32(SEC_CTRL, 0x1058)
    DEP_FIELD(SEC_CTRL, PPK1_INVLD, 2, 30)
    DEP_FIELD(SEC_CTRL, PPK1_WRLK, 1, 29)
    DEP_FIELD(SEC_CTRL, PPK0_INVLD, 2, 27)
    DEP_FIELD(SEC_CTRL, PPK0_WRLK, 1, 26)
    DEP_FIELD(SEC_CTRL, RSA_EN, 15, 11)
    DEP_FIELD(SEC_CTRL, SEC_LOCK, 1, 10)
    DEP_FIELD(SEC_CTRL, PROG_GATE_2, 1, 9)
    DEP_FIELD(SEC_CTRL, PROG_GATE_1, 1, 8)
    DEP_FIELD(SEC_CTRL, PROG_GATE_0, 1, 7)
    DEP_FIELD(SEC_CTRL, DFT_DIS, 1, 6)
    DEP_FIELD(SEC_CTRL, JTAG_DIS, 1, 5)
    DEP_FIELD(SEC_CTRL, ERROR_DIS, 1, 4)
    DEP_FIELD(SEC_CTRL, BBRAM_DIS, 1, 3)
    DEP_FIELD(SEC_CTRL, ENC_ONLY, 1, 2)
    DEP_FIELD(SEC_CTRL, AES_WRLK, 1, 1)
    DEP_FIELD(SEC_CTRL, AES_RDLK, 1, 0)
DEP_REG32(SPK_ID, 0x105c)
DEP_REG32(PPK0_0, 0x10a0)
DEP_REG32(PPK0_1, 0x10a4)
DEP_REG32(PPK0_2, 0x10a8)
DEP_REG32(PPK0_3, 0x10ac)
DEP_REG32(PPK0_4, 0x10b0)
DEP_REG32(PPK0_5, 0x10b4)
DEP_REG32(PPK0_6, 0x10b8)
DEP_REG32(PPK0_7, 0x10bc)
DEP_REG32(PPK0_8, 0x10c0)
DEP_REG32(PPK0_9, 0x10c4)
DEP_REG32(PPK0_10, 0x10c8)
DEP_REG32(PPK0_11, 0x10cc)
DEP_REG32(PPK1_0, 0x10d0)
DEP_REG32(PPK1_1, 0x10d4)
DEP_REG32(PPK1_2, 0x10d8)
DEP_REG32(PPK1_3, 0x10dc)
DEP_REG32(PPK1_4, 0x10e0)
DEP_REG32(PPK1_5, 0x10e4)
DEP_REG32(PPK1_6, 0x10e8)
DEP_REG32(PPK1_7, 0x10ec)
DEP_REG32(PPK1_8, 0x10f0)
DEP_REG32(PPK1_9, 0x10f4)
DEP_REG32(PPK1_10, 0x10f8)
DEP_REG32(PPK1_11, 0x10fc)

#define BIT_POS(ROW, COLUMN)    (ROW * 32 + COLUMN)
#define R_MAX (R_PPK1_11 + 1)

#define EFUSE_NR 3
#define EFUSE_SIZE (64 * 32)
#define EFUSE_ARRAY_SIZE (EFUSE_SIZE * EFUSE_NR)

/* TBIT pattern is specific to zynqmp */
#define TBITS_PATTERN    0xA

/* #define EFUSE_XOSC            26 */
#define EFUSE_DFT             BIT_POS(22, 6)
#define EFUSE_AES_RDLK        BIT_POS(22, 0)
#define EFUSE_AES_WRLK        BIT_POS(22, 1)
#define EFUSE_ENC_ONLY        BIT_POS(22, 2)
#define EFUSE_BBRAM_DIS       BIT_POS(22, 4)
#define EFUSE_RSA_EN          BIT_POS(22, 24)
#define EFUSE_PPK0_WRLK       BIT_POS(22, 26)
#define EFUSE_PPK0_VALID0     BIT_POS(22, 27)
#define EFUSE_PPK0_VALID1     BIT_POS(22, 28)
#define EFUSE_PPK1_WRLK       BIT_POS(22, 29)
#define EFUSE_PPK1_VALID0     BIT_POS(22, 30)
#define EFUSE_PPK1_VALID1     BIT_POS(22, 31)

/* Areas.  */
#define EFUSE_TRIM_START      BIT_POS(1, 0)
#define EFUSE_TRIM_END        BIT_POS(1, 30)
#define EFUSE_DNA_START       BIT_POS(3, 0)
#define EFUSE_DNA_END         BIT_POS(5, 31)
#define EFUSE_AES_START       BIT_POS(24, 0)
#define EFUSE_AES_END         BIT_POS(31, 31)
#define EFUSE_ROM_START       BIT_POS(17, 0)
#define EFUSE_ROM_END         BIT_POS(17, 31)
#define EFUSE_IPDIS_START     BIT_POS(6, 0)
#define EFUSE_IPDIS_END       BIT_POS(6, 31)
#define EFUSE_USER_START      BIT_POS(8, 0)
#define EFUSE_USER_END        BIT_POS(15, 31)
#define EFUSE_BISR_START      BIT_POS(32, 0)
#define EFUSE_BISR_END        BIT_POS(39, 31)

#define EFUSE_SPK_START       BIT_POS(23, 0)
#define EFUSE_SPK_END         BIT_POS(23, 31)

#define EFUSE_PPK0_START      BIT_POS(40, 0)
#define EFUSE_PPK0_END        BIT_POS(51, 31)
#define EFUSE_PPK1_START      BIT_POS(52, 0)
#define EFUSE_PPK1_END        BIT_POS(63, 31)

/* ZYNQ3 */
#define ZYNQ3_EFUSE_AES_START    BIT_POS(12, 0)
#define ZYNQ3_EFUSE_AES_END      BIT_POS(19, 31)
#define ZYNQ3_EFUSE_USER0_START  BIT_POS(20, 0)
#define ZYNQ3_EFUSE_USER0_END    BIT_POS(27, 31)
#define ZYNQ3_EFUSE_USER1_START  BIT_POS(28, 0)
#define ZYNQ3_EFUSE_USER1_END    BIT_POS(35, 31)
#define ZYNQ3_EFUSE_SEC_DBG0     BIT_POS(43, 19)
#define ZYNQ3_EFUSE_SEC_DBG4     BIT_POS(43, 22)

typedef struct EfuseKey {
    union {
        uint8_t u8[256 / 8];
        uint32_t u32[256 / 32];
    };

    ZynqMPAESKeySink *sink;
} EfuseKey;

typedef struct ZynqMPEFuse {
    SysBusDevice parent_obj;
    MemoryRegion iomem;
    qemu_irq irq;

    EfuseKey key;
    EfuseKey user_key0;
    EfuseKey user_key1;

    XLNXEFuse *efuse;
    void (*refresh_cache)(struct ZynqMPEFuse *, unsigned int);
    uint32_t regs[R_MAX];
    DepRegisterInfo regs_info[R_MAX];
} ZynqMPEFuse;

typedef struct Zynq3EFuse {
    ZynqMPEFuse parent_obj;

    qemu_irq sec_dbg_dis[4];
} Zynq3EFuse;

#define EFUSE_CACHE_BIT(s, reg, field) \
    DEP_AF_DP32((s)->regs, reg, field, efuse_get_bit((s->efuse), \
                EFUSE_ ## field))

static void update_tbit_status(ZynqMPEFuse *s)
{
    unsigned int i;

    for (i = 0; i < EFUSE_NR; i++) {
        unsigned int pattern;

        pattern = efuse_tbits_read(s->efuse, i);

        /* In order to use efuse user must burn the TBITS(Test Bits)
         * So check the tbits for each efuse and update the status.
         * TBITS fixed pattern TBITS_PATTERN */
        if (pattern == TBITS_PATTERN) {
            s->regs[R_STATUS] |= 1 << (i);
        }
    }
}

static void efuse_aes_key_sync(ZynqMPEFuse *s, EfuseKey *key, uint32_t start,
                               uint32_t end)
{
    efuse_sync_u32(s->efuse, key->u32, start, end, FBIT_UNKNOWN);
    if (key->sink) {
        zynqmp_aes_key_update(key->sink, key->u8, sizeof key->u8);
    }
}

/*
 * Keep the syncs in bit order so we can bail out for the
 * slower ones.
 */
static void zynqmp_efuse_sync_cache(ZynqMPEFuse *s, unsigned int bit)
{
    unsigned int i;

    EFUSE_CACHE_BIT(s, SEC_CTRL, AES_RDLK);
    EFUSE_CACHE_BIT(s, SEC_CTRL, AES_WRLK);
    EFUSE_CACHE_BIT(s, SEC_CTRL, ENC_ONLY);
    EFUSE_CACHE_BIT(s, SEC_CTRL, BBRAM_DIS);

    EFUSE_CACHE_BIT(s, SEC_CTRL, RSA_EN);
    EFUSE_CACHE_BIT(s, SEC_CTRL, PPK0_WRLK);
    EFUSE_CACHE_BIT(s, SEC_CTRL, PPK1_WRLK);

    i = efuse_get_bit(s->efuse, EFUSE_PPK0_VALID0);
    i += efuse_get_bit(s->efuse, EFUSE_PPK0_VALID1) * 2;
    DEP_AF_DP32(s->regs, SEC_CTRL, PPK0_INVLD, i);
    i = efuse_get_bit(s->efuse, EFUSE_PPK1_VALID0);
    i += efuse_get_bit(s->efuse, EFUSE_PPK1_VALID1) * 2;
    DEP_AF_DP32(s->regs, SEC_CTRL, PPK1_INVLD, i);

    /* Update the tbits.  */
    update_tbit_status(s);

    /* Sync the various areas.  */
    efuse_sync_u32(s->efuse, &s->regs[R_DNA_0], EFUSE_DNA_START,
                   EFUSE_DNA_END, bit);

    if (bit < EFUSE_AES_START) {
        return;
    }

    /* Sync the AES Key.  */
    efuse_aes_key_sync(s, &s->key, EFUSE_AES_START, EFUSE_AES_END);

    efuse_sync_u32(s->efuse, &s->regs[R_ROM_RSVD],
                   EFUSE_ROM_START, EFUSE_ROM_END, bit);
    efuse_sync_u32(s->efuse, &s->regs[R_IPDISABLE],
                   EFUSE_IPDIS_START, EFUSE_IPDIS_END, bit);
    efuse_sync_u32(s->efuse, &s->regs[R_USER_0],
                   EFUSE_USER_START, EFUSE_USER_END, bit);
    efuse_sync_u32(s->efuse, &s->regs[R_SPK_ID],
                   EFUSE_SPK_START, EFUSE_SPK_END, bit);
    efuse_sync_u32(s->efuse, &s->regs[R_PPK0_0],
                   EFUSE_PPK0_START, EFUSE_PPK0_END, bit);
    efuse_sync_u32(s->efuse, &s->regs[R_PPK1_0],
                   EFUSE_PPK1_START, EFUSE_PPK1_END, bit);
}

static void versal_efuse_sync_cache(ZynqMPEFuse *s, unsigned int bit)
{
    Zynq3EFuse *ss = ZYNQ3_EFUSE(s);
    uint32_t sec_dbg_dis = 0;
    int i;

    /* Update the tbits.  */
    update_tbit_status(s);
    /* Sync the AES Key.  */
    efuse_aes_key_sync(s, &s->key, ZYNQ3_EFUSE_AES_START, ZYNQ3_EFUSE_AES_END);
    efuse_aes_key_sync(s, &s->user_key0, ZYNQ3_EFUSE_USER0_START,
                       ZYNQ3_EFUSE_USER0_END);
    efuse_aes_key_sync(s, &s->user_key1, ZYNQ3_EFUSE_USER1_START,
                       ZYNQ3_EFUSE_USER1_END);
    efuse_sync_u32(s->efuse, &sec_dbg_dis, ZYNQ3_EFUSE_SEC_DBG0,
                   ZYNQ3_EFUSE_SEC_DBG4, FBIT_UNKNOWN);
    for (i = 0; i < 4; i++) {
        qemu_set_irq(ss->sec_dbg_dis[i], !!(sec_dbg_dis & (1 << i)));
    }
}

static void zynqmp_efuse_update_irq(ZynqMPEFuse *s)
{
    bool pending = s->regs[R_EFUSE_ISR] & s->regs[R_EFUSE_IMR];
    qemu_set_irq(s->irq, pending);
}

static void zynqmp_efuse_isr_postw(DepRegisterInfo *reg, uint64_t val64)
{
    ZynqMPEFuse *s = ZYNQMP_EFUSE(reg->opaque);
    zynqmp_efuse_update_irq(s);
}

static uint64_t zynqmp_efuse_ier_prew(DepRegisterInfo *reg, uint64_t val64)
{
    ZynqMPEFuse *s = ZYNQMP_EFUSE(reg->opaque);
    uint32_t val = val64;

    s->regs[R_EFUSE_IMR] |= val;
    zynqmp_efuse_update_irq(s);
    return 0;
}

static uint64_t zynqmp_efuse_idr_prew(DepRegisterInfo *reg, uint64_t val64)
{
    ZynqMPEFuse *s = ZYNQMP_EFUSE(reg->opaque);
    uint32_t val = val64;

    s->regs[R_EFUSE_IMR] &= ~val;
    zynqmp_efuse_update_irq(s);
    return 0;
}

static bool zynqmp_efuse_idx_is_aes_key(unsigned int fuse)
{
    if (fuse >= EFUSE_AES_START && fuse <= EFUSE_AES_END) {
        return true;
    }
    return false;
}

static void zynqmp_efuse_pgm_addr_postw(DepRegisterInfo *reg, uint64_t val64)
{
    ZynqMPEFuse *s = ZYNQMP_EFUSE(reg->opaque);
    bool wr_lock, ps, prot;
    unsigned int efuse_idx;

    efuse_idx = s->regs[R_EFUSE_PGM_ADDR];

    /* TODO: Sanity check the timing setup.  */

    wr_lock = DEP_AF_EX32(s->regs, WR_LOCK, LOCK);
    if (wr_lock) {
        qemu_log_mask(LOG_GUEST_ERROR,
                      "%s: Write to eFuse %u while write protected\n",
                      object_get_canonical_path(OBJECT(s)),
                      efuse_idx);
        return;
    }

    ps = DEP_AF_EX32(s->regs, CFG, PGM_EN);
    if (!ps) {
        qemu_log_mask(LOG_GUEST_ERROR,
                      "%s: Write to eFuse %u while not powered\n",
                      object_get_canonical_path(OBJECT(s)),
                      efuse_idx);
        return;
    }

    /* I'm not sure if this is HW enforced or not.  */
    prot = DEP_AF_EX32(s->regs, SEC_CTRL, AES_WRLK);
    if (prot && zynqmp_efuse_idx_is_aes_key(efuse_idx)) {
        qemu_log_mask(LOG_GUEST_ERROR,
                      "%s: Write to AES key eFuse %u while not wr protected\n",
                      object_get_canonical_path(OBJECT(s)),
                      efuse_idx);
        return;
    }
    efuse_pgm_start(s->efuse, 13, val64);
    /* To Vefify after programming, Cache reload should should happen or
     * Margin Read is done
     * FIXME: Implement Margin Read
     */
}

static void zynqmp_efuse_cfg_postw(DepRegisterInfo *reg, uint64_t val64)
{
    ZynqMPEFuse *s = ZYNQMP_EFUSE(reg->opaque);
    unsigned int ps;
    uint32_t val32 = val64;

    ps = DEP_F_EX32(val32, CFG, PGM_EN);
    efuse_stop_timer_ps(s->efuse);
    if (ps) {
        efuse_set_timer_ps(s->efuse, 500);
    }
}

static uint64_t zynqmp_efuse_cache_load_prew(DepRegisterInfo *reg,
                                             uint64_t valu64)
{
    ZynqMPEFuse *s = ZYNQMP_EFUSE(reg->opaque);

    if (valu64 & R_EFUSE_CACHE_LOAD_LOAD_MASK) {
        s->refresh_cache(s, FBIT_UNKNOWN);
        DEP_AF_DP32(s->regs, STATUS, CACHE_DONE, 1);
        zynqmp_efuse_update_irq(s);
    }

    return 0;
}

static uint64_t zynqmp_wr_lock_prew(DepRegisterInfo *reg, uint64_t val)
{
    return val == 0xDF0D ? 0 : 1;
}

static DepRegisterAccessInfo zynqmp_efuse_regs_info[] = {
    {   .name = "WR_LOCK",  .decode.addr = A_WR_LOCK,
        .reset = 0x1,
        .pre_write = zynqmp_wr_lock_prew,
    },{ .name = "CFG",  .decode.addr = A_CFG,
        .post_write = zynqmp_efuse_cfg_postw
    },{ .name = "STATUS",  .decode.addr = A_STATUS,
        .rsvd = 0x8,
        .ro = 0xff,
    },{ .name = "EFUSE_PGM_ADDR",  .decode.addr = A_EFUSE_PGM_ADDR,
         .post_write = zynqmp_efuse_pgm_addr_postw
    },{ .name = "EFUSE_RD_ADDR",  .decode.addr = A_EFUSE_RD_ADDR,
        .rsvd = 0x1f,
    },{ .name = "EFUSE_RD_DATA",  .decode.addr = A_EFUSE_RD_DATA,
        .ro = 0xffffffff,
    },{ .name = "TPGM",  .decode.addr = A_TPGM,
    },{ .name = "TRD",  .decode.addr = A_TRD,
        .reset = 0x1b,
    },{ .name = "TSU_H_PS",  .decode.addr = A_TSU_H_PS,
        .reset = 0xff,
    },{ .name = "TSU_H_PS_CS",  .decode.addr = A_TSU_H_PS_CS,
        .reset = 0xb,
    },{ .name = "TSU_H_CS",  .decode.addr = A_TSU_H_CS,
        .reset = 0x7,
    },{ .name = "EFUSE_ISR",  .decode.addr = A_EFUSE_ISR,
        .rsvd = 0x7fffffe0,
        .w1c = 0x8000001f,
        .post_write = zynqmp_efuse_isr_postw,
    },{ .name = "EFUSE_IMR",  .decode.addr = A_EFUSE_IMR,
        .reset = 0x8000001f,
        .rsvd = 0x7fffffe0,
        .ro = 0xffffffff,
    },{ .name = "EFUSE_IER",  .decode.addr = A_EFUSE_IER,
        .rsvd = 0x7fffffe0,
        .pre_write = zynqmp_efuse_ier_prew,
    },{ .name = "EFUSE_IDR",  .decode.addr = A_EFUSE_IDR,
        .rsvd = 0x7fffffe0,
        .pre_write = zynqmp_efuse_idr_prew,
    },{ .name = "EFUSE_CACHE_LOAD",  .decode.addr = A_EFUSE_CACHE_LOAD,
        .pre_write = zynqmp_efuse_cache_load_prew,
    },{ .name = "EFUSE_PGM_LOCK",  .decode.addr = A_EFUSE_PGM_LOCK,
    },{ .name = "EFUSE_AES_CRC",  .decode.addr = A_EFUSE_AES_CRC,
    },{ .name = "DNA_0",  .decode.addr = A_DNA_0,
        .ro = 0xffffffff,
    },{ .name = "DNA_1",  .decode.addr = A_DNA_1,
        .ro = 0xffffffff,
    },{ .name = "DNA_2",  .decode.addr = A_DNA_2,
        .ro = 0xffffffff,
    },{ .name = "IPDISABLE",  .decode.addr = A_IPDISABLE,
        .ro = 0xffffffff,
    },{ .name = "SYSOSC_CTRL",  .decode.addr = A_SYSOSC_CTRL,
        .ro = 0xffffffff,
    },{ .name = "USER_0",  .decode.addr = A_USER_0,
        .ro = 0xffffffff,
    },{ .name = "USER_1",  .decode.addr = A_USER_1,
        .ro = 0xffffffff,
    },{ .name = "USER_2",  .decode.addr = A_USER_2,
        .ro = 0xffffffff,
    },{ .name = "USER_3",  .decode.addr = A_USER_3,
        .ro = 0xffffffff,
    },{ .name = "USER_4",  .decode.addr = A_USER_4,
        .ro = 0xffffffff,
    },{ .name = "USER_5",  .decode.addr = A_USER_5,
        .ro = 0xffffffff,
    },{ .name = "USER_6",  .decode.addr = A_USER_6,
        .ro = 0xffffffff,
    },{ .name = "USER_7",  .decode.addr = A_USER_7,
        .ro = 0xffffffff,
    },{ .name = "MISC_USER_CTRL",  .decode.addr = A_MISC_USER_CTRL,
        .ro = 0xffffffff,
    },{ .name = "ROM_RSVD",  .decode.addr = A_ROM_RSVD,
        .ro = 0xffffffff,
    },{ .name = "PUF_MISC",  .decode.addr = A_PUF_MISC,
        .ro = 0xffffffff,
    },{ .name = "SEC_CTRL",  .decode.addr = A_SEC_CTRL,
        .ro = 0xffffffff,
    },{ .name = "SPK_ID",  .decode.addr = A_SPK_ID,
        .ro = 0xffffffff,
    },{ .name = "PPK0_0",  .decode.addr = A_PPK0_0,
        .ro = 0xffffffff,
    },{ .name = "PPK0_1",  .decode.addr = A_PPK0_1,
        .ro = 0xffffffff,
    },{ .name = "PPK0_2",  .decode.addr = A_PPK0_2,
        .ro = 0xffffffff,
    },{ .name = "PPK0_3",  .decode.addr = A_PPK0_3,
        .ro = 0xffffffff,
    },{ .name = "PPK0_4",  .decode.addr = A_PPK0_4,
        .ro = 0xffffffff,
    },{ .name = "PPK0_5",  .decode.addr = A_PPK0_5,
        .ro = 0xffffffff,
    },{ .name = "PPK0_6",  .decode.addr = A_PPK0_6,
        .ro = 0xffffffff,
    },{ .name = "PPK0_7",  .decode.addr = A_PPK0_7,
        .ro = 0xffffffff,
    },{ .name = "PPK0_8",  .decode.addr = A_PPK0_8,
        .ro = 0xffffffff,
    },{ .name = "PPK0_9",  .decode.addr = A_PPK0_9,
        .ro = 0xffffffff,
    },{ .name = "PPK0_10",  .decode.addr = A_PPK0_10,
        .ro = 0xffffffff,
    },{ .name = "PPK0_11",  .decode.addr = A_PPK0_11,
        .ro = 0xffffffff,
    },{ .name = "PPK1_0",  .decode.addr = A_PPK1_0,
        .ro = 0xffffffff,
    },{ .name = "PPK1_1",  .decode.addr = A_PPK1_1,
        .ro = 0xffffffff,
    },{ .name = "PPK1_2",  .decode.addr = A_PPK1_2,
        .ro = 0xffffffff,
    },{ .name = "PPK1_3",  .decode.addr = A_PPK1_3,
        .ro = 0xffffffff,
    },{ .name = "PPK1_4",  .decode.addr = A_PPK1_4,
        .ro = 0xffffffff,
    },{ .name = "PPK1_5",  .decode.addr = A_PPK1_5,
        .ro = 0xffffffff,
    },{ .name = "PPK1_6",  .decode.addr = A_PPK1_6,
        .ro = 0xffffffff,
    },{ .name = "PPK1_7",  .decode.addr = A_PPK1_7,
        .ro = 0xffffffff,
    },{ .name = "PPK1_8",  .decode.addr = A_PPK1_8,
        .ro = 0xffffffff,
    },{ .name = "PPK1_9",  .decode.addr = A_PPK1_9,
        .ro = 0xffffffff,
    },{ .name = "PPK1_10",  .decode.addr = A_PPK1_10,
        .ro = 0xffffffff,
    },{ .name = "PPK1_11",  .decode.addr = A_PPK1_11,
        .ro = 0xffffffff,
    }
};

static uint64_t zynqmp_efuse_mem_read(void *opaque, hwaddr addr, unsigned size)
{
    DepRegisterInfo *regi = opaque;
    ZynqMPEFuse *s = ZYNQMP_EFUSE(regi->opaque);
    uint32_t v;

    /* Process programming completion if late.  */
    efuse_pgm_complete(s->efuse);

    if (efuse_is_pgm(s->efuse)) {
        qemu_log_mask(LOG_GUEST_ERROR,
                      "%s: Accessing device while programming\n",
                      object_get_canonical_path(OBJECT(s)));
    }
    v = dep_register_read(regi);
    return v;
}

static MemTxResult zynqmp_efuse_mem_write_with_attrs(void *opaque, hwaddr addr,
                            uint64_t v64, unsigned size, MemTxAttrs attrs)
{
    DepRegisterInfo reg;
    DepRegisterAccessInfo access;
    DepRegisterInfo *regi = opaque;
    ZynqMPEFuse *s;

    if (attrs.debug) {
        dep_register_trap_access(opaque, &reg, &access);
        regi = &reg;
    }
    s = ZYNQMP_EFUSE(regi->opaque);

    /* Process programming completion if late.  */
    efuse_pgm_complete(s->efuse);

    if (efuse_is_pgm(s->efuse)) {
        qemu_log_mask(LOG_GUEST_ERROR,
                      "%s: Accessing device while programming\n",
                      object_get_canonical_path(OBJECT(s)));
    }
    dep_register_write(regi, v64, ~0);
    return MEMTX_OK;
}

static const MemoryRegionOps zynqmp_efuse_ops = {
    .read = zynqmp_efuse_mem_read,
    .write_with_attrs = zynqmp_efuse_mem_write_with_attrs,
    .endianness = DEVICE_LITTLE_ENDIAN,
    .valid = {
        .min_access_size = 4,
        .max_access_size = 4,
    },
};

static void zynqmp_efuse_reset(DeviceState *dev)
{
    ZynqMPEFuse *s = ZYNQMP_EFUSE(dev);
    unsigned int i;

    for (i = 0; i < ARRAY_SIZE(s->regs_info); ++i) {
        dep_register_reset(&s->regs_info[i]);
    }

    s->refresh_cache(s, FBIT_UNKNOWN);
    DEP_AF_DP32(s->regs, STATUS, CACHE_DONE, 1);
    zynqmp_efuse_update_irq(s);
}

static void zynqmp_efuse_realize(DeviceState *dev, Error **errp)
{
    ZynqMPEFuse *s = ZYNQMP_EFUSE(dev);
    const char *prefix = object_get_canonical_path(OBJECT(dev));
    unsigned int i;

    if (!s->key.sink) {
        error_report("%s: AES key sink not connected\n", prefix);
        exit(1);
    }

    for (i = 0; i < ARRAY_SIZE(zynqmp_efuse_regs_info); ++i) {
        DepRegisterInfo *r = &s->regs_info[
                             zynqmp_efuse_regs_info[i].decode.addr / 4];

        *r = (DepRegisterInfo) {
            .data = (uint8_t *)&s->regs[
                    zynqmp_efuse_regs_info[i].decode.addr / 4],
            .data_size = sizeof(uint32_t),
            .access = &zynqmp_efuse_regs_info[i],
            .debug = ZYNQMP_EFUSE_ERR_DEBUG,
            .prefix = prefix,
            .opaque = s,
        };
        memory_region_init_io(&r->mem, OBJECT(dev), &zynqmp_efuse_ops, r,
                              r->access->name, 4);
        memory_region_add_subregion(&s->iomem, r->access->decode.addr, &r->mem);
    }
}

static void versal_efuse_realize(DeviceState *dev, Error **errp)
{
    Zynq3EFuse *s = ZYNQ3_EFUSE(dev);

    qdev_init_gpio_out(dev, s->sec_dbg_dis, 4);
    zynqmp_efuse_realize(dev, errp);
}

static void zynqmp_efuse_init(Object *obj)
{
    ZynqMPEFuse *s = ZYNQMP_EFUSE(obj);
    SysBusDevice *sbd = SYS_BUS_DEVICE(obj);

    object_property_add_link(obj, "zynqmp-aes-key-sink-efuses",
                                 TYPE_ZYNQMP_AES_KEY_SINK,
                                 (Object **)&s->key.sink,
                                 qdev_prop_allow_set_link_before_realize,
                                 OBJ_PROP_LINK_UNREF_ON_RELEASE,
                                 NULL);
    object_property_add_link(obj, "zynqmp-aes-key-sink-efuses-user0",
                                 TYPE_ZYNQMP_AES_KEY_SINK,
                                 (Object **)&s->user_key0.sink,
                                 qdev_prop_allow_set_link_before_realize,
                                 OBJ_PROP_LINK_UNREF_ON_RELEASE,
                                 NULL);
    object_property_add_link(obj, "zynqmp-aes-key-sink-efuses-user1",
                                 TYPE_ZYNQMP_AES_KEY_SINK,
                                 (Object **)&s->user_key1.sink,
                                 qdev_prop_allow_set_link_before_realize,
                                 OBJ_PROP_LINK_UNREF_ON_RELEASE,
                                 NULL);
    object_property_add_link(obj, "efuse",
                            TYPE_XLNX_EFUSE,
                            (Object **)&s->efuse,
                            qdev_prop_allow_set_link_before_realize,
                            OBJ_PROP_LINK_STRONG,
                            NULL);
    memory_region_init(&s->iomem, obj, TYPE_ZYNQMP_EFUSE, R_MAX * 4);
    sysbus_init_mmio(sbd, &s->iomem);
    sysbus_init_irq(sbd, &s->irq);

    s->refresh_cache = zynqmp_efuse_sync_cache;
}

static void versal_efuse_init(Object *obj)
{
    ZynqMPEFuse *s = ZYNQMP_EFUSE(obj);

    s->refresh_cache = versal_efuse_sync_cache;
}

static const VMStateDescription vmstate_efuse = {
    .name = TYPE_ZYNQMP_EFUSE,
    .version_id = 1,
    .minimum_version_id = 1,
    .minimum_version_id_old = 1,
    .fields = (VMStateField[]) {
        VMSTATE_UINT32_ARRAY(regs, ZynqMPEFuse, R_MAX),
        VMSTATE_END_OF_LIST(),
    }
};

static void zynqmp_efuse_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = zynqmp_efuse_reset;
    dc->realize = zynqmp_efuse_realize;
    dc->vmsd = &vmstate_efuse;
}

static void versal_efuse_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->realize = versal_efuse_realize;
}


static const TypeInfo efuse_info = {
    .name          = TYPE_ZYNQMP_EFUSE,
    .parent        = TYPE_SYS_BUS_DEVICE,
    .instance_size = sizeof(ZynqMPEFuse),
    .class_init    = zynqmp_efuse_class_init,
    .instance_init = zynqmp_efuse_init,
};

static const TypeInfo versal_efuse_info = {
    .name          = TYPE_ZYNQ3_EFUSE,
    .parent        = TYPE_ZYNQMP_EFUSE,
    .instance_size = sizeof(Zynq3EFuse),
    .class_init    = versal_efuse_class_init,
    .instance_init = versal_efuse_init,
};

static void efuse_register_types(void)
{
    type_register_static(&efuse_info);
    type_register_static(&versal_efuse_info);
}

type_init(efuse_register_types)
