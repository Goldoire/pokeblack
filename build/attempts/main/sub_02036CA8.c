/* sub_02036CA8 @ 0x02036CA8, 188 bytes, ARM, module main.
   Best attempt: 160/188 (85%), first differing byte +0x39.
   Every instruction matches one-for-one; the only difference is register
   allocation inside the `o->unk0F == 1` arm: the ROM loads o->unk06 into r3
   (the accumulator that the else-arm also uses for 0x40000200) and o->unk04
   into ip, while MWCC here does the reverse and moves the result into r3 with
   the final ORR.  Tried: separate a/b temps vs stores inlined into both arms,
   all 24 permutations of the local declaration order, u16 vs u32 for the
   attr2 value, and four orderings of the OR chain / shift form.  The
   o->unk10 write-back needed a cached local pointer (two reloads, not four) -
   that part is already correct below.
*/
void sub_02036CA8(UnkStruct02036D64 *o)
{
    u32 d = sub_02036D64(o);
    u32 x = sub_02036DC8(d, o->unk00);
    u32 *oam;
    u32 *q;

    if (d == 1) {
        oam = (u32 *)0x07000000;
    } else {
        oam = (u32 *)0x07000400;
    }
    if (o->unk0F == 1) {
        oam[0] = (o->unk06 & 0xFF) | 0x800 | 0x40000000 | ((o->unk04 & 0x1FF) << 16);
        *(u16 *)((u8 *)oam + 4) = x | 0xE000;
    } else {
        oam[0] = 0x40000200;
        *(u16 *)((u8 *)oam + 4) = 0;
    }
    oam[2] = (o->unk06 & 0xFF) | 0x40000000 | ((o->unk04 & 0x1FF) << 16);
    *(u16 *)((u8 *)oam + 0xC) = x | 0xE000;
    if (oam != (u32 *)o->unk10) {
        q = (u32 *)o->unk10;
        q[0] = 0x40000200;
        *(u16 *)((u8 *)q + 4) = 0;
        q = (u32 *)o->unk10;
        q[2] = 0x40000200;
        *(u16 *)((u8 *)q + 0xC) = 0;
        o->unk10 = (u32)oam;
    }
}
