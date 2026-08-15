/*
 * SetBoxMonDataInternal.  main, 0x02019388.
 * Compiler: repo default (dsi/1.1), Thumb.
 *
 * Mirror of GetBoxMonDataInternal; confirms every substruct offset from the
 * write side, and pins the field widths through the bitfield store idioms.
 * Note the third argument is the value itself, not a pointer to it.
 */
#include "types.h"
#include "pk_pokemon.h"

#define MAX_ITEM 626
#define MAX_EV_TOTAL 510

void *sub_02019C38(BoxPokemon *boxMon, u32 pid, u8 which);
u8 sub_02017F50(u16 species, u16 form, u32 pid);
BOOL sub_02019ABC(BoxPokemon *boxMon);
void sub_02045A38(void *src, u16 *dest, u32 count);
void sub_0201F41C(const void *src, void *dest, u32 count);

void sub_02019388(BoxPokemon *boxMon, int attr, u32 value)
{
    PokemonDataBlockA *blockA = sub_02019C38(boxMon, boxMon->pid, 0);
    PokemonDataBlockB *blockB = sub_02019C38(boxMon, boxMon->pid, 1);
    PokemonDataBlockC *blockC = sub_02019C38(boxMon, boxMon->pid, 2);
    PokemonDataBlockD *blockD = sub_02019C38(boxMon, boxMon->pid, 3);
    int mask;
    s64 mask64;

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
        mask64 = 1 << attr;
        if (value) {
            blockC->ribbonsDS2 |= mask64;
        } else {
            blockC->ribbonsDS2 &= mask64 ^ 0xFFFFFFFFFFFFFFFF;
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
        blockB->speedIV = (u8)((value >> 15) & 0x1F);
        blockB->spAtkIV = (u8)((value >> 20) & 0x1F);
        blockB->spDefIV = (u8)((value >> 25) & 0x1F);
        break;
    }
}
