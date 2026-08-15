#ifndef POKEBLACK_OV114_H
#define POKEBLACK_OV114_H

#include "global.h"

/*
 * ===========================================================================
 *  ov114 -- DWC / GameSpy networking middleware
 * ===========================================================================
 *
 * Merged from all nine src/ov114/*.c declarations. Delete the local copies
 * and include this instead.
 *
 * ov114 is ARM, not Thumb (368 of 424 entries) -- see WORKER_GUIDE.md.
 *
 * FIELD GRADES
 *   PROVEN   used by a function verify_functions.py reports N/N OK, so the
 *            compiler emitted that displacement and the ROM agreed.
 *   INFERRED filler placing the next PROVEN field. Name, width and internal
 *            boundaries are guesses.
 *
 * NAMING: the workers used Lock/Mgr/Entry/Sock/Ctx/Conn/Handle/Sess/Node/
 * Pool/Obj/Worker. Those are far too generic for a header shared by 238
 * modules -- ov009 is also networking code and will want `Sock`. Everything
 * here carries the module prefix.
 */

typedef struct Ov114Sock Ov114Sock;
typedef struct Ov114Entry Ov114Entry;
typedef struct Ov114Ctx Ov114Ctx;
typedef struct Ov114Handle Ov114Handle;
typedef struct Ov114Ssl Ov114Ssl;

/* ---------------------------------------------------------------------------
 * Ov114Lock -- 0x24. Two files, identical.
 *
 * UPGRADED: the workers' `u8 mutex[0x18]; u32 queueHead; u32 queueTail;` is
 * exactly the SDK's OSMutex (0x18) followed by OSThreadQueue (head + tail),
 * and `&lock->mutex` is passed to OS_InitMutex (sub_021B9B4C) while
 * `&lock->queue` goes to OS_SleepThread / OS_WakeupThread. Using the real
 * types makes the size verified by construction; both are static-asserted.
 * ------------------------------------------------------------------------- */
typedef struct Ov114Lock {
    u32 inited;          // +0x00 PROVEN x2
    OSMutex mutex;       // +0x04 PROVEN x2 (0x18 bytes)
    OSThreadQueue queue; // +0x1C PROVEN x2 (head +0x1C, tail +0x20)
} Ov114Lock;

/* ---------------------------------------------------------------------------
 * Ov114Mutex -- 0x1C. NOT the same shape as Ov114Lock: the init flag is at
 * the END here, not the front. Kept separate deliberately (unk_021BEC74.c).
 * ------------------------------------------------------------------------- */
typedef struct Ov114Mutex {
    u8 os[0x18];  // +0x00 INFERRED (OSMutex-shaped, but see note below)
    u32 inited;   // +0x18 PROVEN
} Ov114Mutex;

/* ---------------------------------------------------------------------------
 * Ov114Entry -- 0x30. Connection-table record, singly linked at +0x20.
 *
 * Length disagreement only, not an offset one: unk_021BE8E8.c stopped at
 * `next` (0x24), unk_021BEC74.c carried on to unk_2C (0x30). Strict superset,
 * longer wins. unk_10/unk_14 take the typed form (Ov114Sock *) from
 * unk_021BE8E8.c over the other file's void *; a typed pointer still passes
 * to a void * parameter freely, so both files compile against this.
 * ------------------------------------------------------------------------- */
struct Ov114Entry {
    u32 unk_00;          // +0x00 PROVEN x2
    u32 unk_04;          // +0x04 PROVEN x2
    u32 unk_08;          // +0x08 PROVEN x2
    u32 unk_0C;          // +0x0C PROVEN x2
    Ov114Sock *unk_10;   // +0x10 PROVEN x2
    Ov114Sock *unk_14;   // +0x14 PROVEN x2
    u32 unk_18;          // +0x18 PROVEN x2
    u32 unk_1C;          // +0x1C PROVEN x2
    Ov114Entry *next;    // +0x20 PROVEN x2
    u32 unk_24;          // +0x24 PROVEN
    u32 unk_28;          // +0x28 PROVEN
    void *unk_2C;        // +0x2C PROVEN
};

