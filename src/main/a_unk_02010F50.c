#include "types.h"

/* Three parallel per-slot tables, 13 slots:
 *   _0214621C  u8   (sub_02010F50 stores 0x30)
 *   _021461E8  u32  countdown, decremented while > 1 by sub_02010DCC
 *   _02146228  a record whose u8 at +0x1C is the active slot index; 13 means
 *              "none".
 */
extern u8 _0214621C[];
extern u32 _021461E8[];

typedef struct UnkStruct02146228
{
    /* 0x00 */ u8 unk00[0x1C];
    /* 0x1C */ u8 unk1C;
} UnkStruct02146228;

extern UnkStruct02146228 _02146228;

void sub_02048F60(int a0, int a1, void *a2);

void sub_02010F50(int a0)
{
    if (a0 >= 13)
    {
        return;
    }
    _0214621C[a0] = 0x30;
    _021461E8[a0] = 0;
    if (_02146228.unk1C == a0)
    {
        _02146228.unk1C = 13;
    }
}

void sub_02010F7C(void *a0)
{
    sub_02048F60(0x26, 0, a0);
}

/* 0xC-byte records: sub_02010F94 reads the u8 at +0xA, sub_02010FA0 the
 * u16 at +0x02. */
typedef struct Unk0C
{
    /* 0x00 */ u16 unk00;
    /* 0x02 */ u16 unk02;
    /* 0x04 */ u8 unk04[6];
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 unk0B;
} Unk0C;

u8 sub_02010F94(Unk0C *a0, int a1)
{
    return a0[a1].unk0A;
}

u16 sub_02010FA0(Unk0C *a0, int a1)
{
    return a0[a1].unk02;
}
