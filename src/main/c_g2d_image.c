/* lib/TwlSystem/build/libraries/g2d/src/g2d_Image.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define DC_FlushRange                        sub_020862F0
#define GX_BeginLoadTex                      sub_0207F7A0
#define GX_BeginLoadOBJExtPltt               sub_0207F47C
#define GXS_BeginLoadOBJExtPltt              sub_0207F6A8
#define GX_BeginLoadTexPltt                  sub_0207FA0C

#define NNS_G2dInitImagePaletteProxy     sub_020637D4
#define NNS_G2dSetImagePaletteLocation   sub_020637F4
#define NNS_G2dGetImagePaletteLocation   sub_02063800
/* not in shard or dead-stripped: NNS_G2dInitImageProxy (28B) */
/* not in shard or dead-stripped: NNS_G2dSetImageLocation (8B) */
/* not in shard or dead-stripped: NNS_G2dGetImageLocation (8B) */
/* not in shard or dead-stripped: NNS_G2dIsImageReadyToUse (20B) */
/* not in shard or dead-stripped: NNS_G2dIsImagePaletteReadyToUse (24B) */
/* not in shard or dead-stripped: NNS_G2dLoadImage1DMapping (536B) */
/* not in shard or dead-stripped: NNS_G2dLoadImage2DMapping (536B) */
/* not in shard or dead-stripped: NNS_G2dLoadImageVramTransfer (448B) */
/* not in shard or dead-stripped: NNS_G2dLoadPalette (248B) */
/* not in shard or dead-stripped: NNS_G2dLoadPaletteEx (348B) */
/* not in shard or dead-stripped: NNSi_G2dInitializeVRamLocation (28B) */
/* not in shard or dead-stripped: NNSi_G2dSetVramLocation (8B) */
/* not in shard or dead-stripped: NNSi_G2dGetVramLocation (8B) */
/* not in shard or dead-stripped: NNSi_G2dIsVramLocationReadyToUse (20B) */
/* not in shard or dead-stripped: NNSi_G2dDoImageLoadingToVram (124B) */
/* not in shard or dead-stripped: NNSi_G2dSetupImageProxyPrams (344B) */
/* not in shard or dead-stripped: NNSi_G2dDoLoadingPaletteToVram (212B) */
/* not in shard or dead-stripped: NNSi_G2dDoLoadingPaletteToVramEx (312B) */
/* not in shard or dead-stripped: NNSi_G2dSetupPaletteProxyPrams (44B) */

#include "../../lib/TwlSystem/build/libraries/g2d/src/g2d_Image.c"
