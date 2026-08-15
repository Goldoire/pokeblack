#include "types.h"

// ov093 0x021ea3d4..0x021ea40c: per-effect wrapper
// shells and count/table getters.

u32 sub_021F7EB4(void *a0);

int sub_021EA3D4(void *a0)
{
    if (sub_021F7EB4(a0) == 0) {
        return 1;
    }
    return 0;
}

int sub_021EA3F8(void *a0)
{
    if (sub_021F7EB4(a0) == 0) {
        return 1;
    }
    return 0;
}

