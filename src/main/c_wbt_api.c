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

/* WBT_SetPacketSize byte-matches here too, but the ROM copy belongs to the
   other translation unit; leave this one unplaced. */
#define WBT_SetPacketSize unplaced_WBT_SetPacketSize
/* WBT_MpChildSendHook byte-matches here too, but the ROM copy belongs to the
   other translation unit; leave this one unplaced. */
#define WBT_MpChildSendHook unplaced_WBT_MpChildSendHook
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
