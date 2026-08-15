/* lib/NitroSDK/TwlSDK/build/libraries/snd/common/src/snd_work.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define DC_InvalidateRange                   sub_020862B8
#define DC_FlushRange                        sub_020862F0

#define SND_GetPlayerStatus         sub_0208A054
#define SND_GetChannelStatus        sub_0208A07C
#define SND_ReadTrackInfo           sub_0208A0A4
#define SNDi_GetFinishedCommandTag  sub_0208A1AC
#define SNDi_InitSharedWork         sub_0208A1D0
/* not in shard or dead-stripped: SND_GetCaptureStatus (40B) */
/* not in shard or dead-stripped: SND_GetPlayerTickCounter (56B) */
/* not in shard or dead-stripped: SND_GetPlayerLocalVariable (68B) */
/* not in shard or dead-stripped: SND_GetPlayerGlobalVariable (56B) */
/* not in shard or dead-stripped: SND_ReadChannelInfo (364B) */
/* not in shard or dead-stripped: SND_ReadPlayerInfo (164B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/snd/common/src/snd_work.c"
