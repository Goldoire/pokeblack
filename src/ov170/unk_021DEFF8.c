#include "types.h"

typedef struct Ov170Panel {
    u8 unk00[4];
} Ov170Panel;

typedef struct Ov170Ctx {
    u8 unk00[0x14];
    u8 unk14;
    u8 unk15[0x2c - 0x15];
    Ov170Panel *unk2c;
} Ov170Ctx;

u32 sub_02017DBC(void *a0);
void sub_02017DE4(void *a0, u32 a1);
void *sub_021DD2D0(Ov170Ctx *a0, u32 a1, u32 a2);
u32 sub_021DEDD8(void *a0);
void sub_021DEF58(u32 a0);
void sub_021EB2A4(Ov170Ctx *a0, u32 a1);
void sub_021ECCCC(Ov170Ctx *a0, u32 a1, u32 a2);
void sub_021ED028(Ov170Panel *a0, u32 a1);

void sub_021DEFF8(Ov170Ctx *a0, u32 a1)
{
    void *p;
    u32 sav;
    u32 v;

    p = sub_021DD2D0(a0, a0->unk14, a1);
    sav = sub_02017DBC(p);
    v = sub_021DEDD8(p);
    sub_021ECCCC(a0, v, 0xB);
    sub_021ED028(a0->unk2c, v);
    sub_021EB2A4(a0, v);
    sub_021DEF58(v);
    sub_02017DE4(p, sav);
}
