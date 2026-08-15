#include "types.h"

void * sub_0216D534(void *a);
void sub_0216D674(void *a, u32 b1);
void * sub_0216D67C(void *a);
BOOL sub_02188CD0(void *a);
void sub_0219DC34(void *a, u32 b1);

BOOL sub_0219DC08(void *ctx)
{
    return sub_02188CD0(sub_0216D534(sub_0216D67C(ctx)));
}

BOOL sub_0219DC58(void *ctx)
{
    sub_0219DC34(ctx, 0);
    return 1;
}

BOOL sub_0219DC64(void *ctx)
{
    sub_0219DC34(ctx, 1);
    return 1;
}

BOOL sub_0219DC70(void *ctx)
{
    sub_0219DC34(ctx, 2);
    return 1;
}

BOOL sub_0219DC7C(void *ctx)
{
    sub_0219DC34(ctx, 3);
    return 1;
}

BOOL sub_0219DD18(void *ctx)
{
    sub_0216D674(ctx, 0);
    return 0;
}
