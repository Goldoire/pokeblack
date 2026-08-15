/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_exception.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define OS_EnableProtectionUnit              sub_02086CF4
#define OS_DisableProtectionUnit             sub_02086D04
#define OSi_ExceptionHandler                    sub_02086E40
#define OSi_GetAndDisplayContext                sub_02086EB4
#define OSi_SetExContext                        sub_02086EC8
/* stripped or unplaced: OS_SetExceptionVectorUpper (16B) */
/* stripped or unplaced: OS_SetExceptionVectorLower (16B) */
/* stripped or unplaced: OS_InitException (104B) */
/* stripped or unplaced: OSi_GetOriginalExceptionHandler (16B) */
/* stripped or unplaced: OSi_DebuggerExceptionHook (252B) */
/* stripped or unplaced: OS_EnableUserExceptionHandlerOnDebugger (40B) */
/* stripped or unplaced: OS_SetUserExceptionHandler (20B) */
/* stripped or unplaced: OSi_DisplayExContext (124B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_exception.c"
