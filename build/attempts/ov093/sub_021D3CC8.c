// BANKED at 45/52.  ov093 opcode id 46.  Everything matches except the
// schedule of one load: the ROM loads args[4] FIRST of the five, CW emits it
// LAST (load order comes out as declaration order rotated left by one).  All
// 120 permutations of the five locals' declaration order were compiled; the
// best is a,b,c,e,d below, which fixes the register assignment but not the
// rotation.  Also tried: u32 locals, static inline initialiser, an explicit
// S *q = &s, and reordering the field stores.
#include "ov093/battle.h"

void *sub_021B9934(BattleQueue *q, u8 a1);
void sub_021D6848(void *a0, void *a1);

typedef struct UnkStruct021D3CC8 {
    u16 unk_00;
    u16 unk_02;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
} UnkStruct021D3CC8;

int sub_021D3CC8(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    UnkStruct021D3CC8 s;
    void *p = sub_021B9934(ctx->unk_04, (u8)args[0]);
    u16 a = (u16)args[4];
    u16 b = (u16)args[5];
    u8 c = (u8)args[3];
    u8 e = (u8)args[2];
    u8 d = (u8)args[1];

    s.unk_00 = a;
    s.unk_02 = b;
    s.unk_04 = c;
    s.unk_05 = d;
    s.unk_06 = e;
    sub_021D6848(p, &s);
    return 1;
}
