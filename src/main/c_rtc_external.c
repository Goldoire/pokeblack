/* lib/NitroSDK/TwlSDK/build/libraries/rtc/ARM9/src/external.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define PXI_IsCallbackReady                  sub_020885EC
#define PXI_SetFifoRecvCallback              sub_020885A0
#define OS_DisableInterrupts                 sub_02087988
#define OS_RestoreInterrupts                 sub_0208799C
#define RTCi_ReadRawDateAsync                sub_02088EFC
#define RTCi_ReadRawTimeAsync                sub_02088F0C
#define RTCi_ReadRawDateTimeAsync            sub_02088EEC
#define RTCi_WriteRawStatus2Async            sub_02088F1C
#define RTC_GetDayOfWeek                     sub_02089274

#define RTC_Init                sub_02088788
#define RTC_GetDateAsync        sub_020887F4
#define RTC_GetDate             sub_02088864
#define RTC_GetTimeAsync        sub_0208889C
#define RTC_GetTime             sub_0208890C
#define RTC_GetDateTimeAsync    sub_02088944
#define RTC_GetDateTime         sub_020889C0
#define RTC_SetDateTime         sub_02088C14
#define RtcBCD2HEX              sub_02088E5C
#define RtcGetResultCallback    sub_02088EC4
/* not in shard or dead-stripped: RTC_SetDateAsync (132B) */
/* not in shard or dead-stripped: RTC_SetDate (56B) */
/* not in shard or dead-stripped: RTC_SetTimeAsync (132B) */
/* not in shard or dead-stripped: RTC_SetTime (56B) */
/* not in shard or dead-stripped: RTC_SetDateTimeAsync (164B) */
/* not in shard or dead-stripped: RTCi_SetRegStatus2Async (204B) */
/* not in shard or dead-stripped: RTCi_SetRegStatus2 (56B) */
/* not in shard or dead-stripped: RTCi_SetRegAdjustAsync (148B) */
/* not in shard or dead-stripped: RTCi_SetRegAdjust (56B) */
/* not in shard or dead-stripped: RTC_GetAlarmStatusAsync (160B) */
/* not in shard or dead-stripped: RTC_GetAlarmStatus (56B) */
/* not in shard or dead-stripped: RTC_GetAlarmParamAsync (164B) */
/* not in shard or dead-stripped: RTC_GetAlarmParam (56B) */
/* not in shard or dead-stripped: RTC_SetAlarmInterrupt (16B) */
/* not in shard or dead-stripped: RTC_SetAlarmStatusAsync (176B) */
/* not in shard or dead-stripped: RTC_SetAlarmStatus (56B) */
/* not in shard or dead-stripped: RTC_SetAlarmParamAsync (216B) */
/* not in shard or dead-stripped: RTC_SetAlarmParam (56B) */
/* not in shard or dead-stripped: RtcCommonCallback (1088B) */
/* not in shard or dead-stripped: RtcHEX2BCD (100B) */
/* not in shard or dead-stripped: RtcCheckAlarmParam (68B) */
/* not in shard or dead-stripped: RtcMakeAlarmParam (140B) */
/* not in shard or dead-stripped: RtcCheckDate (200B) */
/* not in shard or dead-stripped: RtcCheckTime (172B) */
/* not in shard or dead-stripped: RtcWaitBusy (24B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/rtc/ARM9/src/external.c"
