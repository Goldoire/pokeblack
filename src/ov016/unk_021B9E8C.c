/*
 * Overlay 16 -- Wi-Fi Connection setup applet, text/window helpers.
 *
 * !! COMPILER: tools/mwccarm/2.0/sp2p2, NOT the repo default dsi/1.1.
 */
#include "types.h"

s32 sub_0215F5B4(u32 param0, u32 param1, u32 param2, u32 param3, u32 param4);
void sub_02087C6C(void *param0);

s32 sub_021B9E8C(u32 param0, u32 param1, u32 param2, u32 param3, u32 param4)
{
    s32 result = sub_0215F5B4(param0, param3, param4, 0, param1);

    if (result < 0) {
        return -4;
    }

    return result;
}

BOOL sub_021BA2EC(void *param0)
{
    sub_02087C6C(param0);
    return TRUE;
}
