#include "types.h"

// External data references
extern u32 sub_0200238c;  // Points to 0x020AA260 (HeapManagerState)
extern u32 DAT_02002390;  // Points to 0x020AA354

// External function declarations
extern u32 sub_0208174c(u32* param);
extern void sub_020815bc(u32* param);

void sub_02002368(void) {
    u32* r4 = (u32*)sub_0200238c;  // 0x020AA260 (HeapManagerState)
    u32* r5;
    u32 r0;
    
    // Load field at +0x14
    r0 = r4[5];  // offset +0x14
    
    // Check if zero
    if (r0 == 0) {
        return;
    }
    
    // Load overlay pointer
    r5 = (u32*)DAT_02002390;  // 0x020AA354
    
    // Call first overlay function
    r0 = sub_0208174c(r5);
    
    // Check result
    if (r0 == 0) {
        // Call second overlay function
        sub_020815bc(r5);
        
        // Clear field at HeapManagerState+0x14
        r4[5] = 0;
    }
}
