/* lib/NitroSDK/TwlSDK/build/libraries/fx/common/src/fx_atanidx.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

#define FX_Atan2Idx sub_0207CFB8
/* not in shard or dead-stripped: FX_AtanIdx (184B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/fx/common/src/fx_atanidx.c"
