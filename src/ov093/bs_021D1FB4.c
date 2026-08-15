#include "ov093/battle.h"

// ov093 0x021d1fb4..0x021d248e: battle-script opcode handlers, ids 48..53, 56,
// 57, 58 and 62.  Entries in the {handler, opcode-id} table at 0x021F00E0.
//
//     int op(BattleScriptCtx *ctx, u32 *state, u32 *args);
//
// Two- and three-phase opcodes: kick the effect off, then poll ctx->unk_054
// until it reports done.  sub_021EA7E8 is declared with two parameters here
// because the call sites materialise r1; src/ov093/unk_021EA7E8.c matches the
// callee itself with one, i.e. it ignores the second.

int sub_021B8D8C(BattleSystem *bsys, BattleQueue *q, u8 a1);
int sub_021B8DC0(BattleSystem *bsys, BattleQueue *q, u8 a1);
void *sub_021B8E70(BattleSystem *bsys, int a1);
u32 sub_021B8590(BattleSystem *bsys);
void *sub_021B9934(BattleQueue *q, u8 a1);
BOOL sub_021CD9E0(BattleScriptCtx *ctx);
u8 sub_021CD644(u32 a0);
u32 sub_021D2000(BattleScriptCtx *ctx, u16 a1, u8 a2);
void sub_021D646C(void *a0);
void sub_021EA0A0(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
BOOL sub_021EA0E4(void *a0);
void sub_021EA0F4(void *a0, u32 a1, u32 a2, u32 a3);
BOOL sub_021EA120(void *a0);
void sub_021EA280(void *a0, int a1, u32 a2, u8 *a3, u32 a4);
BOOL sub_021EA2BC(void *a0);
void sub_021EA354(void *a0, int a1, u32 a2);
void sub_021EA384(void *a0, int a1);
BOOL sub_021EA3A0(void *a0);
void sub_021EA40C(void *a0, int a1);
BOOL sub_021EA428(void *a0);
void sub_021EA678(void *a0, u32 a1, u32 *a2);
void sub_021EA6F4(void *a0, u8 a1, u16 a2);
BOOL sub_021EA710(void *a0);
void sub_021EA7C8(void *a0, void *a1);
void sub_021EA7D8(void *a0, void *a1);
BOOL sub_021EA7E8(void *a0, void *a1);
BOOL sub_021F7EB4(void);
void sub_020061E4(u32 a0);
u32 sub_0201BD28(u32 a0, u32 a1);

int sub_021D1FB4(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    switch (*state) {
    case 0:
        if (sub_021CD9E0(ctx) != FALSE) {
            return 1;
        }
        sub_021EA6F4(ctx->unk_054, (u8)args[0], (u16)args[1]);
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

int sub_021D2030(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    u16 v2;
    u8 v1;
    u8 v0;
    u8 v3;
    u32 r;

    switch (*state) {
    case 0:
        if (sub_021CD9E0(ctx) != FALSE) {
            return 1;
        }
        if (sub_021B8590(ctx->unk_00) != 0) {
            v0 = (u8)args[0];
            v1 = (u8)args[1];
            v2 = (u16)args[2];
            v3 = (u8)args[3];
            r = sub_021D2000(ctx, v2, v0);
            sub_021EA0A0(ctx->unk_054, v0, v1, v2, r, v3, 0);
            (*state)++;
            break;
        }
        return 1;
    case 1:
        if (sub_021EA0E4(ctx->unk_054) != FALSE) {
            return 1;
        }
        break;
    }
    return 0;
}

int sub_021D20BC(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    switch (*state) {
    case 0:
        sub_021EA354(ctx->unk_054, sub_021B8DC0(ctx->unk_00, ctx->unk_04, (u8)args[0]),
                     args[1] != 0);
        (*state)++;
        break;
    case 1:
        if (sub_021F7EB4() == FALSE) {
            return 1;
        }
        return 0;
    }
    return 0;
}

int sub_021D210C(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    switch (*state) {
    case 0:
        sub_021EA0F4(ctx->unk_054, (u16)args[2],
                     sub_021B8D8C(ctx->unk_00, ctx->unk_04, (u8)args[0]), (u8)args[1]);
        (*state)++;
        break;
    case 1:
        if (sub_021EA120(ctx->unk_054) != FALSE) {
            return 1;
        }
        break;
    }
    return 0;
}

int sub_021D215C(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    u8 slots[8];
    u32 v1;
    u16 v2;
    int n;
    u8 i;

    switch (*state) {
    case 0:
        n = (u16)args[0];
        i = 0;
        v1 = args[1];
        v2 = (u16)args[2];
        for (; i < n; i++) {
            slots[i] = sub_021CD644(ctx->unk_134);
        }
        sub_021EA280(ctx->unk_054, n, v1, slots, v2);
        (*state)++;
        break;
    case 1:
        if (sub_021EA2BC(ctx->unk_054) != FALSE) {
            return 1;
        }
        break;
    }
    return 0;
}

int sub_021D21D4(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    switch (*state) {
    case 0:
        sub_021EA384(ctx->unk_054, sub_021B8D8C(ctx->unk_00, ctx->unk_04, (u8)args[0]));
        (*state)++;
        break;
    case 1:
        if (sub_021EA3A0(ctx->unk_054) != FALSE) {
            sub_021EA678(ctx->unk_054, 0x61, args);
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

int sub_021D2278(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    int v;

    switch (*state) {
    case 0:
        if (sub_021CD9E0(ctx) == FALSE) {
            v = sub_021B8D8C(ctx->unk_00, ctx->unk_04, (u8)args[0]);
            sub_021EA0A0(ctx->unk_054, v, v, 1, sub_0201BD28(1, 0x1B), 0, 0);
        }
        (*state)++;
        break;
    case 1:
        if (sub_021EA0E4(ctx->unk_054) != FALSE) {
            v = sub_021B8D8C(ctx->unk_00, ctx->unk_04, (u8)args[0]);
            if (sub_021CD9E0(ctx) == FALSE) {
                sub_020061E4(0x564);
            }
            sub_021EA0F4(ctx->unk_054, 1, v, 1);
            (*state)++;
        }
        break;
    case 2:
        if (sub_021EA120(ctx->unk_054) != FALSE) {
            return 1;
        }
        break;
    }
    return 0;
}

int sub_021D2320(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    switch (*state) {
    case 0:
        sub_021EA40C(ctx->unk_054, sub_021B8D8C(ctx->unk_00, ctx->unk_04, (u8)args[0]));
        (*state)++;
        break;
    case 1:
        if (sub_021EA428(ctx->unk_054) != FALSE) {
            sub_021D646C(sub_021B9934(ctx->unk_04, (u8)args[0]));
            return 1;
        }
        break;
    }
    return 0;
}

int sub_021D23B8(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    void *v = sub_021B8E70(ctx->unk_00,
        sub_021B8D8C(ctx->unk_00, ctx->unk_04, (u8)args[0]));

    switch (*state) {
    case 0:
        if (sub_021CD9E0(ctx) != FALSE) {
            return 1;
        }
        if (sub_021B8590(ctx->unk_00) == 0) {
            return 1;
        }
        sub_021EA7C8(ctx->unk_054, v);
        (*state)++;
        break;
    case 1:
        if (sub_021EA7E8(ctx->unk_054, v) != FALSE) {
            return 1;
        }
        break;
    }
    return 0;
}

int sub_021D2424(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    void *v = sub_021B8E70(ctx->unk_00,
        sub_021B8D8C(ctx->unk_00, ctx->unk_04, (u8)args[0]));

    switch (*state) {
    case 0:
        if (sub_021CD9E0(ctx) != FALSE) {
            return 1;
        }
        if (sub_021B8590(ctx->unk_00) == 0) {
            return 1;
        }
        sub_021EA7D8(ctx->unk_054, v);
        (*state)++;
        break;
    case 1:
        if (sub_021EA7E8(ctx->unk_054, v) != FALSE) {
            return 1;
        }
        break;
    }
    return 0;
}
