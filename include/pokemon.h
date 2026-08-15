#ifndef POKEBLACK_POKEMON_H
#define POKEBLACK_POKEMON_H
/*
 * ===========================================================================
 *  Pokemon / BoxPokemon / Party -- the game's central data model
 * ===========================================================================
 *
 * PROMOTED from src/main/pk_pokemon.h. Delete that file and include this.
 *
 * This is the strongest-evidenced structure in the repo, and it is the only
 * one so far proven TWICE OVER by independent means: every field of all four
 * 0x20-byte substructs is pinned separately by the jump table of
 * GetBoxMonDataInternal (0x02018E34, 1224/1224 OK) and by that of
 * SetBoxMonDataInternal (0x02019388, 1736/1736 OK) -- two switches written by
 * different hands over the same layout -- and the two agree everywhere.
 *
 * Sizes each have their own proof: sizeof(Pokemon)=0xDC, BoxPokemon=0x88,
 * PartyPokemon=0x54, Party=0x534, from their own allocation or clear calls.
 *
 * Relative to gen 4 the shape is pokeheartgold's BoxPokemon verbatim -- u32
 * pid, three lock/validity bits, u16 checksum, four shuffled 0x20 substructs
 * -- but the party block shrank from 0x64 to 0x54, so sizeof(Pokemon) is 0xDC
 * and not 0xEC. That 0xDC is the party stride wave 1 measured independently,
 * a third agreement.
 *
 * GRADES: everything here is PROVEN unless a comment says otherwise.
 */

#include "global.h"

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
    /* 0x08 */ u16 substructs[BOX_BLOCK_SIZE / 2];
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


/*
 * MON_DATA_* field ids, read straight out of the jump tables of
 * GetBoxMonDataInternal (0x02018E34, cases 0..0xAF) and
 * SetBoxMonDataInternal (0x02019388, cases 0..0xB1), plus
 * Get/SetMonDataInternal (0x02018DB4 / 0x02019308, cases 0x9D..0xA8).
 * All four are byte-exact, so this numbering is PROVEN, not inferred.
 *
 * Relative to gen 4 (pokeheartgold): identical through 76, then HAS_NICKNAME
 * moves out of slot 77 to slot 117, so 78..109 shift down by one; gen 4's
 * PtHGSS egg/met-location and shiny-leaf fields are replaced by the gen-5
 * NATURE / HIDDEN_ABILITY bytes at 112/113.
 */
