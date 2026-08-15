/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/snd/common/src/snd_alarm.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

#define SND_AlarmInit         sub_02089F88
#define SNDi_IncAlarmId       sub_02089FC0
#define SNDi_SetAlarmHandler  sub_02089FE0
#define SNDi_CallAlarmHandler sub_0208A010

#include "../../lib/NitroSDK/TwlSDK/build/libraries/snd/common/src/snd_alarm.c"
