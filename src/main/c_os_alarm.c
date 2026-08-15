/* lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_alarm.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define OS_GetTick                           sub_020870D0
#define OSi_EnterTimerCallback               sub_020848F8
#define OS_EnableIrqMask                     sub_02084968
#define OSi_SetTimerReserved                 sub_02086FC4
#define OS_DisableIrqMask                    sub_02084998
#define OS_DisableInterrupts                 sub_02087988
#define OS_RestoreInterrupts                 sub_0208799C
#define _ll_udiv                             sub_0209C00C
#define OS_Terminate                         sub_02088234

#define OSi_SetTimer        sub_02087180
#define OS_InitAlarm        sub_02087208
#define OS_IsAlarmAvailable sub_02087244
#define OS_CreateAlarm      sub_02087254
#define OSi_InsertAlarm     sub_02087264
#define OS_SetAlarm         sub_0208738C
#define OS_CancelAlarm      sub_020873F8
#define OSi_AlarmHandler    sub_0208747C
#define OSi_ArrangeTimer    sub_0208748C
/* not in shard or dead-stripped: OS_EndAlarm (60B) */
/* not in shard or dead-stripped: OS_SetPeriodicAlarm (112B) */
/* not in shard or dead-stripped: OS_SetAlarmTag (8B) */
/* not in shard or dead-stripped: OS_CancelAlarms (108B) */
/* not in shard or dead-stripped: OS_CancelAllAlarms (88B) */
/* not in shard or dead-stripped: OSi_GetAlarmQueue (12B) */
/* not in shard or dead-stripped: OS_GetNumberOfAlarm (60B) */
/* not in shard or dead-stripped: OS_GetAlarmResource (24B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_alarm.c"
