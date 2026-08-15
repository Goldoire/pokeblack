/* lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_valarm.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define OS_DisableIrqMask                    sub_02084998
#define OS_DisableInterrupts                 sub_02087988
#define OS_RestoreInterrupts                 sub_0208799C
#define OS_Terminate                         sub_02088234
#define OS_SetIrqFunction                    sub_02084774
#define GX_SetVCountEqVal                    sub_0207D384
#define OS_EnableIrqMask                     sub_02084968
#define OS_ResetRequestIrqMask               sub_020849C8

#define OS_InitVAlarm        sub_02087578
#define OSi_InsertVAlarm     sub_020875B8
#define OSi_AppendVAlarm     sub_02087634
#define OSi_DetachVAlarm     sub_0208766C
#define OS_CreateVAlarm      sub_020876A4
#define OS_SetVAlarm         sub_020876B8
#define OSi_SetNextVAlarm    sub_02087744
#define OSi_CompareVCount    sub_020878EC
#define OSi_GetVFrame        sub_02087938
/* not in shard or dead-stripped: OS_EndVAlarm (40B) */
/* not in shard or dead-stripped: OS_IsVAlarmAvailable (16B) */
/* not in shard or dead-stripped: OS_SetPeriodicVAlarm (140B) */
/* not in shard or dead-stripped: OS_SetVAlarmTag (32B) */
/* not in shard or dead-stripped: OS_CancelVAlarm (72B) */
/* not in shard or dead-stripped: OS_CancelAllVAlarms (88B) */
/* not in shard or dead-stripped: OS_CancelVAlarms (116B) */
/* not in shard or dead-stripped: OSi_VAlarmHandler (352B) */
/* not in shard or dead-stripped: OS_DumpVAlarm (48B) */
/* not in shard or dead-stripped: OS_GetNumberOfVAlarm (60B) */
/* not in shard or dead-stripped: OS_GetVAlarmResource (24B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_valarm.c"
