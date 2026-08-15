#ifndef POKEBLACK_OV009_H
#define POKEBLACK_OV009_H

#include "global.h"

/*
 * ===========================================================================
 *  ov009 -- DWC / GameSpy: the dwc_rapcommon allocator block
 * ===========================================================================
 *
 * From src/ov009/dwc_rapcommon.c (64 functions, all N/N OK). Delete the local
 * `UnkStruct021A8268` and include this instead.
 *
 * INSTRUCTION SET: ov009 is Thumb only for its first ~8 KB
 * (0x02155160-0x02157170, Game Freak's own code). Everything above that,
 * including this block, is ARM DWC/GameSpy library code. See WORKER_GUIDE.md.
 *
 * The original translation unit is named in the overlay's rodata:
 * "dwc_rapcommon.c" at 0x021A1C7C.
 */

/* ---------------------------------------------------------------------------
 * Ov009RapAlloc -- 0x24. The singleton behind the pointer at 0x021A8268.
 *
 * This is a two-tier allocator: a primary NNS expheap over an aligned buffer,
 * plus a secondary heap that requests are routed to when they match a tag and
 * exceed a size threshold.
 *
 * The routing rule is read straight out of sub_02156F5C, which matches:
 *     if (a->unk08 != NULL && tag == a->unk10 && size > a->unk18)
 *         -> allocate from the secondary heap
 * which is what types +0x10 as the tag and +0x18 as the threshold.
 *
 * INDEPENDENT CORROBORATION of the heap layer: this file calls
 * sub_02060C5C and sub_02060CA0 directly, and its own comments identify them
 * as the NNS expheap create/alloc entry points -- the same two addresses
 * heap.h pinned from the other direction (by finding the only callers of the
 * byte-exact NNS sweep placements). Two independent derivations agreeing.
 *
 * FIELD GRADES: everything below is PROVEN -- used by one of the 64 byte-exact
 * functions in the file.
 * ------------------------------------------------------------------------- */
typedef struct Ov009RapAlloc {
    void *unk00;  // +0x00 allocator handle over the aligned buffer
    void *unk04;  // +0x04 the raw buffer, allocated from the caller's heap
    void *unk08;  // +0x08 secondary allocator handle (NULL = tier disabled)
    void *unk0C;  // +0x0C buffer behind unk08, freed by sub_02156F14
    u32 unk10;    // +0x10 tag the secondary allocator is selected by
    u32 unk14;    // +0x14 live allocations served by the secondary heap
    u32 unk18;    // +0x18 size threshold for the secondary heap
    u32 unk1C;    // +0x1C shutdown-deferred flag (set when unk14 != 0)
    u16 unk20;    // +0x20 set by sub_02156F50
    u16 unk22;    // +0x22
} Ov009RapAlloc;  // 0x24

extern Ov009RapAlloc *_021A8268;

#endif // POKEBLACK_OV009_H
