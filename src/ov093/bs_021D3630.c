#include "ov093/battle.h"

// ov093 0x021d3630..0x021d36ca: battle-script opcode handlers, ids 88 and 1.
//
//     int op(BattleScriptCtx *ctx, u32 *state, u32 *args);
//
// These two are the multi-frame opcodes: `state` is the script's per-command
// step counter, the handler returns 0 while it still has work to do and 1 once
// the command is finished, and it bumps *state itself between phases.

void *sub_021B8D8C(BattleSystem *bsys, BattleQueue *q, u8 a1);
BOOL sub_021CD9E0(BattleScriptCtx *ctx);
void sub_021EA768(void *a0, void *a1, u32 a2);
BOOL sub_021EA778(void *a0, void *a1);
void sub_021EA788(void *a0, void *a1);
BOOL sub_021EA798(void *a0, void *a1);

int sub_021D3630(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    void *p = sub_021B8D8C(ctx->unk_00, ctx->unk_04, (u8)args[0]);

    switch (*state) {
    case 0:
        if (sub_021CD9E0(ctx) != FALSE) {
            return 1;
        }
        sub_021EA768(ctx->unk_054, p, 1);
        (*state)++;
        break;
    case 1:
        if (sub_021EA778(ctx->unk_054, p) != FALSE) {
            (*state)++;
        }
        break;
    default:
        return 1;
    }
    return 0;
}

int sub_021D3688(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    void *p = sub_021B8D8C(ctx->unk_00, ctx->unk_04, (u8)args[0]);

    switch (*state) {
    case 0:
        sub_021EA788(ctx->unk_054, p);
        (*state)++;
        break;
    case 1:
        if (sub_021EA798(ctx->unk_054, p) != FALSE) {
            return 1;
        }
        break;
    }
    return 0;
}
