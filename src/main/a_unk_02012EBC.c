#include "types.h"

/* A large aggregate whose accessors run 0x02012EBC..0x02012FF0. Only the
 * offsets these functions touch are known; everything else is filler.
 *   +0x000 pointer to the save data (every sub_020071CC / sub_0200C0F0 /
 *          sub_02009EC8 ... forwarder loads it first)
 *   +0x1CF u8
 *   +0x5EC, +0x680, +0x694, +0x6A4 sub-objects returned by address
 *   +0x684, +0x688, +0x6A8 u32 fields, +0x6AC a pointer
 */
typedef struct UnkStruct02012EBC
{
    /* 0x000 */ void *unk000;
    /* 0x004 */ u8 unk004[0x1CB];
    /* 0x1CF */ u8 unk1CF;
    /* 0x1D0 */ u8 unk1D0[0x41C];
    /* 0x5EC */ u8 unk5EC[0x94];
    /* 0x680 */ u8 unk680[4];
    /* 0x684 */ u32 unk684;
    /* 0x688 */ u32 unk688;
    /* 0x68C */ u8 unk68C[8];
    /* 0x694 */ u8 unk694[0x10];
    /* 0x6A4 */ u8 unk6A4[4];
    /* 0x6A8 */ u32 unk6A8;
    /* 0x6AC */ void *unk6AC;
} UnkStruct02012EBC;

void *sub_020071CC(void *a0, int a1);
void *sub_0200C0F0(void *a0);
/* These five forwarders tail-call through a literal that the ROM stores with
 * bit 0 set (the Thumb interworking bit). triage.json has no entry for the
 * callees, so verify_functions.py cannot know to set that bit for an even
 * `sub_02009EC8`-style name; naming the Thumb entry point directly is what
 * makes the literal come out byte-identical. Rename to the even address once
 * tools/scripts/callsite_modes.py has taught triage their instruction set. */
void *sub_02009EC9(void *a0);  /* 0x02009EC8, Thumb */
void *sub_020089C1(void *a0);  /* 0x020089C0, Thumb */
void *sub_02009449(void *a0);  /* 0x02009448, Thumb */
void *sub_02007B45(void *a0);  /* 0x02007B44, Thumb */
void *sub_020085D5(void *a0, int a1);  /* 0x020085D4, Thumb */

void *sub_02012EBC(UnkStruct02012EBC *a0)
{
    return a0->unk000;
}

void *sub_02012EC0(UnkStruct02012EBC *a0)
{
    return a0->unk000;
}

u8 *sub_02012EC4(UnkStruct02012EBC *a0)
{
    return a0->unk5EC;
}

u8 *sub_02012ED0(UnkStruct02012EBC *a0)
{
    return a0->unk680;
}

u32 sub_02012ED8(UnkStruct02012EBC *a0)
{
    return a0->unk688;
}

void sub_02012EE4(UnkStruct02012EBC *a0, u32 a1)
{
    a0->unk688 = a1;
}

void *sub_02012EF0(UnkStruct02012EBC *a0)
{
    return sub_020071CC(a0->unk000, 0x3A);
}

void *sub_02012EFC(UnkStruct02012EBC *a0)
{
    return sub_020071CC(a0->unk000, 0x3B);
}

void *sub_02012F08(UnkStruct02012EBC *a0)
{
    return sub_0200C0F0(a0->unk000);
}

void *sub_02012F14(UnkStruct02012EBC *a0)
{
    return sub_02009EC9(a0->unk000);
}

u32 sub_02012F20(UnkStruct02012EBC *a0)
{
    return a0->unk684;
}

void *sub_02012F2C(UnkStruct02012EBC *a0)
{
    return sub_020071CC(a0->unk000, 0x26);
}

u8 *sub_02012F38(UnkStruct02012EBC *a0)
{
    return a0->unk694;
}

void *sub_02012F44(UnkStruct02012EBC *a0)
{
    return sub_020071CC(a0->unk000, 0x2A);
}

u8 *sub_02012F50(UnkStruct02012EBC *a0)
{
    return a0->unk6A4;
}

void *sub_02012F5C(UnkStruct02012EBC *a0)
{
    return sub_020089C1(a0->unk000);
}

void *sub_02012F68(UnkStruct02012EBC *a0)
{
    return sub_020071CC(a0->unk000, 0x42);
}

void sub_02012F74(UnkStruct02012EBC *a0, u32 a1)
{
    a0->unk6A8 = a1;
}

u32 sub_02012F80(UnkStruct02012EBC *a0)
{
    return a0->unk6A8;
}

void *sub_02012F8C(UnkStruct02012EBC *a0)
{
    return sub_02009449(a0->unk000);
}

void *sub_02012F98(UnkStruct02012EBC *a0)
{
    return sub_02007B45(a0->unk000);
}

void sub_02012FA4(UnkStruct02012EBC *a0, u8 a1)
{
    a0->unk1CF = a1;
}

u8 sub_02012FB0(UnkStruct02012EBC *a0)
{
    return a0->unk1CF;
}

void *sub_02012FBC(UnkStruct02012EBC *a0, int a1)
{
    return sub_020085D5(a0->unk6AC, a1);
}

void *sub_02012FCC(UnkStruct02012EBC *a0)
{
    return a0->unk6AC;
}

void *sub_02012FD8(UnkStruct02012EBC *a0)
{
    return sub_020071CC(a0->unk000, 0x43);
}

void *sub_02012FE4(void *a0)
{
    return sub_020071CC(a0, 0x2D);
}
