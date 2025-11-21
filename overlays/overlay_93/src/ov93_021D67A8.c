/**
 * @file ov93_021D67A8.c
 * @brief Gets halfword from structure
 * @address 0x021D67A8
 */

#include "overlay_93.h"

u16 ov93_021D67A8(void* context) {
    return *(u16*)((u8*)context + (0x53 << 2));
}
