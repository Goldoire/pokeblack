/**
 * @file ov93_021C8140.c
 * @brief Gets array element
 * @address 0x021C8140
 */

#include "overlay_93.h"

u8 ov93_021C8140(void* base, u32 index) {
    u8* ptr = (u8*)base + index;
    return ptr[0x7D9];
}
