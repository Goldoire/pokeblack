/* lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/g2.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

#define G2x_SetBGyAffine_          sub_0207D59C
#define G2x_SetBlendAlpha_         sub_0207D63C
#define G2x_SetBlendBrightness_    sub_0207D658
#define G2x_SetBlendBrightnessExt_ sub_0207D67C
#define G2x_ChangeBlendBrightness_ sub_0207D6C0

#include "../../lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/g2.c"
