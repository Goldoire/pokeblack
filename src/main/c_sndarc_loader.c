/* TwlSDK/TwlSystem lib/TwlSystem/build/libraries/snd/src/sndarc_loader.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define SND_AssignWaveArc                    sub_0208A2BC
#define NNS_SndHeapAlloc                     sub_0207482C
#define DC_StoreRange                        sub_020862D4
#define NNS_SndArcGetCurrent                 sub_020742FC
#define MI_CpuCopy8                          sub_02082D44
#define MI_CpuFill8                          sub_02082BCC
#define OS_DisableInterrupts                 sub_02087988
#define NNS_SndArcSetCurrent                 sub_020742E4
#define OS_RestoreInterrupts                 sub_0208799C
#define SND_InvalidateSeqData                sub_020896AC
#define SND_InvalidateBankData               sub_020896CC
#define SND_DestroyBank                      sub_0208A38C
#define SND_InvalidateWaveData               sub_020896EC
#define SND_DestroyWaveArc                   sub_0208A424
#define SND_GetWaveDataAddress               sub_0208A674
#define SND_SetWaveDataAddress               sub_0208A640
#define SND_GetWaveDataCount                 sub_0208A638
#define SND_GetFirstInstDataPos              sub_0208A46C
#define SND_GetNextInstData                  sub_0208A48C
#define NNSi_SndArcLoadSeq          sub_02074BEC
#define NNSi_SndArcLoadSeqArc       sub_02074C70
#define NNSi_SndArcLoadBank         sub_02074CD0
#define DisposeCallback             sub_020751F4
#define SeqDisposeCallback          sub_0207524C
#define BankDisposeCallback         sub_02075274
#define WaveArcDisposeCallback      sub_020752A4
#define WaveArcTableDisposeCallback sub_020752D4
#define SingleWaveDisposeCallback   sub_020752F4
#define LoadSingleWave              sub_0207533C
/* stripped or unplaced: NNS_SndArcLoadGroup (24B) */
/* stripped or unplaced: NNS_SndArcLoadSeq (48B) */
/* stripped or unplaced: NNS_SndArcLoadSeqArc (48B) */
/* stripped or unplaced: NNS_SndArcLoadBank (48B) */
/* stripped or unplaced: NNS_SndArcLoadWaveArc (48B) */
/* stripped or unplaced: NNS_SndArcLoadSeqEx (40B) */
/* stripped or unplaced: NNS_SndArcLoadBankEx (40B) */
/* stripped or unplaced: NNSi_SndArcLoadGroup (252B) */
/* stripped or unplaced: NNSi_SndArcLoadWaveArc (132B) */
/* stripped or unplaced: NNSi_SndArcLoadFile (164B) */
/* stripped or unplaced: LoadSeq (108B) */
/* stripped or unplaced: LoadSeqArc (108B) */
/* stripped or unplaced: LoadBank (108B) */
/* stripped or unplaced: LoadWaveArc (108B) */
/* stripped or unplaced: LoadWaveArcTable (296B) */
/* stripped or unplaced: LoadSingleWaves (192B) */

#include "../../lib/TwlSystem/build/libraries/snd/src/sndarc_loader.c"
