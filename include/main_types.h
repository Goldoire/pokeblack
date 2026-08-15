#ifndef POKEBLACK_MAIN_TYPES_H
#define POKEBLACK_MAIN_TYPES_H

#include "global.h"

/*
 * ===========================================================================
 *  main (ARM9 static image) -- shared engine objects
 * ===========================================================================
 *
 * Merged from src/main/a_*.c and src/main/b_*.c. Delete the local copies and
 * include this instead.
 *
 * These are the objects every overlay reaches through, so getting them wrong
 * is expensive in a way an overlay-local struct is not.
 *
 * FIELD GRADES: PROVEN = used by a function that verify_functions.py reports
 * N/N OK. INFERRED = filler placing the next proven field.
 *
 * INSTRUCTION SET WARNING: main is not uniformly Thumb. 0x02023FD8-0x0204A39C
 * is ARM (359 of 364 entries) apart from 0x02023FD8-0x0202744C at the bottom.
 * Check triage.json or fn.py before compiling; see WORKER_GUIDE.md.
 */

typedef struct MainSub MainSub;

/* ---------------------------------------------------------------------------
 * MainRec -- 0x14. The global main record at 0x020AA194.
 *
 * Constrained by, all byte-exact (src/main/a_unk_0200560C.c, 6/6 OK):
 *   sub_0200566C  clears +0x00 and +0x08
 *   sub_02005640  calls +0x08 with +0x00 as its only argument -- which is
 *                 what types +0x08 as void (*)(void *) and +0x00 as its arg
 *   sub_02005654  installs that pair
 *   sub_0200567C  increments +0x0C once per frame
 *   sub_02005610 / sub_020056BC  load the pointer at +0x10, then read +0x18
 *                 and +0x20 out of it
 *
 * sub_0200566C is one of the three original reference matches in this repo,
 * so +0x00 and +0x08 have been verified since before the swarm started.
 * ------------------------------------------------------------------------- */
typedef struct MainRec {
    void *cbArg;           // +0x00 PROVEN -- sole argument passed to cb
    u32 unk04;             // +0x04 PROVEN
    void (*cb)(void *);    // +0x08 PROVEN -- per-frame callback
    u32 frameCount;        // +0x0C PROVEN -- incremented once per frame
    MainSub *unk10;        // +0x10 PROVEN
} MainRec;                 // 0x14

extern MainRec _020AA194;
#define gMainRec _020AA194

/* ---------------------------------------------------------------------------
 * MainSub -- 0x24. Hangs off MainRec+0x10.
 *
 * The three u64s at the front are load-bearing as u64: they are what makes
 * the ROM's 8-byte accesses come out, and narrowing them to pairs of u32
 * changes codegen.
 * ------------------------------------------------------------------------- */
struct MainSub {
    u64 unk00;    // +0x00 PROVEN
    u64 unk08;    // +0x08 PROVEN
    u64 unk10;    // +0x10 PROVEN
    void *unk18;  // +0x18 PROVEN
    u32 unk1C;    // +0x1C PROVEN
    void *unk20;  // +0x20 PROVEN
};                // 0x24

/* ---------------------------------------------------------------------------
 * Unk020AA1AC -- 0x0C. The global at 0x020AA1AC.
 *
 * NOTE: the old Ghidra header called this `HeapManager` and it is nothing of
 * the sort -- the real heap globals are `sHeapInfo` at 0x02146954, see
 * heap.h. That misnaming is why the Ghidra headers are quarantined.
 * ------------------------------------------------------------------------- */
typedef struct Unk020AA1AC {
    u16 unk00;      // +0x00 PROVEN
    u16 unk02;      // +0x02 PROVEN
    u32 index;      // +0x04 PROVEN -- used as an array index
    void **unk08;   // +0x08 PROVEN -- pointer-to-pointer table
} Unk020AA1AC;      // 0x0C

extern Unk020AA1AC _020AA1AC;

/* ---------------------------------------------------------------------------
 * Unk020A9E80 -- 0x0C. The global at 0x020A9E80.
 * ------------------------------------------------------------------------- */
typedef struct Unk020A9E80 {
    u32 unk00;              // +0x00 PROVEN x2
    void (*unk04)(void);    // +0x04 PROVEN
    u32 unk08;              // +0x08 PROVEN
} Unk020A9E80;              // 0x0C

extern Unk020A9E80 _020A9E80;

/* ---------------------------------------------------------------------------
 * Unk020AA260 -- 0x34. The global at 0x020AA260.
 *
 * Two files declared this; the only disagreement was `u32` vs `void *` at
 * +0x0C / +0x10 / +0x14 -- same width, typed form wins.
 *
 * NOTE: the old Ghidra header called this `HeapManagerState` and gave it
 * fields spanning "audio channel mask" and "fade brightness" in one struct.
 * Nothing about that survived contact with the bytes.
 * ------------------------------------------------------------------------- */
typedef struct Unk020AA260 {
    u16 unk00;     // +0x00 PROVEN
    u16 unk02;     // +0x02 PROVEN
    u32 unk04;     // +0x04 PROVEN
    u32 unk08;     // +0x08 PROVEN
    void *unk0C;   // +0x0C PROVEN x2
    void *unk10;   // +0x10 PROVEN x2
    void *unk14;   // +0x14 PROVEN x2
    u32 unk18;     // +0x18 PROVEN
    u32 unk1C;     // +0x1C PROVEN
    u32 unk20;     // +0x20 PROVEN
    u16 unk24;     // +0x24 PROVEN
    u16 unk26;     // +0x26 PROVEN
    u32 unk28;     // +0x28 PROVEN
    u32 unk2C;     // +0x2C PROVEN
    u32 unk30;     // +0x30 PROVEN
} Unk020AA260;     // 0x34

extern Unk020AA260 _020AA260;

/* ---------------------------------------------------------------------------
 * Fifo -- 0x10. The ring buffer at 0x0203640C.. (src/main/b_fifo.c, 11/11 OK).
 *
 * `wpos` is volatile and that is load-bearing, not decoration: the writer
 * runs from an interrupt, and without volatile CW keeps the value in a
 * register across the loop and the bytes stop matching. See WORKER_GUIDE.md,
 * "One volatile field stops CW from CSE-ing a value the ROM re-loads".
 *
 * `size` is s32 in the struct but sub_0203640C stores `(s16)size` into it --
 * the truncation is in the ROM, keep the cast at the assignment.
 * ------------------------------------------------------------------------- */
typedef struct Fifo {
    u8 *data;            // +0x00 PROVEN
    s32 size;            // +0x04 PROVEN -- written as (s16)size
    u32 unk08;           // +0x08 PROVEN
    s16 rpos;            // +0x0C PROVEN -- read cursor
    volatile s16 wpos;   // +0x0E PROVEN -- write cursor; volatile is required
} Fifo;                  // 0x10

/* ---------------------------------------------------------------------------
 * TPData -- deliberately NOT declared here.
 *
 * src/main/b_unk_020358a0.c (18/18 OK) declares a local
 *   struct TPData { u16 x, y, touch, validity; }
 * which is byte-for-byte the SDK's own TPData in <nitro/spi/ARM9/tp.h>. That
 * one arrives through global.h, so redeclaring it here is both redundant and
 * a hard compile error (`identifier 'TPData' redeclared`).
 *
 * ACTION FOR THE main-B WORKER: delete the local `TPData` declaration; the
 * SDK's is already in scope via "global.h", and using it makes the layout
 * verified by construction instead of by transcription.
 * ------------------------------------------------------------------------- */

#endif // POKEBLACK_MAIN_TYPES_H
