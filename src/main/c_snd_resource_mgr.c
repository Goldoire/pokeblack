/* TwlSDK/TwlSystem lib/TwlSystem/build/libraries/snd/src/resource_mgr.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define SND_LockChannel                      sub_020895D8
#define SND_UnlockChannel                    sub_020895F8
#define NNS_SndUnlockChannel    sub_02072974
#define NNS_SndUnlockCapture    sub_020729A4
#define NNS_SndFreeAlarm        sub_02072A08
#define NNSi_SndInitResourceMgr sub_02072A28
/* stripped or unplaced: NNS_SndLockChannel (68B) */
/* stripped or unplaced: NNS_SndLockCapture (36B) */
/* stripped or unplaced: NNS_SndAllocAlarm (68B) */
/* stripped or unplaced: NNSi_GetLockedChannel (16B) */

#include "../../lib/TwlSystem/build/libraries/snd/src/resource_mgr.c"
