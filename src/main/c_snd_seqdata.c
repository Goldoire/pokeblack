/* TwlSDK/TwlSystem lib/TwlSystem/build/libraries/snd/src/seqdata.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

#define NNSi_SndSeqArcGetSeqInfo  sub_02075B54
/* stripped or unplaced: NNSi_SndSeqArcGetSeqCount (8B) */

#include "../../lib/TwlSystem/build/libraries/snd/src/seqdata.c"
