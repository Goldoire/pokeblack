#include "types.h"

// ov093 0x021d70e4..0x021d7108: per-effect wrapper
// shells and count/table getters.

void sub_021D7108(void *a0, void *a1, int a2, int a3);

void sub_021D70E4(void *a0, void *a1)
{
    sub_021D7108(a0, a1, 7, 0);
}

void sub_021D70F0(void *a0, void *a1)
{
    sub_021D7108(a0, a1, 7, 1);
}

void sub_021D70FC(void *a0, void *a1, int a2)
{
    sub_021D7108(a0, a1, a2, 1);
}

