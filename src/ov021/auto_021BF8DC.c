#include "types.h"

BOOL sub_021BF7F8(void *a);
void sub_021BF874(void *a);
BOOL sub_021BF978(void *a);
void sub_021BF9F4(void *a);

BOOL sub_021BF8DC(void *ctx)
{
    sub_021BF874(ctx);
    return sub_021BF7F8(ctx);
}

BOOL sub_021BFA5C(void *ctx)
{
    sub_021BF9F4(ctx);
    return sub_021BF978(ctx);
}