#define MON_DATA_PERSONALITY          0
#define MON_DATA_IS_PARTY_DECRYPTED   1
#define MON_DATA_IS_BOX_DECRYPTED     2
#define MON_DATA_CHECKSUM_FAILED      3
#define MON_DATA_CHECKSUM             4
#define MON_DATA_SPECIES              5
#define MON_DATA_HELD_ITEM            6
#define MON_DATA_OT_ID                7
#define MON_DATA_EXPERIENCE           8
#define MON_DATA_FRIENDSHIP           9
#define MON_DATA_ABILITY              10
#define MON_DATA_MARKINGS             11
#define MON_DATA_LANGUAGE             12
#define MON_DATA_HP_EV                13
#define MON_DATA_ATK_EV               14
#define MON_DATA_DEF_EV               15
#define MON_DATA_SPEED_EV             16
#define MON_DATA_SPATK_EV             17
#define MON_DATA_SPDEF_EV             18
#define MON_DATA_COOL                 19
#define MON_DATA_BEAUTY               20
#define MON_DATA_CUTE                 21
#define MON_DATA_SMART                22
#define MON_DATA_TOUGH                23
#define MON_DATA_SHEEN                24
#define MON_DATA_RIBBON_DS1_FIRST     25 // .. 53, bit (id - 25) of blockA.ribbonsDS1
#define MON_DATA_RIBBON_DS1_LAST      53
#define MON_DATA_MOVE1                54 // .. 57
#define MON_DATA_MOVE1_PP             58 // .. 61
#define MON_DATA_MOVE1_PP_UPS         62 // .. 65
#define MON_DATA_MOVE1_MAX_PP         66 // .. 69, get-only (set is a no-op)
#define MON_DATA_HP_IV                70
#define MON_DATA_ATK_IV               71
#define MON_DATA_DEF_IV               72
#define MON_DATA_SPEED_IV             73
#define MON_DATA_SPATK_IV             74
#define MON_DATA_SPDEF_IV             75
#define MON_DATA_IS_EGG               76
#define MON_DATA_RIBBON_GBA_FIRST     77 // .. 108, bit (id - 77) of blockB.ribbonsGBA
#define MON_DATA_RIBBON_GBA_LAST      108
#define MON_DATA_FATEFUL_ENCOUNTER    109
#define MON_DATA_GENDER               110 // getter recomputes and writes back
#define MON_DATA_FORM                 111
#define MON_DATA_NATURE               112
#define MON_DATA_HIDDEN_ABILITY       113
#define MON_DATA_UNK_114              114
#define MON_DATA_NICKNAME             115
#define MON_DATA_NICKNAME_STRING      116
#define MON_DATA_HAS_NICKNAME         117
#define MON_DATA_UNK_118              118
#define MON_DATA_MET_GAME             119
#define MON_DATA_RIBBON_DS2_FIRST     120 // .. 140, bit (id - 120) of blockC.ribbonsDS2
#define MON_DATA_RIBBON_DS2_LAST      140
#define MON_DATA_OT_NAME              141
#define MON_DATA_OT_NAME_STRING       142
#define MON_DATA_EGG_YEAR             143
#define MON_DATA_EGG_MONTH            144
#define MON_DATA_EGG_DAY              145
#define MON_DATA_MET_YEAR             146
#define MON_DATA_MET_MONTH            147
#define MON_DATA_MET_DAY              148
#define MON_DATA_EGG_LOCATION         149
#define MON_DATA_MET_LOCATION         150
#define MON_DATA_POKERUS              151
#define MON_DATA_POKEBALL             152
#define MON_DATA_MET_LEVEL            153
#define MON_DATA_OT_GENDER            154
#define MON_DATA_ENCOUNTER_TYPE       155
#define MON_DATA_POKEBALL_HGSS        156
#define MON_DATA_STATUS               157 // party block starts here
#define MON_DATA_LEVEL                158
#define MON_DATA_CAPSULE              159
#define MON_DATA_HP                   160
#define MON_DATA_MAX_HP               161
#define MON_DATA_ATK                  162
#define MON_DATA_DEF                  163
#define MON_DATA_SPEED                164
#define MON_DATA_SP_ATK               165
#define MON_DATA_SP_DEF               166
#define MON_DATA_MAIL                 167
#define MON_DATA_BALL_CAPSULE         168 // no-op both ways
#define MON_DATA_SPECIES_EXISTS       169
#define MON_DATA_SANITY_IS_EGG        170
#define MON_DATA_SPECIES_OR_EGG       171
#define MON_DATA_COMBINED_IVS         172
#define MON_DATA_NO_PRINT_GENDER      173
#define MON_DATA_TYPE_1               174
#define MON_DATA_TYPE_2               175
#define MON_DATA_SPECIES_NAME         176 // set-only
#define MON_DATA_SPECIES_NAME_STRING  177 // set-only

#define SPECIES_EGG_BLACK 650 // returned by MON_DATA_SPECIES on a bad egg
#define MAX_ITEM_ID       626

#define PARTY_SIZE 6

typedef struct Party {
    /* 0x000 */ int maxCount;
    /* 0x004 */ int curCount;
    /* 0x008 */ Pokemon mons[PARTY_SIZE];
    /* 0x530 */ u8 unk_530;
} Party; // 0x534


#endif // POKEBLACK_POKEMON_H
