/*
 * Overlay 16 -- Wi-Fi Connection setup applet, DWC request wrappers.
 *
 * !! COMPILER: tools/mwccarm/2.0/sp2p2, NOT the repo default dsi/1.1.
 */
#include "types.h"

void sub_021BBB98(void *param0);
void sub_021BBBC0(void *param0, u32 param1, u32 param2);
void sub_021BBC38(void *param0, void *param1);
void sub_021BC7B8(void *param0);

typedef struct UnkStruct021DCFD0 {
    u32 unk00[31];
    void (*unk7C)(void *param0);
} UnkStruct021DCFD0;

UnkStruct021DCFD0 _021DCFD0;

void sub_021BC55C(void *param0, u32 param1, u32 param2)
{
    u8 work[0x58];

    sub_021BBB98(work);
    sub_021BBBC0(work, param1, param2);
    sub_021BBC38(param0, work);
}

void sub_021BC804(void)
{
    u8 work[12];

    sub_021BC7B8(work);
    _021DCFD0.unk7C(work);
}
