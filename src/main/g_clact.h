#ifndef G_CLACT_H
#define G_CLACT_H

/* Local, PROPOSED types for GameFreak's clact.c (cell-actor / 2D sprite
 * system), main 0x0204A48C-0x0204E074.  Every offset annotated PROVEN is
 * constrained by a byte-exact function in src/main/g_clact.c; the address
 * given is that function.  Naming follows pokeheartgold's sprite.h where the
 * gen-4 function corresponds.
 *
 * Do not move these into include/ -- the integrator agent owns that.
 */

#include "types.h"

struct GClactSet;

struct GClactRenderer;

typedef struct GClactVec2 {
    s16 x;
    s16 y;
} GClactVec2;

typedef struct GClactVec2u32 {
    u32 x;
    u32 y;
} GClactVec2u32;

/* Layout-identical copies of lib/TwlSystem nnsys/g2d/g2d_Image.h.  Sizes
 * (0x24 / 0x14) PROVEN by the ldm/stm run lengths in sub_0204B784 /
 * sub_0204B728; the identification is from sub_0204CAE4, which initialises
 * actor+0x1C with NNSi_G2dInitializeVRamLocation (0x02063790) and actor+0x40
 * with NNS_G2dInitImagePaletteProxy (0x020637D4). */
typedef struct GNNSVRamLocation {
    u32 baseAddrOfVram[3];
} GNNSVRamLocation;

typedef struct GNNSImageAttr {
    int sizeS;
    int sizeT;
    int fmt;
    int bExtendedPlt;
    int plttUse;
    int mappingType;
} GNNSImageAttr;

typedef struct GNNSImageProxy {          /* NNSG2dImageProxy, 0x24 */
    GNNSVRamLocation vramLocation;
    GNNSImageAttr attr;
} GNNSImageProxy;

typedef struct GNNSImagePaletteProxy {          /* NNSG2dImagePaletteProxy, 0x14 */
    int fmt;
    int bExtendedPlt;
    GNNSVRamLocation vramLocation;
} GNNSImagePaletteProxy;

/* == NNSG2dAnimController (lib/TwlSystem g2d_Animation.h), 0x30 bytes.
 * Field identifications PROVEN by offset:
 *   +0x08 bReverse, +0x0C bActive, +0x10 currentTime, +0x18 overriddenPlayMode
 * constrained by sub_0204B95C / sub_0204B98C / sub_0204B8F4 / sub_0204B9C4. */
typedef struct GClactAnimCtrl {
    const void *pCurrent;         // 0x00
    const void *pActiveCurrent;   // 0x04
    u32 bReverse;                 // 0x08
    u32 bActive;                  // 0x0C
    u32 currentTime;              // 0x10
    u32 speed;                    // 0x14
    u32 overriddenPlayMode;       // 0x18
    const void *pAnimSequence;    // 0x1C
    u32 callbackFunctor[4];       // 0x20
} GClactAnimCtrl;

/* Tail of GClact.  Word 0 is a small type tag that indexes the seven
 * function-pointer tables at 0x020A1394/0x020A13A0/0x020A13B8/0x020A13E8/
 * 0x020A140C/0x020A7F3C/0x020A7F48 (sub_0204D324..sub_0204D510).  For every
 * tag the handler returns `this + 0x0C`, i.e. an NNSG2dCellAnimation whose
 * first member is the NNSG2dAnimController above. */
typedef struct GClactAnim {
    u32 type;                     // 0x00
    const void *cellBank;         // 0x04
    const void *animBankData;     // 0x08
    u8 animation[0x7C - 0x0C];    // 0x0C
} GClactAnim;

/* The per-actor object.  sizeof == 0xE4, PROVEN by the stride in the
 * constructor sub_0204B100 (`mov r4,#0xe4; mla r0,r7,r4,r0`). */
