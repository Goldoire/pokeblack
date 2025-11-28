/**
 * @file ov93_021D8454.c
 * @brief Extracts lower 4 bits from word
 * @address 0x021D8454
 */

#include "overlay_93.h"

u32 ov93_021D8454(void* context) {
    u32 value = *(u32*)context;
    return (value << 28) >> 28;
}
