#include "types.h"

extern u32 _020A9E80;

int sub_020392B8(void);
int sub_0203D26C(void);
int sub_0203D29C(void);
int sub_020351D0(int a0);
int sub_02005420(void);
void sub_02005428(void);

#define reg_EXMEMCNT (*(volatile u16 *)0x04000204)

int sub_020051D8(void)
{
    if (sub_020392B8() > 1)
    {
        return 0;
    }
    if (sub_0203D26C() != 0)
    {
        return 0;
    }
    if (sub_0203D29C() == 0)
    {
        return 1;
    }
    return 0;
}

void sub_020053EC(void)
{
    if (_020A9E80 == 0)
    {
        return;
    }
    if (sub_020351D0(2) != 0)
    {
        return;
    }
    if (sub_02005420() != 0)
    {
        return;
    }
    reg_EXMEMCNT |= 0x8000;
    sub_02005428();
}
