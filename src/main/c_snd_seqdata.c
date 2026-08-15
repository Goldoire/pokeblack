/* lib/TwlSystem/build/libraries/snd/src/seqdata.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

#define NNSi_SndSeqArcGetSeqInfo  sub_02075B54
/* not in shard or dead-stripped: NNSi_SndSeqArcGetSeqCount (8B) */

#include "../../lib/TwlSystem/build/libraries/snd/src/seqdata.c"
