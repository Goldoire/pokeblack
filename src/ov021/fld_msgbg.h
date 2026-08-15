#ifndef POKEBLACK_OV021_FLD_MSGBG_H
#define POKEBLACK_OV021_FLD_MSGBG_H

/*
 * ov021 / field_msgbg.c -- the overworld message/BG text layer.
 *
 * PROPOSAL for include/. TU recovered from the assert __FILE__ string
 * "field_msgbg.c" at 0x021DDA50 (13 references); it spans
 * 0x021901EC..0x021938AC, 180 functions / 14016 bytes -- the largest per-file
 * count in ov021 outside the fldmmdl_acmd belt.
 *
 * FieldSystem+0x02C points at a MsgBg (fld_fieldsys.h), and FieldSystem+0x028
 * points at a second, distinct object of this TU.
 *
 * The TU owns at least three objects. Only MsgBg has a proven size; the other
 * two are only ever reached through a pointer, so their extents are open.
 */

/*
 * Size 0x17C, PROVEN by the allocation in MsgBg_New (0x021901EC):
 *     movs r1,#0x69 ; lsls r1,r1,#2   -> 0x1A4, stored as the line number 420
 *     subs r1,#0x28                   -> 0x17C, the size
 *     blx sub_02030734 (heapId, 0x17C, 1, "field_msgbg.c", 420)
 * The 0x17C/420 pun is CW reusing one constant for both, which is also why
 * 0xFF is materialised twice in the ctor (as a value and as an offset base).
 */
typedef struct MsgBg {
    /* 0x000 */ u16 heapId;   // PROVEN 0x021901EC (the ctor argument); re-read
                              // by 0x021902AC and 0x021904B0
    /* 0x002 */ u16 unk002;   // PROVEN 0x021901EC = 0xFF; read by 0x021902AC
    /* 0x004 */ u16 unk004;   // PROVEN 0x021901EC = 0xFF
    /* 0x006 */ u16 unk006;   // PROVEN 0x02190708 (set to 14, then re-read as
                              // the 7th argument of 0x02190680)
    /* 0x008 */ void *unk008; // PROVEN 0x021901EC = sub_0201D7EC(0x17,0,0,0,heapId)
    /* 0x00C */ void *unk00C; // PROVEN 0x021901EC = sub_0201C440(heapId);
                              // acc 0x021904A8, fed to sub_0201C6EC / sub_0201C6B4
    /* 0x010 */ u8 filler010[0x15C - 0x010];
    /* 0x15C */ void *unk15C; // PROVEN 0x0219047C (nullable; sub_02194764 frees it)
    /* 0x160 */ u32 unk160;   // PROVEN 0x021901EC / 0x021904DC: the ADDRESS of this
                              // slot is handed to sub_021931F4 (init) and
                              // sub_02193208, so 0x160 starts an embedded struct
    /* 0x164 */ void *unk164; // PROVEN 0x021901EC = sub_0203101C(heapId, heapId, 1, 4)
    /* 0x168 */ void *unk168; // PROVEN 0x021901EC (the ctor's 2nd argument)
    /* 0x16C */ void *task16C;// PROVEN 0x0219027C = sub_020056A0(sub_02192EB8, this, 0),
                              // created lazily; 0x021903CC tests it for NULL
    /* 0x170 */ u8 unk170;    // PROVEN 0x021904D0 (strb 1)
    /* 0x171 */ u8 filler171[3];
    /* 0x174 */ void *unk174; // PROVEN 0x021901EC = sub_0204A1BC(5, 0xC, 0, heapId)
    /* 0x178 */ u32 unk178;   // PROVEN 0x021901EC: the ADDRESS of this slot is the
                              // 2nd argument of sub_02062A4C
} MsgBg;                      // size 0x17C

/*
 * The per-window record. No allocation site in this TU reaches it, so the size
 * is open; 0x19 bytes are proven.
 */
typedef struct MsgBgWin {
    /* 0x00 */ u8 filler00[8];
    /* 0x08 */ void *unk08;  // PROVEN 0x02190538 (NULLed), 0x02190604 (read)
    /* 0x0C */ void *unk0C;  // PROVEN 0x02190538 (NULLed)
    /* 0x10 */ void *unk10;  // PROVEN 0x02190538 (NULLed)
    /* 0x14 */ void *unk14;  // PROVEN 0x02190620 (fed to sub_02045770 / sub_02045730)
    /* 0x18 */ void *unk18;  // PROVEN 0x02190538 (read, freed by sub_02045808, NULLed)
} MsgBgWin;

/*
 * The pair that 0x02190728 tears down. Two words; every forwarder in the
 * 0x02190740..0x021907A8 run reaches its window through +0x04.
 *
 * NOTE the open question: 0x02190708 writes a u16 at +0x06 of ITS first
 * argument, which cannot coexist with unk04 being a pointer. Either 0x02190708
 * takes a MsgBg (whose +0x06 is free -- the reading adopted here) or this pair
 * has a different head. Do not merge the two types without resolving it.
 */
typedef struct MsgBgWinSet {
    /* 0x00 */ void *unk00;    // PROVEN 0x02190728 (sub_02193130), 0x02190740
    /* 0x04 */ MsgBgWin *win;  // PROVEN 0x02190728, 0x02190740, 0x02190758,
                               // 0x02190764, 0x0219077C, 0x02190788, 0x02190794
} MsgBgWinSet;

/*
 * A larger printer record. Same window at +0x04 as MsgBgWinSet but a different
 * head, so the two are genuinely distinct objects.
 */
typedef struct MsgBgPrinter {
    /* 0x00 */ u8 filler00[4];
    /* 0x04 */ MsgBgWin *win; // PROVEN 0x021909BC (sub_02190538)
    /* 0x08 */ void *unk08;   // PROVEN 0x021909BC (sub_02193130), 0x02190B1C
    /* 0x0C */ void *unk0C;   // PROVEN 0x021909BC (sub_0201F868)
    /* 0x10 */ void *unk10;   // PROVEN 0x021909BC (sub_0202020C), 0x02190A14
} MsgBgPrinter;

/* The window template the 0x02190938 family is handed. */
typedef struct MsgBgWinTemplate {
    /* 0x00 */ u16 unk00;     // PROVEN 0x02190B08
    /* 0x02 */ u8 filler02[0x14 - 0x02];
    /* 0x14 */ u16 unk14;     // PROVEN 0x02190B08
    /* 0x16 */ u16 unk16;     // PROVEN 0x02190B08
    /* 0x18 */ u16 unk18;     // PROVEN 0x02190B08
    /* 0x1A */ u16 unk1A;     // PROVEN 0x02190B08
    /* 0x1C */ u32 unk1C;     // PROVEN 0x02190960
} MsgBgWinTemplate;

#endif // POKEBLACK_OV021_FLD_MSGBG_H
