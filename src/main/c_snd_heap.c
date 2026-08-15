/* TwlSDK/TwlSystem lib/TwlSystem/build/libraries/snd/src/heap.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define NNS_FndCreateFrmHeapEx               sub_020610E0
#define NNS_FndDestroyFrmHeap                sub_02061120
#define NNS_FndGetPrevListObject             sub_0206062C
#define NNS_FndRemoveListObject              sub_020605B4
#define NNS_FndFreeToFrmHeap                 sub_02061160
#define NNS_FndAllocFromFrmHeapEx            sub_0206112C
#define NNS_FndAppendListObject              sub_020604AC
#define NNS_FndRecordStateForFrmHeap         sub_0206118C
#define NNS_FndFreeByStateToFrmHeap          sub_020611DC
#define NNS_FndInitList                      sub_02060468
#define SND_GetCurrentCommandTag             sub_02089D40
#define SND_FlushCommand                     sub_02089B38
#define SND_WaitForCommandProc               sub_02089CD4
#define NNS_SndHeapDestroy         sub_02074758
#define NNS_SndHeapClear           sub_02074770
#define NNS_SndHeapAlloc           sub_0207482C
#define NNS_SndHeapLoadState       sub_020748E0
#define InitHeap                   sub_020749C4
#define NewSection                 sub_020749F8
#define EraseSync                  sub_02074A34
/* stripped or unplaced: NNS_SndHeapCreate (116B) */
/* stripped or unplaced: NNS_SndHeapSaveState (80B) */
/* stripped or unplaced: NNS_SndHeapGetCurrentLevel (12B) */
/* stripped or unplaced: NNS_SndHeapGetSize (16B) */
/* stripped or unplaced: NNS_SndHeapGetFreeSize (36B) */
/* stripped or unplaced: InitHeapSection (16B) */

#include "../../lib/TwlSystem/build/libraries/snd/src/heap.c"
