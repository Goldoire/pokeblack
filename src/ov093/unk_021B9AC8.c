#include "types.h"

// Small ordered pointer list used by the battle engine: six slots plus a
// one-byte length at 0x18.  sub_021B9C24 rotates a slot to the end, which is
// how a finished entry is retired without disturbing the order of the rest.
typedef struct UnkList021B9B40 {
    /* 0x00 */ void *entries[6];
    /* 0x18 */ u8 count;
} UnkList021B9B40;

// 0x1C-byte records living at +4 of some owner object (sub_021B9AEC/AF8).
typedef struct UnkItem021B9AEC {
    /* 0x00 */ u8 unk_00[0x1C];
} UnkItem021B9AEC;

typedef struct UnkOwner021B9AEC {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ UnkItem021B9AEC items[1];
} UnkOwner021B9AEC;

// Only the two fields this file needs; see src/ov093/unk_021B8548.c for the
// rest of the layout.
typedef struct BattleSystem {
    /* 0x000 */ void *core;
    /* 0x004 */ u8 unk_004[0x00C];
    /* 0x010 */ void *unk_010[4];
    /* 0x020 */ u8 unk_020[0x44E];
    /* 0x46E */ u8 unk_46E;
} BattleSystem;

BOOL sub_021B8B9C(BattleSystem *bsys, u8 a1);
void sub_021CD9F4(void *a0, void *a1);
BOOL sub_021D5B7C(void *a0);

UnkList021B9B40 *sub_021B9AF8(UnkOwner021B9AEC *a0, int a1);
u8 sub_021B9B98(UnkList021B9B40 *p);
void sub_021B9C24(UnkList021B9B40 *p, u8 a1);

u32 sub_021B9AC8(u32 a0)
{
    switch (a0) {
    case 2:
        return 2;
    case 3:
        return 1;
    }
    return 0;
}

u8 sub_021B9AE0(int a0)
{
    return a0 & 1;
}

UnkItem021B9AEC *sub_021B9AEC(UnkOwner021B9AEC *a0, int a1)
{
    return &a0->items[a1];
}

UnkList021B9B40 *sub_021B9AF8(UnkOwner021B9AEC *a0, int a1)
{
    return (UnkList021B9B40 *)&a0->items[a1];
}

u8 sub_021B9B04(UnkOwner021B9AEC *a0, int a1)
{
    return sub_021B9B98(sub_021B9AF8(a0, a1));
}

void sub_021B9B10(BattleSystem *bsys, u8 a1, void *a2)
{
    if (bsys->unk_46E != 0 && sub_021B8B9C(bsys, a1) != FALSE && bsys->unk_010[a1] != NULL) {
        sub_021CD9F4(bsys->unk_010[a1], a2);
    }
}

void sub_021B9B40(UnkList021B9B40 *p)
{
    int i;

    p->count = 0;
    for (i = 0; i < 6; i++) {
        p->entries[i] = NULL;
    }
}

void sub_021B9B54(UnkList021B9B40 *p, void *a1)
{
    p->entries[p->count++] = a1;
}

void sub_021B9B60(UnkList021B9B40 *p)
{
    u32 n = 0;
    int i = 0;

    for (; n < p->count; n++) {
        if (sub_021D5B7C(p->entries[i]) != FALSE) {
            i++;
        } else {
            sub_021B9C24(p, (u8)i);
        }
    }
}

u8 sub_021B9B94(UnkList021B9B40 *p)
{
    return p->count;
}

u8 sub_021B9B98(UnkList021B9B40 *p)
{
    int i = 0;
    int n = 0;

    for (; i < p->count; i++) {
        if (sub_021D5B7C(p->entries[i]) != FALSE) {
            n++;
        }
    }
    return n;
}

u8 sub_021B9BC4(UnkList021B9B40 *p, int a1)
{
    int n = 0;

    for (; a1 < p->count; a1++) {
        if (sub_021D5B7C(p->entries[a1]) != FALSE) {
            n++;
        }
    }
    return n;
}

void *sub_021B9BF0(UnkList021B9B40 *p, u8 a1)
{
    if (a1 < p->count) {
        return p->entries[a1];
    }
    return NULL;
}

void *sub_021B9C00(UnkList021B9B40 *p, u8 a1)
{
    if (a1 < p->count) {
        return p->entries[a1];
    }
    return NULL;
}

void sub_021B9C10(UnkList021B9B40 *p, int a1, int a2)
{
    void *tmp = p->entries[a1];

    p->entries[a1] = p->entries[a2];
    p->entries[a2] = tmp;
}

void sub_021B9C24(UnkList021B9B40 *p, u8 a1)
{
    void *tmp = p->entries[a1];

    while (a1 < p->count - 1) {
        p->entries[a1] = p->entries[a1 + 1];
        a1++;
    }
    p->entries[a1] = tmp;
}
