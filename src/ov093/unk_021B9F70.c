#include "ov093/battle.h"

// ov093 0x021b9f70..0x021ba093: accessors for the four 0x28-byte BattleSlot
// records at BattleSystem+0x20 and the pointer arrays at +0x298 / +0x2A8.

void *sub_0201A920(int a0);
BOOL sub_021BA1A8(BattleSystem *bsys, int a1);

u32 sub_021B8588(BattleSystem *bsys);
u32 sub_021B86B8(BattleSystem *bsys);
BOOL sub_021B9F70(BattleSystem *bsys, int a1);

BOOL sub_021B9F70(BattleSystem *bsys, int a1)
{
    if (bsys->unk_020[a1].unk_00 == NULL) {
        return TRUE;
    }
    return FALSE;
}

u16 sub_021B9F84(BattleSystem *bsys, int a1, u32 a2)
{
    BattleSlot *slot;

    if (sub_021B9F70(bsys, a1) != FALSE) {
        slot = &bsys->unk_020[a1];
        if (a2 < 4) {
            return slot->unk_10[a2];
        }
    }
    return 0;
}

u32 sub_021B9FAC(BattleSystem *bsys, int a1, u32 *a2)
{
    *a2 = bsys->unk_020[a1].unk_08;
    return bsys->unk_020[a1].unk_04;
}

u32 sub_021B9FBC(BattleSystem *bsys, int a1)
{
    if (sub_021B86B8(bsys) == 0) {
        if (sub_021BA1A8(bsys, 8) != FALSE) {
            return 8 << 8;
        }
        if (sub_021B8588(bsys) == 1) {
            return 0x80;
        }
    } else if (sub_021B9F70(bsys, a1) != FALSE) {
        return bsys->unk_020[a1].unk_0C;
    }
    return 0;
}

u16 sub_021BA004(BattleSystem *bsys, int a1)
{
    if (sub_021B9F70(bsys, a1) != FALSE) {
        return bsys->unk_020[a1].unk_0A;
    }
    return 0;
}

u16 sub_021BA020(BattleSystem *bsys, int a1)
{
    return bsys->unk_020[a1].unk_08;
}

u8 *sub_021BA02C(BattleSystem *bsys, int a1, int a2)
{
    if (sub_021B86B8(bsys) == 2) {
        if (sub_021B9F70(bsys, a1) != FALSE) {
            if (a2 == 1) {
                return bsys->unk_020[a1].unk_20;
            }
            return bsys->unk_020[a1].unk_18;
        }
    }
    return NULL;
}

void *sub_021BA064(BattleSystem *bsys, int a1)
{
    if (sub_021B9F70(bsys, a1) != FALSE) {
        return NULL;
    }
    return bsys->unk_020[a1].unk_00;
}

u32 sub_021BA08C(BattleSystem *bsys)
{
    return bsys->unk_2BC;
}
