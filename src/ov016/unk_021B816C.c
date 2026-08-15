/*
 * Overlay 16 -- Wi-Fi Connection setup applet, allocator / callback shims.
 *
 * !! COMPILER: tools/mwccarm/2.0/sp2p2, NOT the repo default dsi/1.1.
 * !! See src/ov016/unk_021B6CF0.c for the evidence.
 */
#include "types.h"

void sub_0215F500(u32 param0, u32 param1, u32 param2, u32 param3, u8 *param4);

/* Overlay .bss: the applet's allocator hook table.
 *   _021DCE20[0] alloc(size)   _021DCE20[1] state-change notify(id)
 *   _021DCE2C   free(ptr)
 * _021DCE2C is referenced by its own address (offset 0) rather than as
 * _021DCE20[3], so it is a separate object in the retail source. */
extern void *(*_021DCE20[2])();
extern void (*_021DCE2C)(void *ptr);

void *sub_021B816C(void *param0, s32 param1)
{
    if (param1 > 0) {
        return _021DCE20[0](param1);
    }

    return NULL;
}

void sub_021B8184(void *param0, void *param1)
{
    _021DCE2C(param1);
}

void sub_021B824C(u32 param0, u32 param1, u32 param2, u32 param3, u8 *param4, u32 *param5)
{
    *param4 = (u8)*param5;
    sub_0215F500(param0, param1, param2, param3, param4);
}

u32 sub_021B89C8(s32 param0)
{
    if (_021DCE20[1] != NULL) {
        _021DCE20[1](param0);
    }

    return 0;
}
