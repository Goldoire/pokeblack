#include "ov093/battle.h"

// ov093 0x021d3138..0x021d362e: battle-script opcode handlers, ids 72, 73, 74,
// 76, 77, 78, 79 and 80.  Entries in the {handler, opcode-id} table at 0x021F00E0.
//
//     int op(BattleScriptCtx *ctx, u32 *state, u32 *args);

int sub_021B8D8C(BattleSystem *bsys, BattleQueue *q, u8 a1);
void *sub_021B8E70(BattleSystem *bsys, int a1);
u32 sub_021B8590(BattleSystem *bsys);
void *sub_021B9934(BattleQueue *q, u8 a1);
void *sub_021B9AEC(BattleQueue *q, u32 a1);
u32 sub_021B9F70(BattleSystem *bsys, u8 a1);
void sub_021B9C50(void *p, u8 a1, u32 a2, u32 a3);
BOOL sub_021CD9E0(BattleScriptCtx *ctx);
BOOL sub_021D3558(u16 a0);
void sub_021D66D0(void *a0, u32 a1);
void sub_021D66D8(void *a0, u8 a1);
void sub_021D6C2C(void *a0);
void sub_021EA3B8(void *a0, void *a1, u16 a2);
BOOL sub_021EA3D4(void *a0);
void sub_021EA3E8(void *a0, void *a1, void *a2, u16 a3);
BOOL sub_021EA3F8(void *a0);
void sub_021EA614(void *a0, u8 *a1);
void sub_021EA678(void *a0, u32 a1, u32 *a2);
BOOL sub_021EA710(void *a0);
void sub_021EA768(void *a0, int a1, u32 a2);
BOOL sub_021EA778(void *a0, int a1);
void sub_021EA7A8(void *a0, int a1);
BOOL sub_021EA7B8(void *a0, int a1);
void sub_021EA868(void *a0, int a1, BOOL a2);
BOOL sub_021EA878(void *a0);
void sub_021EA888(void *a0, void *a1);
BOOL sub_021EA8A4(void *a0);
void sub_021EAA6C(void *a0, u8 a1, u8 a2);
BOOL sub_021EAAD8(void *a0);
void sub_021EAF18(u8 *a0, u32 a1, u32 a2);
void sub_021F7998(u32 a0);
void sub_021F7D44(void *a0, u16 a1);
BOOL sub_021F7EB4(void);

int sub_021D3138(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    switch (*state) {
    case 0:
        sub_021F7D44(sub_021B8E70(ctx->unk_00, (u8)args[0]), (u16)args[1]);
        (*state)++;
        break;
    case 1:
        if (sub_021F7EB4() == FALSE) {
            sub_021EAF18(ctx->unk_058, 1, 0x43);
            sub_021EA614(ctx->unk_054, ctx->unk_058);
            (*state)++;
        }
        break;
    case 2:
        if (sub_021EA710(ctx->unk_054) != FALSE) {
            return 1;
        }
        break;
    }
    return 0;
}

int sub_021D31A0(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    u8 v0;
    u8 v1;
    u8 f;
    u16 msg;

    switch (*state) {
    case 0:
        v0 = (u8)args[0];
        v1 = (u8)args[1];
        sub_021B9C50(sub_021B9AEC(ctx->unk_04, v0), v1, 0, 0);
        sub_021EAA6C(ctx->unk_054, v0, v1);
        (*state)++;
        break;
    case 1:
        if (sub_021EAAD8(ctx->unk_054) != FALSE) {
            v1 = (u8)args[1];
            if (v1 == 1) {
                return 1;
            }
            f = (u8)sub_021B9F70(ctx->unk_00, (u8)args[0]);
            if (v1 == 3) {
                msg = f != 0 ? 0x26 : 0x27;
            } else {
                msg = f != 0 ? 0x28 : 0x29;
            }
            sub_021EA678(ctx->unk_054, msg, args);
            (*state)++;
        }
        break;
    case 2:
        if (sub_021EA710(ctx->unk_054) != FALSE) {
            return 1;
        }
        break;
    }
    return 0;
}

