/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/mi/common/src/mi_dma_card.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define MIi_CheckAnotherAutoDMA              sub_02082688
#define MIi_CheckDma0SourceAddress           sub_02082714
#define MIi_DmaSetParameters                 sub_020A9EA0
#define MIi_CardDmaCopy32 sub_020835A0

#include "../../lib/NitroSDK/TwlSDK/build/libraries/mi/common/src/mi_dma_card.c"
