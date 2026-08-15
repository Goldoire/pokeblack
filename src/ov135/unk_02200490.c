#include "ov135/worldtrade.h"

void sub_021F4E98(WorldTradeWork *work, u32 a1, u32 a2);
u32 sub_020221A4(void);
void sub_0202208C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);

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
