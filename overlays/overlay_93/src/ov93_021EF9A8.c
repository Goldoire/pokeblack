/**
 * @file ov93_021EF9A8.c
 * @brief Extracts lower bits from word
 * @address 0x021EF9A8
 */

#include "overlay_93.h"

u32 ov93_021EF9A8(void* context) {
    u32 value = *(u32*)context;
    return (value << 0) >> 0;
}
