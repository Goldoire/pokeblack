/**
 * @file ov93_021D6DC4.c
 * @brief Clears structure field
 * @address 0x021D6DC4
 */

#include "overlay_93.h"

void ov93_021D6DC4(void* context) {
    *((u8*)context + 0xD0) = 0;
}
