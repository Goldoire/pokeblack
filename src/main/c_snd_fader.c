/* lib/TwlSystem/build/libraries/snd/src/fader.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

#define NNSi_SndFaderInit       sub_02075B94
#define NNSi_SndFaderSet        sub_02075BAC
#define NNSi_SndFaderGet        sub_02075BD4
#define NNSi_SndFaderUpdate     sub_02075C08
#define NNSi_SndFaderIsFinished sub_02075C20

#include "../../lib/TwlSystem/build/libraries/snd/src/fader.c"
