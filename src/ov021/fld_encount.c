/*
 * ov021 / field_encount.c -- wild-encounter driver.
 *
 * TU recovered from the assert __FILE__ string "field_encount.c" at
 * 0x021DDFA4; it spans 0x021A9ED8..0x021AA77C (19 functions, 2212 bytes).
 *
 * Compiler: tools/mwccarm/dsi/1.1 (repo default), --thumb.
 *
 * Struct layouts and their evidence: src/ov021/fld_encount.h.
 */
#include "types.h"

#include "fld_encount.h"

u16 sub_02188C84(FieldSystem *fieldSystem);
void *sub_02188C80(FieldSystem *fieldSystem);

void *sub_02030734(u16 heapId, u32 size, u32 atEnd, void *file, u32 line);
void sub_020307B0(void *ptr);
void sub_02082BCC(void *dst, u8 value, u32 size); /* MI_CpuFill8 */
u32 sub_020056EC(u32 max);

void *sub_020120F4(void *ovyManager);
void *sub_02012844(void *saveData);
void *sub_0216255C(void *a0);

void *sub_021AA77C(u16 heapId);
void sub_021AA7AC(FieldEncount *encount, void *a1);
void sub_021AA7CC(FieldEncount *encount, void *a1);
void sub_021AA794(void *a0);
u32 sub_021AA778(void *a0);
u32 sub_021AA6E0(void);

void *sub_021A3074(FieldSystem *fieldSystem);
u16 sub_0216D83C(void *player);
u16 sub_0216D854(void *player);
u16 sub_0216D86C(void *player);

extern u8 _021DDFA4[]; /* "field_encount.c" */

/* ---- 0x021A9ED8: FieldEncount_New ---- */

FieldEncount *sub_021A9ED8(FieldSystem *fieldSystem)
{
    u16 heapId = sub_02188C84(fieldSystem);
    FieldEncount *encount = sub_02030734(heapId, sizeof(FieldEncount), 1, _021DDFA4, 98);
    void *ovyManager;
    void *saveData;
    void *unk10;

    encount->fieldSystem = fieldSystem;
    ovyManager = sub_02188C80(fieldSystem);
    encount->ovyManager = ovyManager;
    saveData = sub_020120F4(ovyManager);
    encount->saveData = saveData;
    encount->rates = sub_0216255C(sub_02012844(saveData));
    unk10 = sub_021AA77C(heapId);
    encount->unk10 = unk10;
    sub_021AA7AC(encount, unk10);
    return encount;
}

/* ---- 0x021A9F28: FieldEncount_Delete ---- */

void sub_021A9F28(FieldEncount *encount)
{
    sub_021AA7CC(encount, encount->unk10);
    sub_021AA794(encount->unk10);
    sub_020307B0(encount);
}

/* ---- 0x021AA3E0: encounter rate for slot `index`, biased by `bias` ---- */

int sub_021AA3E0(FieldEncount *encount, int index, int bias)
{
    int rate;

    if (index >= 7) {
        return 0;
    }
    rate = encount->rates[index];
    if (rate > 0) {
        rate += bias;
    }
    if (rate < 0) {
        rate = 0;
    }
    return rate;
}

/* ---- 0x021AA3FC ---- */

BOOL sub_021AA3FC(FieldEncount *encount, void *a1, u32 rate)
{
    u32 kind;

    if (rate > 100) {
        rate = 100;
    }
    kind = sub_021AA778(a1);
    if (kind == 0) {
        return FALSE;
    }
    if (kind == 1) {
        rate = 1;
    }
    if (sub_021AA6E0() <= rate) {
        return TRUE;
    }
    return FALSE;
}

/* ---- 0x021AA6E0: a 0..99 roll (0xFFFF * 656 == 0xFFFF0, one 16-bit draw) ---- */

u32 sub_021AA6E0(void)
{
    return sub_020056EC(0xFFFF) / 656;
}

/* ---- 0x021AA6F8: seed the step counter with the player's current tile ---- */

void sub_021AA6F8(FieldEncountStep *step, FieldSystem *fieldSystem)
{
    void *player = sub_021A3074(fieldSystem);

    sub_02082BCC(step, 0, sizeof(FieldEncountStep));
    step->x = sub_0216D83C(player);
    step->y = sub_0216D854(player);
    step->z = sub_0216D86C(player);
}

/* ---- 0x021AA728: count one step once the player has left the seed tile ---- */

void sub_021AA728(FieldEncountStep *step, FieldSystem *fieldSystem)
{
    void *player = sub_021A3074(fieldSystem);

    if (step->moved != 0) {
        if (step->steps < 0xA000) {
            step->steps++;
        }
        return;
    }
    if (step->x != sub_0216D83C(player) || step->y != sub_0216D854(player) ||
        step->z != sub_0216D86C(player)) {
        step->moved = 1;
        step->steps++;
    }
}

/* ---- 0x021AA35C: classify the tile the player is standing on ---- */

void *sub_02188CB4(FieldSystem *fieldSystem);
void *sub_02188C98(FieldSystem *fieldSystem);
void *sub_021A30C8(void *a0);
BOOL sub_021AB100(void *tile);
u32 sub_021AB0F8(void *tile);
void *sub_021AB0F0(void *tile);
BOOL sub_021AB140(void *tile);
BOOL sub_021AB29C(void *tile);

int sub_021AA35C(FieldEncount *encount, int a1, u8 *out)
{
    void *player;
    void *tile;
    u32 attr;

    player = sub_02188CB4(encount->fieldSystem);
    sub_02188C98(encount->fieldSystem);
    *out = 0;
    tile = sub_021A30C8(player);
    if (sub_021AB100(tile) == 0) {
        return 0xFF;
    }
    attr = sub_021AB0F8(tile);
    if (a1 != 1 && (attr & 4) == 0) {
        return 0xFF;
    }
    tile = sub_021AB0F0(tile);
    if (sub_021AB140(tile) != 0) {
        *out += 10;
    }
    if (attr & 2) {
        if (a1 == 1) {
            return 4;
        }
        return 3;
    }
    if (a1 == 1) {
        return 2;
    }
    if (sub_021AB29C(tile) != 0) {
        return 1;
    }
    return 0;
}

/* ---- 0x021AA69C: weather -> encounter class (dense jump table, 0..12) ---- */

void *sub_02188C6C(FieldSystem *fieldSystem);
u32 sub_021A1BF4(void *weather);

int sub_021AA69C(FieldSystem *fieldSystem)
{
    switch (sub_021A1BF4(sub_02188C6C(fieldSystem))) {
    case 2:
    case 6:
    case 7:
        return 2;
    case 3:
    case 12:
        return 4;
    case 4:
    case 5:
        return 3;
    default:
        return 0;
    }
}
