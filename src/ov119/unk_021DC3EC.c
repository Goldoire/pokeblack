#include "ov119/pokemontrade.h"

typedef void (*PokemonTradeCallback)(PokemonTradeWork *work);

typedef struct PokemonTradePair
{
    u32 unk_00;
    u32 unk_04;
} PokemonTradePair;

/* Argument block threaded through the 0x021DC8xx list-menu helpers. */
typedef struct PokemonTradeSub
{
    u8 pad_0000[0x14];
    u32 unk_0014;
    u8 pad_0018[0x30 - 0x18];
    u32 unk_0030;
} PokemonTradeSub;

extern const PokemonTradePair _021E76F4;

void sub_021E55BC(PokemonTradeWork *work);
void *sub_02014B08(u32 a0, u16 a1);
void sub_02016020(void *a0, u32 a1);
void sub_02015BF0(void *a0);
void sub_02005E9C(void);
void sub_02005DE4(u32 a0);
void sub_02005DF8(u32 a0);
PokemonTradeWork *sub_021DC854(void *a0, u32 a1);
u32 sub_021DC894(void *a0, u32 a1, PokemonTradeSub *a2, PokemonTradeWork *a3,
                 u32 a4);
void sub_021DCBA4(PokemonTradeSub *a0, PokemonTradeWork *a1);
void sub_021D8E84(PokemonTradeWork *work, PokemonTradeCallback cb);
u32 sub_021D8A24(PokemonTradeWork *work);
u32 sub_02039C68(u32 a0, u32 a1, u32 a2);
u32 sub_021D8ADC(PokemonTradeWork *work, u8 a1);
void sub_020307B0(void *a0);
s32 sub_0201293C(void *a0);
s32 sub_021DD21C(PokemonTradeWork *work);
void sub_021E2A1C(PokemonTradeWork *work, u32 a1, u32 a2);
void *sub_02012934(void *a0);
s32 sub_0201AA18(void *a0);
s32 sub_02007984(s32 a0);
void sub_021E1410(PokemonTradeWork *work, const PokemonTradePair *a1, u32 a2);
void sub_021B6558(void *a0, u32 a1, u32 a2);

void sub_021D6F2C(PokemonTradeWork *work);
void sub_021D4AB4(PokemonTradeWork *work);
void sub_021DDA50(PokemonTradeWork *work);

void sub_021DC3EC(PokemonTradeWork *work)
{
    sub_021E55BC(work);
    work->unk_0840 = sub_02014B08(4, (u16)((work->unk_05F4 & 0x7FFF) | 0x8000));
    sub_02016020(work->unk_0840, 3 << 16);
    sub_02015BF0(work->unk_0840);
}

void sub_021DC818(PokemonTradeWork *work)
{
    switch (work->unk_11F8)
    {
    case 0:
        break;
    case 2:
        sub_02005E9C();
        sub_02005DE4(0);
        /* fall through */
    case 1:
        sub_02005E9C();
        sub_02005DE4(0);
        sub_02005DF8(0x1E);
        break;
    }
    work->unk_11F8 = 0;
}

u32 sub_021DCCB8(void *a0, u32 a1, PokemonTradeSub *a2)
{
    PokemonTradeWork *work = sub_021DC854(a0, 0x96000);
    u32 ret;

    a2->unk_0014 = a2->unk_0030;
    ret = sub_021DC894(a0, a1, a2, work, 8);
    sub_021DCBA4(a2, work);
    sub_021D8E84(work, sub_021D6F2C);
    return ret;
}

u32 sub_021DCCF8(void *a0, u32 a1, PokemonTradeSub *a2)
{
    PokemonTradeWork *work = sub_021DC854(a0, 0x96000);
    u32 ret;

    a2->unk_0014 = a2->unk_0030;
    ret = sub_021DC894(a0, a1, a2, work, 6);
    sub_021DCBA4(a2, work);
    sub_021D8E84(work, sub_021D4AB4);
    return ret;
}

void sub_021DD080(u32 a0, u32 a1, PokemonTradeWork *work)
{
    if (sub_021D8A24(work) != 0)
    {
        sub_02039C68(a0, a1, 8);
    }
}

u32 sub_021DD140(PokemonTradeWork *work)
{
    if (work->unk_11F1 != 0)
    {
        if (sub_021D8ADC(work, work->unk_11F1) != 0)
        {
            work->unk_11F1 = (u8)(work->unk_11F1 - 1);
        }
        else
        {
            work->unk_11F1 = 0;
        }
    }
    if (work->unk_11F1 == 0)
    {
        return 1;
    }
    return 0;
}

void sub_021DD174(PokemonTradeWork *work)
{
    s32 i;
    s32 j;

    for (j = 0; j < 2; j++)
    {
        for (i = 0; i < 3; i++)
        {
            if (work->unk_0FD8[j][i] != NULL)
            {
                sub_020307B0(work->unk_0FD8[j][i]);
                work->unk_0FD8[j][i] = NULL;
            }
        }
    }
}

/* The two extra arguments have to be forwarded to the callee: only then are r1
 * and r2 live across the field load, which is what pushes the 0x118C offset
 * temp into r3.  Dropping them (or declaring sub_021E2A1C with one parameter)
 * frees r1 and mwcc loads the offset there instead -- 17/20. */
void sub_021DD294(PokemonTradeWork *work, u32 a1, u32 a2)
{
    if (work->unk_118C == 3)
    {
        sub_021E2A1C(work, a1, a2);
    }
}

u32 sub_021DD2A8(PokemonTradeWork *work)
{
    s32 a = sub_0201293C(work->unk_082C);
    s32 n = sub_021DD21C(work);
    s32 total = sub_0201AA18(sub_02012934(work->unk_082C)) + sub_02007984(a);

    if (total == 2 && n >= 1)
    {
        return 1;
    }
    if (total > 2 && n >= 2)
    {
        return 1;
    }
    return 0;
}

void sub_021DD4F4(PokemonTradeWork *work, s32 a1, s32 a2)
{
    work->unk_0FA4[a1][a2] = -1;
    work->unk_0FBC[a1][a2] = -1;
    if (work->unk_0FD8[a1][a2] != NULL)
    {
        sub_020307B0(work->unk_0FD8[a1][a2]);
    }
    work->unk_0FD8[a1][a2] = NULL;
}

void sub_021DDAD4(PokemonTradeWork *work)
{
    PokemonTradePair tmp;

    tmp = _021E76F4;
    sub_021E1410(work, &tmp, 2);
    sub_021B6558(work->unk_09C0, 1, 0);
    sub_021D8E84(work, sub_021DDA50);
}
