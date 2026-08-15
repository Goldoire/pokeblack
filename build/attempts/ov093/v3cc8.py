PRELUDE = '''#include "ov093/battle.h"
void *sub_021B9934(BattleQueue *q, u8 a1);
void sub_021D6848(void *a0, void *a1);
typedef struct S { u16 unk_00; u16 unk_02; u8 unk_04; u8 unk_05; u8 unk_06; } S;
static inline void S_Init(S *q, u16 a, u16 b, u8 c, u8 d, u8 e)
{
    q->unk_00 = a;
    q->unk_02 = b;
    q->unk_04 = c;
    q->unk_05 = d;
    q->unk_06 = e;
}
'''
NAME = "sub_021D3CC8"
VARIANTS = [
"""int sub_021D3CC8(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    S s;
    void *p = sub_021B9934(ctx->unk_04, (u8)args[0]);
    u32 a = args[4];
    u32 b = args[5];
    u32 c = args[3];
    u32 e = args[2];
    u32 d = args[1];

    s.unk_00 = (u16)a;
    s.unk_02 = (u16)b;
    s.unk_04 = (u8)c;
    s.unk_05 = (u8)d;
    s.unk_06 = (u8)e;
    sub_021D6848(p, &s);
    return 1;
}""",
"""int sub_021D3CC8(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    S s;
    void *p = sub_021B9934(ctx->unk_04, (u8)args[0]);

    S_Init(&s, (u16)args[4], (u16)args[5], (u8)args[3], (u8)args[1], (u8)args[2]);
    sub_021D6848(p, &s);
    return 1;
}""",
"""int sub_021D3CC8(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    S s;
    void *p = sub_021B9934(ctx->unk_04, (u8)args[0]);
    u16 a = (u16)args[4];
    u16 b = (u16)args[5];
    u8 c = (u8)args[3];
    u8 e = (u8)args[2];
    u8 d = (u8)args[1];

    s.unk_00 = a;
    s.unk_02 = b;
    s.unk_04 = c;
    s.unk_06 = e;
    s.unk_05 = d;
    sub_021D6848(p, &s);
    return 1;
}""",
"""int sub_021D3CC8(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    S s;
    S *q = &s;
    void *p = sub_021B9934(ctx->unk_04, (u8)args[0]);
    u16 a = (u16)args[4];
    u16 b = (u16)args[5];
    u8 c = (u8)args[3];
    u8 e = (u8)args[2];
    u8 d = (u8)args[1];

    q->unk_00 = a;
    q->unk_02 = b;
    q->unk_04 = c;
    q->unk_05 = d;
    q->unk_06 = e;
    sub_021D6848(p, q);
    return 1;
}""",
]
