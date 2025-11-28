/**
 * @file ov93_021B8CB0.c
 * @brief Extracts lower bits from word
 * @address 0x021B8CB0
 */

#include "overlay_93.h"

u32 ov93_021B8CB0(void* context) {
    u32 value = *(u32*)context;
    return (value << 0) >> 0;
}
