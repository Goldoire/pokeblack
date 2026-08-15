#include "types.h"

// ov093 0x021ea7e8..0x021ea7fc: per-effect wrapper
// shells and count/table getters.

u32 sub_021F7EB4(void *a0);

int sub_021EA7E8(void *a0)
{
    if (sub_021F7EB4(a0) == 0) {
        return 1;
    }
    return 0;
}

