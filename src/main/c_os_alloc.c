/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_alloc.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
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
/* stripped or unplaced: DLOverlap (76B) */
/* stripped or unplaced: OS_AllocFixed (572B) */
/* stripped or unplaced: OS_FreeAllToHeap (120B) */
/* stripped or unplaced: OS_SetCurrentHeap (48B) */
/* stripped or unplaced: OS_ClearAlloc (20B) */
/* stripped or unplaced: OS_DestroyHeap (72B) */
/* stripped or unplaced: OS_AddToHeap (112B) */
/* stripped or unplaced: OS_CheckHeap (388B) */
/* stripped or unplaced: OS_DumpHeap (4B) */
/* stripped or unplaced: OS_VisitAllocated (144B) */
/* stripped or unplaced: OSi_GetTotalAllocSize (144B) */
/* stripped or unplaced: OS_GetTotalFreeSize (100B) */
/* stripped or unplaced: OS_GetMaxFreeSize (104B) */
/* stripped or unplaced: OS_ClearHeap (116B) */
/* stripped or unplaced: OS_IsOnMainMemory (28B) */
/* stripped or unplaced: OS_IsOnExtendedMainMemory (28B) */
/* stripped or unplaced: OS_IsOnWramB (8B) */
/* stripped or unplaced: OS_IsOnWramC (8B) */
/* stripped or unplaced: OS_IsOnWram0 (40B) */
/* stripped or unplaced: OS_IsOnWram1 (36B) */
/* stripped or unplaced: OS_IsOnWram (100B) */
/* stripped or unplaced: OS_IsOnDtcm (44B) */
/* stripped or unplaced: OS_IsOnItcm (36B) */
/* stripped or unplaced: OS_IsOnWramA (8B) */
/* stripped or unplaced: OS_IsOnArm7PrvWram (8B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_alloc.c"
