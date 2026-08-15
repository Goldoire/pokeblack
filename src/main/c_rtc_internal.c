/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/rtc/ARM9/src/internal.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define PXI_SendWordByFifo                   sub_02088610
#define RTCi_SetHourFormatAsync    sub_020846AC
#define RTCi_ReadRawDateTimeAsync  sub_02088EEC
#define RTCi_ReadRawDateAsync      sub_02088EFC
#define RTCi_ReadRawTimeAsync      sub_02088F0C
#define RTCi_WriteRawStatus2Async  sub_02088F1C
#define RtcSendPxiCommand          sub_02088F2C
/* stripped or unplaced: RTCi_ResetAsync (16B) */
/* stripped or unplaced: RTCi_WriteRawDateTimeAsync (16B) */
/* stripped or unplaced: RTCi_WriteRawDateAsync (16B) */
/* stripped or unplaced: RTCi_WriteRawTimeAsync (16B) */
/* stripped or unplaced: RTCi_ReadRawPulseAsync (16B) */
/* stripped or unplaced: RTCi_WriteRawPulseAsync (16B) */
/* stripped or unplaced: RTCi_ReadRawAlarm1Async (16B) */
/* stripped or unplaced: RTCi_WriteRawAlarm1Async (16B) */
/* stripped or unplaced: RTCi_ReadRawAlarm2Async (16B) */
/* stripped or unplaced: RTCi_WriteRawAlarm2Async (16B) */
/* stripped or unplaced: RTCi_ReadRawStatus1Async (16B) */
/* stripped or unplaced: RTCi_WriteRawStatus1Async (16B) */
/* stripped or unplaced: RTCi_ReadRawStatus2Async (16B) */
/* stripped or unplaced: RTCi_ReadRawAdjustAsync (16B) */
/* stripped or unplaced: RTCi_WriteRawAdjustAsync (16B) */
/* stripped or unplaced: RTCi_ReadRawFreeAsync (16B) */
/* stripped or unplaced: RTCi_WriteRawFreeAsync (16B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/rtc/ARM9/src/internal.c"
