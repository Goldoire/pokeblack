/* lib/NitroSDK/TwlSDK/build/libraries/mi/common/src/mi_swap.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

#define MI_SwapWord sub_020834B8
/* not in shard or dead-stripped: MI_SwapByte (8B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/mi/common/src/mi_swap.c"
