/*
 * Pokemon lock / Get-Set entry points.  main, 0x02017D30..0x02017FA8.
 * Compiler: repo default (dsi/1.1), Thumb.
 */
#include "types.h"
#include "pk_pokemon.h"

void sub_02019A50(void *data, u32 size, u32 seed);
u16 sub_02019A9C(void *data, u32 size);

BOOL sub_02018D10(Pokemon *mon);
void sub_02018D6C(Pokemon *mon);
BOOL sub_02018D34(BoxPokemon *boxMon);
void sub_02018D8C(BoxPokemon *boxMon);
u32 sub_02018DB4(Pokemon *mon, int attr, void *dest);
void sub_02019308(Pokemon *mon, int attr, u32 value);
u32 sub_02018E34(BoxPokemon *boxMon, int attr, void *dest);
void sub_02019388(BoxPokemon *boxMon, int attr, u32 value);

BOOL sub_02017DBC(BoxPokemon *boxMon);
BOOL sub_02017DE4(BoxPokemon *boxMon, BOOL locked);
u32 sub_02017E88(BoxPokemon *boxMon, int attr, void *dest);
BOOL sub_02017EB4(BoxPokemon *boxMon);
BOOL sub_02017ED8(u32 otId, u32 pid);
u8 sub_02017F08(BoxPokemon *boxMon);
u8 sub_02017F50(u16 species, u16 form, u32 pid);

void *sub_02019C54(u16 species, u16 form);
u32 sub_0201AE1C(void *personal, int attr);

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
