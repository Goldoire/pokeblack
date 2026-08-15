/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/fs/common/src/fs_overlay.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define FS_FindArchive                       sub_02077EB8
#define IC_InvalidateRange                   sub_0208632C
#define DC_InvalidateRange                   sub_020862B8
#define MI_CpuFill8                          sub_02082BCC
#define FS_InitFile                          sub_020788AC
#define MI_CpuCopy8                          sub_02082D44
#define FS_OpenFileFast                      sub_020789A4
#define FS_CreateFileFromRom                 sub_0207ACD4
#define FS_CloseFile                         sub_02078A80
#define FS_GetFileLength                     sub_02078A94
#define DC_FlushRange                        sub_020862F0
#define OS_DisableInterrupts                 sub_02087988
#define OS_RestoreInterrupts                 sub_0208799C
#define FSi_GetOverlayBinarySize sub_02078CB0
#define FS_ClearOverlayImage     sub_02078CCC
#define FS_LoadOverlayImage      sub_02078EB0
#define FS_EndOverlay            sub_02079164
#define FS_UnloadOverlayImage    sub_02079254
#define FS_LoadOverlay           sub_02079264
#define FS_UnloadOverlay         sub_020792B8
/* stripped or unplaced: FSi_InitOverlay (112B) */
/* stripped or unplaced: FS_GetOverlayFileID (44B) */
/* stripped or unplaced: FS_LoadOverlayInfo (368B) */
/* stripped or unplaced: FS_LoadOverlayImageAsync (132B) */
/* stripped or unplaced: FSi_CompareDigest (192B) */
/* stripped or unplaced: FS_StartOverlay (240B) */
/* stripped or unplaced: FS_AttachOverlayTable (128B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/fs/common/src/fs_overlay.c"
