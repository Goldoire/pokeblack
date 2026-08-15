/* TwlSDK/TwlSystem lib/TwlSystem/build/libraries/snd/src/sndarc.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define FS_ConvertPathToFileID               sub_020788D8
#define FS_InitFile                          sub_020788AC
#define FS_OpenFileFast                      sub_020789A4
#define FS_OpenFileEx                        sub_020789FC
#define NNS_SndHeapAlloc                     sub_0207482C
#define MIi_CpuCopy32                        sub_02082A90
#define NNSi_SndSeqArcGetSeqInfo             sub_02075B28
#define NNS_SndArcSetCurrent         sub_020742E4
#define NNS_SndArcGetCurrent         sub_020742FC
#define NNS_SndArcGetSeqParam        sub_0207430C
#define FatDisposeCallback           sub_020746C4
/* stripped or unplaced: NNS_SndArcInit (184B) */
/* stripped or unplaced: NNS_SndArcInitWithResult (144B) */
/* stripped or unplaced: NNS_SndArcSetup (416B) */
/* stripped or unplaced: NNS_SndArcInitOnMemory (184B) */
/* stripped or unplaced: NNS_SndArcGetSeqArcParam (68B) */
/* stripped or unplaced: NNS_SndArcGetSeqInfo (100B) */
/* stripped or unplaced: NNS_SndArcGetSeqArcInfo (100B) */
/* stripped or unplaced: NNS_SndArcGetBankInfo (100B) */
/* stripped or unplaced: NNS_SndArcGetWaveArcInfo (100B) */
/* stripped or unplaced: NNS_SndArcGetStrmInfo (100B) */
/* stripped or unplaced: NNS_SndArcGetPlayerInfo (100B) */
/* stripped or unplaced: NNS_SndArcGetStrmPlayerInfo (100B) */
/* stripped or unplaced: NNS_SndArcGetGroupInfo (100B) */
/* stripped or unplaced: NNS_SndArcGetSeqCount (48B) */
/* stripped or unplaced: NNS_SndArcGetSeqArcCount (48B) */
/* stripped or unplaced: NNS_SndArcGetBankCount (48B) */
/* stripped or unplaced: NNS_SndArcGetWaveArcCount (48B) */
/* stripped or unplaced: NNS_SndArcGetStrmCount (48B) */
/* stripped or unplaced: NNS_SndArcGetGroupCount (48B) */
/* stripped or unplaced: NNS_SndArcGetSeqArcSeqCount (48B) */
/* stripped or unplaced: NNS_SndArcGetFileOffset (40B) */
/* stripped or unplaced: NNS_SndArcGetFileSize (40B) */
/* stripped or unplaced: NNS_SndArcReadFile (200B) */
/* stripped or unplaced: NNS_SndArcGetFileID (32B) */
/* stripped or unplaced: NNS_SndArcGetFileAddress (40B) */
/* stripped or unplaced: NNS_SndArcSetFileAddress (28B) */
/* stripped or unplaced: NNS_SndArcGetLoadBlockSize (20B) */
/* stripped or unplaced: NNS_SndArcSetLoadBlockSize (20B) */
/* stripped or unplaced: NNS_SndArcGetSeqSymbol (76B) */
/* stripped or unplaced: NNS_SndArcGetSeqArcSymbol (120B) */
/* stripped or unplaced: NNS_SndArcGetSeqArcIdxSymbol (132B) */
/* stripped or unplaced: NNS_SndArcGetBankSymbol (76B) */
/* stripped or unplaced: NNS_SndArcGetWaveArcSymbol (76B) */
/* stripped or unplaced: NNS_SndArcGetStrmSymbol (76B) */
/* stripped or unplaced: NNS_SndArcGetGroupSymbol (76B) */
/* stripped or unplaced: NNSi_SndArcSetFilePath (8B) */
/* stripped or unplaced: NNSi_SndArcGetFilePath (20B) */
/* stripped or unplaced: NNSi_SndArcSetSeekCacheInfo (12B) */
/* stripped or unplaced: NNSi_SndArcGetSeekCache (20B) */
/* stripped or unplaced: NNSi_SndArcGetSeekCacheSize (20B) */
/* stripped or unplaced: GetSymbol (64B) */
/* stripped or unplaced: InfoDisposeCallback (12B) */
/* stripped or unplaced: SymbolDisposeCallback (12B) */

#include "../../lib/TwlSystem/build/libraries/snd/src/sndarc.c"
