#include "types.h"

/*
 * ov009 / dwc_rap.c  --  0x0215539C .. 0x02156E2C
 *
 * Named after the __FILE__ string "dwc_rap.c" (ov009 rodata 0x021A1C60) that
 * sub_0215539C and sub_02156C00 hand to the heap allocator.
 *
 * Everything in here hangs off the module work block pointed to by the bss
 * word at 0x021A8264.  Byte offsets recovered so far:
 *      +0x000  u32   outgoing packet header (id | seq<<8)
 *      +0x002  u8    sequence number mirror
 *      +0x004  u8[]  outgoing packet payload
 *      +0x27C  fn    callback A (set by sub_02155648)
 *      +0x280  fn    callback B (set by sub_02155648) - (aid, src, u16 size)
 *      +0x2A4  fn    callback C (set by sub_02155664)
 *      +0x754  u32   state / step, written only through sub_02155374
 *      +0x758  u32   error code
 *      +0x760  u32   "send in flight" flag
 *      +0x774  s32   -1 on disconnect
 *      +0x794  u16   local aid, shifted into the packet header
 *      +0x79C  u8    outgoing sequence counter
 *      +0x7A2  u8    flag set once the socket has been shut down
 *      +0x7A5  u8    queried by sub_02155678
 *      +0x7A6  u8    "may send" gate
 *      +0x7A7  u8    "disconnect pending" gate
 *      +0x7A8  u8    connected flag
 */

extern u8 *_021A8264;

/* ov009 / net_devwifi.c */
void sub_02155374(u32 state);

/* ARM9 */
void MI_CpuCopy8(const void *src, void *dst, u32 size);

/* elsewhere in ov009 */
u32 sub_0216B908(void);
u32 sub_02176FD4(u32 param0, const void *param1, u32 param2);
u32 sub_0216B838(void);
void sub_0216B65C(void);

void sub_02155904(void)
{
    if (*(u32 *)(_021A8264 + 0x754) == 12) {
        sub_02155374(13);
    } else {
        sub_02155374(11);
    }
}

BOOL sub_02155A80(const void *param0, int param1, u32 param2)
{
    u16 v0;

    if (param1 >= 0x100) {
        return FALSE;
    }

    if (*(u32 *)(_021A8264 + 0x760) != 0) {
        return FALSE;
    }

    *(u32 *)_021A8264 = param2 | (*(u16 *)(_021A8264 + 0x794) << 8);
    _021A8264[0x79C]++;
    _021A8264[2] = _021A8264[0x79C];

    MI_CpuCopy8(param0, _021A8264 + 4, param1);
    *(u32 *)(_021A8264 + 0x760) = 1;

    v0 = sub_0216B908();

    if (v0 != sub_02176FD4(v0, _021A8264, param1 + 4)) {
        *(u32 *)(_021A8264 + 0x760) = 0;
        return FALSE;
    }

    return TRUE;
}

BOOL sub_02155B00(const void *param0, int param1)
{
    if (sub_02155A80(param0, param1, 3)) {
        return TRUE;
    }

    return FALSE;
}

BOOL sub_02155B14(const void *param0, u32 param1, u32 param2)
{
    if (_021A8264[0x7A6] == 0) {
        return FALSE;
    }

    if (!sub_02155A80(param0, param1, 1)) {
        return FALSE;
    }

    _021A8264[0x7A6] = 0;

    if (*(u32 *)(_021A8264 + 0x280) != 0) {
        (*(void (**)(u32, const void *, u16))(_021A8264 + 0x280))(
            sub_0216B838(), param0, (u16)param1);
    }

    return TRUE;
}

void sub_02155B68(void)
{
    u32 v0;

    if (_021A8264[0x7A7] != 0) {
        v0 = 0;

        if (sub_02155B00(&v0, 4)) {
            _021A8264[0x7A7] = 0;
        }
    }
}

void sub_02155BDC(u32 param0)
{
    if (param0 < 2 && _021A8264[0x7A8] != 0) {
        sub_0216B65C();
        *(s32 *)(_021A8264 + 0x774) = -1;
        sub_02155374(20);
    }
}

void sub_02155C0C(int param0)
{
    if (param0 == 0) {
        sub_02155374(6);
    } else {
        sub_02155374(14);
    }
}

void sub_02155C24(void)
{
}
