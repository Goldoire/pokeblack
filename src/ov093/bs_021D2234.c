#include "ov093/battle.h"

// ov093 0x021d2234..0x021d299a: battle-script opcode handlers, ids 54, 59, 66,
// 68, 82 and 86.  Entries in the {handler, opcode-id} table at 0x021F00E0.
//
//     int op(BattleScriptCtx *ctx, u32 *state, u32 *args);
//
// Same two-phase shape as 0x021D1BD0: start the effect in phase 0, poll for it
// in phase 1, answer 1 only when it is done.

int sub_021B8D8C(BattleSystem *bsys, BattleQueue *q, u8 a1);
void *sub_021B8E70(BattleSystem *bsys, int a1);
void sub_021EA384(void *a0, int a1);
BOOL sub_021EA3A0(void *a0);
void sub_021EA438(void *a0, int a1);
BOOL sub_021EA448(void *a0);
void sub_021F81D0(u32 a0, void *a1);
void sub_021F7E94(void *a0);
BOOL sub_021F7EB4(void);
void sub_021F878C(u32 a0);

int sub_021D2234(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    switch (*state) {
    case 0:
        sub_021F81D0(args[1],
            sub_021B8E70(ctx->unk_00,
                sub_021B8D8C(ctx->unk_00, ctx->unk_04, (u8)args[0])));
        (*state)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}

int sub_021D2374(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    switch (*state) {
    case 0:
        sub_021EA438(ctx->unk_054, sub_021B8D8C(ctx->unk_00, ctx->unk_04, (u8)args[0]));
        (*state)++;
        break;
    case 1:
        if (sub_021EA448(ctx->unk_054) != FALSE) {
            return 1;
        }
        break;
    }
    return 0;
}

int sub_021D2580(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    switch (*state) {
    case 0:
        sub_021EA384(ctx->unk_054, sub_021B8D8C(ctx->unk_00, ctx->unk_04, (u8)args[0]));
        (*state)++;
        break;
    case 1:
        if (sub_021EA3A0(ctx->unk_054) != FALSE) {
            return 1;
        }
        break;
    }
    return 0;
}

int sub_021D2628(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    u8 v0 = (u8)args[0];

    switch (*state) {
    case 0:
        sub_021EA384(ctx->unk_054, sub_021B8D8C(ctx->unk_00, ctx->unk_04, v0));
        (*state)++;
        break;
    case 1:
        if (sub_021EA3A0(ctx->unk_054) != FALSE) {
            return 1;
        }
        break;
    }
    return 0;
}

int sub_021D2814(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    switch (*state) {
    case 0:
        sub_021F7E94(sub_021B8E70(ctx->unk_00, (u8)args[0]));
        (*state)++;
        break;
    case 1:
        if (sub_021F7EB4() == FALSE) {
            return 1;
        }
        break;
    }
    return 0;
}

int sub_021D2990(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    sub_021F878C(args[0]);
    return 1;
}
