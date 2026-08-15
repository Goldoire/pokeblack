/*
 * ov021 / field_msgbg.c -- overworld message/BG text layer.
 *
 * TU recovered from the assert __FILE__ string "field_msgbg.c" at 0x021DDA50;
 * it spans 0x021901EC..0x021938AC (180 functions, 14016 bytes).
 *
 * Compiler: tools/mwccarm/dsi/1.1 (repo default), --thumb.
 *
 * Struct layouts and their evidence: src/ov021/fld_msgbg.h.
 */
#include "types.h"

#include "fld_msgbg.h"

void *sub_02030734(u16 heapId, u32 size, u32 atEnd, void *file, u32 line);
void sub_020307B0(void *ptr);

void *sub_0201D7EC(u32 a0, u32 a1, u32 a2, u32 a3, u16 heapId);
void *sub_0201C440(u16 heapId);
void *sub_0203101C(u16 a0, u16 a1, u32 a2, u32 a3);
void *sub_0204A1BC(u32 a0, u32 a1, u32 a2, u16 heapId);
void sub_02062A4C(void *a0, void *a1);
void sub_021931F4(void *a0);
void *sub_02193208(void *a0, u32 a1);
void sub_02193130(void *a0);

extern u8 _021DDA50[]; /* "field_msgbg.c" */

/* ---- 0x021901EC: MsgBg_New ---- */

MsgBg *sub_021901EC(u16 heapId, void *a1)
{
    MsgBg *msgBg = sub_02030734(heapId, sizeof(MsgBg), 1, _021DDA50, 420);

    msgBg->heapId = heapId;
    msgBg->unk002 = 0xFF;
    msgBg->unk004 = 0xFF;
    msgBg->unk168 = a1;
    msgBg->unk008 = sub_0201D7EC(0x17, 0, 0, 0, msgBg->heapId);
    msgBg->unk00C = sub_0201C440(msgBg->heapId);
    msgBg->unk164 = sub_0203101C(msgBg->heapId, msgBg->heapId, 1, 4);
    sub_021931F4(&msgBg->unk160);
    msgBg->unk174 = sub_0204A1BC(5, 0xC, 0, heapId);
    sub_02062A4C(msgBg->unk174, &msgBg->unk178);
    return msgBg;
}

/* ---- 0x02190270 ---- */

void sub_02192BD0(MsgBg *msgBg, u32 a1);

void sub_02190270(MsgBg *msgBg)
{
    sub_02192BD0(msgBg, 1);
}

/* ---- 0x0219027C: start the message task if it is not already running ---- */

void sub_02192CF0(MsgBg *msgBg, u32 a1);
void sub_02192EB8(void);
void *sub_020056A0(void *cb, MsgBg *msgBg, u32 a2);

void sub_0219027C(MsgBg *msgBg)
{
    sub_02192CF0(msgBg, 0);
    if (msgBg->task16C == NULL) {
        msgBg->task16C = sub_020056A0(sub_02192EB8, msgBg, 0);
    }
}

/* ---- 0x021902AC ---- */

void sub_02192FEC(u16 a0, u16 a1, void *a2);

void sub_021902AC(MsgBg *msgBg, void *a1)
{
    sub_02192FEC(msgBg->unk002, msgBg->heapId, a1);
}

/* ---- 0x021903CC ---- */

BOOL sub_021903CC(MsgBg *msgBg)
{
    if (msgBg->task16C == NULL) {
        return TRUE;
    }
    return FALSE;
}

/* ---- 0x0219047C ---- */

void sub_02194764(void *a0);

void sub_0219047C(MsgBg *msgBg)
{
    if (msgBg->unk15C != NULL) {
        sub_02194764(msgBg->unk15C);
    }
}

/* ---- 0x02190490 / 0x0219049C / 0x021904A8 ---- */

void *sub_0201C6EC(void *a0);
void *sub_0201C6B4(void *a0);

void *sub_02190490(MsgBg *msgBg)
{
    return sub_0201C6EC(msgBg->unk00C);
}

void *sub_0219049C(MsgBg *msgBg)
{
    return sub_0201C6B4(msgBg->unk00C);
}

void *sub_021904A8(MsgBg *msgBg)
{
    return msgBg->unk00C;
}

/* ---- 0x021904B0 ---- */

void sub_02045B38(u32 a0, u32 a1, u16 a2, u16 heapId);

