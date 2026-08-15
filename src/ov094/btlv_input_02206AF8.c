#include "types.h"

// 0x020061E4 is PlaySE(seqNo): tail-calls 0x020061A4(seqNo, -1), which checks
// the sound-enabled flag, resolves the player for the sequence and starts it
// through NNS_SndArcPlayerStartSeq.
void sub_020061E4(u16 seqNo);

typedef struct UnkStruct_02206AF8
{
    u8 unk00[0x54];
    u32 unk54;
    u32 unk58;
} UnkStruct_02206AF8;

void sub_02206AF8(UnkStruct_02206AF8 *p)
{
    if (p->unk54 != 3 || p->unk58 == 6)
    {
        sub_020061E4(0x555);
    }
}

void sub_02206B14(UnkStruct_02206AF8 *p)
{
    if (p->unk54 != 3 || p->unk58 == 6)
    {
        sub_020061E4(0x548);
    }
}

void sub_02206B30(UnkStruct_02206AF8 *p)
{
    if (p->unk58 != 6)
    {
        if (p->unk54 != 3)
        {
            sub_020061E4(0x54D);
        }
    }
    else
    {
        sub_020061E4(0x54C);
    }
}

void sub_02206B58(UnkStruct_02206AF8 *p)
{
    if (p->unk54 != 3 || p->unk58 == 6)
    {
        sub_020061E4(0x552);
    }
}

void sub_02206B74(UnkStruct_02206AF8 *p)
{
    if (p->unk54 != 3 || p->unk58 == 6)
    {
        sub_020061E4(0x579);
    }
}

void sub_02206B90(UnkStruct_02206AF8 *p)
{
    if (p->unk54 != 3 || p->unk58 == 6)
    {
        sub_020061E4(0x54D);
    }
}

void sub_02206BAC(UnkStruct_02206AF8 *p)
{
    if (p->unk54 != 3 || p->unk58 == 6)
    {
        sub_020061E4(0x557);
    }
}
