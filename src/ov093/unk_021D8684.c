#include "types.h"

// ov093 0x021d8684..0x021d869c: per-effect wrapper
// shells and count/table getters.

void sub_021D76BC(int a0, int a1);
u32 sub_021D775C(int a0);

void sub_021D8684(void *a0, void *a1, int a2)
{
    if (a2 == sub_021D775C(4)) {
        sub_021D76BC(65, 1);
    }
}