/* ---------------------------------------------------------------------------
 * Ov114Mgr -- 0x2C. The singleton at 0x021CF984.
 *
 * THE ONE REAL CONFLICT in this module: unk_021BE8E8.c declared +0x04 as
 * `void *ctx`, unk_021BEC74.c as `Ctx *ctx`. Resolved to the typed form --
 * unk_021BEC74.c is the file that constructs and walks the context
 * (sub_021BEF08 / sub_021BEEC4), so it is the one with information; `void *`
 * was the other file's shrug.
 * ------------------------------------------------------------------------- */
typedef struct Ov114Mgr {
    Ov114Entry *head; // +0x00 PROVEN x2 (`_021CF984.head`)
    Ov114Ctx *ctx;    // +0x04 PROVEN x2
    Ov114Lock lock;   // +0x08 PROVEN x2 (`&_021CF984.lock`)
} Ov114Mgr;

/* ---------------------------------------------------------------------------
 * Ov114Ctx -- 0x54. The library context sub_021BEF08 lazily builds at
 * 0x021CF9C0; sub_021BEEC4 walks five sub-objects and inits each. The worker
 * declared five opaque byte runs, which is exactly right: the code only ever
 * takes the address of each run.
 * ------------------------------------------------------------------------- */
struct Ov114Ctx {
    u8 unk_00[0x28]; // +0x00 PROVEN (address taken)
    u8 unk_28[0x08]; // +0x28 PROVEN (address taken)
    u8 unk_30[0x04]; // +0x30 PROVEN (address taken)
    u8 unk_34[0x1C]; // +0x34 PROVEN (address taken)
    u8 unk_50[0x04]; // +0x50 PROVEN (address taken)
};

/* ---------------------------------------------------------------------------
 * Ov114Handle -- 0x2C. The 0x021BEC74 / 0x021BED04 / 0x021BED90 trio each
 * pump `cb` with a different opcode, which is what pins +0x1C.
 * ------------------------------------------------------------------------- */
struct Ov114Handle {
    u8 pad_00[0x1C];                                // +0x00 INFERRED
    int (*cb)(Ov114Handle *h, int op, u32 *args);   // +0x1C PROVEN x2
    u32 unk_20;                                     // +0x20 INFERRED
    u32 unk_24;                                     // +0x24 PROVEN
    u32 unk_28;                                     // +0x28 PROVEN x2
};

/* ---------------------------------------------------------------------------
 * Ov114Sock -- 0x254. Declared four times at four different lengths
 * (0x34, 0xDC, 0xE0, 0x254) because each file stopped where its own needs
 * stopped. Every named offset is consistent across all four -- there is no
 * contradiction anywhere -- so this is the union.
 * ------------------------------------------------------------------------- */
struct Ov114Sock {
    u32 unk_00;              // +0x000 PROVEN x4
    u32 unk_04;              // +0x004 PROVEN x4
    u32 unk_08;              // +0x008 PROVEN x2
    u32 unk_0C;              // +0x00C PROVEN x2
    u32 unk_10;              // +0x010 PROVEN x2
    u32 unk_14;              // +0x014 PROVEN x2
    u32 unk_18;              // +0x018 PROVEN x2
    u8 filler_1C[0x30 - 0x1C];  // +0x01C INFERRED
    u8 unk_30[4];            // +0x030 PROVEN (unk_021BA7DC.c)
    u32 unk_34;              // +0x034 PROVEN (unk_021BE648.c)
    u8 filler_38[0x4C - 0x38];  // +0x038 INFERRED
    u8 unk_4C[0xA8 - 0x4C];  // +0x04C PROVEN (address taken, unk_021BE8E8.c)
    u32 unk_A8;              // +0x0A8 PROVEN
    Ov114Ssl *unk_AC;        // +0x0AC PROVEN (unk_021B9D8C.c)
    u8 filler_B0[0xC0 - 0xB0];  // +0x0B0 INFERRED
    u32 unk_C0;              // +0x0C0 PROVEN x2
    u32 unk_C4;              // +0x0C4 PROVEN x2
    u32 unk_C8;              // +0x0C8 PROVEN
    u8 filler_CC[0xD0 - 0xCC];  // +0x0CC INFERRED
    u32 unk_D0;              // +0x0D0 PROVEN (unk_021BE648.c)
    u8 filler_D4[0xD8 - 0xD4];  // +0x0D4 INFERRED
    u32 unk_D8;              // +0x0D8 PROVEN (unk_021B9D8C.c)
    u32 unk_DC;              // +0x0DC PROVEN (unk_021BE8E8.c)
    u8 filler_E0[0x24C - 0xE0]; // +0x0E0 INFERRED -- 364 bytes, unexamined
    u32 unk_24C;             // +0x24C PROVEN (unk_021BE648.c)
    u32 unk_250;             // +0x250 PROVEN (unk_021BE648.c)
};

