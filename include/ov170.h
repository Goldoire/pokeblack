#ifndef POKEBLACK_OV170_H
#define POKEBLACK_OV170_H

#include "global.h"

/*
 * ===========================================================================
 *  ov170 -- menu / panel overlay
 * ===========================================================================
 *
 * Merged from src/ov170/unk_021EE3CC.c and src/ov170/unk_021EF31C.c. Delete
 * the local copies in both files and include this instead.
 *
 * CONFIDENCE: HIGH. `verify_functions.py ov170` reports 51/51 OK, so every
 * offset these files use is byte-exact against the ROM. One of them,
 * Ov170Panel+0x74, is independently confirmed by `evidence.py --module ov170`:
 *
 *     run 0x021ef670..0x021ef68c  (2 functions)
 *       +0x074:4B
 *
 * i.e. the disassembler found a 4-byte access at a constant +0x74 from an
 * untouched argument register inside functions that matched. That is the
 * strongest class of evidence available and it agrees with both workers.
 */

typedef struct Ov170Panel Ov170Panel;

/* ---------------------------------------------------------------------------
 * Ov170Ctx -- 0x30. Both files declared this identically. No conflict.
 * ------------------------------------------------------------------------- */
typedef struct Ov170Ctx {
    u8 unk00[0x2c];   // +0x00 INFERRED (filler)
    Ov170Panel *unk2c;// +0x2C PROVEN -- reached in every function of both files
} Ov170Ctx;

/* ---------------------------------------------------------------------------
 * Ov170Panel -- 0xA16C.
 *
 * CONFLICT RESOLVED: unk_021EE3CC.c declared five fields, unk_021EF31C.c only
 * two. It is a clean superset/subset -- the short version is
 * `u8 unk00[0x74]; void *unk74;`, which is the long version with +0x70 folded
 * back into the leading filler. Neither contradicts the other at any offset,
 * so the five-field form wins and the two-field file loses nothing.
 * ------------------------------------------------------------------------- */
struct Ov170Panel {
    u8 unk00[0x70];              // +0x0000 INFERRED (filler)
    void *unk70;                 // +0x0070 PROVEN -- list-menu object
                                 //   (sub_02025D14 / sub_0202616C / sub_020260E4)
    void *unk74;                 // +0x0074 PROVEN by match AND by evidence.py
                                 //   (+0x074:4B at 0x021EF670..0x021EF68C)
                                 //   slide/window object
    u8 unk78[0xA168 - 0x78];     // +0x0078 INFERRED (filler) -- 41200 bytes of
                                 //   it, so treat the 0xA168 offset as the only
                                 //   claim being made here, not the extent
    u32 unkA168;                 // +0xA168 PROVEN -- saved menu-state id
                                 //   (sub_021EECB0)
};

/* ---------------------------------------------------------------------------
 * Ov170Rec12 -- 12-byte table record. Single-file, folded in for one home.
 * Only the first two bytes are ever touched.
 * ------------------------------------------------------------------------- */
typedef struct Ov170Rec12 {
    u8 unk00;    // +0x00 PROVEN
    u8 unk01;    // +0x01 PROVEN
    u8 unk02[10];// +0x02 INFERRED (filler)
} Ov170Rec12;

#endif // POKEBLACK_OV170_H
