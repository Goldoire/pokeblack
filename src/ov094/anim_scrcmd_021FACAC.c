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

typedef struct AnimVec3
{
    s32 x;
    s32 y;
    s32 z;
} AnimVec3;

// Parameter block handed to sub_021FFA18; only the fields the command fills in
// are named, the rest is padding out to the 0x3C the caller reserves.
typedef struct AnimParamsA18
{
    /* 0x00 */ u32 unk00;
    /* 0x04 */ void *unk04;
    /* 0x08 */ u32 unk08;
    /* 0x0C */ u32 unk0C;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ u32 unk24;
    /* 0x28 */ u8 pad_28[0x3C - 0x28];
} AnimParamsA18;

u32 sub_0201134C(ScriptContext *ctx);

void *sub_021F8694(void);
int sub_021FCA04(BattleAnimScript *work, u32 mask, void **out);
void sub_021FF4C0(void *sys, void *sprite, u32 a2, AnimVec3 *a3, u32 a4, u32 a5, u32 a6);
void sub_021FF5B0(void *sys, void *sprite, u32 a2, AnimVec3 *a3, u32 a4, u32 a5, u32 a6);
void sub_021FF730(void *sys, void *sprite, u32 a2, AnimVec3 *a3, u32 a4, u32 a5, u32 a6);
void sub_021FF924(void *sys, void *sprite, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
void sub_021FFA18(void *sys, AnimParamsA18 *params);
void sub_021FFBBC(void *sys, void *sprite, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);

u32 sub_021FACAC(ScriptContext *ctx, BattleAnimScript *work)
{
    void *sprites[8];
    AnimVec3 vec;
    int count;
    u32 a, d, e, f;
    int i;

    count = sub_021FCA04(work, sub_0201134C(ctx), sprites);
    a = sub_0201134C(ctx);
    vec.x = sub_0201134C(ctx);
    vec.y = sub_0201134C(ctx);
    vec.z = 0;
    d = sub_0201134C(ctx);
    e = sub_0201134C(ctx);
    f = sub_0201134C(ctx);

    if (count != 0)
    {
        for (i = 0; i < count; i++)
        {
            sub_021FF4C0(sub_021F8694(), sprites[i], a, &vec, d, e, f);
        }
    }

    return work->unk23C;
}

u32 sub_021FAD2C(ScriptContext *ctx, BattleAnimScript *work)
{
    AnimParamsA18 params;
    void *sprites[8];
    int count;
    int i;

    count = sub_021FCA04(work, sub_0201134C(ctx), sprites);
    params.unk08 = sub_0201134C(ctx);
    params.unk0C = sub_0201134C(ctx);
    params.unk10 = sub_0201134C(ctx);
    params.unk14 = sub_0201134C(ctx);
    params.unk18 = (s32)sub_0201134C(ctx) >> 12;
    params.unk1C = (s32)sub_0201134C(ctx) >> 12;
    params.unk20 = (s32)sub_0201134C(ctx) >> 12;
    params.unk24 = sub_0201134C(ctx);

    if (count != 0 && params.unk20 != 0)
    {
        for (i = 0; i < count; i++)
        {
            params.unk04 = sprites[i];
            sub_021FFA18(sub_021F8694(), &params);
        }
    }

    return work->unk23C;
}

u32 sub_021FAE48(ScriptContext *ctx, BattleAnimScript *work)
{
    AnimVec3 vec;
    void *sprites[8];
    int count;
    u32 a, d, e, f;
    int i;

    count = sub_021FCA04(work, sub_0201134C(ctx), sprites);
    a = sub_0201134C(ctx);
    vec.x = sub_0201134C(ctx);
    vec.y = sub_0201134C(ctx);
    vec.z = 0x1000;
    d = sub_0201134C(ctx);
    e = sub_0201134C(ctx);
    f = sub_0201134C(ctx);

    if (count != 0)
    {
        for (i = 0; i < count; i++)
        {
            sub_021FF5B0(sub_021F8694(), sprites[i], a, &vec, d, e, f);
        }
    }

    return work->unk23C;
}

u32 sub_021FAECC(ScriptContext *ctx, BattleAnimScript *work)
{
    void *sprites[8];
    AnimVec3 vec;
    int count;
    u32 a, d, e, f;
    int i;

    count = sub_021FCA04(work, sub_0201134C(ctx), sprites);
    a = sub_0201134C(ctx);
    vec.x = 0;
    vec.y = 0;
    vec.z = sub_0201134C(ctx);
    d = sub_0201134C(ctx);
    e = sub_0201134C(ctx);
    f = sub_0201134C(ctx);

    if (count != 0)
    {
        for (i = 0; i < count; i++)
        {
            sub_021FF730(sub_021F8694(), sprites[i], a, &vec, d, e, f);
        }
    }

    return work->unk23C;
}

u32 sub_021FAF44(ScriptContext *ctx, BattleAnimScript *work)
{
    void *sprites[8];
    int count;
    u32 a, b, c, d, e;
    int i;

    count = sub_021FCA04(work, sub_0201134C(ctx), sprites);
    a = sub_0201134C(ctx);
    b = sub_0201134C(ctx);
    c = sub_0201134C(ctx);
    d = sub_0201134C(ctx);
    e = sub_0201134C(ctx);

    if (count != 0)
    {
        for (i = 0; i < count; i++)
        {
            sub_021FF924(sub_021F8694(), sprites[i], a, b, c, d, e);
        }
    }

    return work->unk23C;
}

u32 sub_021FAFBC(ScriptContext *ctx, BattleAnimScript *work)
{
    void *sprites[8];
    int count;
    u32 a, b, c, d, e;
    int i;

    count = sub_021FCA04(work, sub_0201134C(ctx), sprites);
    a = sub_0201134C(ctx);
    b = sub_0201134C(ctx);
    c = sub_0201134C(ctx);
    d = sub_0201134C(ctx);
    e = sub_0201134C(ctx);

    if (count != 0)
    {
        for (i = 0; i < count; i++)
        {
            sub_021FFBBC(sub_021F8694(), sprites[i], a, b, c, d, e);
        }
    }

    return work->unk23C;
}
