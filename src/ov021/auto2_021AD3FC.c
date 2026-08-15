#include "types.h"

BOOL sub_020307B0(void *a);
void sub_021AD530(void *a);
void sub_021ADA1C(void *a);

BOOL sub_021AD3FC(void *a, void *b)
{
    sub_021AD530(b);
    return sub_020307B0(b);
}

BOOL sub_021AD7A0(void *a, void *b)
{
    sub_021ADA1C(b);
    return sub_020307B0(b);
}
