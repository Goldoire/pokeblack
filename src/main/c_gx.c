/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/gx.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define GX_InitGXState                       sub_02080CC4
#define MIi_DmaFill32                        sub_020821C0
#define MI_WaitDma                           sub_02082594
#define OS_DisableInterrupts                 sub_02087988
#define OS_RestoreInterrupts                 sub_0208799C
#define GX_SetVCountEqVal        sub_0207D384
#define GX_DispOff               sub_0207D42C
#define GX_DispOn                sub_0207D46C
#define GX_SetGraphicsMode       sub_0207D4B0
#define GXS_SetGraphicsMode      sub_0207D518
#define GXx_SetMasterBrightness_ sub_0207D534
#define GXx_GetMasterBrightness_ sub_0207D55C
/* stripped or unplaced: GX_Init (328B) */
/* stripped or unplaced: GX_HBlankIntr (48B) */
/* stripped or unplaced: GX_VBlankIntr (48B) */
/* stripped or unplaced: GX_IsDispOn (16B) */
/* stripped or unplaced: GX_SetDefaultDMA (68B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/gx.c"
