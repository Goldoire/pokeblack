#include "types.h"

/* sub_020071CC(save, 0x1B) hands back this record. Offsets in evidence:
 *   +0x24 a sub-object returned by pointer (sub_02008748)
 *   +0x2C a u8 flag (sub_02008754 reads it, 0x02008764 / 0x02008774 set and
 *         clear it)
 *   +0x30 a u16 array indexed by the second argument, whose "valid" value is
 *         0xC21E (sub_02008784 / 0x020087A8 / 0x020087C0)
 */
typedef struct UnkStruct020071CC
{
    /* 0x00 */ u8 unk00[0x24];
    /* 0x24 */ u8 unk24[8];
    /* 0x2C */ u8 unk2C;
    /* 0x2D */ u8 unk2D[3];
    /* 0x30 */ u16 unk30[2];
} UnkStruct020071CC;

UnkStruct020071CC *sub_020071CC(void *a0, int a1);

UnkStruct020071CC *sub_0200873C(void *a0)
{
    return sub_020071CC(a0, 0x1B);
}

u8 *sub_02008748(void *a0)
{
    return sub_020071CC(a0, 0x1B)->unk24;
}

u8 sub_02008754(void *a0)
{
    return sub_020071CC(a0, 0x1B)->unk2C;
}

void sub_02008764(void *a0)
{
    sub_020071CC(a0, 0x1B)->unk2C = 1;
}

void sub_02008774(void *a0)
{
    sub_020071CC(a0, 0x1B)->unk2C = 0;
}

int sub_02008784(void *a0, int a1)
{
    if (sub_020071CC(a0, 0x1B)->unk30[a1] == 0xC21E)
    {
        return 1;
    }
    return 0;
}

void sub_020087A8(void *a0, int a1)
{
    sub_020071CC(a0, 0x1B)->unk30[a1] = 0xC21E;
}

void sub_020087C0(void *a0, int a1)
{
    sub_020071CC(a0, 0x1B)->unk30[a1] = 0;
}
