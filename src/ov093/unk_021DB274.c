#include "types.h"

// ov093 0x021db274..0x021db298: per-effect wrapper
// shells and count/table getters.

u32 sub_021D775C(int a0);
void sub_021DB254(void *a0, void *a1, int a2, int a3);

void sub_021DB274(void *a0, void *a1, int a2, int a3)
{
    if (a2 == sub_021D775C(2)) {
        sub_021DB254(a0, a1, a2, a3);
    }
}

