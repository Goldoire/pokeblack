#include "ov119.h"

void sub_021B65B4(void *a0, u32 a1);
void sub_021B6558(void *a0, u32 a1, u32 a2);
void sub_021B6548(void *a0, u32 a1, u32 a2);
void *sub_02008FEC(void *a0);
s32 sub_02009020(void *a0, u32 a1);
s32 sub_020173EC(const u8 *a0);
u32 sub_0203CD98(s32 a0);
u32 sub_021D9038(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
void sub_021D90E8(u8 a0, u32 a1, void *a2, u32 a3, u32 a4);
u32 sub_020399A8(u32 a0);

void sub_0203D7B0(u32 a0);
void sub_0203D7BC(u32 a0);
void sub_0203C554(u32 a0);

void sub_021D89CC(PokemonTradeWork *work)
{
    sub_0203D7B0(0);
    sub_0203D7BC(0);
    sub_0203C554(0);
    work->unk_0008[2] = 3;
}

void sub_021D8980(PokemonTradeWork *work)
{
    sub_021B65B4(work->unk_09C0, 1);
    sub_021B6558(work->unk_09C0, 1, 1);
    sub_021B6548(work->unk_09C0, 1, 1);
}

u32 sub_021D89A8(PokemonTradeWork *work)
{
    void *p = sub_02008FEC(work->unk_082C);
    u32 ret = 0;

    if (sub_02009020(p, 0) == -1)
    {
        ret = 1;
    }
    return ret;
}

u32 sub_021D89EC(const u8 *a0)
{
    s32 n = sub_020173EC(a0);
    s32 i;

    if (a0 == NULL)
    {
        return 0;
    }
    for (i = 0; i < n; i++)
    {
        if (a0[i] != 0)
        {
            return 1;
        }
    }
    return 0;
}

u8 sub_021D8A18(PokemonTradeWork *work)
{
    return work->unk_11F2;
}

u32 sub_021D8A24(PokemonTradeWork *work)
{
    s32 idx;

    if (work->unk_0008 == 0)
    {
        return 0;
    }
    idx = work->unk_118C;
    if (idx >= 4)
    {
        return 0;
    }
    if (sub_0203CD98(idx) != 0)
    {
        return 1;
    }
    return 0;
}

u32 sub_021D8AF4(s32 a0, PokemonTradeWork *work)
{
    if (a0 >= 2)
    {
        return (a0 - 2) / 6;
    }
    return work->unk_0630;
}

s32 sub_021D8B0C(s32 a0, s32 a1)
{
    if (a0 >= 2)
    {
        return (a0 - 2) % 6 + a1 * 6;
    }
    if (a1 < 3)
    {
        return a0 + a1 * 2;
    }
    return -1;
}

void sub_021D90AC(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    sub_021D9038(a0, a1, a2, a3, a4, 0);
}

void sub_021D90C0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    sub_021D9038(a0, a1, a2, a3, a4, 1);
}

void sub_021D90D4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    sub_021D9038(a0, a1, a2, a3, a4, 2);
}

void sub_021D9124(void *a0, u32 a1, const u8 *a2, u32 a3, u32 a4)
{
    sub_021D90E8(*a2, 0, a0, a3, a4);
}

void sub_021D913C(void *a0, u32 a1, const u8 *a2, u32 a3, u32 a4)
{
    sub_021D90E8(*a2, 1, a0, a3, a4);
}

void sub_021D9154(void *a0, u32 a1, const u8 *a2, u32 a3, u32 a4)
{
    sub_021D90E8(*a2, 2, a0, a3, a4);
}

void sub_021D916C(u32 a0, u32 a1, const u8 *a2, PokemonTradeWork *work, u32 a4)
{
    if (a4 == sub_020399A8(a0))
    {
        work->unk_05E4[a0] = *a2;
    }
}

void sub_021D92DC(u32 a0, u32 a1, const u8 *a2, PokemonTradeWork *work, u32 a4)
{
    if (a4 == sub_020399A8(a0))
    {
        work->unk_11E0[a0] = *a2;
    }
}
