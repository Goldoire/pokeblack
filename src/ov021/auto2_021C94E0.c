#include "types.h"

BOOL sub_020307B0(void *a);
void sub_021C952C(void *a);

BOOL sub_021C94E0(void *a, void *b)
{
    sub_021C952C(b);
    return sub_020307B0(b);
}
