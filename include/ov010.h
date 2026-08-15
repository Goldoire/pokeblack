#ifndef POKEBLACK_OV010_H
#define POKEBLACK_OV010_H

#include "global.h"

/*
 * ===========================================================================
 *  ov010 -- the 0x0216D410..0x0216D8xx accessor record
 * ===========================================================================
 *
 * Merged from src/ov010/unk_0216D410.c, flags.c, vtable_dispatch.c and
 * unk_0216D910.c. All four verify (25 / 24 / 17 / 10 functions, all N/N OK).
 * Delete the local `UnkStruct0216D410` / `UnkStruct0216D684` /
 * `UnkVtable0216D684` declarations and include this instead.
 *
 * WHY THESE ARE ONE OBJECT, and how confident that is.
 * The four files each declared a *different* struct for what turns out to be
 * the same record. The join is src/ov010/unk_0216D910.c, which passes one
 * pointer to both accessor families in the same function:
 *
 *     sub_0216D948(p) -> sub_0216D4D4(p, 1)      reads the word at +0x00
 *     sub_0216D910(p) -> sub_0216D67C(p)         reads the pointer at +0x88
 *
 * That file matches byte for byte, so the two families genuinely share a
 * receiver. It is nonetheless a single file's reading -- it spells the
 * parameter `void *p`, so the compiler never checked the identification. The
 * *offsets* are all independently proven; the claim that they belong to one
 * struct is the part carrying the risk. If a worker finds them separate, this
 * splits cleanly at +0x88.
 *
 * FIELD GRADES: PROVEN = used by a function that verifies N/N OK.
 *               INFERRED = filler placing the next proven field.
 */

typedef struct Ov010Record Ov010Record;

/* ---------------------------------------------------------------------------
 * Ov010Vtable -- 0x14. Two of these hang off the record at +0x8C and +0x90.
 * ------------------------------------------------------------------------- */
typedef struct Ov010Vtable {
    void (*unk_00)(Ov010Record *); // +0x00 PROVEN
    void (*unk_04)(Ov010Record *); // +0x04 PROVEN
    void (*unk_08)(Ov010Record *); // +0x08 PROVEN
    void (*unk_0C)(Ov010Record *); // +0x0C PROVEN
    void (*unk_10)(Ov010Record *); // +0x10 PROVEN
} Ov010Vtable;

/* ---------------------------------------------------------------------------
 * Ov010Record -- 0xD4.
 *
 * The two 32-bit words at the front are bit flag banks, each with a
 * set / clear / test triple:
 *     word0  sub_0216D548 (|=)  sub_0216D550 (&= ~)  sub_0216D55C (&)
 *     word1  sub_0216D568 (|=)  sub_0216D570 (&= ~)  sub_0216D57C (&)
 * sub_0216D4D4 also tests word0. Masks seen in the matched code: 0x1, 0x2,
 * 0x4, 0x200, 0x400, 0x600.
 *
 * The seven u16s at +0x08..+0x15 each have a get/set accessor pair, and
 * `evidence.py --module ov010` confirms the whole run independently, off the
 * disassembly rather than off a worker's reading:
 *
 *     run 0x0216d564..0x0216d5b8  (18 functions)
 *       +0x004:4B  +0x008:2B  +0x00a:2B  +0x00c:2B  +0x00e:2B
 *       +0x010:2B  +0x012:2B  +0x014:2B
 *
 * i.e. eighteen byte-exact functions accessing exactly these offsets at
 * exactly these widths. That is the strongest evidence in this header.
 * ------------------------------------------------------------------------- */
struct Ov010Record {
    u32 word0;                    // +0x00 PROVEN -- bit bank
    u32 word1;                    // +0x04 PROVEN -- bit bank (evidence.py 4B)
    u16 unk_08;                   // +0x08 PROVEN (evidence.py 2B)
    u16 unk_0A;                   // +0x0A PROVEN (evidence.py 2B)
    u16 unk_0C;                   // +0x0C PROVEN (evidence.py 2B)
    u16 unk_0E;                   // +0x0E PROVEN (evidence.py 2B)
    u16 unk_10;                   // +0x10 PROVEN (evidence.py 2B)
    u16 unk_12;                   // +0x12 PROVEN (evidence.py 2B)
    u16 unk_14;                   // +0x14 PROVEN (evidence.py 2B)
    u8 filler_16[0x88 - 0x16];    // +0x16 INFERRED -- 114 bytes, unexamined
    void *unk_88;                 // +0x88 PROVEN -- sub_0216D67C returns this
                                  //   (thumb: add r0,#0x88 ; ldr r0,[r0] ; bx lr)
    const Ov010Vtable *unk_8C;    // +0x8C PROVEN
    const Ov010Vtable *unk_90;    // +0x90 PROVEN
    u8 unk_94[0x10];              // +0x94 PROVEN (address returned by 0216D69C)
    u8 unk_A4[0x10];              // +0xA4 PROVEN (address returned by 0216D6B8)
    u8 unk_B4[0x10];              // +0xB4 PROVEN (address returned by 0216D6D4)
    u8 unk_C4[0x10];              // +0xC4 PROVEN (address returned by 0216D6F0)
};                                // 0xD4

/* ---------------------------------------------------------------------------
 * Ov010Sub88 -- the object hanging off Ov010Record::unk_88.
 *
 * sub_0216D910 does sub_0216D520(record->unk_88), and 0x0216D520 onwards is a
 * run of one-instruction accessors on this object. Offsets read straight out
 * of the Thumb bytes at 0x0216D520..0x0216D544:
 *     6A40  ldr  r0,[r0,#0x24]      6A80  ldr  r0,[r0,#0x28]
 *     6281  str  r1,[r0,#0x28]      6B40  ldr  r0,[r0,#0x34]
 *     6B80  ldr  r0,[r0,#0x38]      6BC0  ldr  r0,[r0,#0x3C]
 *     6C00  ldr  r0,[r0,#0x40] then a null check and ldrh [r0,#0]
 * Only those offsets are claimed; the size is a lower bound, not a size.
 * ------------------------------------------------------------------------- */
typedef struct Ov010Sub88 {
    u8 filler_00[0x24];  // +0x00 INFERRED
    void *unk_24;        // +0x24 PROVEN
    void *unk_28;        // +0x28 PROVEN (get and set)
    u8 filler_2C[0x08];  // +0x2C INFERRED
    void *unk_34;        // +0x34 PROVEN
    void *unk_38;        // +0x38 PROVEN
    void *unk_3C;        // +0x3C PROVEN
    u16 *unk_40;         // +0x40 PROVEN -- null-checked, then dereferenced u16
} Ov010Sub88;            // >= 0x44

#endif // POKEBLACK_OV010_H
