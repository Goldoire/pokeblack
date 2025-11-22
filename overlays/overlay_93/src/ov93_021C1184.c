/**
 * @file ov93_021C1184.c
 * @brief Gets byte at offset 1
 * @address 0x021C1184
 */

#include "overlay_93.h"

u8 ov93_021C1184(void* context) {
    return *(u8*)((u8*)context + 1);
}
