/* lib/NitroSDK/TwlSDK/build/libraries/snd/common/src/snd_alarm.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

#define SND_AlarmInit         sub_02089F88
#define SNDi_IncAlarmId       sub_02089FC0
#define SNDi_SetAlarmHandler  sub_02089FE0
#define SNDi_CallAlarmHandler sub_0208A010

#include "../../lib/NitroSDK/TwlSDK/build/libraries/snd/common/src/snd_alarm.c"
