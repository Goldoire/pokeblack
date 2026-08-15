#include "types.h"

// Script-command handlers: (ctx, script) -> BOOL "yield".
// sub_0215A5E4 / sub_0215A5DC / sub_0215A5F4 read an operand out of the
// script; sub_02159AE8 resolves the destination script variable.

void *sub_0215A5DC(void *script);
void *sub_0215A5E4(void *script);
void *sub_0215A5F4(void *script);
u16 sub_0215A5D0(void *script);
u16 sub_0215A610(void *script);
u16 *sub_02159AE8(void *ctx, void *script);
u32 sub_02159B10(void *ctx, void *script);

void *sub_0200CA1C(void *param0);
void sub_0200CA28(void *param0);
void sub_0200CA40(void *param0);
u16 sub_0200CA38(void *param0);
void *sub_02012934(void *param0);
void sub_0201BA34(void *param0);
void *sub_0201210C(void *param0);
void sub_021F385C(void *param0);
void *sub_02012B38(void *param0);
u16 sub_02014460(void *param0);
void *sub_02012F08(void *param0);
u16 sub_0200C258(void *param0);
void *sub_0201296C(void *param0);
void sub_02014314(void *param0, u32 param1);
void sub_0201433C(void *param0, u32 param1);
void sub_0215A4EC(void *param0, u32 param1);
void sub_0215A500(void *param0, u32 param1);
u16 sub_0216F830(void *param0);
u16 sub_021690B4(void *param0);
u16 sub_021690F0(void *param0);
u16 sub_0201214C(void *param0);
void sub_02158FBC(void *param0);
void sub_020121CC(void *param0);
void sub_0216CC40(void *param0);
void sub_0216F900(void *param0);
void sub_0215897C(void *param0, u32 param1);
u32 sub_020145CC(void *param0);
u32 sub_021670F8(void *param0);
u32 sub_021F38BC(void *param0);
void *sub_02188D50(void *param0);
u16 sub_021C3400(void *param0);
u16 sub_021C340C(void *param0);
u16 sub_021C34C4(void *param0);

/* ---- F3: *var = c(b(a(script))) ------------------------------------- */

int sub_02159708(void *ctx, void *script)
{
    u16 *dest = sub_02159AE8(ctx, script);

    *dest = sub_02014460(sub_02012B38(sub_0215A5E4(script)));

    return 0;
}

int sub_0215ACA8(void *ctx, void *script)
{
    u16 *dest = sub_02159AE8(ctx, script);

    *dest = sub_0200C258(sub_02012F08(sub_0215A5E4(script)));

    return 0;
}

int sub_0215AFF4(void *ctx, void *script)
{
    u16 *dest = sub_02159AE8(ctx, script);

    *dest = sub_0200CA38(sub_0200CA1C(sub_0215A5E4(script)));

    return 0;
}

/* ---- F5: *var = a(script) ------------------------------------------- */

int sub_0215AADC(void *ctx, void *script)
{
    u16 *dest = sub_02159AE8(ctx, script);

    *dest = sub_0215A610(script);

    return 0;
}

int sub_0215AD38(void *ctx, void *script)
{
    u16 *dest = sub_02159AE8(ctx, script);

    *dest = sub_0215A5D0(script);

    return 0;
}

/* ---- F6: operand first, then destination ---------------------------- */

int sub_0215AAF4(void *ctx, void *script)
{
    void *arg = sub_0215A5E4(script);
    u16 *dest = sub_02159AE8(ctx, script);

    *dest = sub_0216F830(arg);

    return 0;
}

int sub_0215AB18(void *ctx, void *script)
{
    void *arg = sub_0215A5E4(script);
    u16 *dest = sub_02159AE8(ctx, script);

    *dest = sub_021690B4(arg);

    return 0;
}

int sub_0215AB3C(void *ctx, void *script)
{
    void *arg = sub_0215A5E4(script);
    u16 *dest = sub_02159AE8(ctx, script);

    *dest = sub_021690F0(arg);

    return 0;
}

