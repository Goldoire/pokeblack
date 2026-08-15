#include "types.h"

// ov093 0x021e0838..0x021e0850: per-effect wrapper
// shells and count/table getters.

void sub_021D7324(void *a0);
u32 sub_021D775C(int a0);

void sub_021E0838(void *a0, void *a1, int a2)
{
    if (a2 == sub_021D775C(3)) {
        sub_021D7324(a0);
    }
}

