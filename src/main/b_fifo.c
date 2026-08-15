#include "types.h"

typedef struct Fifo {
    u8 *data;
    s32 size;
    u32 unk08;
    s16 rpos;
    volatile s16 wpos;
} Fifo;

extern const char _020A79A4[];
extern const char _020A79B4[];
extern const char _020A79C0[];

void sub_02034714(const char *file, int line, const char *msg);
void sub_02039548(void);

s32 sub_020365E8(Fifo *b);
s32 sub_02036624(Fifo *b, s32 idx);
s32 sub_02036568(Fifo *b, u8 *restrict dst, s32 count, s32 max);
s32 sub_020364D4(Fifo *b, u8 *dst, s32 count, s32 max);
u32 sub_02036500(Fifo *b);
s32 sub_02036640(Fifo *b);

void sub_0203640C(Fifo *b, u8 *data, s32 size)
{
    b->data = data;
    b->size = (s16)size;
    b->rpos = 0;
    b->wpos = 0;
}

void sub_02036428(Fifo *b, const u8 *src, s32 len)
{
    s32 i;
    s32 n;

    if (sub_02036640(b) <= len) {
        sub_02039548();
        return;
    }

    n = 0;
    for (i = b->wpos; i < b->wpos + len; i++) {
        if (src == NULL) {
            sub_02034714(_020A79A4, 68, _020A79B4);
        }
        b->data[sub_02036624(b, i)] = src[n];
        n++;
    }
    b->wpos = sub_02036624(b, i);
}

s32 sub_020364D4(Fifo *b, u8 *dst, s32 count, s32 max)
{
    s32 n = sub_02036568(b, dst, count, max);

    b->rpos = sub_02036624(b, b->rpos + n);
    return n;
}

u32 sub_02036500(Fifo *b)
{
    u8 v;

    if (sub_020364D4(b, &v, 1, 1) == 1) {
        return v;
    }
    sub_02034714(_020A79A4, 108, _020A79C0);
    return 0;
}

u16 sub_02036540(Fifo *b)
{
    u16 v = sub_02036500(b) << 8;

    v |= sub_02036500(b);
    return v;
}

s32 sub_02036568(Fifo *b, u8 *restrict dst, s32 count, s32 max)
{
    s32 i;
    s32 n = 0;

    for (i = b->rpos; i < b->rpos + count; i++) {
        if (b->wpos == sub_02036624(b, i) || n == max) {
            return n;
        }
        dst[n] = b->data[sub_02036624(b, i)];
        n++;
    }
    return n;
}

s32 sub_020365E8(Fifo *b)
{
    s32 v;

    if (b->rpos > b->wpos) {
        v = b->size + b->wpos;
    } else {
        v = b->wpos;
    }
    return v - b->rpos;
}

s32 sub_0203660C(Fifo *b)
{
    return b->size - sub_020365E8(b);
}

s32 sub_02036624(Fifo *b, s32 idx)
{
    return idx % b->size;
}

s32 sub_02036640(Fifo *b)
{
    s32 v;

    if (b->rpos > b->wpos) {
        v = b->size + b->wpos;
    } else {
        v = b->wpos;
    }
    v -= b->rpos;
    return b->size - v;
}

void sub_0203666C(void)
{
}
