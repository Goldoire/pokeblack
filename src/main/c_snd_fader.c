/* TwlSDK/TwlSystem lib/TwlSystem/build/libraries/snd/src/fader.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define _s32_div_f                           sub_0209C0AC
#define NNSi_SndFaderInit       sub_02075B94
#define NNSi_SndFaderSet        sub_02075BAC
#define NNSi_SndFaderGet        sub_02075BD4
#define NNSi_SndFaderUpdate     sub_02075C08
#define NNSi_SndFaderIsFinished sub_02075C20

#include "../../lib/TwlSystem/build/libraries/snd/src/fader.c"
