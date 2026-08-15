#include "types.h"

typedef struct UnkStruct020360B8_entry {
    u32 unk00;
    u32 unk04;
    u8 unk08;
    u8 unk09;
    u8 unk0A;
    u8 unk0B;
} UnkStruct020360B8_entry;

typedef struct UnkStruct020360B8 {
    UnkStruct020360B8_entry *unk00;
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
} UnkStruct020360B8;

void *sub_02035224(void);
void sub_02035F38(void *sys);
UnkStruct020360B8 *sub_0203521C(void *sys);
void sub_02036254(void *sys, u32 a, u32 b);

void sub_020360A8(void)
{
    sub_02035F38(sub_02035224());
}

void sub_020360B8(UnkStruct020360B8 *p)
{
    UnkStruct020360B8_entry *e;

    if (p->unk00 == NULL) {
        return;
    }
    e = p->unk00 + p->unk08;
    while (TRUE) {
        switch (e->unk08) {
        case 0:
            return;
        case 1:
            if ((p->unk1C & e->unk00) != 0) {
                p->unk1C |= e->unk04;
            }
            if ((p->unk18 & e->unk00) != 0) {
                p->unk18 |= e->unk04;
            }
            if ((p->unk20 & e->unk00) != 0) {
                p->unk20 |= e->unk04;
            }
            break;
        case 2:
        {
            u32 t = 0;
            if ((p->unk1C & e->unk00) != 0) {
                t |= e->unk04;
            }
            if ((p->unk1C & e->unk04) != 0) {
                t |= e->unk00;
            }
            p->unk1C &= (e->unk00 | e->unk04) ^ 0xFFFF;
            p->unk1C |= t;
        }
        {
            u32 t = 0;
            if ((p->unk18 & e->unk00) != 0) {
                t |= e->unk04;
            }
            if ((p->unk18 & e->unk04) != 0) {
                t |= e->unk00;
            }
            p->unk18 &= (e->unk00 | e->unk04) ^ 0xFFFF;
            p->unk18 |= t;
        }
        {
            u32 t = 0;
            if ((p->unk20 & e->unk00) != 0) {
                t |= e->unk04;
            }
            if ((p->unk20 & e->unk04) != 0) {
                t |= e->unk00;
            }
            p->unk20 &= (e->unk00 | e->unk04) ^ 0xFFFF;
            p->unk20 |= t;
        }
            break;
        case 3:
            p->unk1C &= e->unk00 ^ 0xFFFF;
            p->unk18 &= e->unk00 ^ 0xFFFF;
            p->unk20 &= e->unk00 ^ 0xFFFF;
            break;
        }
        e++;
    }
}

void sub_02036254(void *sys, u32 a, u32 b)
{
    UnkStruct020360B8 *p = sub_0203521C(sys);

    p->unk40 = a;
    p->unk44 = b;
}

void sub_02036270(u32 a, u32 b)
{
    sub_02036254(sub_02035224(), a, b);
}
