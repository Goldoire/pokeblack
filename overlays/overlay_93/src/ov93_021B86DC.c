/**
 * @file ov93_021B86DC.c
 * @brief Nested halfword getter at offset 0x1a
 * @address 0x021B86DC
 */

#include "overlay_93.h"

u16 ov93_021B86DC(void* context) {
    void* ptr = *(void**)context;
    return *(u16*)((u8*)ptr + 0x1a);
}
