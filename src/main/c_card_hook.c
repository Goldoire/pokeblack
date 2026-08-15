/* lib/NitroSDK/TwlSDK/build/libraries/card/common/src/card_hook.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

#define CARDi_NotifyEvent    sub_02076100
/* not in shard or dead-stripped: CARDi_RegisterHook (52B) */
/* not in shard or dead-stripped: CARDi_UnregisterHook (80B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/card/common/src/card_hook.c"
