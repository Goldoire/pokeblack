/**
 * @file ov93_021B8564.c
 * @brief Checks if all slots are available
 * @address 0x021B8564
 */

#include "overlay_93.h"

u32 ov93_021B8564(void* context) {
    u8* ptr = (u8*)context;

    // Check all 4 slots
    for (u32 i = 0; i < 4; i++) {
        // Get pointer at offset 0x10 + i*4
        u32* slot_ptr = (u32*)(ptr + 0x10 + i * 4);

        // If slot has a pointer and flag byte is zero, slot is busy
        if (*slot_ptr != 0 && ptr[0xC4 + i] == 0) {
            return 0;  // Slot is busy
        }
    }

    return 1;  // All slots available
}
