#include "ov135/worldtrade.h"

extern u32 (*const _02203C48[])(void *a0);

/* worldtrade_input.c work block (distinct from WorldTradeWork). */
typedef struct WorldTradeInputEntry
{
    u32 unk_00;
    u32 unk_04;
} WorldTradeInputEntry;

typedef struct WorldTradeInput
{
    u8 pad_0000[0x18];
    void *unk_0018;
    u8 pad_001C[0x30 - 0x1C];
    WorldTradeInputEntry *unk_0030;
    void *unk_0034;
    u8 pad_0038[0x48 - 0x38];
    u32 unk_0048;
    u8 pad_004C[0x56 - 0x4C];
    s16 unk_0056;
    s32 unk_0058;
    u8 pad_005C[0x7C - 0x5C];
    u8 unk_007C;
} WorldTradeInput;

void sub_021B9B00(u8 *a0, void *a1);
void sub_021C8E18(u8 *a0, u8 *a1);
void sub_021F4EC0(WorldTradeWork *work, u32 a1, u32 a2);
void sub_020307B0(void *a0);
void sub_021F4FC4(WorldTradeWork *work);
void sub_021C8658(void);
void sub_021F90B8(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4, u32 a5);
u32 sub_021F914C(void *a0, u32 a1, u32 a2, u32 a3, u16 a4, u32 a5, u32 a6);
void sub_022028C8(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6,
                  u32 a7);
void sub_02202744(u8 *a0);
void sub_022029D4(void *a0);
void sub_0202CA0C(void *a0);
void sub_0202CD94(void *a0);
void sub_02202770(u8 *a0);
void sub_022029F8(void *a0);
u32 sub_0209C0A4(u32 a0, u32 a1);
void sub_021F9F58(WorldTradeInput *a0, s32 a1);
void sub_020061E4(u32 a0);

u32 sub_021F8BBC(WorldTradeWork *work)
{
    sub_021B9B00(&work->unk_0F18, work->unk_0000[7]);
    sub_021C8E18(&work->unk_0F18, &work->unk_0F7C);
    work->unk_0F8C = 0;
    return 1;
}

u32 sub_021F8DA4(WorldTradeWork *work)
{
    u32 *p = (u32 *)work->unk_10DC;

    if (work->unk_12F4 == 0)
    {
        switch (p[7])
        {
        case 0:
            work->state = 0;
            break;
        case 1:
            sub_021F4EC0(work, 0, 0);
            work->state = 1;
            break;
        }
        sub_020307B0(work->unk_10DC);
    }
    return 2;
}

u32 sub_021F8E58(WorldTradeWork *work)
{
    if (work->unk_12F4 == 0)
    {
        sub_020307B0(work->unk_10DC);
        sub_021F4EC0(work, 0, 0);
        work->state = 1;
    }
    return 2;
}

u32 sub_021F8F5C(void)
{
    sub_021C8658();
    return 0;
}

u32 sub_021F8F68(WorldTradeWork *work)
{
    sub_021F4FC4(work);
    work->state = 0;
    work->unk_0EB4 = 1;
    return 3;
}

void sub_021F9088(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    sub_021F90B8(a0, a1, a2, a3, a4, 1);
}

void sub_021F90A0(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    sub_021F90B8(a0, a1, a2, a3, a4, 0);
}

void sub_021F91A0(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 a5, u32 a6)
{
    u32 r = sub_021F914C(a0, a1, a2, a4, a5, 0, a6);

    sub_022028C8(a0, 0, a1, r, a3, 0, a5, a6);
}

void sub_021F91DC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 a5, u32 a6)
{
    u32 r = sub_021F914C(a0, a1, a2, a4, a5, 0, a6);

    sub_022028C8(a0, 0, a1, r, a3, 0, a5, a6);
}

void sub_021F99D0(WorldTradeInput *a0)
{
    sub_02202744(&a0->unk_007C);
    sub_022029D4(a0->unk_0034);
    sub_0202CA0C(a0->unk_0018);
    sub_020307B0(a0);
}

u32 sub_021F99F0(WorldTradeInput *a0)
{
    u32 ret = _02203C48[a0->unk_0048](a0);

    sub_0202CD94(a0->unk_0018);
    sub_02202770(&a0->unk_007C);
    sub_022029F8(a0->unk_0034);
    return ret;
}

u32 sub_021F9EEC(u32 a0, u32 a1)
{
    if (a0 == 0)
    {
        return 1;
    }
    return (a0 + (a1 - 1)) / a1;
}

s32 sub_021F9F00(WorldTradeInput *a0, s32 a1)
{
    s32 idx;

    switch (a1)
    {
    case 4:
        return -2;
    case 5:
        sub_021F9F58(a0, -1);
        return -1;
    case 6:
        sub_021F9F58(a0, 1);
        return -1;
    }
    idx = a1 + a0->unk_0056 * 4;
    if (idx < a0->unk_0058)
    {
        sub_020061E4(0x54C);
        return a0->unk_0030[idx].unk_04;
    }
    return -1;
}
