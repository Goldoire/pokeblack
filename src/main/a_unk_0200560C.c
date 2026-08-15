#include "types.h"

/* Global "main" record at 0x020AA194.
 *
 * Constrained by: sub_0200566C (clears +0x00 and +0x08), sub_02005640
 * (calls +0x08 with +0x00 as its only argument), sub_02005654 (installs
 * that pair), sub_0200567C (increments +0x0C once per frame), and
 * sub_02005610 / sub_020056BC (load the pointer at +0x10 then read +0x18 /
 * +0x20 out of it).
 */
typedef struct MainSub
{
    /* 0x00 */ u64 unk00;
    /* 0x08 */ u64 unk08;
    /* 0x10 */ u64 unk10;
    /* 0x18 */ void *unk18;
    /* 0x1C */ u32 unk1C;
    /* 0x20 */ void *unk20;
} MainSub;

typedef struct MainRec
{
    /* 0x00 */ void *cbArg;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ void (*cb)(void *);
    /* 0x0C */ u32 frameCount;
    /* 0x10 */ MainSub *unk10;
} MainRec;

extern MainRec _020AA194;
#define gMainRec _020AA194

void sub_02030D28(void *a0);
void sub_020419E4(void);
void sub_02050A70(void);
void sub_0204E638(void);

void sub_0200560C(void)
{
}

void sub_02005610(void)
{
    sub_02030D28(gMainRec.unk10->unk18);
}

void sub_02005640(void)
{
    if (gMainRec.cb != NULL)
    {
        gMainRec.cb(gMainRec.cbArg);
    }
}

int sub_02005654(void (*cb)(void *), void *arg)
{
    if (gMainRec.cb != NULL)
    {
        return 0;
    }
    gMainRec.cb = cb;
    gMainRec.cbArg = arg;
    return 1;
}

void sub_0200567C(void)
{
    sub_02030D28(gMainRec.unk10->unk20);
    sub_020419E4();
    sub_02050A70();
    sub_0204E638();
    gMainRec.frameCount++;
}

void *sub_020056BC(void)
{
    return gMainRec.unk10->unk20;
}
