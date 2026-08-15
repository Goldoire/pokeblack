#include "types.h"

// ov094 is the battle-animation overlay (loaded directly after ov093, the
// battle engine core). Everything in it hangs off one singleton pointer kept
// in the overlay's .bss word at 0x0220AF20; this file is the block of leaf
// accessors that hand out its sub-objects.
typedef struct BattleAnimSys
{
    /* 0x000 */ void *unk000;
    /* 0x004 */ u8 pad_004[0x188 - 0x004];
    /* 0x188 */ void *unk188;
    /* 0x18C */ void *unk18C;
    /* 0x190 */ void *unk190;
    /* 0x194 */ void *unk194;
    /* 0x198 */ void *unk198;
    /* 0x19C */ void *unk19C;
    /* 0x1A0 */ void *unk1A0;
    /* 0x1A4 */ void *unk1A4;
    /* 0x1A8 */ u8 pad_1A8[0x1B4 - 0x1A8];
    /* 0x1B4 */ void *unk1B4;
    /* 0x1B8 */ void *unk1B8;
    /* 0x1BC */ void *unk1BC;
    /* 0x1C0 */ void *unk1C0;
    /* 0x1C4 */ u8 pad_1C4[0x1D4 - 0x1C4];
    /* 0x1D4 */ u16 unk1D4[4];
    /* 0x1DC */ void *unk1DC;
    /* 0x1E0 */ void *unk1E0;
    /* 0x1E4 */ void *unk1E4;
} BattleAnimSys;

extern BattleAnimSys *_0220AF20;

BattleAnimSys *sub_021F8678(void)
{
    return _0220AF20;
}

void *sub_021F8684(void)
{
    return _0220AF20->unk19C;
}

void *sub_021F8694(void)
{
    return _0220AF20->unk190;
}

void *sub_021F86A4(void)
{
    return _0220AF20->unk194;
}

void *sub_021F86B4(void)
{
    return _0220AF20->unk1A4;
}

void *sub_021F86C4(void)
{
    return _0220AF20->unk188;
}

void *sub_021F86D4(void)
{
    return _0220AF20->unk000;
}

void *sub_021F86E0(void)
{
    return _0220AF20->unk18C;
}

void *sub_021F86F0(void)
{
    return _0220AF20->unk1A0;
}

void *sub_021F8700(void)
{
    return _0220AF20->unk1B4;
}

void *sub_021F8710(void)
{
    return _0220AF20->unk1BC;
}

void *sub_021F8720(void)
{
    return _0220AF20->unk1C0;
}

void *sub_021F8730(void)
{
    return _0220AF20->unk1DC;
}

u16 sub_021F8740(int idx)
{
    return _0220AF20->unk1D4[idx];
}

void *sub_021F8754(void)
{
    return _0220AF20->unk1E4;
}

void *sub_021F8764(void)
{
    return _0220AF20->unk1E0;
}
