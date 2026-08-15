#include "types.h"

/* Banked by main-A at 19/20: the C was correct, but the call at +0x4 targets
 * the ARM linker veneer at 0x02005454, which had no triage entry, so the
 * verifier defaulted it to Thumb and emitted BL where the ROM has BLX(1).
 * Unblocked by tools/scripts/callsite_modes.py --apply. */

typedef struct Unk020A9E80
{
    u32 unk00;
} Unk020A9E80;

extern Unk020A9E80 _020A9E80;

void sub_02005454(int a0);

void sub_02005440(void)
{
    sub_02005454(0);
    _020A9E80.unk00 = 1;
}
