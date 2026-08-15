#include "types.h"

BOOL sub_020307B0(void *a);
void sub_021ADD38(void *a);
void sub_021ADF68(void *a);

BOOL sub_021ADCDC(void *a, void *b)
{
    sub_021ADD38(b);
    return sub_020307B0(b);
}

BOOL sub_021ADF00(void *a, void *b)
{
    sub_021ADF68(b);
    return sub_020307B0(b);
}