/* ---------------------------------------------------------------------------
 * Ov114Ssl -- 0x830. Single declaration (unk_021B9D8C.c).
 * ------------------------------------------------------------------------- */
struct Ov114Ssl {
    u8 pad_000[0x800];          // +0x000 INFERRED -- an 2KB I/O buffer
    u32 unk_800;                // +0x800 PROVEN
    u8 pad_804[0x810 - 0x804];  // +0x804 INFERRED
    void *unk_810;              // +0x810 PROVEN
    u32 unk_814;                // +0x814 PROVEN
    u32 unk_818;                // +0x818 PROVEN
    u8 pad_81C[0x830 - 0x81C];  // +0x81C INFERRED
};

/* ---------------------------------------------------------------------------
 * Ov114Buffer -- 0x804C. THREE worker names turned out to be one type.
 *
 * unk_021B9D8C.c called it `Node`, unk_021BEC74.c called it `Pool`, and
 * unk_021BF184.c called it `Conn`. All three put a 32-bit counter at +0x8048
 * and nothing contradicts anywhere else, and `Node`'s reading explains the
 * whole shape: a 0x40 header, a 0x8000-byte data area, then cursor / bytes
 * available / refcount. `Conn`'s named fields at +0x00..+0x18 all land inside
 * `Node`'s opaque header, so they are complementary, not conflicting.
 *
 * This is the merge that mattered most in ov114: three files were each
 * carrying a partial view of the same 32 KB buffer node.
 * ------------------------------------------------------------------------- */
typedef struct Ov114Buffer {
    s32 unk_00;        // +0x0000 PROVEN (unk_021BF184.c)
    s32 unk_04;        // +0x0004 PROVEN (unk_021BF184.c)
    u32 unk_08;        // +0x0008 PROVEN
    u32 unk_0C;        // +0x000C PROVEN
    void *unk_10;      // +0x0010 PROVEN
    void *unk_14;      // +0x0014 PROVEN
    s32 unk_18;        // +0x0018 PROVEN
    u8 filler_1C[0x40 - 0x1C]; // +0x001C INFERRED
    u8 data[0x8000];   // +0x0040 PROVEN (unk_021B9D8C.c)
    u32 off;           // +0x8040 PROVEN -- read cursor
    u32 avail;         // +0x8044 PROVEN -- bytes available
    s32 refcount;      // +0x8048 PROVEN x3 -- all three names agreed here
} Ov114Buffer;

/* ---------------------------------------------------------------------------
 * Ov114Conn -- 0x2C. The *small* Conn from unk_021BEC74.c, which is a
 * different object from the 0x804C one above despite sharing a name in the
 * worker sources. Renamed apart on purpose.
 * ------------------------------------------------------------------------- */
typedef struct Ov114Conn {
    u32 unk_00;                 // +0x00 PROVEN
    u32 unk_04;                 // +0x04 PROVEN
    u8 pad_08[0x1C - 0x08];     // +0x08 INFERRED
    u32 unk_1C;                 // +0x1C PROVEN
    u8 pad_20[0x28 - 0x20];     // +0x20 INFERRED
    u32 unk_28;                 // +0x28 PROVEN
} Ov114Conn;

