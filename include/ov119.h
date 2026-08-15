#ifndef POKEBLACK_OV119_H
#define POKEBLACK_OV119_H

/*
 * ===========================================================================
 *  ov119 -- link (player-to-player) trade
 * ===========================================================================
 *
 * PROMOTED VERBATIM from src/ov119/pokemontrade.h, which the ov119 worker
 * wrote to the standard this project wants: every named field carries the
 * byte-verified function that constrains it, and the runs that are only
 * padding say so. Nothing was re-derived or "improved" -- changing a field
 * here would invalidate the matches that produced it.
 *
 * ACTION FOR THE ov119 WORKER: replace
 *     #include "pokemontrade.h"
 * with
 *     #include "ov119.h"
 * and delete the private header. The local copy currently wins the quoted
 * include search, so the promotion has no effect until it is removed.
 *
 * In this project's vocabulary the commented fields are PROVEN (used by a
 * function that verify_functions.py reports N/N OK) and the pads are
 * INFERRED (they exist only to place the next proven field, and must not be
 * assumed to be single objects).
 */

#include "global.h"

/* Overlay 119 is the link (player-to-player) trade.  The original translation
 * units are named in the overlay's .rodata assert strings:
 * pokemontrade_proc.c, pokemontrade_nego.c, pokemontrade_mcss.c,
 * pokemontrade_save.c, pokemontrade_3d.c, pokemontrade_2d.c.
 *
 * Reconstructed from the reference bytes; every named field is constrained by
 * a byte-verified function.  Array extents marked GUESS are sized only to fill
 * the gap up to the next known field.
 */
typedef struct PokemonTradeWork
{
    u8 pad_0000[0x08];
    u32 *unk_0008;     /* sub_021D8A24 null-checks it; [2] set to 3 by sub_021D89CC */
    u8 pad_000C[0x5E4 - 0x0C];
    u32 unk_05E4[4];   /* per-netId, sub_021D916C; 4 fits exactly up to 0x5F4 */
    u16 unk_05F4;      /* sub_021D9434 */
    u8 pad_05F6[0x630 - 0x5F6];
    u32 unk_0630;      /* sub_021D8AF4 / sub_021DC5F0: box count n */
    u32 unk_0634;      /* n * 6 + 2      (sub_021DC5F0) */
    u32 unk_0638;      /* n * 0x14 + 0xC (sub_021DC5F0) */
    u32 unk_063C;      /* n * 0xA0 + 0x60, a pixel height (sub_021DC5F0) */
    u8 pad_0640[0x828 - 0x640];
    void *unk_0828;    /* sub_021DABB0 */
    void *unk_082C;    /* sub_021D89A8 */
    u8 pad_0830[0x840 - 0x830];
    void *unk_0840;    /* sub_021DC3EC: message handle */
    void *unk_0844;    /* sub_021DFD0C */
    u8 pad_0848[0x854 - 0x848];
    u32 unk_0854;      /* sub_021DFD0C */
    u8 pad_0858[0x9C0 - 0x858];
    void *unk_09C0;    /* sub_021D8980: the 0x021B65xx subsystem handle */
    u8 pad_09C4[0xF20 - 0x9C4];
    void *unk_0F20;    /* sub_021E66E8 */
    u8 pad_0F24[0xF2C - 0xF24];
    s32 unk_0F2C;      /* sub_021D9BC4: frame/timer, gated on > 0x1E */
    u8 pad_0F30[0xF84 - 0xF30];
    u32 unk_0F84;      /* sub_021DA1B4 */
    u32 unk_0F88;      /* sub_021D9E0C / sub_021DA1B4 */
    u8 pad_0F8C[0xFA0 - 0xF8C];
    u32 unk_0FA0;      /* sub_021D93E0 */
    /* Three parallel [2][3] tables; the 0xFA4/0xFBC pair is reset to -1 and
     * the 0xFD8 pointer released by sub_021DD4F4 / sub_021DD174. */
    s32 unk_0FA4[2][3];
    s32 unk_0FBC[2][3];
    u8 pad_0FD4[0xFD8 - 0xFD4];
    void *unk_0FD8[2][3];
    u8 pad_0FF0[0x1064 - 0xFF0];
    void *unk_1064[3]; /* sub_021DC5D0 frees all three */
    u8 pad_1070[0x107C - 0x1070];
    s16 unk_107C;      /* sub_021DB4EC: scroll position */
    u16 unk_107E;      /* sub_021D9384 */
    u8 pad_1080[0x118C - 0x1080];
    s32 unk_118C;      /* sub_021D8A24: index, valid when < 4 */
    u8 pad_1190[0x11E0 - 0x1190];
    u8 unk_11E0[4];    /* per-netId, sub_021D92DC */
    u8 pad_11E4[0x11F1 - 0x11E4];
    u8 unk_11F1;       /* sub_021DD140: countdown */
    u8 unk_11F2;       /* sub_021D8A18 */
    u8 pad_11F3[0x11F8 - 0x11F3];
    u8 unk_11F8;       /* sub_021DC818: pending fade kind */
} PokemonTradeWork;


#endif // POKEBLACK_OV119_H
