#include "types.h"

// ov093 0x021db430..0x021db4e8: per-effect wrapper
// shells and count/table getters.

u32 sub_021DA8A8(void *a0, void *a1, int a2);
void sub_021DA96C(void *a0, void *a1, int a2, int a3);

void sub_021DB430(void *a0, void *a1, void *a2)
{
    if (sub_021DA8A8(a1, a2, 10) != 0) {
        sub_021DA96C(a1, a2, 3, 1);
    }
}

void sub_021DB4C4(void *a0, void *a1, void *a2)
{
    if (sub_021DA8A8(a1, a2, 12) != 0) {
        sub_021DA96C(a1, a2, 3, 1);
    }
}

