#ifndef POKEBLACK_HEAP_H
#define POKEBLACK_HEAP_H

#include "global.h"

/*
 * ===========================================================================
 *  GameFreak heap layer -- main, ARM, 0x0202FBAC .. 0x020304B8
 * ===========================================================================
 *
 * CONFIDENCE: HIGH. Every offset below was read out of Black's own
 * instructions; the evidence is cited per field and reproduced in
 * include/README.md. Nothing here was copied from pokeheartgold on faith --
 * gen 5 rearranged this file substantially (HGSS keeps five parallel arrays,
 * Black keeps one array of 16-byte slots; HGSS's alloc header is 0x10 bytes,
 * Black's is 0x1C; Black folds Create/CreateAtEnd and Alloc/AllocAtEnd into
 * one entry point each using bit 15 of the heap id).
 *
 * This layer is ARM code even though 81.6% of the game is Thumb. Compile the
 * file that implements it WITHOUT --thumb.
 */

/* ---------------------------------------------------------------------------
 * Heap ids
 *
 * SPECULATIVE: the id -> purpose mapping is NOT known for Black. Only the
 * mechanics are verified. Do not port pokeheartgold's `enum HeapID` list --
 * gen 5 renumbered it. Pass the raw number a call site uses until someone
 * pins the table in Heap_InitSystem's caller.
 * ------------------------------------------------------------------------- */
typedef u32 HeapID;

/*
 * VERIFIED: bit 15 of the heap id selects tail allocation.
 *   Heap_Alloc   0x020300AC  tst r7, #0x8000 -> alignment = -4, else +4
 *   Heap_Create  0x0202FDD4  same test, same effect
 * and the id is masked with 0x7FFF before use (literals at 0x0203015C /
 * 0x0202FE64 are 0x00007FFF).
 */
#define HEAP_AT_END  0x8000
#define HEAP_ID_MASK 0x7FFF

/*
 * VERIFIED: 0xFF in the heapIdxs table means "no heap allocated for this id".
 *   Heap_InitSystem 0x0202FD24  mov r2, #0xff ; memset of the whole table
 *   Heap_GetHandle  0x0202FBB8  cmp r2, #0xff -> return NULL
 */
#define HEAP_IDX_UNALLOCATED 0xFF

/* ---------------------------------------------------------------------------
 * struct HeapSlot -- one live heap. 0x10 bytes.
 *
 * VERIFIED size: Heap_InitSystem allocates usableHeaps * 0x10 bytes
 * (0x0202FCA0  lsl r1, sb, #4) and every access indexes with `lsl #4`.
 *
 * VERIFIED fields: four sibling accessors, one per field, each 36 bytes,
 * all doing  slot = sHeapInfo.heaps[sHeapInfo.heapIdxs[id]]  then one load:
 *   0x0202FBAC  ldr  r0, [r0, r2, lsl #4]   -> +0x00
 *   0x0202FBD0  ldr  r0, [r0, #4]           -> +0x04
 *   0x0202FBF8  ldr  r0, [r0, #8]           -> +0x08
 *   0x0202FC20  ldrh r0, [r0, #0xc]         -> +0x0C, halfword
 * and the init loop at 0x0202FCBC writes str/str/str/strh/strb across
 * +0x00 +0x04 +0x08 +0x0C +0x0E -- which is what fixes +0x0E as a *byte*.
 * ------------------------------------------------------------------------- */
typedef struct HeapSlot {
    NNSFndHeapHandle handle;       // +0x00 VERIFIED  expheap handle for this heap
    NNSFndHeapHandle parentHandle; // +0x04 VERIFIED  heap this one was carved out of
    void *rawPtr;                  // +0x08 VERIFIED  block handed back to the parent on destroy
    u16 numMemBlocks;              // +0x0C VERIFIED  ++ in Heap_Alloc, -- in Heap_Free
    u8 unk_0E;                     // +0x0E VERIFIED as a byte (strb at 0x0202FCF4); purpose UNKNOWN
    u8 unk_0F;                     // +0x0F never observed being touched
} HeapSlot;

