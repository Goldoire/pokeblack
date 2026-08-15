/*
 * BoxPokemon encryption / checksum / substruct addressing.
 * main, 0x02019A50..0x02019C4C.  Compiler: repo default (dsi/1.1), Thumb.
 */
#include "types.h"
#include "pk_pokemon.h"

u16 sub_02019A7C(u32 *seed);
void *sub_02019C38(BoxPokemon *boxMon, u32 pid, u8 which);
void sub_02045F5C(void *msgData, u32 msgNo, u16 *dest, u32 count);
int sub_0201F448(const u16 *a, const u16 *b);

extern void *_020A7370;
extern u16 _021462F0[];

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

// BoxMonHasDefaultNickname: compares the stored nickname against the species
// name.  Called by SetBoxMonDataInternal to maintain blockB.hasNickname.
BOOL sub_02019ABC(BoxPokemon *boxMon)
{
    BOOL ret = FALSE;
    PokemonDataBlockA *blockA = sub_02019C38(boxMon, boxMon->pid, 0);
    PokemonDataBlockC *blockC = sub_02019C38(boxMon, boxMon->pid, 2);

    sub_02045F5C(_020A7370, blockA->species, _021462F0, 0x20);
    if (sub_0201F448(_021462F0, blockC->nickname) == 0) {
        ret = TRUE;
    }
    return ret;
}
