#include "types.h"

/* ov172 0x021B69E0 - 0x021B6BD0 : IMA-ADPCM codec used by the Xtransceiver
 * voice channel.  Compiler: repo default (dsi/1.1), --thumb.
 *
 * PROVEN by the two rodata tables this file indexes:
 *   _021C4D10  s8[16]  = {-1,-1,-1,-1,2,4,6,8, -1,-1,-1,-1,2,4,6,8}
 *   _021C4D20  u32[89] = {7,8,9,10,11,12,13,14,16,...,32767}
 * i.e. the standard IMA index-adjust and step tables, with the step index
 * clamped to [0,88] and the sample to [-32767,32767].
 */

typedef struct AdpcmState {
    s16 sample;
    s8 index;
} AdpcmState;

extern const s8 _021C4D10[];
extern const s32 _021C4D20[];

/* _021C88E4[0] is the decoder state, _021C88E4[1] (== _021C88E8) the encoder's. */
extern AdpcmState _021C88E4[];
extern AdpcmState _021C88E8[];

s8 sub_021B6ADC(s32 sample, AdpcmState *st);
s16 sub_021B6B68(u8 code, AdpcmState *st);
void sub_021B6A30(const s16 *src, u8 *dst, s32 count, AdpcmState *st);
void sub_021B6A88(const u8 *src, s16 *dst, s32 nibbles, AdpcmState *st);

void sub_021B69E0(void)
{
    _021C88E8->sample = 0;
    _021C88E8->index = 0;
}

void sub_021B69F0(void)
{
    _021C88E4->sample = 0;
    _021C88E4->index = 0;
}

u32 sub_021B6A00(const s16 *src, u32 size, u8 *dst)
{
    sub_021B6A30(src, dst, (s32)(size >> 1), _021C88E8);
    return (size + 3) >> 2;
}

u32 sub_021B6A18(const u8 *src, u32 size, s16 *dst)
{
    sub_021B6A88(src, dst, (s32)(size << 1), _021C88E4);
    return size << 2;
}

void sub_021B6A30(const s16 *src, u8 *dst, s32 count, AdpcmState *st)
{
    s32 i;
    s32 j = 0;
    u8 low = 0;
    s32 pending = 0;

    for (i = 0; i < count; i++) {
        u8 code = (u8)sub_021B6ADC(src[i], st);
        if (pending == 0) {
            low = code;
            pending = 1;
        } else {
            dst[j] = (u8)(low + (u8)(code << 4));
            pending = 0;
            low = 0;
            j++;
        }
    }
    if (pending == 1) {
        dst[j] = low;
    }
}

void sub_021B6A88(const u8 *src, s16 *dst, s32 nibbles, AdpcmState *st)
{
    s32 i;
    s32 count = nibbles / 2;

    for (i = 0; i < count; i++) {
        s8 b = (s8)src[i];
        s16 *out = &dst[i * 2];
        dst[i * 2] = sub_021B6B68((u8)(b & 0xF), st);
        out[1] = sub_021B6B68((u8)((b & 0xF0) >> 4), st);
    }
}

s8 sub_021B6ADC(s32 sample, AdpcmState *st)
{
    s8 index = st->index;
    s32 prev = st->sample;
    s32 step = _021C4D20[index];
    s32 diff = sample - prev;
    s32 code = 0;
    s32 delta;

    if (diff < 0) {
        code = 8;
        diff = -diff;
    }
    delta = step >> 3;
    if (diff >= step) {
        code |= 4;
        diff -= step;
        delta += step;
    }
    step >>= 1;
    if (diff >= step) {
        code |= 2;
        diff -= step;
        delta += step;
    }
    step >>= 1;
    if (diff >= step) {
        code |= 1;
        delta += step;
    }

    if (code & 8) {
        prev -= delta;
    } else {
        prev += delta;
    }
    if (prev > 32767) {
        prev = 32767;
    } else if (prev < -32767) {
        prev = -32767;
    }

    index += _021C4D10[code];
    if (index < 0) {
        index = 0;
    }
    if (index > 88) {
        index = 88;
    }

    st->sample = (s16)prev;
    st->index = index;
    return (s8)(code & 0xF);
}

s16 sub_021B6B68(u8 code, AdpcmState *st)
{
    s32 sample = st->sample;
    s8 index = st->index;
    s32 step = _021C4D20[index];
    s32 delta = step >> 3;

    if (code & 4) {
        delta += step;
    }
    if (code & 2) {
        delta += step >> 1;
    }
    if (code & 1) {
        delta += step >> 2;
    }

    if (code & 8) {
        sample -= delta;
        if (sample < -32767) {
            sample = -32767;
        }
    } else {
        sample += delta;
        if (sample > 32767) {
            sample = 32767;
        }
    }

    index += _021C4D10[code];
    if (index < 0) {
        index = 0;
    } else if (index > 88) {
        index = 88;
    }

    st->sample = (s16)sample;
    st->index = index;
    return (s16)sample;
}
