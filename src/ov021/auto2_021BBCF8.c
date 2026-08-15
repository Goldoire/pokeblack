#include "types.h"

BOOL sub_020307B0(void *a);
void sub_021BBD64(void *a);
void sub_021BBFB4(void *a);

BOOL sub_021BBCF8(void *a, void *b)
{
    sub_021BBD64(b);
    return sub_020307B0(b);
}

BOOL sub_021BBF9C(void *a, void *b)
{
    sub_021BBFB4(b);
    return sub_020307B0(b);
}
