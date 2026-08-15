#include "types.h"

typedef struct ScriptContext ScriptContext;

typedef struct BattleAnimScript
{
    /* 0x000 */ u32 unk000;
    /* 0x004 */ u32 unk004;
    /* 0x008 */ u8 pad_008[0x0CC - 0x008];
    /* 0x0CC */ void *unk0CC[(0x238 - 0x0CC) / 4];
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

typedef struct AnimPoint16
{
    u16 x;
    u16 y;
} AnimPoint16;

u32 sub_0201134C(ScriptContext *ctx);
int sub_0206DF3C(const AnimVec3 *pWorld, int *px, int *py); // NNS_G3dWorldPosToScrPos

void *sub_021F8694(void);
void *sub_021F86F0(void);
u32 sub_021FCF2C(ScriptContext *ctx, u32 a1);
void sub_021FF3F4(void *sys, AnimVec3 *pos, u32 a2);
void *sub_02201AF8(void *sys, int a1, u32 a2, s16 a3, s16 a4, u32 a5, u32 a6);
void sub_02201CA4(void *sys, void *obj);
void sub_02201CD0(void *sys, void *obj, u32 a2, AnimPoint16 *pt, u32 a4, u32 a5, u32 a6);
void sub_02201D5C(void *sys, void *obj, u32 a2, AnimVec3 *pos, u32 a4, u32 a5, u32 a6);
void sub_02201DA0(void *sys, void *obj, u32 a2);
void sub_02201DB4(void *sys, void *obj, u8 a2, u8 a3, s8 a4, u16 a5);

u32 sub_021FB6F4(ScriptContext *ctx, BattleAnimScript *work)
{
    AnimVec3 pos;
    int sx;
    int sy;
    u32 idx, a, b, c, d, e, f;

    idx = sub_0201134C(ctx);
    a = sub_0201134C(ctx);
    b = sub_021FCF2C(ctx, sub_0201134C(ctx));
    c = sub_0201134C(ctx);
    d = sub_0201134C(ctx);
    e = sub_0201134C(ctx);
    f = sub_0201134C(ctx);

    sub_021FF3F4(sub_021F8694(), &pos, b);
    pos.x += c;
    pos.y += d;
    sub_0206DF3C(&pos, &sx, &sy);

    work->unk0CC[idx] = sub_02201AF8(sub_021F86F0(), 0x5F, a, (s16)sx, (s16)sy, e, f);

    return work->unk23C;
}

u32 sub_021FB790(ScriptContext *ctx, BattleAnimScript *work)
{
    AnimPoint16 pt;
    u32 idx, a, d, e, f;

    idx = sub_0201134C(ctx);
    a = sub_0201134C(ctx);
    pt.x = (u16)sub_0201134C(ctx);
    pt.y = (u16)sub_0201134C(ctx);
    d = sub_0201134C(ctx);
    e = sub_0201134C(ctx);
    f = sub_0201134C(ctx);

    sub_02201CD0(sub_021F86F0(), work->unk0CC[idx], a, &pt, d, e, f);

    return work->unk23C;
}

u32 sub_021FB7F8(ScriptContext *ctx, BattleAnimScript *work)
{
    AnimVec3 v;
    u32 idx, a, d, e, f;

    idx = sub_0201134C(ctx);
    a = sub_0201134C(ctx);
    v.x = sub_0201134C(ctx);
    v.y = sub_0201134C(ctx);
    v.z = 0x1000;
    d = sub_0201134C(ctx);
    e = sub_0201134C(ctx);
    f = sub_0201134C(ctx);

    sub_02201D5C(sub_021F86F0(), work->unk0CC[idx], a, &v, d, e, f);

    return work->unk23C;
}

u32 sub_021FB864(ScriptContext *ctx, BattleAnimScript *work)
{
    u32 idx, a;

    idx = sub_0201134C(ctx);
    a = sub_0201134C(ctx);

    sub_02201DA0(sub_021F86F0(), work->unk0CC[idx], a);

    return work->unk23C;
}

u32 sub_021FB894(ScriptContext *ctx, BattleAnimScript *work)
{
    u32 idx, a, b, c, d;

    idx = sub_0201134C(ctx);
    a = sub_0201134C(ctx);
    b = sub_0201134C(ctx);
    c = sub_0201134C(ctx);
    d = sub_0201134C(ctx);

    sub_02201DB4(sub_021F86F0(), work->unk0CC[idx], (u8)a, (u8)b, (s8)c, (u16)d);

    return work->unk23C;
}

u32 sub_021FB8F4(ScriptContext *ctx, BattleAnimScript *work)
{
    u32 idx;

    idx = sub_0201134C(ctx);

    sub_02201CA4(sub_021F86F0(), work->unk0CC[idx]);
    work->unk0CC[idx] = (void *)-1;

    return work->unk23C;
}
