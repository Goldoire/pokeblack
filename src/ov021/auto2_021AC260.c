#include "types.h"

BOOL sub_020307B0(void *a);
void sub_021AC2AC(void *a);
void sub_021AC514(void *a);
void sub_021AC740(void *a);
void sub_021ACB0C(void *a);

BOOL sub_021AC260(void *a, void *b)
{
    sub_021AC2AC(b);
    return sub_020307B0(b);
}

BOOL sub_021AC4B8(void *a, void *b)
{
    sub_021AC514(b);
    return sub_020307B0(b);
}

BOOL sub_021AC6C0(void *a, void *b)
{
    sub_021AC740(b);
    return sub_020307B0(b);
}

BOOL sub_021ACA5C(void *a, void *b)
{
    sub_021ACB0C(b);
    return sub_020307B0(b);
}
