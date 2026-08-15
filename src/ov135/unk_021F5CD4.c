#include "ov135.h"

extern const u32 _02202C58[];
extern u8 _02203B68[];

/* 4-byte descriptor built by sub_021F6CDC and consumed by sub_021F6C80. */
typedef struct WorldTradeBoxEntry
{
    s16 unk_00;
    u8 unk_02;
    u8 unk_03;
} WorldTradeBoxEntry;

/* 0x20C-byte records; only +4 is constrained (sub_021F6DB4). */
typedef struct WorldTradeBoxRecord
{
    u8 pad_0000[4];
    u32 unk_0004;
    u8 pad_0008[0x20C - 0x08];
} WorldTradeBoxRecord;

void sub_021F4EC0(WorldTradeWork *work, u32 a1, u32 a2);
void sub_021F4E98(WorldTradeWork *work, u32 a1, u32 a2);
void sub_021F4BE0(WorldTradeWork *work, u32 a1, u32 a2, u32 a3, u8 a4);
void sub_021F663C(WorldTradeWork *work, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
void sub_0202208C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
u32 sub_02202840(WorldTradeAdapter *a0);
u32 sub_02018438(void *a0);
u32 sub_021F6B34(u32 a0);
s32 sub_0201AA18(void *a0);
u32 sub_020078C4(void *a0, u32 a1);
u32 sub_02017DBC(void *a0);
u32 sub_02017E88(void *a0, u32 a1, u32 a2);
void sub_02017DE4(void *a0, u32 a1);
u32 sub_02017E1C(void *a0, u32 a1, u32 a2);
u32 sub_0202136C(u16 a0);
void *sub_0201F81C(u32 a0, u32 a1);
void sub_0201F878(void *a0, void *a1, u32 a2, u32 a3, u32 a4);
void sub_021F4D50(WorldTradeWork *work, u32 a1, u32 a2, u32 a3);
u32 sub_021F4D14(WorldTradeWork *work);
void sub_021F4CE4(WorldTradeWork *work);
void sub_02034714(void *a0, u32 a1, void *a2);
void sub_021F6474(WorldTradeWork *work);
void sub_0201F7A8(void *a0, u32 a1);
u32 sub_021F6B40(void *a0, void *a1, u32 a2, s32 a3);
void *sub_0201BABC(void *a0);
void *sub_021F66C8(void *a0, void *a1, void **a2, u32 a3);
void sub_02082B0C(const void *src, void *dst, u32 size);
void sub_020307B0(void *a0);
u32 sub_0201BB5C(void *a0, u32 a1, u32 a2, u32 a3);
s32 sub_0201AB28(void *a0, s32 a1);
u32 sub_020185F4(s32 a0);
u32 sub_02007A18(void *a0, u32 a1, s32 a2);
u32 sub_021F6C80(WorldTradeBoxEntry *a0, void *a1);
u32 sub_020076A4(void *a0);
u32 sub_020076B4(void *a0);

u32 sub_020362DC(void);
u32 sub_02035C60(void);

u32 sub_021F6604(WorldTradeWork *work)
{
    if (sub_02202840(&work->unk_0FA0) == 0)
    {
        if (sub_020362DC() != 0 || sub_02035C60() != 0)
        {
            sub_0201F7A8(work->unk_0DD0, 0);
            work->state = work->unk_002C;
        }
    }
    return 2;
}

void sub_021F5CD4(WorldTradeWork *work, u32 a1)
{
    if (a1 == 5)
    {
        sub_021F4EC0(work, 1, 0);
        work->state = 2;
    }
    else if (a1 == 6)
    {
        sub_021F4EC0(work, 3, 0x11);
        work->state = 2;
    }
}

u32 sub_021F632C(WorldTradeWork *work)
{
    if (work->unk_0014 == 0 || work->unk_0014 == 8 || work->unk_0014 == 3)
    {
        sub_0202208C(0, 0, 0, 0, 6, 1, 0x48);
        work->unk_0EB4 = 1;
    }
    else
    {
        sub_0202208C(3, 0, 0, 0, 6, 1, 0x48);
    }
    work->state = 0;
    return 3;
}

u32 sub_021F6384(WorldTradeWork *work)
{
    sub_021F4BE0(work, 0x14, 0x1AD, 8, 1);
    work->state = 6;
    return 2;
}

u32 sub_021F63EC(WorldTradeWork *work)
{
    sub_021F663C(work, 0x19, 1, 0, 0xF0F, 1);
    sub_021F4E98(work, 3, 0xC);
    return 2;
}

u32 sub_021F6418(WorldTradeWork *work)
{
    sub_021F4BE0(work, 0x12, 0x1AD, 8, 1);
    work->state = 0xD;
    return 2;
}

u32 sub_021F6548(WorldTradeWork *work)
{
    sub_021F4BE0(work, 0x12, 0x1AD, 8, 1);
    work->state = 0x10;
    return 2;
}

u32 sub_021F65E8(WorldTradeWork *work)
{
    if (sub_02202840(&work->unk_0FA0) == 0)
    {
        work->state = work->unk_002C;
    }
    return 2;
}

void sub_021F6748(void *a0, u8 *a1)
{
    a1[3] = sub_02018438(a0);
}

void sub_021F6B80(void *a0, void *a1, u32 a2)
{
    if (sub_021F6B34(a2) != 0)
    {
        sub_0201AA18(a0);
    }
    else
    {
        sub_020078C4(a1, a2);
    }
}

u32 sub_021F6BA4(void *a0, void *a1, u32 a2)
{
    if (sub_021F6B34(a2) != 0)
    {
        if (sub_0201AA18(a0) < 2)
        {
            return 0;
        }
    }
    return 1;
}

u32 sub_021F6BC4(void *a0)
{
    u32 saved;
    u32 ret;
    u32 i;

    saved = sub_02017DBC(a0);
    for (i = 0; i < 15; i++)
    {
        ret = sub_02017E88(a0, _02202C58[i], 0);
        if (ret == 1)
        {
            break;
        }
    }
    sub_02017DE4(a0, saved);
    return ret;
}

u32 sub_021F6BFC(void *a0)
{
    u32 saved = sub_02017DBC(a0);

    sub_02017E88(a0, 5, 0);
    sub_02017E88(a0, 0x6F, 0);
    sub_02017DE4(a0, saved);
    return 0;
}

u32 sub_021F6C28(void *a0)
{
    u32 saved = sub_02017DBC(a0);

    sub_02017E88(a0, 6, 0);
    sub_02017DE4(a0, saved);
    return 0;
}

u32 sub_021F6DE8(void *a0)
{
    u32 ret = 0;
    u16 v = (u16)sub_02017E1C(a0, 6, 0);

    if (sub_0202136C(v) != 0)
    {
        ret = 1;
    }
    return ret;
}

u32 sub_021F5FC0(WorldTradeWork *work)
{
    work->unk_0DE8 = sub_0201F81C(3, 0x48);
    sub_0201F878(work->unk_0DE8, work->unk_0B6C, 0x68, 1, 0x48);
    sub_0201F878(work->unk_0DE8, work->unk_0B6C, 0x69, 2, 0x48);
    sub_0201F878(work->unk_0DE8, work->unk_0B6C, 0x6A, 3, 0x48);
    sub_021F4D50(work, 0, 3, 0x14);
    work->state = 8;
    return 2;
}

u32 sub_021F6178(WorldTradeWork *work)
{
    work->unk_0DE8 = sub_0201F81C(3, 0x48);
    sub_0201F878(work->unk_0DE8, work->unk_0B6C, 0x5D, 1, 0x48);
    sub_0201F878(work->unk_0DE8, work->unk_0B6C, 0x5E, 2, 0x48);
    sub_0201F878(work->unk_0DE8, work->unk_0B6C, 0x5F, 3, 0x48);
    sub_021F4D50(work, 0, 3, 0x14);
    work->state = 10;
    return 2;
}

u32 sub_021F63A8(WorldTradeWork *work)
{
    u32 r = sub_021F4D14(work);

    sub_02034714(_02203B68, 0, _02203B68);
    if (r == 1)
    {
        sub_021F4CE4(work);
        work->state = 2;
        sub_021F4EC0(work, 0, 0);
    }
    else if (r == 2)
    {
        sub_021F4CE4(work);
        work->state = 0;
    }
    return 2;
}

u32 sub_021F643C(WorldTradeWork *work)
{
    u32 r = sub_021F4D14(work);

    if (r == 1)
    {
        sub_021F4CE4(work);
        sub_021F6474(work);
    }
    else if (r == 2)
    {
        sub_021F4CE4(work);
        sub_0201F7A8(work->unk_0DD0, 0);
        work->state = 1;
    }
    return 2;
}

u32 sub_021F651C(WorldTradeWork *work)
{
    sub_021F663C(work, 0x19, 1, 0, 0xF0F, 1);
    sub_021F4E98(work, 3, 0xF);
    return 2;
}

u32 sub_021F656C(WorldTradeWork *work)
{
    u32 r = sub_021F4D14(work);

    if (r == 1)
    {
        sub_021F4CE4(work);
        work->unk_00CC = sub_021F6B40(work->unk_0000[2], work->unk_0000[3],
                                      work->unk_00C4, work->unk_00C6);
        work->state = 2;
        sub_021F4EC0(work, 6, 0);
    }
    else if (r == 2)
    {
        sub_021F4CE4(work);
        sub_0201F7A8(work->unk_0DD0, 0);
        work->state = 1;
    }
    return 2;
}

void sub_021F66F0(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, void *a6,
                  u8 *a7)
{
    void *sp8;
    void *tmp;

    tmp = sub_021F66C8(a6, sub_0201BABC(a0), &sp8, 0x48);
    sub_02082B0C(((void **)sp8)[5], a7 + 0xC, 0x200);
    *(u32 *)a7 = ((a4 << 4) + 0x1C) << 5;
    *(u32 *)(a7 + 8) = a5;
    *(u32 *)(a7 + 4) = sub_0201BB5C(a0, a1, a2, a3) + 5;
    sub_020307B0(tmp);
}

u32 sub_021F6B40(void *a0, void *a1, u32 a2, s32 a3)
{
    if (sub_021F6B34(a2) != 0)
    {
        if (a3 > sub_0201AA18(a0) - 1)
        {
            return 0;
        }
        return sub_020185F4(sub_0201AB28(a0, a3));
    }
    return sub_02007A18(a1, a2, a3);
}

void sub_021F6CDC(void *a0, void *a1)
{
    WorldTradeBoxEntry entry;

    entry.unk_00 = (s16)sub_02017E88(a0, 5, 0);
    entry.unk_02 = (u8)(sub_02017E88(a0, 0x6E, 0) + 1);
    entry.unk_03 = (u8)sub_02018438(a0);
    sub_021F6C80(&entry, a1);
}

void sub_021F6DB4(WorldTradeBoxEntry *a0, void *a1, void *a2,
                  WorldTradeBoxRecord *a3)
{
    s32 i;

    for (i = 0; i < 30; i++)
    {
        if (a0[i].unk_00 != 0 && sub_021F6C80(&a0[i], a2) == 0)
        {
            a3[i].unk_0004 += 3;
        }
    }
}

void sub_021F6E08(WorldTradeWork *work)
{
    u32 i;

    work->unk_00C8 = sub_020076A4(work->unk_0000[3]);
    if (work->unk_00C8 < 0x18)
    {
        for (i = 0; i < work->unk_00C8; i++)
        {
            if (sub_020078C4(work->unk_0000[3], i) == 0)
            {
                break;
            }
        }
        if (i == work->unk_00C8)
        {
            work->unk_00C8 = sub_020076B4(work->unk_0000[3]);
        }
    }
}
