#ifndef POKEBLACK_OV114_H
#define POKEBLACK_OV114_H

#include "global.h"

/*
 * ===========================================================================
 *  ov114 -- socket / connection library
 * ===========================================================================
 *
 * Merged from the two worker declarations in src/ov114/unk_021BE8E8.c and
 * src/ov114/unk_021BEC74.c. Delete the local copies in those files and
 * include this instead.
 *
 * CONFIDENCE: HIGH for every field listed as PROVEN. `verify_functions.py
 * ov114` reports 49/49 OK, so each offset that appears in that code is
 * byte-exact against the ROM -- the compiler emitted the displacement the ROM
 * has. Fields marked INFERRED are filler that only exists to place the next
 * proven field; nothing reads them, so their names, widths and boundaries are
 * guesses and must not be relied on.
 *
 * (evidence.py's `proven` pass reports nothing for ov114. That is a limitation
 * of its liveness heuristic on Thumb code that shuffles arguments, not a
 * counter-indication: the functions matched.)
 *
 * NAMING: the workers called these Lock/Mgr/Entry/Sock/Ctx/Conn/Handle. Those
 * are far too generic to put in a header shared by 238 modules -- ov009 is
 * also networking code and will want `Sock`. Everything here carries the
 * module prefix.
 */

typedef struct Ov114Sock Ov114Sock;
typedef struct Ov114Entry Ov114Entry;
typedef struct Ov114Ctx Ov114Ctx;
typedef struct Ov114Conn Ov114Conn;
typedef struct Ov114Handle Ov114Handle;

/* ---------------------------------------------------------------------------
 * Ov114Lock -- 0x24. An init flag guarding an OSMutex and an OSThreadQueue.
 *
 * The workers spelled the tail as `u8 mutex[0x18]; u32 queueHead; u32
 * queueTail;`. Those are the SDK's own OSMutex (0x18) and OSThreadQueue (0x08,
 * head + tail), so the real types are used here instead -- same layout, and
 * the size is then verified by construction rather than by counting.
 *
 * PROVEN: all four. `inited` (+0x00), `&lock->mutex` (+0x04, passed to
 * OS_InitMutex = sub_021B9B4C), `queueHead` (+0x1C, OS_SleepThread /
 * OS_WakeupThread), `queueTail` (+0x20).
 * ------------------------------------------------------------------------- */
typedef struct Ov114Lock {
    u32 inited;          // +0x00 PROVEN
    OSMutex mutex;       // +0x04 PROVEN (0x18 bytes)
    OSThreadQueue queue; // +0x1C PROVEN (head +0x1C, tail +0x20)
} Ov114Lock;

/* ---------------------------------------------------------------------------
 * Ov114Entry -- 0x30. Singly linked connection-table record.
 *
 * The two files disagreed on length: unk_021BE8E8.c stopped at `next` (0x24),
 * unk_021BEC74.c carried on to unk_2C (0x30). Strict superset, so the longer
 * one wins; the short version was simply not looking past its own needs.
 * unk_10/unk_14 are typed Ov114Sock* (the specific form, from unk_021BE8E8.c)
 * rather than void*; void* arguments still take them implicitly.
 * ------------------------------------------------------------------------- */
struct Ov114Entry {
    u32 unk_00;         // +0x00 PROVEN
    u32 unk_04;         // +0x04 PROVEN
    u32 unk_08;         // +0x08 INFERRED (filler)
    u32 unk_0C;         // +0x0C PROVEN
    Ov114Sock *unk_10;  // +0x10 PROVEN
    Ov114Sock *unk_14;  // +0x14 PROVEN
    u32 unk_18;         // +0x18 INFERRED (filler)
    u32 unk_1C;         // +0x1C PROVEN
    Ov114Entry *next;   // +0x20 PROVEN (list walk in sub_021BEAB8's callers)
    u32 unk_24;         // +0x24 PROVEN
    u32 unk_28;         // +0x28 PROVEN
    void *unk_2C;       // +0x2C PROVEN
};

