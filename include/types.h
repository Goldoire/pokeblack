#ifndef TYPES_H
#define TYPES_H

/*
 * Base integer types for the Pokemon Black decomp.
 *
 * VERIFIED-BY-CONSTRUCTION: these come from the game's own SDK
 * (lib/NitroSDK/TwlSDK/include/nitro/types.h), which is the header the retail
 * build compiled against. Do NOT re-typedef u8/u16/u32/s8/s16/s32/BOOL here:
 * the SDK spells u32 as `unsigned long`, and a local `unsigned int` typedef
 * makes "types.h" and <nitro.h>/<nnsys.h> mutually exclusive in one TU.
 * (Both are 32-bit, so codegen is unaffected -- but the compile breaks.)
 *
 * Including this header is therefore always safe alongside <nitro.h>.
 */
#include <nitro/types.h>

/* Not in the SDK; GameFreak spellings used across pret decomps. */
typedef u8 bool8;
typedef u32 bool32;

#ifndef NELEMS
#define NELEMS(a) (sizeof(a) / sizeof(*(a)))
#endif

#endif // TYPES_H
