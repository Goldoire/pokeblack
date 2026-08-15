PRELUDE = '''#include "ov093/battle.h"
void *sub_021B9934(BattleQueue *q, u8 a1);
void sub_021D6744(void *a0, u8 a1, u32 a2, u8 a3, u16 a4, u16 a5);
void sub_021D5734(void *a0, u8 a1, u16 a2, u8 a3, u32 a4);
void sub_021D6034(void *a0, u32 a1, u32 a2);
'''
VARIANTS = [
"""int sub_021D3A40(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    void *p = sub_021B9934(ctx->unk_04, (u8)args[0]);

    sub_021D6744(p, args[1], args[2], args[3], args[4], args[5]);
    return 1;
}
int sub_021D3B28(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    void *p = sub_021B9934(ctx->unk_04, (u8)args[0]);

    sub_021D5734(p, args[1], args[4], args[2], args[3]);
    return 1;
}""",
"""int sub_021D3A40(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    sub_021D6744(sub_021B9934(ctx->unk_04, (u8)args[0]), args[1], args[2],
                 args[3], args[4], args[5]);
    return 1;
}
int sub_021D3B28(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    sub_021D5734(sub_021B9934(ctx->unk_04, (u8)args[0]), args[1], args[4],
                 args[2], args[3]);
    return 1;
}""",
]
