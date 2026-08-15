/* lib/NitroSDK/TwlSDK/build/libraries/snd/common/src/snd_util.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

#define SND_CalcChannelVolume sub_0208A24C
/* not in shard or dead-stripped: SND_CalcTimer (292B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/snd/common/src/snd_util.c"
