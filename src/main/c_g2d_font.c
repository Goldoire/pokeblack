/* TwlSDK/TwlSystem lib/TwlSystem/build/libraries/g2d/src/g2d_Font.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define NNSi_G2dGetUnpackedFont              sub_02069900
#define GetGlyphIndex                     sub_02067EB0
#define NNS_G2dFontInitUTF8               sub_02067F78
#define NNS_G2dFontFindGlyphIndex         sub_02067F9C
/* stripped or unplaced: NNS_G2dFontInitAuto (48B) */
/* stripped or unplaced: NNS_G2dFontInitUTF16 (36B) */
/* stripped or unplaced: NNS_G2dFontInitShiftJIS (36B) */
/* stripped or unplaced: NNS_G2dFontInitCP1252 (36B) */
/* stripped or unplaced: NNS_G2dFontGetCharWidthsFromIndex (72B) */
/* stripped or unplaced: NNSi_G2dFontGetStringWidth (172B) */
/* stripped or unplaced: NNSi_G2dFontGetTextHeight (116B) */
/* stripped or unplaced: NNSi_G2dFontGetTextWidth (88B) */
/* stripped or unplaced: NNSi_G2dFontGetTextRect (148B) */

#include "../../lib/TwlSystem/build/libraries/g2d/src/g2d_Font.c"
