#include "ov093/battle.h"

// ov093 0x021b90f8..0x021b9210 + 0x021b9940..0x021b99b4: BattleSystem helpers
// around the +0x3E0 pointer array, the +0x434 running total and the BattleQueue
// slot table at +0x84.

BOOL sub_02007B50(void *a0);
u8 sub_02007C70(void *a0);
BOOL sub_021B9114(BattleSystem *bsys, int a1);

BOOL sub_021B90F8(BattleSystem *bsys)
{
    BattleCore *core = bsys->core;

    if (core->unk_94 != NULL && core->unk_23 == 0) {
        return TRUE;
    }
    return FALSE;
}

void sub_021B916C(BattleSystem *bsys, u32 a1)
{
    if (bsys->unk_444 == 7) {
        bsys->unk_444 = a1;
    }
}

void sub_021B91E4(BattleSystem *bsys, u32 a1)
{
    u32 v;

    if (bsys->unk_473_3 == 0) {
        v = bsys->unk_434 + a1;
        bsys->unk_434 = v;
        if (v > 99999) {
            bsys->unk_434 = 99999;
        }
    }
}

void *sub_021B9940(BattleQueue *q, int a1)
{
    return q->unk_84[a1];
}

u8 sub_021B997C(BattleSystem *bsys, int a1)
{
    if (sub_021B9114(bsys, a1) == FALSE) {
        if (bsys->unk_3E0[a1] != NULL) {
            if (sub_02007B50(bsys->unk_3E0[a1]) != FALSE) {
                return sub_02007C70(bsys->unk_3E0[a1]);
            }
        }
        return 0;
    }
    return bsys->core->unk_44[a1];
}
