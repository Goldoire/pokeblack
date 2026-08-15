/*
 * BoxPokemon encryption / checksum / substruct addressing.
 * main, 0x02019A50..0x02019C4C.  Compiler: repo default (dsi/1.1), Thumb.
 */
#include "types.h"
#include "pk_pokemon.h"

u16 sub_02019A7C(u32 *seed);

// sBlockOffsets[pid shuffle index][substruct id] -> byte offset into the
// 0x80-byte encrypted region.  24 permutations x 4 blocks of 0x20 bytes.
extern const u8 _0209E3A4[24][4];

// MonEncryptSegment / MonDecryptSegment (XOR, so one routine does both)
void sub_02019A50(u16 *data, u32 size, u32 seed)
{
    u32 i = 0;
    u32 count = size / 2;

    for (; i < count; i++) {
        data[i] ^= sub_02019A7C(&seed);
    }
}

// LCRandom over a caller-supplied seed
u16 sub_02019A7C(u32 *seed)
{
    *seed = *seed * 0x41C64E6D + 0x6073;
    return (u16)(*seed >> 16);
}

// CalcMonChecksum
u16 sub_02019A9C(u16 *data, u32 size)
{
    u16 checksum = 0;
    u32 i = 0;
    u32 count = size / 2;

    for (; i < count; i++) {
        checksum += data[i];
    }
    return checksum;
}

// GetSubstructAddr
void *sub_02019C38(BoxPokemon *boxMon, u32 pid, u8 which)
{
    return (u8 *)boxMon->substructs + _0209E3A4[(pid & 0x0003E000) >> 13][which];
}
