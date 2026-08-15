/* lib/NitroSDK/TwlSDK/build/libraries/card/common/src/card_utility.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define MI_StopDma                           sub_020825F0
#define MIi_CardDmaCopy32                    sub_020835A0
#define OS_Terminate                         sub_02088234
#define IC_InvalidateAll                     sub_02086320
#define IC_InvalidateRange                   sub_0208632C
#define DC_FlushAll                          sub_02086284
#define DC_StoreRange                        sub_020862D4
#define DC_InvalidateRange                   sub_020862B8
#define DC_WaitWriteBufferEmpty              sub_02086314

#define CARDi_ICInvalidateSmart sub_02076344
#define CARDi_DCInvalidateSmart sub_02076360
/* not in shard or dead-stripped: CARDi_GetDmaInterface (60B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/card/common/src/card_utility.c"
