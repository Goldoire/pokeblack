#include "types.h"

typedef struct BattleAnimSys
{
    /* 0x000 */ u8 pad_000[0x188];
    /* 0x188 */ void *unk188;
    /* 0x18C */ u8 pad_18C[0x1A4 - 0x18C];
    /* 0x1A4 */ void *unk1A4;
    /* 0x1A8 */ u8 pad_1A8[0x1E8 - 0x1A8];
    /* 0x1E8 */ u32 unk1E8;
} BattleAnimSys;

extern BattleAnimSys *_0220AF20;

void sub_021F7A28(void *a0, u32 a1);
void sub_021F8AE8(void *a0, u32 a1);
void sub_021F97E4(void *a0);
void sub_021F9814(void *a0);
void sub_02208958(void *a0, u32 a1, u32 a2, u32 a3);

void sub_021F7BEC(void)
{
    sub_021F97E4(_0220AF20->unk188);
    _0220AF20->unk1E8 = 0;
}

void sub_021F7C0C(void)
{
    sub_021F9814(_0220AF20->unk188);
    _0220AF20->unk1E8 = 1;
}

void sub_021F7CE4(void *a0)
{
    sub_021F7A28(a0, 0x23B);
    sub_021F8AE8(a0, 0);
}

void sub_021F821C(u32 a0, u32 a1, u32 a2)
{
    sub_02208958(_0220AF20->unk1A4, a0, a1, a2);
}
