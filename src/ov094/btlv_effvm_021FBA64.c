#include "types.h"

typedef struct ScriptContext ScriptContext;
typedef void (*ScrCmdFunc)(void);

typedef struct BattleAnimScript
{
    /* 0x000 */ u32 unk000;
    /* 0x004 */ u32 unk004;
    /* 0x008 */ u8 pad_008[0x1E4 - 0x008];
    /* 0x1E4 */ u32 unk1E4;
    /* 0x1E8 */ u8 pad_1E8[0x23C - 0x1E8];
    /* 0x23C */ u32 unk23C;
    /* 0x240 */ u32 unk240;
} BattleAnimScript;

u32 sub_0201134C(ScriptContext *ctx);
void sub_020113D0(ScriptContext *ctx, ScrCmdFunc fn);

void sub_020061F8(u32 player);
void sub_02006210(void);

void sub_021F9858(ScriptContext *ctx, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                  u32 a7, u32 a8);
void sub_021F9948(ScriptContext *ctx, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                  u32 a7, u32 a8, u32 a9);

// Thumb function pointers spelled as data so the low bit survives (mwcc types an
// undefined function symbol STT_NOTYPE and the verifier only sets bit 0 for
// STT_FUNC).
extern const u8 _021FC745[]; // sub_021FC744
extern const u8 _021FC9D1[]; // sub_021FC9D0

u32 sub_021FBA64(ScriptContext *ctx, BattleAnimScript *work)
{
    u32 v1, v2, v3, v4, v5, v6, v7, v8;

    v1 = sub_0201134C(ctx);
    v2 = sub_0201134C(ctx);
    v3 = sub_0201134C(ctx);
    v4 = sub_0201134C(ctx);
    v5 = sub_0201134C(ctx);
    v6 = sub_0201134C(ctx);
    v7 = sub_0201134C(ctx);
    v8 = sub_0201134C(ctx);
    sub_0201134C(ctx);

    sub_021F9858(ctx, v1, v2, v3, v5, v6, v7, v8, v4);

    return work->unk23C;
}

u32 sub_021FBAD8(ScriptContext *ctx, BattleAnimScript *work)
{
    u32 player;

    player = sub_0201134C(ctx);
    if (player == 5)
    {
        sub_02006210();
    }
    else
    {
        sub_020061F8(player);
    }

    return work->unk23C;
}

u32 sub_021FBC78(ScriptContext *ctx, BattleAnimScript *work)
{
    u32 v1, v2, v3, v4, v5, v6, v7, v8, v9;

    v1 = sub_0201134C(ctx);
    v2 = sub_0201134C(ctx);
    v3 = sub_0201134C(ctx);
    v4 = sub_0201134C(ctx);
    v5 = sub_0201134C(ctx);
    v6 = sub_0201134C(ctx);
    v7 = sub_0201134C(ctx);
    v8 = sub_0201134C(ctx);
    v9 = sub_0201134C(ctx);

    sub_021F9948(ctx, v1, v2, v3, v4, v5, v6, v7, v8, v9);

    return work->unk23C;
}

u32 sub_021FBCEC(ScriptContext *ctx, BattleAnimScript *work)
{
    work->unk240 = sub_0201134C(ctx);
    sub_020113D0(ctx, (ScrCmdFunc)_021FC745);
    work->unk23C = TRUE;
    return TRUE;
}

u32 sub_021FBD10(ScriptContext *ctx, BattleAnimScript *work)
{
    work->unk1E4 = sub_0201134C(ctx);
    sub_020113D0(ctx, (ScrCmdFunc)_021FC9D1);
    work->unk23C = TRUE;
    return TRUE;
}

u32 sub_021FBD34(ScriptContext *ctx, BattleAnimScript *work)
{
    u32 v;

    v = sub_0201134C(ctx);
    work->unk23C = v;
    return v;
}
