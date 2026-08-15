/* lib/NitroSDK/TwlSDK/build/libraries/snd/common/src/snd_bank.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define SNDi_LockMutex                       sub_02089880
#define SNDi_UnlockMutex                     sub_02089894
#define DC_StoreRange                        sub_020862D4

#define SND_AssignWaveArc       sub_0208A2BC
#define SND_DestroyBank         sub_0208A38C
#define SND_DestroyWaveArc      sub_0208A424
#define SND_GetFirstInstDataPos sub_0208A46C
#define SND_GetNextInstData     sub_0208A48C
#define SND_GetWaveDataCount    sub_0208A638
#define SND_SetWaveDataAddress  sub_0208A640
#define SND_GetWaveDataAddress  sub_0208A674
/* not in shard or dead-stripped: SND_ReadInstData (408B) */
/* not in shard or dead-stripped: SND_WriteInstData (472B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/snd/common/src/snd_bank.c"
