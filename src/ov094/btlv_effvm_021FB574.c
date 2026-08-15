#include "types.h"

typedef struct ScriptContext ScriptContext;

typedef struct BattleAnimScript
{
    /* 0x000 */ u32 unk000;
    /* 0x004 */ u32 unk004;
    /* 0x008 */ u8 pad_008[0x238 - 0x008];
    /* 0x238 */ u16 unk238;
    /* 0x23A */ u16 unk23A;
    /* 0x23C */ u32 unk23C;
} BattleAnimScript;

u32 sub_0201134C(ScriptContext *ctx);
void sub_0207D63C(u32 reg, int plane1, int plane2, int ev1, int ev2); // G2x_SetBlendAlpha_
void sub_021F8298(u32 a0, u8 a1, u8 a2, u8 a3, u16 a4);
void sub_021F839C(u32 a0, u32 a1);

u32 sub_021FB574(ScriptContext *ctx, BattleAnimScript *work)
{
    u32 a;

    sub_0201134C(ctx);
    sub_0201134C(ctx);
    a = sub_0201134C(ctx);
    sub_0201134C(ctx);
    sub_0201134C(ctx);
    sub_0201134C(ctx);

    if (a == 0x1F)
    {
        sub_0207D63C(0x04000050, 2, 0x3D, 0x1F, 7);
    }
    else
    {
        sub_0207D63C(0x04000050, 0xA, 0x35, 0x1F, a);
    }

    work->unk000 |= 0x20;

    return work->unk23C;
}

u32 sub_021FB5D4(ScriptContext *ctx, BattleAnimScript *work)
{
    u32 a, b, c, d, e;

    a = sub_0201134C(ctx);
    b = sub_0201134C(ctx);
    c = sub_0201134C(ctx);
    d = sub_0201134C(ctx);
    e = sub_0201134C(ctx);

    sub_021F8298(a, (u8)b, (u8)c, (u8)d, (u16)e);

    return work->unk23C;
}

u32 sub_021FB624(ScriptContext *ctx, BattleAnimScript *work)
{
    u32 a, b;

    a = sub_0201134C(ctx);
    b = sub_0201134C(ctx);

    sub_021F839C(a, b);

    return work->unk23C;
}
