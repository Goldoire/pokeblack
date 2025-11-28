/**
 * @file ov93_021CDA0C.c
 * @brief Sets word at offset 0x28
 * @address 0x021CDA0C
 */

#include "overlay_93.h"

void ov93_021CDA0C(void* context, u32 value) {
    *(u32*)((u8*)context + 0x28) = value;
}