typedef struct GClact {
    struct GClact *next;      // 0x00 draw-list link, PROVEN sub_0204CA30
    struct GClact *prev;      // 0x04 draw-list link, PROVEN sub_0204CA30
    void *list;               // 0x08 owning renderer, PROVEN sub_0204B800
    GClactVec2 pos;           // 0x0C PROVEN sub_0204B528/sub_0204B53C
    GClactVec2 unk10;         // 0x10 PROVEN sub_0204B588/sub_0204B59C
    GClactVec2u32 scale;      // 0x14 fx32 pair, =FX32_ONE in sub_0204CAE4
    GNNSImageProxy imageProxy;  // 0x1C PROVEN sub_0204B784/sub_0204B7C8/sub_0204CAE4
    GNNSImagePaletteProxy palProxy;    // 0x40 PROVEN sub_0204B728/sub_0204B764/sub_0204CAE4
    u32 animSpeed;            // 0x54 =FX32_ONE in sub_0204CAE4, PROVEN sub_0204B954
    u16 unk58;                // 0x58 PROVEN sub_0204B5F4/sub_0204B5FC
    u16 animSeq;              // 0x5A PROVEN sub_0204B878/sub_0204B898
    u16 unk5C;                // 0x5C PROVEN sub_0204B7F0
    u16 unk5E;                // 0x5E PROVEN sub_0204B7F8
    /* 0x60: one u32 of bitfields.  Every boundary below is PROVEN by the
     * bic/orr mask of the listed accessor. */
    u32 unk60_00 : 8;         // b0-7   sub_0204B800 / sub_0204B838
    u32 unk60_08 : 4;         // b8-11  sub_0204B688 / sub_0204B6E4(read 22)
    u32 unk60_0C : 4;         // b12-15 sub_0204B6F4 / sub_0204B714
    u32 unk60_10 : 2;         // b16-17 sub_0204B84C / sub_0204B864
    u32 unk60_12 : 2;         // b18-19 sub_0204B570
    u32 unk60_14 : 2;         // b20-21 sub_0204B604 / sub_0204B658
    u32 unk60_16 : 2;         // b22-23 sub_0204B688 / sub_0204B6E4
    u32 unk60_18 : 1;         // b24    (inferred: fills the gap)
    u32 unk60_19 : 1;         // b25    sub_0204B92C / sub_0204B944
    u32 unk60_1A : 1;         // b26    sub_0204B3DC / sub_0204B3F4
    u32 unk60_1B : 4;         // b27-30 sub_0204B9C4
    u32 unk60_1F : 1;         // b31    sub_0204B6F4
    u32 unk64_00 : 1;         // 0x64 b0 sub_0204BA20
    u32 unk64_01 : 31;
    struct GClactAnim anim;   // 0x68 nested animation object, 0x7C bytes
} GClact;

/* Creation parameters, >= 0x18 bytes.  0x00-0x07 PROVEN by sub_0204CED8,
 * 0x08-0x16 PROVEN by sub_0204D048.  Every field is copied straight into the
 * actor, which is what identifies them. */
typedef struct GClactInit {
    s16 x;                    // 0x00 -> GClact.pos.x   (via sub_0204B49C)
    s16 y;                    // 0x02 -> GClact.pos.y
    u16 animSeq;              // 0x04 -> GClact.animSeq
    u8 priority;              // 0x06 -> GClact.unk60_00
    u8 unk07;                 // 0x07 -> GClact.unk60_10
    s16 unk08;                // 0x08 -> GClact.unk10.x and .y
    u16 unk0A;                // 0x0A
    u32 unk0C;                // 0x0C -> GClact.scale.x
    u32 unk10;                // 0x10 -> GClact.scale.y
    u16 unk14;                // 0x14 -> GClact.unk58
    u16 unk16;                // 0x16 -> GClact.unk60_12
} GClactInit;

/* INFERRED from sub_0204B09C / sub_0204B0C8: the renderer holds a pointer at
 * +0x98 to an array of 0x48-byte records whose first two words are an fx32
 * (x,y) pair -- a screen-space origin the actor's s16 position is relative
 * to.  The renderer itself lives at GClactCore+0x40. */
typedef struct GClactCamera {
    u32 x;                    // 0x00 fx32
    u32 y;                    // 0x04 fx32
    u8 unk08[0x48 - 8];
} GClactCamera;

typedef struct GClactRenderer {
    u8 unk00[0x98];
    GClactCamera *cameras;    // 0x98 PROVEN sub_0204B09C/sub_0204B0C8
} GClactRenderer;

/* Resource header.  Field offsets PROVEN by sub_0204CF40. */
typedef struct GClactResHeader {
    u16 unk00;                // 0x00 -> GClact.unk5C
    u16 unk02;                // 0x02 -> GClact.unk5E
    GNNSImageProxy *imageProxy; // 0x04
    GNNSImagePaletteProxy *palProxy;   // 0x08
} GClactResHeader;

