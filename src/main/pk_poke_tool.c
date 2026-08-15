/*
 * poke_tool.c -- the Pokemon / BoxPokemon translation unit.
 * main, 0x0201742C..0x0201A568 (TU boundary from build/reference/main_tu_map.json).
 * Compiler: repo default (dsi/1.1), Thumb.
 *
 * Verified so far: 0x02017528, 0x02017550, 0x02017D30..0x02017FA8,
 * 0x02018D10..0x02018DB4, 0x02018E34, 0x02019308, 0x02019388,
 * 0x02019A50..0x02019ABC, 0x02019C38.
 *
 * The two keystones are GetBoxMonDataInternal (0x02018E34) and
 * SetBoxMonDataInternal (0x02019388): every case of their switches pins one
 * substruct field's offset, width and signedness.  See pk_pokemon.h.
 */
#include "types.h"
#include "pk_pokemon.h"

#define SPECIES_EGG       650
#define MAX_ITEM          626
#define SPECIES_ARCEUS    493
#define ABILITY_MULTITYPE 121
#define MAX_EV_TOTAL      510

#define SHINY_CHECK(otid, pid)     (((((otid) & 0xFFFF0000u) >> 16u) ^ ((otid) & 0xFFFFu) ^ (((pid) & 0xFFFF0000u) >> 16u) ^ ((pid) & 0xFFFFu)) < 8u)

/* ---- in this translation unit ---- */
BOOL sub_02017DBC(BoxPokemon *boxMon);
BOOL sub_02017DE4(BoxPokemon *boxMon, BOOL locked);
u32 sub_02017E1C(Pokemon *mon, int attr, void *dest);
void sub_02017E40(Pokemon *mon, int attr, u32 value);
u32 sub_02017E88(BoxPokemon *boxMon, int attr, void *dest);
BOOL sub_02017EB4(BoxPokemon *boxMon);
BOOL sub_02017ED8(u32 otId, u32 pid);
u8 sub_02017F08(BoxPokemon *boxMon);
u8 sub_02017F50(u16 species, u16 form, u32 pid);
BOOL sub_02018D10(Pokemon *mon);
BOOL sub_02018D34(BoxPokemon *boxMon);
void sub_02018D6C(Pokemon *mon);
void sub_02018D8C(BoxPokemon *boxMon);
u32 sub_02018DB4(Pokemon *mon, int attr, void *dest);
u32 sub_02018E34(BoxPokemon *boxMon, int attr, void *dest);
void sub_02019308(Pokemon *mon, int attr, u32 value);
void sub_02019388(BoxPokemon *boxMon, int attr, u32 value);
void sub_02019A50(void *data, u32 size, u32 seed);
u16 sub_02019A7C(u32 *seed);
u16 sub_02019A9C(void *data, u32 size);
BOOL sub_02019ABC(BoxPokemon *boxMon);
void *sub_02019C38(BoxPokemon *boxMon, u32 pid, u8 which);

/* ---- elsewhere ---- */
void MIi_CpuClearFast(u32 data, void *dest, u32 size);
void sub_02008F3C(void *src, void *dest);
u32 sub_0201850C(u16 species, u8 form, u32 exp);
u32 sub_0201C158(u16 move, u8 ppUp);
u32 sub_02019BBC(u16 item);
u32 sub_02019C90(u16 species, u8 form, int attr);
void *sub_02019C54(u16 species, u16 form);
u32 sub_0201AE1C(void *personal, int attr);
void sub_02045924(void *dest, const u16 *src);
void sub_02045A38(void *src, u16 *dest, u32 count);
void sub_02045CAC(void *msgData, u32 msgNo, void *dest);
void sub_02045F5C(void *msgData, u32 msgNo, u16 *dest, u32 count);
void sub_0201F41C(const void *src, void *dest, u32 count);
int sub_0201F448(const u16 *a, const u16 *b);

