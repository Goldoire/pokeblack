#include "ov093/battle.h"

// ov093 0x021d370c..0x021d381c: battle-script opcodes 5..11.  Entries in the
// {handler, opcode-id} table at 0x021F00E0; each resolves the per-battler
// object for args[0] out of the context's BattleQueue and forwards the rest of
// the argument list.

void *sub_021B9934(BattleQueue *q, u8 a1);
void sub_021D5608(void *a0, u8 a1, u8 a2);
void sub_021D5640(void *a0, u8 a1, u8 a2);
void sub_021D5674(void *a0, u8 a1, u8 a2);
void sub_021D56A0(void *a0, u8 a1, u8 a2);
void sub_021D56CC(void *a0, u8 a1);
void sub_021D5DC0(void *a0, u32 a1, u8 a2);
void sub_021D5E38(void *a0, u32 a1, u8 a2);

int sub_021D370C(BattleScriptCtx *ctx, void *a1, u32 *a2)
{
    u8 v1 = (u8)a2[1];
    u8 v2 = (u8)a2[2];
    void *p = sub_021B9934(ctx->unk_04, (u8)a2[0]);

    sub_021D5608(p, v1, v2);
    return 1;
}

int sub_021D3734(BattleScriptCtx *ctx, void *a1, u32 *a2)
{
    u8 v1 = (u8)a2[1];
    u8 v2 = (u8)a2[2];
    void *p = sub_021B9934(ctx->unk_04, (u8)a2[0]);

    sub_021D5640(p, v1, v2);
    return 1;
}

int sub_021D375C(BattleScriptCtx *ctx, void *a1, u32 *a2)
{
    u8 v1 = (u8)a2[1];
    void *p = sub_021B9934(ctx->unk_04, (u8)a2[0]);

    sub_021D56CC(p, v1);
    return 1;
}

int sub_021D3794(BattleScriptCtx *ctx, void *a1, u32 *a2)
{
    sub_021D5674(sub_021B9934(ctx->unk_04, (u8)a2[0]), (u8)a2[1], (u8)a2[2]);
    return 1;
}

int sub_021D37B8(BattleScriptCtx *ctx, void *a1, u32 *a2)
{
    sub_021D56A0(sub_021B9934(ctx->unk_04, (u8)a2[0]), (u8)a2[1], (u8)a2[2]);
    return 1;
}

int sub_021D37DC(BattleScriptCtx *ctx, void *a1, u32 *a2)
{
    sub_021D5DC0(sub_021B9934(ctx->unk_04, (u8)a2[0]), a2[1], (u8)a2[2]);
    return 1;
}

int sub_021D37FC(BattleScriptCtx *ctx, void *a1, u32 *a2)
{
    sub_021D5E38(sub_021B9934(ctx->unk_04, (u8)a2[0]), a2[1], (u8)a2[2]);
    return 1;
}
