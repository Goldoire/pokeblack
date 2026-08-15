/* lib/NitroSDK/TwlSDK/build/libraries/pxi/common/src/pxi_init.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define PXI_InitFifo                         sub_020884A4

#define PXI_Init sub_02088498

#include "../../lib/NitroSDK/TwlSDK/build/libraries/pxi/common/src/pxi_init.c"
