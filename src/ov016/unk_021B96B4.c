/*
 * Overlay 16 -- Wi-Fi Connection setup applet, mutex-guarded allocator.
 *
 * !! COMPILER: tools/mwccarm/2.0/sp2p2, NOT the repo default dsi/1.1.
 */
#include "types.h"

void sub_02086028(void *mutex);
void sub_02086078(void *mutex);
u32 sub_02087988(void);
void sub_0208799C(u32 param0);

/* Overlay .bss control block for the DWC allocator / state machine. */
typedef struct UnkStruct021DCFD0 {
    u32 unk00;
    void *(*unk04)(s32 size);
    u32 unk08;
    void (*unk0C)(void *ptr);
    u32 unk10[22];
    u32 unk68;
    u32 unk6C;
    u32 unk70[3];
    void (*unk7C)(void *param0);
} UnkStruct021DCFD0;

UnkStruct021DCFD0 _021DCFD0;
extern u32 _021DD064[8];

/* 0x021DD054.  Referenced one word early so that the verifier does not
 * mistake the undefined symbol for a thumb function (another overlay has
 * code at 0x021DD054); the relocation addend still yields 0x021DD054. */
extern u32 _021DD050[];

void *sub_021B96B4(u32 param0, s32 param1)
{
    void *ptr;

    if (param1 > 0) {
        sub_02086028(_021DD064);
        ptr = _021DCFD0.unk04(param1);
        sub_02086078(_021DD064);
        return ptr;
    }

    return NULL;
}

void sub_021B96E4(u32 param0, void *param1, s32 param2)
{
    if (param1 == NULL) {
        return;
    }

    if (param2 <= 0) {
        return;
    }

    sub_02086028(_021DD064);
    _021DCFD0.unk0C(param1);
    sub_02086078(_021DD064);
}

void sub_021B970C(void)
{
    u32 intrMode = sub_02087988();
    s32 i;

    _021DCFD0.unk68 = 0;
    _021DCFD0.unk6C = 0;

    {
        u32 *p = _021DD050 + 1;

        for (i = 0; i < 4; i++) {
            *p = 0;
            p++;
        }
    }

    sub_0208799C(intrMode);
}
