/**
 * @file ov93_021BB830.c
 * @brief Gets byte at offset 0xb
 * @address 0x021BB830
 */

#include "overlay_93.h"

u8 ov93_021BB830(void* context) {
    return *(u8*)((u8*)context + 0xb);
}
