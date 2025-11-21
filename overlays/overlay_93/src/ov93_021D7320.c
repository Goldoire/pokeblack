/**
 * @file ov93_021D7320.c
 * @brief Setter - stores word at offset 0xc
 * @address 0x021D7320
 */

#include "overlay_93.h"

void ov93_021D7320(void* context, u32 value) {
    *(u32*)((u8*)context + 0xc) = value;
}
