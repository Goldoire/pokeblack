/* lib/NitroSDK/TwlSDK/build/libraries/os/ARM9/src/os_terminate_proc.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define OS_DisableInterrupts                 sub_02087988

#define OS_Halt                  sub_020882D0
/* not in shard or dead-stripped: OS_Terminate (48B) */
/* not in shard or dead-stripped: OSi_TerminateCore (16B) */
/* not in shard or dead-stripped: OSi_SetTerminateCallback (16B) */
/* not in shard or dead-stripped: OS_Exit (20B) */
/* not in shard or dead-stripped: OS_FExit (16B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/ARM9/src/os_terminate_proc.c"
