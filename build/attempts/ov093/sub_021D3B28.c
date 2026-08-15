// BANKED at 44/50.  ov093 opcode id 32.  Two halfwords swapped: the ROM emits
// `ldr r2,[r4,#0x10]` before `str r1,[sp]`, CW emits the store first.  Same
// sweep as sub_021D3A40 (see that file) plus struct-by-value for a2 and a4.
#include "ov093/battle.h"

void *sub_021B9934(BattleQueue *q, u8 a1);
void sub_021D5734(void *a0, u8 a1, u16 a2, u8 a3, u32 a4);

int sub_021D3B28(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    void *p = sub_021B9934(ctx->unk_04, (u8)args[0]);

    sub_021D5734(p, (u8)args[1], (u16)args[4], (u8)args[2], args[3]);
    return 1;
}
