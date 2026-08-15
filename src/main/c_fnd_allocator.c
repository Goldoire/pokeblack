/* TwlSDK/TwlSystem lib/TwlSystem/build/libraries/fnd/src/allocator.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define NNS_FndAllocFromFrmHeapEx            sub_0206112C
#define NNS_FndAllocFromUnitHeap             sub_02061244
#define OS_AllocFromHeap                     sub_020868E0
#define OS_FreeToHeap                        sub_020869E8
#define AllocatorAllocForUnitHeap       sub_020612C8
#define NNS_FndAllocFromAllocator       sub_02061330
#define NNS_FndFreeToAllocator          sub_02061344
/* stripped or unplaced: AllocatorAllocForExpHeap (20B) */
/* stripped or unplaced: AllocatorFreeForExpHeap (16B) */
/* stripped or unplaced: AllocatorAllocForFrmHeap (20B) */
/* stripped or unplaced: AllocatorFreeForFrmHeap (4B) */
/* stripped or unplaced: AllocatorFreeForUnitHeap (16B) */
/* stripped or unplaced: AllocatorAllocForSDKHeap (28B) */
/* stripped or unplaced: AllocatorFreeForSDKHeap (28B) */
/* stripped or unplaced: NNS_FndInitAllocatorForExpHeap (28B) */
/* stripped or unplaced: NNS_FndInitAllocatorForFrmHeap (28B) */
/* stripped or unplaced: NNS_FndInitAllocatorForUnitHeap (28B) */
/* stripped or unplaced: NNS_FndInitAllocatorForSDKHeap (32B) */

#include "../../lib/TwlSystem/build/libraries/fnd/src/allocator.c"
