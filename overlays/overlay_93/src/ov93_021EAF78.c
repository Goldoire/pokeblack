/**
 * @file ov93_021EAF78.c
 * @brief Setter - stores byte at offset 2
 * @address 0x021EAF78
 */

#include "overlay_93.h"

void ov93_021EAF78(void* context, u8 value) {
    *(u8*)((u8*)context + 2) = value;
}
