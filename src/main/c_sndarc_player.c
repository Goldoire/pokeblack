/* lib/TwlSystem/build/libraries/snd/src/sndarc_player.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define NNS_SndArcGetCurrent                 sub_020742FC
#define NNS_SndPlayerSetPlayableSeqCount     sub_02072DB0
#define NNS_SndPlayerSetAllocatableChannel   sub_02072DD0
#define NNSi_SndSeqArcGetSeqInfo             sub_02075B54
#define NNSi_SndArcLoadBank                  sub_02074CD0
#define NNSi_SndArcLoadSeq                   sub_02074BEC
#define NNS_SndPlayerSetInitialVolume        sub_02072F48
#define NNS_SndPlayerSetSeqArcNo             sub_020730DC

#define NNS_SndArcPlayerStartSeq      sub_02075560
#define NNS_SndArcPlayerStartSeqEx    sub_020755A8
#define NNS_SndArcPlayerStartSeqArc   sub_02075618
/* not in shard or dead-stripped: NNS_SndArcPlayerSetup (152B) */
/* not in shard or dead-stripped: NNS_SndArcPlayerStartSeqArcEx (172B) */
/* not in shard or dead-stripped: StartSeq (260B) */
/* not in shard or dead-stripped: StartSeqArc (200B) */

#include "../../lib/TwlSystem/build/libraries/snd/src/sndarc_player.c"
