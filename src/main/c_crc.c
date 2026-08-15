/* lib/NitroSDK/TwlSDK/build/libraries/math/common/src/crc.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

#define MATHi_CRC8InitTable     sub_02081940
#define MATHi_CRC8Update        sub_02081980
#define MATHi_CRC16InitTable    sub_020819B8
#define MATHi_CRC16InitTableRev sub_020819FC
#define MATHi_CRC16Update       sub_02081A40
#define MATHi_CRC16UpdateRev    sub_02081A80
#define MATHi_CRC32InitTableRev sub_02081AC0
#define MATHi_CRC32UpdateRev    sub_02081B00
#define MATH_CalcCRC8           sub_02081B3C
#define MATH_CalcCRC16          sub_02081B64
#define MATH_CalcCRC16CCITT     sub_02081B8C
#define MATH_CalcCRC32          sub_02081BB8
/* not in shard or dead-stripped: MATHi_CRC8InitTableRev (64B) */
/* not in shard or dead-stripped: MATHi_CRC32InitTable (64B) */
/* not in shard or dead-stripped: MATHi_CRC32Update (60B) */
/* not in shard or dead-stripped: MATH_CalcCRC32POSIX (44B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/math/common/src/crc.c"
