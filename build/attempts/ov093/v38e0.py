PRELUDE = '''#include "ov093/battle.h"
void *sub_021B9934(BattleQueue *q, u8 a1);
typedef struct W { u32 a; } W;
'''
VARIANTS = [
"""void sub_021D6034(void *a0, ...);
int sub_021D38E0(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    void *p = sub_021B9934(ctx->unk_04, (u8)args[0]);
    sub_021D6034(p, args[1], args[2]);
    return 1;
}""",
"""void sub_021D6034(void *a0, u32 a1, W a2);
int sub_021D38E0(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    W w;
    void *p = sub_021B9934(ctx->unk_04, (u8)args[0]);
    w.a = args[2];
    sub_021D6034(p, args[1], w);
    return 1;
}""",
"""void sub_021D6034(void *a0, u32 a1, u32 a2, ...);
int sub_021D38E0(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    void *p = sub_021B9934(ctx->unk_04, (u8)args[0]);
    sub_021D6034(p, args[1], args[2]);
    return 1;
}""",
"""void sub_021D6034(void *a0, u32 a1, u32 a2);
int sub_021D38E0(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    u32 dummy;
    void *p = sub_021B9934(ctx->unk_04, (u8)args[0]);
    sub_021D6034(p, args[1], args[2]);
    return 1;
}""",
"""void sub_021D6034(void *a0, u32 a1, u32 a2);
int sub_021D38E0(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    void *p = sub_021B9934(ctx->unk_04, (u8)args[0]);
    u32 v = args[2];
    sub_021D6034(p, args[1], v);
    return 1;
}""",
]
