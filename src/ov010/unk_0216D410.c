#include "types.h"

// The object this file operates on: two 32-bit flag words followed by a run of
// u16 fields, each with a get/set accessor pair below.
struct UnkStruct0216D410
{
    u32 unk_00;
    u32 unk_04;
    u16 unk_08;
    u16 unk_0A;
    u16 unk_0C;
    u16 unk_0E;
    u16 unk_10;
    u16 unk_12;
    u16 unk_14;
};

void sub_0216D7C0(struct UnkStruct0216D410 *p);
void sub_0216D7C8(struct UnkStruct0216D410 *p, u32 param1);

void sub_0216D568(struct UnkStruct0216D410 *p, u32 mask);
void sub_0216D570(struct UnkStruct0216D410 *p, u32 mask);
u32 sub_0216D57C(struct UnkStruct0216D410 *p, u32 mask);

void sub_0216D410(struct UnkStruct0216D410 *p)
{
    sub_0216D7C0(p);
    sub_0216D7C8(p, 0);
    sub_0216D568(p, 0x200);
    sub_0216D570(p, 0x400);
}

void sub_0216D438(struct UnkStruct0216D410 *p)
{
    sub_0216D7C0(p);
    sub_0216D7C8(p, 0);
    sub_0216D570(p, 0x400);
}

int sub_0216D454(struct UnkStruct0216D410 *p)
{
    if (!sub_0216D57C(p, 0x200))
    {
        return TRUE;
    }

    if (sub_0216D57C(p, 0x400))
    {
        return TRUE;
    }

    return FALSE;
}

int sub_0216D480(struct UnkStruct0216D410 *p)
{
    if (!sub_0216D57C(p, 0x200))
    {
        return TRUE;
    }

    if (!sub_0216D57C(p, 0x400))
    {
        return FALSE;
    }

    sub_0216D570(p, 0x600);

    return TRUE;
}

void sub_0216D548(struct UnkStruct0216D410 *p, u32 mask)
{
    p->unk_00 |= mask;
}

void sub_0216D550(struct UnkStruct0216D410 *p, u32 mask)
{
    p->unk_00 &= ~mask;
}

u32 sub_0216D55C(struct UnkStruct0216D410 *p, u32 mask)
{
    return p->unk_00 & mask;
}

u32 sub_0216D564(struct UnkStruct0216D410 *p)
{
    return p->unk_04;
}

void sub_0216D568(struct UnkStruct0216D410 *p, u32 mask)
{
    p->unk_04 |= mask;
}

void sub_0216D570(struct UnkStruct0216D410 *p, u32 mask)
{
    p->unk_04 &= ~mask;
}

u32 sub_0216D57C(struct UnkStruct0216D410 *p, u32 mask)
{
    return p->unk_04 & mask;
}

void sub_0216D584(struct UnkStruct0216D410 *p, u16 value)
{
    p->unk_08 = value;
}

u16 sub_0216D588(struct UnkStruct0216D410 *p)
{
    return p->unk_08;
}

void sub_0216D58C(struct UnkStruct0216D410 *p, u16 value)
{
    p->unk_0A = value;
}

u16 sub_0216D590(struct UnkStruct0216D410 *p)
{
    return p->unk_0A;
}

void sub_0216D594(struct UnkStruct0216D410 *p, u16 value)
{
    p->unk_0C = value;
}

u16 sub_0216D598(struct UnkStruct0216D410 *p)
{
    return p->unk_0C;
}

void sub_0216D59C(struct UnkStruct0216D410 *p, u16 value)
{
    p->unk_0E = value;
}

u16 sub_0216D5A0(struct UnkStruct0216D410 *p)
{
    return p->unk_0E;
}

void sub_0216D5A4(struct UnkStruct0216D410 *p, u16 value)
{
    p->unk_10 = value;
}

u16 sub_0216D5A8(struct UnkStruct0216D410 *p)
{
    return p->unk_10;
}

void sub_0216D5AC(struct UnkStruct0216D410 *p, u16 value)
{
    p->unk_12 = value;
}

u16 sub_0216D5B0(struct UnkStruct0216D410 *p)
{
    return p->unk_12;
}

void sub_0216D5B4(struct UnkStruct0216D410 *p, u16 value)
{
    p->unk_14 = value;
}

u16 sub_0216D5B8(struct UnkStruct0216D410 *p)
{
    return p->unk_14;
}
