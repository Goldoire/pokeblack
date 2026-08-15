#include "types.h"

// ov093 0x021da808..0x021da838: per-effect wrapper
// shells and count/table getters.

void sub_021D76BC(int a0, int a1);
u32 sub_021D775C(int a0);

void sub_021DA808(void *a0, void *a1, int a2)
{
    if (a2 == sub_021D775C(4)) {
        sub_021D76BC(81, 1);
    }
}

void sub_021DA820(void *a0, void *a1, int a2)
{
    if (a2 == sub_021D775C(3)) {
        sub_021D76BC(81, 1);
    }
}

