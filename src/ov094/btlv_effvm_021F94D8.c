#include "types.h"

typedef struct BattleAnimScript
{
    /* 0x000 */ u32 unk000;
    /* 0x004 */ u8 pad_004[0x23C - 0x004];
    /* 0x23C */ u32 unk23C;
    /* 0x240 */ u8 pad_240[0x26C - 0x240];
    /* 0x26C */ int unk26C[6];
    /* 0x284 */ u32 unk284;
    /* 0x288 */ u32 unk288;
    /* 0x28C */ u8 pad_28C[0x294 - 0x28C];
    /* 0x294 */ u32 unk294;
    /* 0x298 */ u8 pad_298[0x2A4 - 0x298];
    /* 0x2A4 */ u32 unk2A4;
    /* 0x2A8 */ u32 unk2A8;
} BattleAnimScript;

typedef struct ScriptContext ScriptContext;

void sub_02006BB4(int a0);
void sub_02011264(void *task);
BattleAnimScript *sub_02011324(void *task);
void sub_020307B0(void *ptr);

void *sub_021F8684(void);
void sub_021F70F0(void *a0, u32 *a1, u32 *a2);
void sub_021F97E4(void *a0);

void sub_021F94D8(void *task)
{
    BattleAnimScript *work;

    work = sub_02011324(task);
    sub_021F97E4(task);
    sub_020307B0(work);
    sub_02011264(task);
}

void sub_021F9814(void *task)
{
    BattleAnimScript *work;

    work = sub_02011324(task);
    work->unk000 &= ~0x80;
}

void sub_021F9A7C(void *task)
{
    BattleAnimScript *work;
    int i;

    work = sub_02011324(task);
    for (i = 0; i < 6; i++)
    {
        if (work->unk26C[i] != -1)
        {
            sub_02006BB4(work->unk26C[i]);
        }
    }
}

void sub_021F9AA4(void *task)
{
    BattleAnimScript *work;

    work = sub_02011324(task);
    work->unk2A4 = 0;
    work->unk2A8 = 0;
}

u32 sub_021FA108(ScriptContext *ctx, BattleAnimScript *work)
{
    work->unk284 = 1;
    sub_021F70F0(sub_021F8684(), &work->unk288, &work->unk294);
    return work->unk23C;
}
