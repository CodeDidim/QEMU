/* This file is autogenerated by scripts/decodetree.py.  */

typedef struct {
    int rot;
    int q;
    int vm;
    int vn;
    int vd;
    int size;
} arg_disas_neon_shared0;

typedef struct {
    int q;
    int vm;
    int vn;
    int vd;
} arg_disas_neon_shared1;

typedef struct {
    int s;
    int vm;
    int vn;
    int vd;
    int q;
} arg_disas_neon_shared2;

typedef struct {
    int vm;
    int vn;
    int vd;
} arg_disas_neon_shared3;

typedef struct {
    int rot;
    int q;
    int index;
    int vm;
    int vn;
    int vd;
    int size;
} arg_disas_neon_shared4;

typedef struct {
    int q;
    int index;
    int vm;
    int vn;
    int vd;
} arg_disas_neon_shared5;

typedef struct {
    int s;
    int index;
    int rm;
    int vn;
    int vd;
    int q;
} arg_disas_neon_shared6;

typedef arg_disas_neon_shared0 arg_VCMLA;
static bool trans_VCMLA(DisasContext *ctx, arg_VCMLA *a);
typedef arg_disas_neon_shared0 arg_VCADD;
static bool trans_VCADD(DisasContext *ctx, arg_VCADD *a);
typedef arg_disas_neon_shared1 arg_VSDOT;
static bool trans_VSDOT(DisasContext *ctx, arg_VSDOT *a);
typedef arg_disas_neon_shared1 arg_VUDOT;
static bool trans_VUDOT(DisasContext *ctx, arg_VUDOT *a);
typedef arg_disas_neon_shared1 arg_VUSDOT;
static bool trans_VUSDOT(DisasContext *ctx, arg_VUSDOT *a);
typedef arg_disas_neon_shared1 arg_VDOT_b16;
static bool trans_VDOT_b16(DisasContext *ctx, arg_VDOT_b16 *a);
typedef arg_disas_neon_shared2 arg_VFML;
static bool trans_VFML(DisasContext *ctx, arg_VFML *a);
typedef arg_disas_neon_shared3 arg_VSMMLA;
static bool trans_VSMMLA(DisasContext *ctx, arg_VSMMLA *a);
typedef arg_disas_neon_shared3 arg_VUMMLA;
static bool trans_VUMMLA(DisasContext *ctx, arg_VUMMLA *a);
typedef arg_disas_neon_shared3 arg_VUSMMLA;
static bool trans_VUSMMLA(DisasContext *ctx, arg_VUSMMLA *a);
typedef arg_disas_neon_shared3 arg_VMMLA_b16;
static bool trans_VMMLA_b16(DisasContext *ctx, arg_VMMLA_b16 *a);
typedef arg_disas_neon_shared1 arg_VFMA_b16;
static bool trans_VFMA_b16(DisasContext *ctx, arg_VFMA_b16 *a);
typedef arg_disas_neon_shared4 arg_VCMLA_scalar;
static bool trans_VCMLA_scalar(DisasContext *ctx, arg_VCMLA_scalar *a);
typedef arg_disas_neon_shared5 arg_VSDOT_scalar;
static bool trans_VSDOT_scalar(DisasContext *ctx, arg_VSDOT_scalar *a);
typedef arg_disas_neon_shared5 arg_VUDOT_scalar;
static bool trans_VUDOT_scalar(DisasContext *ctx, arg_VUDOT_scalar *a);
typedef arg_disas_neon_shared5 arg_VUSDOT_scalar;
static bool trans_VUSDOT_scalar(DisasContext *ctx, arg_VUSDOT_scalar *a);
typedef arg_disas_neon_shared5 arg_VSUDOT_scalar;
static bool trans_VSUDOT_scalar(DisasContext *ctx, arg_VSUDOT_scalar *a);
typedef arg_disas_neon_shared5 arg_VDOT_b16_scal;
static bool trans_VDOT_b16_scal(DisasContext *ctx, arg_VDOT_b16_scal *a);
typedef arg_disas_neon_shared6 arg_VFML_scalar;
static bool trans_VFML_scalar(DisasContext *ctx, arg_VFML_scalar *a);
typedef arg_disas_neon_shared5 arg_VFMA_b16_scal;
static bool trans_VFMA_b16_scal(DisasContext *ctx, arg_VFMA_b16_scal *a);