/* ---------------------------------------------------------------------------
 * Ov114Mgr -- 0x2C. The singleton at 0x021CF984.
 *
 * THE ONE REAL CONFLICT in this module: unk_021BE8E8.c declared field +0x04 as
 * `void *ctx`, unk_021BEC74.c as `Ctx *ctx`. Resolved in favour of the typed
 * form -- unk_021BEC74.c is the file that actually constructs and walks the
 * context (sub_021BEF08 / sub_021BEEC4), so it is the one with information
 * about what lives there; `void *` was the other file's shrug. Both compile
 * against this, because a typed pointer passes to a void* parameter freely.
 *
 * PROVEN: head (+0x00, `_021CF984.head`), ctx (+0x04), lock (+0x08,
 * `&_021CF984.lock` and `_021CF984.lock.inited`).
 * ------------------------------------------------------------------------- */
typedef struct Ov114Mgr {
    Ov114Entry *head; // +0x00 PROVEN
    Ov114Ctx *ctx;    // +0x04 PROVEN
    Ov114Lock lock;   // +0x08 PROVEN
} Ov114Mgr;

/* ---------------------------------------------------------------------------
 * Ov114Ctx -- 0x54. The library context sub_021BEF08 lazily builds at
 * 0x021CF9C0; sub_021BEEC4 walks five sub-objects and inits each.
 *
 * The worker declared it as five opaque byte runs and that is exactly right --
 * the code only ever takes the address of each run. Kept verbatim.
 * ------------------------------------------------------------------------- */
struct Ov114Ctx {
    u8 unk_00[0x28]; // +0x00 PROVEN (address taken)
    u8 unk_28[0x08]; // +0x28 PROVEN (address taken)
    u8 unk_30[0x04]; // +0x30 PROVEN (address taken)
    u8 unk_34[0x1C]; // +0x34 PROVEN (address taken)
    u8 unk_50[0x04]; // +0x50 PROVEN (address taken)
};

/* ---------------------------------------------------------------------------
 * Ov114Handle -- 0x2C. Carries the per-handle callback.
 * The 0x021BEC74 / 0x021BED04 / 0x021BED90 trio all pump `cb` with a
 * different opcode, which is what pins +0x1C.
 * ------------------------------------------------------------------------- */
struct Ov114Handle {
    u8 pad_00[0x1C];                                // +0x00 INFERRED (filler)
    int (*cb)(Ov114Handle *h, int op, u32 *args);   // +0x1C PROVEN
    u32 unk_20;                                     // +0x20 INFERRED (filler)
    u32 unk_24;                                     // +0x24 INFERRED (filler)
    u32 unk_28;                                     // +0x28 PROVEN
};

/* ---------------------------------------------------------------------------
 * Ov114Conn -- 0x2C. Single-file type, folded in so the module has one home.
 * ------------------------------------------------------------------------- */
struct Ov114Conn {
    u32 unk_00;            // +0x00
    u32 unk_04;            // +0x04
    u8 pad_08[0x1C - 0x08];// +0x08 INFERRED (filler)
    u32 unk_1C;            // +0x1C
    u8 pad_20[0x28 - 0x20];// +0x20 INFERRED (filler)
    u32 unk_28;            // +0x28
};

/* ---------------------------------------------------------------------------
 * Ov114Sock -- 0xE0. Only the fields below are ever touched; every `pad_`
 * run is INFERRED and exists purely to place the next proven offset.
 * ------------------------------------------------------------------------- */
struct Ov114Sock {
    u32 unk_00;              // +0x00
    u32 unk_04;              // +0x04
    u32 unk_08;              // +0x08
    u32 unk_0C;              // +0x0C
    u32 unk_10;              // +0x10 PROVEN
    u32 unk_14;              // +0x14
    u32 unk_18;              // +0x18
    u8 pad_1C[0x4C - 0x1C];  // +0x1C INFERRED (filler)
    u8 unk_4C[0xA8 - 0x4C];  // +0x4C PROVEN (address taken)
    u32 unk_A8;              // +0xA8 PROVEN
    u8 pad_AC[0xC0 - 0xAC];  // +0xAC INFERRED (filler)
    u32 unk_C0;              // +0xC0 PROVEN
    u32 unk_C4;              // +0xC4 PROVEN
    u32 unk_C8;              // +0xC8 PROVEN
    u8 pad_CC[0xDC - 0xCC];  // +0xCC INFERRED (filler)
    u32 unk_DC;              // +0xDC PROVEN
};

extern Ov114Mgr _021CF984;      // PROVEN address (literal in both files)
extern const char _021CE53C[];

#endif // POKEBLACK_OV114_H
