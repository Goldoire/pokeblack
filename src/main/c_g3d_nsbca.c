/* TwlSDK/TwlSystem lib/TwlSystem/build/libraries/g3d/src/anm/nsbca.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define MIi_CpuClear16                       sub_02082A48
#define MI_Zero36B                           sub_020834A8
#define VEC_Normalize                        sub_0207CCA4
#define NNSi_G3dAnmCalcNsBca    sub_0206EB7C
#define getMdlScale_            sub_0206EC50
#define getMdlRot_              sub_0206ECE0
/* stripped or unplaced: NNSi_G3dAnmObjInitNsBca (124B) */
/* stripped or unplaced: getMdlTrans_ (148B) */
/* stripped or unplaced: getJntSRTAnmResult_ (852B) */
/* stripped or unplaced: getTransData_ (336B) */
/* stripped or unplaced: getTransDataEx_ (340B) */
/* stripped or unplaced: getScaleData_ (468B) */
/* stripped or unplaced: getScaleDataEx_ (384B) */
/* stripped or unplaced: getRotData_ (1028B) */
/* stripped or unplaced: getRotDataEx_ (824B) */
/* stripped or unplaced: getRotDataByIdx_ (360B) */

#include "../../lib/TwlSystem/build/libraries/g3d/src/anm/nsbca.c"
