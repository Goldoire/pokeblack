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

/* overlay rodata: the empty string used as the assert text below */
extern const char _021A1C5C[];

/* ov009 / net_devwifi.c */
void sub_02155374(u32 state);

/* ARM9 */
void sub_02034714(const char *param0, int param1, const char *param2);
void sub_02082BCC(void *dst, u8 value, u32 size); /* MI_CpuFill8 */
void sub_02082D44(const void *src, void *dst, u32 size); /* MI_CpuCopy8 */
u8 *sub_0203D798(void);

/* elsewhere in ov009 */
u32 sub_0216B908(void);
u32 sub_02176FD4(u32 param0, const void *param1, u32 param2);
u32 sub_0216B838(void);
void sub_0216B65C(void);
int sub_02177270(u8 param0, int param1);
BOOL sub_0215610C(void);
void sub_02156344(u16 param0);
void sub_021AEF6C(u16 param0, int param1, int param2);
void sub_021AF18C(void *param0);
extern const u8 _0215631D[];  /* sub_0215631C */

/* ov021 */
void sub_021AF13C(void);
void sub_021AF1A0(void);
void sub_021AF2AC(u32 param0);
void sub_021AF30C(u8 param0);
extern const u8 _021AF211[];  /* sub_021AF210 */
void sub_02156BD8(int param0);
u16 sub_02157108(u16 param0);
void sub_02156E30(int param0, int param1, int param2, int param3);
void *sub_0203D650(void);
void sub_02034AC4(u32 overlayId);
void sub_02034A5C(u32 overlayId);
/* NitroSDK FS_OVERLAY_ID(x) is the *address* of the linker-defined symbol
 * SDK_OVERLAY_x_ID, so an overlay id reaches the code as an ABS32 relocation
 * rather than an immediate.  This one resolves to 17. */
extern u8 _00000011[];
void sub_021B6100(void);
void sub_021688FC(void *param0, int param1);
int sub_0209C0A4(int numerator, int denominator); /* signed divide helper */
void sub_0216AE88(void);
void sub_021554C8(void);
void sub_0216B7E0(u8 param0);
void sub_021567B8(void);
void sub_021AEE14(int param0);
BOOL sub_021AF238(u32 param0, u32 param1);
int sub_02155F58(void);
void sub_02156CF4(void);
void sub_02155C70(void);

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

    sub_02082D44(param0, _021A8264 + 4, param1);
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

void sub_02155C28(u32 param0, u32 param1)
{
    int i;

    sub_0203D798();

    for (i = 0; i < 32; i++) {
        if (*(s32 *)(_021A8264 + i * 4 + 0x17C) == -1) {
            *(u32 *)(_021A8264 + i * 4 + 0x17C) = param0;
            *(u32 *)(_021A8264 + i * 4 + 0x1FC) = param1;
        }
    }
}

void sub_02155C6C(void)
{
}

void sub_02155C70(void)
{
    sub_02082BCC(_021A8264 + 0x784, 0, 8);
}

void sub_02155C8C(void)
{
    int i;
    int v0;

    for (i = 0; i < 2; i++) {
        sub_02177270((u8)i, 0);
    }

    v0 = 0;

    if (sub_0216B838() == 0) {
        while (v0 < *(s32 *)(_021A8264 + 0x764)) {
            if (v0 != sub_0216B838() && (sub_0216B908() & (1 << v0))) {
                if (sub_02177270((u8)v0, 10000) == 0) {
                    sub_02034714(_021A1C5C, 0, _021A1C5C);
                }
            }

            v0++;
        }
    } else if (sub_02177270((u8)v0, 10000) == 0) {
        sub_02034714(_021A1C5C, v0, _021A1C5C);
    }

    _021A8264[0x7A8] = 1;
    sub_02155C70();
}

void sub_02155D2C(int param0)
{
#pragma unused(param0)
    sub_02155374(9);
    sub_02155C8C();
}

BOOL sub_02155D7C(void)
{
    return TRUE;
}

void sub_02155D80(u32 param0, u32 param1)
{
#pragma unused(param0)
    if (param1 < 2) {
        *(u32 *)(_021A8264 + 0x760) = 0;
        *(u32 *)(_021A8264 + 0x784 + param1 * 4) = 0;
    }
}

void sub_02155DA4(u32 param0)
{
    if (param0 & 0x100) {
        *(u32 *)(_021A8264 + 0x790) = 1;
    } else {
        *(u32 *)(_021A8264 + 0x790) = 0;
    }
}