/* sBlockOffsets[pid shuffle index][substruct id]: byte offset of substruct
   `which` inside the 0x80-byte encrypted region.  24 permutations. */
extern const u8 _0209E3A4[24][4];
extern void *_020A7370;
extern u16 _021462F0[];

void sub_02017528(Pokemon *mon)
{
    MIi_CpuClearFast(0, mon, sizeof(Pokemon));
    sub_02019A50(mon->box.substructs, BOX_BLOCK_SIZE, mon->box.checksum);
    sub_02019A50(&mon->party, sizeof(PartyPokemon), mon->box.pid);
}

void sub_02017550(BoxPokemon *boxMon)
{
    MIi_CpuClearFast(0, boxMon, sizeof(BoxPokemon));
    sub_02019A50(boxMon->substructs, BOX_BLOCK_SIZE, boxMon->checksum);
}

// AcquireMonLock
BOOL sub_02017D30(Pokemon *mon)
{
    BOOL locked = FALSE;
    if (!mon->box.partyDecrypted) {
        locked = TRUE;
        mon->box.partyDecrypted = locked;
        mon->box.boxDecrypted = TRUE;
        sub_02019A50(&mon->party, sizeof(PartyPokemon), mon->box.pid);
        sub_02019A50(mon->box.substructs, BOX_BLOCK_SIZE, mon->box.checksum);
    }
    return locked;
}

// ReleaseMonLock
BOOL sub_02017D70(Pokemon *mon, BOOL locked)
{
    BOOL prev = FALSE;
    if (mon->box.partyDecrypted == TRUE && locked == TRUE) {
        mon->box.partyDecrypted = FALSE;
        mon->box.boxDecrypted = FALSE;
        prev = TRUE;
        sub_02019A50(&mon->party, sizeof(PartyPokemon), mon->box.pid);
        mon->box.checksum = sub_02019A9C(mon->box.substructs, BOX_BLOCK_SIZE);
        sub_02019A50(mon->box.substructs, BOX_BLOCK_SIZE, mon->box.checksum);
    }
    return prev;
}

// AcquireBoxMonLock
BOOL sub_02017DBC(BoxPokemon *boxMon)
{
    BOOL locked = FALSE;
    if (!boxMon->boxDecrypted) {
        boxMon->boxDecrypted = TRUE;
        locked = TRUE;
        sub_02019A50(boxMon->substructs, BOX_BLOCK_SIZE, boxMon->checksum);
    }
    return locked;
}

// ReleaseBoxMonLock
BOOL sub_02017DE4(BoxPokemon *boxMon, BOOL locked)
{
    BOOL prev = FALSE;
    if (boxMon->boxDecrypted == TRUE && locked == TRUE) {
        prev = TRUE;
        boxMon->boxDecrypted = FALSE;
        boxMon->checksum = sub_02019A9C(boxMon->substructs, BOX_BLOCK_SIZE);
        sub_02019A50(boxMon->substructs, BOX_BLOCK_SIZE, boxMon->checksum);
    }
    return prev;
}

// GetMonData
u32 sub_02017E1C(Pokemon *mon, int attr, void *dest)
{
    u32 ret;
    sub_02018D10(mon);
    ret = sub_02018DB4(mon, attr, dest);
    sub_02018D6C(mon);
    return ret;
}

// SetMonData
void sub_02017E40(Pokemon *mon, int attr, u32 value)
{
    if (sub_02018D10(mon) == TRUE) {
        sub_02019308(mon, attr, value);
    }
    sub_02018D6C(mon);
}

// SetBoxMonData
void sub_02017E64(BoxPokemon *boxMon, int attr, u32 value)
{
    if (sub_02018D34(boxMon) == TRUE) {
        sub_02019388(boxMon, attr, value);
    }
    sub_02018D8C(boxMon);
}

