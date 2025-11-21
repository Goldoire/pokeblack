/**
 * @file ov93_021CC95C.c
 * @brief Setter - stores word at offset 0
 * @address 0x021CC95C
 */

#include "overlay_93.h"

void ov93_021CC95C(void* context, u32 value) {
    *(u32*)context = value;
}
