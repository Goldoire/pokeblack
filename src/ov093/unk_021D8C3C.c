#include "types.h"

// ov093 0x021d8c3c..0x021d8ca0: per-effect wrapper
// shells and count/table getters.

void sub_021D8CAC(void *a0, void *a1, int a2);

void sub_021D8C3C(void *a0, void *a1, void *a2)
{
    sub_021D8CAC(a1, a2, 9);
}

void sub_021D8C58(void *a0, void *a1, void *a2)
{
    sub_021D8CAC(a1, a2, 10);
}

void sub_021D8C74(void *a0, void *a1, void *a2)
{
    sub_021D8CAC(a1, a2, 11);
}

void sub_021D8C90(void *a0, void *a1, void *a2)
{
    sub_021D8CAC(a1, a2, 6);
}

