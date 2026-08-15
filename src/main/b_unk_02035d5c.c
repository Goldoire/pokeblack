#include "types.h"

typedef struct UnkStruct02035D5C {
    u8 pad00[0x0C];
    u8 unk0C[0x4C];
    u16 unk58;
    u16 unk5A;
    u16 unk5C;
    u16 unk5E;
    u16 unk60;
    u16 unk62;
    u16 unk64;
    u16 unk66;
    u16 unk68;
    u16 unk6A;
    u16 unk6C;
    u16 unk6E;
    u16 unk70;
    u16 unk72;
    u8 pad74;
    u8 unk75;
    u8 unk76;
} UnkStruct02035D5C;

typedef struct UnkStruct02035F38_pad {
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
} UnkStruct02035F38_pad;

typedef struct UnkStruct02035F38 {
    u8 pad00[0x3E];
    u8 unk3E;
} UnkStruct02035F38;

extern const char _020A799C[];

UnkStruct02035D5C *sub_02035750(void);
void *sub_02035224(void);
UnkStruct02035F38_pad *sub_0203521C(UnkStruct02035F38 *p);
void *sub_02030734(u32 heap, u32 size, u32 c, const char *file, u32 line);
void sub_02082BCC(void *dst, u8 val, u32 size);
void sub_0208AD14(void);
void sub_0208B220(u32 a);
u32 sub_0208B238(u32 a);
void sub_0208AC0C(u32 a, u32 b, void *c, u32 d);
void sub_020360B8(UnkStruct02035F38_pad *p);

u32 sub_02035D5C(UnkStruct02035D5C *s);
u32 sub_02035E18(UnkStruct02035D5C *s);
void sub_02035D98(void);
void sub_02035DD8(void);

u32 sub_02035D5C(UnkStruct02035D5C *s)
{
    if (s->unk58 == 0) {
        return 1;
    }
    sub_0208AD14();
    sub_0208B220(4);
    if (sub_0208B238(4) != 0) {
        return 2;
    }
    return 1;
}

void sub_02035D98(void)
{
    UnkStruct02035D5C *s = sub_02035750();

    if (s != NULL && s->unk5A != 0 && s->unk58 != 0) {
        sub_02035E18(s);
        s->unk5A = 0;
    }
}

void sub_02035DC8(void)
{
    sub_02035224();
    sub_02035D98();
}

void sub_02035DD8(void)
{
    UnkStruct02035D5C *s = sub_02035750();

    if (s != NULL && s->unk5A != 1 && s->unk58 != 0) {
        sub_02035D5C(s);
        s->unk5A = 1;
    }
}

void sub_02035E08(void)
{
    sub_02035224();
    sub_02035DD8();
}

u32 sub_02035E18(UnkStruct02035D5C *s)
{
    sub_0208AC0C(0, s->unk75, s->unk0C, 9);
    sub_0208B220(2);
    if (sub_0208B238(2) != 0) {
        return 2;
    }
    return 1;
}

void sub_02035E54(void)
{
    UnkStruct02035D5C *s = sub_02035750();

    s->unk64 = 0;
    s->unk66 = 0;
    s->unk68 = 0;
    s->unk6A = 0;
    s->unk6C = 0;
    s->unk6E = 0;
    s->unk70 = 0;
    s->unk72 = 0;
}

void sub_02035E84(void *unused, u32 a, u32 b, u32 c, u16 d)
{
    UnkStruct02035D5C *s = sub_02035750();

    s->unk64 = c;
    s->unk66 = d;
    s->unk5C = a;
    s->unk5E = b;
}

void sub_02035EB0(void *unused, u32 a, u32 b)
{
    UnkStruct02035D5C *s = sub_02035750();

    s->unk68 = b;
    s->unk60 = a;
}

void sub_02035ECC(void *unused, u32 a, u32 b)
{
    UnkStruct02035D5C *s = sub_02035750();

    s->unk6A = b;
    s->unk62 = a;
}

UnkStruct02035F38_pad *sub_02035EE8(u32 heapId)
{
    UnkStruct02035F38_pad *p = sub_02030734(heapId, 0x4C, 0, _020A799C, 0x44);

    sub_02082BCC(p, 0, 0x4C);
    p->unk40 = 8;
    p->unk44 = 0xF;
    return p;
}

void sub_02035F38(UnkStruct02035F38 *sys)
{
    UnkStruct02035F38_pad *p = sub_0203521C(sys);
    u16 keys;

    if (((*(volatile u16 *)0x02FFFFA8 & 0x8000) >> 15) != 0) {
        p->unk1C = 0;
        p->unk18 = 0;
        p->unk20 = 0;
        p->unk28 = 0;
        p->unk24 = 0;
        p->unk2C = 0;
        return;
    }

    keys = ((*(volatile u16 *)0x04000130 | *(volatile u16 *)0x02FFFFA8) ^ 0x2FFF) & 0x2FFF;
    keys = keys & ~((keys & 0x40) << 1) & ~((keys & 0x20) >> 1);

    p->unk10 = keys & (keys ^ p->unk0C);
    p->unk14 = keys & (keys ^ p->unk0C);
    if (keys != 0 && p->unk0C == keys) {
        p->unk3C--;
        if (p->unk3C == 0) {
            p->unk14 = keys;
            p->unk3C = p->unk40;
        }
    } else {
        p->unk3C = p->unk44;
    }
    p->unk0C = keys;
    p->unk1C = p->unk10;
    p->unk18 = keys;
    p->unk20 = p->unk14;
    sub_020360B8(p);
    p->unk34 |= p->unk1C;
    p->unk30 |= p->unk18;
    p->unk38 |= p->unk20;
    if (sys->unk3E % 2 == 0) {
        p->unk28 = p->unk34;
        p->unk24 = p->unk30;
        p->unk2C = p->unk38;
        p->unk34 = 0;
        p->unk30 = 0;
        p->unk38 = 0;
    }
}
