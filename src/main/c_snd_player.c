/* TwlSDK/TwlSystem lib/TwlSystem/build/libraries/snd/src/player.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define NNS_SndHeapAlloc                     sub_0207482C
#define NNS_FndAppendListObject              sub_020604AC
#define NNS_FndGetNextListObject             sub_02060614
#define NNSi_SndFaderSet                     sub_02075BAC
#define SND_SetPlayerChannelPriority         sub_020893E8
#define SND_SetTrackMute                     sub_02089580
#define SND_SetTrackVolume                   sub_02089400
#define SND_SetTrackPitch                    sub_0208941C
#define SND_SetTrackPan                      sub_02089438
#define SND_SetTrackModDepth                 sub_02089454
#define SND_SetTrackModSpeed                 sub_02089470
#define SND_SetTrackAllocatableChannel       sub_0208948C
#define SND_SetPlayerTempoRatio              sub_020893B8
#define NNS_FndInitList                      sub_02060468
#define SND_GetPlayerStatus                  sub_0208A054
#define SND_IsFinishedCommandTag             sub_02089D6C
#define NNSi_SndFaderUpdate                  sub_02075C08
#define NNSi_SndFaderGet                     sub_02075BD4
#define SND_SetPlayerVolume                  sub_020893D0
#define NNSi_SndFaderIsFinished              sub_02075C20
#define SND_StartPreparedSeq                 sub_02089378
#define SND_PrepareSeq                       sub_02089350
#define SND_GetCurrentCommandTag             sub_02089D40
#define SND_PauseSeq                         sub_02089398
#define NNS_FndRemoveListObject              sub_020605B4
#define NNS_SndHeapClear                     sub_02074770
#define NNSi_SndFaderInit                    sub_02075B94
#define NNS_FndInsertListObject              sub_02060550
#define SND_StopSeq                          sub_02089330
#define NNS_SndHeapDestroy                   sub_02074758
#define NNS_SndPlayerSetPlayerVolume            sub_02072D98
#define NNS_SndPlayerSetPlayableSeqCount        sub_02072DB0
#define NNS_SndPlayerSetAllocatableChannel      sub_02072DD0
#define NNS_SndHandleInit                       sub_02072EBC
#define NNS_SndPlayerCountPlayingSeqByPlayerNo  sub_02072EC8
#define NNS_SndPlayerCountPlayingSeqBySeqNo     sub_02072EE0
#define NNS_SndPlayerSetVolume                  sub_02072F34
#define NNS_SndPlayerSetInitialVolume           sub_02072F48
#define NNS_SndPlayerMoveVolume                 sub_02072F5C
#define NNS_SndPlayerSetPlayerPriority          sub_02072F88
#define NNS_SndPlayerSetTrackVolume             sub_02072FE8
#define NNS_SndPlayerSetSeqArcNo                sub_020730DC
#define NNS_SndPlayerWriteGlobalVariable        sub_02079254
/* stripped or unplaced: NNS_SndPlayerCreateHeap (132B) */
/* stripped or unplaced: NNS_SndPlayerStopSeq (16B) */
/* stripped or unplaced: NNS_SndPlayerStopSeqByPlayerNo (92B) */
/* stripped or unplaced: NNS_SndPlayerStopSeqBySeqNo (88B) */
/* stripped or unplaced: NNS_SndPlayerStopSeqBySeqArcNo (88B) */
/* stripped or unplaced: NNS_SndPlayerStopSeqBySeqArcIdx (100B) */
/* stripped or unplaced: NNS_SndPlayerStopSeqAll (64B) */
/* stripped or unplaced: NNS_SndPlayerPause (16B) */
/* stripped or unplaced: NNS_SndPlayerPauseByPlayerNo (88B) */
/* stripped or unplaced: NNS_SndPlayerPauseAll (80B) */
/* stripped or unplaced: NNS_SndHandleReleaseSeq (28B) */
/* stripped or unplaced: NNS_SndPlayerCountPlayingSeqBySeqArcNo (84B) */
/* stripped or unplaced: NNS_SndPlayerCountPlayingSeqBySeqArcIdx (96B) */
/* stripped or unplaced: NNS_SndPlayerSetChannelPriority (32B) */
/* stripped or unplaced: NNS_SndPlayerSetTrackMute (32B) */
/* stripped or unplaced: NNS_SndPlayerSetTrackMuteEx (32B) */
/* stripped or unplaced: SND_SetTrackMuteEx (4B) */
/* stripped or unplaced: NNS_SndPlayerSetTrackPitch (32B) */
/* stripped or unplaced: NNS_SndPlayerSetTrackPan (32B) */
/* stripped or unplaced: NNS_SndPlayerSetTrackPanRange (32B) */
/* stripped or unplaced: NNS_SndPlayerSetTrackModDepth (32B) */
/* stripped or unplaced: NNS_SndPlayerSetTrackModSpeed (32B) */
/* stripped or unplaced: NNS_SndPlayerSetTrackAllocatableChannel (32B) */
/* stripped or unplaced: NNS_SndPlayerSetTempoRatio (32B) */
/* stripped or unplaced: NNS_SndPlayerSetSeqNo (32B) */
/* stripped or unplaced: NNS_SndPlayerGetSeqType (24B) */
/* stripped or unplaced: NNS_SndPlayerGetSeqNo (40B) */
/* stripped or unplaced: NNS_SndPlayerGetSeqArcNo (40B) */
/* stripped or unplaced: NNS_SndPlayerGetSeqArcIdx (40B) */
/* stripped or unplaced: NNS_SndPlayerReadVariable (72B) */
/* stripped or unplaced: NNS_SndPlayerReadGlobalVariable (24B) */
/* stripped or unplaced: NNS_SndPlayerWriteVariable (40B) */
/* stripped or unplaced: NNS_SndPlayerGetTick (52B) */
/* stripped or unplaced: NNS_SndPlayerReadDriverPlayerInfo (36B) */
/* stripped or unplaced: NNS_SndPlayerReadDriverTrackInfo (36B) */
/* stripped or unplaced: NNSi_SndPlayerInit (180B) */
/* stripped or unplaced: NNSi_SndPlayerMain (356B) */
/* stripped or unplaced: NNSi_SndPlayerAllocSeqPlayer (156B) */
/* stripped or unplaced: NNSi_SndPlayerFreeSeqPlayer (12B) */
/* stripped or unplaced: NNSi_SndPlayerStartSeq (80B) */
/* stripped or unplaced: NNSi_SndPlayerStopSeq (80B) */
/* stripped or unplaced: NNSi_SndPlayerPause (40B) */
/* stripped or unplaced: NNSi_SndPlayerAllocHeap (88B) */
/* stripped or unplaced: InitPlayer (72B) */
/* stripped or unplaced: InsertPlayerList (80B) */
/* stripped or unplaced: InsertPrioList (84B) */
/* stripped or unplaced: ForceStopSeq (56B) */
/* stripped or unplaced: AllocSeqPlayer (108B) */
/* stripped or unplaced: ShutdownPlayer (128B) */
/* stripped or unplaced: PlayerHeapDisposeCallback (80B) */
/* stripped or unplaced: SetPlayerPriority (96B) */

#include "../../lib/TwlSystem/build/libraries/snd/src/player.c"
