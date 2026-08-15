/* TwlSDK/TwlSystem lib/TwlSystem/build/libraries/g3d/src/anm/nsbma.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define MIi_CpuClear16                       sub_02082A48
#define GetMatColAnmuAlphaValue_ sub_02070274
/* stripped or unplaced: GetMatColAnmValue_ (352B) */
/* stripped or unplaced: NNSi_G3dAnmObjInitNsBma (204B) */
/* stripped or unplaced: NNSi_G3dAnmCalcNsBma (268B) */

#include "../../lib/TwlSystem/build/libraries/g3d/src/anm/nsbma.c"
