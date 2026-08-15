#include "types.h"

/* NOT YET on include/ov170.h.  The fields this file names at panel+0x68 /
 * +0x6C fall inside the Ov170Anim embedded at +0x58, where the shared header
 * still has only `u8 filler_10[0x08]`.  Reaching them would mean punning
 * through that filler, which is worse than the private struct below and would
 * silently survive the integrator naming those two words.  Move this file over
 * once Ov170Anim has real members at +0x10 (u32) and +0x14 (void *).
 * panel+0x60 in the sibling files is already `anim.unk08`. */

typedef struct Ov170Panel {
    u8 unk00[0x58];
    u32 (*unk58)(void *);
    u8 unk5c[0x68 - 0x5c];
    u32 unk68;
    void *unk6c;
    u8 unk70[0xA188 - 0x70];
    u32 unkA188;
    u32 unkA18C;
} Ov170Panel;

typedef struct Ov170Ctx {
    u8 unk00[8];
    u32 unk08;
    u8 unk0c[0x12 - 0x0c];
    u8 unk12;
    u8 unk13[0x28 - 0x13];
    u32 unk28;
    Ov170Panel *unk2c;
} Ov170Ctx;

/* 12-byte dispatch records at 0x021EFA28. */
typedef struct Ov170Handler {
    void (*unk00)(Ov170Ctx *);
    void (*unk04)(Ov170Ctx *);
    u32 unk08;
} Ov170Handler;

/* The rodata tables this file reads live inside the 7376-byte blob that
 * build/reference/triage.json records as a *function* at 0x021EF770.  Because
 * of that, verify_functions.py's new "undefined symbol inside a Thumb extent
 * must be a function" rule ORs bit 0 into any relocation that names one of
 * them, so an `extern const ... _021EFA28[];` declaration no longer verifies.
 * Spelling the tables as absolute addresses keeps every byte checked (no
 * relocation at all).  Switch back to named externs once triage marks
 * 0x021EF770 as data.
 */
extern const Ov170Handler _021EFA28[];

u32 sub_020221A4(Ov170Ctx *a0);
u32 sub_02021ED8(void *a0);
u32 sub_021DCFC0(Ov170Ctx *a0);

u32 sub_021E2020(Ov170Ctx *a0)
{
    if (sub_020221A4(a0) == 1) {
        return a0->unk2c->unkA188;
    }
    return 2;
}

u32 sub_021E203C(Ov170Ctx *a0)
{
    if (sub_02021ED8(a0->unk2c->unk6c) == 0) {
        return a0->unk28;
    }
    return 3;
}

u32 sub_021E2054(Ov170Ctx *a0)
{
    Ov170Panel *p = a0->unk2c;

    if (p->unkA18C == 0) {
        return a0->unk28;
    }
    p->unkA18C = p->unkA18C - 1;
    return 4;
}

u32 sub_021E2070(Ov170Ctx *a0)
{
    if (a0->unk2c->unk58 != NULL) {
        if (a0->unk2c->unk58(a0) == 0) {
            a0->unk2c->unk58 = NULL;
            return a0->unk2c->unk68;
        }
    }
    return 5;
}

u32 sub_021E2140(Ov170Ctx *a0)
{
    if (sub_021DCFC0(a0) == 0) {
        return a0->unk28;
    }
    return 8;
}

u32 sub_021E2154(Ov170Ctx *a0)
{
    _021EFA28[a0->unk12].unk00(a0);
    return 0xA;
}

u32 sub_021E216C(Ov170Ctx *a0)
{
    if (a0->unk08 != 1) {
        _021EFA28[a0->unk12].unk04(a0);
        a0->unk28 = _021EFA28[a0->unk12].unk08;
        return 0;
    }
    return 0xA;
}
