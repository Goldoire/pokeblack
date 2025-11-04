#include "types.h"

// External function declarations
extern u32 sub_0200190c(void);      // Returns heap block metadata pointer
extern void sub_0206ee7c(u32 ptr, u32 value);  // Overlay function - likely memset/initialize
extern void sub_020019c8(void);     // Additional heap initialization

/**
 * sub_02001d14 - Heap block initialization sequence
 * 
 * This function initializes a heap block by:
 * 1. Getting the heap block metadata pointer via sub_0200190c
 * 2. Initializing/zeroing the block via sub_0206ee7c (overlay function)
 * 3. Performing additional heap setup via sub_020019c8
 * 
 * Called as the second step in sub_02001d34's initialization chain,
 * right after callback validation (sub_02001ce0).
 * 
 * Pattern: Classic initialization sequence for heap memory structures
 * 
 * @return void
 * 
 * Called by:
 * - sub_02001d34 (main initialization chain)
 * - sub_02001ff4 (at offset 0x207c)
 */
void sub_02001d14(void)
{
    u32 heapBlockPtr;
    
    // Get pointer to heap block metadata (28-byte structure)
    heapBlockPtr = sub_0200190c();
    
    // Initialize/zero the heap block structure
    // sub_0206ee7c is in overlay (0x0206xxxx range)
    // Second parameter (0) suggests memset to zero or initialization value
    sub_0206ee7c(heapBlockPtr, 0);
    
    // Perform additional heap initialization
    sub_020019c8();
}
