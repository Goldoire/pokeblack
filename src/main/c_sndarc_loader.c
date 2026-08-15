/* lib/TwlSystem/build/libraries/snd/src/sndarc_loader.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
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
/* not in shard or dead-stripped: NNS_SndArcLoadGroup (24B) */
/* not in shard or dead-stripped: NNS_SndArcLoadSeq (48B) */
/* not in shard or dead-stripped: NNS_SndArcLoadSeqArc (48B) */
/* not in shard or dead-stripped: NNS_SndArcLoadBank (48B) */
/* not in shard or dead-stripped: NNS_SndArcLoadWaveArc (48B) */
/* not in shard or dead-stripped: NNS_SndArcLoadSeqEx (40B) */
/* not in shard or dead-stripped: NNS_SndArcLoadBankEx (40B) */
/* not in shard or dead-stripped: NNSi_SndArcLoadGroup (252B) */
/* not in shard or dead-stripped: NNSi_SndArcLoadWaveArc (132B) */
/* not in shard or dead-stripped: NNSi_SndArcLoadFile (164B) */
/* not in shard or dead-stripped: LoadSeq (108B) */
/* not in shard or dead-stripped: LoadSeqArc (108B) */
/* not in shard or dead-stripped: LoadBank (108B) */
/* not in shard or dead-stripped: LoadWaveArc (108B) */
/* not in shard or dead-stripped: LoadWaveArcTable (296B) */
/* not in shard or dead-stripped: LoadSingleWaves (192B) */

#include "../../lib/TwlSystem/build/libraries/snd/src/sndarc_loader.c"