static void disas_neon_shared_extract_disas_neon_shared_Fmt_0(DisasContext *ctx, arg_disas_neon_shared0 *a, uint32_t insn)
{
    a->rot = extract32(insn, 23, 2);
    a->size = plus_1(ctx, extract32(insn, 20, 1));
    a->vd = deposit32(extract32(insn, 12, 4), 4, 28, extract32(insn, 22, 1));
    a->q = extract32(insn, 6, 1);
    a->vm = deposit32(extract32(insn, 0, 4), 4, 28, extract32(insn, 5, 1));
    a->vn = deposit32(extract32(insn, 16, 4), 4, 28, extract32(insn, 7, 1));
}

static void disas_neon_shared_extract_disas_neon_shared_Fmt_1(DisasContext *ctx, arg_disas_neon_shared0 *a, uint32_t insn)
{
    a->rot = extract32(insn, 24, 1);
    a->size = plus_1(ctx, extract32(insn, 20, 1));
    a->vd = deposit32(extract32(insn, 12, 4), 4, 28, extract32(insn, 22, 1));
    a->q = extract32(insn, 6, 1);
    a->vm = deposit32(extract32(insn, 0, 4), 4, 28, extract32(insn, 5, 1));
    a->vn = deposit32(extract32(insn, 16, 4), 4, 28, extract32(insn, 7, 1));
}

static void disas_neon_shared_extract_disas_neon_shared_Fmt_10(DisasContext *ctx, arg_disas_neon_shared6 *a, uint32_t insn)
{
    a->rm = extract32(insn, 0, 3);
    a->vd = deposit32(extract32(insn, 12, 4), 4, 28, extract32(insn, 22, 1));
    a->q = 1;
    a->index = deposit32(extract32(insn, 3, 1), 1, 31, extract32(insn, 5, 1));
    a->vn = deposit32(extract32(insn, 16, 4), 4, 28, extract32(insn, 7, 1));
    a->s = extract32(insn, 20, 1);
}

static void disas_neon_shared_extract_disas_neon_shared_Fmt_11(DisasContext *ctx, arg_disas_neon_shared5 *a, uint32_t insn)
{
    a->vd = deposit32(extract32(insn, 12, 4), 4, 28, extract32(insn, 22, 1));
    a->q = extract32(insn, 6, 1);
    a->index = deposit32(extract32(insn, 3, 1), 1, 31, extract32(insn, 5, 1));
    a->vm = extract32(insn, 0, 3);
    a->vn = deposit32(extract32(insn, 16, 4), 4, 28, extract32(insn, 7, 1));
}

static void disas_neon_shared_extract_disas_neon_shared_Fmt_2(DisasContext *ctx, arg_disas_neon_shared1 *a, uint32_t insn)
{
    a->vd = deposit32(extract32(insn, 12, 4), 4, 28, extract32(insn, 22, 1));
    a->vm = deposit32(extract32(insn, 0, 4), 4, 28, extract32(insn, 5, 1));
    a->vn = deposit32(extract32(insn, 16, 4), 4, 28, extract32(insn, 7, 1));
    a->q = extract32(insn, 6, 1);
}

static void disas_neon_shared_extract_disas_neon_shared_Fmt_3(DisasContext *ctx, arg_disas_neon_shared2 *a, uint32_t insn)
{
    a->vd = deposit32(extract32(insn, 12, 4), 4, 28, extract32(insn, 22, 1));
    a->q = 0;
    a->vm = deposit32(extract32(insn, 5, 1), 1, 31, extract32(insn, 0, 4));
    a->vn = deposit32(extract32(insn, 7, 1), 1, 31, extract32(insn, 16, 4));
    a->s = extract32(insn, 23, 1);
}

static void disas_neon_shared_extract_disas_neon_shared_Fmt_4(DisasContext *ctx, arg_disas_neon_shared2 *a, uint32_t insn)
{
    a->vd = deposit32(extract32(insn, 12, 4), 4, 28, extract32(insn, 22, 1));
    a->q = 1;
    a->vm = deposit32(extract32(insn, 0, 4), 4, 28, extract32(insn, 5, 1));
    a->vn = deposit32(extract32(insn, 16, 4), 4, 28, extract32(insn, 7, 1));
    a->s = extract32(insn, 23, 1);
}

static void disas_neon_shared_extract_disas_neon_shared_Fmt_5(DisasContext *ctx, arg_disas_neon_shared3 *a, uint32_t insn)
{
    a->vd = deposit32(extract32(insn, 12, 4), 4, 28, extract32(insn, 22, 1));
    a->vm = deposit32(extract32(insn, 0, 4), 4, 28, extract32(insn, 5, 1));
    a->vn = deposit32(extract32(insn, 16, 4), 4, 28, extract32(insn, 7, 1));
}

