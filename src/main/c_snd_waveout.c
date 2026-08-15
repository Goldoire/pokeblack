/* lib/TwlSystem/build/libraries/snd/src/waveout.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define NNS_SndLockChannel                   sub_0207292C
#define NNS_SndUnlockChannel                 sub_02072974
#define _ll_udiv                             sub_0209C00C
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
/* not in shard or dead-stripped: NNS_SndWaveOutFreeChannel (24B) */
/* not in shard or dead-stripped: NNS_SndWaveOutStart (300B) */
/* not in shard or dead-stripped: NNS_SndWaveOutStop (60B) */
/* not in shard or dead-stripped: NNS_SndWaveOutSetPan (36B) */
/* not in shard or dead-stripped: NNS_SndWaveOutWaitForChannelStop (120B) */

#include "../../lib/TwlSystem/build/libraries/snd/src/waveout.c"