BOOL sub_0215615C(u32 param0)
{
    if (*(u32 *)(_021A8264 + 0x760) == 0 && sub_0215610C()
        && (sub_0216B908() & 0xFFFE)) {
        *(u32 *)(_021A8264 + 0x760) = 1;
        *(u32 *)_021A8264 = 2 | (*(u16 *)(_021A8264 + 0x794) << 8);

        sub_02176FD4(sub_0216B908(), _021A8264, 4);
        *(u32 *)(_021A8264 + param0 * 4 + 0x784) = 0;

        return TRUE;
    }

    return FALSE;
}

int sub_021562EC(void)
{
    if (_021A8264 != NULL) {
        u32 v0 = *(u32 *)(_021A8264 + 0x754);

        if (v0 == 9 || v0 == 10 || v0 == 18) {
            return sub_0216B838();
        }
    }

    return -1;
}

void sub_0215631C(void)
{
    *(u32 *)(_021A8264 + 0x76C) = 0;
}

void sub_02156330(void)
{
    *(u16 *)(_021A8264 + 0x794) = 1;
}

void sub_021563C0(void)
{
    void *v0 = sub_0203D798();

    sub_02156344(*(u16 *)((u8 *)v0 + 0x56));
}

void sub_021563D0(void)
{
    if (*(u32 *)(_021A8264 + 0x76C) != 0) {
        sub_021AF13C();
    }
}

u32 sub_021563EC(void)
{
    return *(u32 *)(_021A8264 + 0x76C);
}

void sub_02156400(void)
{
    sub_021AF1A0();

    if (_021A8264 != NULL) {
        *(u32 *)(_021A8264 + 0x76C) = 0;
        *(u32 *)(_021A8264 + 0x768) = 0;
        *(u16 *)(_021A8264 + 0x794) = 0;
    }
}

void sub_0215642C(BOOL param0)
{
    if (param0) {
        sub_021AF2AC(sub_0216B838());
        _021A8264[0x79F] = 1;
    } else {
        _021A8264[0x79F] = 0;
    }

    sub_021AF30C(_021A8264[0x79F]);
}

BOOL sub_02156730(void)
{
    u32 v0 = *(u32 *)(_021A8264 + 0x754);

    if (v0 == 19 || v0 == 20 || v0 == 16 || v0 == 6) {
        sub_02155374(6);
        *(u32 *)(_021A8264 + 0x758) = 1007;
        *(s32 *)(_021A8264 + 0x774) = -1;
        return TRUE;
    }

    return FALSE;
}

void sub_02156B18(int param0, int param1, int param2, int param3, int param4)
{
#pragma unused(param2, param3)
    *(u32 *)(_021A8264 + 0x778) = 0;

    if (param0 == 0 && param1 == 0) {
        sub_02155D2C(param4);
    }
}

void sub_02156B3C(u32 param0)
{
    *(u32 *)(_021A8264 + 0x774) = param0;

    if (*(u32 *)(_021A8264 + 0x29C) != 0) {
        (*(void (**)(u16, u32))(_021A8264 + 0x29C))(
            (u16)param0, *(u32 *)(_021A8264 + 0x2A0));
    }
}

void sub_02156B68(void)
{
    ((void (*)(void))_021AF211)();
}

s16 sub_02156B70(void)
{
    if (_021A8264 != NULL) {
        return *(s16 *)(_021A8264 + 0x782);
    }

    return 0;
}

u32 sub_02156B8C(void)
{
    if (_021A8264 != NULL) {
        return *(u32 *)(_021A8264 + 0x774);
    }

    return 0;
}

s16 sub_02156BA8(void)
{
    if (_021A8264 != NULL) {
        return *(s16 *)(_021A8264 + 0x780);
    }

    return -1;
}

void sub_02156BC4(u16 param0)
{
    *(u16 *)(_021A8264 + 0x782) = param0;
}

void sub_02156C60(void)
{
    int i;

    for (i = 0; i < 2; i++) {
        sub_02156BD8(i);
    }

    _021A8264[0x7A6] = 1;
}

u8 sub_02156C84(void)
{
    return _021A8264[0x7A2];
}

void sub_02156C98(void)
{
    _021A8264[0x7A2] = 0;
}

BOOL sub_02156CAC(void)
{
    if (_021A8264 != NULL) {
        if (*(u32 *)(_021A8264 + 0x754) == 6) {
            return TRUE;
        }

        return FALSE;
    }

    return FALSE;
}

BOOL sub_02156CD0(void)
{
    if (_021A8264 != NULL) {
        u32 v0 = *(u32 *)(_021A8264 + 0x754);

        if (v0 == 9 || v0 == 10) {
            return TRUE;
        }
    }

    return FALSE;
}

