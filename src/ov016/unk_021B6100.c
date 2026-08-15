/*
 * Overlay 16 -- Nintendo Wi-Fi Connection setup ("RAP" access-point utility)
 * applet.  This is NOT battle code; the debug string handed to the heap
 * allocator in sub_021B6100 is literally "dwc_raputil.c", which names the
 * retail translation unit this range came from.
 *
 * COMPILER: this file matches with the repo default,
 *     python tools/scripts/cc.py src/ov016/unk_021B6100.c --thumb
 * i.e. tools/mwccarm/dsi/1.1.  The rest of the overlay does NOT -- see
 * src/ov016/unk_021B6CF0.c, which needs tools/mwccarm/2.0/sp2p2.
 */
#include "types.h"

#define reg_OS_IME (*(REGType16v *)0x04000208)

void sub_021B6100(u32 param0);
void sub_02087BCC(u32 param0);
void sub_0203064C(u32 param0, u32 param1, u32 param2);
void sub_0200F17C(u32 param0);
void sub_02034AC4(u32 param0);
u32 sub_02087988(void);
void sub_0208799C(u32 param0);
void *sub_02030734(u32 param0, u32 param1, u32 param2, const char *file, u16 line);
BOOL sub_02085D3C(void);
void sub_021C0970(void *param0, u32 param1, u32 param2);
void sub_020307B0(void *param0);

/* 0x021DAAA0.  Defined rather than declared extern: the verifier's
 * enclosing-extent heuristic reads this .rodata address as the inside of a
 * triaged thumb function and would set bit 0 in the literal.  A local
 * definition emits identical code and a section-relative relocation. */
static const char _021DAAA0[] = "dwc_raputil.c";

/* Linker-absolute overlay id (the SDK's FS_OVERLAY_ID idiom): the symbol's
 * *address* is the overlay number, so it always materialises through the
 * literal pool rather than as a MOV immediate.  Overlay 107 == 0x6B. */
extern u32 _0000006B[];

extern void (*_021DCE20)(void *param0);
extern void (*_021DCE2C)(void *param0);

void sub_021B6100(u32 param0)
{
    u32 intrMode;
    void *heap;

    intrMode = sub_02087988();
    heap = sub_02030734(param0, 0x40000, 1, _021DAAA0, 61);

    if (sub_02085D3C() == 0) {
        sub_021C0970(heap, 1, 0);
    }

    sub_020307B0(heap);
    sub_0208799C(intrMode);

    {
        u16 prep = reg_OS_IME;
        reg_OS_IME = 1;
    }
}

BOOL sub_021B6154(void *param0, void *param1)
{
    sub_0203064C(1, 15, 0x40100);
    sub_0200F17C(1);
    sub_02034AC4((u32)_0000006B);
    return TRUE;
}

BOOL sub_021B6178(void *param0, void *param1)
{
    sub_021B6100(15);
    return TRUE;
}

BOOL sub_021B6184(void *param0, void *param1)
{
    sub_02087BCC(0);
    return TRUE;
}

void sub_021B61B0(void *param0)
{
    _021DCE20(param0);
}

void sub_021B61C0(void *param0)
{
    _021DCE2C(param0);
}