// GetBoxMonData
u32 sub_02017E88(BoxPokemon *boxMon, int attr, void *dest)
{
    u32 ret;
    sub_02018D34(boxMon);
    ret = sub_02018E34(boxMon, attr, dest);
    sub_02018D8C(boxMon);
    return ret;
}

// MonIsShiny
BOOL sub_02017EAC(Pokemon *mon)
{
    return sub_02017EB4(&mon->box);
}

// BoxMonIsShiny
BOOL sub_02017EB4(BoxPokemon *boxMon)
{
    u32 otId = sub_02017E88(boxMon, 7, NULL);
    u32 pid = sub_02017E88(boxMon, 0, NULL);
    return sub_02017ED8(otId, pid);
}

#define SHINY_CHECK(otid, pid)     (((((otid) & 0xFFFF0000u) >> 16u) ^ ((otid) & 0xFFFFu) ^ (((pid) & 0xFFFF0000u) >> 16u) ^ ((pid) & 0xFFFFu)) < 8u)

// CalcShininessByOtIdAndPersonality
BOOL sub_02017ED8(u32 otId, u32 pid)
{
    return SHINY_CHECK(otId, pid);
}

// GetMonGender
u8 sub_02017F00(Pokemon *mon)
{
    return sub_02017F08(&mon->box);
}

// GetBoxMonGender
u8 sub_02017F08(BoxPokemon *boxMon)
{
    u16 species;
    u32 form;
    u32 pid;
    BOOL locked = sub_02017DBC(boxMon);
    species = (u16)sub_02017E88(boxMon, 5, NULL);
    form = sub_02017E88(boxMon, 0x6F, NULL);
    pid = sub_02017E88(boxMon, 0, NULL);
    sub_02017DE4(boxMon, locked);
    return sub_02017F50(species, (u16)form, pid);
}

// GetGenderBySpeciesAndPersonality
u8 sub_02017F50(u16 species, u16 form, u32 pid)
{
    u8 ratio = (u8)sub_0201AE1C(sub_02019C54(species, form), 0x14);
    switch (ratio) {
    case 0:
        return 0;
    case 0xFE:
        return 1;
    case 0xFF:
        return 2;
    }
    if ((u8)pid < ratio) {
        return 1;
    } else {
        return 0;
    }
}

// GetMonStatus
u32 sub_02017F90(Pokemon *mon)
{
    return sub_02017E1C(mon, 0x9D, NULL);
}

// SetMonStatus
void sub_02017F9C(Pokemon *mon, u32 status)
{
    sub_02017E40(mon, 0x9D, status);
}

BOOL sub_02018D10(Pokemon *mon)
{
    BOOL ret = TRUE;
    if (!mon->box.partyDecrypted) {
        sub_02019A50(&mon->party, sizeof(PartyPokemon), mon->box.pid);
        ret = sub_02018D34(&mon->box);
    }
    return ret;
}

BOOL sub_02018D34(BoxPokemon *boxMon)
{
    u16 checksum;
    BOOL ret = TRUE;
    if (!boxMon->boxDecrypted) {
        sub_02019A50(boxMon->substructs, BOX_BLOCK_SIZE, boxMon->checksum);
        checksum = sub_02019A9C(boxMon->substructs, BOX_BLOCK_SIZE);
        if (checksum != boxMon->checksum) {
            boxMon->checksumFail = TRUE;
            ret = FALSE;
        }
    }
    return ret;
}

void sub_02018D6C(Pokemon *mon)
{
    if (!mon->box.partyDecrypted) {
        sub_02019A50(&mon->party, sizeof(PartyPokemon), mon->box.pid);
        sub_02018D8C(&mon->box);
    }
}

void sub_02018D8C(BoxPokemon *boxMon)
{
    if (!boxMon->boxDecrypted) {
        boxMon->checksum = sub_02019A9C(boxMon->substructs, BOX_BLOCK_SIZE);
        sub_02019A50(boxMon->substructs, BOX_BLOCK_SIZE, boxMon->checksum);
    }
}

