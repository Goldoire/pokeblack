#include "types.h"

typedef struct ScriptContext
{
    /* 0x00 */ u8 pad_00[0x14];
    /* 0x14 */ const u8 *scriptPtr;
} ScriptContext;

typedef struct BattleAnimScript
{
    /* 0x000 */ u32 unk000;
    /* 0x004 */ u32 unk004;
    /* 0x008 */ u8 pad_008[0x0DC - 0x008];
    /* 0x0DC */ void *unk0DC;
    /* 0x0E0 */ void *unk0E0;
    /* 0x0E4 */ u8 pad_0E4[0x23C - 0x0E4];
    /* 0x23C */ u32 unk23C;
} BattleAnimScript;

u32 sub_0201134C(ScriptContext *ctx);
void sub_020113B0(ScriptContext *ctx, const u8 *ptr);

void *sub_021F8694(void);
int sub_021F7F1C(u32 a0);
int sub_021FCA04(BattleAnimScript *work, u32 mask, void **out);
u32 sub_021FDBB0(BattleAnimScript *work, u32 id);
void sub_021FFFD8(void *sys, void *sprite, u32 a2, u32 a3);
void sub_02200140(void *sys, void *a1, void *a2);

void sub_021FBDD4(ScriptContext *ctx, int lhs, int rhs, int op, int offset);

u32 sub_021FBD44(ScriptContext *ctx, BattleAnimScript *work)
{
    u32 lhs, op, rhs, offset;

    lhs = sub_021FDBB0(work, sub_0201134C(ctx));
    op = sub_0201134C(ctx);
    rhs = sub_0201134C(ctx);
    offset = sub_0201134C(ctx);

    sub_021FBDD4(ctx, lhs, rhs, op, offset);

    return work->unk23C;
}

u32 sub_021FBD88(ScriptContext *ctx, BattleAnimScript *work)
{
    u32 lhs, op, rhs, offset;

    lhs = sub_021FDBB0(work, sub_0201134C(ctx));
    op = sub_0201134C(ctx);
    rhs = sub_021FDBB0(work, sub_0201134C(ctx));
    offset = sub_0201134C(ctx);

    sub_021FBDD4(ctx, lhs, rhs, op, offset);

    return work->unk23C;
}

void sub_021FBDD4(ScriptContext *ctx, int lhs, int rhs, int op, int offset)
{
    int taken;

    taken = 0;
    switch (op)
    {
    case 0:
        if (lhs == rhs)
        {
            taken = 1;
        }
        break;
    case 1:
        if (lhs != rhs)
        {
            taken = 1;
        }
        break;
    case 2:
        if (lhs < rhs)
        {
            taken = 1;
        }
        break;
    case 3:
        if (lhs > rhs)
        {
            taken = 1;
        }
        break;
    case 4:
        if (lhs <= rhs)
        {
            taken = 1;
        }
        break;
    case 5:
        if (lhs >= rhs)
        {
            taken = 1;
        }
        break;
    }

    if (taken == 1)
    {
        sub_020113B0(ctx, ctx->scriptPtr + offset);
    }
}

u32 sub_021FBE28(ScriptContext *ctx, BattleAnimScript *work)
{
    u32 a, b, offset;

    a = sub_0201134C(ctx);
    b = sub_0201134C(ctx);
    offset = sub_0201134C(ctx);

    if (b == sub_021F7F1C(a))
    {
        sub_020113B0(ctx, ctx->scriptPtr + offset);
    }

    return work->unk23C;
}

u32 sub_021FBE60(ScriptContext *ctx, BattleAnimScript *work)
{
    work->unk004 = sub_0201134C(ctx);
    return work->unk23C;
}

u32 sub_021FBE74(ScriptContext *ctx, BattleAnimScript *work)
{
    work->unk004 = sub_021FDBB0(work, sub_0201134C(ctx));
    return work->unk23C;
}

u32 sub_021FBF48(ScriptContext *ctx, BattleAnimScript *work)
{
    void *sprites[8];
    int count;
    u32 a, b;
    int i;

    a = sub_0201134C(ctx);
    count = sub_021FCA04(work, sub_0201134C(ctx), sprites);
    b = sub_0201134C(ctx);

    if (count != 0)
    {
        for (i = 0; i < count; i++)
        {
            sub_021FFFD8(sub_021F8694(), sprites[i], a, b);
        }
    }

    return work->unk23C;
}

u32 sub_021FBFA0(ScriptContext *ctx, BattleAnimScript *work)
{
    sub_02200140(sub_021F8694(), work->unk0E0, work->unk0DC);
    return work->unk23C;
}
