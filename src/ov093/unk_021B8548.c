#include "ov093/battle.h"

// ov093 0x021b8548..0x021b8cfc + 0x021b8f38..0x021b90f0: BattleSystem accessors.
// Struct layout lives in src/ov093/battle.h.

void sub_021CD914(void *a0);
void *sub_021D5444(int a0);
void *sub_021D5844(int a0);
void sub_0200CED4(void *a0, void *a1);
void sub_0200CFA0(void *a0, void *a1);
u32 sub_020083C8(u32 a0);

BOOL sub_021B8B9C(BattleSystem *bsys, u8 a1);
u8 sub_021B8BC4(BattleSystem *bsys, int a1);
u8 sub_021B8C20(int a0, int a1, int a2);
void sub_021B969C(BattleQueue *a0, BattleSystem *bsys, int a2, int a3);
u32 sub_021B985C(BattleQueue *a0, int a1);
void sub_02007E50(void *a0, int a1, int a2, u16 a3);
void sub_02007F1C(void *a0, int a1, int a2, u16 a3);

u32 sub_021B8588(BattleSystem *bsys);
u32 sub_021B8670(BattleSystem *bsys);
u32 sub_021B86B8(BattleSystem *bsys);
BOOL sub_021B86C8(BattleSystem *bsys);
u32 sub_021B86C0(BattleSystem *bsys);
u8 sub_021B8FC0(BattleSystem *bsys, int a1);
u8 sub_021B9010(BattleSystem *bsys, int a1);
int sub_021B9064(BattleSystem *bsys, int a1, int a2);

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
    return bsys->core->format;
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

    if (core->mode <= 1) {
        return core->unk_70;
    }
    return 0;
}

u32 sub_021B8640(BattleSystem *bsys)
{
    switch (bsys->core->format) {
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
    switch (bsys->core->format) {
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
    return bsys->core->mode;
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
    switch (bsys->core->mode) {
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

BOOL sub_021B8F38(BattleSystem *bsys)
{
    u32 v;

    if (sub_021B86C8(bsys) != FALSE) {
        v = sub_021B86B8(bsys);
        if (v != 1 && v != 0) {
            return TRUE;
        }
    }
    return FALSE;
}

u32 sub_021B8F5C(BattleSystem *bsys, int a1)
{
    sub_021B969C(bsys->unk_0C8, bsys, a1, 0);
    return sub_021B985C(bsys->unk_0C8, a1);
}

u32 sub_021B8F7C(BattleSystem *bsys, int a1)
{
    u8 v;

    if (sub_021B86C8(bsys) != FALSE) {
        v = (a1 + 2) & 3;
        if (sub_021B8B9C(bsys, v) != FALSE) {
            sub_021B969C(bsys->unk_0C8, bsys, v, 0);
            return sub_021B985C(bsys->unk_0C8, v);
        }
    }
    return 0;
}

u8 sub_021B8FC0(BattleSystem *bsys, int a1)
{
    if (sub_021B86C8(bsys) != FALSE) {
        if (a1 & 2) {
            return 1;
        }
        return 0;
    }
    return 0;
}

u8 sub_021B8FE4(BattleSystem *bsys)
{
    return sub_021B8FC0(bsys, bsys->unk_46C);
}

u8 sub_021B8FF4(BattleSystem *bsys)
{
    return bsys->unk_46C;
}

u8 sub_021B9000(BattleSystem *bsys)
{
    return sub_021B9010(bsys, bsys->unk_46C);
}

u8 sub_021B9010(BattleSystem *bsys, int a1)
{
    u8 v = (a1 + 2) & 3;

    if (sub_021B8B9C(bsys, v) == FALSE) {
        v = 4;
    }
    return v;
}

BOOL sub_021B902C(u8 a0, u8 a1)
{
    if (a0 == a1) {
        return TRUE;
    }
    if (a0 == (u8)((a1 + 2) & 3)) {
        return TRUE;
    }
    return FALSE;
}

u8 sub_021B904C(BattleSystem *bsys, int a1)
{
    return sub_021B9064(bsys, bsys->unk_46C, a1);
}

int sub_021B9064(BattleSystem *bsys, int a1, int a2)
{
    a1 = (a1 & 1) ^ 1;

    if (a2 != 0) {
        u8 w = a1 + (a2 & 1) * 2;
        if (sub_021B8B9C(bsys, w) != FALSE) {
            a1 = w;
        }
    }
    return a1;
}

void sub_021B9090(BattleSystem *bsys, u8 a1, int a2)
{
    BattleCore *core = bsys->core;

    if (core->unk_23 == 0 && a1 == bsys->unk_46C) {
        sub_02007F1C(core->unk_60, a2, 1, bsys->unk_468);
    }
}

void sub_021B90BC(BattleSystem *bsys, u8 a1, int a2)
{
    BattleCore *core = bsys->core;

    if (core->unk_23 == 0 && a1 == bsys->unk_46C) {
        sub_02007E50(core->unk_60, a2, 1, bsys->unk_468);
    }
}

void *sub_021B90E8(BattleSystem *bsys)
{
    return bsys->core->unk_60;
}

void *sub_021B90F0(BattleSystem *bsys)
{
    return bsys->core->unk_64;
}

BOOL sub_021B8B9C(BattleSystem *bsys, u8 a1)
{
    u32 i;

    if (a1 < 4) {
        for (i = 0; i < 6; i++) {
            if (a1 == bsys->unk_428[i]) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

u8 sub_021B8BC4(BattleSystem *bsys, int a1)
{
    return a1 & 1;
}

BOOL sub_021B8BD0(BattleSystem *bsys, u8 a1)
{
    if (a1 == sub_021B8BC4(bsys, bsys->unk_46C)) {
        return TRUE;
    }
    return FALSE;
}

u8 sub_021B8BEC(BattleSystem *bsys, u8 a1, u8 a2)
{
    u8 i;

    for (i = 0; i < 6; i++) {
        if (a1 == bsys->unk_428[i]) {
            if (a2 == 0) {
                return i;
            }
            a2--;
        }
    }
    return 6;
}

u8 sub_021B8C20(int a0, int a1, int a2)
{
    if ((a1 & 1) == 0) {
        return a2 * 2 + 1;
    }
    return a2 * 2;
}

u8 sub_021B8C50(BattleSystem *bsys, int a1, int a2)
{
    return sub_021B8C20(bsys->core->format, a1, a2);
}

u8 sub_021B8C38(int a0, int a1)
{
    if ((a0 & 1) == 0) {
        return a1 * 2;
    }
    return a1 * 2 + 1;
}

u8 sub_021B8CB0(BattleSystem *bsys, u8 a1)
{
    switch (bsys->core->format) {
    case 0:
        return a1;
    case 3:
        return a1;
    case 1:
        return (a1 + 2) & 3;
    case 2:
        return a1;
    default:
        return a1;
    }
}

BOOL sub_021B8CE8(int a0, int a1, int a2)
{
    return (a1 & 1) != (a2 & 1);
}

u8 sub_021B8CFC(BattleSystem *bsys, int a1)
{
    return bsys->unk_428[a1];
}
