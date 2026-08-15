/* lib/NitroSDK/TwlSDK/build/libraries/wbt/common/src/wbt_api.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define OS_DisableInterrupts                 sub_02087988
#define MI_CpuFill8                          sub_02082BCC
#define OS_RestoreInterrupts                 sub_0208799C
#define MI_CpuCopy8                          sub_02082D44

#define WBT_SetPacketSize              sub_0207ACB4
#define WBT_MpChildSendHook            sub_0208C848
/* not in shard or dead-stripped: WBT_PrintBTList (36B) */
/* not in shard or dead-stripped: WBT_AidbitmapToAid (36B) */
/* not in shard or dead-stripped: WBT_InitParent (184B) */
/* not in shard or dead-stripped: WBT_InitChild (140B) */
/* not in shard or dead-stripped: WBT_End (68B) */
/* not in shard or dead-stripped: WBT_SetOwnAid (40B) */
/* not in shard or dead-stripped: WBT_GetOwnAid (16B) */
/* not in shard or dead-stripped: WBT_CalcPacketbitmapSize (24B) */
/* not in shard or dead-stripped: WBT_GetCurrentDownloadProgress (68B) */
/* not in shard or dead-stripped: WBT_NumOfRegisteredBlock (20B) */
/* not in shard or dead-stripped: WBT_MpParentSendHook (36B) */
/* not in shard or dead-stripped: WBT_MpParentRecvHook (36B) */
/* not in shard or dead-stripped: WBT_MpChildRecvHook (32B) */
/* not in shard or dead-stripped: WBT_RegisterBlock (100B) */
/* not in shard or dead-stripped: WBT_UnregisterBlock (24B) */
/* not in shard or dead-stripped: WBT_RequestSync (92B) */
/* not in shard or dead-stripped: WBT_GetBlockInfo (156B) */
/* not in shard or dead-stripped: WBT_GetBlock (188B) */
/* not in shard or dead-stripped: WBT_PutUserData (112B) */
/* not in shard or dead-stripped: WBT_CancelCurrentCommand (36B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/wbt/common/src/wbt_api.c"
