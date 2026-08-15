#include "types.h"

// Battle-animation script commands. The VM lives in main: a command is
// BOOL cmd(ScriptContext *ctx, void *data) where `data` is ctx->data (0x20),
// here the battle-animation work struct. sub_0201134C is ScriptReadWord.
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

/* Same object as every other btlv file's AnimVec3, which include/ov094.h
 * records as the SDK's VecFx32 (proved by the NNS_G3dWorldPosToScrPos call in
 * btlv_effvm_021FB6F4.c).  Renamed from AnimVec3 and widened from u32 to s32;
 * both spellings produce identical code here (plain stores). */
typedef struct AnimVec3
{
    s32 x;
    s32 y;
    s32 z;
} AnimVec3;

u32 sub_0201134C(ScriptContext *ctx);

void *sub_021F8694(void);
void sub_021F7F04(void *sprite);
void sub_021F7F58(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
void *sub_021F84D0(u32 a0);
void sub_021F8010(u32 a0);
int sub_021FCA04(BattleAnimScript *work, u32 mask, void **out);
u32 sub_021FCF2C(ScriptContext *ctx, u32 a1);
void sub_021FF304(void *sys, void *sprite, u32 a2);
void sub_021FF374(void *sys, void *sprite, u32 a2);
void sub_021FF470(void *sys, void *sprite, u8 a2);
void sub_021FF4C0(void *sys, void *a1, u32 a2, AnimVec3 *a3, u32 a4, u32 a5, u32 a6);
void sub_021FF6B0(void *sys, void *sprite, u32 a2, AnimVec3 *a3, u32 a4, u32 a5, u32 a6);
void sub_021FF870(void *sys, void *sprite, u32 a2, u32 a3, u32 a4);
void sub_021FFDB4(void *sys, void *sprite, u8 a2, u8 a3, u8 a4, u32 a5);
u32 sub_0220041C(void *sys, u32 a1, u32 a2);
void sub_02200468(void *sys, u32 a1);
void sub_02200654(void *sys);

u32 sub_021FB034(ScriptContext *ctx, BattleAnimScript *work)
{
    void *sprites[8];
    int count;
    u32 a, b, c;
    int i;

    count = sub_021FCA04(work, sub_0201134C(ctx), sprites);
    a = sub_0201134C(ctx);
    b = sub_0201134C(ctx);
    c = sub_0201134C(ctx);

    if (count != 0)
    {
        if (c == 0)
        {
            c = 1;
        }
        for (i = 0; i < count; i++)
        {
            sub_021FF870(sub_021F8694(), sprites[i], a, b, c);
        }
    }

    return work->unk23C;
}

u32 sub_021FB09C(ScriptContext *ctx, BattleAnimScript *work)
{
    void *sprites[8];
    int count;
    u32 a;
    int i;

    count = sub_021FCA04(work, sub_0201134C(ctx), sprites);
    a = sub_0201134C(ctx);

    if (count != 0)
    {
        for (i = 0; i < count; i++)
        {
            sub_021FF304(sub_021F8694(), sprites[i], a);
        }
    }

    return work->unk23C;
}

u32 sub_021FB0E8(ScriptContext *ctx, BattleAnimScript *work)
{
    void *sprites[8];
    int count;
    u32 a, b, c, d;
    int i;

    count = sub_021FCA04(work, sub_0201134C(ctx), sprites);
    a = sub_0201134C(ctx);
    b = sub_0201134C(ctx);
    c = sub_0201134C(ctx);
    d = sub_0201134C(ctx);

    if (count != 0)
    {
        for (i = 0; i < count; i++)
        {
            sub_021FFDB4(sub_021F8694(), sprites[i], (u8)a, (u8)b, (u8)c, d);
        }
    }

    return work->unk23C;
}

u32 sub_021FB168(ScriptContext *ctx, BattleAnimScript *work)
{
    void *sprites[8];
    int count;
    u32 a;
    int i;

    count = sub_021FCA04(work, sub_0201134C(ctx), sprites);
    a = sub_0201134C(ctx);

    if (a == 5)
    {
        sub_02200654(sub_021F8694());
    }
    else if (count != 0)
    {
        for (i = 0; i < count; i++)
        {
            sub_021FF374(sub_021F8694(), sprites[i], a);
        }
    }

    return work->unk23C;
}

u32 sub_021FB1C4(ScriptContext *ctx, BattleAnimScript *work)
{
    void *sprites[8];
    int count;
    u32 a;
    int i;

    count = sub_021FCA04(work, sub_0201134C(ctx), sprites);
    a = sub_0201134C(ctx);

    if (count != 0)
    {
        for (i = 0; i < count; i++)
        {
            sub_021FF470(sub_021F8694(), sprites[i], (u8)a);
        }
    }

    return work->unk23C;
}

u32 sub_021FB214(ScriptContext *ctx, BattleAnimScript *work)
{
    AnimVec3 vec;
    void *sprites[8];
    int count;
    u32 a, b, c, d;
    int i;

    count = sub_021FCA04(work, sub_0201134C(ctx), sprites);
    a = sub_0201134C(ctx);
    vec.x = sub_0201134C(ctx);
    vec.y = sub_0201134C(ctx);
    vec.z = 0x1000;
    b = sub_0201134C(ctx);
    c = sub_0201134C(ctx);
    d = sub_0201134C(ctx);

    if (count != 0)
    {
        for (i = 0; i < count; i++)
        {
            sub_021FF6B0(sub_021F8694(), sprites[i], a, &vec, b, c, d);
        }
    }

    return work->unk23C;
}

u32 sub_021FB298(ScriptContext *ctx, BattleAnimScript *work)
{
    void *sprites[8];
    int count;
    int i;

    count = sub_021FCA04(work, sub_0201134C(ctx), sprites);

    if (count != 0)
    {
        for (i = 0; i < count; i++)
        {
            sub_021F7F04(sprites[i]);
        }
    }

    return work->unk23C;
}

u32 sub_021FB2D0(ScriptContext *ctx, BattleAnimScript *work)
{
    u32 a, b, c, d, e;

    a = sub_0201134C(ctx);
    b = sub_021FCF2C(ctx, sub_0201134C(ctx));
    c = sub_0201134C(ctx);
    d = sub_0201134C(ctx);
    e = sub_0201134C(ctx);

    if (a == (u32)-1)
    {
        a = work->unk004;
    }

    sub_021F7F58(a, b, c, d, e);

    return work->unk23C;
}

u32 sub_021FB328(ScriptContext *ctx, BattleAnimScript *work)
{
    AnimVec3 vec;
    void *a;
    u32 b, c, d, e;

    a = sub_021F84D0(sub_0201134C(ctx));
    b = sub_0201134C(ctx);
    vec.x = sub_0201134C(ctx);
    vec.y = sub_0201134C(ctx);
    vec.z = sub_0201134C(ctx);
    c = sub_0201134C(ctx);
    d = sub_0201134C(ctx);
    e = sub_0201134C(ctx);

    sub_021FF4C0(sub_021F8694(), a, b, &vec, c, d, e);

    return work->unk23C;
}

u32 sub_021FB390(ScriptContext *ctx, BattleAnimScript *work)
{
    u32 a, b;

    a = sub_0201134C(ctx);
    b = sub_0201134C(ctx);

    if (sub_0220041C(sub_021F8694(), a, b) == 1)
    {
        sub_02200468(sub_021F8694(), a);
    }

    return work->unk23C;
}

u32 sub_021FB3C8(ScriptContext *ctx, BattleAnimScript *work)
{
    sub_021F8010(sub_0201134C(ctx));
    return work->unk23C;
}
