#ifndef OV135_WORLDTRADE_H
#define OV135_WORLDTRADE_H

#include "types.h"

/* Overlay 135 is the Global Trade Station.  The original translation units are
 * named in the overlay's .rodata (assert strings): worldtrade.c,
 * worldtrade_box.c, worldtrade_demo.c, worldtrade_deposit.c,
 * worldtrade_enter.c, worldtrade_input.c, worldtrade_search.c,
 * worldtrade_status.c, worldtrade_sublcd.c, worldtrade_adapter.c.
 *
 * Everything below is reconstructed from the reference bytes.  Each named
 * field is constrained by at least one byte-verified function (listed in the
 * comment); the pads are unknown and must not be assumed to be single objects.
 */

/* Sub-object embedded at WorldTradeWork+0x0FA0, driven by the
 * worldtrade_adapter.c routines at 0x022028xx-0x022029xx. */
typedef struct WorldTradeAdapter
{
    u8 pad_0000[0x10];
    void *unk_0010; /* sub_02202840 */
} WorldTradeAdapter;

/* 0x128-byte "trade slot" record.  Nine of them live back-to-back at
 * WorldTradeWork+0x00E4 and exactly fill the gap up to 0x0B4C, which is what
 * pins both the stride and the count:
 *   sub_021F7338 returns &slot[0] for selectors 8/10 and
 *   &slot[1 + work->unk_00D4] (base 0x020C, stride 0x128) for selector 9. */
typedef struct WorldTradeSlot
{
    u8 pad_0000[0xEC];
    u16 unk_00EC; /* sub_021F8668 copies 0x0B4C..0x0B54 into 0xEC..0xF4 */
    u16 unk_00EE;
    u16 unk_00F0;
    u16 unk_00F2;
    u16 unk_00F4;
    u8 pad_00F6[0x128 - 0xF6];
} WorldTradeSlot;

typedef struct WorldTradeWork
{
    void **unk_0000;  /* [2] and [3] are subsystem handles; +0x40 is a save ptr */
    u8 pad_0004[0x10 - 0x04];
    u32 unk_0010;     /* sub_021F8A18: zero => return 4 */
    u32 unk_0014;     /* sub_021F632C / sub_021F7F14: entry-mode selector */
    u32 unk_0018;     /* sub_02200450 */
    u8 pad_001C[0x20 - 0x1C];
    u32 unk_0020;     /* sub_021F89B4: 0x13/0x15 => state 2, 0x14 => state 4 */
    u8 pad_0024[0x28 - 0x24];
    u32 state;        /* index into the 0x02203B0C / 0x02203BBC jump tables */
    u32 unk_002C;     /* "next state" latch, written with state by sub_021F4E98 */
    u16 unk_0030;     /* sub_021F8A44 */
    u8 pad_0032[0xBC - 0x32];
    u16 unk_00BC;     /* sub_021F7CDC / sub_021F7DA8 store 0xFFFF */
    u8 pad_00BE[0xC4 - 0xBE];
    u16 unk_00C4;     /* sub_021F656C */
    u16 unk_00C6;
    u32 unk_00C8;     /* sub_021F6E08: box/party count */
    u32 unk_00CC;     /* sub_021F656C */
    u8 pad_00D0[0xD4 - 0xD0];
    u32 unk_00D4;     /* sub_021F7338: slot index */
    void *unk_00D8;   /* sub_021F7268: ENV resource set */
    u8 pad_00DC[0xE4 - 0xDC];
    WorldTradeSlot unk_00E4[9];
    u16 unk_0B4C;     /* sub_021F8668 */
    u16 unk_0B4E;
    u16 unk_0B50;
    u16 unk_0B52;
    u16 unk_0B54;
    u8 pad_0B56[0xB6C - 0xB56];
    void *unk_0B6C;   /* sub_021F5FC0: message/window handle */
    u8 pad_0B70[0xB88 - 0xB70];
    void *unk_0B88;   /* sub_0220040C */
    void *unk_0B8C;
    u8 pad_0B90[0xBF4 - 0xB90];
    void *unk_0BF4;   /* sub_022004F0 */
    u8 pad_0BF8[0xD40 - 0xBF8];
    void *unk_0D40;   /* sub_021F4FA4 */
    u8 pad_0D44[4];
    void *unk_0D48;   /* sub_022003BC */
    u8 pad_0D4C[4];
    void *unk_0D50[3];
    u8 pad_0D5C[0xDD0 - 0xD5C];
    void *unk_0DD0;   /* sub_021F643C */
    u8 pad_0DD4[0xDE0 - 0xDD4];
    void *unk_0DE0;
    void *unk_0DE4;   /* sub_021F7A70 */
    void *unk_0DE8;   /* sub_021F5FC0 */
    u8 pad_0DEC[0xDF8 - 0xDEC];
    void *unk_0DF8;   /* sub_021F4FA4 */
    u8 pad_0DFC[0xE04 - 0xDFC];
    void *unk_0E04;   /* sub_021F4CE4 */
    void *unk_0E08;
    u8 pad_0E0C[0xE18 - 0xE0C];
    u16 unk_0E18;     /* sub_02200450: quit requested */
    u8 pad_0E1A[0xEA4 - 0xE1A];
    void *unk_0EA4;   /* sub_021F7268 */
    u8 pad_0EA8[0xEB2 - 0xEA8];
    u16 unk_0EB2;     /* sub_021F8A44 */
    u32 unk_0EB4;     /* sub_021F632C / sub_021F7EC0 */
    u8 pad_0EB8[0xF18 - 0xEB8];
    u8 unk_0F18;      /* sub_021F8BBC: sub-object, +0x64 is a second one */
    u8 pad_0F19[0xF7C - 0xF19];
    u8 unk_0F7C;
    u8 pad_0F7D[0xF88 - 0xF7D];
    u16 unk_0F88;     /* sub_021F89F0 clears on state change */
    u16 unk_0F8A;
    u32 unk_0F8C;     /* sub_021F8BBC */
    u8 pad_0F90[0xFA0 - 0xF90];
    WorldTradeAdapter unk_0FA0;
    u8 pad_0FB4[0x10DC - (0xFA0 + sizeof(WorldTradeAdapter))];
    void *unk_10DC;   /* sub_021F7268 */
    u8 pad_10E0[0x12F4 - 0x10E0];
    u32 unk_12F4;     /* sub_021F8DA4 / sub_021F8E58 gate */
    u32 unk_12F8;
} WorldTradeWork;

#endif /* OV135_WORLDTRADE_H */
