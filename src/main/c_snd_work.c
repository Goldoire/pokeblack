/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/snd/common/src/snd_work.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define DC_InvalidateRange                   sub_020862B8
#define DC_FlushRange                        sub_020862F0
#define SND_GetPlayerStatus         sub_0208A054
#define SND_GetChannelStatus        sub_0208A07C
#define SND_ReadTrackInfo           sub_0208A0A4
#define SNDi_GetFinishedCommandTag  sub_0208A1AC
#define SNDi_InitSharedWork         sub_0208A1D0
/* stripped or unplaced: SND_GetCaptureStatus (40B) */
/* stripped or unplaced: SND_GetPlayerTickCounter (56B) */
/* stripped or unplaced: SND_GetPlayerLocalVariable (68B) */
/* stripped or unplaced: SND_GetPlayerGlobalVariable (56B) */
/* stripped or unplaced: SND_ReadChannelInfo (364B) */
/* stripped or unplaced: SND_ReadPlayerInfo (164B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/snd/common/src/snd_work.c"
