/**
 * @file ov93_021C8138.c
 * @brief Returns pointer with offset
 * @address 0x021C8138
 */

#include "overlay_93.h"

u16 ov93_021C8138(void* context) {
    return (u16)(*(u32*)((u8*)context + 0x10));
}
