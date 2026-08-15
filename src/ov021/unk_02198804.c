#include "types.h"

void sub_021984C0(void *ctx, u32 a, u32 b, s8 c, u16 d, s16 e, u16 f, u32 g);

void sub_0219852C(void *ctx, u32 a, u32 b, s8 c, u16 d, s16 e, u16 f)
{
    sub_021984C0(ctx, a, b, c, d, e, f, 0x55E);
}

BOOL sub_02198804(void *ctx)
{
    sub_0219852C(ctx, 2, 0x2000, 0x10, 3, 0, 0x100);
    return TRUE;
}

BOOL sub_02198824(void *ctx)
{
    sub_0219852C(ctx, 3, 0x2000, 0x10, 3, 0, 0x100);
    return TRUE;
}

BOOL sub_02198848(void *ctx)
{
    sub_0219852C(ctx, 2, 0x1000, 0x10, 2, 0, 0xF0);
    return TRUE;
}

BOOL sub_02198868(void *ctx)
{
    sub_0219852C(ctx, 3, 0x1000, 0x10, 2, 0, 0xF0);
    return TRUE;
}

BOOL sub_02198888(void *ctx)
{
    sub_0219852C(ctx, 2, 0x4000, 0xC, 3, 0, 0x140);
    return TRUE;
}

BOOL sub_021988AC(void *ctx)
{
    sub_0219852C(ctx, 3, 0x4000, 0xC, 3, 0, 0x140);
    return TRUE;
}

BOOL sub_021988D0(void *ctx)
{
    sub_021984C0(ctx, 0, 0x2000, 0x18, 3, 0, 0xA0, 0);
    return TRUE;
}

BOOL sub_021988F4(void *ctx)
{
    sub_021984C0(ctx, 1, 0x2000, 0x18, 3, 0, 0xA0, 0);
    return TRUE;
}

BOOL sub_02198918(void *ctx)
{
    sub_021984C0(ctx, 2, 0x2000, 0x18, 3, 0, 0xA0, 0);
    return TRUE;
}

BOOL sub_0219893C(void *ctx)
{
    sub_021984C0(ctx, 3, 0x2000, 0x18, 3, 0, 0xA0, 0);
    return TRUE;
}
