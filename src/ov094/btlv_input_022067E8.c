#include "types.h"

// btlv_input.c shares the one big BTLV work struct with btlv_effvm.c /
// btlv_effect.c (the object behind the 0x0220AF20 singleton): 0x23C is the same
// "yield" word the effect-VM commands return.
typedef struct BtlvWork
{
    /* 0x000 */ u8 pad_000[0x008];
    /* 0x008 */ u32 unk008[8];
    /* 0x028 */ u32 unk028[8];
    /* 0x048 */ u8 pad_048[0x23C - 0x048];
    /* 0x23C */ u32 unk23C;
    /* 0x240 */ u16 unk240;
    /* 0x242 */ u8 unk242[6][8];
    /* 0x272 */ u8 pad_272[0x278 - 0x272];
    /* 0x278 */ u32 unk278;
    /* 0x27C */ u32 unk27C;
    /* 0x280 */ u32 unk280;
    /* 0x284 */ u8 unk284[0x20];
} BtlvWork;

void sub_020215BC(void *a0, void *a1, u32 a2, u32 a3, u32 a4);
void sub_02021F64(void *dst, void *src, u32 a2, u32 a3, u32 a4);

int sub_021B86B8(void *a0);

void sub_021F8554(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
void *sub_021F86B4(void);
void *sub_021F86E0(void);
void *sub_021F8694(void);
void *sub_021F8754(void);
void sub_021F8AC0(u32 a0);
int sub_021F8914(void);

u32 sub_022005C4(void *sys, u32 sprId);
u32 sub_02207D78(void *a0, u32 a1);
void sub_0220687C(BtlvWork *w, u32 a1);

int sub_022068C4(BtlvWork *w);

void sub_022067E8(BtlvWork *w)
{
    sub_021F8AC0(2);
    sub_021F8554(w->unk278, 1, 0xA, 0, 8);
}

void sub_0220680C(BtlvWork *w)
{
    int i;

    if ((sub_02207D78(sub_021F86B4(), w->unk278) |
         sub_022005C4(sub_021F8694(), w->unk278)) == 1)
    {
        for (i = 0; i < 8; i++)
        {
            w->unk242[w->unk27C][i] = 0;
        }
    }
}

void sub_0220684C(BtlvWork *w, u32 a1, u32 a2)
{
    int i;

    i = sub_022068C4(w);
    w->unk008[i] = a1;
    w->unk028[i] = a2;
}

int sub_02206864(BtlvWork *w, u32 key)
{
    int i;
    u32 v;

    for (i = 0; i < 8; i++)
    {
        v = w->unk008[i];
        if (v == key)
        {
            break;
        }
    }

    return i;
}

int sub_022068C4(BtlvWork *w)
{
    int i;

    for (i = 0; i < 8; i++)
    {
        if (w->unk008[i] == 0)
        {
            break;
        }
    }

    if (i == 8)
    {
        sub_0220687C(w, w->unk008[0]);
        i = 0;
    }

    return i;
}

void sub_02206A14(BtlvWork *w)
{
    u8 buf[0x20];

    if (sub_021B86B8(sub_021F8754()) == 4)
    {
        return;
    }
    if (sub_021F8914() != 0)
    {
        return;
    }

    sub_02021F64(w->unk284, buf, 0x10, 8, 0);
    sub_020215BC(sub_021F86E0(), buf, 1, 0x20, 0x20);
}

void sub_02206A58(BtlvWork *w)
{
    if (w->unk23C == 1)
    {
        sub_020215BC(sub_021F86E0(), w->unk284, 1, 0x20, 0x20);
    }
}
