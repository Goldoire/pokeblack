/* lib/TwlSystem/build/libraries/snd/src/main.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define SND_Init                             sub_02089848
#define PM_AppendPostSleepCallback           sub_0208C828
#define NNSi_SndInitResourceMgr              sub_02072A28
#define NNSi_SndCaptureInit                  sub_02073D5C
#define SND_RecvCommandReply                 sub_02089978
#define NNSi_SndPlayerMain                   sub_020731E0
#define NNSi_SndCaptureMain                  sub_02073D7C
#define SND_FlushCommand                     sub_02089B38
#define SND_SetMasterVolume                  sub_0208970C
#define SND_SetMasterPan                     sub_02089754
#define SND_ResetMasterPan                   sub_02089774
#define SND_StopTimer                        sub_020894DC
#define SND_GetCurrentCommandTag             sub_02089D40
#define SND_WaitForCommandProc               sub_02089CD4
#define SND_IsFinishedCommandTag             sub_02089D6C
#define SND_ReadDriverInfo                   sub_02089794
#define DC_InvalidateRange                   sub_020862B8
#define SND_ReadTrackInfo                    sub_0208A0A4
#define NNSi_SndCaptureBeginSleep            sub_02073EE4

#define NNS_SndSetMonoFlag           sub_02072794
#define BeginSleep                   sub_020728E8
/* not in shard or dead-stripped: NNS_SndInit (124B) */
/* not in shard or dead-stripped: NNS_SndShutdown (68B) */
/* not in shard or dead-stripped: NNS_SndMain (48B) */
/* not in shard or dead-stripped: NNS_SndSetMasterVolume (12B) */
/* not in shard or dead-stripped: NNS_SndStopSoundAll (88B) */
/* not in shard or dead-stripped: NNS_SndStopChannelAll (24B) */
/* not in shard or dead-stripped: NNS_SndUpdateDriverInfo (212B) */
/* not in shard or dead-stripped: NNS_SndReadDriverChannelInfo (80B) */
/* not in shard or dead-stripped: NNSi_SndReadDriverPlayerInfo (80B) */
/* not in shard or dead-stripped: NNSi_SndReadDriverTrackInfo (88B) */
/* not in shard or dead-stripped: EndSleep (12B) */

#include "../../lib/TwlSystem/build/libraries/snd/src/main.c"
