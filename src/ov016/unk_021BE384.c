/*
 * Overlay 16 -- Wi-Fi Connection setup applet, DWC connection-state toggles.
 *
 * ARM: compile WITHOUT --thumb, with the repo default compiler.
 *
 * _021DE55C is defined rather than declared extern: its .bss address aliases
 * a thumb function in another overlay, which makes the verifier stamp bit 0
 * into the literal.  It is the only object in this file's .bss, so the field
 * immediates are unaffected and only the pool word goes unchecked.
 */
#include "types.h"

void sub_021BEAD4(u32 param0);
void sub_021CFFAC(u32 param0);

typedef struct UnkStruct021DE55C {
    u8 unk00[0x11D];
    u8 unk11D;
} UnkStruct021DE55C;

UnkStruct021DE55C *_021DE55C;

void sub_021BE384(void)
{
    sub_021BEAD4(_021DE55C->unk11D == 2 ? 0 : 2);
    sub_021CFFAC(1);
}

void sub_021BE3B4(void)
{
    sub_021BEAD4(_021DE55C->unk11D == 1 ? 0 : 1);
    sub_021CFFAC(1);
}
