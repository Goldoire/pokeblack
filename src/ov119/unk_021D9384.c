#include "ov119/pokemontrade.h"

typedef void (*PokemonTradeCallback)(PokemonTradeWork *work);

u32 sub_020399A8(void);
u32 sub_02039338(void);
void sub_021DF8A0(PokemonTradeWork *work, u8 a1, u32 a2);
u32 sub_020221A4(void);
void sub_021D8E84(PokemonTradeWork *work, PokemonTradeCallback cb);
void sub_0202208C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
void sub_021E36D8(void *a0, s32 a1);
u32 sub_021D8AA8(void *a0);
void sub_021E36A8(void *a0, s32 a1, s32 a2, s32 a3, u32 a4, u32 a5);
void sub_021E1B14(void *a0, s32 a1, s32 a2);
void sub_021E2438(void *a0, s32 a1);
void sub_021E62D4(void *a0, s32 a1, s32 a2);
s32 sub_02017E1C(void *a0, u32 a1, u32 a2);
void *sub_021D8FA4(void *a0, u32 a1);
u32 sub_021D8A24(PokemonTradeWork *work);
u32 sub_02039CB4(u32 a0, u32 a1, u32 a2);
u32 sub_02039C68(u32 a0, u32 a1, u32 a2);
void sub_021E1098(PokemonTradeWork *work);
u32 sub_021E12AC(PokemonTradeWork *work);

void sub_021D9384(u32 a0, u32 a1, const void *a2, PokemonTradeWork *work,
                  u32 a4)
{
    if (a4 == sub_020399A8())
    {
        if (a0 != sub_02039338())
        {
            work->unk_107E = *(const s16 *)a2;
        }
    }
}

void sub_021D93AC(u32 a0, u32 a1, const u8 *a2, PokemonTradeWork *work, u32 a4)
{
    if (a4 == sub_020399A8())
    {
        if (a0 != sub_02039338())
        {
            sub_021DF8A0(work, *a2, 1);
        }
    }
}

void sub_021D93E0(u32 a0, u32 a1, const u8 *a2, PokemonTradeWork *work, u32 a4)
{
    if (a4 == sub_020399A8())
    {
        if (a0 != sub_02039338())
        {
            work->unk_0FA0 = *a2;
        }
    }
}

void sub_021D941C(PokemonTradeWork *work)
{
    if (sub_020221A4() != 0)
    {
        sub_021D8E84(work, NULL);
    }
}

void sub_021D9434(PokemonTradeWork *work)
{
    sub_0202208C(0, 0, 0, 0, 6, 1, work->unk_05F4);
    sub_021D8E84(work, sub_021D941C);
}

void sub_021D9468(void *a0, s32 a1, s32 a2)
{
    if (a2 != 0)
    {
        sub_021E36D8(a0, a1);
        sub_021E36A8(a0, a1, 1 - a1, a2, 1, sub_021D8AA8(a0));
        sub_021E1B14(a0, a1, a2);
    }
}

void sub_021D94A0(void *a0, s32 a1)
{
    s32 i;

    if (sub_021D8AA8(a0) == 0)
    {
        sub_021E36D8(a0, a1);
        sub_021E2438(a0, a1);
        return;
    }
    for (i = 0; i < 3; i++)
    {
        sub_021E62D4(a0, a1, i);
    }
}

u32 sub_021D95A0(void *a0)
{
    u32 ret = 0;

    if (sub_02017E1C(a0, 3, 0) == 1)
    {
        return 1;
    }
    if (sub_02017E1C(a0, 5, 0) > 0x28B)
    {
        ret = 1;
    }
    return ret;
}

u32 sub_021D95D0(void *a0)
{
    u32 which = 0;

    if (sub_021D8AA8(a0) != 0)
    {
        which = 1;
    }
    return sub_021D95A0(sub_021D8FA4(a0, which));
}

u32 sub_021D95F0(void *a0)
{
    u32 which = 1;

    if (sub_021D8AA8(a0) != 0)
    {
        which = 0;
    }
    return sub_021D95A0(sub_021D8FA4(a0, which));
}

void sub_021D9B84(PokemonTradeWork *work)
{
    if (sub_021D8A24(work) != 0)
    {
        if (sub_02039CB4(sub_020399A8(), 0x14, 8) != 0)
        {
            sub_021E1098(work);
            sub_021D8E84(work, sub_021D9434);
        }
    }
    else
    {
        sub_021E1098(work);
        sub_021D8E84(work, sub_021D9434);
    }
}

void sub_021D9BC4(PokemonTradeWork *work)
{
    if (sub_021E12AC(work) != 0 && work->unk_0F2C > 0x1E)
    {
        if (sub_021D8A24(work) != 0)
        {
            sub_02039C68(sub_020399A8(), 0x14, 8);
        }
        sub_021D8E84(work, sub_021D9B84);
    }
}
