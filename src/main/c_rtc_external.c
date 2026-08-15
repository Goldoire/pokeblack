/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/rtc/ARM9/src/external.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
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
/* stripped or unplaced: RTC_SetDateAsync (132B) */
/* stripped or unplaced: RTC_SetDate (56B) */
/* stripped or unplaced: RTC_SetTimeAsync (132B) */
/* stripped or unplaced: RTC_SetTime (56B) */
/* stripped or unplaced: RTC_SetDateTimeAsync (164B) */
/* stripped or unplaced: RTCi_SetRegStatus2Async (204B) */
/* stripped or unplaced: RTCi_SetRegStatus2 (56B) */
/* stripped or unplaced: RTCi_SetRegAdjustAsync (148B) */
/* stripped or unplaced: RTCi_SetRegAdjust (56B) */
/* stripped or unplaced: RTC_GetAlarmStatusAsync (160B) */
/* stripped or unplaced: RTC_GetAlarmStatus (56B) */
/* stripped or unplaced: RTC_GetAlarmParamAsync (164B) */
/* stripped or unplaced: RTC_GetAlarmParam (56B) */
/* stripped or unplaced: RTC_SetAlarmInterrupt (16B) */
/* stripped or unplaced: RTC_SetAlarmStatusAsync (176B) */
/* stripped or unplaced: RTC_SetAlarmStatus (56B) */
/* stripped or unplaced: RTC_SetAlarmParamAsync (216B) */
/* stripped or unplaced: RTC_SetAlarmParam (56B) */
/* stripped or unplaced: RtcCommonCallback (1088B) */
/* stripped or unplaced: RtcHEX2BCD (100B) */
/* stripped or unplaced: RtcCheckAlarmParam (68B) */
/* stripped or unplaced: RtcMakeAlarmParam (140B) */
/* stripped or unplaced: RtcCheckDate (200B) */
/* stripped or unplaced: RtcCheckTime (172B) */
/* stripped or unplaced: RtcWaitBusy (24B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/rtc/ARM9/src/external.c"
