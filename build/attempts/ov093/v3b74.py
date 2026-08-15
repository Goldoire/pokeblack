PRELUDE = '''#include "ov093/battle.h"
void f64(void *a0, u32 a1, u64 a2);
void fs64(void *a0, u32 a1, s64 a2);
'''
NAME = "sub_021D3B74"
VARIANTS = [
"""void sub_021EF9F4(void *a0, u32 a1, u64 a2);
int sub_021D3B74(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    sub_021EF9F4(ctx->unk_034, args[0], args[1]);
    return 1;
}""",
"""void sub_021EF9F4(void *a0, u32 a1, s64 a2);
int sub_021D3B74(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    sub_021EF9F4(ctx->unk_034, args[0], (s64)args[1]);
    return 1;
}""",
]
