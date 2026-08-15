#include "types.h"

// ov093 0x021d8e58..0x021d8e7c: per-effect wrapper
// shells and count/table getters.

u32 sub_021D775C(int a0);
void sub_021D8E1C(void *a0, void *a1, int a2, int a3);

void sub_021D8E58(void *a0, void *a1, int a2, int a3)
{
    if (a2 == sub_021D775C(2)) {
        sub_021D8E1C(a0, a1, a2, a3);
    }
}

