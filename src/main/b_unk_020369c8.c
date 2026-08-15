#include "types.h"

typedef struct UnkStruct020369C8_entry {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u16 unk0C;
    u16 unk0E;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
} UnkStruct020369C8_entry;

typedef struct UnkStruct020369C8_src {
    u32 unk00;
    u16 unk04;
    u16 unk06;
} UnkStruct020369C8_src;

typedef struct UnkStruct020369C8 {
    UnkStruct020369C8_entry *unk00;
    UnkStruct020369C8_entry *unk04;
    UnkStruct020369C8_entry *unk08;
    UnkStruct020369C8_entry *unk0C;
    UnkStruct020369C8_entry *unk10;
    u32 unk14;
    UnkStruct020369C8_entry *unk18;
    u32 unk1C;
} UnkStruct020369C8;

extern const char _020A79C4[];
extern const char _020A79EC[];

u32 sub_020366FC(void *p);
u32 sub_020367C4(UnkStruct020369C8_entry *e, UnkStruct020369C8_src *s, u32 c, u32 flag);
void sub_02034714(const char *file, int line, const char *msg);
void sub_02082BCC(void *dst, u8 val, u32 size);
void *sub_02030734(u32 heap, u32 size, u32 c, const char *file, u32 line);
void sub_020307B0(void *p);

UnkStruct020369C8_entry *sub_020369C8(UnkStruct020369C8 *p);
void sub_020369F8(UnkStruct020369C8 *p);

UnkStruct020369C8_entry *sub_020369C8(UnkStruct020369C8 *p)
{
    if (p->unk10 != NULL) {
        return p->unk10;
    }
    if (p->unk00 != NULL) {
        return p->unk00;
    }
    if (p->unk08 != NULL) {
        return p->unk08;
    }
    return NULL;
}

void sub_020369F8(UnkStruct020369C8 *p)
{
    if (p->unk10 != NULL) {
        p->unk10 = NULL;
        return;
    }
    if (sub_020366FC(p) != 0) {
        return;
    }
    if (sub_020366FC(&p->unk08) != 0) {
        return;
    }
    sub_02034714(_020A79C4, 0x12F, _020A79EC);
}

u32 sub_02036A50(UnkStruct020369C8 *p, UnkStruct020369C8_src *s)
{
    UnkStruct020369C8_entry *e;
    u32 flag = 0;

    while (s->unk04 != 0) {
        e = sub_020369C8(p);
        if (e == NULL) {
            break;
        }
        sub_020369F8(p);
        if (sub_020367C4(e, s, p->unk14, flag) == 0) {
            p->unk10 = e;
            break;
        }
        flag = 1;
        if (s->unk04 == 0xFFFF) {
            p->unk10 = e;
            return 0;
        }
        sub_02082BCC(e, 0, 0x14);
    }
    return 1;
}

void sub_02036AF4(UnkStruct020369C8 *p, u32 count, u32 c, u32 heapId)
{
    sub_02082BCC(p, 0, 0x28);
    p->unk18 = sub_02030734(heapId, count * 0x14, 1, _020A79C4, 0x173);
    p->unk1C = count;
    p->unk14 = c;
}

void sub_02036B4C(UnkStruct020369C8 *p)
{
    sub_02082BCC(p->unk18, 0, p->unk1C * 0x14);
    p->unk00 = NULL;
    p->unk04 = NULL;
    p->unk08 = NULL;
    p->unk0C = NULL;
    p->unk10 = NULL;
}

void sub_02036B88(UnkStruct020369C8 *p)
{
    sub_020307B0(p->unk18);
}
