#include "ov135/worldtrade.h"

void *sub_020419E4(u32 a0);
void sub_0204A648(void *a0);
void sub_02202940(WorldTradeAdapter *a0);
void sub_020452E8(void *a0);

void sub_021F4864(u32 a0, WorldTradeWork *work)
{
    sub_0204A648(sub_020419E4(a0));
    if (work->unk_0EBC != NULL)
    {
        work->unk_0EBC(work);
        work->unk_0EBC = NULL;
    }
    if (work->unk_0EC0 != NULL)
    {
        work->unk_0EC0(work);
    }
}

void sub_021F5940(WorldTradeWork *work)
{
    sub_02202940(&work->unk_0FA0);
    sub_020452E8(work->unk_0DE0);
    sub_020452E8(work->unk_0DD0);
    sub_020452E8(work->unk_0D50[1]);
    sub_020452E8(work->unk_0D40);
    sub_020452E8(work->unk_0D4C);
}
