#ifndef POKEBLACK_OV094_H
#define POKEBLACK_OV094_H

#include "global.h"
#include "gf_fwd.h"

/*
 * ===========================================================================
 *  ov094 -- battle visual effects (btlv): script VM, sprite manager, input
 * ===========================================================================
 *
 * Merged from all 21 src/ov094/*.c declarations. Delete the local copies and
 * include this instead.
 *
 * FIELD GRADES
 *   PROVEN   the field is used by a function that verify_functions.py reports
 *            N/N OK. The compiler emitted that displacement and the ROM
 *            agrees, so the offset and the access width are right.
 *   INFERRED filler. It exists only to place the next PROVEN field. Its name,
 *            width and internal boundaries are guesses.
 *
 * `xN` after PROVEN is how many independent worker files put that field at
 * that offset.
 */

typedef struct AnimSprite AnimSprite;

/* ---------------------------------------------------------------------------
 * AnimVec3 -- 0x0C. Was declared 8 times, identically, plus once more as
 * `UnkVec3` with u32 members.
 *
 * UPGRADED: btlv_effvm_021FB6F4.c passes one of these to sub_0206DF3C, which
 * is NNS_G3dWorldPosToScrPos(const VecFx32 *, int *, int *). So this type IS
 * the SDK's VecFx32 (fx32 == s32) and the layout is verified by construction
 * rather than by eight workers agreeing. `Vec3` (2 decls, identical) is the
 * same type under a third name.
 *
 * ACTION: btlv_effvm_021FB034.c should rename UnkVec3 -> AnimVec3.
 * ------------------------------------------------------------------------- */
typedef VecFx32 AnimVec3;
typedef VecFx32 Vec3;

typedef struct AnimPoint16 {
    u16 x; // +0x00
    u16 y; // +0x02
} AnimPoint16;

/* ---------------------------------------------------------------------------
 * AnimSprRes -- 0x24. Sprite resource/geometry block at AnimSprite+0x04.
 * ------------------------------------------------------------------------- */
typedef struct AnimSprRes {
    u32 unk00; // +0x00 PROVEN
    s32 unk04; // +0x04 PROVEN
    u32 unk08; // +0x08 PROVEN
    s32 unk0C; // +0x0C PROVEN
    s32 unk10; // +0x10 PROVEN
    s32 unk14; // +0x14 PROVEN
    s32 unk18; // +0x18 PROVEN
    s32 unk1C; // +0x1C PROVEN
    u32 unk20; // +0x20 PROVEN
} AnimSprRes;

/* ---------------------------------------------------------------------------
 * AnimSprXform -- 0x10. Transform block at AnimSprite+0x2C.
 * ------------------------------------------------------------------------- */
typedef struct AnimSprXform {
    u32 unk00; // +0x00 PROVEN
    u32 unk04; // +0x04 PROVEN
    u32 unk08; // +0x08 PROVEN
    u16 unk0C; // +0x0C PROVEN
    u16 unk0E; // +0x0E PROVEN
} AnimSprXform;

/* ---------------------------------------------------------------------------
 * AnimSprite -- 0x5C. The element type of AnimMgr::sprites.
 *
 * The 0x5C stride is self-checking: 14 * 0x5C == 0x508, and placing the array
 * at AnimMgr+0x008 lands its end exactly on the bitfield word at 0x510. Any
 * other stride or base leaves an unexplained hole.
 * ------------------------------------------------------------------------- */
struct AnimSprite {
    void *unk00;         // +0x00 PROVEN x6
    AnimSprRes res;      // +0x04 PROVEN
    void *unk28;         // +0x28 PROVEN x3
    AnimSprXform xf;     // +0x2C PROVEN x2
    u32 unk3C;           // +0x3C PROVEN x3
    u32 unk40;           // +0x40 PROVEN x3
    u32 unk44;           // +0x44 PROVEN x3
    int unk48;           // +0x48 PROVEN x4
    u32 unk4C;           // +0x4C PROVEN -- the most-read field in the module
    u8 filler_50[0x0C];  // +0x50 INFERRED (to the 0x5C stride)
};

