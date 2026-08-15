/*
 * Pokemon / BoxPokemon lock + accessor core.  main, 0x02018D10..0x02018DB4.
 * Compiler: repo default (dsi/1.1), Thumb.
 */
#include "types.h"
#include "pk_pokemon.h"

void sub_02019A50(void *data, u32 size, u32 seed);
u16 sub_02019A9C(void *data, u32 size);
void sub_02008F3C(void *src, void *dest);

BOOL sub_02018D34(BoxPokemon *boxMon);
void sub_02018D8C(BoxPokemon *boxMon);
u32 sub_02018E34(BoxPokemon *boxMon, int attr, void *dest);
void sub_02019388(BoxPokemon *boxMon, int attr, u32 value);

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
