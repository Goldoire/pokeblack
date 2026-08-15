#include "types.h"

/* 0x020A9E80: { u32 unk00; void (*unk04)(void); u32 unk08; }.
 * sub_02005328 writes all three through one base literal and then hands
 * &unk04 to sub_020053E4; sub_020053EC tests unk00. */
typedef struct Unk020A9E80
{
    /* 0x00 */ u32 unk00;
    /* 0x04 */ void (*unk04)(void);
    /* 0x08 */ u32 unk08;
} Unk020A9E80;

extern Unk020A9E80 _020A9E80;
extern u8 _020A9E94[];

#define reg_OS_IME (*(volatile u16 *)0x04000208)

void sub_02086368(void);
void sub_02086FE8(void);
void sub_02087208(void);
void sub_02088788(void);
void sub_0207D204(void);
void sub_0207D148(void);
u32 sub_02085CBC(void);
void sub_0208C988(int a0);
void sub_0207AD04(int a0);
u32 sub_0207ACB4(u32 a0, u32 a1);
u32 sub_02086788(u32 a0, u32 a1, u32 a2);
void sub_02061C0C(void *a0, int a1);
int sub_0202EB0C(void);
/* The word the ROM stores is 0x02005441: the Thumb entry point of the
 * function at 0x02005440, address | 1. triage.json has no entry for
 * 0x02005440 (it sits between two linker veneers and the prologue scan
 * missed it), so the verifier cannot know to set that bit for a
 * `sub_02005440` function symbol -- naming the datum directly is what makes
 * the literal come out byte-identical. Replace with &sub_02005440 once
 * triage records 0x02005440 as thumb. */
extern u8 _02005441[];
void sub_020053E4(void *a0);
void sub_0208C030(u32 *a0);
void sub_0208BEF0(int a0);

void sub_02005328(void)
{
    u32 amp;
    u32 tmp;

    sub_02086368();
    sub_02086FE8();
    sub_02087208();
    sub_02088788();
    sub_0207D204();
    sub_0207D148();
    if ((sub_02085CBC() & 0x03000000) != 0)
    {
        sub_0208C988(1);
        *(volatile u32 *)0x04004008 &= ~0x2000;
        *(volatile u32 *)0x02FFFDF0 &= ~0x2000;
    }
    {
        u16 prep = reg_OS_IME;
        reg_OS_IME = 1;
    }
    sub_0207AD04(1);
    tmp = sub_0207ACB4(0, 0);
    sub_0207ACB4(sub_02086788(0, tmp, 4), tmp);
    sub_02061C0C(_020A9E94, 0x30);
    if (sub_0202EB0C() != 0)
    {
        _020A9E80.unk00 = 0;
        _020A9E80.unk04 = (void (*)(void))_02005441;
        _020A9E80.unk08 = 0;
        sub_020053E4(&_020A9E80.unk04);
    }
    sub_0208C030(&amp);
    if (amp == 1)
    {
        sub_0208BEF0(0);
    }
}
