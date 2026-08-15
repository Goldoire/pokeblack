#include "types.h"

void sub_0216D674(void *a, u32 b1);
void sub_0216D6BC(void *a, u32 b1);
void sub_0216D7CC(void *a);

BOOL sub_02199CC8(void *ctx)
{
    sub_0216D6BC(ctx, 4);
    sub_0216D674(ctx, 1);
    sub_0216D7CC(ctx);
    return 0;
}

BOOL sub_02199D00(void *ctx)
{
    sub_0216D674(ctx, 10);
    sub_0216D7CC(ctx);
    return 1;
}

BOOL sub_02199EAC(void *ctx)
{
    sub_0216D674(ctx, 10);
    sub_0216D7CC(ctx);
    return 1;
}

BOOL sub_02199EC0(void *ctx)
{
    sub_0216D674(ctx, 11);
    sub_0216D7CC(ctx);
    return 0;
}

BOOL sub_0219A014(void *ctx)
{
    sub_0216D674(ctx, 10);
    sub_0216D7CC(ctx);
    return 0;
}

BOOL sub_0219A028(void *ctx)
{
    sub_0216D674(ctx, 11);
    sub_0216D7CC(ctx);
    return 0;
}
