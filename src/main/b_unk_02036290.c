#include "types.h"

typedef struct UnkStruct02036290_sub {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
    u32 unk34;
    u32 unk38;
    u32 unk3C;
    u32 unk40;
    u32 unk44;
} UnkStruct02036290_sub;

typedef struct UnkStruct02036290 {
    UnkStruct02036290_sub *unk00;
    u8 pad04[0x39];
    u8 unk3D;
} UnkStruct02036290;

UnkStruct02036290_sub *sub_0203521C(UnkStruct02036290 *a);
UnkStruct02036290 *sub_02035224(void);

void sub_02036290(UnkStruct02036290 *a, u32 v);
u32 sub_020362BC(UnkStruct02036290 *a);
u32 sub_020362EC(UnkStruct02036290 *a);
u32 sub_0203631C(UnkStruct02036290 *a);
void sub_0203634C(UnkStruct02036290 *a, u32 *x, u32 *y);

void sub_02036290(UnkStruct02036290 *a, u32 v)
{
    UnkStruct02036290_sub *p = sub_0203521C(a);

    p->unk00 = v;
}

void sub_020362A4(u32 v)
{
    sub_02036290(sub_02035224(), v);
}

u32 sub_020362BC(UnkStruct02036290 *a)
{
    UnkStruct02036290_sub *p = sub_0203521C(a);

    if (a->unk3D == 0x1E) {
        return p->unk28;
    }
    return p->unk1C;
}

u32 sub_020362DC(void)
{
    return sub_020362BC(sub_02035224());
}

u32 sub_020362EC(UnkStruct02036290 *a)
{
    UnkStruct02036290_sub *p = sub_0203521C(a);

    if (a->unk3D == 0x1E) {
        return p->unk24;
    }
    return p->unk18;
}

u32 sub_0203630C(void)
{
    return sub_020362EC(sub_02035224());
}

u32 sub_0203631C(UnkStruct02036290 *a)
{
    UnkStruct02036290_sub *p = sub_0203521C(a);

    if (a->unk3D == 0x1E) {
        return p->unk2C;
    }
    return p->unk20;
}

u32 sub_0203633C(void)
{
    return sub_0203631C(sub_02035224());
}

void sub_0203634C(UnkStruct02036290 *a, u32 *x, u32 *y)
{
    UnkStruct02036290_sub *p = sub_0203521C(a);

    *x = p->unk40;
    *y = p->unk44;
}

void sub_02036370(u32 *x, u32 *y)
{
    sub_0203634C(sub_02035224(), x, y);
}

void sub_02036390(UnkStruct02036290 *a)
{
    UnkStruct02036290_sub *p = sub_0203521C(a);

    p->unk24 = 0;
    p->unk28 = 0;
    p->unk2C = 0;
    p->unk30 = 0;
    p->unk34 = 0;
    p->unk38 = 0;
}

void sub_020363B8(UnkStruct02036290 *a, u32 x, u32 y)
{
    UnkStruct02036290_sub *p = sub_0203521C(a);

    p->unk28 = y;
    p->unk1C = x;
}

void sub_020363D4(UnkStruct02036290 *a, u32 x, u32 y)
{
    UnkStruct02036290_sub *p = sub_0203521C(a);

    p->unk24 = y;
    p->unk18 = x;
}

void sub_020363F0(UnkStruct02036290 *a, u32 x, u32 y)
{
    UnkStruct02036290_sub *p = sub_0203521C(a);

    p->unk2C = y;
    p->unk20 = x;
}
