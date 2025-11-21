/**
 * @file ov93_021D7D6C.c
 * @brief Getter function
 * @address 0x021D7D6C
 */

#include "overlay_93.h"

u32 ov93_021D7D6C(u32 value) {
    if ((s32)value < 6) {
        return 1;
    }
    return value;
}
