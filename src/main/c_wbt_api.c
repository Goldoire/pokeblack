/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/wbt/common/src/wbt_api.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define OS_DisableInterrupts                 sub_02087988
#define MI_CpuFill8                          sub_02082BCC
#define OS_RestoreInterrupts                 sub_0208799C
#define MI_CpuCopy8                          sub_02082D44
#define WBT_SetPacketSize              sub_0207ACB4
#define WBT_MpChildSendHook            sub_0208C848
/* stripped or unplaced: WBT_PrintBTList (36B) */
/* stripped or unplaced: WBT_AidbitmapToAid (36B) */
/* stripped or unplaced: WBT_InitParent (184B) */
/* stripped or unplaced: WBT_InitChild (140B) */
/* stripped or unplaced: WBT_End (68B) */
/* stripped or unplaced: WBT_SetOwnAid (40B) */
/* stripped or unplaced: WBT_GetOwnAid (16B) */
/* stripped or unplaced: WBT_CalcPacketbitmapSize (24B) */
/* stripped or unplaced: WBT_GetCurrentDownloadProgress (68B) */
/* stripped or unplaced: WBT_NumOfRegisteredBlock (20B) */
/* stripped or unplaced: WBT_MpParentSendHook (36B) */
/* stripped or unplaced: WBT_MpParentRecvHook (36B) */
/* stripped or unplaced: WBT_MpChildRecvHook (32B) */
/* stripped or unplaced: WBT_RegisterBlock (100B) */
/* stripped or unplaced: WBT_UnregisterBlock (24B) */
/* stripped or unplaced: WBT_RequestSync (92B) */
/* stripped or unplaced: WBT_GetBlockInfo (156B) */
/* stripped or unplaced: WBT_GetBlock (188B) */
/* stripped or unplaced: WBT_PutUserData (112B) */
/* stripped or unplaced: WBT_CancelCurrentCommand (36B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/wbt/common/src/wbt_api.c"