/* ---------------------------------------------------------------------------
 * struct HeapInfo -- the one global. At 0x02146954.
 *
 * VERIFIED address: the literal 0x02146954 is the PC-relative constant in
 * every function of this file (0x0202FBCC, 0x0202FDC0, 0x02030158,
 * 0x02030234, 0x0203029C, ...).
 *
 * VERIFIED fields, all from Heap_InitSystem (0x0202FC48):
 *   0x0202FCB4  str  r0, [r1]        heaps       = OS_AllocFromArenaLo(...)
 *   0x0202FD1C  str  r0, [r1, #4]    heapIdxs    = OS_AllocFromArenaLo(...)
 *   0x0202FD44  strh r5, [r8, #8]    totalNumHeaps
 *   0x0202FD48  strh r6, [r8, #0xa]  nTemplates
 *   0x0202FD4C  strh sb, [r8, #0xc]  maxHeaps  (= nTemplates + 24)
 *   0x0202FD50  strh r4, [r8, #0xe]  lastError = 0
 * and +0x08 is re-read as the bounds check in Heap_Alloc (0x020300B4
 * ldrh r1, [r8, #8] ; cmp r7, r1 ; bhs fail).
 *
 * Total size is at least 0x10; nothing past 0x0F has been observed.
 * ------------------------------------------------------------------------- */
typedef struct HeapInfo {
    HeapSlot *heaps;    // +0x00 VERIFIED  maxHeaps entries
    u8 *heapIdxs;       // +0x04 VERIFIED  totalNumHeaps entries; heapID -> slot, 0xFF = none
    u16 totalNumHeaps;  // +0x08 VERIFIED  upper bound on a valid heap id
    u16 nTemplates;     // +0x0A VERIFIED  heaps created up front from the template table
    u16 maxHeaps;       // +0x0C VERIFIED  nTemplates + 24
    u16 lastError;      // +0x0E VERIFIED  see HEAP_ERR_* below; 0 on success
} HeapInfo;

/*
 * VERIFIED error codes -- each is a literal stored to sHeapInfo.lastError on
 * one specific failure path.
 *   Heap_Alloc:  1 = id >= totalNumHeaps (0x020300C8)
 *                2 = no handle for that id (0x020300E0)
 *                3 = the expheap allocation failed (0x02030104 -> 0x0203013C)
 *   Heap_Free:   1 = header magic wrong (0x02030184)
 *                2 = id >= totalNumHeaps
 *                3 = no handle
 *                4 = numMemBlocks was already 0
 */
#define HEAP_ERR_NONE       0
#define HEAP_ERR_BAD_ID     1
#define HEAP_ERR_NO_HANDLE  2
#define HEAP_ERR_ALLOC_FAIL 3

/* ---------------------------------------------------------------------------
 * struct MemBlockHeader -- prefixed to every Heap_Alloc block. 0x1C bytes.
 *
 * VERIFIED size: Heap_Alloc adds 0x1C to the requested size before calling
 * NNS (0x020300F8  add r1, r6, #0x1c), advances the returned pointer by 0x1C
 * (0x02030118  strh r7, [r5], #0x1c), and Heap_Free subtracts it back
 * (0x02030168  sub r6, r0, #0x1c).
 *
 * VERIFIED fields:
 *   +0x00 u16 heapID   0x02030118 strh r7 (the masked id) at [r5], post-inc
 *                      0x02030174 ldrh r4, [r0, #-0x1c] on the free path
 *   +0x02 u16 magic    0x02030114 strh 0x194E on alloc
 *                      0x0203016C/0x02030178 compared against 0x194E on free
 *                      0x02030204 strh 0x194D (magic - 1) to poison on free
 *
 * +0x04 .. +0x1B are NOT identified. Twenty-four bytes is a lot of slack --
 * most likely gen 5's alloc tracking (file/line/size/tag) -- but nothing in
 * this file reads or writes them, so do not guess. Leave the filler alone.
 * ------------------------------------------------------------------------- */
#define HEAP_BLOCK_MAGIC       0x194E
#define HEAP_BLOCK_MAGIC_FREED 0x194D

typedef struct MemBlockHeader {
    u16 heapID;       // +0x00 VERIFIED
    u16 magic;        // +0x02 VERIFIED
    u8 filler_04[24]; // +0x04 UNKNOWN, untouched by the heap layer itself
} MemBlockHeader;     // 0x1C

/* ---------------------------------------------------------------------------
 * struct HeapParam -- the template table passed to Heap_InitSystem.
 *
 * VERIFIED stride 8: 0x0202FD64  ldr r1, [r7, r4, lsl #3], and that load is
 * the size argument, so `size` is at +0x00.
 *
 * +0x04 is UNVERIFIED. pokeheartgold has an OSArenaId there, and the stride
 * says a second word exists, but Black's Heap_InitSystem never reads it: the
 * arena argument to OS_AllocFromArenaLo is a hard 0 (OS_ARENA_MAIN) from
 * `mov sb, r4` at 0x0202FD5C. Named after the gen 4 field, not confirmed.
 * ------------------------------------------------------------------------- */
