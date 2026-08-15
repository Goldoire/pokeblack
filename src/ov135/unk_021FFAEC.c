#include "ov135/worldtrade.h"

extern u32 (*const _02203E58[])(WorldTradeWork *work);
extern u32 (*const _02203E94[])(WorldTradeWork *work);

typedef struct WorldTradePoint
{
    u16 x;
    u16 y;
} WorldTradePoint;

void sub_0204B404(void *a0, const WorldTradePoint *a1, u32 a2);
void sub_020403F4(u32 a0);

void sub_021FFAEC(void *a0, u16 a1, u16 a2)
{
    WorldTradePoint p;

    p.x = a1;
    p.y = (u16)(a2 - 8);
    sub_0204B404(a0, &p, 1);
}

u32 sub_021FFEB4(WorldTradeWork *work)
{
    return _02203E58[work->state](work);
}

void sub_02200118(void)
{
    sub_020403F4(2);
    sub_020403F4(1);
    sub_020403F4(0);
}

u32 sub_02200C80(WorldTradeWork *work)
{
    return _02203E94[work->state](work);
}

void sub_02200DB8(void)
{
    sub_020403F4(2);
    sub_020403F4(1);
    sub_020403F4(0);
}