/* 0x20-byte stack template built by sub_0204CFA4 (all nine stores PROVEN). */
typedef struct GClactTemplate {
    u16 x;                    // 0x00
    u16 y;                    // 0x02
    u32 unk04;                // 0x04
    u32 unk08;                // 0x08
    u32 unk0C;                // 0x0C
    u32 unk10;                // 0x10
    u32 unk14;                // 0x14 zeroed
    u32 unk18;                // 0x18 zeroed
    u32 unk1C;                // 0x1C zeroed
} GClactTemplate;

/* The manager.  sizeof == 0x18, PROVEN by the allocation in sub_0204B100. */
typedef struct GClactSet {
    GClact *actors;           // 0x00 PROVEN sub_0204B100/sub_0204B1CC
    GClact *drawList;         // 0x04 circular, priority-sorted, PROVEN sub_0204C98C
    GClactRenderer *renderer; // 0x08 PROVEN sub_0204B258/sub_0204B270
    u16 count;                // 0x0C PROVEN sub_0204B100/sub_0204B1CC
    u8 unk0E_0 : 4;           // 0x0E b0-3 PROVEN sub_0204B258/sub_0204B270
    u8 unk0E_4 : 4;           // 0x0E b4-7 PROVEN sub_0204B22C/sub_0204B248
    u8 unk0F;                 // 0x0F list sort key, PROVEN sub_0204BBC8
    struct GClactSet *next;   // 0x10 PROVEN sub_0204BBC8/sub_0204BC40
    struct GClactSet *prev;   // 0x14 PROVEN sub_0204BBC8/sub_0204BC40
} GClactSet;

/* VRAM transfer request, 16 bytes.  Stride PROVEN by `lsl #4` indexing in
 * sub_0204C718 / sub_0204C7A4 / sub_0204C804; field offsets by sub_0204C8A4
 * and sub_0204C8B8. */
typedef struct GClactXfer {
    void *src;                // 0x00
    u32 dst;                  // 0x04
    u32 size;                 // 0x08
    u32 kind;                 // 0x0C indexes the table at 0x020A138C
} GClactXfer;

typedef struct GClactXferList {
    void *buffer;             // 0x00 PROVEN sub_0204C6E4
    GClactXfer *entries;      // 0x04 PROVEN sub_0204C718
    u32 count;                // 0x08 unsigned, PROVEN sub_0204C718/sub_0204C7A4
    u32 unk0C;                // 0x0C PROVEN sub_0204C6E4
} GClactXferList;

/* Two of these live at the head of GClactCore; stride 0x20 PROVEN by the
 * `add r0,r5,r4,lsl #5` loop in sub_0204BCF4 / sub_0204BD18. */
typedef struct GClactCoreEntry {
    u8 unk00[0x1C];           // 0x00
    u32 unk1C;                // 0x1C PROVEN sub_0204BD3C/sub_0204BD64/sub_0204BD7C
} GClactCoreEntry;

/* The clact.c singleton, reached through the global pointer _02146A74.
 * PROVEN offsets are those a byte-exact function reads or writes. */
typedef struct GClactCore {
    GClactCoreEntry engine[2];      // 0x00,0x20 PROVEN sub_0204BCF4/sub_0204BD18
    GClactRenderer renderer;        // 0x40 PROVEN sub_0204B270
    u8 unkDC[0xE0 - 0xDC];          // 0xDC
    GClactXferList xfer;            // 0xE0 PROVEN sub_0204C6E4/sub_0204C718/sub_0204C83C
    u16 unkF0;                      // 0xF0 PROVEN sub_0204BA7C
    u16 unkF2;                      // 0xF2 PROVEN sub_0204BA7C
    u32 unkF4;                      // 0xF4 PROVEN sub_0204BA7C
    u32 unkF8;                      // 0xF8 PROVEN sub_0204BAEC/sub_0204BB04
    u32 unkFC;                      // 0xFC PROVEN sub_0204BB20/sub_0204BB38
    GClactSet *head;                // 0x100 circular list head, PROVEN sub_0204BBC8
    u32 unk104;                     // 0x104
    u32 unk108;                     // 0x108
    u32 unk10C;                     // 0x10C INFERRED sub_0204B294
    void *unk110;                   // 0x110 INFERRED sub_0204B294 (stride-0x18 array)
    void *unk114;                   // 0x114 INFERRED sub_0204B294 (stride-0x14 array)
} GClactCore;

#endif // G_CLACT_H
