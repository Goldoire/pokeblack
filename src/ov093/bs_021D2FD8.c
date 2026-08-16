#include "ov093/battle.h"

// ov093 0x021d2fd8..0x021d3126: battle-script opcode id 71, the five-phase
// faint/replace sequence.  Entry in the {handler, opcode-id} table at
// 0x021F00E0.
//
//     int op(BattleScriptCtx *ctx, u32 *state, u32 *args);

extern const u16 _021EFF80[];

void *sub_021B8E70(BattleSystem *bsys, u8 a1);
void *sub_021B98AC(BattleQueue *q, u8 a1);
void sub_021B92A0(BattleSystem *bsys);
void sub_021BA2D4(BattleSystem *bsys, void *a1);
u32 sub_021D5440(void *a0);
void sub_021EA614(void *a0, u8 *a1);
BOOL sub_021EA710(void *a0);
void sub_021EAF18(u8 *a0, u32 a1, u32 a2);
void sub_021EAF50(u8 *a0, u32 a1);
void sub_021F7C0C(void);
void sub_021F7CFC(void *a0, u16 a1, u8 a2, u32 a3, u32 a4);
BOOL sub_021F7EB4(void);
void sub_021F883C(u32 a0);
BOOL sub_02005F38(void);
void sub_02005D90(u32 a0, u32 a1);

int sub_021D2FD8(BattleScriptCtx *ctx, u32 *state, const u32 *args)
{
    void *m;
    u32 k;

    switch (*state) {
    case 0:
        sub_021F7CFC(sub_021B8E70(ctx->unk_00, (u8)args[0]), (u16)args[5],
                     (u8)args[1], args[2], args[4]);
        (*state)++;
        break;
    case 1:
        if (sub_021F7EB4() == FALSE) {
            if (args[2] != 0) {
                m = sub_021B98AC(ctx->unk_04, (u8)args[0]);
                sub_021EAF18(ctx->unk_058, 1, 0x41);
                sub_021EAF50(ctx->unk_058, sub_021D5440(m));
                sub_021F883C(0x518);
            } else {
                if (args[1] < 4) {
                    k = _021EFF80[args[1]];
                } else {
                    k = 0x3D;
                }
                sub_021EAF18(ctx->unk_058, 1, k);
            }
            sub_021EA614(ctx->unk_054, ctx->unk_058);
            (*state)++;
        }
        break;
    case 2:
        if (sub_021EA710(ctx->unk_054) != FALSE) {
            if (args[2] != 0) {
                sub_021BA2D4(ctx->unk_00, sub_021B98AC(ctx->unk_04, (u8)args[0]));
                (*state)++;
            } else {
                return 1;
            }
        }
        break;
    case 3:
        if (sub_02005F38() == FALSE) {
            sub_021F7C0C();
            sub_02005D90(0x47C, 0xFFFF);
            sub_021B92A0(ctx->unk_00);
            if (args[3] != 0) {
                m = sub_021B98AC(ctx->unk_04, (u8)args[0]);
                sub_021EAF18(ctx->unk_058, 1, 0x42);
                sub_021EAF50(ctx->unk_058, sub_021D5440(m));
                sub_021EA614(ctx->unk_054, ctx->unk_058);
                (*state)++;
            } else {
                return 1;
            }
        }
        break;
    case 4:
        if (sub_021EA710(ctx->unk_054) != FALSE) {
            (*state)++;
        }
        break;
    default:
        return 1;
    }
    return 0;
}