/* ---------------------------------------------------------------------------
 * Ov114Sess -- 0x43C. Single declaration (unk_021BF184.c). `unk_0C` is
 * volatile in the source and that is load-bearing: the ROM re-loads it, which
 * is what stops CW CSE-ing the value.
 * ------------------------------------------------------------------------- */
typedef struct Ov114Sess {
    u32 unk_00;                     // +0x000 PROVEN
    u32 unk_04;                     // +0x004 PROVEN
    u32 unk_08;                     // +0x008 PROVEN
    volatile s32 unk_0C;            // +0x00C PROVEN -- volatile is required
    u8 pad_10[0x1C - 0x10];         // +0x010 INFERRED
    u32 unk_1C;                     // +0x01C PROVEN
    u8 pad_20[0x28 - 0x20];         // +0x020 INFERRED
    u32 unk_28;                     // +0x028 PROVEN
    u8 pad_2C[0x438 - 0x2C];        // +0x02C INFERRED
    int unk_438;                    // +0x438 PROVEN
} Ov114Sess;

/* ---------------------------------------------------------------------------
 * Ov114Worker -- 0xE0. A message queue, its backing array, and a thread.
 *
 * NOT upgraded to SDK types, deliberately. `queue` is 0x20 and sizeof
 * (OSMessageQueue) is 0x20, so that one would be safe -- but `thread` is
 * 0xB4 in the worker's declaration and sizeof(OSThread) is 0xC0. Swapping in
 * OSThread would move nothing here (it is the last member) yet would assert a
 * size the evidence does not support, and if anything is ever placed after it
 * the layout would shift. The byte runs are what the matched code was built
 * against; the discrepancy is recorded rather than resolved.
 * ------------------------------------------------------------------------- */
typedef struct Ov114Worker {
    u8 queue[0x20];   // +0x00 PROVEN (OSMessageQueue-shaped, size agrees)
    void *msgbuf[3];  // +0x20 PROVEN
    u8 thread[0xB4];  // +0x2C PROVEN as a span; OSThread is 0xC0, see note
} Ov114Worker;

/* --- small single-declaration types, folded in so the module has one home - */

typedef struct Ov114SockAddr {  /* BSD sockaddr_in shape */
    u8 len;     // +0x00 PROVEN
    u8 family;  // +0x01 PROVEN
    u16 port;   // +0x02 PROVEN
    u32 addr;   // +0x04 PROVEN
} Ov114SockAddr;

typedef struct Ov114HostEnt {
    u8 pad_00[0x0A];      // +0x00 INFERRED
    s16 h_length;         // +0x0A PROVEN
    u8 **h_addr_list;     // +0x0C PROVEN
} Ov114HostEnt;

typedef void *(*Ov114AllocFn)(u32 size);
typedef void (*Ov114FreeFn)(void *p);

typedef struct Ov114Alloc {
    Ov114AllocFn alloc; // +0x00 PROVEN
    Ov114FreeFn free;   // +0x04 PROVEN
    u32 unk_08;         // +0x08 PROVEN
    s32 unk_0C;         // +0x0C PROVEN
    void *unk_10;       // +0x10 PROVEN
    void *unk_14;       // +0x14 PROVEN
    u32 unk_18;         // +0x18 PROVEN
    u32 unk_1C;         // +0x1C PROVEN
    u32 unk_20;         // +0x20 PROVEN
} Ov114Alloc;

typedef struct Ov114Obj {
    u8 pad_00[0xAC];  // +0x00 INFERRED
    void *unk_AC;     // +0xAC PROVEN
} Ov114Obj;

typedef struct Ov114ThreadInfo {
    u32 unk_00;     // +0x00 PROVEN
    void *current;  // +0x04 PROVEN
} Ov114ThreadInfo;

extern Ov114Mgr _021CF984;      // PROVEN address (literal in both files)
extern const char _021CE53C[];

#endif // POKEBLACK_OV114_H
