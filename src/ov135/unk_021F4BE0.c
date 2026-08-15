#include <nitro.h>
#include "ov135/worldtrade.h"

extern u8 _02202BFC[];
extern u32 (*const _02203B0C[])(WorldTradeWork *work);

void sub_021F4BF8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u8 a5);
void sub_02027858(void *a0);
void sub_02027FD8(void *a0);
void sub_02027974(void *a0);
u32 sub_020279E8(void *a0);
u32 sub_02027A04(void *a0);
void sub_021F5060(void);
void sub_021F4894(u8 *a0);
void sub_021F49F8(WorldTradeWork *work, u8 *a1);
void sub_021F4BCC(WorldTradeWork *work);
void *sub_020056BC(void);
void *sub_0202EE30(void *a0, void *a1, u32 a2, u32 a3, u32 a4);
void *sub_020120F4(void *a0);
void sub_02012E08(void *a0);
void sub_0200F7C0(u32 a0);

void sub_021F4BE0(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4)
{
    sub_021F4BF8(a0, a1, a2, a3, 0, a4);
}

void sub_021F4CE4(WorldTradeWork *work)
{
    if (work->unk_0E08 != NULL)
    {
        sub_02027858(work->unk_0E08);
        work->unk_0E08 = NULL;
    }
    if (work->unk_0E04 != NULL)
    {
        sub_02027FD8(work->unk_0E04);
        work->unk_0E04 = NULL;
    }
}

u32 sub_021F4D14(WorldTradeWork *work)
{
    u32 ret = 0;

    if (work->unk_0E08 != NULL)
    {
        sub_02027974(work->unk_0E08);
        if (sub_020279E8(work->unk_0E08) != 0)
        {
            ret = sub_02027A04(work->unk_0E08);
            if (ret == 0)
            {
                ret = 1;
            }
            else if (ret == 1)
            {
                ret = 2;
            }
            sub_021F5060();
        }
    }
    return ret;
}

s32 sub_021F4E30(WorldTradeWork *work)
{
    s32 ret = -1;

    if (work->unk_0E08 != NULL)
    {
        sub_02027974(work->unk_0E08);
        if (sub_020279E8(work->unk_0E08) != 0)
        {
            ret = sub_02027A04(work->unk_0E08) + 1;
            sub_021F5060();
        }
    }
    return ret;
}

void sub_021F4E64(WorldTradeWork *work)
{
    if (work->unk_0E08 != NULL)
    {
        sub_02027858(work->unk_0E08);
        work->unk_0E08 = NULL;
    }
    if (work->unk_0E04 != NULL)
    {
        sub_02027FD8(work->unk_0E04);
        work->unk_0E04 = NULL;
    }
    sub_021F5060();
}

void sub_021F4EDC(WorldTradeWork *work)
{
    sub_021F4894(_02202BFC);
    sub_021F49F8(work, _02202BFC);
    sub_021F4BCC(work);
}

void sub_021F4FA4(WorldTradeWork *work)
{
    work->unk_0DF8 = sub_0202EE30(sub_020056BC(), work->unk_0D40, 15, 16, 0x48);
}

/* G2x_SetBlendBrightness_ lives at 0x0207D658; spelled by address so the
 * verifier can check the call encoding instead of masking it out. */
void sub_0207D658(u32 addr, int plane, int brightness);

#define WT_BLEND_PLANES_A                                                      \
    (GX_BLEND_PLANEMASK_BG1 | GX_BLEND_PLANEMASK_BG2 | GX_BLEND_PLANEMASK_BG3 | \
     GX_BLEND_PLANEMASK_OBJ)
#define WT_BLEND_PLANES_B                                                      \
    (GX_BLEND_PLANEMASK_BG0 | GX_BLEND_PLANEMASK_BG1 | GX_BLEND_PLANEMASK_BG3 | \
     GX_BLEND_PLANEMASK_OBJ)

void sub_021F5008(u32 a0)
{
    if (a0 != 0)
    {
        sub_0207D658((u32)&reg_G2_BLDCNT, WT_BLEND_PLANES_A, -7);
    }
    else
    {
        sub_0207D658((u32)&reg_G2S_DB_BLDCNT, WT_BLEND_PLANES_A, -7);
    }
}

void sub_021F5034(u32 a0)
{
    if (a0 != 0)
    {
        sub_0207D658((u32)&reg_G2_BLDCNT, WT_BLEND_PLANES_B, -7);
    }
    else
    {
        sub_0207D658((u32)&reg_G2S_DB_BLDCNT, WT_BLEND_PLANES_B, -7);
    }
}

void sub_021F513C(WorldTradeWork *work)
{
    sub_02012E08(sub_020120F4(work->unk_0000[0x10]));
    sub_0200F7C0(0x29);
}

u32 sub_021F51F0(WorldTradeWork *work)
{
    return _02203B0C[work->state](work);
}
