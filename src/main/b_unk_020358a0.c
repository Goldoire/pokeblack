#include "types.h"

typedef struct TPData {
    u16 x;
    u16 y;
    u16 touch;
    u16 validity;
} TPData;

typedef struct UnkStruct020358A0_ts {
    u8 pad00[0x5C];
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
    u8 unk74;
    u8 unk75;
    u8 unk76;
} UnkStruct020358A0_ts;

typedef struct UnkStruct020358A0 {
    u8 pad00[0x3E];
    u8 unk3E;
} UnkStruct020358A0;

UnkStruct020358A0_ts *sub_02035750(void);
UnkStruct020358A0 *sub_02035224(void);
u16 sub_02035760(UnkStruct020358A0 *p);
u16 sub_02035780(UnkStruct020358A0 *p);
u16 sub_020357A0(UnkStruct020358A0 *p);
u16 sub_020357C0(UnkStruct020358A0 *p);
void sub_02082BCC(void *dst, u8 val, u32 size);
void sub_0208AB1C(void);
u32 sub_0208ABB8(TPData *raw);
void sub_0208ADB4(TPData *raw);
void sub_0208B104(TPData *disp, const TPData *raw);

void sub_020358A0(UnkStruct020358A0 *sys);
u32 sub_02035A70(const u8 *p, u32 x, u32 y);
u32 sub_02035AA4(const u8 *p, u32 x, u32 y);
s32 sub_02035ADC(const u8 *list, u32 x, u32 y);
s32 sub_02035B58(UnkStruct020358A0 *sys, const u8 *list);
s32 sub_02035BBC(UnkStruct020358A0 *sys, const u8 *list);
u16 sub_02035C20(UnkStruct020358A0 *sys);
u16 sub_02035C48(UnkStruct020358A0 *sys);
u32 sub_02035C70(UnkStruct020358A0 *sys, u32 *px, u32 *py);
u32 sub_02035CD8(UnkStruct020358A0 *sys, u32 *px, u32 *py);

void sub_020358A0(UnkStruct020358A0 *sys)
{
    TPData raw;
    TPData disp;
    u8 count;
    u32 fail = 0;
    UnkStruct020358A0_ts *s = sub_02035750();

    if (s == NULL) {
        return;
    }
    if (((*(volatile u16 *)0x02FFFFA8 & 0x8000) >> 15) != 0) {
        sub_02082BCC(s, 0, 0x7C);
        return;
    }
    if (s->unk74 == 0) {
        count = 0;
        sub_0208AB1C();
        while (sub_0208ABB8(&raw) != 0) {
            count++;
            if (count >= 0x20) {
                disp.validity = 3;
                fail = 1;
                break;
            }
            sub_0208AB1C();
        }
    } else {
        sub_0208ADB4(&raw);
    }
    if (fail == 0) {
        sub_0208B104(&disp, &raw);
    }
    if (disp.validity == 0) {
        s->unk5C = disp.x;
        s->unk5E = disp.y;
    } else {
        if (s->unk62 != 0) {
            switch (disp.validity) {
            case 1:
                s->unk5E = disp.y;
                break;
            case 2:
                s->unk5C = disp.x;
                break;
            }
        } else {
            disp.touch = 0;
        }
    }
    s->unk60 = disp.touch & (disp.touch ^ s->unk62);
    s->unk62 = disp.touch;
    s->unk70 |= s->unk60;
    s->unk72 |= s->unk62;
    if (s->unk5E != 0) {
        s->unk6E = s->unk5E;
    }
    if (s->unk5C != 0) {
        s->unk6C = s->unk5C;
    }
    if (sys->unk3E % 2 == 0) {
        s->unk64 = s->unk6C;
        s->unk66 = s->unk6E;
        s->unk68 = s->unk70;
        s->unk6A = s->unk72;
        s->unk6C = 0;
        s->unk6E = 0;
        s->unk70 = 0;
        s->unk72 = 0;
    }
}

void sub_02035A60(void)
{
    sub_020358A0(sub_02035224());
}

u32 sub_02035A70(const u8 *p, u32 x, u32 y)
{
    u32 dx = p[1] - x;
    u32 dy = p[2] - y;

    return dx * dx + dy * dy < p[3] * p[3];
}

u32 sub_02035AA4(const u8 *p, u32 x, u32 y)
{
    if (x - p[2] <= p[3] - p[2] && y - p[0] <= p[1] - p[0]) {
        return 1;
    }
    return 0;
}

s32 sub_02035ADC(const u8 *list, u32 x, u32 y)
{
    s32 i;

    for (i = 0; list[i * 4] != 0xFF; i++) {
        if (list[i * 4] == 0xFD) {
            continue;
        }
        if (list[i * 4] == 0xFE) {
            if (sub_02035A70(&list[i * 4], x, y) != 0) {
                return i;
            }
        } else {
            if (sub_02035AA4(&list[i * 4], x, y) != 0) {
                return i;
            }
        }
    }
    return -1;
}

s32 sub_02035B58(UnkStruct020358A0 *sys, const u8 *list)
{
    u32 x;
    u32 y;

    sub_02035750();
    if (sub_020357A0(sys) == 0) {
        return -1;
    }
    x = sub_02035760(sys);
    y = sub_02035780(sys);
    return sub_02035ADC(list, x, y);
}

s32 sub_02035BA4(const u8 *list)
{
    return sub_02035B58(sub_02035224(), list);
}

s32 sub_02035BBC(UnkStruct020358A0 *sys, const u8 *list)
{
    u32 x;
    u32 y;

    sub_02035750();
    if (sub_020357C0(sys) == 0) {
        return -1;
    }
    x = sub_02035760(sys);
    y = sub_02035780(sys);
    return sub_02035ADC(list, x, y);
}

s32 sub_02035C08(const u8 *list)
{
    return sub_02035BBC(sub_02035224(), list);
}

u16 sub_02035C20(UnkStruct020358A0 *sys)
{
    sub_02035750();
    return sub_020357A0(sys);
}

u16 sub_02035C38(void)
{
    return sub_02035C20(sub_02035224());
}

u16 sub_02035C48(UnkStruct020358A0 *sys)
{
    sub_02035750();
    return sub_020357C0(sys);
}

u16 sub_02035C60(void)
{
    return sub_02035C48(sub_02035224());
}

u32 sub_02035C70(UnkStruct020358A0 *sys, u32 *px, u32 *py)
{
    sub_02035750();
    if (sub_020357A0(sys) == 0) {
        return 0;
    }
    *px = sub_02035760(sys);
    *py = sub_02035780(sys);
    return 1;
}

u32 sub_02035CB8(u32 *px, u32 *py)
{
    return sub_02035C70(sub_02035224(), px, py);
}

u32 sub_02035CD8(UnkStruct020358A0 *sys, u32 *px, u32 *py)
{
    sub_02035750();
    if (sub_020357C0(sys) == 0) {
        return 0;
    }
    *px = sub_02035760(sys);
    *py = sub_02035780(sys);
    return 1;
}

u32 sub_02035D20(u32 *px, u32 *py)
{
    return sub_02035CD8(sub_02035224(), px, py);
}

s32 sub_02035D40(const u8 *list, u32 x, u32 y)
{
    return sub_02035ADC(list, (u16)x, (u16)y);
}
