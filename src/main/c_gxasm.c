/* lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/gxasm.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

#define GX_SendFifo48B  sub_02080C84
#define GX_SendFifo64B  sub_02080CA8
/* not in shard or dead-stripped: GX_SendFifo128B (44B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/gxasm.c"