// GetMonDataInternal -- party-block fields, everything else falls through to
// the box-mon getter.  Every case here pins one PartyPokemon offset.
u32 sub_02018DB4(Pokemon *mon, int attr, void *dest)
{
    switch (attr) {
    case 157:
        return mon->party.status;
    case 158:
        return mon->party.level;
    case 159:
        return mon->party.capsule;
    case 160:
        return mon->party.hp;
    case 161:
        return mon->party.maxHp;
    case 162:
        return mon->party.atk;
    case 163:
        return mon->party.def;
    case 164:
        return mon->party.speed;
    case 165:
        return mon->party.spAtk;
    case 166:
        return mon->party.spDef;
    case 167:
        sub_02008F3C(mon->party.mail, dest);
        return TRUE;
    case 168:
        return TRUE;
    }
    return sub_02018E34(&mon->box, attr, dest);
}

u32 sub_02018E34(BoxPokemon *boxMon, int attr, void *dest)
{
    u32 ret = 0;
    PokemonDataBlockA *blockA = sub_02019C38(boxMon, boxMon->pid, 0);
    PokemonDataBlockB *blockB = sub_02019C38(boxMon, boxMon->pid, 1);
    PokemonDataBlockC *blockC = sub_02019C38(boxMon, boxMon->pid, 2);
    PokemonDataBlockD *blockD = sub_02019C38(boxMon, boxMon->pid, 3);
    BOOL flag = TRUE;

    switch (attr) {
    default:
        ret = 0;
        break;
    case 0:
        ret = boxMon->pid;
        break;
    case 1:
        ret = boxMon->partyDecrypted;
        break;
    case 2:
        ret = boxMon->boxDecrypted;
        break;
    case 3:
        ret = boxMon->checksumFail;
        break;
    case 4:
        ret = boxMon->checksum;
        break;
    case 169:
        if (blockA->species == 0) {
            flag = FALSE;
        }
        ret = flag;
        break;
    case 170:
        ret = boxMon->checksumFail;
        if (!ret) {
            ret = blockB->isEgg;
        }
        break;
    case 171:
        ret = blockA->species;
        if (ret != 0 && (blockB->isEgg || boxMon->checksumFail)) {
            ret = SPECIES_EGG;
        }
        break;
    case 158:
        ret = sub_0201850C(blockA->species, blockB->form, blockA->exp);
        break;
    case 5:
        if (boxMon->checksumFail) {
            ret = SPECIES_EGG;
        } else {
            ret = blockA->species;
        }
        break;
    case 6:
        ret = blockA->heldItem;
        if (ret > MAX_ITEM) {
            ret = 0;
        }
        break;
    case 7:
        ret = blockA->otId;
        break;
    case 8:
        ret = blockA->exp;
        break;
    case 9:
        ret = blockA->friendship;
        break;
    case 10:
        ret = blockA->ability;
        break;
    case 11:
        ret = blockA->markings;
        break;
    case 12:
        ret = blockA->originLanguage;
        break;
    case 13:
        ret = blockA->hpEV;
        break;
    case 14:
        ret = blockA->atkEV;
        break;
    case 15:
        ret = blockA->defEV;
        break;
    case 16:
        ret = blockA->speedEV;
        break;
    case 17:
        ret = blockA->spAtkEV;
        break;
    case 18:
        ret = blockA->spDefEV;
        break;
    case 19:
        ret = blockA->cool;
        break;
    case 20:
        ret = blockA->beauty;
        break;
    case 21:
        ret = blockA->cute;
        break;
    case 22:
        ret = blockA->smart;
        break;
    case 23:
        ret = blockA->tough;
        break;
    case 24:
        ret = blockA->sheen;
        break;
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
        attr -= 25;
        if (!(blockA->ribbonsDS1 & ((u64)flag << attr))) {
            flag = FALSE;
        }
        ret = flag;
        break;
    case 54:
    case 55:
    case 56:
    case 57:
        attr -= 54;
        ret = blockB->moves[attr];
        break;
    case 58:
    case 59:
    case 60:
    case 61:
        attr -= 58;
        ret = blockB->movePP[attr];
        break;
    case 62:
    case 63:
    case 64:
    case 65:
        attr -= 62;
        ret = blockB->movePpUps[attr];
        break;
    case 66:
    case 67:
    case 68:
    case 69:
        attr -= 66;
        if (blockB->moves[attr] != 0) {
            ret = sub_0201C158(blockB->moves[attr], blockB->movePpUps[attr]);
        }
        break;
    case 70:
        ret = blockB->hpIV;
        break;
    case 71:
        ret = blockB->atkIV;
        break;
    case 72:
        ret = blockB->defIV;
        break;
    case 73:
        ret = blockB->speedIV;
        break;
    case 74:
        ret = blockB->spAtkIV;
        break;
    case 75:
        ret = blockB->spDefIV;
        break;
    case 76:
        ret = boxMon->checksumFail;
        if (!ret) {
            ret = blockB->isEgg;
        }
        break;
    case 117:
        ret = blockB->hasNickname;
        break;
    case 77:
    case 78:
    case 79:
    case 80:
    case 81:
    case 82:
    case 83:
    case 84:
    case 85:
    case 86:
    case 87:
    case 88:
    case 89:
    case 90:
    case 91:
    case 92:
    case 93:
    case 94:
    case 95:
    case 96:
    case 97:
    case 98:
    case 99:
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
    case 105:
    case 106:
    case 107:
    case 108:
        attr -= 77;
        if (!(blockB->ribbonsGBA & ((u64)flag << attr))) {
            flag = FALSE;
        }
        ret = flag;
        break;
    case 109:
        ret = blockB->fatefulEncounter;
        break;
    case 110:
        ret = sub_02017F50(blockA->species, blockB->form, boxMon->pid);
        blockB->gender = (u8)ret;
        boxMon->checksum = sub_02019A9C(boxMon->substructs, BOX_BLOCK_SIZE);
        break;
    case 111:
        ret = blockB->form;
        break;
    case 112:
        ret = blockB->nature;
        break;
    case 113:
        ret = blockB->hasDreamWorldAbility;
        break;
    case 114:
        ret = blockB->unk_1C;
        break;
    case 115:
        if (boxMon->checksumFail) {
            sub_02045CAC(_020A7370, SPECIES_EGG + 1, dest);
        } else {
            sub_02045924(dest, blockC->nickname);
        }
        break;
    case 116:
        if (boxMon->checksumFail) {
            sub_02045F5C(_020A7370, SPECIES_EGG + 1, dest, 11);
        } else {
            sub_0201F41C(blockC->nickname, dest, 11);
        }
        break;
    case 118:
        ret = blockC->unk_16;
        break;
    case 119:
        ret = blockC->originGame;
        break;
    case 120:
    case 121:
    case 122:
    case 123:
    case 124:
    case 125:
    case 126:
    case 127:
    case 128:
    case 129:
    case 130:
    case 131:
    case 132:
    case 133:
    case 134:
    case 135:
    case 136:
    case 137:
    case 138:
    case 139:
    case 140:
        attr -= 120;
        if (!(blockC->ribbonsDS2 & ((u64)flag << attr))) {
            flag = FALSE;
        }
        ret = flag;
        break;
    case 141:
        sub_02045924(dest, blockD->otName);
        break;
    case 142:
        sub_0201F41C(blockD->otName, dest, 8);
        break;
    case 143:
        ret = blockD->eggYear;
        break;
    case 144:
        ret = blockD->eggMonth;
        break;
    case 145:
        ret = blockD->eggDay;
        break;
    case 146:
        ret = blockD->metYear;
        break;
    case 147:
        ret = blockD->metMonth;
        break;
    case 148:
        ret = blockD->metDay;
        break;
    case 149:
        ret = blockD->eggLocation;
        break;
    case 150:
        ret = blockD->metLocation;
        break;
    case 151:
        ret = blockD->pokerus;
        break;
    case 152:
        ret = blockD->pokeball;
        break;
    case 153:
        ret = blockD->metLevel;
        break;
    case 154:
        ret = blockD->otGender;
        break;
    case 155:
        ret = blockD->encounterType;
        break;
    case 156:
        ret = blockD->pokeballHgss;
        break;
    case 172:
        ret = blockB->hpIV | (blockB->atkIV << 5) | (blockB->defIV << 10) | (blockB->speedIV << 15) | (blockB->spAtkIV << 20) | (blockB->spDefIV << 25);
        break;
    case 173:
        if ((blockA->species == 29 || blockA->species == 32) && !blockB->hasNickname) {
            ret = FALSE;
        } else {
            ret = TRUE;
        }
        break;
    case 174:
    case 175:
        if (blockA->species == SPECIES_ARCEUS && blockA->ability == ABILITY_MULTITYPE) {
            ret = sub_02019BBC(blockA->heldItem);
        } else {
            attr -= 168;
            ret = sub_02019C90(blockA->species, blockB->form, attr);
        }
        break;
    }
    return ret;
}

