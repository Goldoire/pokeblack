/**
 * @file ov93_021B92A0.c
 * @brief Sets bit 5 of byte at offset 0x473
 * @address 0x021B92A0
 */

#include "overlay_93.h"

void ov93_021B92A0(void* context) {
    u8* ctx = (u8*)context;
    ctx[0x473] |= 0x20;  // Set bit 5
}
