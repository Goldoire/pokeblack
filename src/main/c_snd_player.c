/* lib/TwlSystem/build/libraries/snd/src/player.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
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
/* not in shard or dead-stripped: NNS_SndPlayerCreateHeap (132B) */
/* not in shard or dead-stripped: NNS_SndPlayerStopSeq (16B) */
/* not in shard or dead-stripped: NNS_SndPlayerStopSeqByPlayerNo (92B) */
/* not in shard or dead-stripped: NNS_SndPlayerStopSeqBySeqNo (88B) */
/* not in shard or dead-stripped: NNS_SndPlayerStopSeqBySeqArcNo (88B) */
/* not in shard or dead-stripped: NNS_SndPlayerStopSeqBySeqArcIdx (100B) */
/* not in shard or dead-stripped: NNS_SndPlayerStopSeqAll (64B) */
/* not in shard or dead-stripped: NNS_SndPlayerPause (16B) */
/* not in shard or dead-stripped: NNS_SndPlayerPauseByPlayerNo (88B) */
/* not in shard or dead-stripped: NNS_SndPlayerPauseAll (80B) */
/* not in shard or dead-stripped: NNS_SndHandleReleaseSeq (28B) */
/* not in shard or dead-stripped: NNS_SndPlayerCountPlayingSeqBySeqArcNo (84B) */
/* not in shard or dead-stripped: NNS_SndPlayerCountPlayingSeqBySeqArcIdx (96B) */
/* not in shard or dead-stripped: NNS_SndPlayerSetChannelPriority (32B) */
/* not in shard or dead-stripped: NNS_SndPlayerSetTrackMute (32B) */
/* not in shard or dead-stripped: NNS_SndPlayerSetTrackMuteEx (32B) */
/* not in shard or dead-stripped: SND_SetTrackMuteEx (4B) */
/* not in shard or dead-stripped: NNS_SndPlayerSetTrackPitch (32B) */
/* not in shard or dead-stripped: NNS_SndPlayerSetTrackPan (32B) */
/* not in shard or dead-stripped: NNS_SndPlayerSetTrackPanRange (32B) */
/* not in shard or dead-stripped: NNS_SndPlayerSetTrackModDepth (32B) */
/* not in shard or dead-stripped: NNS_SndPlayerSetTrackModSpeed (32B) */
/* not in shard or dead-stripped: NNS_SndPlayerSetTrackAllocatableChannel (32B) */
/* not in shard or dead-stripped: NNS_SndPlayerSetTempoRatio (32B) */
/* not in shard or dead-stripped: NNS_SndPlayerSetSeqNo (32B) */
/* not in shard or dead-stripped: NNS_SndPlayerGetSeqType (24B) */
/* not in shard or dead-stripped: NNS_SndPlayerGetSeqNo (40B) */
/* not in shard or dead-stripped: NNS_SndPlayerGetSeqArcNo (40B) */
/* not in shard or dead-stripped: NNS_SndPlayerGetSeqArcIdx (40B) */
/* not in shard or dead-stripped: NNS_SndPlayerReadVariable (72B) */
/* not in shard or dead-stripped: NNS_SndPlayerReadGlobalVariable (24B) */
/* not in shard or dead-stripped: NNS_SndPlayerWriteVariable (40B) */
/* not in shard or dead-stripped: NNS_SndPlayerGetTick (52B) */
/* not in shard or dead-stripped: NNS_SndPlayerReadDriverPlayerInfo (36B) */
/* not in shard or dead-stripped: NNS_SndPlayerReadDriverTrackInfo (36B) */
/* not in shard or dead-stripped: NNSi_SndPlayerInit (180B) */
/* not in shard or dead-stripped: NNSi_SndPlayerMain (356B) */
/* not in shard or dead-stripped: NNSi_SndPlayerAllocSeqPlayer (156B) */
/* not in shard or dead-stripped: NNSi_SndPlayerFreeSeqPlayer (12B) */
/* not in shard or dead-stripped: NNSi_SndPlayerStartSeq (80B) */
/* not in shard or dead-stripped: NNSi_SndPlayerStopSeq (80B) */
/* not in shard or dead-stripped: NNSi_SndPlayerPause (40B) */
/* not in shard or dead-stripped: NNSi_SndPlayerAllocHeap (88B) */
/* not in shard or dead-stripped: InitPlayer (72B) */
/* not in shard or dead-stripped: InsertPlayerList (80B) */
/* not in shard or dead-stripped: InsertPrioList (84B) */
/* not in shard or dead-stripped: ForceStopSeq (56B) */
/* not in shard or dead-stripped: AllocSeqPlayer (108B) */
/* not in shard or dead-stripped: ShutdownPlayer (128B) */
/* not in shard or dead-stripped: PlayerHeapDisposeCallback (80B) */
/* not in shard or dead-stripped: SetPlayerPriority (96B) */

#include "../../lib/TwlSystem/build/libraries/snd/src/player.c"
