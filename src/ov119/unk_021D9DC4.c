#include <nitro.h>
#include "ov119.h"

typedef void (*PokemonTradeCallback)(PokemonTradeWork *work);

typedef struct PokemonTradePair
{
    u32 unk_00;
    u32 unk_04;
} PokemonTradePair;

extern const PokemonTradePair _021E7584;

void sub_0207D658(u32 addr, int plane, int brightness);
u32 sub_021DB0A0(PokemonTradeWork *work);
void sub_021E1410(PokemonTradeWork *work, const PokemonTradePair *a1, u32 a2);
void sub_021D8E84(PokemonTradeWork *work, PokemonTradeCallback cb);
u32 sub_020399A8(void);
u32 sub_0203D3A8(u32 a0, u32 a1, u32 a2, const void *a3);
u32 sub_021DD5B4(PokemonTradeWork *work, u32 a1, u32 a2);
u32 sub_021D8A24(PokemonTradeWork *work);
u32 sub_02039CB4(u32 a0, u32 a1, u32 a2);
u32 sub_02039C68(u32 a0, u32 a1, u32 a2);
u32 sub_021E12AC(PokemonTradeWork *work);
u32 sub_020221A4(void);
void sub_021E1098(PokemonTradeWork *work);
void sub_0202208C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
void sub_021E31FC(PokemonTradeWork *work);
void sub_021DC62C(PokemonTradeWork *work, s32 a1);
u32 sub_021E3E00(PokemonTradeWork *work, s32 a1);
void sub_021E5098(PokemonTradeWork *work, s32 a1);
void sub_021E4E64(void *a0, PokemonTradeWork *work, u32 a2);

void sub_021D9D60(PokemonTradeWork *work);
void sub_021D9DC4(PokemonTradeWork *work);
void sub_021DBBD0(PokemonTradeWork *work);
void sub_021DF5D8(PokemonTradeWork *work);
void sub_021DA700(PokemonTradeWork *work);
void sub_021DA8F8(PokemonTradeWork *work);
void sub_021DA9F0(PokemonTradeWork *work);
void sub_021DAA18(PokemonTradeWork *work);
void sub_021DAA7C(PokemonTradeWork *work);
void sub_021DAAE4(PokemonTradeWork *work);
void sub_021DAB34(PokemonTradeWork *work);
void sub_021DABE8(PokemonTradeWork *work);
void sub_021DA798(PokemonTradeWork *work);
void sub_021DAE2C(PokemonTradeWork *work);

void sub_021D9DC4(PokemonTradeWork *work)
{
    PokemonTradePair tmp;

    if (sub_021DB0A0(work) != 0)
    {
        tmp = _021E7584;
        sub_021E1410(work, &tmp, 2);
        sub_0207D658((u32)&reg_G2S_DB_BLDCNT,
                     GX_BLEND_PLANEMASK_BG0 | GX_BLEND_PLANEMASK_BG1 |
                         GX_BLEND_PLANEMASK_BG3 | GX_BLEND_PLANEMASK_OBJ,
                     -8);
        sub_021D8E84(work, sub_021D9D60);
    }
}

void sub_021D9E0C(PokemonTradeWork *work)
{
    u32 same = 0;

    if (work->unk_0F88 == work->unk_0630)
    {
        same = 1;
    }
    if (sub_0203D3A8(sub_020399A8(), 0xC16, 1, &same) != 0)
    {
        sub_021D8E84(work, sub_021D9DC4);
    }
}

void sub_021DA1B4(PokemonTradeWork *work)
{
    if (sub_021DD5B4(work, work->unk_0F84, work->unk_0F88) != 0)
    {
        sub_021D8E84(work, sub_021DBBD0);
    }
}

void sub_021DA254(PokemonTradeWork *work)
{
    if (sub_021DD5B4(work, work->unk_0F84, work->unk_0F88) != 0)
    {
        sub_021D8E84(work, sub_021DF5D8);
    }
}

void sub_021DA76C(PokemonTradeWork *work)
{
    if (sub_021D8A24(work) != 0)
    {
        if (sub_02039CB4(sub_020399A8(), 0xD, 8) == 0)
        {
            return;
        }
    }
    sub_021D8E84(work, sub_021DA700);
}

void sub_021DA9F0(PokemonTradeWork *work)
{
    if (sub_021E12AC(work) != 0 && sub_020221A4() != 0)
    {
        sub_021E1098(work);
        sub_021D8E84(work, sub_021DA8F8);
    }
}

void sub_021DAA18(PokemonTradeWork *work)
{
    sub_0202208C(4, 0, 0, 0, 6, 1, work->unk_05F4);
    sub_021D8E84(work, sub_021DA9F0);
}

void sub_021DAA4C(PokemonTradeWork *work)
{
    if (sub_021D8A24(work) != 0)
    {
        if (sub_02039CB4(sub_020399A8(), 0x12, 8) == 0)
        {
            return;
        }
    }
    sub_021E31FC(work);
    sub_021D8E84(work, sub_021DAA18);
}

void sub_021DAAE4(PokemonTradeWork *work)
{
    sub_021DC62C(work, work->unk_0F2C - 1);
    if (work->unk_0F2C >= 0x18)
    {
        sub_021D8E84(work, sub_021DAA7C);
    }
}

void sub_021DAB0C(PokemonTradeWork *work)
{
    if (sub_021E3E00(work, work->unk_0F2C - 1) != 0)
    {
        work->unk_0F2C = 0;
        sub_021D8E84(work, sub_021DAAE4);
    }
}

void sub_021DABB0(PokemonTradeWork *work)
{
    sub_021E5098(work, work->unk_0F2C - 1);
    if (work->unk_0F2C > 0x19)
    {
        sub_021E4E64(work->unk_0828, work, 0);
        sub_021D8E84(work, sub_021DAB34);
    }
}

void sub_021DAC20(PokemonTradeWork *work)
{
    if (sub_020221A4() != 0)
    {
        if (sub_021D8A24(work) != 0)
        {
            sub_02039C68(sub_020399A8(), 0x16, 8);
            sub_021D8E84(work, sub_021DABE8);
        }
        else
        {
            sub_021D8E84(work, sub_021DAB34);
        }
    }
}

void sub_021DAD84(PokemonTradeWork *work)
{
    if (sub_021E12AC(work) != 0)
    {
        sub_02039C68(sub_020399A8(), 0x1B, 8);
        sub_021D8E84(work, sub_021DA798);
    }
}

void sub_021DAEC8(PokemonTradeWork *work)
{
    if (sub_021E12AC(work) != 0)
    {
        sub_02039C68(sub_020399A8(), 0x19, 8);
        sub_021D8E84(work, sub_021DAE2C);
    }
}
