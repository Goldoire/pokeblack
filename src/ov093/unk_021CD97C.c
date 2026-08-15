#include "types.h"

// ov093 0x021cd97c: indirect dispatch through a callback slot at +0x28.
typedef struct UnkDispatch021CD97C {
    /* 0x00 */ u8 unk_00[0x28];
    /* 0x28 */ void (*unk_28)(struct UnkDispatch021CD97C *a0);
} UnkDispatch021CD97C;

void sub_021CD97C(UnkDispatch021CD97C *p)
{
    p->unk_28(p);
}
