/**
 * @file ov93_021D3D70.c
 * @brief Gets u8 at offset 0x1A6
 * @address 0x021D3D70
 */

#include "overlay_93.h"

u8 ov93_021D3D70(void* context) {
    return *(u8*)((u8*)context + 0x1A6);
}
