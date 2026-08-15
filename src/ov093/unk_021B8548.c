#include "types.h"

// Battle system object owned by ov093.  Only the offsets actually constrained
// by the accessors in this file are named; the gaps are opaque padding.
typedef struct BattleCore {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ u32 unk_04;
    /* 0x08 */ u8 unk_08[0x12];
    /* 0x1A */ u16 unk_1A;
    /* 0x1C */ u8 unk_1C[0x04];
    /* 0x20 */ u8 unk_20;
    /* 0x21 */ u8 unk_21;
    /* 0x22 */ u8 unk_22;
    /* 0x23 */ u8 unk_23;
    /* 0x24 */ u8 unk_24[0x34];
    /* 0x58 */ u32 unk_58;
    /* 0x5C */ u32 unk_5C;
    /* 0x60 */ void *unk_60;
    /* 0x64 */ void *unk_64;
    /* 0x68 */ void *unk_68;
    /* 0x6C */ u32 unk_6C;
    /* 0x70 */ u32 unk_70;
    /* 0x74 */ u8 unk_74[0x0C];
    /* 0x80 */ u8 unk_80;
} BattleCore;

typedef struct BattleSystem {
    /* 0x000 */ BattleCore *core;
    /* 0x004 */ u8 unk_004[0x00C];
    /* 0x010 */ void *unk_010[4];
    /* 0x020 */ u8 unk_020[0x0A0];
    /* 0x0C0 */ void *unk_0C0;
    /* 0x0C4 */ u8 unk_0C4[0x004];
    /* 0x0C8 */ u8 unk_0C8[0x374];
    /* 0x43C */ void *unk_43C;
    /* 0x440 */ u8 unk_440[0x028];
    /* 0x468 */ u16 unk_468;
    /* 0x46A */ u8 unk_46A[0x002];
    /* 0x46C */ u8 unk_46C;
    /* 0x46D */ u8 unk_46D[0x006];
    /* 0x473 */ u8 unk_473_0 : 1;
                u8 unk_473_1 : 1;
                u8 unk_473_2 : 1;
                u8 unk_473_3 : 1;
                u8 unk_473_4 : 1;
                u8 unk_473_5 : 1;
                u8 unk_473_6 : 1;
                u8 unk_473_7 : 1;
} BattleSystem;

void sub_021CD914(void *a0);
void *sub_021D5444(int a0);
void *sub_021D5844(int a0);
void sub_0200CED4(void *a0, void *a1);
void sub_0200CFA0(void *a0, void *a1);
u32 sub_020083C8(u32 a0);

BOOL sub_021B8B9C(BattleSystem *bsys, u8 a1);
void sub_021B969C(u8 *a0, BattleSystem *bsys, int a2, int a3);
u32 sub_021B985C(u8 *a0, int a1);
void sub_02007E50(void *a0, int a1, int a2, u16 a3);
void sub_02007F1C(void *a0, int a1, int a2, u16 a3);

u32 sub_021B8588(BattleSystem *bsys);
u32 sub_021B8670(BattleSystem *bsys);
u32 sub_021B86B8(BattleSystem *bsys);
BOOL sub_021B86C8(BattleSystem *bsys);
u32 sub_021B86C0(BattleSystem *bsys);
u8 sub_021B8FC0(BattleSystem *bsys, int a1);
u8 sub_021B9010(BattleSystem *bsys, int a1);
u8 sub_021B9064(BattleSystem *bsys, u8 a1, int a2);

void sub_021B8548(BattleSystem *bsys)
{
    u32 i;

    for (i = 0; i < 4; i++) {
        if (bsys->unk_010[i] != NULL) {
            sub_021CD914(bsys->unk_010[i]);
        }
    }
}

BOOL sub_021B8564(BattleSystem *bsys)
{
    u32 i;

    for (i = 0; i < 4; i++) {
        if (bsys->unk_010[i] != NULL && bsys->unk_0C4[i] == 0) {
            return FALSE;
        }
    }
    return TRUE;
}

u32 sub_021B8588(BattleSystem *bsys)
{
    return bsys->core->unk_04;
}

u32 sub_021B8590(BattleSystem *bsys)
{
    return bsys->unk_473_2;
}

u32 sub_021B85A0(BattleSystem *bsys)
{
    return bsys->core->unk_80;
}

BOOL sub_021B85A8(BattleSystem *bsys)
{
    if (sub_021B86B8(bsys) == 1 && sub_021B8588(bsys) == 0 && sub_021B86C0(bsys) == 0
        && sub_020083C8(bsys->core->unk_5C) == 0) {
        return TRUE;
    }
    return FALSE;
}

u32 sub_021B8630(BattleSystem *bsys)
{
    BattleCore *core = bsys->core;

    if (core->unk_00 <= 1) {
        return core->unk_70;
    }
    return 0;
}

u32 sub_021B8640(BattleSystem *bsys)
{
    switch (bsys->core->unk_04) {
    case 0:
        return 1;
    case 1:
        return 3;
    case 2:
        return 5;
    case 3:
        return 5;
    default:
        return 5;
    }
}

u32 sub_021B8670(BattleSystem *bsys)
{
    switch (bsys->core->unk_04) {
    case 0:
        return 1;
    case 1:
        return 2;
    case 2:
        return 3;
    case 3:
        return 1;
    default:
        return 1;
    }
}

BOOL sub_021B86A0(BattleSystem *bsys, u32 a1)
{
    if (a1 < sub_021B8670(bsys) * 2) {
        return TRUE;
    }
    return FALSE;
}

u32 sub_021B86B8(BattleSystem *bsys)
{
    return bsys->core->unk_00;
}

u32 sub_021B86C0(BattleSystem *bsys)
{
    return bsys->core->unk_20;
}

BOOL sub_021B86C8(BattleSystem *bsys)
{
    if (bsys->core->unk_22 != 0) {
        return TRUE;
    }
    return FALSE;
}

u32 sub_021B86DC(BattleSystem *bsys)
{
    return bsys->core->unk_1A;
}

u32 sub_021B86E4(BattleSystem *bsys)
{
    switch (bsys->core->unk_00) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 2;
    default:
        return 1;
    }
}

u8 *sub_021B8714(BattleSystem *bsys)
{
    return bsys->core->unk_08;
}

void *sub_021B871C(BattleSystem *bsys)
{
    return bsys->unk_0C0;
}

void sub_021B8724(BattleSystem *bsys, int a1)
{
    sub_0200CED4(bsys->core->unk_68, sub_021D5444(a1));
}

u32 sub_021B8748(BattleSystem *bsys)
{
    return bsys->core->unk_58;
}

void sub_021B8750(BattleSystem *bsys, int a1, int a2)
{
    if (sub_021B86B8(bsys) <= 1 && a1 != 0) {
        sub_0200CFA0(bsys->core->unk_68, sub_021D5844(a2));
    }
}
