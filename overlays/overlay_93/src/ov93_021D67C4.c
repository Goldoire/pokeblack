/**
 * @file ov93_021D67C4.c
 * @brief Returns pointer with offset
 * @address 0x021D67C4
 */

#include "overlay_93.h"

u8 ov93_021D67C4(void* context) {
    return *(u8*)((u8*)context + 0x152);
}
