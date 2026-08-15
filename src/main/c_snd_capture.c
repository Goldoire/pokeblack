/* lib/TwlSystem/build/libraries/snd/src/capture.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define MIi_CpuClear32                       sub_02082A7C
#define DC_FlushRange                        sub_020862F0
#define NNSi_SndFaderSet                     sub_02075BAC
#define OS_InitMessageQueue                  sub_02085D94
#define OS_CreateThread                      sub_020853C0
#define OS_WakeupThreadDirect                sub_02085868
#define OS_SendMessage                       sub_02085DBC
#define OS_JoinThread                        sub_02085710
#define NNSi_SndFaderUpdate                  sub_02075C08
#define NNSi_SndFaderIsFinished              sub_02075C20
#define NNSi_SndFaderGet                     sub_02075BD4
#define SND_SetChannelVolume                 sub_02089638
#define NNS_SndFreeAlarm                     sub_02072A08
#define NNS_SndUnlockCapture                 sub_020729A4
#define SND_SetupChannelPcm                  sub_02089660
#define SND_SetupAlarm                       sub_02089540
#define SND_SetOutputSelector                sub_0208972C
#define SND_StartTimer                       sub_020894B4
#define NNSi_SndFaderInit                    sub_02075B94
#define SND_StopTimer                        sub_020894DC
#define SND_GetCurrentCommandTag             sub_02089D40
#define SND_FlushCommand                     sub_02089B38
#define SND_WaitForCommandProc               sub_02089CD4
#define OS_ReceiveMessage                    sub_02085E50
#define NNS_SndUnlockChannel                 sub_02072974
#define DC_InvalidateRange                   sub_020862B8

#define NNSi_SndCaptureInit           sub_02073D5C
#define NNSi_SndCaptureMain           sub_02073D7C
#define NNSi_SndCaptureBeginSleep     sub_02073EE4
/* not in shard or dead-stripped: NNS_SndCaptureStartReverb (172B) */
/* not in shard or dead-stripped: NNS_SndCaptureSetReverbVolume (60B) */
/* not in shard or dead-stripped: NNS_SndCaptureStopReverb (80B) */
/* not in shard or dead-stripped: NNS_SndCaptureStartEffect (176B) */
/* not in shard or dead-stripped: NNS_SndCaptureStopEffect (44B) */
/* not in shard or dead-stripped: NNS_SndCaptureStartSampling (180B) */
/* not in shard or dead-stripped: NNS_SndCaptureStopSampling (44B) */
/* not in shard or dead-stripped: NNS_SndCaptureCreateThread (140B) */
/* not in shard or dead-stripped: NNS_SndCaptureDestroyThread (64B) */
/* not in shard or dead-stripped: NNS_SndCaptureIsActive (16B) */
/* not in shard or dead-stripped: NNS_SndCaptureGetCaptureType (16B) */
/* not in shard or dead-stripped: NNSi_SndCaptureStart (872B) */
/* not in shard or dead-stripped: NNSi_SndCaptureStop (228B) */
/* not in shard or dead-stripped: NNSi_SndCaptureEndSleep (128B) */
/* not in shard or dead-stripped: AlarmCallback (232B) */
/* not in shard or dead-stripped: CaptureThread (128B) */

#include "../../lib/TwlSystem/build/libraries/snd/src/capture.c"
