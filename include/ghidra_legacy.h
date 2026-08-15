#ifndef GHIDRA_LEGACY_H
#define GHIDRA_LEGACY_H

/*
 * ===========================================================================
 *  QUARANTINE -- UNVERIFIED GHIDRA OUTPUT. DO NOT USE IN NEW CODE.
 * ===========================================================================
 *
 * These struct definitions were auto-derived from Ghidra pseudo-C before the
 * verify loop existed. Not one field offset here was checked against the ROM,
 * several of the structs are almost certainly three unrelated objects fused
 * together (see HeapManagerState, which contains both "audio channel mask" and
 * "fade brightness"), and the addresses in the comments are on the legacy
 * file-offset base, not real RAM.
 *
 * They live here only so the 35 legacy top-level src/*.c scratch files keep
 * compiling. WORKER_GUIDE.md: "Never extend src/*.c ... exactly one function
 * in it matches."
 *
 * New code includes "global.h" and "heap.h". If you need a struct, send the
 * integrator a proposal with the evidence (which functions constrain which
 * offsets, and what the accesses look like).
 */

#include "types.h"

typedef struct HeapManager {
    u32 field_00;
    u32 field_04;
    void **field_08;
} HeapManager;

typedef struct HeapBlock {
    u32 field_00;
    u16 field_04;
    u16 field_06;
    u32 field_08;
    u32 field_0C;
    u32 field_10;
    u32 field_14;
    u32 field_18;
} HeapBlock;

extern HeapManager *gHeapManager;
extern HeapBlock *gHeapBlocks;

typedef struct HeapManagerState {
    u32 field_00;
    u32 field_04;
    u32 field_08;
    u32 field_0C;
    u32 field_10;
    u32 field_14;
    u32 field_18;
    u16 field_1C;
    u16 field_1E;
    u32 field_20;
    u32 field_24;
    u16 field_26;
    u16 field_28;
    u16 field_2A;
    u32 field_2C;
    u32 field_30;
} HeapManagerState;

extern HeapManagerState *gHeapManagerState;

typedef struct SoundChannel {
    u32 state;
    void *data;
} SoundChannel;

extern SoundChannel *gSoundChannels;

u32 HeapManager_GetCurrentIndex(void);
u8 *HeapManager_GetCurrentBlockPtr(void);
void HeapManager_SetResourceArray(void *resourceArray);
u32 HeapBlock_GetStateValue(void);
void FadeState_Reset(void);
void FadeStateMachine_Update(void);
void FadeState_ProcessTransition(void);
void FadeState_InitTransition(u32 param1, u16 param2);
void SetFadeStateCallback(void *callback);
u32 AsyncOperation_IsComplete(void);

#define HEAP_INVALID_ID     0xFFFF
#define FADE_MAX_BRIGHTNESS 0x7F

typedef struct ResourceObject {
    u32 state;
    u32 field_04;
    u32 field_08;
    u32 field_0C;
    u32 field_10;
    u32 field_14;
    u32 field_18;
    u8 field_1C;
    u8 field_1D;
    u8 pad_1E[2];
    u32 field_20;
    u32 field_24;
    u8 field_28;
    u8 pad_29[3];
    u32 field_2C;
    u32 field_30;
} ResourceObject;

typedef struct ResourceHeader {
    u32 flags;
} ResourceHeader;

typedef struct ResourceData {
    u32 field_00[15];
    u32 field_3c;
} ResourceData;

typedef u32 (*CallbackFunc)(u32 param);

typedef struct CallbackRegistry {
    void *field_0x0;
    CallbackFunc callback;
} CallbackRegistry;

s32 ResourceObject_LoadAndInit(ResourceObject *obj, u32 param);
void ResourceObject_Destroy(void *objectPtr);
void ResourceObject_Reset(void *objPtr);
u16 ResourcePool_AllocateSlot(void);
void Buffer_Reverse(u8 *buffer, u32 length);

#define RESOURCE_MAGIC_0C      0x00003443
#define RESOURCE_MAGIC_20      0x000064E1
#define RESOURCE_DEFAULT_28    0x40
#define RESOURCE_ID_MASK       0x00FFFFFF
#define RESOURCE_HAS_SECONDARY 0x01

#endif // GHIDRA_LEGACY_H
