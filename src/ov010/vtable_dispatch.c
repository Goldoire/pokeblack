#include "types.h"

struct UnkStruct0216D684;

// Two five-entry callback tables hang off the object at +0x8C and +0x90.
struct UnkVtable0216D684
{
    void (*unk_00)(struct UnkStruct0216D684 *);
    void (*unk_04)(struct UnkStruct0216D684 *);
    void (*unk_08)(struct UnkStruct0216D684 *);
    void (*unk_0C)(struct UnkStruct0216D684 *);
    void (*unk_10)(struct UnkStruct0216D684 *);
};

struct UnkStruct0216D684
{
    u8 unk_00[0x8C];
    const struct UnkVtable0216D684 *unk_8C;
    const struct UnkVtable0216D684 *unk_90;
    u8 unk_94[0x10];
    u8 unk_A4[0x10];
    u8 unk_B4[0x10];
    u8 unk_C4[0x10];
};

void sub_02082BCC(void *dest, u8 value, u32 size);   // MI_CpuFill8

void *sub_0216D69C(struct UnkStruct0216D684 *p);
void *sub_0216D6B8(struct UnkStruct0216D684 *p);
void *sub_0216D6D4(struct UnkStruct0216D684 *p);
void *sub_0216D6F0(struct UnkStruct0216D684 *p);

void *sub_0216D684(struct UnkStruct0216D684 *p, u32 size)
{
    void *buf = sub_0216D69C(p);

    sub_02082BCC(buf, 0, size);

    return buf;
}

void *sub_0216D69C(struct UnkStruct0216D684 *p)
{
    return p->unk_94;
}

void *sub_0216D6A0(struct UnkStruct0216D684 *p, u32 size)
{
    void *buf = sub_0216D6B8(p);

    sub_02082BCC(buf, 0, size);

    return buf;
}

void *sub_0216D6B8(struct UnkStruct0216D684 *p)
{
    return p->unk_A4;
}

void *sub_0216D6BC(struct UnkStruct0216D684 *p, u32 size)
{
    void *buf = sub_0216D6D4(p);

    sub_02082BCC(buf, 0, size);

    return buf;
}

void *sub_0216D6D4(struct UnkStruct0216D684 *p)
{
    return p->unk_B4;
}

void *sub_0216D6D8(struct UnkStruct0216D684 *p, u32 size)
{
    void *buf = sub_0216D6F0(p);

    sub_02082BCC(buf, 0, size);

    return buf;
}

void *sub_0216D6F0(struct UnkStruct0216D684 *p)
{
    return p->unk_C4;
}

void sub_0216D6F4(struct UnkStruct0216D684 *p)
{
    if (p->unk_8C->unk_04 != NULL)
    {
        p->unk_8C->unk_04(p);
    }
}

void sub_0216D708(struct UnkStruct0216D684 *p)
{
    if (p->unk_8C->unk_08 != NULL)
    {
        p->unk_8C->unk_08(p);
    }
}

void sub_0216D71C(struct UnkStruct0216D684 *p)
{
    if (p->unk_8C->unk_0C != NULL)
    {
        p->unk_8C->unk_0C(p);
    }
}

void sub_0216D730(struct UnkStruct0216D684 *p)
{
    if (p->unk_8C->unk_10 != NULL)
    {
        p->unk_8C->unk_10(p);
    }
}

void sub_0216D744(struct UnkStruct0216D684 *p)
{
    if (p->unk_90->unk_00 != NULL)
    {
        p->unk_90->unk_00(p);
    }
}

void sub_0216D758(struct UnkStruct0216D684 *p)
{
    if (p->unk_90->unk_04 != NULL)
    {
        p->unk_90->unk_04(p);
    }
}

void sub_0216D76C(struct UnkStruct0216D684 *p)
{
    if (p->unk_90->unk_08 != NULL)
    {
        p->unk_90->unk_08(p);
    }
}

void sub_0216D780(struct UnkStruct0216D684 *p)
{
    if (p->unk_90->unk_0C != NULL)
    {
        p->unk_90->unk_0C(p);
    }
}

void sub_0216D794(struct UnkStruct0216D684 *p)
{
    if (p->unk_90->unk_10 != NULL)
    {
        p->unk_90->unk_10(p);
    }
}
