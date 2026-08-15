PRELUDE = '''#include "ov093/battle.h"
void *sub_021B9934(BattleQueue *q, u8 a1);
void sub_021D6744(void *a0, u8 a1, u32 a2, u8 a3, u16 a4, u16 a5);
void sub_021D5734(void *a0, u8 a1, u16 a2, u8 a3, u32 a4);
'''
VARIANTS = [
"""int sub_021D3B28(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    void *p = sub_021B9934(ctx->unk_04, (u8)args[0]);
    u32 v3 = args[3];
    u16 v4 = (u16)args[4];

    sub_021D5734(p, (u8)args[1], v4, (u8)args[2], v3);
    return 1;
}
int sub_021D3A40(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    void *p = sub_021B9934(ctx->unk_04, (u8)args[0]);
    u16 v4 = (u16)args[4];
    u8 v3 = (u8)args[3];
    u16 v5 = (u16)args[5];

    sub_021D6744(p, (u8)args[1], args[2], v3, v4, v5);
    return 1;
}""",
"""int sub_021D3B28(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    void *p = sub_021B9934(ctx->unk_04, (u8)args[0]);
    u32 v3 = args[3];
    u32 v4 = args[4];

    sub_021D5734(p, (u8)args[1], (u16)v4, (u8)args[2], v3);
    return 1;
}
int sub_021D3A40(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    void *p = sub_021B9934(ctx->unk_04, (u8)args[0]);
    u32 v4 = args[4];
    u32 v3 = args[3];
    u32 v5 = args[5];

    sub_021D6744(p, (u8)args[1], args[2], (u8)v3, (u16)v4, (u16)v5);
    return 1;
}""",
]
