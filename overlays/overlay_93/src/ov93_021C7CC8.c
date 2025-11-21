/**
 * @file ov93_021C7CC8.c
 * @brief Gets halfword at large offset 0x1f7e
 * @address 0x021C7CC8
 */

#include "overlay_93.h"

u16 ov93_021C7CC8(void* context) {
    return *(u16*)((u8*)context + 0x1F7E);
}
