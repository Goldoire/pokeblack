#ifndef PK_POKEMON_H
#define PK_POKEMON_H

/*
 * Pokemon / BoxPokemon data model for Pokemon Black (main, 0x02017000..0x0201C000).
 *
 * PROPOSED to the integrator -- file-local until it lands in include/.
 *
 * Every offset below is read straight out of the ROM's GetBoxMonDataInternal
 * (0x02018E34), GetMonDataInternal (0x02018DB4), SetMonDataInternal
 * (0x02019308) and the four lock routines (0x02018D10/D34/D6C/D8C).
 * See the field table at the bottom of this file for the attr -> offset map.
 *
 * Shape is the gen-4 (pokeheartgold) BoxPokemon verbatim: u32 pid, three
 * lock/validity bits, u16 checksum, four 0x20-byte shuffled substructs.
 * The party block shrank from 0x64 (gen 4) to 0x54, so sizeof(Pokemon) is
 * 0xDC and not 0xEC -- which is the party stride wave 1 measured.
 */

#include "types.h"

#define PARTY_BLOCK_SIZE 0x54
#define BOX_BLOCK_SIZE   0x80

typedef struct PokemonDataBlockA {
    /* 0x00 */ u16 species;
    /* 0x02 */ u16 heldItem;
    /* 0x04 */ u32 otId;
    /* 0x08 */ u32 exp;
    /* 0x0C */ u8 friendship;
    /* 0x0D */ u8 ability;
    /* 0x0E */ u8 markings;
    /* 0x0F */ u8 originLanguage;
    /* 0x10 */ u8 hpEV;
    /* 0x11 */ u8 atkEV;
    /* 0x12 */ u8 defEV;
    /* 0x13 */ u8 speedEV;
    /* 0x14 */ u8 spAtkEV;
    /* 0x15 */ u8 spDefEV;
    /* 0x16 */ u8 cool;
    /* 0x17 */ u8 beauty;
    /* 0x18 */ u8 cute;
    /* 0x19 */ u8 smart;
    /* 0x1A */ u8 tough;
    /* 0x1B */ u8 sheen;
    /* 0x1C */ u32 ribbonsDS1;
} PokemonDataBlockA;

typedef struct PokemonDataBlockB {
    /* 0x00 */ u16 moves[4];
    /* 0x08 */ u8 movePP[4];
    /* 0x0C */ u8 movePpUps[4];
    /* 0x10 */ u32 hpIV : 5;
               u32 atkIV : 5;
               u32 defIV : 5;
               u32 speedIV : 5;
               u32 spAtkIV : 5;
               u32 spDefIV : 5;
               u32 isEgg : 1;
               u32 hasNickname : 1;
    /* 0x14 */ u32 ribbonsGBA;
    /* 0x18 */ u8 fatefulEncounter : 1;
               u8 gender : 2;
               u8 form : 5;
    /* 0x19 */ u8 nature;
    /* 0x1A */ u16 hasDreamWorldAbility : 1;
               u16 unk_1A_1 : 15;
    /* 0x1C */ u32 unk_1C;
} PokemonDataBlockB;

typedef struct PokemonDataBlockC {
    /* 0x00 */ u16 nickname[11];
    /* 0x16 */ u8 unk_16;
    /* 0x17 */ u8 originGame;
    /* 0x18 */ u64 ribbonsDS2;
} PokemonDataBlockC;

typedef struct PokemonDataBlockD {
    /* 0x00 */ u16 otName[8];
    /* 0x10 */ u8 eggYear;
    /* 0x11 */ u8 eggMonth;
    /* 0x12 */ u8 eggDay;
    /* 0x13 */ u8 metYear;
    /* 0x14 */ u8 metMonth;
    /* 0x15 */ u8 metDay;
    /* 0x16 */ u16 eggLocation;
    /* 0x18 */ u16 metLocation;
    /* 0x1A */ u8 pokerus;
    /* 0x1B */ u8 pokeball;
    /* 0x1C */ u8 metLevel : 7;
               u8 otGender : 1;
    /* 0x1D */ u8 encounterType;
    /* 0x1E */ u16 pokeballHgss;
} PokemonDataBlockD;

typedef struct BoxPokemon {
    /* 0x00 */ u32 pid;
    /* 0x04 */ u16 partyDecrypted : 1;
               u16 boxDecrypted : 1;
               u16 checksumFail : 1;
    /* 0x06 */ u16 checksum;
    /* 0x08 */ u32 substructs[BOX_BLOCK_SIZE / 4];
} BoxPokemon;

typedef struct PartyPokemon {
    /* 0x00 */ u32 status;
    /* 0x04 */ u8 level;
    /* 0x05 */ u8 capsule;
    /* 0x06 */ u16 hp;
    /* 0x08 */ u16 maxHp;
    /* 0x0A */ u16 atk;
    /* 0x0C */ u16 def;
    /* 0x0E */ u16 speed;
    /* 0x10 */ u16 spAtk;
    /* 0x12 */ u16 spDef;
    /* 0x14 */ u8 mail[0x40];
} PartyPokemon;

typedef struct Pokemon {
    /* 0x00 */ BoxPokemon box;
    /* 0x88 */ PartyPokemon party;
} Pokemon;

#define PARTY_SIZE 6

typedef struct Party {
    /* 0x000 */ int maxCount;
    /* 0x004 */ int curCount;
    /* 0x008 */ Pokemon mons[PARTY_SIZE];
    /* 0x530 */ u8 unk_530;
} Party; // 0x534

#endif // PK_POKEMON_H