static void disas_neon_shared_extract_disas_neon_shared_Fmt_6(DisasContext *ctx, arg_disas_neon_shared4 *a, uint32_t insn)
{
    a->rot = extract32(insn, 20, 2);
    a->size = 1;
    a->vd = deposit32(extract32(insn, 12, 4), 4, 28, extract32(insn, 22, 1));
    a->q = extract32(insn, 6, 1);
    a->index = extract32(insn, 5, 1);
    a->vm = extract32(insn, 0, 4);
    a->vn = deposit32(extract32(insn, 16, 4), 4, 28, extract32(insn, 7, 1));
}

static void disas_neon_shared_extract_disas_neon_shared_Fmt_7(DisasContext *ctx, arg_disas_neon_shared4 *a, uint32_t insn)
{
    a->rot = extract32(insn, 20, 2);
    a->size = 2;
    a->vd = deposit32(extract32(insn, 12, 4), 4, 28, extract32(insn, 22, 1));
    a->q = extract32(insn, 6, 1);
    a->index = 0;
    a->vm = deposit32(extract32(insn, 0, 4), 4, 28, extract32(insn, 5, 1));
    a->vn = deposit32(extract32(insn, 16, 4), 4, 28, extract32(insn, 7, 1));
}

static void disas_neon_shared_extract_disas_neon_shared_Fmt_8(DisasContext *ctx, arg_disas_neon_shared5 *a, uint32_t insn)
{
    a->vd = deposit32(extract32(insn, 12, 4), 4, 28, extract32(insn, 22, 1));
    a->q = extract32(insn, 6, 1);
    a->index = extract32(insn, 5, 1);
    a->vm = extract32(insn, 0, 4);
    a->vn = deposit32(extract32(insn, 16, 4), 4, 28, extract32(insn, 7, 1));
}

static void disas_neon_shared_extract_disas_neon_shared_Fmt_9(DisasContext *ctx, arg_disas_neon_shared6 *a, uint32_t insn)
{
    a->rm = deposit32(extract32(insn, 5, 1), 1, 31, extract32(insn, 0, 3));
    a->vd = deposit32(extract32(insn, 12, 4), 4, 28, extract32(insn, 22, 1));
    a->q = 0;
    a->index = extract32(insn, 3, 1);
    a->vn = deposit32(extract32(insn, 7, 1), 1, 31, extract32(insn, 16, 4));
    a->s = extract32(insn, 20, 1);
}

