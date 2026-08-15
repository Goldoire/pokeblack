/*
 * Overlay 16 -- Wi-Fi Connection setup applet, access-point context.
 *
 * !! COMPILER: this translation unit matches with tools/mwccarm/2.0/sp2p2,
 * !! NOT the repo default tools/mwccarm/dsi/1.1.  The two differ in whether a
 * !! global's address is hoisted into a callee-saved register across a call
 * !! (dsi/1.1 hoists, 2.0 re-materialises the literal-pool load each time --
 * !! the ROM re-materialises).  Same MWCFLAGS otherwise.
 */
#include "types.h"

void sub_021B61C0(void *param0);
u32 sub_021B89C8(s32 param0);
void sub_021B8240(void *dst, u32 val, u32 size);

/* Overlay .data, initialised { .unk04 = -1, .unk08 = -1 } */
typedef struct UnkStruct021DAAB4 {
    s32 unk00;
    s32 unk04;
} UnkStruct021DAAB4;

/* Defined rather than extern for the same verifier reason as _021DAAA0 in
 * src/ov016/unk_021B6100.c: 0x021DAAB4 is .data inside a triaged extent. */
UnkStruct021DAAB4 _021DAAB4 = { -1, -1 };

/* Overlay .data.  unk04 / unk0C are heap-owned blocks released through the
 * indirect free hook in sub_021B61C0; unk24..unk3F is the access-point
 * descriptor handed to the DWC connection code (0xC0A80B01 == 192.168.11.1). */
typedef struct UnkStruct021DC040 {
    u32 unk00;
    void *unk04;
    u32 unk08;
    void *unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    void *unk24;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
    u32 unk34;
    u32 unk38;
    u8 unk3C;
    u8 unk3D;
    u8 unk3E;
    u8 unk3F;
} UnkStruct021DC040;

extern UnkStruct021DC040 _021DC040;
extern u8 _021DCDA0[8];

typedef struct UnkStruct021B6D1C {
    u16 unk00;
    u8 unk02;
    u8 unk03;
    u16 unk04;
    u8 unk06[32];
} UnkStruct021B6D1C;

void sub_021B6CF0(void)
{
    if (_021DC040.unk0C != NULL) {
        sub_021B61C0(_021DC040.unk0C);
        _021DC040.unk0C = NULL;
    }

    if (_021DC040.unk04 != NULL) {
        sub_021B61C0(_021DC040.unk04);
        _021DC040.unk04 = NULL;
    }
}

void sub_021B6D1C(UnkStruct021B6D1C *param0)
{
    sub_021B8240(_021DCDA0, 0, 8);
    _021DC040.unk10 = 1;
    sub_021B8240(&_021DC040.unk24, 0, 0x1C);
    _021DC040.unk24 = param0->unk06;
    _021DC040.unk28 = param0->unk04;
    _021DC040.unk2C = param0->unk00 & 0xF;
    _021DC040.unk3D = param0->unk02;
    _021DC040.unk30 = 0;
    _021DC040.unk34 = 0xC0A80B01;
    _021DC040.unk3C = 0;
}

u32 sub_021B7098(s32 param0)
{
    if (param0 == -1) {
        _021DAAB4.unk04 = param0;
        return 0;
    }

    if (_021DAAB4.unk04 != param0) {
        _021DAAB4.unk04 = param0;
        return sub_021B89C8(param0);
    }

    return 0;
}

void sub_021B6D74(u32 param0)
{
    _021DC040.unk10 = param0;
}

u32 sub_021B6D80(void)
{
    return _021DC040.unk10;
}