int sub_0215F2B8(void *ctx, void *script)
{
    void *arg = sub_0215A5DC(script);
    u16 *dest = sub_02159AE8(ctx, script);

    *dest = sub_0201214C(arg);

    return 0;
}

/* ---- F4: two-operand setter ----------------------------------------- */

int sub_02159728(void *ctx, void *script)
{
    void *obj = sub_0201296C(sub_0215A5E4(script));

    sub_02014314(obj, sub_02159B10(ctx, script));

    return 0;
}

int sub_02159750(void *ctx, void *script)
{
    void *obj = sub_0201296C(sub_0215A5E4(script));

    sub_0201433C(obj, sub_02159B10(ctx, script));

    return 0;
}

int sub_0215B328(void *ctx, void *script)
{
    void *obj = sub_0201296C(sub_0215A5E4(script));

    sub_0215A4EC(obj, sub_02159B10(ctx, script));

    return 0;
}

int sub_0215B350(void *ctx, void *script)
{
    void *obj = sub_0201296C(sub_0215A5E4(script));

    sub_0215A500(obj, sub_02159B10(ctx, script));

    return 0;
}

/* ---- F1: three-deep void chain -------------------------------------- */

int sub_0215AFE0(void *ctx, void *script)
{
    sub_0200CA28(sub_0200CA1C(sub_0215A5E4(script)));

    return 0;
}

int sub_0215B014(void *ctx, void *script)
{
    sub_0200CA40(sub_0200CA1C(sub_0215A5E4(script)));

    return 0;
}

int sub_0215B5A8(void *ctx, void *script)
{
    sub_0201BA34(sub_02012934(sub_0215A5E4(script)));

    return 0;
}

int sub_0216F8C8(void *ctx, void *script)
{
    sub_021F385C(sub_0201210C(sub_0215A5DC(script)));

    return 0;
}

/* ---- F2: two-deep void chain ---------------------------------------- */

int sub_0215C6F0(void *ctx, void *script)
{
    sub_02158FBC(sub_0215A5F4(script));

    return 1;
}

int sub_0215F228(void *ctx, void *script)
{
    sub_020121CC(sub_0215A5DC(script));

    return 1;
}

int sub_0216CC30(void *ctx, void *script)
{
    sub_0216CC40(sub_0215A5DC(script));

    return 0;
}

int sub_0216F8B8(void *ctx, void *script)
{
    sub_0216F900(sub_0215A5DC(script));

    return 0;
}

int sub_0215C5EC(void *ctx, void *script)
{
    void *obj = sub_0215A5F4(script);

    sub_0215897C(obj, sub_020145CC(sub_0215A5DC(script)));

    return 1;
}

int sub_0216B7F8(void *ctx, void *script)
{
    void *obj = sub_0215A5F4(script);

    sub_0215897C(obj, sub_021670F8(sub_0215A5DC(script)));

    return 1;
}

int sub_0216F8DC(void *ctx, void *script)
{
    void *obj = sub_0215A5F4(script);

    sub_0215897C(obj, sub_021F38BC(sub_0215A5DC(script)));

    return 1;
}

int sub_0215CE98(void *ctx, void *script)
{
    u16 *dest = sub_02159AE8(ctx, script);

    *dest = sub_021C3400(sub_02188D50(sub_0201210C(sub_0215A5DC(script))));

    return 0;
}

int sub_0215CFB4(void *ctx, void *script)
{
    u16 *dest = sub_02159AE8(ctx, script);

    *dest = sub_021C340C(sub_02188D50(sub_0201210C(sub_0215A5DC(script))));

    return 0;
}

int sub_0215CFD8(void *ctx, void *script)
{
    u16 *dest = sub_02159AE8(ctx, script);

    *dest = sub_021C34C4(sub_02188D50(sub_0201210C(sub_0215A5DC(script))));

    return 0;
}
