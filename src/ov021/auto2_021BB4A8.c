#include "types.h"

BOOL sub_020307B0(void *a);
void sub_021BB504(void *a);

BOOL sub_021BB4A8(void *a, void *b)
{
    sub_021BB504(b);
    return sub_020307B0(b);
}
