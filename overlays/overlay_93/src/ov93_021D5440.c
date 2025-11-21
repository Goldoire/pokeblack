/**
 * @file ov93_021D5440.c
 * @brief Getter - loads byte at offset 0x19
 * @address 0x021D5440
 */

#include "overlay_93.h"

u8 ov93_021D5440(void* context) {
    return *(u8*)((u8*)context + 0x19);
}
