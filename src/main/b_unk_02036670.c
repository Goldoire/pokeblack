#include "types.h"

typedef struct UnkStruct02036670_entry {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u16 unk0C;
    u16 unk0E;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
} UnkStruct02036670_entry;

typedef struct UnkStruct02036670 {
    u8 pad00[0x18];
    UnkStruct02036670_entry *unk18;
    s32 unk1C;
} UnkStruct02036670;

typedef struct UnkStruct020366FC {
    struct UnkStruct020366FC *unk00;
    struct UnkStruct020366FC *unk04;
    struct UnkStruct020366FC *unk08;
} UnkStruct020366FC;

typedef struct UnkStruct02036738 {
    u8 *unk00;
    u16 unk04;
} UnkStruct02036738;

void sub_02036738(UnkStruct02036738 *w, u8 v);

UnkStruct02036670_entry *sub_02036670(UnkStruct02036670 *p)
{
    UnkStruct02036670_entry *e = p->unk18;
    s32 i;

    for (i = 0; i < p->unk1C; i++) {
        if (e->unk0E == 0) {
            return e;
        }
        e++;
    }
    return NULL;
}

s32 sub_020366C0(UnkStruct02036670 *p)
{
    UnkStruct02036670_entry *e = p->unk18;
    s32 i;
    s32 n = 0;

    for (i = 0; i < p->unk1C; i++) {
        if (e->unk0E != 0) {
            n++;
        }
        e++;
    }
    return n;
}

u32 sub_020366FC(UnkStruct020366FC *p)
{
    UnkStruct020366FC *n = p->unk00;

    if (n != NULL) {
        n = n->unk08;
        if (n != NULL) {
            p->unk00 = n;
            n->unk04 = NULL;
        } else {
            p->unk00 = NULL;
            p->unk04 = NULL;
        }
        return 1;
    }
    return 0;
}

void sub_02036738(UnkStruct02036738 *w, u8 v)
{
    *w->unk00 = v;
    w->unk00++;
    w->unk04--;
}

u32 sub_0203675C(UnkStruct02036670_entry *e, UnkStruct02036738 *w)
{
    sub_02036738(w, e->unk0E >> 8);
    sub_02036738(w, e->unk0E);
    sub_02036738(w, e->unk0C >> 8);
    sub_02036738(w, e->unk0C);
    sub_02036738(w, e->unk10);
    return 0;
}
