#include "ov093/battle.h"

// ov093 0x021d1bd0..0x021d1fb2: battle-script opcode handlers, ids 55, 60, 61,
// 89, 91, 92 and 93.  Entries in the {handler, opcode-id} table at 0x021F00E0.
//
//     int op(BattleScriptCtx *ctx, u32 *state, u32 *args);
//
// This whole run is the "say something, then wait for it" family: phase 0 hands
// a message to ctx->unk_054 and bumps *state, phase 1 polls until the message
// is finished and only then answers 1.  Returning 0 means "call me again next
// frame", which is why these -- unlike the one-shot opcodes at 0x021D36CC --
// do not simply `return 1`.  ctx->unk_058 is the format buffer the text is
// assembled into.

void *sub_021B8E70(BattleSystem *bsys, u8 a1);
int sub_021B8BEC(BattleSystem *bsys, u8 a1, u8 a2);
BOOL sub_021B8CE8(BattleSystem *bsys, u8 a1, u8 a2);
void *sub_021B9920(BattleQueue *q, u8 a1, u8 a2);
u32 sub_021B9F70(BattleSystem *bsys, u8 a1);
u32 sub_021D5440(void *a0);
u32 sub_021D1DF4(BattleScriptCtx *ctx);
void sub_021CDECC(BattleScriptCtx *ctx);
void sub_021EA488(void *a0, int a1, u8 a2, u8 a3);
BOOL sub_021EA4C4(void *a0);
int sub_021B8D8C(BattleSystem *bsys, BattleQueue *q, u8 a1);
BOOL sub_021CD9E0(BattleScriptCtx *ctx);
u32 sub_021D1C40(BattleScriptCtx *ctx, u8 a1, u32 *a2);
void sub_021EA458(void *a0, void *a1, u16 a2);
BOOL sub_021EA478(void *a0);
void sub_021EA614(void *a0, u8 *a1);
void sub_021EA678(void *a0, u16 a1, u32 *a2);
void sub_021EA694(void *a0, u16 a1, u32 *a2);
BOOL sub_021EA710(void *a0);
BOOL sub_021EA720(void *a0);
void sub_021EAF18(u8 *a0, u32 a1, u32 a2);
void sub_021EAF50(u8 *a0, u32 a1);
void sub_020061E4(u32 a0);

int sub_021D1BD0(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    u32 flag;

    switch (*state) {
    case 0:
        sub_021EAF18(ctx->unk_058, 1, sub_021D1C40(ctx, (u8)args[0], &flag));
        if (flag != 0) {
            sub_021EAF50(ctx->unk_058, args[0]);
        }
        sub_021EAF50(ctx->unk_058, args[1]);
        sub_021EA614(ctx->unk_054, ctx->unk_058);
        (*state)++;
        break;
    case 1:
        if (sub_021EA710(ctx->unk_054) != FALSE) {
            return 1;
        }
        break;
    }
    return 0;
}

int sub_021D1CAC(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    switch (*state) {
    case 0:
        sub_021EA458(ctx->unk_054, sub_021B8E70(ctx->unk_00, (u8)args[0]), (u16)args[1]);
        (*state)++;
        break;
    case 1:
        if (sub_021EA478(ctx->unk_054) != FALSE) {
            return 1;
        }
        break;
    }
    return 0;
}

int sub_021D1CF4(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    u8 v0 = (u8)args[0];
    u8 v1 = (u8)args[1];
    u8 v3 = (u8)args[3];
    u32 t;

    switch (*state) {
    case 0:
        if (v3 != 0) {
            t = sub_021D5440(sub_021B9920(ctx->unk_04, v0, v1));
            if (sub_021B8CE8(ctx->unk_00, ctx->unk_1A6, v0) == FALSE) {
                if (ctx->unk_1A6 == v0) {
                    sub_021EAF18(ctx->unk_058, 1, sub_021D1DF4(ctx));
                sub_021EAF50(ctx->unk_058, t);
                sub_021EA614(ctx->unk_054, ctx->unk_058);
                } else {
                    sub_021EAF18(ctx->unk_058, 1, 0x11);
                    sub_021EAF50(ctx->unk_058, v0);
                sub_021EAF50(ctx->unk_058, t);
                sub_021EA614(ctx->unk_054, ctx->unk_058);
                }
            } else if (sub_021B9F70(ctx->unk_00, v0) != 0) {
                sub_021EAF18(ctx->unk_058, 1, 0x0E);
                sub_021EAF50(ctx->unk_058, v0);
                sub_021EAF50(ctx->unk_058, t);
                sub_021EA614(ctx->unk_054, ctx->unk_058);
            } else {
                sub_021EAF18(ctx->unk_058, 1, 0x11);
                sub_021EAF50(ctx->unk_058, v0);
                sub_021EAF50(ctx->unk_058, t);
                sub_021EA614(ctx->unk_054, ctx->unk_058);
            }
        }
        (*state)++;
        break;
    case 1:
        if (sub_021EA710(ctx->unk_054) != FALSE) {
            sub_021EA488(ctx->unk_054, sub_021B8BEC(ctx->unk_00, v0, v1), v0, v1);
            (*state)++;
        }
        break;
    case 2:
        if (sub_021EA4C4(ctx->unk_054) != FALSE) {
            sub_021CDECC(ctx);
            return 1;
        }
        break;
    }
    return 0;
}

int sub_021D1E6C(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    switch (*state) {
    case 0:
        if (sub_021CD9E0(ctx) != FALSE) {
            return 1;
        }
        sub_021EA678(ctx->unk_054, (u16)args[0], &args[1]);
        (*state)++;
        break;
    case 1:
        if (sub_021EA710(ctx->unk_054) != FALSE) {
            return 1;
        }
        break;
    }
    return 0;
}

int sub_021D1EB4(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    switch (*state) {
    case 0:
        if (sub_021CD9E0(ctx) != FALSE) {
            return 1;
        }
        sub_021EA678(ctx->unk_054, (u16)args[0], &args[2]);
        (*state)++;
        break;
    case 1:
        if (sub_021EA720(ctx->unk_054) != FALSE) {
            sub_020061E4(args[1]);
        }
        if (sub_021EA710(ctx->unk_054) != FALSE) {
            return 1;
        }
        break;
    }
    return 0;
}

int sub_021D1F10(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    switch (*state) {
    case 0:
        if (sub_021CD9E0(ctx) != FALSE) {
            return 1;
        }
        sub_021EA694(ctx->unk_054, (u16)args[0], &args[1]);
        (*state)++;
        break;
    case 1:
        if (sub_021EA710(ctx->unk_054) != FALSE) {
            return 1;
        }
        break;
    }
    return 0;
}

int sub_021D1F58(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    switch (*state) {
    case 0:
        if (sub_021CD9E0(ctx) != FALSE) {
            return 1;
        }
        sub_021EA694(ctx->unk_054, (u16)args[0], &args[2]);
        (*state)++;
        break;
    case 1:
        if (sub_021EA720(ctx->unk_054) != FALSE) {
            sub_020061E4(args[1]);
        }
        if (sub_021EA710(ctx->unk_054) != FALSE) {
            return 1;
        }
        break;
    }
    return 0;
}
