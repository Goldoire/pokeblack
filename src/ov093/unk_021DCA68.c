#include "types.h"

// ov093 0x021dca68..0x021dca8c: per-effect wrapper
// shells and count/table getters.

u32 sub_021DA8A8(void *a0, void *a1, int a2);
void sub_021DA96C(void *a0, void *a1, int a2, int a3);

void sub_021DCA68(void *a0, void *a1, void *a2)
{
    if (sub_021DA8A8(a1, a2, 11) != 0) {
        sub_021DA96C(a1, a2, 1, 1);
    }
}