void sub_02156CF4(void)
{
    int i;

    for (i = 0; i < 32; i++) {
        if (*(s32 *)(_021A8264 + i * 4 + 0x17C) != -1) {
            u8 *v0 = sub_0203D798();

            if (*(u32 *)(v0 + 0x3C) != 0) {
                (*(void (**)(u32, u32, void *))(v0 + 0x3C))(
                    *(u32 *)(_021A8264 + i * 4 + 0x17C),
                    *(u32 *)(_021A8264 + i * 4 + 0x1FC),
                    sub_0203D650());
            }

            *(s32 *)(_021A8264 + i * 4 + 0x17C) = -1;
        }
    }
}

u32 sub_02156D5C(void)
{
    return *(u32 *)(_021A8264 + 0x758);
}

void sub_02156D70(u8 param0)
{
    _021A8264[0x7A5] = param0;
}

BOOL sub_02156D84(void)
{
    u32 v0;

    if (_021A8264 == NULL) {
        return TRUE;
    }

    v0 = *(u32 *)(_021A8264 + 0x754);

    if (v0 == 19 || v0 == 16 || v0 == 20) {
        return TRUE;
    }

    return FALSE;
}

void sub_02156DB0(u8 param0)
{
    _021A8264[0x7A3] = param0;
}

void sub_02156DC4(void *param0, void *param1)
{
    *(void **)(_021A8264 + 0x28C) = param0;
    *(void **)(_021A8264 + 0x290) = param1;
}

void sub_02156DE0(void *param0, void *param1)
{
    *(void **)(_021A8264 + 0x294) = param0;
    *(void **)(_021A8264 + 0x298) = param1;
}

void sub_02156DFC(int param0)
{
    if (sub_02157108(param0) == 3) {
        sub_02034AC4((u32)_00000011);
        sub_021B6100();
        sub_02034A5C((u32)_00000011);
    }
}

void sub_02156E24(int param0, int param1, int param2)
{
    sub_02156E30(param0, param1, 0, param2);
}

void sub_02155648(void *param0, void *param1)
{
    *(void **)(_021A8264 + 0x27C) = param0;
    *(void **)(_021A8264 + 0x280) = param1;
}

void sub_02155664(void *param0)
{
    *(void **)(_021A8264 + 0x2A4) = param0;
}

void sub_02155674(void)
{
}

u8 sub_02155678(void)
{
    return _021A8264[0x7A5];
}

void sub_0215683C(void *param0, int param1)
{
    if (param1 > 32) {
        sub_02034714(_021A1C5C, 0, _021A1C5C);
    }

    sub_021688FC(param0, param1);
}

u8 *sub_02156860(u32 param0)
{
    return _021A8264 + 0x34C + param0 * 32;
}

u8 sub_02156874(u32 param0)
{
    return _021A8264[param0 + 0x32C];
}

/* Maps a DWC/GameSpy numeric error code (param0) plus an error class
 * (param1) onto the game's own error-screen id. */
int sub_02156460(int param0, int param1)
{
    int v0 = sub_0209C0A4(param0, 100);
    int v1 = sub_0209C0A4(param0, 1000);

    if (param0 == 20101) {
        return 1;
    }

    if (v1 == 23) {
        return 1;
    }

    if (param0 == 20108) {
        return 2;
    }

    if (param0 == 20110) {
        return 3;
    }

    if (v0 == 512) {
        return 4;
    }

    if (v0 == 500) {
        return 5;
    }

    if (param0 == 51103) {
        return 6;
    }

    if (v0 == 510) {
        return 6;
    }

    if (v0 == 511) {
        return 6;
    }

    if (v0 == 513) {
        return 6;
    }

    if (param0 >= 52000 && param0 <= 52003) {
        return 8;
    }

    if (param0 >= 52010 && param0 <= 52012) {
        return 8;
    }

    if (param0 >= 52100 && param0 <= 52103) {
        return 8;
    }

    if (param0 >= 52110 && param0 <= 52112) {
        return 8;
    }

    if (param0 >= 52200 && param0 <= 52203) {
        return 8;
    }

    if (param0 >= 52210 && param0 <= 52212) {
        return 8;
    }

    if (param0 >= 52400 && param0 <= 52403) {
        return 8;
    }

    if (param0 >= 52410 && param0 <= 52412) {
        return 8;
    }

    if (param0 >= 52500 && param0 <= 52503) {
        return 8;
    }

    if (param0 >= 52510 && param0 <= 52512) {
        return 8;
    }

    if (param0 >= 52700 && param0 <= 52703) {
        return 8;
    }

    if (param0 >= 52710 && param0 <= 52712) {
        return 8;
    }

    if (param0 == 80430) {
        return 9;
    }

    if (v1 == 20) {
        return 0;
    }

    if (v0 == 520) {
        return 0;
    }

    if (v0 == 521) {
        return 0;
    }

    if (v0 == 522) {
        return 0;
    }

    if (v0 == 523) {
        return 0;
    }

    if (v0 == 530) {
        return 0;
    }

    if (v0 == 531) {
        return 0;
    }

    if (v0 == 532) {
        return 0;
    }

    if (param0 < 10000) {
        return 14;
    }

    if (v1 == 31) {
        return 12;
    }

    switch (param1) {
    case 0:
    case 1:
        return 14;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        return 11;
    default:
        sub_02034714(_021A1C5C, 0, _021A1C5C);
        break;
    case 7:
        return 15;
    }

    return -1;
}