int sub_021D324C(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    u8 v0 = (u8)args[0];
    int v = sub_021B8D8C(ctx->unk_00, ctx->unk_04, v0);

    switch (*state) {
    case 0:
        if (sub_021CD9E0(ctx) != FALSE) {
            sub_021D66D0(sub_021B9934(ctx->unk_04, v0), args[1]);
            return 1;
        }
        sub_021EA768(ctx->unk_054, v, 0);
        (*state)++;
        break;
    case 1:
        if (sub_021EA778(ctx->unk_054, v) != FALSE) {
            sub_021D66D0(sub_021B9934(ctx->unk_04, v0), args[1]);
            sub_021EA7A8(ctx->unk_054, v);
            (*state)++;
        }
        break;
    case 2:
        if (sub_021EA7B8(ctx->unk_054, v) != FALSE) {
            (*state)++;
        }
        break;
    default:
        return 1;
    }
    return 0;
}

int sub_021D344C(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    u8 v0;
    int d;
    void *p;
    BOOL f;

    switch (*state) {
    case 0:
        v0 = (u8)args[0];
        d = sub_021B8D8C(ctx->unk_00, ctx->unk_04, v0);
        p = sub_021B9934(ctx->unk_04, v0);
        f = sub_021CD9E0(ctx);
        sub_021D6C2C(p);
        sub_021EA868(ctx->unk_054, d, f);
        (*state)++;
        break;
    case 1:
        if (sub_021EA878(ctx->unk_054) != FALSE) {
            (*state)++;
        }
        break;
    default:
        return 1;
    }
    return 0;
}

int sub_021D34B0(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    if (*state == 0) {
        if (sub_021CD9E0(ctx) != FALSE) {
            return 1;
        }
        sub_021F7998(args[0]);
        (*state)++;
    } else {
        if (sub_021F7EB4() == FALSE) {
            return 1;
        }
    }
    return 0;
}

int sub_021D34E8(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    void *p = sub_021B8E70(ctx->unk_00, (u8)args[0]);

    if (*state == 0) {
        if (sub_021CD9E0(ctx) != FALSE) {
            return 1;
        }
        if (sub_021B8590(ctx->unk_00) == 0) {
            if (sub_021D3558((u16)args[1]) != FALSE) {
                return 1;
            }
        }
        sub_021EA3B8(ctx->unk_054, p, (u16)args[1]);
        (*state)++;
    } else {
        if (sub_021EA3D4(ctx->unk_054) != FALSE) {
            return 1;
        }
    }
    return 0;
}

int sub_021D3568(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    void *p1;
    void *p2;

    if (*state == 0) {
        if (sub_021CD9E0(ctx) != FALSE) {
            return 1;
        }
        p1 = sub_021B8E70(ctx->unk_00, (u8)args[0]);
        p2 = sub_021B8E70(ctx->unk_00, (u8)args[1]);
        sub_021EA3E8(ctx->unk_054, p1, p2, (u16)args[2]);
        (*state)++;
    } else {
        if (sub_021EA3F8(ctx->unk_054) != FALSE) {
            return 1;
        }
    }
    return 0;
}

int sub_021D35C8(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    void *p;

    switch (*state) {
    case 0:
        p = sub_021B8E70(ctx->unk_00,
            sub_021B8D8C(ctx->unk_00, ctx->unk_04, (u8)args[0]));
        sub_021D66D8(sub_021B9934(ctx->unk_04, (u8)args[0]), (u8)args[1]);
        sub_021EA888(ctx->unk_054, p);
        (*state)++;
        break;
    case 1:
        if (sub_021EA8A4(ctx->unk_054) != FALSE) {
            (*state)++;
        }
        break;
    default:
        return 1;
    }
    return 0;
}
