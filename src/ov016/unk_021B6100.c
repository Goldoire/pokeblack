#include "types.h"

/* Overlay 16 is the Nintendo Wi-Fi Connection setup ("RAP" access-point
 * utility) applet, not battle code.  The debug string the heap allocator is
 * handed below is literally "dwc_raputil.c", which names this translation
 * unit in the retail build. */

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

/* "dwc_raputil.c" */
extern const char _021DAAA0[];

/* Linker-absolute overlay id (the SDK's FS_OVERLAY_ID idiom): the symbol's
 * *address* is the overlay number, so it always materialises through the
 * literal pool rather than as a MOV immediate.  Overlay 107 == 0x6B. */
extern u32 _0000006B[];

extern void (*_021DCE20)(u32 param0);
extern void (*_021DCE2C)(u32 param0);

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

void sub_021B61B0(u32 param0)
{
    _021DCE20(param0);
}

void sub_021B61C0(u32 param0)
{
    _021DCE2C(param0);
}
