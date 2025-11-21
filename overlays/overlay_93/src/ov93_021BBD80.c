/**
 * @file ov93_021BBD80.c
 * @brief Clears structure field
 * @address 0x021BBD80
 */

#include "overlay_93.h"

void ov93_021BBD80(void* context) {
    *(u8*)((u8*)context + 0x77C) = 0;
}
