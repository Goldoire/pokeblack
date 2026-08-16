#include "ov093/battle.h"

// ov093 0x021d32e0..0x021d3446: battle-script opcode id 75, the seven-phase
// two-battler swap-in.  Entry in the {handler, opcode-id} table at 0x021F00E0.
//
//     int op(BattleScriptCtx *ctx, u32 *state, u32 *args);
//
// _021F3B64[1] is a .bss frame counter this opcode owns: phase 0 arms it at 8,
// phase 1 counts it down, phase 3 clears it and phase 4 counts it back up.

extern u32 _021F3B64[];

int sub_021B8D8C(BattleSystem *bsys, BattleQueue *q, u8 a1);
void *sub_021B9934(BattleQueue *q, u8 a1);
u32 sub_021B9A24(u8 a0, u8 a1);
BOOL sub_021CD9E0(BattleScriptCtx *ctx);
void sub_021D66D0(void *a0, u16 a1);
void sub_021EA768(void *a0, int a1, u32 a2);
u32 sub_021EA778(void *a0, int a1);
void sub_021EA7A8(void *a0, int a1);
BOOL sub_021EA7B8(void *a0, int a1);

int sub_021D32E0(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    void *p2;
    void *p1;
    int d2;
    u8 v0;
    u8 v1;
    u16 w2;
    int d1;
    u16 w3;
    u8 a;
    u8 b;

    v0 = (u8)args[0];
    v1 = (u8)args[1];
    w2 = (u16)args[2];
    w3 = (u16)args[3];
    d1 = sub_021B8D8C(ctx->unk_00, ctx->unk_04, v0);
    d2 = sub_021B8D8C(ctx->unk_00, ctx->unk_04, v1);
    p1 = sub_021B9934(ctx->unk_04, v0);
    p2 = sub_021B9934(ctx->unk_04, v1);

    switch (*state) {
    case 0:
        if (sub_021CD9E0(ctx) != FALSE) {
            sub_021D66D0(p1, w2);
            sub_021D66D0(p2, w3);
            return 1;
        }
        if (sub_021B9A24(v0, v1) != 0) {
            sub_021D66D0(p1, w2);
            sub_021D66D0(p2, w3);
            return 1;
        }
        sub_021EA768(ctx->unk_054, d1, 0);
        _021F3B64[1] = 8;
        (*state)++;
        break;
    case 1:
        sub_021EA778(ctx->unk_054, d1);
        if (_021F3B64[1] != 0) {
            _021F3B64[1]--;
        } else {
            sub_021EA768(ctx->unk_054, d2, 0);
            (*state)++;
        }
        break;
    case 2:
        a = (u8)sub_021EA778(ctx->unk_054, d1);
        b = (u8)sub_021EA778(ctx->unk_054, d2);
        if (a != 0 && b != 0) {
            (*state)++;
        }
        break;
    case 3:
        sub_021D66D0(p1, w2);
        sub_021D66D0(p2, w3);
        _021F3B64[1] = 0;
        (*state)++;
        break;
    case 4:
        _021F3B64[1]++;
        if (_021F3B64[1] > 8) {
            sub_021EA7A8(ctx->unk_054, d1);
            (*state)++;
        }
        break;
    case 5:
        if (sub_021EA7B8(ctx->unk_054, d1) != FALSE) {
            sub_021EA7A8(ctx->unk_054, d2);
            (*state)++;
        }
        break;
    case 6:
        if (sub_021EA7B8(ctx->unk_054, d2) != FALSE) {
            (*state)++;
        }
        break;
    default:
        return 1;
    }
    return 0;
}
