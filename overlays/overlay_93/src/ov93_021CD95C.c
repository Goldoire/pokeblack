/**
 * @file ov93_021CD95C.c
 * @brief Setter - stores word at offset 0x54
 * @address 0x021CD95C
 */

#include "overlay_93.h"

void ov93_021CD95C(void* context, u32 value) {
    *(u32*)((u8*)context + 0x54) = value;
}
