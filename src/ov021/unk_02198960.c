#include "types.h"

typedef u32 BOOL;

void sub_02198960(void *ctx, u32 arg);

BOOL sub_02198998(void *ctx)
{
    sub_02198960(ctx, 1);
    return TRUE;
}

BOOL sub_021989A4(void *ctx)
{
    sub_02198960(ctx, 2);
    return TRUE;
}

BOOL sub_021989B0(void *ctx)
{
    sub_02198960(ctx, 4);
    return TRUE;
}

BOOL sub_021989BC(void *ctx)
{
    sub_02198960(ctx, 8);
    return TRUE;
}

BOOL sub_021989C8(void *ctx)
{
    sub_02198960(ctx, 15);
    return TRUE;
}

BOOL sub_021989D4(void *ctx)
{
    sub_02198960(ctx, 16);
    return TRUE;
}

BOOL sub_021989E0(void *ctx)
{
    sub_02198960(ctx, 32);
    return TRUE;
}
