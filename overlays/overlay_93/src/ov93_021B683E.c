/**
 * @file ov93_021B683E.c
 * @brief Returns 1
 * @address 0x021B683E
 *
 * Analysis:
 *   movs r0, #1    ; r0 = 1
 *   bx lr          ; return r0
 *
 * Function: Simply returns 1. Likely a stub or placeholder.
 */

#include "overlay_93.h"

u32 ov93_021B683E(void) {
    return 1;
}
