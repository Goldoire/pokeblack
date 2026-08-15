#include "ov093/battle.h"

// ov093 0x021d36cc..0x021d3d70: battle-script opcode handlers.  Each one is an
// entry in the {handler, opcode-id} table at 0x021F01B0, takes the script
// context plus the opcode's u32 argument list, and returns 1 to advance.
//
// sub_021B9934(ctx->unk_04, args[0]) resolves the per-battler object out of
// the BattleQueue the context points at; see src/ov093/battle.h.

void *sub_021B9934(BattleQueue *q, u8 a1);
void sub_021D5B44(void *a0, u16 a1);
void sub_021D5EFC(void *a0);
void sub_021D5F08(void *a0);
void sub_021D5F38(void *a0, u32 a1);
void sub_021D5F90(void *a0, u16 a1);
void sub_021D5FA4(void *a0, u16 a1);
void sub_021D5FB8(void *a0);
void sub_021D5FC0(void *a0, u32 a1);
void sub_021D5FE4(void *a0, u32 a1);
void sub_021D6008(void *a0, u32 a1);
void sub_021D61F0(void *a0);
void sub_021D6238(void *a0, u32 a1);
void sub_021D6440(void *a0, u32 a1);
void sub_021D64F0(void *a0);
void sub_021D66B0(void *a0, u16 a1);
void sub_021D66D0(void *a0, u32 a1);
void sub_021D6730(void *a0, u16 a1);
void sub_021D6738(void *a0);
void sub_021D67D8(void *a0, u16 a1);
void sub_021D6D5C(void *a0, u16 a1);
void sub_021D6D70(void *a0);

int sub_021D36CC(BattleScriptCtx *ctx, void *a1, u32 *a2)
{
    sub_021D5F90(sub_021B9934(ctx->unk_04, (u8)a2[0]), (u16)a2[1]);
    return 1;
}

int sub_021D36EC(BattleScriptCtx *ctx, void *a1, u32 *a2)
{
    sub_021D5FA4(sub_021B9934(ctx->unk_04, (u8)a2[0]), (u16)a2[1]);
    return 1;
}

int sub_021D377C(BattleScriptCtx *ctx, void *a1, u32 *a2)
{
    sub_021D5FB8(sub_021B9934(ctx->unk_04, (u8)a2[0]));
    return 1;
}

int sub_021D3894(BattleScriptCtx *ctx, void *a1, u32 *a2)
{
    sub_021D5EFC(sub_021B9934(ctx->unk_04, (u8)a2[0]));
    return 1;
}

int sub_021D38AC(BattleScriptCtx *ctx, void *a1, u32 *a2)
{
    sub_021D5F08(sub_021B9934(ctx->unk_04, (u8)a2[0]));
    return 1;
}

int sub_021D38C4(BattleScriptCtx *ctx, void *a1, u32 *a2)
{
    sub_021D5F38(sub_021B9934(ctx->unk_04, (u8)a2[0]), a2[1]);
    return 1;
}

int sub_021D3900(BattleScriptCtx *ctx, void *a1, u32 *a2)
{
    sub_021D61F0(sub_021B9934(ctx->unk_04, (u8)a2[0]));
    return 1;
}

int sub_021D3918(BattleScriptCtx *ctx, void *a1, u32 *a2)
{
    sub_021D6238(sub_021B9934(ctx->unk_04, (u8)a2[0]), a2[1]);
    return 1;
}

int sub_021D3988(BattleScriptCtx *ctx, void *a1, u32 *a2)
{
    sub_021D66B0(sub_021B9934(ctx->unk_04, (u8)a2[0]), (u16)a2[1]);
    return 1;
}

int sub_021D3A20(BattleScriptCtx *ctx, void *a1, u32 *a2)
{
    sub_021D6730(sub_021B9934(ctx->unk_04, (u8)a2[0]), (u16)a2[1]);
    return 1;
}

int sub_021D3A7C(BattleScriptCtx *ctx, void *a1, u32 *a2)
{
    sub_021D5FE4(sub_021B9934(ctx->unk_04, (u8)a2[0]), a2[1]);
    return 1;
}

int sub_021D3A98(BattleScriptCtx *ctx, void *a1, u32 *a2)
{
    sub_021D6008(sub_021B9934(ctx->unk_04, (u8)a2[0]), a2[1]);
    return 1;
}

int sub_021D3AB4(BattleScriptCtx *ctx, void *a1, u32 *a2)
{
    sub_021D5FC0(sub_021B9934(ctx->unk_04, (u8)a2[0]), a2[1]);
    return 1;
}

int sub_021D3AD0(BattleScriptCtx *ctx, void *a1, u32 *a2)
{
    sub_021D6440(sub_021B9934(ctx->unk_04, (u8)a2[0]), a2[1]);
    return 1;
}

int sub_021D3AEC(BattleScriptCtx *ctx, void *a1, u32 *a2)
{
    sub_021D66D0(sub_021B9934(ctx->unk_04, (u8)a2[0]), a2[1]);
    return 1;
}

int sub_021D3B08(BattleScriptCtx *ctx, void *a1, u32 *a2)
{
    sub_021D5B44(sub_021B9934(ctx->unk_04, (u8)a2[0]), (u16)a2[1]);
    return 1;
}

int sub_021D3B5C(BattleScriptCtx *ctx, void *a1, u32 *a2)
{
    sub_021D64F0(sub_021B9934(ctx->unk_04, (u8)a2[0]));
    return 1;
}

int sub_021D3C0C(BattleScriptCtx *ctx, void *a1, u32 *a2)
{
    sub_021D6D5C(sub_021B9934(ctx->unk_04, (u8)a2[0]), (u16)a2[1]);
    return 1;
}

int sub_021D3C2C(BattleScriptCtx *ctx, void *a1, u32 *a2)
{
    sub_021D6D70(sub_021B9934(ctx->unk_04, (u8)a2[0]));
    return 1;
}

int sub_021D3C90(BattleScriptCtx *ctx, void *a1, u32 *a2)
{
    sub_021D6738(sub_021B9934(ctx->unk_04, (u8)a2[0]));
    return 1;
}

int sub_021D3D50(BattleScriptCtx *ctx, void *a1, u32 *a2)
{
    sub_021D67D8(sub_021B9934(ctx->unk_04, (u8)a2[0]), (u16)a2[1]);
    return 1;
}

