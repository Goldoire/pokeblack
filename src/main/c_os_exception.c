/* lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_exception.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define OS_EnableProtectionUnit              sub_02086CF4
#define OS_DisableProtectionUnit             sub_02086D04

#define OSi_ExceptionHandler                    sub_02086E40
#define OSi_GetAndDisplayContext                sub_02086EB4
#define OSi_SetExContext                        sub_02086EC8
/* not in shard or dead-stripped: OS_SetExceptionVectorUpper (16B) */
/* not in shard or dead-stripped: OS_SetExceptionVectorLower (16B) */
/* not in shard or dead-stripped: OS_InitException (104B) */
/* not in shard or dead-stripped: OSi_GetOriginalExceptionHandler (16B) */
/* not in shard or dead-stripped: OSi_DebuggerExceptionHook (252B) */
/* not in shard or dead-stripped: OS_EnableUserExceptionHandlerOnDebugger (40B) */
/* not in shard or dead-stripped: OS_SetUserExceptionHandler (20B) */
/* not in shard or dead-stripped: OSi_DisplayExContext (124B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_exception.c"
