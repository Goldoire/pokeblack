#ifndef POKEBLACK_GLOBAL_H
#define POKEBLACK_GLOBAL_H

/*
 * Umbrella header for Pokemon Black game code.
 *
 * Include this (not <nitro.h> directly) at the top of a new .c file. It pulls
 * in the exact SDK and NNS headers the retail build compiled against, which
 * are in-tree and therefore verified by construction:
 *
 *   lib/NitroSDK/TwlSDK/include   -- OS/GX/FS/MI/FX/... types and prototypes
 *   lib/TwlSystem/include         -- NNS G2D/G3D/FND/SND types and prototypes
 *
 * Everything reachable from here is real Nintendo source, not a guess. Prefer
 * an SDK/NNS type over inventing one: if the field you are looking at is an
 * NNSG2dImageProxy or an NNSFndHeapHandle, say so.
 *
 * ---------------------------------------------------------------------------
 * HOUSE RULE THAT PROTECTS THE VERIFIER  (read this once, it is not obvious)
 * ---------------------------------------------------------------------------
 * verify_functions.py derives a call target's address from the *symbol name*:
 * only  sub_XXXXXXXX / FUN_XXXXXXXX / DAT_XXXXXXXX / _XXXXXXXX  resolve.
 * A relocation against any other name is MASKED -- those bytes are dropped
 * from both the numerator and the denominator, so a function that calls
 * `Heap_Alloc(...)` can report "N/N OK" while the call target was never
 * checked at all. Friendly names silently buy you a false positive.
 *
 * So every cross-function reference in this tree is spelled as the address
 * symbol, and readability comes from a macro alias:
 *
 *     void *sub_02030098(u32 heapID, u32 size);   // prototype: address symbol
 *     #define Heap_Alloc sub_02030098             // alias: what you type
 *
 * Write `Heap_Alloc(HEAP_ID_x, n)`; the object records `sub_02030098`; the
 * verifier checks the branch word. Never declare a prototype under a friendly
 * name alone.
 */

#include <nitro.h>
#include <nnsys.h>

#include "types.h"

#endif // POKEBLACK_GLOBAL_H