void sub_021904B0(MsgBg *msgBg, u32 a1)
{
    sub_02045B38(0, 2, a1, msgBg->heapId);
}

/* ---- 0x021904D0 / 0x021904DC ---- */

void sub_021904D0(MsgBg *msgBg)
{
    msgBg->unk170 = 1;
}

/* r1 stays live across the offset arithmetic (CW reaches for r2 instead), so
 * the second argument is forwarded -- the arg-preplacement tell. */
void *sub_021904DC(MsgBg *msgBg, u32 a1)
{
    return sub_02193208(&msgBg->unk160, a1);
}

/* ---- 0x02190538: release one window's resources ---- */

void sub_02045808(void *a0);

void sub_02190538(MsgBgWin *win)
{
    void *v = win->unk18;

    win->unk08 = NULL;
    win->unk0C = NULL;
    sub_02045808(v);
    win->unk18 = NULL;
    win->unk10 = NULL;
}

/* ---- 0x02190620 ---- */

void *sub_02045770(void *a0);
void sub_02043B5C(void *a0, u32 a1);
void *sub_02045730(void *a0);
void sub_020409B4(void *a0);

void sub_02190620(MsgBgWin *win)
{
    sub_02043B5C(sub_02045770(win->unk14), 0xFF);
    sub_020409B4(sub_02045730(win->unk14));
}

/* ---- 0x02190604 ---- */

void sub_021905C8(MsgBgWin *win, u32 a1, u32 a2, u32 a3, u16 a4, void *a5);

void sub_02190604(MsgBgWin *win, u32 a1, u32 a2, u32 a3, u16 a4)
{
    sub_021905C8(win, a1, a2, a3, a4, win->unk08);
}

/* ---- 0x02190728 / 0x02190740 and the forwarder run above them ---- */

void sub_02190550(MsgBgWin *win);
void sub_02190590(MsgBgWin *win, u16 a1, u32 a2, u32 a3);
void *sub_0219061C(MsgBgWin *win);
void sub_0219063C(MsgBgWin *win, u32 a1, u32 a2, u32 a3, u32 a4);

void sub_02190728(MsgBgWinSet *set)
{
    sub_02193130(set->unk00);
    sub_02190538(set->win);
    sub_020307B0(set);
}

void sub_02190740(MsgBgWinSet *set)
{
    sub_02190550(set->win);
    sub_020409B4(sub_02045730(set->unk00));
}

void sub_02190758(MsgBgWinSet *set, u16 a1, u32 a2, u32 a3)
{
    sub_02190590(set->win, a1, a2, a3);
}

void sub_02190764(MsgBgWinSet *set, u32 a1, u32 a2, u32 a3, u16 a4, void *a5)
{
    sub_021905C8(set->win, a1, a2, a3, a4, a5);
}

void *sub_0219077C(MsgBgWinSet *set)
{
    return sub_0219061C(set->win);
}

void sub_02190788(MsgBgWinSet *set)
{
    sub_02190620(set->win);
}

void sub_02190794(MsgBgWinSet *set, u32 a1, u32 a2, u32 a3, u32 a4)
{
    sub_0219063C(set->win, a1, a2, a3, a4);
}

/* ---- 0x02190708 / 0x021907A8 ---- */

void sub_02190680(MsgBg *msgBg, u32 a1, u32 a2, u32 a3, u16 a4, u16 a5, u16 a6);

void sub_02190708(MsgBg *msgBg, u32 a1, u32 a2, u32 a3, u16 a4, u16 a5)
{
    msgBg->unk006 = 14;
    sub_02190680(msgBg, a1, a2, a3, a4, a5, msgBg->unk006);
}

void sub_021907A8(MsgBg *msgBg, u32 a1)
{
    sub_02190708(msgBg, a1, 1, 0x13, 0x1E, 4);
}

/* ---- 0x02190344 / 0x02190378 / 0x02190398 ---- */

void sub_02194798(void *a0);
void sub_02040DA8(u16 a0, u32 a1, u32 a2);
void sub_020403F4(u8 a0);
void sub_02192E0C(MsgBg *msgBg);

void sub_02190344(MsgBg *msgBg)
{
    if (msgBg->unk15C != NULL) {
        sub_02194798(msgBg->unk15C);
        msgBg->unk15C = NULL;
    }
    if (msgBg->unk002 != 0xFF) {
        sub_02040DA8(msgBg->unk002, 1, 0);
        sub_020403F4(msgBg->unk002);
        msgBg->unk002 = 0xFF;
    }
}

