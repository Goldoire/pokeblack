/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/fs/common/src/fs_api.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define FSi_InitRomArchive                   sub_0207AB10
#define OS_DisableInterrupts                 sub_02087988
#define OS_RestoreInterrupts                 sub_0208799C
#define FS_Init        sub_0207AD04
/* stripped or unplaced: FS_IsAvailable (16B) */
/* stripped or unplaced: FS_End (60B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/fs/common/src/fs_api.c"
