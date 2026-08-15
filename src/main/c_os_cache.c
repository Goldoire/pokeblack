/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/os/ARM9/src/os_cache.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define OS_DisableInterrupts                 sub_02087988
#define OS_RestoreInterrupts                 sub_0208799C
#define DC_FlushAll             sub_02086284
#define DC_InvalidateRange      sub_020862B8
#define DC_StoreRange           sub_020862D4
#define DC_FlushRange           sub_020862F0
#define DC_WaitWriteBufferEmpty sub_02086314
#define IC_InvalidateAll        sub_02086320
#define IC_InvalidateRange      sub_0208632C
/* stripped or unplaced: DC_Enable (24B) */
/* stripped or unplaced: DC_Disable (24B) */
/* stripped or unplaced: DC_Restore (40B) */
/* stripped or unplaced: DC_InvalidateAll (12B) */
/* stripped or unplaced: DC_StoreAll (44B) */
/* stripped or unplaced: DC_TouchRange (28B) */
/* stripped or unplaced: DC_LockdownRange (120B) */
/* stripped or unplaced: DC_UnlockdownAll (12B) */
/* stripped or unplaced: DC_Unlockdown (24B) */
/* stripped or unplaced: IC_Enable (24B) */
/* stripped or unplaced: IC_Disable (24B) */
/* stripped or unplaced: IC_Restore (40B) */
/* stripped or unplaced: IC_PrefetchRange (28B) */
/* stripped or unplaced: IC_LockdownRange (120B) */
/* stripped or unplaced: IC_UnlockdownAll (12B) */
/* stripped or unplaced: IC_Unlockdown (24B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/ARM9/src/os_cache.c"
