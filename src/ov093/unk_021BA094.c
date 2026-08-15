#include "ov093/battle.h"

// ov093 0x021ba094..0x021ba81c: the rest of the BattleSystem accessors --
// the +0x298 / +0x2A8 pointer pairs, the current-battler shortcuts that index
// unk_010 with unk_46C, and the BattleCore side/position tables at +0x24.

void MI_CpuCopy8(const void *src, void *dest, u32 size);
void *sub_0201A920(int a0);
void sub_0201A948(void *a0);
BOOL sub_0201AA18(void *a0);
void sub_0201AB28(void *a0, int a1);
void sub_0201AC2C(void *a0, void *a1);
void sub_02008494(void *a0, void *a1);

u32 sub_021B6818(BattleCore *core);
u32 sub_021B86B8(BattleSystem *bsys);
BOOL sub_021B8B9C(BattleSystem *bsys, u8 a1);
BOOL sub_021B90F8(BattleSystem *bsys);
u8 sub_021B92D4(BattleSystem *bsys, int a1, int a2);
u8 sub_021B997C(BattleSystem *bsys, int a1);
void sub_021BB8BC(void *a0, int a1);
void *sub_021CD924(void *a0, u32 *a1);
void sub_021CD9B0(void *a0);
u32 sub_021CDDA0(void *a0);
u32 sub_021CDDCC(void *a0);

BOOL sub_021BA1EC(BattleSystem *bsys);
u8 sub_021BA710(u8 a0, u8 a1);

void sub_021BA094(BattleSystem *bsys)
{
    u32 i;

    for (i = 0; i < 4; i++) {
        bsys->unk_298[i] = sub_0201A920(0x12);
        bsys->unk_2A8[i] = sub_0201A920(0x12);
    }
    bsys->unk_2B8 = sub_0201A920(0x12);
}

void sub_021BA128(BattleSystem *bsys, int a1, void *a2)
{
    if (bsys->unk_298[a1] != NULL) {
        sub_0201A948(bsys->unk_298[a1]);
        sub_0201A948(bsys->unk_2A8[a1]);
        sub_0201AC2C(a2, bsys->unk_298[a1]);
        sub_0201AC2C(a2, bsys->unk_2A8[a1]);
        if (sub_0201AA18(bsys->unk_2A8[a1]) != FALSE) {
            sub_0201AB28(bsys->unk_2A8[a1], 0);
        }
    }
}

void *sub_021BA178(BattleSystem *bsys, int a1, int a2)
{
    if (a2 != 0) {
        if (sub_0201AA18(bsys->unk_2A8[a1]) != FALSE) {
            sub_0201AB28(bsys->unk_2A8[a1], 0);
        }
        return bsys->unk_2A8[a1];
    }
    return bsys->unk_298[a1];
}

BOOL sub_021BA1EC(BattleSystem *bsys)
{
    BOOL v = FALSE;

    if (sub_021B6818(bsys->core) == 1) {
        v = (bsys->core->unk_7F != 0);
    }
    return v;
}

BOOL sub_021BA20C(BattleSystem *bsys)
{
    if (sub_021B6818(bsys->core) == 1) {
        return sub_021BA1EC(bsys);
    }
    switch (sub_021B86B8(bsys)) {
    case 0:
    case 1:
        return TRUE;
    }
    return FALSE;
}

void sub_021BA238(BattleSystem *bsys, int a1)
{
    sub_021B92D4(bsys, a1, 0);
    sub_021BB8BC(bsys->unk_008, a1);
}

BOOL sub_021BA534(BattleSystem *bsys)
{
    switch (sub_021B86B8(bsys)) {
    case 2:
    case 3:
        return TRUE;
    }
    return FALSE;
}

u16 sub_021BA5C4(BattleSystem *bsys)
{
    return bsys->unk_442;
}

u16 sub_021BA5D0(BattleSystem *bsys)
{
    return bsys->unk_440;
}

u32 sub_021BA5D8(BattleSystem *bsys)
{
    if (bsys->core->unk_23 == 0) {
        if (bsys->unk_440 != 0) {
            return sub_021CDDA0(bsys->unk_010[bsys->unk_46C]);
        }
        return 0;
    }
    return sub_021CDDA0(bsys->unk_010[bsys->unk_46C]);
}

u32 sub_021BA618(BattleSystem *bsys)
{
    u32 v;

    if (bsys->core->unk_23 != 0) {
        v = sub_021CDDCC(bsys->unk_010[bsys->unk_46C]);
        if (v != 0) {
            bsys->unk_444 = 2;
        }
        return v;
    }
    return 0;
}

void sub_021BA648(BattleSystem *bsys, u8 a1, void *a2)
{
    BattleCore *core;
    u8 i = sub_021BA710(bsys->unk_46C, a1);

    core = bsys->core;
    if (core->unk_24[i] != NULL) {
        sub_0201AC2C(a2, core->unk_24[i]);
    }
}

void sub_021BA670(BattleSystem *bsys, u8 a1, void *a2)
{
    BattleCore *core;
    u8 i = sub_021BA710(bsys->unk_46C, a1);

    core = bsys->core;
    if (core->unk_34[i] != NULL) {
        sub_02008494(a2, core->unk_34[i]);
    }
}

void sub_021BA698(BattleSystem *bsys, u8 a1)
{
    u8 i = sub_021BA710(bsys->unk_46C, a1);

    bsys->core->unk_44[i] = sub_021B997C(bsys, a1);
}

void sub_021BA6C0(BattleSystem *bsys)
{
    u32 size;
    void *p;

    if (sub_021B90F8(bsys) != FALSE) {
        p = sub_021CD924(bsys->unk_010[bsys->unk_46C], &size);
        if (p != NULL) {
            MI_CpuCopy8(p, bsys->core->unk_94, size);
            bsys->core->unk_98 = size;
            bsys->core->unk_9C = bsys->unk_3F0;
        }
    }
}

u8 sub_021BA710(u8 a0, u8 a1)
{
    int v;

    if (a0 == a1) {
        return 0;
    }
    if ((u8)(a0 & 1) == (u8)(a1 & 1)) {
        return 2;
    }
    v = 1;
    if (a1 > 1) {
        v = 3;
    }
    return v;
}

void sub_021BA7F8(BattleSystem *bsys)
{
    u32 i;

    for (i = 0; i < 4; i++) {
        if (sub_021B8B9C(bsys, (u8)i) != FALSE) {
            sub_021CD9B0(bsys->unk_010[i]);
        }
    }
}
