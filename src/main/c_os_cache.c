/* lib/NitroSDK/TwlSDK/build/libraries/os/ARM9/src/os_cache.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define OS_DisableInterrupts                 sub_02087988
#define OS_RestoreInterrupts                 sub_0208799C

#define DC_FlushAll             sub_02086284
#define DC_InvalidateRange      sub_020862B8
#define DC_StoreRange           sub_020862D4
#define DC_FlushRange           sub_020862F0
#define DC_WaitWriteBufferEmpty sub_02086314
#define IC_InvalidateAll        sub_02086320
#define IC_InvalidateRange      sub_0208632C
/* not in shard or dead-stripped: DC_Enable (24B) */
/* not in shard or dead-stripped: DC_Disable (24B) */
/* not in shard or dead-stripped: DC_Restore (40B) */
/* not in shard or dead-stripped: DC_InvalidateAll (12B) */
/* not in shard or dead-stripped: DC_StoreAll (44B) */
/* not in shard or dead-stripped: DC_TouchRange (28B) */
/* not in shard or dead-stripped: DC_LockdownRange (120B) */
/* not in shard or dead-stripped: DC_UnlockdownAll (12B) */
/* not in shard or dead-stripped: DC_Unlockdown (24B) */
/* not in shard or dead-stripped: IC_Enable (24B) */
/* not in shard or dead-stripped: IC_Disable (24B) */
/* not in shard or dead-stripped: IC_Restore (40B) */
/* not in shard or dead-stripped: IC_PrefetchRange (28B) */
/* not in shard or dead-stripped: IC_LockdownRange (120B) */
/* not in shard or dead-stripped: IC_UnlockdownAll (12B) */
/* not in shard or dead-stripped: IC_Unlockdown (24B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/ARM9/src/os_cache.c"
