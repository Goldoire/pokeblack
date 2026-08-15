/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/card/common/src/card_hook.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define OS_DisableInterrupts                 sub_02087988
#define OS_RestoreInterrupts                 sub_0208799C
#define CARDi_NotifyEvent    sub_02076100
/* stripped or unplaced: CARDi_RegisterHook (52B) */
/* stripped or unplaced: CARDi_UnregisterHook (80B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/card/common/src/card_hook.c"
