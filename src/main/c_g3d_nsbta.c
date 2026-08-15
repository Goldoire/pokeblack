/* TwlSDK/TwlSystem lib/TwlSystem/build/libraries/g3d/src/anm/nsbta.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define MIi_CpuClear16                       sub_02082A48
#define GetTexSRTAnmSinCosVal_  sub_02070624
/* stripped or unplaced: GetTexSRTAnmVectorVal_ (244B) */
/* stripped or unplaced: GetTexSRTAnm_ (252B) */
/* stripped or unplaced: NNSi_G3dAnmObjInitNsBta (204B) */
/* stripped or unplaced: NNSi_G3dAnmCalcNsBta (96B) */

#include "../../lib/TwlSystem/build/libraries/g3d/src/anm/nsbta.c"
