#include "types.h"

typedef struct UnkStruct020067A4
{
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ u32 unk08;
    /* 0x0C */ u32 unk0C;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u8 unk14[8];
    /* 0x1C */ u8 unk1C;
    /* 0x1D */ u8 unk1D;
    /* 0x1E */ u8 unk1E[2];
    /* 0x20 */ u32 unk20;
    /* 0x24 */ u32 unk24;
    /* 0x28 */ u8 unk28;
    /* 0x29 */ u8 unk29[3];
    /* 0x2C */ u32 unk2C;
} UnkStruct020067A4;

void sub_020067A4(UnkStruct020067A4 *a0)
{
    a0->unk08 = 0;
    a0->unk0C = 0x3443;
    a0->unk1C = 0;
    a0->unk1D = 0;
    a0->unk20 = 0x64E1;
    a0->unk24 = 0;
    a0->unk28 = 0x40;
    a0->unk2C = 0;
    a0->unk10 = a0->unk04;
}
