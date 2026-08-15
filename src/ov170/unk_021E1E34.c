#include "types.h"

typedef struct Ov170Panel {
    u8 unk00[0x8c];
    void *unk8c;
} Ov170Panel;

typedef struct Ov170Ctx {
    u8 unk00[0x2c];
    Ov170Panel *unk2c;
} Ov170Ctx;

typedef u32 (*Ov170StateFn)(Ov170Ctx *);

extern Ov170StateFn const _021EFA7C[];

u32 sub_0201C6B4(void *a0);
void sub_021EAB50(Ov170Panel *a0);
void sub_021EBF74(Ov170Panel *a0);

u32 sub_021E1E34(Ov170Ctx *a0, u32 *a1)
{
    if (a0->unk2c == NULL || a0->unk2c->unk8c == NULL
        || sub_0201C6B4(a0->unk2c->unk8c) != 0) {
        *a1 = _021EFA7C[*a1](a0);
    }
    if (*a1 == 0x69) {
        return 0;
    }
    if (a0->unk2c != NULL) {
        sub_021EAB50(a0->unk2c);
        sub_021EBF74(a0->unk2c);
    }
    return 1;
}
