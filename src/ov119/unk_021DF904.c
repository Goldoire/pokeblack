#include "ov119/pokemontrade.h"

extern u8 _021E792C[];

u32 sub_021D8AA8(PokemonTradeWork *work);
void sub_021E57FC(PokemonTradeWork *work);
void sub_02015E04(void *a0);
void sub_020307B0(void *a0);
void sub_02005E9C(void);
u32 sub_02035C08(void *a0);
void sub_021E35A0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
u32 sub_0209C0A4(u32 a0, u32 a1);
void sub_0204B3B4(void *a0);
void sub_0207D63C(u32 addr, int plane1, int plane2, int ev1, int ev2);
void sub_021E7160(u32 a0, u32 a1, u32 a2, u32 a3);
void *sub_020056BC(void);
void sub_02030DA8(void *a0, void (*a1)(void *, u32), void *a2, u32 a3);
void sub_02043534(u32 a0);
void sub_02030EAC(void *a0);

void sub_021E7220(void *a0, u32 a1);
void sub_021E7234(void *a0, u32 a1);

void sub_021DF904(PokemonTradeWork *work)
{
    if (sub_021D8AA8(work) != 0)
    {
        sub_021E57FC(work);
    }
}

void sub_021DFD0C(PokemonTradeWork *work)
{
    sub_02015E04(work->unk_0844);
    work->unk_0854 = 1;
}

void sub_021DFD24(void *a0)
{
    if (a0 != NULL)
    {
        sub_020307B0(a0);
    }
}

void sub_021DFD30(PokemonTradeWork *work, s32 a1)
{
    work->unk_0F2C = a1;
}

void sub_021DFD64(PokemonTradeWork *work)
{
    sub_02005E9C();
    work->unk_11F8 = (u8)(work->unk_11F8 - 1);
}

u32 sub_021E2A80(void)
{
    if (sub_02035C08(_021E792C) == 0)
    {
        return 1;
    }
    return 0;
}

void sub_021E36C8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    sub_021E35A0(a0, a1, a2, a3, a4);
}

u32 sub_021E5158(u32 a0)
{
    return a0 % 12;
}

void sub_021E66E8(PokemonTradeWork *work)
{
    if (work->unk_0F20 != NULL)
    {
        sub_0204B3B4(work->unk_0F20);
        work->unk_0F20 = NULL;
    }
}

void sub_021E6700(void)
{
    sub_0207D63C(0x04001050, 0, 0xF, 8, 8);
}

void sub_021E71E0(u32 a0, u32 a1)
{
    sub_021E7160(a0, a1, 3, 0xFFFE);
}

void sub_021E71F0(u32 a0, void *a1)
{
    sub_02030DA8(sub_020056BC(), sub_021E7220, a1, 10);
}

void sub_021E7208(u32 a0, void *a1)
{
    sub_02030DA8(sub_020056BC(), sub_021E7234, a1, 10);
}

void sub_021E7220(void *a0, u32 a1)
{
    sub_02043534(a1);
    sub_02030EAC(a0);
}
