#include "ov093/battle.h"

// ov093 0x021d3b74..0x021d3d50: battle-script opcode handlers, ids 34..47 and
// 20/67.  Entries in the {handler, opcode-id} table at 0x021F00E0.
//
//     int op(BattleScriptCtx *ctx, u32 *state, u32 *args);
//
// ctx->unk_00 is the owning BattleSystem, ctx->unk_04 the BattleQueue, and
// ctx->unk_34 the message/print object the 0x021EFxxx family drives.

void *sub_021B9934(BattleQueue *q, u8 a1);
void *sub_021B9AEC(void *a0, int a1);
void sub_021B9B10(void *bsys, u8 a1, u32 a2);
void sub_021B9D10(void *bsys, void *a1, u8 a2);
void sub_021CD9F4(void *a0, u32 a1);
void sub_021D5970(void *a0, u32 a1, u16 a2);
void sub_021D6264(void *a0, u8 a1);
void sub_021D6408(void *a0);
void sub_021D6848(void *a0, void *a1);
void sub_021D65C8(void *a0, void *a1);
void sub_021D69A0(void *a0, u32 a1, u8 a2);
void sub_021D6E88(void *a0);
void sub_021EF9F4(void *a0, u32 a1, u32 a2, u32 a3);
void sub_021EFA94(void *a0, u32 a1);
void sub_021EFAD8(void *a0, u32 a1, u8 a2);
void sub_021EFB34(void *a0, u8 a1);
void sub_021EFC78(void *a0, u32 a1, u32 a2);

typedef struct UnkStruct021D3CC8 {
    u16 unk_00;
    u16 unk_02;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
} UnkStruct021D3CC8;

int sub_021D3B74(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    u32 v1 = args[1];

    sub_021EF9F4(ctx->unk_034, args[0], v1, 0);
    return 1;
}

int sub_021D3B88(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    sub_021EFAD8(ctx->unk_034, args[0], (u8)args[1]);
    return 1;
}

int sub_021D3B9C(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    sub_021EFB34(ctx->unk_034, (u8)args[0]);
    return 1;
}

int sub_021D3BB0(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    sub_021EFA94(ctx->unk_034, args[0]);
    return 1;
}

int sub_021D3BC0(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    sub_021D69A0(sub_021B9934(ctx->unk_04, (u8)args[0]), args[1], (u8)args[2]);
    return 1;
}

int sub_021D3BE0(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    void *a = sub_021B9934(ctx->unk_04, (u8)args[0]);
    void *b = sub_021B9934(ctx->unk_04, (u8)args[1]);

    sub_021D65C8(b, a);
    return 1;
}

int sub_021D3C44(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    u8 v0 = (u8)args[0];
    u8 v1 = (u8)args[1];

    if (v0 == ctx->unk_1A6) {
        sub_021CD9F4(ctx, v1);
    } else {
        sub_021B9B10(ctx->unk_00, v0, v1);
    }
    return 1;
}

int sub_021D3C70(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    u8 v0 = (u8)args[0];

    sub_021B9D10(ctx->unk_00, sub_021B9AEC(ctx->unk_04, v0), v0);
    return 1;
}

int sub_021D3CA8(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    sub_021D6264(sub_021B9934(ctx->unk_04, (u8)args[0]), (u8)args[1]);
    return 1;
}

int sub_021D3CC8(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    void *p = sub_021B9934(ctx->unk_04, (u8)args[0]);
    UnkStruct021D3CC8 s = { (u16)args[4], (u16)args[5], (u8)args[3], (u8)args[1], (u8)args[2] };

    sub_021D6848(p, &s);
    return 1;
}

int sub_021D3CFC(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    void *p = sub_021B9934(ctx->unk_04, (u8)args[0]);

    sub_021D6408(p);
    sub_021D6E88(p);
    return 1;
}

int sub_021D3D1C(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    sub_021EFC78(ctx->unk_034, 0, 0);
    return 1;
}

int sub_021D3D2C(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    u32 v1 = args[1];
    void *p = sub_021B9934(ctx->unk_04, (u8)args[0]);

    sub_021D5970(p, v1, (u16)args[2]);
    return 1;
}
