/* lib/TwlSystem/build/libraries/g2d/src/g2d_Font.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define NNSi_G2dGetUnpackedFont              sub_020698F8

#define GetGlyphIndex                     sub_02067EB0
#define NNS_G2dFontInitUTF8               sub_02067F78
#define NNS_G2dFontFindGlyphIndex         sub_02067F9C
/* not in shard or dead-stripped: NNS_G2dFontInitAuto (48B) */
/* not in shard or dead-stripped: NNS_G2dFontInitUTF16 (36B) */
/* not in shard or dead-stripped: NNS_G2dFontInitShiftJIS (36B) */
/* not in shard or dead-stripped: NNS_G2dFontInitCP1252 (36B) */
/* not in shard or dead-stripped: NNS_G2dFontGetCharWidthsFromIndex (72B) */
/* not in shard or dead-stripped: NNSi_G2dFontGetStringWidth (172B) */
/* not in shard or dead-stripped: NNSi_G2dFontGetTextHeight (116B) */
/* not in shard or dead-stripped: NNSi_G2dFontGetTextWidth (88B) */
/* not in shard or dead-stripped: NNSi_G2dFontGetTextRect (148B) */

#include "../../lib/TwlSystem/build/libraries/g2d/src/g2d_Font.c"
