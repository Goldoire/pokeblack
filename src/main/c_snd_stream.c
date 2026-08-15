/* TwlSDK/TwlSystem lib/TwlSystem/build/libraries/snd/src/stream.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define NNS_FndInitList                      sub_02060468
#define NNS_SndLockChannel                   sub_02072934
#define NNS_SndUnlockChannel                 sub_02072974
#define _u32_div_f                           sub_0209C2B8
#define NNS_SndAllocAlarm                    sub_020729C8
#define SND_SetupChannelPcm                  sub_02089660
#define SND_SetupAlarm                       sub_02089540
#define NNS_FndAppendListObject              sub_020604AC
#define OS_DisableInterrupts                 sub_02087988
#define OS_RestoreInterrupts                 sub_0208799C
#define SND_StartTimer                       sub_020894B4
#define PM_PrependPreSleepCallback           sub_0208C810
#define PM_AppendPostSleepCallback           sub_0208C828
#define SND_CalcChannelVolume                sub_0208A24C
#define SND_SetChannelVolume                 sub_02089638
#define SND_StopTimer                        sub_020894DC
#define PM_DeletePostSleepCallback           sub_0208C88C
#define SND_GetCurrentCommandTag             sub_02089D40
#define SND_FlushCommand                     sub_02089B38
#define SND_WaitForCommandProc               sub_02089CD4
#define NNS_SndFreeAlarm                     sub_02072A08
#define NNS_FndRemoveListObject              sub_020605B4
#define NNS_SndStrmFreeChannel      sub_02073898
#define NNS_SndStrmSetup            sub_020738C0
#define NNS_SndStrmStart            sub_02073A60
#define NNS_SndStrmStop             sub_02073AB4
#define NNS_SndStrmSetVolume        sub_02073AD0
#define ForceStopStrm               sub_02073B3C
#define ShutdownStrm                sub_02073BB0
#define AlarmCallback               sub_02073BE0
#define StrmCallback                sub_02073BF0
#define BeginSleep                  sub_02073CA0
#define EndSleep                    sub_02073CEC
/* stripped or unplaced: NNS_SndStrmInit (116B) */
/* stripped or unplaced: NNS_SndStrmAllocChannel (92B) */
/* stripped or unplaced: NNS_SndStrmSetChannelVolume (84B) */
/* stripped or unplaced: NNS_SndStrmSetChannelPan (48B) */

#include "../../lib/TwlSystem/build/libraries/snd/src/stream.c"
