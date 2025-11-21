/**
 * @file ov93_021B85A0.c
 * @brief Returns pointer with offset
 * @address 0x021B85A0
 */

#include "overlay_93.h"

u8 ov93_021B85A0(void* context) {
    void* ptr = *(void**)context;
    return *(u8*)((u8*)ptr + 0x80);
}
