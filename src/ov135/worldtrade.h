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
typedef struct WorldTradeWork
{
    void **unk_0000;
    u8 pad_0004[0x18 - 0x04];
    u32 unk_0018;
    u8 pad_001C[0x28 - 0x1C];
    u32 state;
    u32 unk_002C;
    u8 pad_0030[0xB6C - 0x30];
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
    u8 pad_0DE4[0xDF8 - 0xDE4];
    void *unk_0DF8;
    u8 pad_0DFC[0xE04 - 0xDFC];
    void *unk_0E04;
    void *unk_0E08;
    u8 pad_0E0C[0xE18 - 0xE0C];
    u16 unk_0E18;
    u8 pad_0E1A[0xFA0 - 0xE1A];
    u8 unk_0FA0;
} WorldTradeWork;

#endif /* OV135_WORLDTRADE_H */
