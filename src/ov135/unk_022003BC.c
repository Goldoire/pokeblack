#include "types.h"

/* Global Trade Station ("worldtrade") main work structure.  Only the offsets
 * this file touches are named; everything else is padding. */
typedef struct WorldTradeWork
{
    u8 pad_0000[0x18];
    u32 unk_0018;
    u8 pad_001C[0x28 - 0x1C];
    u32 state;
    u8 pad_002C[0xB6C - 0x2C];
    void *unk_0B6C;
    u8 pad_0B70[0xB88 - 0xB70];
    void *unk_0B88;
    void *unk_0B8C;
    u8 pad_0B90[0xBF4 - 0xB90];
    void *unk_0BF4;
    u8 pad_0BF8[0xD40 - 0xBF8];
    void *unk_0D40;
    void *unk_0D48;
    void *unk_0D50[3];
    u8 pad_0D5C[0xDD0 - 0xD5C];
    void *unk_0DD0;
    u8 pad_0DD4[0xDE0 - 0xDD4];
    void *unk_0DE0;
    u8 pad_0DE4[0xE18 - 0xDE4];
    u16 unk_0E18;
    u8 pad_0E1A[0xFA0 - 0xE1A];
    u8 unk_0FA0;
} WorldTradeWork;

void sub_02202940(void *a0);
void sub_020452E8(void *a0);
void *sub_020457B0(u32 a0, u32 a1);
void *sub_02045EC0(void *a0, u32 a1);
void sub_02045808(void *a0);
void sub_020434DC(u32 a0, u32 a1);
void sub_021F4EC0(WorldTradeWork *work, u32 a1, u32 a2);
void sub_021F4E98(WorldTradeWork *work, u32 a1, u32 a2);
void sub_021F4F90(WorldTradeWork *work);
u32 sub_020221A4(void);
void sub_0202208C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
void sub_022009A4(WorldTradeWork *work, u32 a1, u32 a2, u32 a3, u32 a4);
void sub_0204B92C(void *a0, u32 a1);

void sub_022003BC(WorldTradeWork *work)
{
    s32 i;

    sub_02202940(&work->unk_0FA0);
    sub_020452E8(work->unk_0DE0);
    sub_020452E8(work->unk_0DD0);
    sub_020452E8(work->unk_0D40);
    for (i = 0; i < 3; i++)
    {
        sub_020452E8(work->unk_0D50[i]);
    }
    sub_020452E8(work->unk_0D48);
}

void sub_0220040C(WorldTradeWork *work)
{
    work->unk_0B88 = sub_020457B0(0xB4, 0x48);
    work->unk_0B8C = sub_02045EC0(work->unk_0B6C, 0x2D);
}

void sub_02200434(WorldTradeWork *work)
{
    sub_02045808(work->unk_0B88);
    sub_02045808(work->unk_0B8C);
}

u32 sub_02200450(WorldTradeWork *work)
{
    if (work->unk_0E18 != 0)
    {
        sub_020434DC(1, 0);
        sub_020434DC(2, 0);
        sub_020434DC(4, 0);
        sub_021F4EC0(work, 7, 11);
        work->unk_0018 = 1;
        work->state = 9;
    }
    return 2;
}

u32 sub_02200490(WorldTradeWork *work)
{
    sub_021F4E98(work, 10, 2);
    return 2;
}

u32 sub_022004A0(WorldTradeWork *work)
{
    sub_0202208C(3, 1, 1, 0, 6, 1, 0x48);
    work->state = 3;
    return 2;
}

u32 sub_022004C8(WorldTradeWork *work)
{
    if (sub_020221A4() != 0)
    {
        work->state = 5;
    }
    return 2;
}

u32 sub_022004DC(WorldTradeWork *work)
{
    if (sub_020221A4() != 0)
    {
        work->state = 5;
    }
    return 2;
}

u32 sub_022004F0(WorldTradeWork *work)
{
    sub_022009A4(work, 4, 1, 0, 0xF0F);
    sub_021F4E98(work, 10, 6);
    sub_0204B92C(work->unk_0BF4, 1);
    sub_021F4F90(work);
    return 2;
}
