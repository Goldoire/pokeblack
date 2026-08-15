/* lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_alloc.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define OS_DisableInterrupts                 sub_02087988
#define OS_RestoreInterrupts                 sub_0208799C
#define OS_GetDTCMAddress                    sub_02086CE0

#define DLAddFront                sub_020867F4
#define DLExtract                 sub_02086810
#define DLInsert                  sub_02086838
#define OS_AllocFromHeap          sub_020868E0
#define OS_FreeToHeap             sub_020869E8
#define OS_InitAlloc              sub_02086A50
#define OS_CreateHeap             sub_02086AF8
#define OS_ReferentSize           sub_02086C54
#define OS_IsOnVram               sub_02086CBC
/* not in shard or dead-stripped: DLOverlap (76B) */
/* not in shard or dead-stripped: OS_AllocFixed (572B) */
/* not in shard or dead-stripped: OS_FreeAllToHeap (120B) */
/* not in shard or dead-stripped: OS_SetCurrentHeap (48B) */
/* not in shard or dead-stripped: OS_ClearAlloc (20B) */
/* not in shard or dead-stripped: OS_DestroyHeap (72B) */
/* not in shard or dead-stripped: OS_AddToHeap (112B) */
/* not in shard or dead-stripped: OS_CheckHeap (388B) */
/* not in shard or dead-stripped: OS_DumpHeap (4B) */
/* not in shard or dead-stripped: OS_VisitAllocated (144B) */
/* not in shard or dead-stripped: OSi_GetTotalAllocSize (144B) */
/* not in shard or dead-stripped: OS_GetTotalFreeSize (100B) */
/* not in shard or dead-stripped: OS_GetMaxFreeSize (104B) */
/* not in shard or dead-stripped: OS_ClearHeap (116B) */
/* not in shard or dead-stripped: OS_IsOnMainMemory (28B) */
/* not in shard or dead-stripped: OS_IsOnExtendedMainMemory (28B) */
/* not in shard or dead-stripped: OS_IsOnWramB (8B) */
/* not in shard or dead-stripped: OS_IsOnWramC (8B) */
/* not in shard or dead-stripped: OS_IsOnWram0 (40B) */
/* not in shard or dead-stripped: OS_IsOnWram1 (36B) */
/* not in shard or dead-stripped: OS_IsOnWram (100B) */
/* not in shard or dead-stripped: OS_IsOnDtcm (44B) */
/* not in shard or dead-stripped: OS_IsOnItcm (36B) */
/* not in shard or dead-stripped: OS_IsOnWramA (8B) */
/* not in shard or dead-stripped: OS_IsOnArm7PrvWram (8B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_alloc.c"
