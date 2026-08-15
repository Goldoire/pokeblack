#include "types.h"

/* 0x021467A4: the object sub_02022174 drives every frame.
 *   +0x000 u32  selector, 0/1/2 (sub_02022340)
 *   +0x004 u32  "A busy" flag, cleared by sub_02022390
 *   +0x008 u32  "B busy" flag, cleared by sub_02022390
 *   +0x00C u32 / +0x010 u32  enables for the two sub-objects (sub_020222EC)
 *   +0x014 0x30 bytes  sub-object A -- always passed alongside +0x004
 *   +0x03C u32  read after each sub_02022670 call
 *   +0x044 0x108 bytes sub-object B -- always passed alongside +0x008
 *   +0x14C u16 / +0x150 u16  written at the top of sub_020222EC; the offsets
 *          exceed the STRH immediate range, hence the 0x53 << 2 index.
 *
 * 0x021468E4 is a second object (sub_02022174 and sub_020221A4 both address
 * it as a base with a +0xC halfword and +0xE / +0xF bytes).
 */
typedef struct UnkStruct021467A4
{
    /* 0x000 */ u32 unk000;
    /* 0x004 */ u32 unk004;
    /* 0x008 */ u32 unk008;
    /* 0x00C */ u32 unk00C;
    /* 0x010 */ u32 unk010;
    /* 0x014 */ u8 unk014[0x0C];
    /* 0x020 */ u32 unk020;
    /* 0x024 */ u8 unk024[0x18];
    /* 0x03C */ u32 unk03C;
    /* 0x040 */ u32 unk040;
    /* 0x044 */ u8 unk044[0x0C];
    /* 0x050 */ u32 unk050;
    /* 0x054 */ u8 unk054[0xF8];
    /* 0x14C */ u16 unk14C;
    /* 0x14E */ u16 unk14E;
    /* 0x150 */ u16 unk150;
} UnkStruct021467A4;

typedef struct UnkStruct021468E4
{
    /* 0x00 */ u8 unk00[0xC];
    /* 0x0C */ u16 unk0C;
    /* 0x0E */ u8 unk0E;
    /* 0x0F */ u8 unk0F;
} UnkStruct021468E4;

extern UnkStruct021467A4 _021467A4;
extern UnkStruct021468E4 _021468E4;
extern u8 _02146818[];

int sub_02022340(UnkStruct021467A4 *a0, void *a1, void *a2);
void sub_020222EC(UnkStruct021467A4 *a0);
void sub_02022390(u32 *a0, void *a1);
void sub_020224DC(void *a0, int a1);
void sub_020226A0(UnkStruct021467A4 *a0);
u16 sub_02022608(UnkStruct021467A4 *a0);
void sub_02022670(void *a0);
void sub_0207D534(void *a0);
int sub_020223AC(void *a0);

void sub_02022174(void)
{
    UnkStruct021467A4 *p = &_021467A4;

    if (_021468E4.unk0C != 0)
    {
        if (sub_02022340(p, &p->unk014, &p->unk044) == 1)
        {
            sub_020222EC(p);
        }
    }
}

int sub_020221A4(void)
{
    if (_021468E4.unk0C == 0)
    {
        return 1;
    }
    return 0;
}

void sub_020221B8(void)
{
    sub_020224DC(_02146818, 0);
    sub_020224DC(_02146818, 1);
    if (_021467A4.unk004 != 0)
    {
        _021467A4.unk020 = 2;
    }
    if (_021467A4.unk008 != 0)
    {
        _021467A4.unk050 = 2;
    }
    sub_02022390(&_021467A4.unk004, &_021467A4.unk014);
    sub_02022390(&_021467A4.unk008, &_021467A4.unk044);
    _021468E4.unk0C = 0;
    _021468E4.unk0E = 0;
    _021468E4.unk0F = 0;
    sub_020226A0(&_021467A4);
}

void sub_020222CC(int a0)
{
    if (a0 == 0)
    {
        sub_0207D534((void *)0x0400006C);
        return;
    }
    sub_0207D534((void *)0x0400106C);
}

void sub_020222EC(UnkStruct021467A4 *a0)
{
    a0->unk14C = 0;
    a0->unk150 = sub_02022608(a0);
    if (a0->unk00C != 0)
    {
        sub_02022670(&a0->unk014);
        if (a0->unk03C == 0)
        {
            _021468E4.unk0E = 0;
        }
    }
    if (a0->unk010 != 0)
    {
        sub_02022670(&a0->unk044);
        if (a0->unk03C == 0)
        {
            _021468E4.unk0F = 0;
        }
    }
    sub_020226A0(a0);
}

int sub_02022340(UnkStruct021467A4 *a0, void *a1, void *a2)
{
    switch (a0->unk000)
    {
    case 0:
        sub_02022390(&a0->unk004, a1);
        sub_02022390(&a0->unk008, a2);
        break;
    case 1:
        if (a0->unk004 != 0)
        {
            sub_02022390(&a0->unk004, a1);
        }
        else
        {
            sub_02022390(&a0->unk008, a2);
        }
        break;
    case 2:
        if (a0->unk008 != 0)
        {
            sub_02022390(&a0->unk008, a2);
        }
        else
        {
            sub_02022390(&a0->unk004, a1);
        }
        break;
    }
    if (a0->unk004 == 0 && a0->unk008 == 0)
    {
        return 1;
    }
    return 0;
}

void sub_02022390(u32 *a0, void *a1)
{
    if (*a0 != 0)
    {
        if (sub_020223AC(a1) == 1)
        {
            *a0 = 0;
        }
    }
}
