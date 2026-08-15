/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_valarm.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define OS_DisableInterrupts                 sub_02087988
#define OS_RestoreInterrupts                 sub_0208799C
#define GX_SetVCountEqVal                    sub_0207D384
#define OS_InitVAlarm        sub_02087578
#define OSi_InsertVAlarm     sub_020875B8
#define OSi_AppendVAlarm     sub_02087634
#define OSi_DetachVAlarm     sub_0208766C
#define OS_CreateVAlarm      sub_020876A4
#define OS_SetVAlarm         sub_020876B8
#define OSi_SetNextVAlarm    sub_02087744
#define OSi_CompareVCount    sub_020878EC
#define OSi_GetVFrame        sub_02087938
/* stripped or unplaced: OS_EndVAlarm (40B) */
/* stripped or unplaced: OS_IsVAlarmAvailable (16B) */
/* stripped or unplaced: OS_SetPeriodicVAlarm (140B) */
/* stripped or unplaced: OS_SetVAlarmTag (32B) */
/* stripped or unplaced: OS_CancelVAlarm (72B) */
/* stripped or unplaced: OS_CancelAllVAlarms (88B) */
/* stripped or unplaced: OS_CancelVAlarms (116B) */
/* stripped or unplaced: OSi_VAlarmHandler (352B) */
/* stripped or unplaced: OS_DumpVAlarm (48B) */
/* stripped or unplaced: OS_GetNumberOfVAlarm (60B) */
/* stripped or unplaced: OS_GetVAlarmResource (24B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_valarm.c"
