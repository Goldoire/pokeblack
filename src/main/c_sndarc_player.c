/* TwlSDK/TwlSystem lib/TwlSystem/build/libraries/snd/src/sndarc_player.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define NNS_SndPlayerSetPlayableSeqCount     sub_02072DB0
#define NNS_SndPlayerSetAllocatableChannel   sub_02072DD0
#define NNS_SndPlayerCreateHeap              sub_02072DE8
#define NNSi_SndSeqArcGetSeqInfo             sub_02075B28
#define NNSi_SndArcLoadBank                  sub_02074CD0
#define NNSi_SndArcLoadSeq                   sub_02074BEC
#define NNS_SndPlayerSetInitialVolume        sub_02072F48
#define NNS_SndPlayerSetChannelPriority      sub_02072FA4
#define NNS_SndPlayerSetSeqArcNo             sub_020730DC
#define NNS_SndArcPlayerStartSeq      sub_02075560
#define NNS_SndArcPlayerStartSeqEx    sub_020755A8
#define NNS_SndArcPlayerStartSeqArc   sub_02075618
/* stripped or unplaced: NNS_SndArcPlayerSetup (152B) */
/* stripped or unplaced: NNS_SndArcPlayerStartSeqArcEx (172B) */
/* stripped or unplaced: StartSeq (260B) */
/* stripped or unplaced: StartSeqArc (200B) */

#include "../../lib/TwlSystem/build/libraries/snd/src/sndarc_player.c"
