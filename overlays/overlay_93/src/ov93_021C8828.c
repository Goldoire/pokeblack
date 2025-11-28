/**
 * @file ov93_021C8828.c
 * @brief Gets halfword at offset 2
 * @address 0x021C8828
 */

#include "overlay_93.h"

u16 ov93_021C8828(void* context) {
    return *(u16*)((u8*)context + 2);
}
