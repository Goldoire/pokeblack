#include "types.h"

// ov093 0x021e5f18..0x021e6004: per-effect wrapper
// shells and count/table getters.

void sub_021D7040(void *a0);
void sub_021D76BC(int a0, int a1);
u32 sub_021D775C(int a0);

void sub_021E5F18(void *a0, void *a1, int a2)
{
    if (a2 == sub_021D775C(3)) {
        sub_021D76BC(81, 1);
    }
}

void sub_021E5F30(void *a0, void *a1, int a2)
{
    if (a2 == sub_021D775C(3)) {
        sub_021D76BC(66, 0);
    }
}

void sub_021E5FEC(void *a0, void *a1, int a2)
{
    if (a2 == sub_021D775C(2)) {
        sub_021D7040(a0);
    }
}

