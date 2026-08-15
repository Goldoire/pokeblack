#ifndef GLOBALS_H
#define GLOBALS_H

/*
 * TOMBSTONE.
 *
 * This header used to hold 4000-odd `extern u32 DAT_xxxxxxxx;` lines
 * auto-generated from symbols.txt. It was removed because:
 *
 *   1. It did not compile. Every function-pointer entry was emitted as
 *      `extern void (*)(void) DAT_020011C4;` -- a declarator with no name --
 *      so any file that included it died with dozens of syntax errors.
 *   2. Every address in it was on the legacy Ghidra base (file offset +
 *      0x02000000), not real RAM. main loads at 0x02004000, so all of them
 *      were 0x4000 low. See SWARM_PROMPT.md, "Address bases are mixed".
 *   3. Most entries were not data at all -- 0x0200080C "= 0xE3A00000" is an
 *      ARM `mov r0, #0` instruction that the exporter mistook for a variable.
 *
 * There is nothing to salvage. Reference data by its address symbol at the
 * point of use -- `extern u32 _020AA194;` in your own file -- which is the
 * spelling verify_functions.py resolves. Real, shared globals get a verified
 * declaration in the header that owns their subsystem (see heap.h).
 */

#include "global.h"

#endif // GLOBALS_H
