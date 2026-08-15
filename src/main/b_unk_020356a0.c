#include "types.h"

typedef struct UnkStruct020356A0 {
    u16 unk00;
    u16 unk02;
    u16 unk04;
    u16 unk06;
    u16 unk08;
    u8 unk0A;
    u8 unk0B;
} UnkStruct020356A0;

typedef struct UnkStruct02035750 {
    u8 pad00[0x58];
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
    u8 pad6C[0x9];
    u8 unk75;
    u8 unk76;
} UnkStruct02035750;

typedef struct UnkStruct02035760 {
    u8 pad00[0x3D];
    u8 unk3D;
} UnkStruct02035760;

typedef struct UnkStruct020357E0 {
    u16 unk00;
    u16 unk02;
    u16 unk04;
    u16 unk06;
} UnkStruct020357E0;

typedef struct Unk021469BC {
    void *unk00;
    u32 (*unk04)(UnkStruct020356A0 *a, UnkStruct020356A0 *b);
} Unk021469BC;

extern Unk021469BC _021469BC;
extern UnkStruct02035750 *_021469C4;
extern const char _020A798C[];

void sub_020363B8(void *p, u32 a, u32 b);
void sub_020363D4(void *p, u32 a, u32 b);
void sub_020363F0(void *p, u32 a, u32 b);
void sub_02035E84(void *p, u32 a, u32 b, u32 c, u32 d);
void sub_02035EB0(void *p, u32 a, u32 b);
void sub_02035ECC(void *p, u32 a, u32 b);

void *sub_02030734(u32 heap, u32 size, u32 c, const char *file, u32 line);
void sub_02082BCC(void *dst, u8 val, u32 size);
void sub_0208A924(void);
u32 sub_0208A998(UnkStruct020357E0 *p);
void sub_0208AA2C(UnkStruct020357E0 *p);

UnkStruct02035750 *sub_02035750(void);

void sub_020356A0(void *p)
{
    UnkStruct020356A0 a;
    UnkStruct020356A0 b;

    if (_021469BC.unk04 == NULL) {
        return;
    }
    if (_021469BC.unk04(&a, &b) == 0) {
        return;
    }
    sub_020363B8(p, a.unk00, b.unk00);
    sub_020363D4(p, a.unk02, b.unk02);
    sub_020363F0(p, a.unk04, b.unk04);
    sub_02035E84(p, a.unk06, a.unk08, b.unk06, b.unk08);
    sub_02035EB0(p, a.unk0A, b.unk0A);
    sub_02035ECC(p, a.unk0B, b.unk0B);
}

UnkStruct02035750 *sub_02035750(void)
{
    return _021469C4;
}

u16 sub_02035760(UnkStruct02035760 *p)
{
    UnkStruct02035750 *s = sub_02035750();

    if (p->unk3D == 0x1E) {
        return s->unk64;
    }
    return s->unk5C;
}

u16 sub_02035780(UnkStruct02035760 *p)
{
    UnkStruct02035750 *s = sub_02035750();

    if (p->unk3D == 0x1E) {
        return s->unk66;
    }
    return s->unk5E;
}

u16 sub_020357A0(UnkStruct02035760 *p)
{
    UnkStruct02035750 *s = sub_02035750();

    if (p->unk3D == 0x1E) {
        return s->unk6A;
    }
    return s->unk62;
}

u16 sub_020357C0(UnkStruct02035760 *p)
{
    UnkStruct02035750 *s = sub_02035750();

    if (p->unk3D == 0x1E) {
        return s->unk68;
    }
    return s->unk60;
}

UnkStruct02035750 *sub_020357E0(u32 heapId)
{
    UnkStruct02035750 *s;
    UnkStruct020357E0 t;

    s = sub_02030734(heapId, 0x7C, 0, _020A798C, 0x83);
    sub_02082BCC(s, 0, 0x7C);
    s->unk58 = 0;
    s->unk5A = 0;
    sub_0208A924();
    if (sub_0208A998(&t) == 1) {
        sub_0208AA2C(&t);
    } else {
        t.unk00 = 0x2AE;
        t.unk02 = 0x58C;
        t.unk04 = 0xE25;
        t.unk06 = 0x1208;
        sub_0208AA2C(&t);
    }
    s->unk75 = 4;
    s->unk76 = 0;
    _021469C4 = s;
    return s;
}
