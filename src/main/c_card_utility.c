/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/card/common/src/card_utility.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define MI_StopDma                           sub_020825F0
#define MIi_CardDmaCopy32                    sub_020835A0
#define IC_InvalidateAll                     sub_02086320
#define IC_InvalidateRange                   sub_0208632C
#define DC_FlushAll                          sub_02086284
#define DC_StoreRange                        sub_020862D4
#define DC_InvalidateRange                   sub_020862B8
#define DC_WaitWriteBufferEmpty              sub_02086314
#define CARDi_ICInvalidateSmart sub_02076344
#define CARDi_DCInvalidateSmart sub_02076360
/* stripped or unplaced: CARDi_GetDmaInterface (60B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/card/common/src/card_utility.c"
