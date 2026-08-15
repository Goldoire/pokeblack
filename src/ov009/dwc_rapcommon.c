#include "types.h"

/*
 * ov009 / dwc_rapcommon.c  --  0x02156E30 .. 0x02157170
 *
 * Named after the __FILE__ string "dwc_rapcommon.c" (ov009 rodata 0x021A1C7C)
 * that sub_02156E30 and sub_02157048 hand to the heap allocator.
 *
 * This file owns the third bss word, 0x021A8268, a pointer to a 0x24-byte
 * work block allocated by sub_02157048.  The layout below is pinned by
 * sub_02157048 (allocates 0x24, writes +0x00/+0x04/+0x20), sub_02156ED0
 * (+0x14, +0x1C), sub_02156F14 (+0x08, +0x0C, +0x20) and sub_02156F5C
 * (+0x08, +0x10, +0x14, +0x18).
 */

typedef struct UnkStruct021A8268 {
    void *unk00;  /* allocator handle over the aligned buffer */
    void *unk04;  /* raw buffer, allocated from the caller's heap */
    void *unk08;  /* secondary allocator handle */
    void *unk0C;  /* buffer behind unk08, freed by sub_02156F14 */
    u32 unk10;    /* tag the secondary allocator is selected by */
    u32 unk14;    /* number of allocations served by the secondary heap */
    u32 unk18;    /* size threshold for the secondary heap */
    u32 unk1C;
    u16 unk20;
    u16 unk22;
} UnkStruct021A8268;

extern UnkStruct021A8268 *_021A8268;

/* overlay rodata */
extern const char _021A1C78[];  /* "" - assert text */
extern const char _021A1C7C[];  /* "dwc_rapcommon.c" */

/* ARM9 */
void sub_02034714(const char *param0, int param1, const char *param2);
void *sub_02030734(u32 heapId, u32 size, u32 param2, const char *file, int line);
void sub_0203C9AC(int param0, int param1, int param2, int param3);
void *sub_02060C5C(void *start, u32 size, u32 param2);
void *sub_02060CA0(void *heap, u32 size, u32 align);
u32 sub_02087988(void);  /* OS_DisableInterrupts */
void sub_0208799C(u32 state);  /* OS_RestoreInterrupts */
void sub_0200FB6C(void);

/* this file */
void sub_02156F14(void);

void sub_02156ED0(void)
{
    if (_021A8268 == NULL) {
        sub_02034714(_021A1C78, 0, _021A1C78);
    }

    if (_021A8268->unk14 != 0) {
        sub_0203C9AC(0, 0, 0, 1006);
        _021A8268->unk1C = 1;
    } else {
        sub_02156F14();
    }
}

void sub_02156F50(u16 param0)
{
    _021A8268->unk20 = param0;
}

void *sub_02156F5C(u32 param0, u32 param1, u32 param2)
{
    void *v0;
    u32 v1;

    if (_021A8268->unk08 != NULL && param0 == _021A8268->unk10
        && param1 > _021A8268->unk18) {
        v1 = sub_02087988();
        v0 = sub_02060CA0(_021A8268->unk08, param1, param2);
        sub_0208799C(v1);
        _021A8268->unk14++;
    } else {
        v1 = sub_02087988();
        v0 = sub_02060CA0(_021A8268->unk00, param1, param2);
        sub_0208799C(v1);
    }

    if (v0 == NULL) {
        sub_0200FB6C();
        sub_0203C9AC(0, 0, 0, 1006);
        return NULL;
    }

    return v0;
}

void sub_02157048(u32 param0, u32 param1)
{
    if (_021A8268 != NULL) {
        sub_02034714(_021A1C78, 0, _021A1C78);
    }

    _021A8268 = sub_02030734(0, sizeof(UnkStruct021A8268), 1, _021A1C7C, 332);
    _021A8268->unk04 = sub_02030734(param0, param1 - 0x80, 0, _021A1C7C, 333);
    _021A8268->unk00 =
        sub_02060C5C((void *)(((u32)_021A8268->unk04 + 31) & ~31), param1 - 0xC0, 0);
    _021A8268->unk20 = 0;
}
