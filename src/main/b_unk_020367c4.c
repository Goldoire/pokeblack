#include "types.h"

typedef struct UnkStruct020367C4_entry {
    u8 *unk00;
    struct UnkStruct020367C4_entry *unk04;
    struct UnkStruct020367C4_entry *unk08;
    u16 unk0C;
    u16 unk0E;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
} UnkStruct020367C4_entry;

typedef struct UnkStruct020367C4_src {
    u8 *unk00;
    u16 unk04;
    u16 unk06;
} UnkStruct020367C4_src;

typedef struct UnkStruct020368C0 {
    UnkStruct020367C4_entry *unk00;
    UnkStruct020367C4_entry *unk04;
    UnkStruct020367C4_entry *unk08;
    UnkStruct020367C4_entry *unk0C;
    UnkStruct020367C4_entry *unk10;
    void *unk14;
    UnkStruct020367C4_entry *unk18;
    u32 unk1C;
} UnkStruct020368C0;

extern const char _020A79C4[];
extern const char _020A79D0[];
extern const char _020A79D4[];

u32 sub_0203675C(UnkStruct020367C4_entry *e, UnkStruct020367C4_src *s);
s32 sub_020364D4(void *fifo, u8 *dst, s32 count, s32 max);
void sub_02082D44(void *dst, const void *src, u32 size);
UnkStruct020367C4_entry *sub_02036670(UnkStruct020368C0 *p);
void sub_02034714(const char *file, int line, const char *msg);
s32 sub_0203660C(void *fifo);
void sub_02036428(void *fifo, const u8 *src, s32 len);
void sub_0203666C(void *fifo);

u32 sub_020367C4(UnkStruct020367C4_entry *e, UnkStruct020367C4_src *s, void *fifo, u32 flag)
{
    if (e->unk11 == 0) {
        if (flag != 0 && s->unk04 < e->unk0C + 5) {
            return 0;
        }
        sub_0203675C(e, s);
    }
    if (s->unk04 < e->unk0C) {
        if (e->unk00 == NULL) {
            sub_020364D4(fifo, s->unk00, s->unk04, s->unk04);
        } else {
            sub_02082D44(e->unk00, s->unk00, s->unk04);
            e->unk00 = e->unk00 + s->unk04;
        }
        e->unk0C = e->unk0C - s->unk04;
        s->unk04 = 0xFFFF;
        e->unk11 = 1;
        return 1;
    } else {
        if (e->unk00 == NULL) {
            sub_020364D4(fifo, s->unk00, e->unk0C, e->unk0C);
        } else {
            sub_02082D44(e->unk00, s->unk00, e->unk0C);
        }
        s->unk00 = s->unk00 + e->unk0C;
        s->unk04 = s->unk04 - e->unk0C;
    }
    return 1;
}

u32 sub_020368C0(UnkStruct020368C0 *p, u32 id, u8 *data, s32 len, u32 unused, u32 copy, u32 kind)
{
    UnkStruct020367C4_entry *e = sub_02036670(p);

    if (e == NULL) {
        sub_02034714(_020A79C4, 0xDB, _020A79D0);
        return 0;
    }
    if (0x7FFF <= (u16)len) {
        sub_02034714(_020A79C4, 0xDF, _020A79D4);
    }
    if (copy != 0) {
        if (len + 5 >= sub_0203660C(p->unk14)) {
            sub_02034714(_020A79C4, 0xE3, _020A79D0);
            return 0;
        }
        sub_02036428(p->unk14, data, len);
        sub_0203666C(p->unk14);
        e->unk00 = NULL;
    } else {
        e->unk00 = data;
    }
    e->unk0C = len;
    e->unk0E = id;
    e->unk10 = kind;
    e->unk11 = 0;
    if (p->unk04 == NULL) {
        p->unk04 = e;
        p->unk00 = e;
    } else {
        p->unk04->unk08 = e;
        e->unk04 = p->unk04;
        p->unk04 = e;
    }
    return 1;
}
