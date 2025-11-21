/**
 * @file ov93_021D3F60.c
 * @brief Getter - loads byte at offset 1
 * @address 0x021D3F60
 */

#include "overlay_93.h"

u8 ov93_021D3F60(void* context) {
    return *(u8*)((u8*)context + 1);
}
