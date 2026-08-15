#include "types.h"

/* Same 0x020AA260 record as src/main/a_unk_02005B24.c; only +0x0C (the
 * argument handed to the worker thread) and +0x14 (the live OSThread, NULL
 * when none) are touched here. _020AA354 is that OSThread and _020AA9B4 is
 * the stack it runs on -- the same block sub_02005B24 gives the allocator. */
typedef struct Unk020AA260
{
    /* 0x00 */ u8 unk00[0x0C];
    /* 0x0C */ void *unk0C;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ void *unk14;
} Unk020AA260;

extern Unk020AA260 _020AA260;
extern u8 _020AA354[];
extern u8 _020AA9B4[];

/* 0x020062D8 / 0x020062EC, both Thumb; triage.json has no entry for either,
 * so the +1 interworking bit the ROM stores in the OS_CreateThread argument
 * only comes out right when the Thumb entry point is named directly. */
void sub_020062D9(void *arg);
void sub_020062ED(void *arg);

void sub_020853C0(void *thread, void (*func)(void *), void *arg, void *stack,
                  u32 stackSize, u32 prio);
void sub_02085868(void *thread);
int sub_0208574C(void *thread);
void sub_020855BC(void *thread);
void sub_02006368(void);

void sub_02006300(void *a0, int a1)
{
    _020AA260.unk0C = a0;
    sub_02006368();
    switch (a1)
    {
    case 0:
        sub_020853C0(_020AA354, sub_020062D9, &_020AA260.unk0C, _020AA9B4,
                     0x400, 0x11);
        break;
    case 1:
        sub_020853C0(_020AA354, sub_020062ED, &_020AA260.unk0C, _020AA9B4,
                     0x400, 0x11);
        break;
    }
    sub_02085868(_020AA354);
    _020AA260.unk14 = _020AA354;
}

void sub_02006368(void)
{
    if (_020AA260.unk14 != NULL)
    {
        if (sub_0208574C(_020AA354) == 0)
        {
            sub_020855BC(_020AA354);
            _020AA260.unk14 = NULL;
        }
    }
}
