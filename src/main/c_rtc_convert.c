/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/rtc/ARM9/src/convert.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

#define RTC_ConvertDateToDay        sub_02088F58
#define RTCi_ConvertTimeToSecond    sub_02088FEC
#define RTC_ConvertDateTimeToSecond sub_02089004
#define RTC_ConvertDayToDate        sub_02089060
#define RTCi_ConvertSecondToTime    sub_02089160
#define RTC_ConvertSecondToDateTime sub_020891E0
#define RTC_GetDayOfWeek            sub_02089274

#include "../../lib/NitroSDK/TwlSDK/build/libraries/rtc/ARM9/src/convert.c"
