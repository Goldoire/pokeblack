PRELUDE = '''#include "ov093/battle.h"
void *sub_021B9934(BattleQueue *q, u8 a1);
typedef struct W { u32 a; } W;
typedef struct H { u16 a; } H;
'''
VARIANTS = [
"""void sub_021D5734(void *a0, u8 a1, u16 a2, u8 a3, W a4);
int sub_021D3B28(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    W w;
    void *p = sub_021B9934(ctx->unk_04, (u8)args[0]);

    w.a = args[3];
    sub_021D5734(p, (u8)args[1], (u16)args[4], (u8)args[2], w);
    return 1;
}""",
"""void sub_021D5734(void *a0, u8 a1, H a2, u8 a3, u32 a4);
int sub_021D3B28(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    H h;
    void *p = sub_021B9934(ctx->unk_04, (u8)args[0]);

    h.a = (u16)args[4];
    sub_021D5734(p, (u8)args[1], h, (u8)args[2], args[3]);
    return 1;
}""",
"""void sub_021D6744(void *a0, u8 a1, W a2, u8 a3, u16 a4, u16 a5);
int sub_021D3A40(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    W w;
    void *p = sub_021B9934(ctx->unk_04, (u8)args[0]);

    w.a = args[2];
    sub_021D6744(p, (u8)args[1], w, (u8)args[3], (u16)args[4], (u16)args[5]);
    return 1;
}""",
"""void sub_021D6744(void *a0, u8 a1, u32 a2, u8 a3, H a4, H a5);
int sub_021D3A40(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    H h4;
    H h5;
    void *p = sub_021B9934(ctx->unk_04, (u8)args[0]);

    h4.a = (u16)args[4];
    h5.a = (u16)args[5];
    sub_021D6744(p, (u8)args[1], args[2], (u8)args[3], h4, h5);
    return 1;
}""",
]
