#include "types.h"

/* Six-entry table of 0x1C-byte records at 0x020AA1B8, indexed by the u32 at
 * 0x020AA1B0 (= _020AA1AC + 4).
 *
 * Field evidence:
 *   +0x00 u32   sub_020057E8 zeroes it, sub_02005834 stores 1, sub_020058D0
 *               treats it as an "in use" flag.
 *   +0x04 u16   sub_020057E8 stores 0xFFFF, sub_020059A0 stores its argument,
 *               sub_020058D0 reads it and maps 0xFFFF to 0.
 *   +0x08 u32   only ever passed by address (sub_02072EA8 / sub_02072E9C).
 *   +0x0C..0x18 u32 x4, all set to -1 by sub_020057E8 and to the argument by
 *               sub_02005834; +0x14 and +0x18 are written from sub_02074894's
 *               return in sub_0200597C / sub_020059A0.
 *
 * The record at 0x020AA1AC: +0x00 u16 (sub_02005888 stores its argument and
 * passes it to sub_02072DB0), +0x04 the current index, +0x08 a `void **`
 * installed by sub_020057DC and dereferenced once before every sub_02074894.
 */
typedef struct Unk1C
{
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u16 unk04;
    /* 0x06 */ u16 unk06;
    /* 0x08 */ u32 unk08;
    /* 0x0C */ u32 unk0C;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u32 unk14;
    /* 0x18 */ u32 unk18;
} Unk1C;

typedef struct Unk020AA1AC
{
    /* 0x00 */ u16 unk00;
    /* 0x02 */ u16 unk02;
    /* 0x04 */ u32 index;
    /* 0x08 */ void **unk08;
} Unk020AA1AC;

extern Unk020AA1AC _020AA1AC;
extern Unk1C _020AA1B8[];

void sub_02072EA8(u32 *a0);
void sub_02072E9C(u32 *a0);
void sub_02072DB0(u16 a0, int a1);
u32 sub_02074894(void *a0);
void sub_020748E0(void *a0, u32 a1);

void sub_020057E8(int idx);
void sub_02005834(u32 a0);

void sub_020057DC(void **a0)
{
    _020AA1AC.unk08 = a0;
}

void sub_020057E8(int idx)
{
    _020AA1B8[idx].unk00 = 0;
    _020AA1B8[idx].unk04 = 0xFFFF;
    sub_02072EA8(&_020AA1B8[idx].unk08);
    _020AA1B8[idx].unk0C = -1;
    _020AA1B8[idx].unk10 = -1;
    _020AA1B8[idx].unk14 = -1;
    _020AA1B8[idx].unk18 = -1;
}

void sub_02005834(u32 a0)
{
    Unk1C *p = &_020AA1B8[_020AA1AC.index];

    p->unk0C = a0;
    p->unk10 = a0;
    p->unk14 = a0;
    p->unk18 = a0;
    _020AA1B8[_020AA1AC.index].unk00 = 1;
}

void sub_02005858(void)
{
    Unk1C *p = &_020AA1B8[_020AA1AC.index];

    sub_02072EA8(&p->unk08);
    sub_020748E0(*_020AA1AC.unk08, p->unk0C);
    sub_020057E8(_020AA1AC.index);
}

void sub_02005888(u16 a0)
{
    int i;

    _020AA1AC.unk00 = a0;
    _020AA1AC.index = 0;
    for (i = 0; i < 6; i++)
    {
        sub_020057E8(i);
        sub_02072E9C(&_020AA1B8[i].unk08);
    }
    sub_02072DB0(_020AA1AC.unk00, 6);
    sub_02005834(sub_02074894(*_020AA1AC.unk08));
}

u16 sub_020058D0(void)
{
    Unk1C *p = &_020AA1B8[_020AA1AC.index];
    u16 v;

    if (_020AA1B8[_020AA1AC.index].unk00 == 0)
    {
        return 0;
    }
    v = p->unk04;
    if (v == 0xFFFF)
    {
        v = 0;
    }
    return v;
}

u32 sub_02005900(void)
{
    return _020AA1AC.index;
}

void sub_0200597C(void)
{
    Unk1C *p = &_020AA1B8[_020AA1AC.index];

    p->unk14 = sub_02074894(*_020AA1AC.unk08);
}

int sub_020059A0(u16 a0)
{
    Unk1C *p = &_020AA1B8[_020AA1AC.index];

    p->unk18 = sub_02074894(*_020AA1AC.unk08);
    p->unk04 = a0;
    return 1;
}
