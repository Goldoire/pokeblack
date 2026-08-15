/* lib/TwlSystem/build/libraries/snd/src/heap.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define NNS_FndCreateFrmHeapEx               sub_020610E0
#define NNS_FndDestroyFrmHeap                sub_02061118
#define NNS_FndGetPrevListObject             sub_0206062C
#define NNS_FndRemoveListObject              sub_020605B4
#define NNS_FndFreeToFrmHeap                 sub_02061158
#define NNS_FndAllocFromFrmHeapEx            sub_02061124
#define NNS_FndAppendListObject              sub_020604AC
#define NNS_FndRecordStateForFrmHeap         sub_02061184
#define NNS_FndFreeByStateToFrmHeap          sub_020611D4
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
/* not in shard or dead-stripped: NNS_SndHeapCreate (116B) */
/* not in shard or dead-stripped: NNS_SndHeapSaveState (80B) */
/* not in shard or dead-stripped: NNS_SndHeapGetCurrentLevel (12B) */
/* not in shard or dead-stripped: NNS_SndHeapGetSize (16B) */
/* not in shard or dead-stripped: NNS_SndHeapGetFreeSize (36B) */
/* not in shard or dead-stripped: InitHeapSection (16B) */

#include "../../lib/TwlSystem/build/libraries/snd/src/heap.c"
