#include "types.h"

typedef void (*UnkFn02034F5C)(void *);

typedef struct UnkStruct021469BC {
    void *unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    UnkFn02034F5C unk10;
    UnkFn02034F5C unk14;
    UnkFn02034F5C unk18;
    UnkFn02034F5C unk1C;
    UnkFn02034F5C unk20;
    void *unk24;
    void *unk28;
    void *unk2C;
    void *unk30;
    void *unk34;
    u8 unk38;
    u8 unk39;
    u8 unk3A;
    u8 unk3B;
    u8 unk3C;
    u8 unk3D;
    u8 unk3E;
    u8 unk3F;
    u8 unk40;
    u8 unk41;
    u8 unk42;
    u8 unk43;
    u32 unk44;
} UnkStruct021469BC;

extern UnkStruct021469BC *_021469BC;

void sub_02034EF8(UnkStruct021469BC *p);
void sub_02088234(void);
u32 sub_02085D3C(void);
u32 sub_0208BFAC(u16 *out);
u32 sub_0208BF6C(u32 *out);
u32 sub_0208BDD8(u32 which, u32 on);
s32 sub_0203568C(void);
u32 sub_020353B0(void);

void sub_02034F74(UnkStruct021469BC *p, u8 mask);
void sub_02034FA0(UnkStruct021469BC *p, u8 mask);
u32 sub_02034FD4(UnkStruct021469BC *p, u32 mask);
void sub_02035004(UnkStruct021469BC *p, UnkFn02034F5C fn, void *arg);
void sub_02035034(UnkStruct021469BC *p, UnkFn02034F5C fn, void *arg);
void sub_02035080(UnkStruct021469BC *p, UnkFn02034F5C fn, void *arg);
UnkFn02034F5C sub_02035100(UnkStruct021469BC *p);
void sub_02035120(UnkStruct021469BC *p, UnkFn02034F5C fn, void *arg);
void sub_0203512C(UnkStruct021469BC *p, UnkFn02034F5C fn, void *arg);
void sub_0203515C(UnkStruct021469BC *p, u8 mask);
void sub_02035188(UnkStruct021469BC *p, u8 mask);
u32 sub_020351BC(UnkStruct021469BC *p, u32 mask);
void sub_020351EC(UnkStruct021469BC *p, u32 a, u32 b);

void sub_02034F5C(void)
{
    sub_02034EF8(_021469BC);
}

void sub_02034F74(UnkStruct021469BC *p, u8 mask)
{
    p->unk38 |= mask;
}

void sub_02034F84(u8 mask)
{
    sub_02034F74(_021469BC, mask);
}

void sub_02034FA0(UnkStruct021469BC *p, u8 mask)
{
    p->unk38 &= (u8)~mask;
}

void sub_02034FB8(u8 mask)
{
    sub_02034FA0(_021469BC, mask);
}

u32 sub_02034FD4(UnkStruct021469BC *p, u32 mask)
{
    return (p->unk38 & mask) != 0;
}

u32 sub_02034FE8(u32 mask)
{
    return sub_02034FD4(_021469BC, mask);
}

void sub_02035004(UnkStruct021469BC *p, UnkFn02034F5C fn, void *arg)
{
    p->unk14 = fn;
    p->unk28 = arg;
}

void sub_02035010(UnkFn02034F5C fn, void *arg)
{
    sub_02035004(_021469BC, fn, arg);
}

void sub_02035034(UnkStruct021469BC *p, UnkFn02034F5C fn, void *arg)
{
    p->unk10 = fn;
    p->unk28 = arg;
}

void sub_02035040(UnkFn02034F5C fn, void *arg)
{
    sub_02035034(_021469BC, fn, arg);
}

void sub_02035064(void *a, void *b)
{
    _021469BC->unk24 = a;
    _021469BC->unk34 = b;
}

void sub_02035080(UnkStruct021469BC *p, UnkFn02034F5C fn, void *arg)
{
    p->unk1C = fn;
    p->unk2C = arg;
}

void sub_0203508C(UnkFn02034F5C fn0, UnkFn02034F5C fn1, void *arg)
{
    if (_021469BC->unk41 != 0) {
        if (_021469BC->unk18 != NULL) {
            _021469BC->unk18(_021469BC->unk2C);
        }
        if (fn0 != NULL) {
            fn0(arg);
        }
    }
    sub_02035080(_021469BC, fn0, arg);
    sub_02035120(_021469BC, fn1, arg);
}

