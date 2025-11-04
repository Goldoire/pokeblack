#include "types.h"

// External function declarations
extern void sub_02001fbc(void);
extern void* sub_0200190c(void);
extern void sub_0206ee8c(void* heapBlockPtr, u32 param);

void sub_02001de4(u32 param) {
    // Handle state transitions and fade updates
    sub_02001fbc();
    
    // Get heap block pointer
    void* heapBlockPtr = sub_0200190c();
    
    // Update graphics/palette with parameter
    sub_0206ee8c(heapBlockPtr, param);
}
