/**
 * @file ov93_021BA1A8.c
 * @brief Tail call with dereferenced pointer
 * @address 0x021BA1A8
 */

#include "overlay_93.h"

void ov93_021BA1A8(void* context) {
    void* ptr = *(void**)context;
    FUN_02013158(ptr);
}
