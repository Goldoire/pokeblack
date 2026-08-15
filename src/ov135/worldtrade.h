#ifndef OV135_WORLDTRADE_H
#define OV135_WORLDTRADE_H

#include "types.h"

/* Global Trade Station ("worldtrade", overlay 135) main work structure.
 *
 * Reconstructed offset-by-offset from the reference bytes; every named field
 * below is constrained by at least one verified function.  Everything else is
 * padding and MUST NOT be assumed to be a single object.
 *
 *   0x0000  pointer to the field/save context (deref'd then +0x40)  [021F513C]
 *   0x0018  u32, set to 1 by the "exit requested" handler           [02200450]
 *   0x0028  u32 state index into the 0x02203B0C jump table          [021F51F0]
 *   0x002C  u32 written alongside 0x28 by sub_021F4E98              [021F4E98]
 *   0x0B6C  pointer consumed by sub_02045EC0                        [0220040C]
 *   0x0B88  pointer                                                 [0220040C]
 *   0x0B8C  pointer                                                 [0220040C]
 *   0x0BF4  pointer                                                 [022004F0]
 *   0x0D40  pointer, arg1 of sub_0202EE30                           [021F4FA4]
 *   0x0D48  pointer                                                 [022003BC]
 *   0x0D50  pointer[3]                                              [022003BC]
 *   0x0DD0  pointer                                                 [022003BC]
 *   0x0DE0  pointer                                                 [022003BC]
 *   0x0DF8  pointer, result of sub_0202EE30                         [021F4FA4]
 *   0x0E04  pointer, freed with sub_02027FD8                        [021F4CE4]
 *   0x0E08  pointer, freed with sub_02027858 / driven by 0x0202797x [021F4CE4]
 *   0x0E18  u16, non-zero == quit requested                         [02200450]
 *   0x0FA0  sub-object passed to sub_02202940                       [022003BC]
 */
/* The sub-object embedded at WorldTradeWork+0x0FA0, driven by the
 * worldtrade_adapter.c routines at 0x022028xx-0x022029xx. */
typedef struct WorldTradeAdapter
{
    u8 pad_0000[0x10];
    void *unk_0010;
} WorldTradeAdapter;

typedef struct WorldTradeWork
{
    void **unk_0000;
    u8 pad_0004[0x14 - 0x04];
    u32 unk_0014;
    u32 unk_0018;
    u8 pad_001C[0x28 - 0x1C];
    u32 state;
    u32 unk_002C;
    u8 pad_0030[0xBC - 0x30];
    u16 unk_00BC;
    u8 pad_00BE[0xC4 - 0xBE];
    u16 unk_00C4;
    u16 unk_00C6;
    u32 unk_00C8;
    u32 unk_00CC;
    u8 pad_00D0[0xD4 - 0xD0];
    u32 unk_00D4;
    void *unk_00D8;
    u8 pad_00DC[0xE4 - 0xDC];
    /* 0x0128-byte slots run from 0x00E4; slot 0 is the "own" entry and
     * slot 1+n (base 0x020C) is indexed by unk_00D4.  See sub_021F7338. */
    u8 unk_00E4;
    u8 pad_00E5[0xB6C - 0xE5];
    void *unk_0B6C;
    u8 pad_0B70[0xB88 - 0xB70];
    void *unk_0B88;
    void *unk_0B8C;
    u8 pad_0B90[0xBF4 - 0xB90];
    void *unk_0BF4;
    u8 pad_0BF8[0xD40 - 0xBF8];
    void *unk_0D40;
    u8 pad_0D44[4];
    void *unk_0D48;
    u8 pad_0D4C[4];
    void *unk_0D50[3];
    u8 pad_0D5C[0xDD0 - 0xD5C];
    void *unk_0DD0;
    u8 pad_0DD4[0xDE0 - 0xDD4];
    void *unk_0DE0;
    void *unk_0DE4;
    void *unk_0DE8;
    u8 pad_0DEC[0xDF8 - 0xDEC];
    void *unk_0DF8;
    u8 pad_0DFC[0xE04 - 0xDFC];
    void *unk_0E04;
    void *unk_0E08;
    u8 pad_0E0C[0xE18 - 0xE0C];
    u16 unk_0E18;
    u8 pad_0E1A[0xEA4 - 0xE1A];
    void *unk_0EA4;
    u8 pad_0EA8[0xEB4 - 0xEA8];
    u32 unk_0EB4;
    u8 pad_0EB8[0xFA0 - 0xEB8];
    WorldTradeAdapter unk_0FA0;
    u8 pad_0FB4[0x10DC - (0xFA0 + sizeof(WorldTradeAdapter))];
    void *unk_10DC;
    u8 pad_10E0[0x12F8 - 0x10E0];
    u32 unk_12F8;
} WorldTradeWork;

#endif /* OV135_WORLDTRADE_H */
