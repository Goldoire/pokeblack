#include "types.h"

struct UnkStruct02160A64
{
    u32 unk_00;
    int (*unk_04)(void *, void *);
    int (*unk_08)(void *, void *);
    void *unk_0C;
    void *unk_10;
};

struct UnkStruct021673A8
{
    u8 unk_00[0x848];
    u8 unk_848;
    u8 unk_849;
};

struct UnkStruct0216745C
{
    u8 unk_00[8];
    void *unk_08;
};

struct UnkStruct02159284
{
    u8 unk_00[0x14];
    u32 unk_14;
};

extern u16 _02171160[];
extern u16 _02171170[];

u16 *sub_02159AE8(void *ctx, void *script);
u32 sub_02159B10(void *ctx, void *script);

void sub_02159960(void);
void sub_02159984(void);
void sub_021579B0(void);
void sub_02157D68(void);

void sub_020113D0(void *p, void (*fn)(void));
u32 sub_02011330(void *p);
void sub_0201137C(void *p, u32 v);
u32 sub_0201134C(void *p);
void sub_020113B4(void *p, u32 v);
void sub_020113B0(void *p, u32 v);
void *sub_02012EC0(void *p);
void *sub_0200C0E8(void *p);
void sub_0200C224(void *p);
void sub_0200C1DC(void *p);
void sub_0200E06C(void *p);
void sub_0200E024(void *p);
u32 sub_02161DC4(void *p);
u32 sub_0200FB24(void *p);
u32 sub_0202708C(u32 p);
void sub_02165094(u32 p);
void sub_021650CC(u32 p);
void sub_02165104(u32 p);
void sub_0216513C(u32 p);
void sub_0203CEAC(u32 p);
void sub_0203D0DC(u32 p);
void sub_02157960(void *p, void (*fn)(void), u32 v);

/* ---- 0x02160A64 : dispatch through an optional callback ------------- */

int sub_02160A64(struct UnkStruct02160A64 *p)
{
    if (p->unk_04 != NULL)
    {
        return p->unk_04(p->unk_10, p->unk_0C);
    }

    return 1;
}

int sub_02160A7C(struct UnkStruct02160A64 *p)
{
    if (p->unk_08 != NULL)
    {
        return p->unk_08(p->unk_10, p->unk_0C);
    }

    return 1;
}

/* ---- 0x021672D0 ------------------------------------------------------ */

void sub_021672D0(struct UnkStruct0216745C *p)
{
    sub_0200C224(sub_0200C0E8(sub_02012EC0(p->unk_08)));
}

void sub_021672E4(struct UnkStruct0216745C *p)
{
    sub_0200C1DC(sub_0200C0E8(sub_02012EC0(p->unk_08)));
}

/* ---- 0x02159974 : install a callback --------------------------------- */

int sub_02159974(void *p)
{
    sub_020113D0(p, sub_02159960);

    return 1;
}

int sub_02159998(void *p)
{
    sub_020113D0(p, sub_02159984);

    return 1;
}

/* ---- 0x021593DC ------------------------------------------------------ */

int sub_021593DC(void *ctx)
{
    sub_0201137C(ctx, sub_02011330(ctx));

    return 0;
}

int sub_021593F0(void *ctx, void *script)
{
    sub_0201137C(ctx, sub_02159B10(ctx, script));

    return 0;
}

/* ---- 0x02159284 ------------------------------------------------------ */

int sub_02159284(struct UnkStruct02159284 *p)
{
    u32 v = sub_0201134C(p);

    sub_020113B4(p, p->unk_14 + v);

    return 0;
}

int sub_02159658(struct UnkStruct02159284 *p)
{
    u32 v = sub_0201134C(p);

    sub_020113B0(p, p->unk_14 + v);

    return 0;
}

/* ---- 0x02161E4C ------------------------------------------------------ */

int sub_02161E4C(void *p)
{
    if (sub_02161DC4(p))
    {
        return TRUE;
    }

    return FALSE;
}

int sub_0216210C(void *p)
{
    if (sub_0200FB24(p))
    {
        return TRUE;
    }

    return FALSE;
}

/* ---- 0x0216505C ------------------------------------------------------ */

void sub_0216505C(u32 param0)
{
    if (sub_0202708C(param0))
    {
        sub_02165104(param0);
    }
    else
    {
        sub_02165094(param0);
    }
}

void sub_02165078(u32 param0)
{
    if (sub_0202708C(param0))
    {
        sub_0216513C(param0);
    }
    else
    {
        sub_021650CC(param0);
    }
}

/* ---- 0x021673A8 ------------------------------------------------------ */

u8 sub_021673A8(struct UnkStruct021673A8 *p)
{
    u8 v;

    sub_0200E06C(p);
    v = p->unk_848;
    sub_0200E024(p);

    return v;
}

u8 sub_021673C4(struct UnkStruct021673A8 *p)
{
    u8 v;

    sub_0200E06C(p);
    v = p->unk_849;
    sub_0200E024(p);

    return v;
}

/* ---- 0x0215B464 : look a value up in a table ------------------------- */

int sub_0215B464(void *ctx, void *script)
{
    u32 index = sub_02159B10(ctx, script);
    u16 *dest = sub_02159AE8(ctx, script);

    *dest = _02171160[index];

    return 0;
}

int sub_0215B488(void *ctx, void *script)
{
    u32 index = sub_02159B10(ctx, script);
    u16 *dest = sub_02159AE8(ctx, script);

    *dest = _02171170[index];

    return 0;
}

/* ---- 0x02157A58 ------------------------------------------------------ */

void sub_02157A58(void *p)
{
    sub_0203CEAC(0);
    sub_02157960(p, sub_021579B0, 0x10A);
}

void sub_02157D98(void *p)
{
    sub_0203D0DC(0);
    sub_02157960(p, sub_02157D68, 0x1B7);
}
