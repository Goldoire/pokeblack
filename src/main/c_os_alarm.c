/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_alarm.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define OS_GetTick                           sub_020870D0
#define OSi_EnterTimerCallback               sub_02084900
#define OS_EnableIrqMask                     sub_02084970
#define OSi_SetTimerReserved                 sub_02086FCC
#define OS_DisableIrqMask                    sub_020849A0
#define OS_DisableInterrupts                 sub_02087988
#define OS_RestoreInterrupts                 sub_0208799C
#define _ll_udiv                             sub_0209C014
#define OS_Terminate                         sub_0208823C
#define OSi_SetTimer        sub_02087180
#define OS_InitAlarm        sub_02087208
#define OS_IsAlarmAvailable sub_02087244
#define OS_CreateAlarm      sub_02087254
#define OSi_InsertAlarm     sub_02087264
#define OS_SetAlarm         sub_0208738C
#define OS_CancelAlarm      sub_020873F8
#define OSi_AlarmHandler    sub_0208747C
#define OSi_ArrangeTimer    sub_0208748C
/* stripped or unplaced: OS_EndAlarm (60B) */
/* stripped or unplaced: OS_SetPeriodicAlarm (112B) */
/* stripped or unplaced: OS_SetAlarmTag (8B) */
/* stripped or unplaced: OS_CancelAlarms (108B) */
/* stripped or unplaced: OS_CancelAllAlarms (88B) */
/* stripped or unplaced: OSi_GetAlarmQueue (12B) */
/* stripped or unplaced: OS_GetNumberOfAlarm (60B) */
/* stripped or unplaced: OS_GetAlarmResource (24B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_alarm.c"
