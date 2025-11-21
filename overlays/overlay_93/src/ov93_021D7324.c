/**
 * @file ov93_021D7324.c
 * @brief Clears structure field
 * @address 0x021D7324
 */

#include "overlay_93.h"

void ov93_021D7324(void* context) {
    *(u32*)((u8*)context + 0xC) = 0;
}