/* ---------------------------------------------------------------------------
 * AnimMgr -- 0x5A4. Declared in all seven btlv_mcss files.
 *
 * CONFLICT RESOLVED at +0x000. Six files declare
 *   u32 unk000; void *unk004; AnimSprite sprites[14];   (array at +0x008)
 * and one (btlv_mcss_021FF4C0.c) declares the array at +0x000. The six win,
 * and not only on the count: with the array at +0x008 it ends at 0x510, which
 * is exactly where btlv_mcss_021FFCB0.c reads the bitfield word, so the
 * layout closes with no unexplained filler. The +0x000 reading needs a
 * 12-byte hole to reach 0x514 and leaves 0x510 unaccounted for.
 *
 * The seven u8[14] counter rows at the tail are likewise self-checking:
 * 0x542 + 7*14 == 0x5A4, the struct end. Each row is one byte per sprite.
 * ------------------------------------------------------------------------- */
typedef struct AnimMgr {
    u32 unk000;                 // +0x000 PROVEN x6
    void *unk004;               // +0x004 PROVEN x6
    AnimSprite sprites[14];     // +0x008 PROVEN x7 (0x5C stride, ends 0x510)

    /* +0x510 PROVEN (btlv_mcss_021FFCB0.c). A bitfield, not a mask: the ROM
     * does the bic/orr write idiom, and the bits are read individually. */
    u32 unk510_0 : 1;
    u32 unk510_1 : 1;
    u32 unk510_2 : 1;
    u32 unk510_3 : 29;

    u32 unk514;                 // +0x514 PROVEN x3
    u32 unk518;                 // +0x518 PROVEN x3
    u32 unk51C;                 // +0x51C PROVEN x3
    u32 unk520;                 // +0x520 PROVEN x3
    u32 unk524;                 // +0x524 PROVEN x3
    u32 unk528;                 // +0x528 PROVEN
    u32 unk52C;                 // +0x52C PROVEN
    u32 unk530;                 // +0x530 PROVEN
    u32 unk534;                 // +0x534 PROVEN x2
    u32 unk538;                 // +0x538 PROVEN x2
    u32 unk53C;                 // +0x53C PROVEN x2
    u8 filler_540[0x02];        // +0x540 INFERRED

    u8 unk542[14];              // +0x542 PROVEN x3 -- one byte per sprite
    u8 unk550[14];              // +0x550 PROVEN x3
    u8 unk55E[14];              // +0x55E PROVEN x3
    u8 unk56C[14];              // +0x56C PROVEN x3
    u8 unk57A[14];              // +0x57A PROVEN x3
    u8 unk588[14];              // +0x588 PROVEN (btlv_mcss_02200CD0.c)
    u8 unk596[14];              // +0x596 PROVEN (btlv_mcss_02200CD0.c)
} AnimMgr;                      // 0x5A4

/* ---------------------------------------------------------------------------
 * BattleAnimSys -- 0x1EC. The btlv_effect root object.
 * The only disagreement was `void *` vs `u32` at +0x000; the typed form wins.
 * ------------------------------------------------------------------------- */
typedef struct BattleAnimSys {
    void *unk000;            // +0x000 PROVEN x3
    u32 unk004;              // +0x004 PROVEN
    void *unk008[32];        // +0x008 PROVEN -- 32-slot pointer table
    u8 filler_088[0x80];     // +0x088 INFERRED
    u32 unk108[32];          // +0x108 PROVEN -- 32-slot parallel table
    void *unk188;            // +0x188 PROVEN x3
    void *unk18C;            // +0x18C PROVEN x2
    void *unk190;            // +0x190 PROVEN
    void *unk194;            // +0x194 PROVEN
    void *unk198;            // +0x198 PROVEN
    void *unk19C;            // +0x19C PROVEN
    void *unk1A0;            // +0x1A0 PROVEN
    void *unk1A4;            // +0x1A4 PROVEN x2
    u8 filler_1A8[0x0C];     // +0x1A8 INFERRED
    void *unk1B4;            // +0x1B4 PROVEN
    void *unk1B8;            // +0x1B8 PROVEN
    void *unk1BC;            // +0x1BC PROVEN
    void *unk1C0;            // +0x1C0 PROVEN
    u8 filler_1C4[0x10];     // +0x1C4 INFERRED
    u16 unk1D4[4];           // +0x1D4 PROVEN
    void *unk1DC;            // +0x1DC PROVEN
    void *unk1E0;            // +0x1E0 PROVEN
    void *unk1E4;            // +0x1E4 PROVEN x2
    u32 unk1E8;              // +0x1E8 PROVEN x2
} BattleAnimSys;             // 0x1EC

