/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/snd/common/src/snd_bank.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define SNDi_LockMutex                       sub_02089888
#define SNDi_UnlockMutex                     sub_0208989C
#define DC_StoreRange                        sub_020862D4
#define SND_AssignWaveArc       sub_0208A2BC
#define SND_DestroyBank         sub_0208A38C
#define SND_DestroyWaveArc      sub_0208A424
#define SND_GetFirstInstDataPos sub_0208A46C
#define SND_GetNextInstData     sub_0208A48C
#define SND_GetWaveDataCount    sub_0208A638
#define SND_SetWaveDataAddress  sub_0208A640
#define SND_GetWaveDataAddress  sub_0208A674
/* stripped or unplaced: SND_ReadInstData (408B) */
/* stripped or unplaced: SND_WriteInstData (472B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/snd/common/src/snd_bank.c"