int sub_021561C0(void)
{
    int i;
    u32 v0;
    int v1;

    sub_02156CF4();
    sub_0216AE88();
    sub_021567B8();

    if (*(u32 *)(_021A8264 + 0x76C) != 0) {
        if (*(u16 *)(_021A8264 + 0x794) == 1 && *(u32 *)(_021A8264 + 0x790) == 1
            && *(u16 *)(_021A8264 + 0x796) == 1) {
            sub_021AEE14(0);
        } else {
            sub_021AEE14(1);
        }

        if (*(u32 *)(_021A8264 + 0x768) != sub_0216B908()
            && _021A8264[0x79F] == 0 && *(s16 *)(_021A8264 + 0x782) != 0) {
            if (sub_021AF238(sub_0216B908(), sub_0216B838())) {
                *(u32 *)(_021A8264 + 0x768) = sub_0216B908();
            }
        }
    }

    v0 = *(u32 *)(_021A8264 + 0x754);

    if (v0 == 20) {
        v1 = sub_02155F58();

        if (v1 == 0) {
            return 1003;
        }

        return v1;
    }

    if (v0 == 19) {
        return 1004;
    }

    if (v0 == 9 || v0 == 10) {
        for (i = 0; i < *(s32 *)(_021A8264 + 0x764); i++) {
            if ((*(s32 *)(_021A8264 + i * 4 + 0x784))++ >= 240
                && *(u32 *)(_021A8264 + 0x760) == 0 && sub_0215615C(i)) {
                sub_02155C70();
                break;
            }
        }
    }

    return sub_02155F58();
}

void sub_02156A58(int param0, int param1, int param2, int param3, int param4)
{
#pragma unused(param3)
    int v0 = 0;

    *(u32 *)(_021A8264 + 0x778) = 0;

    if (param0 == 0) {
        if (param1 == 0) {
            if (_021A8264[0x7A4] != 0 && param4 == -1) {
                v0 = 1;
            }

            if (*(u32 *)(_021A8264 + 0x2A4) != 0) {
                if ((*(int (**)(int, void *))(_021A8264 + 0x2A4))(
                        param4, sub_0203D650()) == 0) {
                    v0 = 1;
                }
            }

            if (_021A8264[0x7A0] != 0 || v0) {
                if (param4 != -1) {
                    sub_0216B7E0((u8)param4);
                }
            }

            *(u32 *)(_021A8264 + 0x770) = param4;
            *(u32 *)(_021A8264 + 0x798) = sub_0216B908();

            if (*(u32 *)(_021A8264 + 0x798) == 1) {
                sub_02155374(8);
            } else {
                sub_02155D2C(param4);
            }
        } else if (param2 == 0) {
            *(u16 *)(_021A8264 + 0x780) = (u16)param4;
            *(s32 *)(_021A8264 + 0x774) = -1;
        }
    }
}

void sub_02156344(u16 param0)
{
    int v0;

    *(u16 *)(_021A8264 + 0x794) = 1;
    *(u32 *)(_021A8264 + 0x790) = 1;
    *(u16 *)(_021A8264 + 0x796) = 1;

    if (*(u32 *)(_021A8264 + 0x76C) != 0) {
        return;
    }

    switch (*(u32 *)(_021A8264 + 0x77C)) {
    case 2:
        v0 = 1;
        break;
    case 3:
        v0 = 2;
        break;
    case 4:
        v0 = 3;
        break;
    case 5:
        v0 = 4;
        break;
    case 0:
    case 1:
    default:
        v0 = 4;
        break;
    }

    sub_021AEF6C(param0, v0, 1);
    sub_021AF18C((void *)_0215631D);

    *(u32 *)(_021A8264 + 0x76C) = 1;
}
