#include "types.h"

// --- externals in main (real RAM names; verifier resolves by address) ---
int sub_0201AA18(void *party);                  // Party_GetCount
void *sub_0201AB28(void *party, int index);     // Party_GetMonByIndex
int sub_0201A9C8(void *party, int index);       // Party_RemoveMonByIndex
void sub_02019CA0(void *mon, int level);        // Pokemon_SetLevel

struct UnkStruct02155224
{
    u8 unk_00[0x38];
    void *unk_38;
    void *unk_3C[4];
};

void sub_02155160(void *party)
{
    int i;

    for (i = 0; i < sub_0201AA18(party); i++)
    {
        sub_02019CA0(sub_0201AB28(party, i), 50);
    }
}

void sub_02155200(void *party)
{
    int i;
    int count = sub_0201AA18(party);

    for (i = 3; i < count; i++)
    {
        sub_0201A9C8(party, 3);
    }
}

void sub_02155224(struct UnkStruct02155224 *param0)
{
    int i;

    sub_02155200(param0->unk_38);

    for (i = 0; i < 4; i++)
    {
        sub_02155200(param0->unk_3C[i]);
    }
}
