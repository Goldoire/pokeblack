#include "ov093/battle.h"

// ov093 0x021d2a20..0x021d2c60: battle-script opcode id 70, the fourteen-phase
// Pokemon-swap/evolution-style sequence.  Entry in the {handler, opcode-id}
// table at 0x021F00E0.
//
//     int op(BattleScriptCtx *ctx, u32 *state, u32 *args);
//
// The 0x021F3B64 .bss block is this opcode's scratch: +0x08 is a frame
// counter whose address is handed to sub_021D2CA8, +0x0C carries the value the
// script passed in, and +0x14 is a small buffer sub_021D69B8 / sub_021EADA4
// read.  Phase 0 deliberately falls through into phase 1 after arming it.
// (src/ov093/bs_021D32E0.c spells the same object `extern u32 _021F3B64[]`
// because it only ever touches +0x04.)

typedef struct UnkStruct021F3B64 {
    u8 filler_00[0x08];
    int unk_08;
    u32 unk_0C;
    u8 filler_10[0x04];
    u8 unk_14[0x04];
} UnkStruct021F3B64;

extern UnkStruct021F3B64 _021F3B64;

void sub_021B9358(BattleSystem *bsys, u8 a1);
int sub_021B8DC0(BattleSystem *bsys, BattleQueue *q, u8 a1);
void *sub_021B9934(BattleQueue *q, u8 a1);
void sub_021BA238(BattleSystem *bsys, void *a1);
BOOL sub_021D2CA8(BattleScriptCtx *ctx, int *a1, void *a2);
void sub_021D6BFC(void *a0);
void sub_021D6EA0(void *a0);
BOOL sub_021D69B8(void *a0, u32 *a1, u8 *a2);
void sub_021EA3B8(void *a0, int a1, u32 a2);
BOOL sub_021EA3D4(void *a0);
void sub_021EA614(void *a0, u8 *a1);
BOOL sub_021EA710(void *a0);
BOOL sub_021EA720(void *a0);
void sub_021EADA4(void *a0, void *a1, u8 *a2);
BOOL sub_021EADB4(void *a0);
void sub_021EADC4(void *a0);
BOOL sub_021EADD4(void *a0);
void sub_021EADE4(void *a0);
BOOL sub_021EADF4(void *a0);
void sub_021EAF18(u8 *a0, u32 a1, u32 a2);
void sub_021EAF50(u8 *a0, u32 a1);
BOOL sub_021F8134(int a0, u32 a1);
void sub_021F8150(int a0, void *a1);
BOOL sub_021F8180(void);
BOOL sub_021F8204(int a0);
void sub_02005DE4(u32 a0);
void sub_02005D90(u32 a0, u32 a1);
void sub_02005E64(void);
void sub_02005E9C(void);
BOOL sub_02005F38(void);
BOOL sub_02006238(void);
u32 sub_020362DC(void);
u32 sub_02035C60(void);

int sub_021D2A20(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    u32 t;
    u8 v0;
    int d;
    void *p;
    BOOL flag;

    v0 = (u8)args[0];
    p = sub_021B9934(ctx->unk_04, v0);
    d = sub_021B8DC0(ctx->unk_00, ctx->unk_04, v0);
    flag = FALSE;
    if (d != 0xFF && sub_021F8204(d) != FALSE) {
        flag = TRUE;
    }

    switch (*state) {
    case 0:
        _021F3B64.unk_0C = args[1];
        _021F3B64.unk_08 = 0;
        *state = 1;
        /* fall through */
    case 1:
        if (_021F3B64.unk_0C != 0) {
            t = _021F3B64.unk_0C;
            if (sub_021D69B8(p, &t, _021F3B64.unk_14) != FALSE) {
                *state = 3;
            } else {
                if (flag != FALSE) {
                    sub_021F8134(d, _021F3B64.unk_0C);
                    *state = 2;
                } else {
                    *state = 13;
                }
                t = 0;
            }
            _021F3B64.unk_0C = t;
        } else {
            *state = 13;
        }
        break;
    case 2:
        if (sub_021F8180() == FALSE) {
            *state = 13;
        }
        break;
    case 3:
        sub_021D6EA0(p);
        sub_021D6BFC(p);
        if (flag != FALSE) {
            sub_021F8150(d, p);
            *state = 4;
        } else {
            *state = 6;
        }
        break;
    case 4:
        if (sub_021F8180() == FALSE && sub_02006238() == FALSE) {
            sub_021EA3B8(ctx->unk_054, d, 0x25D);
            *state = 5;
        }
        break;
    case 5:
        if (sub_021EA3D4(ctx->unk_054) != FALSE) {
            *state = 6;
        }
        break;
    case 6:
        sub_021EAF18(ctx->unk_058, 1, 0x3C);
        sub_021EAF50(ctx->unk_058, v0);
        sub_021EAF50(ctx->unk_058, _021F3B64.unk_14[0]);
        sub_021EA614(ctx->unk_054, ctx->unk_058);
        *state = 7;
        break;
    case 7:
        if (sub_021EA720(ctx->unk_054) != FALSE) {
            sub_02005DE4(1);
            sub_02005E64();
            sub_02005D90(0x515, 0xFFFF);
        }
        if (sub_021EA710(ctx->unk_054) == FALSE) {
            break;
        }
        if (sub_02005F38() != FALSE) {
            break;
        }
        sub_02005E9C();
        sub_02005DE4(0);
        _021F3B64.unk_08 = 0;
        *state = 8;
        break;
    case 8:
        _021F3B64.unk_08++;
        if ((sub_020362DC() & 3) != 0 || sub_02035C60() != 0
            || _021F3B64.unk_08 > 0x50) {
            _021F3B64.unk_08 = 0;
            sub_021BA238(ctx->unk_00, p);
            sub_021EADA4(ctx->unk_054, p, _021F3B64.unk_14);
            *state = 9;
        }
        break;
    case 9:
        if (sub_021EADB4(ctx->unk_054) == FALSE) {
            break;
        }
        if ((sub_020362DC() & 3) == 0 && sub_02035C60() == 0) {
            break;
        }
        sub_021EADC4(ctx->unk_054);
        *state = 10;
        break;
    case 10:
        if (sub_021EADD4(ctx->unk_054) == FALSE) {
            break;
        }
        if ((sub_020362DC() & 3) == 0 && sub_02035C60() == 0) {
            break;
        }
        sub_021EADE4(ctx->unk_054);
        *state = 11;
        break;
    case 11:
        if (sub_021EADF4(ctx->unk_054) != FALSE) {
            _021F3B64.unk_08 = 0;
            *state = 12;
        }
        break;
    case 12:
        if (sub_021D2CA8(ctx, &_021F3B64.unk_08, p) != FALSE) {
            *state = 1;
        }
        break;
    case 13:
        sub_021B9358(ctx->unk_00, v0);
        return 1;
    }
    return 0;
}
