/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/snd/ARM9/src/snd_interface.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define SNDi_IncAlarmId                      sub_02089FC0
#define SNDi_SetAlarmHandler                 sub_02089FE0
#define SND_AllocCommand                     sub_02089A78
#define SND_PushCommand                      sub_02089B00
#define SND_StopSeq                    sub_02089330
#define SND_PrepareSeq                 sub_02089350
#define SND_StartPreparedSeq           sub_02089378
#define SND_PauseSeq                   sub_02089398
#define SND_SetPlayerTempoRatio        sub_020893B8
#define SND_SetPlayerVolume            sub_020893D0
#define SND_SetPlayerChannelPriority   sub_020893E8
#define SND_SetTrackVolume             sub_02089400
#define SND_SetTrackPitch              sub_0208941C
#define SND_SetTrackPan                sub_02089438
#define SND_SetTrackModDepth           sub_02089454
#define SND_SetTrackModSpeed           sub_02089470
#define SND_SetTrackAllocatableChannel sub_0208948C
#define SND_StartTimer                 sub_020894B4
#define SND_StopTimer                  sub_020894DC
#define SND_SetupAlarm                 sub_02089540
#define SND_SetTrackMute               sub_02089580
#define SND_SetTrackMuteEx             sub_020895B0
#define SND_LockChannel                sub_020895D8
#define SND_UnlockChannel              sub_020895F8
#define SND_SetChannelTimer            sub_02089618
#define SND_SetChannelVolume           sub_02089638
#define SND_SetupChannelPcm            sub_02089660
#define SND_InvalidateSeqData          sub_020896AC
#define SND_InvalidateBankData         sub_020896CC
#define SND_InvalidateWaveData         sub_020896EC
#define SND_SetMasterVolume            sub_0208970C
#define SND_SetOutputSelector          sub_0208972C
#define SND_SetMasterPan               sub_02089754
#define SND_ResetMasterPan             sub_02089774
#define SND_ReadDriverInfo             sub_02089794
#define SNDi_SetPlayerParam            sub_020897B4
#define SNDi_SetTrackParam             sub_020897DC
#define PushCommand_impl               sub_02089804
/* stripped or unplaced: SND_StartSeq (40B) */
/* stripped or unplaced: SND_SetPlayerLocalVariable (40B) */
/* stripped or unplaced: SND_SetPlayerGlobalVariable (32B) */
/* stripped or unplaced: SND_SetTrackPanRange (24B) */
/* stripped or unplaced: SND_SetupCapture (64B) */
/* stripped or unplaced: SND_StopUnlockedChannel (32B) */
/* stripped or unplaced: SND_SetChannelPan (32B) */
/* stripped or unplaced: SND_SetupChannelPsg (40B) */
/* stripped or unplaced: SND_SetupChannelNoise (52B) */
/* stripped or unplaced: SNDi_SetSurroundDecay (32B) */
/* stripped or unplaced: SNDi_SkipSeq (32B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/snd/ARM9/src/snd_interface.c"
