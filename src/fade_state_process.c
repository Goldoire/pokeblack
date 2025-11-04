#include "types.h"

// External function declarations
extern void FUN_02001fbc(void);
extern void* FUN_0200190c(void);
extern void FUN_0206ee8c(void* heapBlockPtr, u32 param);

void FUN_02001de4(u32 param) {
    // Handle state transitions and fade updates
    FUN_02001fbc();
    
    // Get heap block pointer
    void* heapBlockPtr = FUN_0200190c();
    
    // Update graphics/palette with parameter
    FUN_0206ee8c(heapBlockPtr, param);
}
