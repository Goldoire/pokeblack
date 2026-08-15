#include "types.h"

/*
 * ov009 / net_devwifi.c  --  0x02155160 .. 0x02155398
 *
 * The __FILE__ string handed to the heap allocator in sub_02155168 is
 * "net_devwifi.c" (ov009 rodata 0x021A1C4C), which names this translation
 * unit.  The module publishes a table of ~52 function pointers at 0x021A1B80
 * (returned by sub_0215536C); most of the entries are the one-line forwarders
 * below, which mwcc compiles to `ldr r3,=target; bx r3` tail-call thunks.
 *
 * NOTE ON THE THUNKS: verify_functions.py only sets the Thumb low bit on an
 * ABS32 relocation when the target symbol is STT_FUNC, and mwcc types every
 * *undefined* symbol NOTYPE -- so `return sub_0215592C(p);` relocates to an
 * even address and misses by one byte.  Naming the Thumb entry point by its
 * odd address (_<ram+1>) reproduces the linker's encoding exactly.  Each
 * `_0215592D`-style declaration below is really just `sub_0215592C`; once
 * those addresses are in the claim table with a real STT_FUNC symbol the
 * plain call form can replace them.
 */

/* --- overlay .bss (starts at 0x021A8260) --- */
extern void *_021A8260;  /* net_devwifi work block, 8 bytes, allocated below */
extern u8 *_021A8264;    /* dwc_rap work block; +0x27C/+0x280/+0x2A4/+0x754/+0x7A5 */

/* --- overlay .rodata --- */
extern const u8 _021A1B80[];    /* exported function-pointer table */
extern const char _021A1C4C[];  /* "net_devwifi.c" */

/* --- ARM9 --- */
void *sub_02030734(u32 heapId, u32 size, u32 param2, const char *file, int line);
void *sub_0203D798(void);

/* --- elsewhere in ov009 --- */
void sub_02155648(void *param0, void *param1);
BOOL sub_0215568C(int param0, int param1, int param2, int param3);
void sub_0215592C(void *param0);
BOOL sub_02155B14(u32 param0, u32 param1, u32 param2);
int sub_021562EC(void);
BOOL sub_02156690(BOOL param0);
void sub_02156730(void);
u8 sub_02156874(u32 param0);
void sub_0216B908(void);

/* Thumb entry points of forwarding targets (see NOTE ON THE THUNKS). */
extern const u8 _0215592D[];  /* sub_0215592C */
extern const u8 _02155389[];  /* sub_02155388 */
extern const u8 _021562ED[];  /* sub_021562EC */
extern const u8 _02156889[];  /* sub_02156888 */
extern const u8 _02156B71[];  /* sub_02156B70 */
extern const u8 _02156B8D[];  /* sub_02156B8C */
extern const u8 _02156CAD[];  /* sub_02156CAC */
extern const u8 _02156CD1[];  /* sub_02156CD0 */
extern const u8 _02156D71[];  /* sub_02156D70 */
extern const u8 _02156DB1[];  /* sub_02156DB0 */
extern const u8 _02156DFD[];  /* sub_02156DFC */

u32 sub_02156D84(void);
void sub_02157048(u32 param0, u32 param1);

void sub_02155160(void)
{
    ((void (*)(void))_02156DFD)();
}

BOOL sub_02155168(u32 heapId, void *param1)
{
    void *v0;

    if (_021A8260 != NULL) {
        return FALSE;
    }

    v0 = sub_0203D798();
    sub_02157048(*(u16 *)((u8 *)v0 + 0x58), *(u32 *)((u8 *)v0 + 0x48));

    _021A8260 = sub_02030734(heapId, 8, 1, _021A1C4C, 186);
    *(void **)_021A8260 = param1;

    return TRUE;
}

void sub_021551D4(void *param0)
{
    ((void (*)(void *))_0215592D)(param0);
}

BOOL sub_021551DC(void *param0)
{
    if (sub_02156690(param0 == NULL)) {
        sub_02156730();
        return TRUE;
    }

    sub_0215592C(param0);
    return TRUE;
}

BOOL sub_02155234(int param0, int param1, int param2, int param3)
{
    return sub_0215568C(param0, param1, param2, param3);
}

void sub_0215523C(void)
{
    ((void (*)(void))_02156889)();
}

BOOL sub_02155244(void *param0)
{
    if (sub_02156690(param0 == NULL)) {
        sub_02156730();
        return TRUE;
    }

    return FALSE;
}

BOOL sub_02155264(u32 param0, u32 param1, u32 param2, void (*param3)(int))
{
    if (sub_02155B14(param0, param1, param2)) {
        if (param3 != NULL) {
            param3(1);
        }

        return TRUE;
    }

    return FALSE;
}

BOOL sub_02155280(void *param0)
{
    sub_02155648(param0, param0);
    return TRUE;
}

void sub_0215528C(void)
{
    ((void (*)(void))_02155389)();
}

BOOL sub_02155294(void)
{
    if (sub_021562EC() == -1) {
        return FALSE;
    }

    return TRUE;
}

u32 sub_021552AC(void)
{
    u32 v0 = sub_02156D84();

    if (!sub_02155388()) {
        v0 |= 1;
    }

    return v0;
}

void sub_021552C4(void)
{
    ((void (*)(void))_02156CAD)();
}

void sub_021552CC(void)
{
    sub_0216B908();
}

void sub_021552D4(void)
{
    ((void (*)(void))_021562ED)();
}

void sub_02155330(void)
{
    ((void (*)(void))_02156DB1)();
}

BOOL sub_02155338(u32 param0)
{
    if (sub_02156874(param0) == 6) {
        return TRUE;
    }

    return FALSE;
}

void sub_0215534C(void)
{
    ((void (*)(void))_02156B71)();
}

void sub_02155354(void)
{
    ((void (*)(void))_02156B8D)();
}

void sub_0215535C(void)
{
    ((void (*)(void))_02156D71)();
}

void sub_02155364(void)
{
    ((void (*)(void))_02156CD1)();
}

const u8 *sub_0215536C(void)
{
    return _021A1B80;
}

void sub_02155374(u32 param0)
{
    *(u32 *)(_021A8264 + 0x754) = param0;
}

BOOL sub_02155388(void)
{
    if (_021A8264 != NULL) {
        return TRUE;
    }

    return FALSE;
}
