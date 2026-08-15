#include "types.h"

BOOL sub_020307B0(void *a);
void sub_021C483C(void *a);
void sub_021C4A00(void *a);
void sub_021C4BC4(void *a);

BOOL sub_021C47E8(void *a, void *b)
{
    sub_021C483C(b);
    return sub_020307B0(b);
}

BOOL sub_021C49AC(void *a, void *b)
{
    sub_021C4A00(b);
    return sub_020307B0(b);
}

BOOL sub_021C4B50(void *a, void *b)
{
    sub_021C4BC4(b);
    return sub_020307B0(b);
}
