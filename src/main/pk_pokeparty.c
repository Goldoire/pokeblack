/*
 * pokeparty.c -- the Party container.  main, 0x0201A918..0x0201AE10.
 * (main_tu_map.json puts the TU start at 0x0201A944, but that is the address
 *  of the first *literal-pool word* referencing "pokeparty.c"; the two
 *  functions before it, 0x0201A918 and 0x0201A920, are Party_GetSize and
 *  Party_New and the pool word at 0x0201A944 is inside Party_New's own pool.
 *  Real TU start is 0x0201A918.)
 * Compiler: repo default (dsi/1.1), Thumb.
 */
#include "types.h"
#include "pk_pokemon.h"

void MIi_CpuClearFast(u32 data, void *dest, u32 size);
void *sub_02030734(u32 heapId, u32 size, u32 a2, const char *file, u32 line);
void sub_02017528(Pokemon *mon);
void sub_0201ACDC(Party *party, int idx, u32 a2);
u32 sub_02017E1C(Pokemon *mon, int attr, void *dest);

void sub_0201A948(Party *party);
void sub_0201A954(Party *party, int maxCount);
int sub_0201AA18(Party *party);
Pokemon *sub_0201AB28(Party *party, int idx);

// "pokeparty.c" -- the debug allocator's __FILE__ argument
extern const char _020A7304[];

u32 sub_0201A918(void)
{
    return sizeof(Party);
}

Party *sub_0201A920(u32 heapId)
{
    Party *party = sub_02030734(heapId, sizeof(Party), 0, _020A7304, 0x41);
    sub_0201A948(party);
    return party;
}

void sub_0201A948(Party *party)
{
    sub_0201A954(party, PARTY_SIZE);
}

void sub_0201A954(Party *party, int maxCount)
{
    int i;

    MIi_CpuClearFast(0, party, sizeof(Party));
    party->maxCount = maxCount;
    party->curCount = 0;
    party->unk_530 = 0;
    for (i = 0; i < PARTY_SIZE; i++) {
        sub_02017528(&party->mons[i]);
    }
}

BOOL sub_0201A98C(Party *party, Pokemon *mon)
{
    if (party->curCount >= party->maxCount) {
        return FALSE;
    }
    party->mons[party->curCount] = *mon;
    sub_0201ACDC(party, party->curCount, 1);
    party->curCount++;
    return TRUE;
}

BOOL sub_0201A9C8(Party *party, int idx)
{
    while (idx < party->curCount - 1) {
        party->mons[idx] = party->mons[idx + 1];
        idx++;
    }
    sub_02017528(&party->mons[idx]);
    party->curCount--;
    return TRUE;
}

int sub_0201AA14(Party *party)
{
    return party->maxCount;
}

int sub_0201AA18(Party *party)
{
    return party->curCount;
}

int sub_0201AA1C(Party *party)
{
    int i;
    int count = 0;
    int n = sub_0201AA18(party);

    for (i = 0; i < n; i++) {
        if (sub_02017E1C(sub_0201AB28(party, i), 76, NULL) != TRUE) {
            count++;
        }
    }
    return count;
}

Pokemon *sub_0201AB28(Party *party, int idx)
{
    return &party->mons[idx];
}
