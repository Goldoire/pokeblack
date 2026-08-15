#include "types.h"

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
