#include "ov093/battle.h"

// ov093 0x021d2490..0x021d2a1a: battle-script opcode handlers, ids 63..65, 69,
// 83..85 and 87.  Entries in the {handler, opcode-id} table at 0x021F00E0.
//
//     int op(BattleScriptCtx *ctx, u32 *state, u32 *args);
//
// _021EFFAE is a five-entry {message id, effect id} table indexed by the
// opcode's first argument: 0x021D2490 reads the second half in phase 0 and the
// first half in phase 1, which is why the two literal-pool constants are four
// bytes apart with the same stride.

typedef struct UnkPair021EFFAE {
    u16 unk_00;
    u16 unk_02;
} UnkPair021EFFAE;

extern const UnkPair021EFFAE _021EFFAE[];
extern const u16 _021EFF88[];

int sub_021B8D8C(BattleSystem *bsys, BattleQueue *q, u8 a1);
int sub_021B8DC0(BattleSystem *bsys, BattleQueue *q, u8 a1);
int sub_021B8DEC(BattleSystem *bsys, u8 a1);
void *sub_021B8E70(BattleSystem *bsys, int a1);
u32 sub_021B8590(BattleSystem *bsys);
void *sub_021B9934(BattleQueue *q, u8 a1);
void *sub_021B9AEC(BattleQueue *q, u32 a1);
void sub_021B9C10(void *p, u32 a1, u32 a2);
BOOL sub_021CD9E0(BattleScriptCtx *ctx);
void *sub_021D5844(void *a0);
void sub_021D6C2C(void *a0);
void sub_021D6C50(void *a0, void *a1);
u32 sub_021D7AD4(u32 a0);
void sub_021EA1B8(void *a0, u16 a1, int a2, u32 a3);
BOOL sub_021EA1F0(void *a0);
void sub_021EA678(void *a0, u32 a1, u32 *a2);
BOOL sub_021EA710(void *a0);
void sub_021EA838(void *a0, int a1);
BOOL sub_021EA850(void *a0, int a1);
void sub_021EA8B4(void *a0, void *a1, void *a2);
BOOL sub_021EA8D4(void *a0);
void sub_021EA904(void *a0, u8 a1, void *a2, void *a3, u32 a4, u32 a5);
BOOL sub_021EA950(void *a0);
void sub_021EF9C0(void *a0, u8 a1, u16 a2);
void sub_021EF9C8(void *a0);
void sub_021F7EA4(void *a0);
BOOL sub_021F7EB4(void);
void sub_021F7998(u16 a0);
void sub_021F88BC(u32 a0);
u32 sub_02017E1C(void *a0, u16 a1, void *a2);
void sub_02017E40(void *a0, u16 a1, u32 a2);

