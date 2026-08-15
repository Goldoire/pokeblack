#include "ov093/battle.h"

// ov093 0x021d2700..0x021d280e: battle-script opcode id 81, the four-phase
// double-swap.  Entry in the {handler, opcode-id} table at 0x021F00E0.
//
//     int op(BattleScriptCtx *ctx, u32 *state, u32 *args);
//
// Phases 1 and 2 run the same six-call sequence over a different pair of
// arguments, which is why CW cross-jumps phase 2's tail into phase 1's call to
// sub_021EA904, and why the eight temporaries get eight distinct stack slots
// instead of being coalesced.

int sub_021B8BEC(BattleSystem *bsys, u8 a1, u8 a2);
void *sub_021B8E70(BattleSystem *bsys, int a1);
void *sub_021B9AEC(BattleQueue *q, u8 a1);
void sub_021B9C10(void *p, u8 a1, u32 a2);
void sub_021EA904(void *a0, u8 a1, void *a2, void *a3, u8 a4, u32 a5);
BOOL sub_021EA950(void *a0);
void sub_021F7998(u32 a0);
BOOL sub_021F7EB4(void);

int sub_021D2700(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    void *q2;
    void *q1;
    int d2;
    int d1;
    void *p2;
    void *p1;
    int c2;
    int c1;
    u8 v0;
    u8 v1;

    switch (*state) {
    case 0:
        sub_021F7998(0x281);
        (*state)++;
        break;
    case 1:
        if (sub_021F7EB4() == FALSE) {
            v0 = (u8)args[0];
            v1 = (u8)args[1];
            c1 = sub_021B8BEC(ctx->unk_00, v0, v1);
            c2 = sub_021B8BEC(ctx->unk_00, v0, 1);
            p1 = sub_021B8E70(ctx->unk_00, c1);
            p2 = sub_021B8E70(ctx->unk_00, c2);
            sub_021B9C10(sub_021B9AEC(ctx->unk_04, v0), v1, 1);
            sub_021EA904(ctx->unk_054, v0, p1, p2, v1, 1);
            (*state)++;
        }
        break;
    case 2:
        if (sub_021EA950(ctx->unk_054) != FALSE) {
            v0 = (u8)args[2];
            v1 = (u8)args[3];
            d1 = sub_021B8BEC(ctx->unk_00, v0, v1);
            d2 = sub_021B8BEC(ctx->unk_00, v0, 1);
            q1 = sub_021B8E70(ctx->unk_00, d1);
            q2 = sub_021B8E70(ctx->unk_00, d2);
            sub_021B9C10(sub_021B9AEC(ctx->unk_04, v0), v1, 1);
            sub_021EA904(ctx->unk_054, v0, q1, q2, v1, 1);
            (*state)++;
        }
        break;
    case 3:
        if (sub_021EA950(ctx->unk_054) != FALSE) {
            return 1;
        }
        break;
    }
    return 0;
}
