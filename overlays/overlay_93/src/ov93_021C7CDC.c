/**
 * @file ov93_021C7CDC.c
 * @brief Gets u16 at offset 0x1F82
 * @address 0x021C7CDC
 */

#include "overlay_93.h"

u16 ov93_021C7CDC(void* context) {
    return *(u16*)((u8*)context + 0x1F82);
}
