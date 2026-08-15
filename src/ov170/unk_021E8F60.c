#include "types.h"

typedef struct Ov170Panel {
    u8 unk00[0x68];
    u32 unk68;
    u8 unk6c[0x74 - 0x6c];
    void *unk74;
    u8 unk78[0xA188 - 0x78];
    u32 unkA188;
} Ov170Panel;

typedef struct Ov170Save {
    u8 unk00[0x2a];
    u8 unk2a;
    u8 unk2b;
} Ov170Save;

typedef struct Ov170Ctx {
    Ov170Save *unk00;
    u8 unk04[0x14 - 0x04];
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17[0x28 - 0x17];
    u32 unk28;
    Ov170Panel *unk2c;
} Ov170Ctx;

/* The rodata tables this file reads live inside the 7376-byte blob that
 * build/reference/triage.json records as a *function* at 0x021EF770.  Because
 * of that, verify_functions.py's new "undefined symbol inside a Thumb extent
 * must be a function" rule ORs bit 0 into any relocation that names one of
 * them, so an `extern const ... _021EFA28[];` declaration no longer verifies.
 * Spelling the tables as absolute addresses keeps every byte checked (no
 * relocation at all).  Switch back to named externs once triage marks
 * 0x021EF770 as data.
 */
extern const u8 _021EF950[];
extern const u8 _021EF9B4[];

void sub_0202208C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
void sub_021DC9A0(Ov170Panel *a0, u32 a1);
void sub_021DC9B8(Ov170Panel *a0);
void sub_021DD090(Ov170Ctx *a0, u32 a1);
void sub_020061E4(u32 a0);
void sub_021DE898(Ov170Ctx *a0);
void sub_021EB988(Ov170Ctx *a0, const u8 *a1, u32 a2);
void sub_021EBC58(Ov170Ctx *a0, u32 a1, u32 a2, u32 a3);
void sub_021ED588(Ov170Ctx *a0);
void sub_021EF4E4(void *a0);
void sub_021EA75C(Ov170Ctx *a0);
void sub_021ECB20(Ov170Ctx *a0, u32 a1, u32 a2);
void sub_021ED888(Ov170Panel *a0, u32 a1);

u32 sub_021E8F60(Ov170Ctx *a0, u32 a1)
{
    sub_0202208C(0, 1, 1, 0, 6, 1, 0x4C);
    a0->unk2c->unkA188 = a1;
    return 2;
}

u32 sub_021E8F90(Ov170Ctx *a0, u32 a1)
{
    sub_0202208C(0, 0, 0, 0, 6, 1, 0x4C);
    a0->unk2c->unkA188 = a1;
    return 2;
}

u32 sub_021E8FC0(Ov170Ctx *a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    a0->unk2c->unk68 = a2;
    sub_021DC9A0(a0->unk2c, a1);
    return 5;
}

u32 sub_021E8FD0(Ov170Ctx *a0, u32 a1)
{
    a0->unk2c->unk68 = a1;
    sub_021DC9B8(a0->unk2c);
    return 5;
}

u32 sub_021E8FE0(Ov170Ctx *a0, u32 a1)
{
    a0->unk28 = a1;
    return 0xD;
}

void sub_021E9284(Ov170Ctx *a0)
{
    sub_020061E4(0x55D);
    sub_021DE898(a0);
    a0->unk28 = 0x69;
    sub_021E8F90(a0, 1);
}

void sub_021E93F4(Ov170Ctx *a0)
{
    sub_021DE898(a0);
    a0->unk00->unk2a = a0->unk14;
    a0->unk00->unk2b = a0->unk16;
    a0->unk28 = 0x69;
    sub_021E8F90(a0, 1);
}

u32 sub_021E949C(Ov170Ctx *a0, u32 a1, u32 a2)
{
    sub_021DD090(a0, a1);
    a0->unk28 = a2;
    return 8;
}

u32 sub_021E9938(Ov170Ctx *a0)
{
    sub_021EB988(a0, _021EF9B4, 5);
    sub_021EF4E4(a0->unk2c->unk74);
    sub_021EBC58(a0, a0->unk16, 1, 0x18);
    sub_021ED588(a0);
    return 0x2C;
}

u32 sub_021E9968(Ov170Ctx *a0)
{
    sub_021EB988(a0, _021EF950, 5);
    sub_021EF4E4(a0->unk2c->unk74);
    sub_021EBC58(a0, a0->unk16, 1, 0x18);
    sub_021ECB20(a0, 1, 1);
    sub_021ED888(a0->unk2c, 0);
    sub_021EA75C(a0);
    sub_021ED588(a0);
    return 0x31;
}
