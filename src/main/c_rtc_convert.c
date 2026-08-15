/* lib/NitroSDK/TwlSDK/build/libraries/rtc/ARM9/src/convert.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
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
