/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/snd/common/src/snd_util.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

#define SND_CalcChannelVolume sub_0208A24C
/* stripped or unplaced: SND_CalcTimer (292B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/snd/common/src/snd_util.c"
