/* lib/NitroSDK/TwlSDK/build/libraries/rtc/ARM9/src/internal.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define PXI_SendWordByFifo                   sub_02088610

#define RTCi_SetHourFormatAsync    sub_020846AC
#define RTCi_ReadRawDateTimeAsync  sub_02088EEC
#define RTCi_ReadRawDateAsync      sub_02088EFC
#define RTCi_ReadRawTimeAsync      sub_02088F0C
#define RTCi_WriteRawStatus2Async  sub_02088F1C
#define RtcSendPxiCommand          sub_02088F2C
/* not in shard or dead-stripped: RTCi_ResetAsync (16B) */
/* not in shard or dead-stripped: RTCi_WriteRawDateTimeAsync (16B) */
/* not in shard or dead-stripped: RTCi_WriteRawDateAsync (16B) */
/* not in shard or dead-stripped: RTCi_WriteRawTimeAsync (16B) */
/* not in shard or dead-stripped: RTCi_ReadRawPulseAsync (16B) */
/* not in shard or dead-stripped: RTCi_WriteRawPulseAsync (16B) */
/* not in shard or dead-stripped: RTCi_ReadRawAlarm1Async (16B) */
/* not in shard or dead-stripped: RTCi_WriteRawAlarm1Async (16B) */
/* not in shard or dead-stripped: RTCi_ReadRawAlarm2Async (16B) */
/* not in shard or dead-stripped: RTCi_WriteRawAlarm2Async (16B) */
/* not in shard or dead-stripped: RTCi_ReadRawStatus1Async (16B) */
/* not in shard or dead-stripped: RTCi_WriteRawStatus1Async (16B) */
/* not in shard or dead-stripped: RTCi_ReadRawStatus2Async (16B) */
/* not in shard or dead-stripped: RTCi_ReadRawAdjustAsync (16B) */
/* not in shard or dead-stripped: RTCi_WriteRawAdjustAsync (16B) */
/* not in shard or dead-stripped: RTCi_ReadRawFreeAsync (16B) */
/* not in shard or dead-stripped: RTCi_WriteRawFreeAsync (16B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/rtc/ARM9/src/internal.c"
