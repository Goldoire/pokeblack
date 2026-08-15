#include "types.h"

typedef struct UnkStruct02036B98_entry {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u16 unk0C;
    u16 unk0E;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
} UnkStruct02036B98_entry;

typedef struct UnkStruct02036B98 {
    u8 pad00[0x18];
    UnkStruct02036B98_entry *unk18;
    s32 unk1C;
} UnkStruct02036B98;

typedef struct UnkStruct02036D64 {
    u32 unk00;
    u16 unk04;
    u16 unk06;
    u32 unk08;
    u8 unk0C;
    u8 unk0D;
    u8 unk0E;
    u8 unk0F;
    u32 unk10;
} UnkStruct02036D64;

extern const char _020A79F0[];
extern const char _020A79FC[];

void sub_02080C24(void);
void sub_02080C64(void);
void sub_02034714(const char *file, int line, const char *msg);
void *sub_02030734(u32 heap, u32 size, u32 c, const char *file, u32 line);
void sub_02036F24(u32 a, u32 b, u32 c);
u32 sub_02036D64(UnkStruct02036D64 *p);
u32 sub_02036DC8(u32 mode, u32 v);

typedef struct Unk021469C8 {
    u16 unk00;
    u16 unk02 : 14;
    u16 unk02hi : 2;
} Unk021469C8;
extern Unk021469C8 _021469C8;

u32 sub_02036B98(UnkStruct02036B98 *p, u32 id)
{
    s32 i;
    UnkStruct02036B98_entry *e = p->unk18;

    for (i = 0; i < p->unk1C; i++) {
        if (e->unk0E == id) {
            return 1;
        }
        e++;
    }
    return 0;
}

u32 sub_02036D64(UnkStruct02036D64 *p)
{
    switch (p->unk0D) {
    case 1:
        if (((*(u16 *)0x04000304 & 0x8000) >> 15) == 1) {
            return 1;
        }
        return 2;
    case 2:
        if (((*(u16 *)0x04000304 & 0x8000) >> 15) == 1) {
            return 2;
        }
        return 1;
    }
    return 1;
}

u32 sub_02036DC8(u32 mode, u32 v)
{
    s32 reg;

    if (mode == 1) {
        sub_02080C24();
        reg = *(u32 *)0x04000000 & 0x00300010;
    } else {
        sub_02080C64();
        reg = *(u32 *)0x04001000 & 0x00300010;
    }
    switch (reg) {
    case 0x00000010:
        return v * 4;
    case 0x00100010:
        return v * 2;
    case 0x00200010:
        return v;
    case 0x00300010:
        break;
    }
    sub_02034714(_020A79F0, 0xFB, _020A79FC);
    return v;
}

void sub_02036E74(u32 *p, s32 v)
{
    if (v < 4) {
        *p = v;
    }
}

UnkStruct02036D64 *sub_02036BD4(u32 unused0, u32 a1, u32 a2, u32 a3, u32 p5,
                                UnkStruct02036D64 *o, u32 p7, u32 p8, u32 p9)
{
    if (o == NULL) {
        o = sub_02030734((u16)(((u16)a1 & 0x7FFF) | 0x8000), 0x14, 0, _020A79F0, 0x64);
    }
    o->unk04 = a2;
    o->unk06 = a3;
    if (_021469C8.unk00 != 0) {
        o->unk04 = _021469C8.unk00;
        o->unk06 = _021469C8.unk02;
    }
    o->unk00 = p9;
    o->unk0C = p5;
    o->unk0E = p8;
    o->unk0D = p7;
    o->unk0F = 0;
    o->unk10 = 0x7000000;
    sub_02036F24(sub_02036D64(o), o->unk0C, (u16)a1);
    return o;
}

void sub_02036CA8(UnkStruct02036D64 *o)
{
    u32 d = sub_02036D64(o);
    u32 x = sub_02036DC8(d, o->unk00);
    u32 *oam;
    u32 *q;

    if (d == 1) {
        oam = (u32 *)0x07000000;
    } else {
        oam = (u32 *)0x07000400;
    }
    if (o->unk0F == 1) {
        oam[0] = (o->unk06 & 0xFF) | 0x800 | 0x40000000 | ((o->unk04 & 0x1FF) << 16);
        *(u16 *)((u8 *)oam + 4) = x | 0xE000;
    } else {
        oam[0] = 0x40000200;
        *(u16 *)((u8 *)oam + 4) = 0;
    }
    oam[2] = (o->unk06 & 0xFF) | 0x40000000 | ((o->unk04 & 0x1FF) << 16);
    *(u16 *)((u8 *)oam + 0xC) = x | 0xE000;
    if (oam != (u32 *)o->unk10) {
        q = (u32 *)o->unk10;
        q[0] = 0x40000200;
        *(u16 *)((u8 *)q + 4) = 0;
        q = (u32 *)o->unk10;
        q[2] = 0x40000200;
        *(u16 *)((u8 *)q + 0xC) = 0;
        o->unk10 = (u32)oam;
    }
}
