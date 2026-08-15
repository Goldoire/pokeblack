/* lib/TwlSystem/build/libraries/g3d/src/binres/res_struct_accessor_anm.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

#define NNS_G3dGetAnmByIdx                sub_0206E9A4
#define NNSi_G3dGetTexPatAnmFV            sub_0206EA58
#define NNSi_G3dGetTexPatAnmDataByIdx     sub_0206EACC
/* not in shard or dead-stripped: NNSi_G3dIsValidAnmRes (100B) */
/* not in shard or dead-stripped: NNS_G3dGetAnmByName (56B) */
/* not in shard or dead-stripped: NNSi_G3dGetBinaryBlockFromFile (92B) */
/* not in shard or dead-stripped: NNS_G3dGetVisAnmByIdx (80B) */
/* not in shard or dead-stripped: NNS_G3dGetVisAnmSet (28B) */
/* not in shard or dead-stripped: NNSi_G3dGetTexPatAnmTexNameByIdx (40B) */
/* not in shard or dead-stripped: NNSi_G3dGetTexPatAnmPlttNameByIdx (40B) */
/* not in shard or dead-stripped: NNSi_G3dGetTexPatAnmFVByFVIndex (32B) */
/* not in shard or dead-stripped: NNS_G3dGetTexPatAnmByIdx (80B) */
/* not in shard or dead-stripped: NNS_G3dGetTexPatAnmSet (28B) */
/* not in shard or dead-stripped: NNS_G3dGetTexSRTAnmByIdx (80B) */
/* not in shard or dead-stripped: NNS_G3dGetTexSRTAnmSet (28B) */
/* not in shard or dead-stripped: NNS_G3dGetMatCAnmByIdx (80B) */
/* not in shard or dead-stripped: NNS_G3dGetMatCAnmSet (28B) */
/* not in shard or dead-stripped: NNS_G3dGetJntAnmSRTTag (16B) */
/* not in shard or dead-stripped: NNS_G3dGetJntAnmByIdx (80B) */
/* not in shard or dead-stripped: NNS_G3dGetJntAnmSet (28B) */

#include "../../lib/TwlSystem/build/libraries/g3d/src/binres/res_struct_accessor_anm.c"
