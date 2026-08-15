#include "ov135/worldtrade.h"

void sub_021F4EC0(WorldTradeWork *work, u32 a1, u32 a2);
void *sub_020120F4(void *a0);
void sub_02012DAC(void *a0);
u32 sub_020173EC(const void *a0);
void sub_02082D44(const void *src, void *dst, u32 size);

u32 sub_02201A34(WorldTradeWork *work)
{
    sub_021F4EC0(work, 1, 0);
    work->state = 0x28;
    return 2;
}

u32 sub_02201DC0(WorldTradeWork *work)
{
    work->unk_0032 = 1;
    sub_021F4EC0(work, 9, 7);
    work->state = 0x28;
    return 2;
}

u32 sub_02201DD8(WorldTradeWork *work)
{
    work->unk_0032 = 0;
    sub_021F4EC0(work, 9, 8);
    work->state = 0x28;
    return 2;
}

u32 sub_02201DF0(WorldTradeWork *work)
{
    sub_021F4EC0(work, 9, 9);
    work->state = 0x28;
    return 2;
}

u32 sub_02201E04(WorldTradeWork *work)
{
    work->unk_0032 = 0;
    sub_021F4EC0(work, 9, 0xA);
    work->state = 0x22;
    return 2;
}

u32 sub_022020E0(WorldTradeWork *work)
{
    sub_02012DAC(sub_020120F4(work->unk_0000[0x10]));
    work->state = 0x27;
    return 2;
}

void sub_0220262C(const void *a0, void *a1)
{
    sub_02082D44(a0, a1, sub_020173EC(a0));
}
