#include "ov135.h"

extern u32 (*const _02203CF0[])(WorldTradeWork *work);

s32 sub_021F88D8(u32 a0, u32 *a1);
void sub_020403F4(u32 a0);
void sub_021FD5F0(WorldTradeWork *work);

void sub_021FC008(u32 a0, u32 a1)
{
    u32 tmp;

    sub_021F88D8(a1, &tmp);
}

u32 sub_021FC174(WorldTradeWork *work)
{
    return _02203CF0[work->state](work);
}

void sub_021FCFC8(void)
{
    sub_020403F4(1);
    sub_020403F4(2);
}

u32 sub_021FD65C(WorldTradeWork *work)
{
    sub_021FD5F0(work);
    work->state = 1;
    return 2;
}
