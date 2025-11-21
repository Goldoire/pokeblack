/**
 * @file ov93_021B86B8.c
 * @brief Double dereference - gets pointer to pointer
 * @address 0x021B86B8
 */

#include "overlay_93.h"

void* ov93_021B86B8(void* context) {
    void* ptr = *(void**)context;
    return *(void**)ptr;
}
