/*
 * GetBoxMonDataInternal.  main, 0x02018E34.
 * Compiler: repo default (dsi/1.1), Thumb.
 *
 * This is the keystone: every case pins one substruct field's offset, width
 * and signedness.
 */
#include "types.h"
#include "pk_pokemon.h"

#define SPECIES_EGG    650
#define MAX_ITEM       626
#define SPECIES_ARCEUS 493
#define ABILITY_MULTITYPE 121

void *sub_02019C38(BoxPokemon *boxMon, u32 pid, u8 which);
u16 sub_02019A9C(void *data, u32 size);
u8 sub_02017F50(u16 species, u16 form, u32 pid);
u32 sub_0201850C(u16 species, u8 form, u32 exp);
u32 sub_0201C158(u16 move, u8 ppUp);
u32 sub_02019BBC(u16 item);
u32 sub_02019C90(u16 species, u8 form, int attr);

void sub_02045924(void *dest, const u16 *src);
void sub_02045CAC(void *msgData, u32 msgNo, void *dest);
void sub_02045F5C(void *msgData, u32 msgNo, u16 *dest, u32 count);
void sub_0201F41C(const u16 *src, void *dest, u32 count);

extern void *_020A7370;

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
