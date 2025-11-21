/**
 * @file ov93_021B8714.c
 * @brief Gets pointer from context, adds 8
 * @address 0x021B8714
 *
 * Assembly:
 *   ldr r0, [r0]
 *   adds r0, #8
 *   bx lr
 */

#include "overlay_93.h"

void* ov93_021B8714(void* context) {
    void* ptr = *(void**)context;
    return (void*)((u8*)ptr + 8);
}
