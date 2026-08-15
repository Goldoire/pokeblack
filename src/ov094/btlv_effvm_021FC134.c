#include "types.h"

typedef struct ScriptContext
{
    /* 0x00 */ u8 pad_00[0x14];
    /* 0x14 */ const u8 *scriptPtr;
} ScriptContext;

typedef void (*ScrCmdFunc)(void);

// The effect VM keeps a 16-deep save stack of four parallel u32 arrays so that
// a nested effect script can restore the caller's state on return.
typedef struct BattleAnimScript
{
    /* 0x000 */ u32 unk000;
    /* 0x004 */ u32 unk004;
    /* 0x008 */ u8 pad_008[0x0DC - 0x008];
    /* 0x0DC */ u32 unk0DC;
    /* 0x0E0 */ u32 unk0E0;
    /* 0x0E4 */ u32 stack0E4[16];
    /* 0x124 */ u32 stack124[16];
    /* 0x164 */ u32 stack164[16];
    /* 0x1A4 */ u32 stack1A4[16];
    /* 0x1E4 */ u32 unk1E4;
    /* 0x1E8 */ void *unk1E8;
    /* 0x1EC */ u8 pad_1EC[0x23C - 0x1EC];
    /* 0x23C */ u32 unk23C;
    /* 0x240 */ u8 pad_240[0x25C - 0x240];
    /* 0x25C */ u32 unk25C;
    /* 0x260 */ int unk260;
} BattleAnimScript;

u32 sub_0201134C(ScriptContext *ctx);
void sub_020113B0(ScriptContext *ctx, const u8 *ptr);
void sub_020113C4(ScriptContext *ctx);
void sub_020113D0(ScriptContext *ctx, ScrCmdFunc fn);
void sub_020307B0(void *ptr);

void sub_021F8934(u32 a0);

extern const u8 _021FC9E5[]; // sub_021FC9E4

u32 sub_021FC134(ScriptContext *ctx, BattleAnimScript *work)
{
    work->unk25C = sub_0201134C(ctx);
    return work->unk23C;
}

u32 sub_021FC2DC(ScriptContext *ctx, BattleAnimScript *work)
{
    int idx;

    work->unk260--;
    sub_020307B0(work->unk1E8);

    idx = work->unk260;
    work->unk0DC = work->stack0E4[idx];
    work->unk0E0 = work->stack124[idx];
    work->unk1E8 = (void *)work->stack164[idx];
    work->unk004 = work->stack1A4[idx];

    sub_020113C4(ctx);

    return work->unk23C;
}

u32 sub_021FC334(ScriptContext *ctx, BattleAnimScript *work)
{
    u32 offset;

    offset = sub_0201134C(ctx);
    sub_020113B0(ctx, ctx->scriptPtr + offset);

    return work->unk23C;
}

u32 sub_021FC354(ScriptContext *ctx, BattleAnimScript *work)
{
    work->unk000 |= 0x80;
    sub_020113D0(ctx, (ScrCmdFunc)_021FC9E5);
    work->unk23C = TRUE;
    return TRUE;
}

u32 sub_021FC434(ScriptContext *ctx, BattleAnimScript *work)
{
    sub_021F8934(sub_0201134C(ctx));
    return work->unk23C;
}
