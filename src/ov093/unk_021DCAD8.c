#include "types.h"

// ov093 0x021dcad8..0x021dcae8: per-effect wrapper
// shells and count/table getters.

void sub_021E8744(void *a0, void *a1, int a2, int a3);
void sub_021E8798(void *a0, void *a1, int a2, int a3);

void sub_021DCAD8(void *a0, void *a1, int a2, int a3)
{
    sub_021E8744(a0, a1, a2, a3);
}

void sub_021DCAE0(void *a0, void *a1, int a2, int a3)
{
    sub_021E8798(a0, a1, a2, a3);
}

