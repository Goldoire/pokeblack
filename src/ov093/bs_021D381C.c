#include "ov093/battle.h"

// ov093 0x021d381c..0x021d3b78: battle-script opcode handlers, ids 12, 16, 19,
// 23, 25 and 32.  Entries in the {handler, opcode-id} table at 0x021F00E0.
//
//     int op(BattleScriptCtx *ctx, u32 *state, u32 *args);

void *sub_021B9934(BattleQueue *q, u8 a1);
void *sub_021B9AEC(BattleQueue *q, int a1);
void *sub_021B9BF0(void *p, u8 a1);
void sub_021B9C10(void *p, int a1, int a2);
void sub_021D5734(void *a0, u8 a1, u16 a2, u8 a3, u32 a4);
void sub_021D5EA8(void *a0, u8 a1, u8 a2);
BOOL sub_021D5B68(void *a0);
void sub_021D6034(void *a0, u32 a1, u32 a2);
void sub_021D6064(void *a0, void *a1, u32 a2, u32 a3);
void sub_021D63EC(void *a0, u16 a1);
void sub_021D6580(void *a0);
void sub_021D6744(void *a0, u8 a1, u32 a2, u8 a3, u16 a4, u16 a5);
void sub_021D8090(u32 a0, u8 *a1);
void *sub_021D3A10(u32 a0);

int sub_021D381C(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    void *p = sub_021B9934(ctx->unk_04, (u8)args[0]);

    sub_021D5EA8(p, 1, (u8)args[1]);
    sub_021D5EA8(p, 2, (u8)args[2]);
    sub_021D5EA8(p, 3, (u8)args[3]);
    sub_021D5EA8(p, 4, (u8)args[4]);
    sub_021D5EA8(p, 5, (u8)args[5]);
    sub_021D5EA8(p, 6, (u8)args[6]);
    sub_021D5EA8(p, 7, (u8)args[7]);
    return 1;
}

int sub_021D38E0(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    void *p = sub_021B9934(ctx->unk_04, (u8)args[0]);

    sub_021D6034(p, args[1], args[2]);
    return 1;
}

int sub_021D3934(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    u8 a = (u8)ctx->unk_13C;
    u8 b = (u8)ctx->unk_140;
    void *list = sub_021B9AEC(ctx->unk_04, (u8)ctx->unk_138);
    void *e;

    if (a != b) {
        sub_021B9C10(list, a, b);
    }
    e = sub_021B9BF0(list, a);
    sub_021D63EC(e, (u16)args[3]);
    sub_021D6580(e);
    return 1;
}

int sub_021D39A8(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    u8 slots[8];
    u32 n = args[1];
    u32 count = args[0];
    u32 i;
    u32 j;
    void *e;
    void *p;

    sub_021D8090(args[2], slots);
    for (i = 0; i < n; i++) {
        e = sub_021D3A10(i);
        if (e == NULL) {
            break;
        }
        for (j = 0; j < count; j++) {
            p = sub_021B9934(ctx->unk_04, slots[j]);
            if (sub_021D5B68(p) == FALSE) {
                sub_021D6064(p, e, 0, 0);
            }
        }
    }
    return 1;
}

int sub_021D3A40(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    void *p = sub_021B9934(ctx->unk_04, (u8)args[0]);

    sub_021D6744(p, (u8)args[1], args[2], (u8)args[3], (u16)args[4], (u16)args[5]);
    return 1;
}

int sub_021D3B28(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    void *p = sub_021B9934(ctx->unk_04, (u8)args[0]);

    sub_021D5734(p, (u8)args[1], (u16)args[4], (u8)args[2], args[3]);
    return 1;
}
