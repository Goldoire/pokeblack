#include "types.h"

typedef struct Ov170Panel {
    u8 unk00[0x74];
    void *unk74;
    u8 unk78[0x3DF6 - 0x78];
    u8 unk3DF6;
    u8 unk3DF7[0xA180 - 0x3DF7];
    u32 unkA180;
    u32 unkA184;
} Ov170Panel;

typedef struct Ov170Ctx {
    u8 unk00[0x2c];
    Ov170Panel *unk2c;
} Ov170Ctx;

u32 sub_021E066C(Ov170Ctx *a0);
void sub_021EC08C(Ov170Panel *a0, u32 a1, s16 a2, s16 a3, u32 a4);
void sub_021EC0B0(Ov170Panel *a0, u32 a1, s16 *a2, s16 *a3, u32 a4);
void sub_021EC768(Ov170Panel *a0, u32 a1, u32 a2);
void sub_021ED544(Ov170Ctx *a0, u32 a1);
void sub_021ED14C(Ov170Panel *a0, s16 a1, s16 a2);
void sub_021ED310(Ov170Panel *a0);
u32 sub_021EF5C4(void *a0);

u32 sub_021E070C(Ov170Ctx *a0)
{
    if (sub_021E066C(a0) == 0 && sub_021EF5C4(a0->unk2c->unk74) == 0) {
        return 0;
    }
    return 1;
}

void sub_021E072C(Ov170Ctx *a0)
{
    s16 v[2];

    sub_021ED544(a0, 8);
    sub_021EC0B0(a0->unk2c, 4, &v[1], &v[0], 0);
    sub_021EC08C(a0->unk2c, a0->unk2c->unk3DF6, v[1], (s16)(v[0] + 4), 0);
    sub_021EC768(a0->unk2c, 0x24, 0);
}

void sub_021E0FB0(Ov170Panel *a0, u32 a1, u32 a2)
{
    sub_021ED14C(a0, (s16)a1, (s16)a2);
    sub_021ED310(a0);
    a0->unkA180 = a1;
    a0->unkA184 = a2;
}
