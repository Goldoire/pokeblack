#include "types.h"

// ov093 0x021d99c8..0x021d9bbc: per-effect wrapper
// shells and count/table getters.

void sub_021D76BC(int a0, int a1);
u32 sub_021D775C(int a0);

void sub_021D99C8(void *a0, void *a1, int a2)
{
    if (a2 == sub_021D775C(4)) {
        sub_021D76BC(65, 1);
    }
}

void sub_021D99E0(void *a0, void *a1, int a2)
{
    if (a2 == sub_021D775C(4)) {
        sub_021D76BC(71, 1);
    }
}

void sub_021D9A44(void *a0, void *a1, int a2)
{
    if (a2 == sub_021D775C(3)) {
        sub_021D76BC(69, 1);
    }
}

void sub_021D9BA4(void *a0, void *a1, int a2)
{
    if (a2 == sub_021D775C(4)) {
        sub_021D76BC(65, 1);
    }
}

