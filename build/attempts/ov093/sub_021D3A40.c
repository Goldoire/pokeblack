// BANKED at 35/58.  ov093 opcode id 25.  Argument mapping is certain (the
// callee sub_021D6744 is a plain 6-arg function).  What differs is only the
// instruction schedule: the ROM hoists `ldr r3,[r4,#0xc]` (args[3]) and
// `ldr r2,[r4,#8]` (args[2]) one slot earlier than CW does, and splits the
// (u8) lsl/lsr pair across the two stack-argument stores.  Tried: nested vs
// sequenced call form, locals in the ROM's load order, u32 locals with the
// casts at the call, implicit conversion via the prototype instead of explicit
// casts, struct-by-value for a2/a4/a5, all 24 mwccarm builds, -O2/-O3/-O4,s,
// -opt schedule/speed.
#include "ov093/battle.h"

void *sub_021B9934(BattleQueue *q, u8 a1);
void sub_021D6744(void *a0, u8 a1, u32 a2, u8 a3, u16 a4, u16 a5);

int sub_021D3A40(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    void *p = sub_021B9934(ctx->unk_04, (u8)args[0]);

    sub_021D6744(p, (u8)args[1], args[2], (u8)args[3], (u16)args[4], (u16)args[5]);
    return 1;
}
