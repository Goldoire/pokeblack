/* TwlSDK/TwlSystem lib/TwlSystem/build/libraries/snd/src/waveout.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define NNS_SndUnlockChannel                 sub_02072974
#define SND_SetupChannelPcm                  sub_02089660
#define SND_StartTimer                       sub_020894B4
#define SND_GetCurrentCommandTag             sub_02089D40
#define SND_StopTimer                        sub_020894DC
#define SND_SetChannelVolume                 sub_02089638
#define SND_SetChannelTimer                  sub_02089618
#define SND_IsFinishedCommandTag             sub_02089D6C
#define SND_GetChannelStatus                 sub_0208A07C
#define SND_FlushCommand                     sub_02089B38
#define SND_WaitForCommandProc               sub_02089CD4
#define NNS_SndWaveOutAllocChannel       sub_02072A44
#define NNS_SndWaveOutSetVolume          sub_02072C18
#define NNS_SndWaveOutSetSpeed           sub_02072C40
#define NNS_SndWaveOutIsPlaying          sub_02072CC4
/* stripped or unplaced: NNS_SndWaveOutFreeChannel (24B) */
/* stripped or unplaced: NNS_SndWaveOutStart (300B) */
/* stripped or unplaced: NNS_SndWaveOutStop (60B) */
/* stripped or unplaced: NNS_SndWaveOutSetPan (36B) */
/* stripped or unplaced: NNS_SndWaveOutWaitForChannelStop (120B) */

#include "../../lib/TwlSystem/build/libraries/snd/src/waveout.c"
