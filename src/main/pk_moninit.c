/*
 * ZeroMonData / ZeroBoxMonData.  main, 0x02017528..0x0201756C.
 * These two pin sizeof(Pokemon) == 0xDC and sizeof(BoxPokemon) == 0x88.
 * Compiler: repo default (dsi/1.1), Thumb.
 */
#include "types.h"
#include "pk_pokemon.h"

void MIi_CpuClearFast(u32 data, void *dest, u32 size);
void sub_02019A50(void *data, u32 size, u32 seed);

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
