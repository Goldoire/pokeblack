/* TwlSDK/TwlSystem lib/TwlSystem/build/libraries/g3d/src/binres/res_struct_accessor.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

#define NNS_G3dGetMdlSet               sub_0206E954
#define NNS_G3dGetTex                  sub_0206E964
/* stripped or unplaced: NNS_G3dGetResDataByName (444B) */
/* stripped or unplaced: NNS_G3dGetResDictIdxByName (356B) */
/* stripped or unplaced: NNS_G3dGetDataBlockHeaderByIdx (32B) */

#include "../../lib/TwlSystem/build/libraries/g3d/src/binres/res_struct_accessor.c"
