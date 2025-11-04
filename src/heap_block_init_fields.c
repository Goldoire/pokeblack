/**
 * @file heap_block_init_fields.c
 * @brief Initializes heap block fields with default values
 * 
 * Original address: 0x020019c8
 * 
checks if a heap block is active (first field non-zero), if yes initializes several fields including setting the heap ID to 0xFFFF and copying values across multiple offset locations.
 * 
 * @note Assembly implementation in asm/unk_020019c8.s
 */

#include "types.h"

// External data references
extern u32 DAT_020019f4;  // Points to 0x020AA1AC - Main heap control structure
extern u32 DAT_020019f8;  // Points to 0x020AA1B8 - Heap block array
extern u16 DAT_020019fc;  // Value 0xFFFF - Default heap ID

// External function declarations
extern void sub_020708e0(void* param1, void* param2);

/**
 * @brief Initializes fields in the current heap block
 * 
 * Performs conditional initialization of heap block fields:
 * - Sets heap ID to 0xFFFF
 * - Calls overlay initialization function
 * - Copies value from offset +0x10 to offsets +0x14 and +0x18
 */
void sub_020019c8(void) {
    u32* structPtr1 = (u32*)DAT_020019f4;  // 0x020AA1AC
    u32* heapBlockArray = (u32*)DAT_020019f8;  // 0x020AA1B8
    
    // Get index from structPtr1[1] (offset +4)
    u32 index = structPtr1[1];
    
    // Calculate offset: index * 28 (0x1C)
    u32 offset = index * 0x1C;
    
    // Get pointer to the heap block structure
    u32* heapBlock = (u32*)((u8*)heapBlockArray + offset);
    
    // Check if first field is non-zero
    if (heapBlock[0] != 0) {
        // Store 0xFFFF at offset +4 (as halfword)
        *(u16*)((u8*)heapBlock + 4) = DAT_020019fc;
        
        // Get pointer from structPtr1[2] (offset +8), then dereference it
        void* param1 = *(void**)structPtr1[2];
        
        // Get value from heapBlock offset +0x10
        void* param2 = (void*)heapBlock[4];  // offset 0x10 = 4th u32
        
        // Call overlay function
        sub_020708e0(param1, param2);
        
        // Copy value from offset +0x10 to +0x14 and +0x18
        u32 value = heapBlock[4];  // offset +0x10
        heapBlock[5] = value;      // offset +0x14
        heapBlock[6] = value;      // offset +0x18
    }
}
