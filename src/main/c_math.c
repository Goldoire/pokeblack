/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/math/common/src/math.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

#define MATH_CountLeadingZerosFunc sub_02087EA0
/* stripped or unplaced: MATH_CountPopulation (68B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/math/common/src/math.c"
