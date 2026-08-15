/* lib/TwlSystem/build/libraries/snd/src/sndarc.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define FS_ConvertPathToFileID               sub_020788D8
#define FS_InitFile                          sub_020788AC
#define FS_OpenFileFast                      sub_020789A4
#define FS_OpenFileEx                        sub_020789FC
#define FS_SeekFile                          sub_02078B44
#define FS_ReadFile                          sub_02078B70
#define NNS_SndHeapAlloc                     sub_0207482C
#define MIi_CpuCopy32                        sub_02082A90
#define NNSi_SndSeqArcGetSeqInfo             sub_02075B54

#define NNS_SndArcSetCurrent         sub_020742E4
#define NNS_SndArcGetCurrent         sub_020742FC
#define NNS_SndArcGetSeqParam        sub_0207430C
#define NNS_SndArcGetSeqInfo         sub_02074324
#define NNS_SndArcGetSeqArcInfo      sub_02074388
#define NNS_SndArcGetBankInfo        sub_020743EC
#define NNS_SndArcGetWaveArcInfo     sub_02074450
#define NNS_SndArcGetStrmInfo        sub_020744B4
#define NNS_SndArcGetPlayerInfo      sub_02074518
#define NNS_SndArcGetFileOffset      sub_0207457C
#define NNS_SndArcReadFile           sub_020745A4
#define NNS_SndArcGetFileAddress     sub_0207466C
#define NNS_SndArcSetFileAddress     sub_02074694
#define NNS_SndArcGetLoadBlockSize   sub_020746B0
#define FatDisposeCallback           sub_020746C4
/* not in shard or dead-stripped: NNS_SndArcInit (184B) */
/* not in shard or dead-stripped: NNS_SndArcInitWithResult (144B) */
/* not in shard or dead-stripped: NNS_SndArcSetup (416B) */
/* not in shard or dead-stripped: NNS_SndArcInitOnMemory (184B) */
/* not in shard or dead-stripped: NNS_SndArcGetSeqArcParam (68B) */
/* not in shard or dead-stripped: NNS_SndArcGetStrmPlayerInfo (100B) */
/* not in shard or dead-stripped: NNS_SndArcGetGroupInfo (100B) */
/* not in shard or dead-stripped: NNS_SndArcGetSeqCount (48B) */
/* not in shard or dead-stripped: NNS_SndArcGetSeqArcCount (48B) */
/* not in shard or dead-stripped: NNS_SndArcGetBankCount (48B) */
/* not in shard or dead-stripped: NNS_SndArcGetWaveArcCount (48B) */
/* not in shard or dead-stripped: NNS_SndArcGetStrmCount (48B) */
/* not in shard or dead-stripped: NNS_SndArcGetGroupCount (48B) */
/* not in shard or dead-stripped: NNS_SndArcGetSeqArcSeqCount (48B) */
/* not in shard or dead-stripped: NNS_SndArcGetFileSize (40B) */
/* not in shard or dead-stripped: NNS_SndArcGetFileID (32B) */
/* not in shard or dead-stripped: NNS_SndArcSetLoadBlockSize (20B) */
/* not in shard or dead-stripped: NNS_SndArcGetSeqSymbol (76B) */
/* not in shard or dead-stripped: NNS_SndArcGetSeqArcSymbol (120B) */
/* not in shard or dead-stripped: NNS_SndArcGetSeqArcIdxSymbol (132B) */
/* not in shard or dead-stripped: NNS_SndArcGetBankSymbol (76B) */
/* not in shard or dead-stripped: NNS_SndArcGetWaveArcSymbol (76B) */
/* not in shard or dead-stripped: NNS_SndArcGetStrmSymbol (76B) */
/* not in shard or dead-stripped: NNS_SndArcGetGroupSymbol (76B) */
/* not in shard or dead-stripped: NNSi_SndArcSetFilePath (8B) */
/* not in shard or dead-stripped: NNSi_SndArcGetFilePath (20B) */
/* not in shard or dead-stripped: NNSi_SndArcSetSeekCacheInfo (12B) */
/* not in shard or dead-stripped: NNSi_SndArcGetSeekCache (20B) */
/* not in shard or dead-stripped: NNSi_SndArcGetSeekCacheSize (20B) */
/* not in shard or dead-stripped: GetSymbol (64B) */
/* not in shard or dead-stripped: InfoDisposeCallback (12B) */
/* not in shard or dead-stripped: SymbolDisposeCallback (12B) */

#include "../../lib/TwlSystem/build/libraries/snd/src/sndarc.c"
