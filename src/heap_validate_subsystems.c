#include "types.h"

// External function declarations
extern u32 sub_0208174c(void* param);

// External data - note these point to the SAME structure (0x020AA260)!
extern void* DAT_02001c84;  // Points to 0x020AA260 (CallbackRegistry from sub_02001ce0)
extern void* DAT_02001c88;  // Points to 0x020AA354 (different structure/system)

/**
 * sub_02001c64 - System state validation
 * 
 * This function validates that two subsystems are properly initialized:
 * 1. Checks that a field at offset +0x14 in the CallbackRegistry is non-NULL
 * 2. Validates a second system via sub_0208174c (likely in overlay)
 * 
 * Return value convention appears to be:
 * - 0 = systems are ready / validation passed
 * - 1 = validation failed (specifically second system check failed)
 * 
 * The function returns 0 for both success AND when the first check fails,
 * which suggests the first check is a "soft" prerequisite while the second
 * is a "hard" failure condition.
 * 
 * Structure at 0x020AA260 (expanded from CallbackRegistry):
 * offset +0x00: unknown field
 * offset +0x04: callback function pointer (used by sub_02001ce0)
 * offset +0x14: system state pointer/flag (checked here)
 * 
 * @return 0 if validation passes or first system not ready,
 *         1 if second system validation explicitly fails
 * 
 * Called by:
 * - sub_02001ce0 (checks == 0 before proceeding, returns 1 on failure)
 * - sub_02002984 (twice - at offsets 0x990 and 0x9a0)
 */
u32 sub_02001c64(void) {
    void** systemState;
    
    // Check first system - CallbackRegistry structure at 0x020AA260
    systemState = (void**)DAT_02001c84;  // Load 0x020AA260
    
    // Check if field at offset +0x14 (20 bytes) is initialized
    if (systemState[5] == NULL) {  // offset 0x14 / 4 = index 5
        return 0;  // First system not ready
    }
    
    // Check second system via external validation function
    // sub_0208174c is in overlay (0x0208xxxx range)
    if (sub_0208174c(DAT_02001c88) == 0) {  // 0x020AA354
        return 1;  // Second system validation failed
    }
    
    // Both systems are ready
    return 0;
}