/* ---------------------------------------------------------------------------
 * BattleAnimScript -- 0x2AC. Declared in all eight btlv_effvm files.
 *
 * A command is  BOOL cmd(ScriptContext *ctx, BattleAnimScript *work)  where
 * `work` is ctx->data. The VM is in main (sub_0201134C is ScriptReadWord), so
 * ScriptContext is registered opaque in gf_fwd.h, not here.
 *
 * The only disagreements were `u32` vs `void *` at +0x0DC/+0x0E0 -- same
 * width, typed form wins -- and whether +0x008..+0x237 is one flat filler or
 * splits at 0x0CC. btlv_effvm_021FB6F4.c indexes a pointer table there, so
 * the split is real and strictly more informative.
 *
 * +0x238/+0x23A: nothing reads either. Only their combined 4 bytes are
 * load-bearing (they place unk23C at 0x23C). The u16/u16 split is a guess.
 * ------------------------------------------------------------------------- */
typedef struct BattleAnimScript {
    u32 unk000;                             // +0x000 PROVEN x8
    u32 unk004;                             // +0x004 PROVEN x7
    u8 filler_008[0x0CC - 0x008];           // +0x008 INFERRED
    void *unk0CC[(0x0DC - 0x0CC) / 4];      // +0x0CC PROVEN -- indexed table
    void *unk0DC;                           // +0x0DC PROVEN x2
    void *unk0E0;                           // +0x0E0 PROVEN x2
    void *unk0E4[(0x238 - 0x0E4) / 4];      // +0x0E4 PROVEN -- same table
    u16 unk238;                             // +0x238 INFERRED (see note)
    u16 unk23A;                             // +0x23A INFERRED (see note)
    u32 unk23C;                             // +0x23C PROVEN x8
    u32 unk240;                             // +0x240 PROVEN
    u8 filler_244[0x18];                    // +0x244 INFERRED
    u32 unk25C;                             // +0x25C PROVEN
    int unk260;                             // +0x260 PROVEN
    u8 filler_264[0x08];                    // +0x264 INFERRED
    int unk26C[6];                          // +0x26C PROVEN
    u32 unk284;                             // +0x284 PROVEN
    u32 unk288;                             // +0x288 PROVEN
    u8 filler_28C[0x08];                    // +0x28C INFERRED
    u32 unk294;                             // +0x294 PROVEN
    u8 filler_298[0x0C];                    // +0x298 INFERRED
    u32 unk2A4;                             // +0x2A4 PROVEN
    u32 unk2A8;                             // +0x2A8 PROVEN
} BattleAnimScript;                         // 0x2AC

/* ---------------------------------------------------------------------------
 * AnimParamsA18 -- 0x3C. The parameter block handed to sub_021FFA18.
 * ------------------------------------------------------------------------- */
typedef struct AnimParamsA18 {
    u32 unk00;              // +0x00
    void *unk04;            // +0x04
    u32 unk08;              // +0x08
    u32 unk0C;              // +0x0C
    u32 unk10;              // +0x10
    u32 unk14;              // +0x14
    s32 unk18;              // +0x18
    s32 unk1C;              // +0x1C
    s32 unk20;              // +0x20
    u32 unk24;              // +0x24
    u8 filler_28[0x3C - 0x28]; // +0x28 INFERRED (to the reserved 0x3C)
} AnimParamsA18;

/* ---------------------------------------------------------------------------
 * btlv_input, 0x02206AF8..0x02206BAC.
 *
 * evidence.py --module ov094 confirms this one independently, off the
 * disassembly rather than off a worker's reading:
 *     run 0x02206af8..0x02206bac  (7 functions)  +0x054:4B  +0x058:4B
 * i.e. two 4-byte accesses at constant offsets from an untouched argument
 * register, inside seven functions that matched byte for byte.
 * ------------------------------------------------------------------------- */
typedef struct BattleInput {
    u8 filler_00[0x54]; // +0x00 INFERRED
    void *unk54;        // +0x54 PROVEN by match AND by evidence.py
    void *unk58;        // +0x58 PROVEN by match AND by evidence.py
} BattleInput;

#endif // POKEBLACK_OV094_H
