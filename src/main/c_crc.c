/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/math/common/src/crc.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
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
/* stripped or unplaced: MATHi_CRC8InitTableRev (64B) */
/* stripped or unplaced: MATHi_CRC32InitTable (64B) */
/* stripped or unplaced: MATHi_CRC32Update (60B) */
/* stripped or unplaced: MATH_CalcCRC32POSIX (44B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/math/common/src/crc.c"
