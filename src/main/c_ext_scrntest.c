/* lib/NitroSDK/TwlSDK/build/libraries/ext/common/src/ext_scrntest.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

#define EXT_TestResetCounter         sub_02067CFC
/* not in shard or dead-stripped: EXT_Printf (12B) */
/* not in shard or dead-stripped: EXT_CompPrint (156B) */
/* not in shard or dead-stripped: EXT_TestScreenShot (140B) */
/* not in shard or dead-stripped: EXT_TestTickCounter (24B) */
/* not in shard or dead-stripped: EXT_TestSetVRAMForScreenShot (16B) */
/* not in shard or dead-stripped: startCapture_ (184B) */
/* not in shard or dead-stripped: getDispMode_ (20B) */
/* not in shard or dead-stripped: getCaptureMode_ (16B) */
/* not in shard or dead-stripped: getCaptureSrcB_ (28B) */
/* not in shard or dead-stripped: getCaptureDest_ (100B) */
/* not in shard or dead-stripped: calcScreenShotCheckSum_ (92B) */
/* not in shard or dead-stripped: getCapturedPixel_ (28B) */
/* not in shard or dead-stripped: getCapturedBufferBase_ (112B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/ext/common/src/ext_scrntest.c"