int sub_021D2490(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    u8 v0 = (u8)args[0];

    switch (*state) {
    case 0:
        sub_021EF9C0(ctx->unk_034, v0, (u16)args[1]);
        if (sub_021CD9E0(ctx) != FALSE) {
            return 1;
        }
        if (v0 < 5) {
            sub_021F7998(_021EFFAE[v0].unk_02);
        }
        (*state)++;
        break;
    case 1:
        if (sub_021F7EB4() == FALSE) {
            sub_021EA678(ctx->unk_054, _021EFFAE[v0].unk_00, NULL);
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

int sub_021D2510(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    u32 msg;

    switch (*state) {
    case 0:
        switch ((u8)args[0]) {
        case 1:
            msg = 0x59;
            break;
        case 2:
            msg = 0x5A;
            break;
        case 4:
            msg = 0x5B;
            break;
        case 3:
            msg = 0x5C;
            break;
        default:
            return 1;
        }
        sub_021EA678(ctx->unk_054, msg, NULL);
        (*state)++;
        break;
    case 1:
        if (sub_021EA710(ctx->unk_054) != FALSE) {
            sub_021EF9C8(ctx->unk_034);
            return 1;
        }
        break;
    }
    return 0;
}

int sub_021D25C4(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    int v = sub_021B8D8C(ctx->unk_00, ctx->unk_04, (u8)args[0]);

    switch (*state) {
    case 0:
        if (sub_021CD9E0(ctx) != FALSE) {
            return 1;
        }
        if (sub_021B8590(ctx->unk_00) == 0) {
            return 1;
        }
        sub_021EA838(ctx->unk_054, v);
        (*state)++;
        break;
    case 1:
        if (sub_021EA850(ctx->unk_054, v) != FALSE) {
            return 1;
        }
        break;
    }
    return 0;
}

int sub_021D266C(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    int d2;
    int d1;
    u8 v0;
    u8 v1;
    u8 v2;
    void *p1;
    void *p2;

    switch (*state) {
    case 0:
        v0 = (u8)args[0];
        v1 = (u8)args[1];
        v2 = (u8)args[2];
        d1 = sub_021B8DEC(ctx->unk_00, v1);
        d2 = sub_021B8DEC(ctx->unk_00, v2);
        p1 = sub_021B8E70(ctx->unk_00, v1);
        p2 = sub_021B8E70(ctx->unk_00, v2);
        sub_021B9C10(sub_021B9AEC(ctx->unk_04, v0), d1, d2);
        sub_021EA904(ctx->unk_054, v0, p1, p2, d1, d2);
        (*state)++;
        break;
    case 1:
        if (sub_021EA950(ctx->unk_054) != FALSE) {
            return 1;
        }
        break;
    }
    return 0;
}

int sub_021D284C(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    void *p;

    switch (*state) {
    case 0:
        p = sub_021B8E70(ctx->unk_00, (u8)args[0]);
        if (sub_021CD9E0(ctx) != FALSE) {
            sub_021F88BC(1);
        }
        sub_021F7EA4(p);
        (*state)++;
        break;
    case 1:
        if (sub_021F7EB4() == FALSE) {
            if (sub_021CD9E0(ctx) != FALSE) {
                sub_021F88BC(0);
            }
            return 1;
        }
        break;
    }
    return 0;
}

int sub_021D28AC(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    void *d1;
    void *p2;
    void *p1;
    void *d2;

    switch (*state) {
    case 0:
        p1 = sub_021B9934(ctx->unk_04, (u8)args[0]);
        p2 = sub_021B9934(ctx->unk_04, (u8)args[1]);
        d1 = (void *)sub_021B8DC0(ctx->unk_00, ctx->unk_04, (u8)args[0]);
        d2 = (void *)sub_021B8DC0(ctx->unk_00, ctx->unk_04, (u8)args[1]);
        sub_021D6C50(p1, p2);
        sub_021EA8B4(ctx->unk_054, d1, d2);
        (*state)++;
        break;
    case 1:
        if (sub_021EA8D4(ctx->unk_054) != FALSE) {
            return 1;
        }
        break;
    }
    return 0;
}

int sub_021D2930(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    int v;

    switch (*state) {
    case 0:
        if (sub_021CD9E0(ctx) == FALSE) {
            v = sub_021B8D8C(ctx->unk_00, ctx->unk_04, (u8)args[0]);
            sub_021EA1B8(ctx->unk_054, (u16)args[2], v, sub_021D7AD4(args[1]));
            (*state)++;
            break;
        }
        return 1;
    case 1:
        if (sub_021EA1F0(ctx->unk_054) != FALSE) {
            return 1;
        }
        break;
    }
    return 0;
}

int sub_021D29CC(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    void *mon = sub_021D5844(sub_021B9934(ctx->unk_04, (u8)args[0]));
    u32 i;
    u16 k;
    u32 v;

    for (i = 0; i < 6; i++) {
        if (_021EFF88[i + 1] != 0) {
            k = _021EFF88[i];
            v = args[i + 1] + sub_02017E1C(mon, k, NULL);
            if (v > 255) {
                v = 255;
            }
            sub_02017E40(mon, k, v);
        }
    }
    return 1;
}
