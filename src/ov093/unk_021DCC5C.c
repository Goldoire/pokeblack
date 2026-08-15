#include "types.h"

// ov093 0x021dcc5c..0x021dcc80: per-effect wrapper
// shells and count/table getters.

u32 sub_021D775C(int a0);
void sub_021DCC80(void *a0, void *a1, int a2, int a3);

void sub_021DCC5C(void *a0, void *a1, int a2, int a3)
{
    if (a2 == sub_021D775C(2)) {
        sub_021DCC80(a0, a1, a2, a3);
    }
}