typedef struct HeapParam {
    u32 size;  // +0x00 VERIFIED
    u32 arena; // +0x04 SPECULATIVE (stride is 8; Black never reads this word)
} HeapParam;

/* ---------------------------------------------------------------------------
 * Entry points.
 *
 * Declared under their address symbols so the verifier can resolve the branch
 * word (see the house rule in global.h); the macro alias below each is what
 * you should actually type.
 *
 * Every address here was pinned by following calls into NNS functions that
 * the SDK sweep placed byte-exactly:
 *   NNS_FndCreateExpHeapEx         0x02060C5C
 *   NNS_FndAllocFromExpHeapEx      0x02060CA0
 *   NNS_FndFreeToExpHeap           0x02060E30
 *   NNS_FndInitAllocatorForExpHeap 0x02061358
 *   OS_AllocFromArenaLo            0x02086788
 * ------------------------------------------------------------------------- */

/* BOOL Heap_InitSystem(templates, nTemplates, totalNumHeaps, preSize) */
BOOL sub_0202FC48(const HeapParam *templates, u32 nTemplates, u32 totalNumHeaps, u32 preSize);
#define Heap_InitSystem sub_0202FC48

/* NNSFndHeapHandle Heap_GetHandle(heapID)      slot->handle,       or NULL */
NNSFndHeapHandle sub_0202FBAC(HeapID heapID);
#define Heap_GetHandle sub_0202FBAC

/* NNSFndHeapHandle Heap_GetParentHandle(heapID) slot->parentHandle, or NULL */
NNSFndHeapHandle sub_0202FBD0(HeapID heapID);
#define Heap_GetParentHandle sub_0202FBD0

/* void *Heap_GetRawPtr(heapID)                  slot->rawPtr,       or NULL */
void *sub_0202FBF8(HeapID heapID);
#define Heap_GetRawPtr sub_0202FBF8

/* u16 Heap_GetNumMemBlocks(heapID)              slot->numMemBlocks, or 0 */
u16 sub_0202FC20(HeapID heapID);
#define Heap_GetNumMemBlocks sub_0202FC20

/* BOOL Heap_Create(parent, child | HEAP_AT_END, size) */
BOOL sub_0202FDC4(HeapID parent, HeapID child, u32 size);
#define Heap_Create sub_0202FDC4

/* void *Heap_Alloc(heapID | HEAP_AT_END, size) */
void *sub_02030098(HeapID heapID, u32 size);
#define Heap_Alloc sub_02030098

/* BOOL Heap_Free(ptr) -- ptr is the user pointer, i.e. header + 0x1C */
BOOL sub_02030164(void *ptr);
#define Heap_Free sub_02030164

/*
 * BOOL Heap_InitAllocator(pAllocator, heapID | HEAP_AT_END, alignment)
 * 0x02030238. Takes |alignment| and negates it when HEAP_AT_END is set
 * (0x0203024C rsbmi / 0x0203025C rsbne), then calls
 * NNS_FndInitAllocatorForExpHeap.
 *
 * NOTE FOR WHOEVER CLAIMS THIS FILE: functions.json does not list 0x02030238
 * or 0x020302A4 as function starts -- it folds all three into one 480-byte
 * entry at 0x02030164. Same story at 0x0202FBAC, which is really four 36-byte
 * functions (0x0202FBAC / 0x0202FBD0 / 0x0202FBF8 / 0x0202FC20). Split them.
 */
BOOL sub_02030238(NNSFndAllocator *pAllocator, HeapID heapID, int alignment);
#define Heap_InitAllocator sub_02030238

/*
 * 0x020302A4. Also does `sub r7, r0, #0x1c`, so it takes a user pointer and
 * walks back to the block header -- a free/realloc variant. NOT identified;
 * the signature is a guess and is commented out rather than shipped wrong.
 *
 * void sub_020302A4(void *ptr, ...);
 */

extern HeapInfo _02146954; // VERIFIED address; `sHeapInfo` in gen 4 terms
#define sHeapInfo _02146954

#endif // POKEBLACK_HEAP_H
