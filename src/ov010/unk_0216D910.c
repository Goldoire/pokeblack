#include "types.h"

u32 sub_0216D4D4(void *p, u32 mask);
void sub_0216D4DC(void *p, u32 mask);
void sub_0216D4E4(void *p, u32 mask);
void sub_0216D520(void *p);
void *sub_0216D67C(void *p);
u32 sub_0216D55C(void *p, u32 mask);
u32 sub_0216D57C(void *p, u32 mask);
u32 sub_0216DC80(void *p);
void sub_0216DAF8(void *p);
void sub_0216DB04(void *p);
int sub_0216DD1C(void *p, void **out0, u32 *out1);

void sub_0216D910(void *p)
{
    sub_0216D520(sub_0216D67C(p));
}

int sub_0216D948(void *p)
{
    int ret = TRUE;

    if (sub_0216D4D4(p, 0x1) == 0)
    {
        ret = FALSE;
    }

    return ret;
}

void sub_0216D95C(void *p, int flag)
{
    if (flag == TRUE)
    {
        sub_0216D4DC(p, 0x1);
    }
    else
    {
        sub_0216D4E4(p, 0x1);
    }
}

void sub_0216D974(void *p, int flag)
{
    if (flag == FALSE)
    {
        sub_0216D4DC(p, 0x8);
    }
    else
    {
        sub_0216D4E4(p, 0x8);
    }
}

int sub_0216D98C(void *p)
{
    if (sub_0216D4D4(p, 0x8))
    {
        return FALSE;
    }

    return TRUE;
}

void sub_0216D9A0(void *p)
{
    u32 state = 0;
    void *it;

    while (sub_0216DD1C(p, &it, &state) == TRUE)
    {
        if (!sub_0216DC80(it))
        {
            sub_0216DAF8(it);
        }
    }

    sub_0216D4DC(p, 0x20);
}

void sub_0216D9E4(void *p)
{
    u32 state = 0;
    void *it;

    while (sub_0216DD1C(p, &it, &state) == TRUE)
    {
        sub_0216DB04(it);
    }

    sub_0216D4E4(p, 0x20);
}

u32 sub_0216DA20(void *p, u32 mask)
{
    return sub_0216D4D4(sub_0216D67C(p), mask);
}

int sub_0216DA30(void *p)
{
    int ret = TRUE;

    if (sub_0216D55C(p, 0x1) == 0)
    {
        ret = FALSE;
    }

    return ret;
}

int sub_0216DA5C(void *p)
{
    if (sub_0216D57C(p, 0x10))
    {
        return TRUE;
    }

    return FALSE;
}
