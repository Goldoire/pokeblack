/* lib/TwlSystem/build/libraries/fnd/src/allocator.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define NNS_FndAllocFromFrmHeapEx            sub_02061124
#define NNS_FndAllocFromUnitHeap             sub_02061244
#define OS_AllocFromHeap                     sub_020868E0
#define OS_FreeToHeap                        sub_020869E8

#define AllocatorAllocForUnitHeap       sub_020612C8
#define NNS_FndAllocFromAllocator       sub_02061330
#define NNS_FndFreeToAllocator          sub_02061344
/* not in shard or dead-stripped: AllocatorAllocForExpHeap (20B) */
/* not in shard or dead-stripped: AllocatorFreeForExpHeap (16B) */
/* not in shard or dead-stripped: AllocatorAllocForFrmHeap (20B) */
/* not in shard or dead-stripped: AllocatorFreeForFrmHeap (4B) */
/* not in shard or dead-stripped: AllocatorFreeForUnitHeap (16B) */
/* not in shard or dead-stripped: AllocatorAllocForSDKHeap (28B) */
/* not in shard or dead-stripped: AllocatorFreeForSDKHeap (28B) */
/* not in shard or dead-stripped: NNS_FndInitAllocatorForExpHeap (28B) */
/* not in shard or dead-stripped: NNS_FndInitAllocatorForFrmHeap (28B) */
/* not in shard or dead-stripped: NNS_FndInitAllocatorForUnitHeap (28B) */
/* not in shard or dead-stripped: NNS_FndInitAllocatorForSDKHeap (32B) */

#include "../../lib/TwlSystem/build/libraries/fnd/src/allocator.c"
