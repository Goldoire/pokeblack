#include "types.h"

/* Record at 0x020AA260.
 *   +0x00 u16  bitmask, one bit per 0x020AA414 slot (sub_02005BC0)
 *   +0x04 u32  cleared with +0x00/+0x08/+0x14 at the end of sub_02005B74
 *   +0x08 u32  counter, decremented when non-zero (sub_02005BC0)
 *   +0x10 void* the allocator handle from sub_020746E8 (sub_02005B24,
 *               read back by sub_02005C18)
 *   +0x14 u32
 *   +0x1C u32  1 while a transition is running (sub_02005F70 sets, F90 clears)
 *   +0x20 u32  step counter
 *   +0x24 u16 / +0x26 u16 / +0x28 u32 / +0x2C u32 / +0x30 u32
 *               sub_02005F70 loads all five, sub_02005F5C reloads +0x2C and
 *               +0x30 with 60.
 */
typedef struct Unk020AA260
{
    /* 0x00 */ u16 unk00;
    /* 0x02 */ u16 unk02;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ u32 unk08;
    /* 0x0C */ u32 unk0C;
    /* 0x10 */ void *unk10;
    /* 0x14 */ u32 unk14;
    /* 0x18 */ u32 unk18;
    /* 0x1C */ u32 unk1C;
    /* 0x20 */ u32 unk20;
    /* 0x24 */ u16 unk24;
    /* 0x26 */ u16 unk26;
    /* 0x28 */ u32 unk28;
    /* 0x2C */ u32 unk2C;
    /* 0x30 */ u32 unk30;
} Unk020AA260;

/* 16 slots of 0x1A bytes at 0x020AA414 (sub_02005BC0). */
typedef struct Unk1A
{
    u8 unk00[0x1A];
} Unk1A;

extern Unk020AA260 _020AA260;
extern Unk1A _020AA414[];
extern u8 _020AA9B4[];
extern u8 _020A7010[];
extern u8 _020AA2BC[];

void sub_020726D0(void);
void *sub_020746E8(void *start, u32 size);
void sub_02073FB8(void *a0, void *a1, void *a2, u32 a3);
void sub_02005B74(int a0);
int sub_02085D3C(void);
void sub_02005B6C(void);
void sub_02005FF4(void);
void sub_02072758(void);
void sub_020727B4(void);
void *sub_02005C3C(void);
int sub_02073108(void *a0, int a1, Unk1A *a2);
void sub_02074758(void *a0);
void sub_02072794(int a0);
u32 sub_0200590C(void);
void sub_02072F34(u32 a0, int a1);
void sub_02006368(void);
void sub_02005F90(void);

void sub_02005B24(void)
{
    void *heap;

    sub_020726D0();
    heap = sub_020746E8(_020AA9B4, 0x95AD0);
    _020AA260.unk10 = heap;
    sub_02073FB8(_020AA2BC, _020A7010, heap, 0);
    sub_02005B74(1);
    if (sub_02085D3C() == 1)
    {
        sub_02005B6C();
    }
}

void sub_02005BC0(void)
{
    void *r;
    int i;

    sub_02005FF4();
    sub_02072758();
    sub_020727B4();
    r = sub_02005C3C();
    _020AA260.unk00 = 0;
    for (i = 0; i < 16; i++)
    {
        if (sub_02073108(r, i, &_020AA414[i]) == 1)
        {
            _020AA260.unk00 |= (u16)(1 << i);
        }
    }
    if (_020AA260.unk08 != 0)
    {
        _020AA260.unk08--;
    }
}

void sub_02005C18(void)
{
    sub_02074758(_020AA260.unk10);
}

void sub_02005C28(int a0)
{
    sub_02072794(a0 != 1);
}

void sub_02005F5C(void)
{
    _020AA260.unk2C = 60;
    _020AA260.unk30 = 60;
    sub_02005F90();
}

void sub_02005F70(u32 a0, u16 a1, u32 a2, u32 a3)
{
    _020AA260.unk26 = a1;
    _020AA260.unk28 = a0;
    _020AA260.unk2C = a3;
    _020AA260.unk30 = a2;
    _020AA260.unk24 = (u16)a2;
    sub_02006368();
    _020AA260.unk20 = 0;
    _020AA260.unk1C = 1;
}

void sub_02005F90(void)
{
    _020AA260.unk1C = 0;
    _020AA260.unk26 = 0xFFFF;
    _020AA260.unk28 = 0;
    _020AA260.unk24 = 0;
    sub_02072F34(sub_0200590C(), 0x7F);
    _020AA260.unk20 = 0;
    sub_02006368();
}
