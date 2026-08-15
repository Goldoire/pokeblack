/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/gx_bgcnt.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

#define G2_GetBG0ScrPtr   sub_0207DF60
#define G2S_GetBG0ScrPtr  sub_0207DF94
#define G2_GetBG1ScrPtr   sub_0207DFB4
#define G2S_GetBG1ScrPtr  sub_0207DFE8
#define G2_GetBG2ScrPtr   sub_0207E008
#define G2S_GetBG2ScrPtr  sub_0207E08C
#define G2_GetBG3ScrPtr   sub_0207E100
#define G2S_GetBG3ScrPtr  sub_0207E184
#define G2_GetBG0CharPtr  sub_0207E1F8
#define G2S_GetBG0CharPtr sub_0207E22C
#define G2_GetBG1CharPtr  sub_0207E24C
#define G2S_GetBG1CharPtr sub_0207E280
#define G2_GetBG2CharPtr  sub_0207E2A0
#define G2S_GetBG2CharPtr sub_0207E2F0
#define G2_GetBG3CharPtr  sub_0207E330
#define G2S_GetBG3CharPtr sub_0207E388

#include "../../lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/gx_bgcnt.c"
