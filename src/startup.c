#include <nitro.h>

/**
 * @brief __startup - Runtime initialization function
 *
 * This function is called by crt0.o before main/TwlMain.
 * It initializes C runtime, BSS section, data section, etc.
 *
 * For now this is a stub - the actual initialization happens
 * in the SDK's crt0.o.
 */
void __startup(void) {
    // SDK's crt0.o handles the actual startup
    // This stub satisfies the linker requirement
}
