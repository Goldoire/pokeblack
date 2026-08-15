#include "types.h"

// ov093 0x021d8940..0x021d8964: per-effect wrapper
// shells and count/table getters.

u32 sub_021D775C(int a0);
void sub_021D8974(void *a0, void *a1, int a2, int a3);

void sub_021D8940(void *a0, void *a1, int a2, int a3)
{
    if (a2 == sub_021D775C(2)) {
        sub_021D8974(a0, a1, a2, a3);
    }
}

