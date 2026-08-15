#include "types.h"

// ov093 0x021e357c..0x021e36bc: per-effect wrapper
// shells and count/table getters.

void sub_021D7040(void *a0);
u32 sub_021D775C(int a0);

void sub_021E357C(void *a0, void *a1, int a2)
{
    if (a2 == sub_021D775C(2)) {
        sub_021D7040(a0);
    }
}

void sub_021E36A4(void *a0, void *a1, int a2)
{
    if (a2 == sub_021D775C(2)) {
        sub_021D7040(a0);
    }
}