UnkFn02034F5C sub_02035100(UnkStruct021469BC *p)
{
    return p->unk1C;
}

UnkFn02034F5C sub_02035108(void)
{
    return sub_02035100(_021469BC);
}

void sub_02035120(UnkStruct021469BC *p, UnkFn02034F5C fn, void *arg)
{
    p->unk18 = fn;
    p->unk2C = arg;
}

void sub_0203512C(UnkStruct021469BC *p, UnkFn02034F5C fn, void *arg)
{
    p->unk20 = fn;
    p->unk30 = arg;
}

void sub_02035138(UnkFn02034F5C fn, void *arg)
{
    sub_0203512C(_021469BC, fn, arg);
}

void sub_0203515C(UnkStruct021469BC *p, u8 mask)
{
    p->unk39 |= mask;
}

void sub_0203516C(u8 mask)
{
    sub_0203515C(_021469BC, mask);
}

void sub_02035188(UnkStruct021469BC *p, u8 mask)
{
    p->unk39 &= (u8)~mask;
}

void sub_020351A0(u8 mask)
{
    sub_02035188(_021469BC, mask);
}

u32 sub_020351BC(UnkStruct021469BC *p, u32 mask)
{
    return (p->unk39 & mask) != 0;
}

u32 sub_020351D0(u32 mask)
{
    return sub_020351BC(_021469BC, mask);
}

void sub_020351EC(UnkStruct021469BC *p, u32 a, u32 b)
{
    p->unk08 = a;
    p->unk0C = b;
}

void sub_020351F8(u32 a, u32 b)
{
    sub_020351EC(_021469BC, a, b);
}

void *sub_0203521C(UnkStruct021469BC *p)
{
    return p->unk00;
}

UnkStruct021469BC *sub_02035224(void)
{
    if (_021469BC == NULL) {
        sub_02088234();
    }
    return _021469BC;
}

void sub_0203524C(UnkStruct021469BC *p)
{
    if (p->unk14 != NULL) {
        p->unk14(p->unk28);
    }
}

void sub_02035268(UnkStruct021469BC *p)
{
    if (p->unk10 != NULL) {
        p->unk10(p->unk28);
    }
}

void sub_02035284(UnkStruct021469BC *p)
{
    if (p->unk1C != NULL) {
        p->unk1C(p->unk2C);
        p->unk41 = 1;
    }
}

void sub_020352AC(UnkStruct021469BC *p)
{
    if (p->unk18 != NULL && p->unk41 != 0) {
        p->unk18(p->unk2C);
        p->unk41 = 0;
    }
}

void sub_020352DC(void)
{
    u16 a;
    u32 b;

    if (*(u32 *)0x02FFFC3C % 600 != 1) {
        return;
    }
    if (sub_02085D3C() != 0) {
        if (sub_0208BFAC(&a) == 0) {
            _021469BC->unk3F = (u8)a;
        }
    } else {
        if (sub_0208BF6C(&b) != 0) {
            return;
        }
        if (b == 0) {
            _021469BC->unk3F = 5;
        } else {
            _021469BC->unk3F = 1;
        }
    }
}

u32 sub_02035390(void)
{
    return ((*(u16 *)0x02FFFFA8 & 0x8000) >> 15) != 0;
}

u32 sub_020353B0(void)
{
    return sub_0203568C() <= 2;
}

void sub_020353C8(UnkStruct021469BC *p)
{
    if (p->unk20 == NULL) {
        return;
    }
    if (!sub_020353B0()) {
        return;
    }
    p->unk20(p->unk30);
}

u32 sub_020353F8(UnkStruct021469BC *p)
{
    if (p->unk38 != 0) {
        return 1;
    }
    if (p->unk24 == NULL) {
        return 0;
    }
    return ((u32 (*)(void *))p->unk24)(p->unk34);
}

void sub_02035428(u32 arg)
{
    s32 i;

    for (i = 0; i < 1000; i++) {
        if (sub_0208BDD8(2, arg) == 0) {
            return;
        }
    }
}