bool disas_neon_shared(DisasContext *ctx, uint32_t insn)
{
    union {
        arg_disas_neon_shared0 f_disas_neon_shared0;
        arg_disas_neon_shared1 f_disas_neon_shared1;
        arg_disas_neon_shared2 f_disas_neon_shared2;
        arg_disas_neon_shared3 f_disas_neon_shared3;
        arg_disas_neon_shared4 f_disas_neon_shared4;
        arg_disas_neon_shared5 f_disas_neon_shared5;
        arg_disas_neon_shared6 f_disas_neon_shared6;
    } u;

    switch (insn & 0xfe000f10u) {
    case 0xfc000800u:
        /* 1111110. ........ ....1000 ...0.... */
        switch ((insn >> 21) & 0x1) {
        case 0x0:
            /* 1111110. ..0..... ....1000 ...0.... */
            disas_neon_shared_extract_disas_neon_shared_Fmt_1(ctx, &u.f_disas_neon_shared0, insn);
            switch ((insn >> 23) & 0x1) {
            case 0x1:
                /* 1111110. 1.0..... ....1000 ...0.... */
                /* ../target/arm/tcg/neon-shared.decode:46 */
                if (trans_VCADD(ctx, &u.f_disas_neon_shared0)) return true;
                break;
            }
            break;
        case 0x1:
            /* 1111110. ..1..... ....1000 ...0.... */
            /* ../target/arm/tcg/neon-shared.decode:43 */
            disas_neon_shared_extract_disas_neon_shared_Fmt_0(ctx, &u.f_disas_neon_shared0, insn);
            if (trans_VCMLA(ctx, &u.f_disas_neon_shared0)) return true;
            break;
        }
        break;
    case 0xfc000810u:
        /* 1111110. ........ ....1000 ...1.... */
        switch (insn & 0x01300000) {
        case 0x00200000:
            /* 11111100 ..10.... ....1000 ...1.... */
            switch ((insn >> 6) & 0x1) {
            case 0x0:
                /* 11111100 ..10.... ....1000 .0.1.... */
                /* ../target/arm/tcg/neon-shared.decode:59 */
                disas_neon_shared_extract_disas_neon_shared_Fmt_3(ctx, &u.f_disas_neon_shared2, insn);
                if (trans_VFML(ctx, &u.f_disas_neon_shared2)) return true;
                break;
            case 0x1:
                /* 11111100 ..10.... ....1000 .1.1.... */
                /* ../target/arm/tcg/neon-shared.decode:61 */
                disas_neon_shared_extract_disas_neon_shared_Fmt_4(ctx, &u.f_disas_neon_shared2, insn);
                if (trans_VFML(ctx, &u.f_disas_neon_shared2)) return true;
                break;
            }
            break;
        case 0x00300000:
            /* 11111100 ..11.... ....1000 ...1.... */
            disas_neon_shared_extract_disas_neon_shared_Fmt_2(ctx, &u.f_disas_neon_shared1, insn);
            switch ((insn >> 23) & 0x1) {
            case 0x0:
                /* 11111100 0.11.... ....1000 ...1.... */
                /* ../target/arm/tcg/neon-shared.decode:73 */
                if (trans_VFMA_b16(ctx, &u.f_disas_neon_shared1)) return true;
                break;
            }
            break;
        }
        break;
    case 0xfc000c00u:
        /* 1111110. ........ ....1100 ...0.... */
        disas_neon_shared_extract_disas_neon_shared_Fmt_5(ctx, &u.f_disas_neon_shared3, insn);
        switch (insn & 0x01b00040) {
        case 0x00000040:
            /* 11111100 0.00.... ....1100 .1.0.... */
            /* ../target/arm/tcg/neon-shared.decode:70 */
            if (trans_VMMLA_b16(ctx, &u.f_disas_neon_shared3)) return true;
            break;
        case 0x00200040:
            /* 11111100 0.10.... ....1100 .1.0.... */
            /* ../target/arm/tcg/neon-shared.decode:64 */
            if (trans_VSMMLA(ctx, &u.f_disas_neon_shared3)) return true;
            break;
        case 0x00a00040:
            /* 11111100 1.10.... ....1100 .1.0.... */
            /* ../target/arm/tcg/neon-shared.decode:68 */
            if (trans_VUSMMLA(ctx, &u.f_disas_neon_shared3)) return true;
            break;
        }
        break;
    case 0xfc000c10u:
        /* 1111110. ........ ....1100 ...1.... */
        disas_neon_shared_extract_disas_neon_shared_Fmt_5(ctx, &u.f_disas_neon_shared3, insn);
        switch (insn & 0x01b00040) {
        case 0x00200040:
            /* 11111100 0.10.... ....1100 .1.1.... */
            /* ../target/arm/tcg/neon-shared.decode:66 */
            if (trans_VUMMLA(ctx, &u.f_disas_neon_shared3)) return true;
            break;
        }
        break;
    case 0xfc000d00u:
        /* 1111110. ........ ....1101 ...0.... */
        disas_neon_shared_extract_disas_neon_shared_Fmt_2(ctx, &u.f_disas_neon_shared1, insn);
        switch (insn & 0x01b00000) {
        case 0x00000000:
            /* 11111100 0.00.... ....1101 ...0.... */
            /* ../target/arm/tcg/neon-shared.decode:55 */
            if (trans_VDOT_b16(ctx, &u.f_disas_neon_shared1)) return true;
            break;
        case 0x00200000:
            /* 11111100 0.10.... ....1101 ...0.... */
            /* ../target/arm/tcg/neon-shared.decode:49 */
            if (trans_VSDOT(ctx, &u.f_disas_neon_shared1)) return true;
            break;
        case 0x00a00000:
            /* 11111100 1.10.... ....1101 ...0.... */
            /* ../target/arm/tcg/neon-shared.decode:53 */
            if (trans_VUSDOT(ctx, &u.f_disas_neon_shared1)) return true;
            break;
        }
        break;
    case 0xfc000d10u:
        /* 1111110. ........ ....1101 ...1.... */
        disas_neon_shared_extract_disas_neon_shared_Fmt_2(ctx, &u.f_disas_neon_shared1, insn);
        switch (insn & 0x01b00000) {
        case 0x00200000:
            /* 11111100 0.10.... ....1101 ...1.... */
            /* ../target/arm/tcg/neon-shared.decode:51 */
            if (trans_VUDOT(ctx, &u.f_disas_neon_shared1)) return true;
            break;
        }
        break;
    case 0xfe000800u:
        /* 1111111. ........ ....1000 ...0.... */
        switch ((insn >> 23) & 0x3) {
        case 0x0:
            /* 11111110 0....... ....1000 ...0.... */
            /* ../target/arm/tcg/neon-shared.decode:76 */
            disas_neon_shared_extract_disas_neon_shared_Fmt_6(ctx, &u.f_disas_neon_shared4, insn);
            if (trans_VCMLA_scalar(ctx, &u.f_disas_neon_shared4)) return true;
            break;
        case 0x1:
            /* 11111110 1....... ....1000 ...0.... */
            /* ../target/arm/tcg/neon-shared.decode:78 */
            disas_neon_shared_extract_disas_neon_shared_Fmt_7(ctx, &u.f_disas_neon_shared4, insn);
            if (trans_VCMLA_scalar(ctx, &u.f_disas_neon_shared4)) return true;
            break;
        }
        break;
    case 0xfe000810u:
        /* 1111111. ........ ....1000 ...1.... */
        switch (insn & 0x01a00000) {
        case 0x00000000:
            /* 11111110 0.0..... ....1000 ...1.... */
            switch ((insn >> 6) & 0x1) {
            case 0x0:
                /* 11111110 0.0..... ....1000 .0.1.... */
                /* ../target/arm/tcg/neon-shared.decode:94 */
                disas_neon_shared_extract_disas_neon_shared_Fmt_9(ctx, &u.f_disas_neon_shared6, insn);
                if (trans_VFML_scalar(ctx, &u.f_disas_neon_shared6)) return true;
                break;
            case 0x1:
                /* 11111110 0.0..... ....1000 .1.1.... */
                /* ../target/arm/tcg/neon-shared.decode:96 */
                disas_neon_shared_extract_disas_neon_shared_Fmt_10(ctx, &u.f_disas_neon_shared6, insn);
                if (trans_VFML_scalar(ctx, &u.f_disas_neon_shared6)) return true;
                break;
            }
            break;
        case 0x00200000:
            /* 11111110 0.1..... ....1000 ...1.... */
            disas_neon_shared_extract_disas_neon_shared_Fmt_11(ctx, &u.f_disas_neon_shared5, insn);
            switch ((insn >> 20) & 0x1) {
            case 0x1:
                /* 11111110 0.11.... ....1000 ...1.... */
                /* ../target/arm/tcg/neon-shared.decode:98 */
                if (trans_VFMA_b16_scal(ctx, &u.f_disas_neon_shared5)) return true;
                break;
            }
            break;
        }
        break;
    case 0xfe000d00u:
        /* 1111111. ........ ....1101 ...0.... */
        disas_neon_shared_extract_disas_neon_shared_Fmt_8(ctx, &u.f_disas_neon_shared5, insn);
        switch (insn & 0x01b00000) {
        case 0x00000000:
            /* 11111110 0.00.... ....1101 ...0.... */
            /* ../target/arm/tcg/neon-shared.decode:89 */
            if (trans_VDOT_b16_scal(ctx, &u.f_disas_neon_shared5)) return true;
            break;
        case 0x00200000:
            /* 11111110 0.10.... ....1101 ...0.... */
            /* ../target/arm/tcg/neon-shared.decode:81 */
            if (trans_VSDOT_scalar(ctx, &u.f_disas_neon_shared5)) return true;
            break;
        case 0x00800000:
            /* 11111110 1.00.... ....1101 ...0.... */
            /* ../target/arm/tcg/neon-shared.decode:85 */
            if (trans_VUSDOT_scalar(ctx, &u.f_disas_neon_shared5)) return true;
            break;
        }
        break;
    case 0xfe000d10u:
        /* 1111111. ........ ....1101 ...1.... */
        disas_neon_shared_extract_disas_neon_shared_Fmt_8(ctx, &u.f_disas_neon_shared5, insn);
        switch (insn & 0x01b00000) {
        case 0x00200000:
            /* 11111110 0.10.... ....1101 ...1.... */
            /* ../target/arm/tcg/neon-shared.decode:83 */
            if (trans_VUDOT_scalar(ctx, &u.f_disas_neon_shared5)) return true;
            break;
        case 0x00800000:
            /* 11111110 1.00.... ....1101 ...1.... */
            /* ../target/arm/tcg/neon-shared.decode:87 */
            if (trans_VSUDOT_scalar(ctx, &u.f_disas_neon_shared5)) return true;
            break;
        }
        break;
    }
    return false;
}