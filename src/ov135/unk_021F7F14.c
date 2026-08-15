#include <nitro.h>
#include "ov135/worldtrade.h"

extern u8 _02203C18[];
extern const u32 _0220307C[];
extern const u32 _0220301C[];
extern const u32 _02202FC4[];
extern u32 (*const _02203C1C[])(WorldTradeWork *work);

void sub_0202208C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
u32 sub_02202840(WorldTradeAdapter *a0);
void sub_021F8178(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6,
                  u32 a7, u32 a8);
void sub_02034714(void *a0, u32 a1, void *a2);
void sub_021F8554(WorldTradeSlot *a0);
void *sub_0201F81C(s32 a0, u32 a1);
void sub_0201F878(void *a0, void *a1, u32 a2, s32 a3, u32 a4);
void sub_021F50EC(WorldTradeWork *work);
void sub_021F8A3C(WorldTradeWork *work);
void sub_021F8A40(WorldTradeWork *work);
void sub_021F5074(WorldTradeWork *work);
void sub_021F4EC8(WorldTradeWork *work);
void sub_02005D90(u32 a0, u32 a1);
void sub_021F4EC0(WorldTradeWork *work, u32 a1, u32 a2);
u32 sub_02168124(void);
void sub_02168064(void);

u32 sub_021F7F14(WorldTradeWork *work)
{
    if (work->unk_0014 == 0)
    {
        sub_0202208C(0, 0, 0, 0, 6, 1, 0x48);
        work->unk_0EB4 = 1;
    }
    else
    {
        sub_0202208C(3, 0, 0, 0, 6, 1, 0x48);
    }
    work->state = 0;
    return 3;
}

u32 sub_021F7F64(WorldTradeWork *work)
{
    if (sub_02202840(&work->unk_0FA0) == 0)
    {
        work->state = work->unk_002C;
    }
    return 2;
}

u32 sub_021F7F80(u32 a0)
{
    switch (a0)
    {
    case 0:
        return 0x14C0;
    case 1:
        return 0xC80;
    }
    return 0;
}

u32 sub_021F8078(u32 a0, u32 a1)
{
    if (a0 == 1)
    {
        return sub_021F7F80(0);
    }
    if (a0 == 2)
    {
        a1 = sub_021F7F80(1);
    }
    return a1;
}

void sub_021F8154(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 a5, u32 a6,
                  u32 a7)
{
    sub_021F8178(a0, a1, a2, a3, 0, a4, a5, a6, a7);
}

void sub_021F84BC(u32 a0, u32 *a1, u32 *a2)
{
    if (a0 >= 0x1B)
    {
        sub_02034714(_02203C18, 0, _02203C18);
    }
    *a1 = _0220307C[a0];
    a0++;
    *a2 = _0220307C[a0];
}

void sub_021F8668(WorldTradeSlot *slot, WorldTradeWork *work)
{
    sub_021F8554(slot);
    slot->unk_00EC = work->unk_0B4C;
    slot->unk_00EE = work->unk_0B4E;
    slot->unk_00F0 = work->unk_0B50;
    slot->unk_00F2 = work->unk_0B52;
    slot->unk_00F4 = work->unk_0B54;
}

s32 sub_021F87E0(void **a0, void *a1, u32 a2)
{
    const u32 *tbl;
    s32 i;
    s32 count;

    if (a2 == 0)
    {
        tbl = _0220301C;
        count = 12;
    }
    else
    {
        tbl = _02202FC4;
        count = 11;
    }
    *a0 = sub_0201F81C(count, 0x48);
    for (i = 0; i < count; i++)
    {
        sub_0201F878(*a0, a1, tbl[i * 2], i, 0x48);
    }
    return count;
}

u32 sub_021F89B4(WorldTradeWork *work)
{
    sub_021F50EC(work);
    sub_021F8A3C(work);
    reg_GX_POWCNT &= ~REG_GX_POWCNT_DSEL_MASK;
    switch (work->unk_0020)
    {
    case 0x13:
    case 0x15:
        work->state = 2;
        break;
    case 0x14:
        work->state = 4;
        break;
    }
    return 1;
}

u32 sub_021F89F0(WorldTradeWork *work)
{
    u32 prev = work->state;
    u32 ret = _02203C1C[prev](work);

    if (prev != work->state)
    {
        work->unk_0F88 = 0;
        work->unk_0F8A = 0;
    }
    return ret;
}

u32 sub_021F8A18(WorldTradeWork *work)
{
    sub_021F8A40(work);
    sub_021F5074(work);
    sub_021F4EC8(work);
    if (work->unk_0010 == 0)
    {
        return 4;
    }
    return 0;
}

u32 sub_021F8A44(WorldTradeWork *work)
{
    sub_02005D90(0x486, 0xFFFF);
    work->state = 1;
    work->unk_0EB2 = 1;
    work->unk_0030 = 0;
    sub_021F4EC0(work, 1, 0);
    return 2;
}

u32 sub_021F8A74(void)
{
    sub_02168064();
    return 1;
}

void sub_021C8DA0(WorldTradeWork *work);

u32 sub_021F8AF4(WorldTradeWork *work)
{
    sub_021C8DA0(work);
    work->unk_0F8C = 0;
    return 1;
}

u32 sub_021F8A80(void)
{
    switch (sub_02168124())
    {
    case 3:
        return 1;
    case 0:
    case 4:
    case 5:
        return 2;
    }
    return 0;
}
