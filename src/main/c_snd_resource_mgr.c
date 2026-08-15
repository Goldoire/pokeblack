/* lib/TwlSystem/build/libraries/snd/src/resource_mgr.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define SND_LockChannel                      sub_020895D8
#define SND_UnlockChannel                    sub_020895F8

#define NNS_SndUnlockChannel    sub_02072974
#define NNS_SndUnlockCapture    sub_020729A4
#define NNS_SndFreeAlarm        sub_02072A08
#define NNSi_SndInitResourceMgr sub_02072A28
/* not in shard or dead-stripped: NNS_SndLockChannel (68B) */
/* not in shard or dead-stripped: NNS_SndLockCapture (36B) */
/* not in shard or dead-stripped: NNS_SndAllocAlarm (68B) */
/* not in shard or dead-stripped: NNSi_GetLockedChannel (16B) */

#include "../../lib/TwlSystem/build/libraries/snd/src/resource_mgr.c"
