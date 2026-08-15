#include "types.h"

BOOL sub_021BC5E4(void *a);
void sub_021BC63C(void *a);
BOOL sub_021BC654(void *ctx);
BOOL sub_021BC720(void *a);

BOOL sub_021BC5D4(void *ctx)
{
    sub_021BC654(ctx);
    return sub_021BC720(ctx);
}

BOOL sub_021BC654(void *ctx)
{
    sub_021BC63C(ctx);
    return sub_021BC5E4(ctx);
}