BOOL sub_02190378(MsgBg *msgBg)
{
    if (msgBg->unk004 != 0xFF) {
        sub_020403F4(msgBg->unk004);
        msgBg->unk004 = 0xFF;
        return TRUE;
    }
    return FALSE;
}

void sub_02190398(MsgBg *msgBg)
{
    if (msgBg->unk15C != NULL) {
        sub_02194798(msgBg->unk15C);
    }
    sub_02192E0C(msgBg);
    if (msgBg->task16C == NULL) {
        msgBg->task16C = sub_020056A0(sub_02192EB8, msgBg, 0);
    }
}

/* ---- 0x0219082C / 0x02190844 / 0x02190854 ---- */

void sub_02192BC0(void *a0);

void sub_0219082C(MsgBgWinSet *set)
{
    sub_02192BC0(set->unk00);
    sub_02190538(set->win);
    sub_020307B0(set);
}

void sub_02190844(MsgBgWinSet *set, u16 a1, u32 a2, u32 a3)
{
    sub_02190590(set->win, a1 + 8, a2, a3);
}

void sub_02190854(MsgBgWinSet *set)
{
    sub_02190620(set->win);
}

/* ---- 0x02190938 / 0x02190960 / 0x0219097C ---- */

void sub_02190860(MsgBg *msgBg, const void *a1, u32 a2, u32 a3, u16 a4, u16 a5,
                  u32 a6, u32 a7, u32 a8);

void sub_02190938(MsgBg *msgBg, const void *a1, u32 a2, u32 a3, u16 a4, u32 a5,
                  u32 a6, u32 a7)
{
    msgBg->unk006 = 14;
    sub_02190860(msgBg, a1, a2, a3, a4, msgBg->unk006, a5, a6, a7);
}

/* `tmpl` is const: that is what lets CW hoist the unk1C load above the
 * neighbouring stack-argument store, which is the only thing that differs
 * without it. */
void sub_02190960(MsgBg *msgBg, const MsgBgWinTemplate *tmpl, u32 a2, u32 a3, u16 a4)
{
    sub_02190938(msgBg, tmpl, a2, a3, a4, 0, tmpl->unk1C, 0);
}

void sub_0219097C(MsgBg *msgBg, const MsgBgWinTemplate *tmpl, u32 a2)
{
    sub_02190960(msgBg, tmpl, a2, 0, 0);
}

/* ---- 0x021909BC / 0x02190A14 / 0x02190B1C ---- */

void sub_0202020C(void *a0, u32 a1, u32 a2);
void sub_0201F868(void *a0);
void *sub_02020234(void *a0);
void sub_0201F73C(void *a0, u32 a1, u32 a2, u32 a3);

void sub_021909BC(MsgBgPrinter *printer)
{
    sub_0202020C(printer->unk10, 0, 0);
    sub_0201F868(printer->unk0C);
    sub_02193130(printer->unk08);
    sub_02190538(printer->win);
    sub_020307B0(printer);
}

void *sub_02190A14(MsgBgPrinter *printer)
{
    return sub_02020234(printer->unk10);
}

void sub_02190B1C(MsgBgPrinter *printer)
{
    sub_0201F73C(printer->unk08, 0, 1, 0xD);
}

/* ---- 0x02190B08 ---- */

void sub_02190B08(MsgBgWinTemplate *tmpl, u16 a1, u16 a2, u16 a3, u16 a4, u16 a5)
{
    tmpl->unk00 = a1;
    tmpl->unk16 = a3;
    tmpl->unk14 = a2;
    tmpl->unk18 = a4;
    tmpl->unk1A = a5;
}

/* ---- 0x02190C78 ---- */

u32 sub_021909E4(void *a0, u32 a1, u32 a2, u32 a3);

u32 sub_02190C78(void *a0, u32 a1, u32 a2, u32 a3)
{
    u32 v = sub_021909E4(a0, a1, a2, a3);

    if (v == 0xFFFFFFFF) {
        return 2;
    }
    if (v == 0xFFFFFFFE) {
        return 1;
    }
    return v;
}

/* ---- 0x02190D48 ---- */

void sub_0201CE48(void *a0);

void sub_02190D48(MsgBgWinSet *set)
{
    sub_0201CE48(set->win);
    sub_020307B0(set);
}
