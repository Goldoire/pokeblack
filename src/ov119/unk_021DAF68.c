#include <nitro.h>
#include "ov119/pokemontrade.h"

typedef void (*PokemonTradeCallback)(PokemonTradeWork *work);

/* Argument block threaded through the 0x021DC8xx list-menu helpers. */
typedef struct PokemonTradeSub
{
    u8 pad_0000[0x14];
    u32 unk_0014;
    u8 pad_0018[0x30 - 0x18];
    u32 unk_0030;
} PokemonTradeSub;

void sub_0207D658(u32 addr, int plane, int brightness);
u32 sub_020399A8(void);
u32 sub_021E12AC(PokemonTradeWork *work);
u32 sub_021D8A24(PokemonTradeWork *work);
u32 sub_0203D3A8(u32 a0, u32 a1, u32 a2, const void *a3);
void sub_021D8E84(PokemonTradeWork *work, PokemonTradeCallback cb);
void sub_021D8E80(PokemonTradeWork *work);
u32 sub_021E707C(PokemonTradeWork *work);
void sub_021D94A0(PokemonTradeWork *work, s32 a1);
u32 sub_021E665C(PokemonTradeWork *work);
u32 sub_021D8AA8(PokemonTradeWork *work);
s32 sub_021DD34C(PokemonTradeWork *work, u32 a1, u32 a2);
void sub_020307B0(void *a0);
u32 sub_020076A4(void *a0);
PokemonTradeWork *sub_021DC854(void *a0, u32 a1);
u32 sub_021DC894(void *a0, u32 a1, PokemonTradeSub *a2, PokemonTradeWork *a3,
                 u32 a4);
void sub_021DCBA4(PokemonTradeSub *a0, PokemonTradeWork *a1);

s32 sub_021DB4B4(s32 a0);

void sub_021D9C00(PokemonTradeWork *work);
void sub_021DB164(PokemonTradeWork *work);
void sub_021DB290(PokemonTradeWork *work);
void sub_021DBAF8(PokemonTradeWork *work);
void sub_021DBC98(PokemonTradeWork *work);
void sub_021DBC3C(PokemonTradeWork *work);
void sub_021D4B88(PokemonTradeWork *work);
void sub_021D59B0(PokemonTradeWork *work);

void sub_020435F4(u32 a0);
u32 sub_02035C38(PokemonTradeWork *work);
void sub_0204A5AC(void);
void sub_020450C8(void);
void sub_0203F9B4(void);
void sub_021DBE70(PokemonTradeWork *work);

void sub_021DB278(PokemonTradeWork *work)
{
    sub_020435F4(0x1E);
    sub_021D8E84(work, sub_021DBE70);
}

void sub_021DB998(PokemonTradeWork *work)
{
    if (sub_02035C38(work) == 0)
    {
        sub_021D8E84(work, sub_021DBE70);
    }
}

void sub_021DC484(void)
{
    sub_0204A5AC();
    sub_020450C8();
    sub_0203F9B4();
}

void sub_021DAF68(PokemonTradeWork *work)
{
    u32 netId = sub_020399A8();
    u8 buf;

    if (sub_021E12AC(work) != 0)
    {
        if (sub_021D8A24(work) != 0)
        {
            buf = 2;
            if (sub_0203D3A8(netId, 0xC0F, 1, &buf) != 0)
            {
                sub_021D8E84(work, sub_021D9C00);
            }
        }
        else
        {
            sub_021D8E84(work, sub_021D9C00);
        }
    }
}

void sub_021DB198(PokemonTradeWork *work)
{
    sub_0207D658((u32)&reg_G2S_DB_BLDCNT,
                 GX_BLEND_PLANEMASK_BG0 | GX_BLEND_PLANEMASK_BG1 |
                     GX_BLEND_PLANEMASK_BG3 | GX_BLEND_PLANEMASK_OBJ,
                 -8);
    sub_021D8E84(work, sub_021DB164);
}

void sub_021DB2E8(PokemonTradeWork *work)
{
    if (sub_021E707C(work) == 0)
    {
        sub_021D8E84(work, sub_021DB290);
    }
}

u32 sub_021DB4EC(PokemonTradeWork *work, s32 a1)
{
    s32 x = sub_021DB4B4(a1);
    s32 y = work->unk_107C;

    if (y < x && y + 0xE0 > x)
    {
        return 1;
    }
    x += work->unk_063C;
    if (y < x && y + 0xE0 > x)
    {
        return 1;
    }
    return 0;
}

void sub_021DBA38(PokemonTradeWork *work)
{
    if (sub_021D8A24(work) == 0)
    {
        sub_021D94A0(work, 1);
        sub_021D8E80(work);
        sub_021D8E84(work, sub_021DBAF8);
        return;
    }
    if (sub_0203D3A8(sub_020399A8(), 0xC06, 0, NULL) != 0)
    {
        sub_021D8E84(work, sub_021DBAF8);
    }
}

void sub_021DBD3C(PokemonTradeWork *work)
{
    if (sub_021E665C(work) != 0)
    {
        if (sub_021D8A24(work) != 0)
        {
            sub_021D8E84(work, sub_021DBC98);
        }
        else
        {
            sub_021D8E84(work, sub_021DBC3C);
        }
    }
}

u32 sub_021DBD70(PokemonTradeWork *work, u32 a1, u32 a2)
{
    if (sub_021D8AA8(work) == 0)
    {
        if (work->unk_0F84 == a2 && work->unk_0F88 == a1)
        {
            return 1;
        }
    }
    else
    {
        if (sub_021DD34C(work, a1, a2) != -1)
        {
            return 1;
        }
    }
    return 0;
}

void sub_021DC5D0(PokemonTradeWork *work)
{
    u32 i;

    for (i = 0; i < 3; i++)
    {
        sub_020307B0(work->unk_1064[i]);
    }
}

void sub_021DC5F0(PokemonTradeWork *work)
{
    u32 n = sub_020076A4(work->unk_0828);

    work->unk_0634 = n * 6 + 2;
    work->unk_0630 = n;
    work->unk_0638 = n * 0x14 + 0xC;
    work->unk_063C = n * 0xA0 + 0x60;
}

u32 sub_021DCA84(void *a0, u32 a1, PokemonTradeSub *a2)
{
    return sub_021DC894(a0, a1, a2, sub_021DC854(a0, 0xC6000), 2);
}

u32 sub_021DCAAC(void *a0, u32 a1, PokemonTradeSub *a2)
{
    return sub_021DC894(a0, a1, a2, sub_021DC854(a0, 0xC6000), 0);
}

u32 sub_021DCC38(void *a0, u32 a1, PokemonTradeSub *a2)
{
    PokemonTradeWork *work = sub_021DC854(a0, 0xC6000);
    u32 ret;

    a2->unk_0014 = a2->unk_0030;
    ret = sub_021DC894(a0, a1, a2, work, 4);
    sub_021DCBA4(a2, work);
    sub_021D8E84(work, sub_021D4B88);
    return ret;
}

u32 sub_021DCC78(void *a0, u32 a1, PokemonTradeSub *a2)
{
    PokemonTradeWork *work = sub_021DC854(a0, 0x96000);
    u32 ret;

    a2->unk_0014 = a2->unk_0030;
    ret = sub_021DC894(a0, a1, a2, work, 7);
    sub_021DCBA4(a2, work);
    sub_021D8E84(work, sub_021D59B0);
    return ret;
}
