#include "types.h"

// ov093 0x021daeac..0x021daec4: per-effect wrapper
// shells and count/table getters.

void sub_021D7324(void *a0);
u32 sub_021D775C(int a0);

void sub_021DAEAC(void *a0, void *a1, int a2)
{
    if (a2 == sub_021D775C(2)) {
        sub_021D7324(a0);
    }
}

