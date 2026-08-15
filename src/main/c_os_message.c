/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_message.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define OS_DisableInterrupts                 sub_02087988
#define OS_RestoreInterrupts                 sub_0208799C
#define OS_SleepThread                       sub_020857B0
#define OS_WakeupThread                      sub_02085800
#define OS_InitMessageQueue sub_02085D94
#define OS_SendMessage      sub_02085DBC
#define OS_ReceiveMessage   sub_02085E50
#define OS_JamMessage       sub_02085EF0
#define OS_ReadMessage      sub_02085F8C

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_message.c"
