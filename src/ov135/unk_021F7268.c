#include <nitro.h>
#include "ov135/worldtrade.h"

extern u8 _02203B80[];
extern u32 (*const _02203BBC[])(WorldTradeWork *work);

void sub_020307B0(void *a0);
void sub_021F5074(WorldTradeWork *work);
void sub_021F4EC8(WorldTradeWork *work);
void sub_02034714(void *a0, u32 a1, void *a2);
u32 sub_020221A4(void);
void sub_021F7538(WorldTradeWork *work, u32 a1, u32 a2, u32 a3, u32 a4);
void sub_021F4E98(WorldTradeWork *work, u32 a1, u32 a2);
void sub_021F9968(void *a0, u32 a1);
void sub_021F4BE0(WorldTradeWork *work, u32 a1, u32 a2, u32 a3, u8 a4);
u32 sub_021F4D14(WorldTradeWork *work);
void sub_021F4CE4(WorldTradeWork *work);
void sub_021F4EC0(WorldTradeWork *work, u32 a1, u32 a2);
void sub_021F8668(WorldTradeSlot *a0, WorldTradeWork *work);

void sub_021F7964(WorldTradeWork *work);
void sub_021F99D0(void *a0);
void sub_021F79EC(WorldTradeWork *work);
void sub_021F76BC(void);
void sub_022000E4(WorldTradeWork *work);
void sub_0204B3DC(void *a0, u32 a1);
void sub_02202940(WorldTradeAdapter *a0);
void sub_020452E8(void *a0);

void sub_021F7840(WorldTradeWork *work)
{
    s32 i;

    sub_02202940(&work->unk_0FA0);
    sub_020452E8(work->unk_0DE0);
    for (i = 0; i < 6; i++)
    {
        sub_020452E8(work->unk_0D90[i]);
    }
    sub_020452E8(work->unk_0D40);
}

u32 sub_021F74F8(WorldTradeWork *work)
{
    sub_021F7964(work);
    sub_021F99D0(work->unk_0DE4);
    sub_021F79EC(work);
    sub_021F7840(work);
    sub_021F76BC();
    sub_022000E4(work);
    sub_0204B3DC(work->unk_0D38, 0);
    sub_021F4EC8(work);
    return 0;
}

u32 sub_021F7268(WorldTradeWork *work)
{
    if (work->unk_00D8 != NULL)
    {
        sub_020307B0(work->unk_00D8);
        work->unk_00D8 = NULL;
    }
    sub_020307B0(work->unk_0EA4);
    if (work->unk_10DC != NULL)
    {
        sub_020307B0(work->unk_10DC);
        work->unk_10DC = NULL;
    }
    work->unk_12F8 = 0;
    sub_021F5074(work);
    sub_021F4EC8(work);
    reg_G2_BLDCNT = 0;
    return 0;
}

void *sub_021F7338(WorldTradeWork *work, u32 a1)
{
    if (a1 == 9)
    {
        return (u8 *)work + 0x20C + work->unk_00D4 * 0x128;
    }
    if (a1 == 10)
    {
        return &work->unk_00E4[0];
    }
    if (a1 == 8)
    {
        return &work->unk_00E4[0];
    }
    sub_02034714(_02203B80, 0, _02203B80);
    return NULL;
}

u32 sub_021F74E4(WorldTradeWork *work)
{
    return _02203BBC[work->state](work);
}

u32 sub_021F7A18(WorldTradeWork *work)
{
    if (sub_020221A4() != 0)
    {
        sub_021F7538(work, 9, 1, 0, 0xF0F);
        sub_021F4E98(work, 0x10, 1);
    }
    return 2;
}

u32 sub_021F7A70(WorldTradeWork *work)
{
    sub_021F9968(work->unk_0DE4, 0);
    work->state = 6;
    return 2;
}

u32 sub_021F7CB4(WorldTradeWork *work)
{
    sub_021F7538(work, 0xA, 1, 0, 0xF0F);
    sub_021F4E98(work, 0x10, 8);
    return 2;
}

u32 sub_021F7CDC(WorldTradeWork *work)
{
    work->unk_00BC = 0xFFFF;
    sub_021F9968(work->unk_0DE4, 1);
    work->state = 9;
    return 2;
}

u32 sub_021F7D80(WorldTradeWork *work)
{
    sub_021F7538(work, 0xB, 1, 0, 0xF0F);
    sub_021F4E98(work, 0x10, 0xB);
    return 2;
}

u32 sub_021F7DA8(WorldTradeWork *work)
{
    sub_021F9968(work->unk_0DE4, 2);
    work->unk_00BC = 0xFFFF;
    work->state = 0xC;
    return 2;
}

u32 sub_021F7E74(WorldTradeWork *work)
{
    sub_021F7538(work, 0x17, 1, 0, 0xF0F);
    sub_021F4E98(work, 0x10, 0xE);
    return 2;
}

u32 sub_021F7E9C(WorldTradeWork *work)
{
    sub_021F4BE0(work, 0x14, 0x126, 3, 0);
    work->state = 0xF;
    return 2;
}

u32 sub_021F7EC0(WorldTradeWork *work)
{
    u32 r = sub_021F4D14(work);

    if (r == 1)
    {
        sub_021F4CE4(work);
        sub_021F4EC0(work, 7, 7);
        work->state = 2;
        work->unk_0EB4 = 1;
        sub_021F8668(&work->unk_00E4[0], work);
    }
    else if (r == 2)
    {
        sub_021F4CE4(work);
        sub_021F4EC0(work, 5, 5);
        work->state = 2;
    }
    return 2;
}
