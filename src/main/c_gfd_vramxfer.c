/* TwlSDK/TwlSystem lib/TwlSystem/build/libraries/gfd/src/VramTransferMan/gfd_VramTransferManager.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define _u32_div_f                           sub_0209C2B8
#define GX_BeginLoadTex                      sub_0207F7A0
#define GX_LoadTex                           sub_0207F804
#define GX_EndLoadTex                        sub_0207F9BC
#define GX_BeginLoadTexPltt                  sub_0207FA0C
#define GX_LoadTexPltt                       sub_0207FA48
#define GX_EndLoadTexPltt                    sub_0207FAE4
#define GX_BeginLoadClearImage               sub_0207FB2C
#define GX_LoadClearImageColor               sub_0207FBC4
#define GX_EndLoadClearImage                 sub_0207FCEC
#define GX_BeginLoadOBJExtPltt               sub_0207F47C
#define GX_BeginLoadBGExtPltt                sub_0207F308
#define GXS_BeginLoadOBJExtPltt              sub_0207F6A8
#define GXS_BeginLoadBGExtPltt               sub_0203129C
#define DC_FlushRange                        sub_020862F0
#define GetNextIndex_                         sub_02061840
#define IsVramTransferTaskQueueFull_          sub_02061860
#define IsVramTransferTaskQueueEmpty_         sub_02061878
#define ResetTaskQueue_                       sub_02061B5C
#define NNSi_GfdPushVramTransferTaskQueue     sub_02061B74
#define NNSi_GfdGetFrontVramTransferTaskQueue sub_02061BB0
#define NNSi_GfdGetEndVramTransferTaskQueue   sub_02061BC0
#define NNSi_GfdPopVramTransferTaskQueue      sub_02061BD0
#define NNS_GfdInitVramTransferManager        sub_02061C0C
#define NNS_GfdClearVramTransferManagerTask   sub_02061C30
#define NNS_GfdDoVramTransfer                 sub_02061C44
#define NNS_GfdRegisterNewVramTransferTask    sub_02061CA4
/* stripped or unplaced: DoTransfer3dTex (44B) */
/* stripped or unplaced: DoTransfer3dTexPltt (44B) */
/* stripped or unplaced: DoTransfer3dClearImageColor (36B) */
/* stripped or unplaced: DoTransfer3dClearImageDepth (36B) */
/* stripped or unplaced: DoTransfer2dBG0CharMain (12B) */
/* stripped or unplaced: DoTransfer2dBG1CharMain (12B) */
/* stripped or unplaced: DoTransfer2dBG2CharMain (12B) */
/* stripped or unplaced: DoTransfer2dBG3CharMain (12B) */
/* stripped or unplaced: DoTransfer2dBG0ScrMain (12B) */
/* stripped or unplaced: DoTransfer2dBG1ScrMain (12B) */
/* stripped or unplaced: DoTransfer2dBG2ScrMain (12B) */
/* stripped or unplaced: DoTransfer2dBG3ScrMain (12B) */
/* stripped or unplaced: DoTransfer2dBG2BmpMain (12B) */
/* stripped or unplaced: DoTransfer2dBG3BmpMain (12B) */
/* stripped or unplaced: DoTransfer2dObjPlttMain (12B) */
/* stripped or unplaced: DoTransfer2dBGPlttMain (12B) */
/* stripped or unplaced: DoTransfer2dObjExtPlttMain (44B) */
/* stripped or unplaced: DoTransfer2dBGExtPlttMain (44B) */
/* stripped or unplaced: DoTransfer2dObjOamMain (12B) */
/* stripped or unplaced: DoTransfer2dObjCharMain (12B) */
/* stripped or unplaced: DoTransfer2dBG0CharSub (12B) */
/* stripped or unplaced: DoTransfer2dBG1CharSub (12B) */
/* stripped or unplaced: DoTransfer2dBG2CharSub (12B) */
/* stripped or unplaced: DoTransfer2dBG3CharSub (12B) */
/* stripped or unplaced: DoTransfer2dBG0ScrSub (12B) */
/* stripped or unplaced: DoTransfer2dBG1ScrSub (12B) */
/* stripped or unplaced: DoTransfer2dBG2ScrSub (12B) */
/* stripped or unplaced: DoTransfer2dBG3ScrSub (12B) */
/* stripped or unplaced: DoTransfer2dBG2BmpSub (12B) */
/* stripped or unplaced: DoTransfer2dBG3BmpSub (12B) */
/* stripped or unplaced: DoTransfer2dObjPlttSub (12B) */
/* stripped or unplaced: DoTransfer2dBGPlttSub (12B) */
/* stripped or unplaced: DoTransfer2dObjExtPlttSub (44B) */
/* stripped or unplaced: DoTransfer2dBGExtPlttSub (44B) */
/* stripped or unplaced: DoTransfer2dObjOamSub (12B) */
/* stripped or unplaced: DoTransfer2dObjCharSub (12B) */
/* stripped or unplaced: DoTransfer_ (52B) */
/* stripped or unplaced: NNS_GfdGetVramTransferTaskTotalSize (16B) */

#include "../../lib/TwlSystem/build/libraries/gfd/src/VramTransferMan/gfd_VramTransferManager.c"
