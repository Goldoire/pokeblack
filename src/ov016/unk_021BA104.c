/*
 * Overlay 16 -- Wi-Fi Connection setup applet, packet builder.
 *
 * !! COMPILER: tools/mwccarm/2.0/sp2p2, NOT the repo default dsi/1.1.
 */
#include "types.h"

u8 *sub_021BA0A4(u8 *param0);

s32 sub_021BA104(u8 *param0)
{
    u8 *end;

    param0[0] = 0;
    param0[1] = 0;
    param0[2] = 0;
    param0[3] = 0;
    param0[4] = 0;
    param0[5] = 0;
    param0[6] = 0;
    param0[7] = 0;

    end = sub_021BA0A4(param0 + 8);
    *(u16 *)param0 = (u16)(end - param0 - 8);
    return end - param0;
}
