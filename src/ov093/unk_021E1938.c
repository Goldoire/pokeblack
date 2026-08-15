#include "types.h"

// ov093 0x021e1938..0x021e19e0: per-effect wrapper
// shells and count/table getters.

void sub_021E19F8(void *a0, void *a1, int a2, int a3);
void sub_021E1A2C(void *a0, void *a1, int a2, int a3);

void sub_021E1938(void *a0, void *a1, void *a2, int a3)
{
    sub_021E19F8(a1, a2, a3, 1);
}

void sub_021E1948(void *a0, void *a1, void *a2, int a3)
{
    sub_021E1A2C(a1, a2, a3, 1);
}

void sub_021E197C(void *a0, void *a1, void *a2, int a3)
{
    sub_021E19F8(a1, a2, a3, 2);
}

void sub_021E198C(void *a0, void *a1, void *a2, int a3)
{
    sub_021E1A2C(a1, a2, a3, 2);
}

void sub_021E19C0(void *a0, void *a1, void *a2, int a3)
{
    sub_021E19F8(a1, a2, a3, 0);
}

void sub_021E19D0(void *a0, void *a1, void *a2, int a3)
{
    sub_021E1A2C(a1, a2, a3, 0);
}

