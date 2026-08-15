/* TwlSDK/TwlSystem lib/TwlSystem/build/libraries/snd/src/main.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define SND_Init                             sub_02089848
#define PM_AppendPostSleepCallback           sub_0208C828
#define NNSi_SndInitResourceMgr              sub_02072A28
#define NNSi_SndCaptureInit                  sub_02073D5C
#define SND_RecvCommandReply                 sub_02089978
#define NNSi_SndCaptureMain                  sub_02073D7C
#define SND_SetMasterVolume                  sub_0208970C
#define SND_SetMasterPan                     sub_02089754
#define SND_ResetMasterPan                   sub_02089774
#define NNS_SndPlayerStopSeqAll              sub_02072E7C
#define SND_StopTimer                        sub_020894DC
#define SND_GetCurrentCommandTag             sub_02089D40
#define SND_WaitForCommandProc               sub_02089CD4
#define SND_IsFinishedCommandTag             sub_02089D6C
#define SND_ReadDriverInfo                   sub_02089794
#define DC_InvalidateRange                   sub_020862B8
#define SND_ReadTrackInfo                    sub_0208A0A4
#define NNSi_SndCaptureBeginSleep            sub_02073DFC
#define NNS_SndSetMonoFlag           sub_02072794
#define BeginSleep                   sub_020728E8
/* stripped or unplaced: NNS_SndInit (124B) */
/* stripped or unplaced: NNS_SndShutdown (68B) */
/* stripped or unplaced: NNS_SndMain (48B) */
/* stripped or unplaced: NNS_SndSetMasterVolume (12B) */
/* stripped or unplaced: NNS_SndStopSoundAll (88B) */
/* stripped or unplaced: NNS_SndStopChannelAll (24B) */
/* stripped or unplaced: NNS_SndUpdateDriverInfo (212B) */
/* stripped or unplaced: NNS_SndReadDriverChannelInfo (80B) */
/* stripped or unplaced: NNSi_SndReadDriverPlayerInfo (80B) */
/* stripped or unplaced: NNSi_SndReadDriverTrackInfo (88B) */
/* stripped or unplaced: EndSleep (12B) */

#include "../../lib/TwlSystem/build/libraries/snd/src/main.c"