// SetMonDataInternal -- note the third argument is the value itself, not a
// pointer to it (a gen-5 change from gen 4's `const void *`).
void sub_02019308(Pokemon *mon, int attr, u32 value)
{
    switch (attr) {
    case 157:
        mon->party.status = value;
        break;
    case 158:
        mon->party.level = (u8)value;
        break;
    case 159:
        mon->party.capsule = (u8)value;
        break;
    case 160:
        mon->party.hp = (u16)value;
        break;
    case 161:
        mon->party.maxHp = (u16)value;
        break;
    case 162:
        mon->party.atk = (u16)value;
        break;
    case 163:
        mon->party.def = (u16)value;
        break;
    case 164:
        mon->party.speed = (u16)value;
        break;
    case 165:
        mon->party.spAtk = (u16)value;
        break;
    case 166:
        mon->party.spDef = (u16)value;
        break;
    case 167:
        sub_02008F3C((void *)value, mon->party.mail);
        break;
    case 168:
        break;
    default:
        sub_02019388(&mon->box, attr, value);
        break;
    }
}

void sub_02019388(BoxPokemon *boxMon, int attr, u32 value)
{
    PokemonDataBlockA *blockA = sub_02019C38(boxMon, boxMon->pid, 0);
    PokemonDataBlockB *blockB = sub_02019C38(boxMon, boxMon->pid, 1);
    PokemonDataBlockC *blockC = sub_02019C38(boxMon, boxMon->pid, 2);
    PokemonDataBlockD *blockD = sub_02019C38(boxMon, boxMon->pid, 3);
    s64 mask;

    switch (attr) {
    case 0:
        boxMon->pid = value;
        break;
    case 1:
        boxMon->partyDecrypted = value;
        break;
    case 2:
        boxMon->boxDecrypted = value;
        break;
    case 3:
        boxMon->checksumFail = value;
        break;
    case 4:
        boxMon->checksum = (u16)value;
        break;
    case 5:
        blockA->species = (u16)value;
        break;
    case 6:
        if (value <= MAX_ITEM) {
            blockA->heldItem = (u16)value;
        }
        break;
    case 7:
        blockA->otId = value;
        break;
    case 8:
        blockA->exp = value;
        break;
    case 9:
        blockA->friendship = (u8)value;
        break;
    case 10:
        blockA->ability = (u8)value;
        break;
    case 11:
        blockA->markings = (u8)value;
        break;
    case 12:
        blockA->originLanguage = (u8)value;
        break;
    case 13: {
        s32 cur = blockA->hpEV;
        s32 room = MAX_EV_TOTAL - (blockA->hpEV + blockA->atkEV + blockA->defEV + blockA->speedEV + blockA->spAtkEV + blockA->spDefEV);
        if ((s32)(value - cur) > room) {
            value = cur + room;
        }
        if (value > 255) {
            value = 255;
        }
        blockA->hpEV = (u8)value;
    } break;
    case 14: {
        s32 cur = blockA->atkEV;
        s32 room = MAX_EV_TOTAL - (blockA->hpEV + blockA->atkEV + blockA->defEV + blockA->speedEV + blockA->spAtkEV + blockA->spDefEV);
        if ((s32)(value - cur) > room) {
            value = cur + room;
        }
        if (value > 255) {
            value = 255;
        }
        blockA->atkEV = (u8)value;
    } break;
    case 15: {
        s32 cur = blockA->defEV;
        s32 room = MAX_EV_TOTAL - (blockA->hpEV + blockA->atkEV + blockA->defEV + blockA->speedEV + blockA->spAtkEV + blockA->spDefEV);
        if ((s32)(value - cur) > room) {
            value = cur + room;
        }
        if (value > 255) {
            value = 255;
        }
        blockA->defEV = (u8)value;
    } break;
    case 16: {
        s32 cur = blockA->speedEV;
        s32 room = MAX_EV_TOTAL - (blockA->hpEV + blockA->atkEV + blockA->defEV + blockA->speedEV + blockA->spAtkEV + blockA->spDefEV);
        if ((s32)(value - cur) > room) {
            value = cur + room;
        }
        if (value > 255) {
            value = 255;
        }
        blockA->speedEV = (u8)value;
    } break;
    case 17: {
        s32 cur = blockA->spAtkEV;
        s32 room = MAX_EV_TOTAL - (blockA->hpEV + blockA->atkEV + blockA->defEV + blockA->speedEV + blockA->spAtkEV + blockA->spDefEV);
        if ((s32)(value - cur) > room) {
            value = cur + room;
        }
        if (value > 255) {
            value = 255;
        }
        blockA->spAtkEV = (u8)value;
    } break;
    case 18: {
        s32 cur = blockA->spDefEV;
        s32 room = MAX_EV_TOTAL - (blockA->hpEV + blockA->atkEV + blockA->defEV + blockA->speedEV + blockA->spAtkEV + blockA->spDefEV);
        if ((s32)(value - cur) > room) {
            value = cur + room;
        }
        if (value > 255) {
            value = 255;
        }
        blockA->spDefEV = (u8)value;
    } break;
    case 19:
        blockA->cool = (u8)value;
        break;
    case 20:
        blockA->beauty = (u8)value;
        break;
    case 21:
        blockA->cute = (u8)value;
        break;
    case 22:
        blockA->smart = (u8)value;
        break;
    case 23:
        blockA->tough = (u8)value;
        break;
    case 24:
        blockA->sheen = (u8)value;
        break;
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
        attr -= 25;
        mask = 1 << attr;
        if (value) {
            blockA->ribbonsDS1 |= mask;
        } else {
            blockA->ribbonsDS1 &= mask ^ 0xFFFFFFFF;
        }
        break;
    case 54:
    case 55:
    case 56:
    case 57:
        attr -= 54;
        blockB->moves[attr] = (u16)value;
        break;
    case 58:
    case 59:
    case 60:
    case 61:
        attr -= 58;
        blockB->movePP[attr] = (u8)value;
        break;
    case 62:
    case 63:
    case 64:
    case 65:
        attr -= 62;
        blockB->movePpUps[attr] = (u8)value;
        break;
    case 70:
        blockB->hpIV = value;
        break;
    case 71:
        blockB->atkIV = value;
        break;
    case 72:
        blockB->defIV = value;
        break;
    case 73:
        blockB->speedIV = value;
        break;
    case 74:
        blockB->spAtkIV = value;
        break;
    case 75:
        blockB->spDefIV = value;
        break;
    case 76:
        blockB->isEgg = value;
        break;
    case 77:
    case 78:
    case 79:
    case 80:
    case 81:
    case 82:
    case 83:
    case 84:
    case 85:
    case 86:
    case 87:
    case 88:
    case 89:
    case 90:
    case 91:
    case 92:
    case 93:
    case 94:
    case 95:
    case 96:
    case 97:
    case 98:
    case 99:
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
    case 105:
    case 106:
    case 107:
    case 108:
        attr -= 77;
        mask = 1 << attr;
        if (value) {
            blockB->ribbonsGBA |= mask;
        } else {
            blockB->ribbonsGBA &= mask ^ 0xFFFFFFFF;
        }
        break;
    case 109:
        blockB->fatefulEncounter = value;
        break;
    case 110:
        blockB->gender = sub_02017F50(blockA->species, blockB->form, boxMon->pid);
        break;
    case 111:
        blockB->form = value;
        break;
    case 112:
        blockB->nature = (u8)value;
        break;
    case 113:
        blockB->hasDreamWorldAbility = value;
        break;
    case 114:
        blockB->unk_1C = value;
        break;
    case 115:
        sub_02045A38((void *)value, blockC->nickname, 11);
        blockB->hasNickname = sub_02019ABC(boxMon);
        break;
    case 116:
        sub_0201F41C((void *)value, blockC->nickname, 11);
        blockB->hasNickname = sub_02019ABC(boxMon);
        break;
    case 176:
        sub_02045A38((void *)value, blockC->nickname, 11);
        break;
    case 177:
        sub_0201F41C((void *)value, blockC->nickname, 11);
        break;
    case 118:
        blockC->unk_16 = (u8)value;
        break;
    case 119:
        blockC->originGame = (u8)value;
        break;
    case 120:
    case 121:
    case 122:
    case 123:
    case 124:
    case 125:
    case 126:
    case 127:
    case 128:
    case 129:
    case 130:
    case 131:
    case 132:
    case 133:
    case 134:
    case 135:
    case 136:
    case 137:
    case 138:
    case 139:
    case 140:
        attr -= 120;
        mask = 1 << attr;
        if (value) {
            blockC->ribbonsDS2 |= mask;
        } else {
            blockC->ribbonsDS2 &= mask ^ 0xFFFFFFFFFFFFFFFF;
        }
        break;
    case 141:
        sub_02045A38((void *)value, blockD->otName, 8);
        break;
    case 142:
        sub_0201F41C((void *)value, blockD->otName, 8);
        break;
    case 143:
        blockD->eggYear = (u8)value;
        break;
    case 144:
        blockD->eggMonth = (u8)value;
        break;
    case 145:
        blockD->eggDay = (u8)value;
        break;
    case 146:
        blockD->metYear = (u8)value;
        break;
    case 147:
        blockD->metMonth = (u8)value;
        break;
    case 148:
        blockD->metDay = (u8)value;
        break;
    case 149:
        blockD->eggLocation = (u16)value;
        break;
    case 150:
        blockD->metLocation = (u16)value;
        break;
    case 151:
        blockD->pokerus = (u8)value;
        break;
    case 152:
        blockD->pokeball = (u8)value;
        break;
    case 153:
        blockD->metLevel = (u8)value;
        break;
    case 154:
        blockD->otGender = (u8)value;
        break;
    case 155:
        blockD->encounterType = (u8)value;
        break;
    case 156:
        blockD->pokeballHgss = (u16)value;
        break;
    case 172:
        blockB->hpIV = (u8)(value & 0x1F);
        blockB->atkIV = (u8)((value >> 5) & 0x1F);
        blockB->defIV = (u8)((value >> 10) & 0x1F);
        blockB->spAtkIV = (u8)((value >> 15) & 0x1F);
        blockB->spDefIV = (u8)((value >> 20) & 0x1F);
        blockB->speedIV = (u8)((value >> 25) & 0x1F);
        break;
    }
}

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
