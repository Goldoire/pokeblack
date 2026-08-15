#include "types.h"

// bitfield accessors living just below this block in the same overlay
void sub_0216D548(void *p, u32 mask);   // p->word0 |=  mask
void sub_0216D550(void *p, u32 mask);   // p->word0 &= ~mask
u32 sub_0216D55C(void *p, u32 mask);    // p->word0 &   mask
void sub_0216D568(void *p, u32 mask);   // p->word1 |=  mask
void sub_0216D570(void *p, u32 mask);   // p->word1 &= ~mask
u32 sub_0216D57C(void *p, u32 mask);    // p->word1 &   mask

void *sub_0216D67C(void *p);
u32 sub_0216D948(void *p);

BOOL sub_0216DAA0(void *p)
{
    if (sub_0216D57C(p, 0x2))
    {
        return TRUE;
    }

    return FALSE;
}

BOOL sub_0216DAB4(void *p)
{
    if (sub_0216D55C(p, 0x4))
    {
        return TRUE;
    }

    return FALSE;
}

void sub_0216DAC8(void *p, BOOL flag)
{
    if (flag == TRUE)
    {
        sub_0216D548(p, 0x4);
    }
    else
    {
        sub_0216D550(p, 0x4);
    }
}

void sub_0216DAE0(void *p, BOOL flag)
{
    if (flag == TRUE)
    {
        sub_0216D550(p, 0x80);
    }
    else
    {
        sub_0216D548(p, 0x80);
    }
}

BOOL sub_0216DB10(void *p)
{
    if (sub_0216D57C(p, 0x8))
    {
        return TRUE;
    }

    return FALSE;
}

BOOL sub_0216DB24(void *p)
{
    if (sub_0216D948(sub_0216D67C(p)) == 0)
    {
        return FALSE;
    }

    if (sub_0216DAA0(p))
    {
        return TRUE;
    }

    return FALSE;
}

void sub_0216DB4C(void *p, BOOL flag)
{
    if (flag == TRUE)
    {
        sub_0216D548(p, 0x200);
    }
    else
    {
        sub_0216D550(p, 0x200);
    }
}

BOOL sub_0216DB68(void *p)
{
    if (sub_0216D55C(p, 0x200))
    {
        return TRUE;
    }

    return FALSE;
}

void sub_0216DB80(void *p, BOOL flag)
{
    if (flag == TRUE)
    {
        sub_0216D548(p, 0x20);
    }
    else
    {
        sub_0216D550(p, 0x20);
    }
}

void sub_0216DB98(void *p, BOOL flag)
{
    if (flag == TRUE)
    {
        sub_0216D548(p, 0x800);
    }
    else
    {
        sub_0216D550(p, 0x800);
    }
}

BOOL sub_0216DBB4(void *p)
{
    if (sub_0216D55C(p, 0x800))
    {
        return TRUE;
    }

    return FALSE;
}

void sub_0216DBCC(void *p, BOOL flag)
{
    if (flag == TRUE)
    {
        sub_0216D568(p, 0x40000);
    }
    else
    {
        sub_0216D570(p, 0x40000);
    }
}

BOOL sub_0216DBE8(void *p)
{
    if (sub_0216D57C(p, 0x40000))
    {
        return TRUE;
    }

    return FALSE;
}

BOOL sub_0216DC00(void *p)
{
    if (sub_0216D55C(p, 0x1000))
    {
        return TRUE;
    }

    return FALSE;
}

void sub_0216DC18(void *p, BOOL flag)
{
    if (flag == TRUE)
    {
        sub_0216D568(p, 0x20000);
    }
    else
    {
        sub_0216D570(p, 0x20000);
    }
}

BOOL sub_0216DC34(void *p)
{
    if (sub_0216D57C(p, 0x20000))
    {
        return TRUE;
    }

    return FALSE;
}

BOOL sub_0216DC4C(void *p)
{
    if (sub_0216D57C(p, 0x200))
    {
        return TRUE;
    }

    return FALSE;
}

void sub_0216DC64(void *p, BOOL flag)
{
    if (flag == TRUE)
    {
        sub_0216D568(p, 0x80000);
    }
    else
    {
        sub_0216D570(p, 0x80000);
    }
}

BOOL sub_0216DC80(void *p)
{
    if (sub_0216D57C(p, 0x80000))
    {
        return TRUE;
    }

    return FALSE;
}

void sub_0216DC98(void *p, BOOL flag)
{
    if (flag == TRUE)
    {
        sub_0216D548(p, 0x400);
    }
    else
    {
        sub_0216D550(p, 0x400);
    }
}

BOOL sub_0216DCB4(void *p)
{
    if (sub_0216D55C(p, 0x400))
    {
        return TRUE;
    }

    return FALSE;
}

void sub_0216DCCC(void *p, BOOL flag)
{
    if (flag == TRUE)
    {
        sub_0216D568(p, 0x100000);
    }
    else
    {
        sub_0216D570(p, 0x100000);
    }
}

void sub_0216DCE8(void *p, BOOL flag)
{
    if (flag == TRUE)
    {
        sub_0216D568(p, 0x200000);
    }
    else
    {
        sub_0216D570(p, 0x200000);
    }
}

BOOL sub_0216DD04(void *p)
{
    if (sub_0216D57C(p, 0x200000))
    {
        return TRUE;
    }

    return FALSE;
}
