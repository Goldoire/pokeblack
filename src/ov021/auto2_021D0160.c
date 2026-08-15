#include "types.h"

BOOL sub_020307B0(void *a);
void sub_021D01D8(void *a);
void sub_021D0440(void *a);
void sub_021D06E0(void *a);

BOOL sub_021D0160(void *a, void *b)
{
    sub_021D01D8(b);
    return sub_020307B0(b);
}

BOOL sub_021D03B0(void *a, void *b)
{
    sub_021D0440(b);
    return sub_020307B0(b);
}

BOOL sub_021D0634(void *a, void *b)
{
    sub_021D06E0(b);
    return sub_020307B0(b);
}
