/* ov009 sub_0215592C  (0x0215592C, 340 bytes) -- WALL, 323/340.
 * Belongs in src/ov009/dwc_rap.c (0x0215539C..0x02156E2C), whose declarations
 * this file reuses.  THUMB (ov009 is Thumb only below 0x02157170).
 *
 * RETRIED 2nd wave.  Structure, switch layout, jump table, every block, every
 * instruction and every immediate are byte-exact.  The only 17 bytes that
 * differ are the four "store an error code into *(u32 *)(_021A8264 + 0x758)"
 * sites (case 9 -> 1000, case 11 -> 1001, case 13 -> 1002, case 6 -> 1007),
 * and at each of them the INSTRUCTION ORDER is also identical -- only the
 * register numbers rotate:
 *     case 11  ROM   value->r0, ptr->r2, offset->r1   (str r0,[r2,r1])
 *              mwcc  value->r2, ptr->r1, offset->r0   (str r2,[r1,r0])
 * The ROM puts the stored value in r0; mwcc puts it in the last-allocated
 * scratch register.
 *
 * RULED OUT THIS WAVE:
 *  - Compiler build.  All 24 mwccarm builds swept (--thumb; 1.2/* need -ipa
 *    dropped).  Every dsi build gives exactly 323/340; 2.0/* gives 124/356.
 *  - The shared-struct theory in the previous note is WRONG.  Declaring
 *    `Rap *_021A8264` with real fields and writing `_021A8264->error = 1001;`
 *    produces byte-for-byte the same 323/340.  (Hoisting the struct pointer
 *    into a local first is much worse, 32/312, because it defeats the
 *    per-case reload of the global.)  include/ov009.h's Ov009RapAlloc is a
 *    different object -- it is the allocator behind the pointer at
 *    0x021A8268, not this work block.
 *  - A u32 temp for the value; a u8 * temp for the base; both temps in either
 *    order; `((u32 *)_021A8264)[0x758 / 4]`; a `static inline` setter taking
 *    the value, and one taking (value, base); a separate `u32 *q` lvalue.
 *
 * What is left is a pure register-allocation preference, the same class of
 * wall as ov114 sub_021BA150 / sub_021BA448 / sub_021BF1B0.
 */


void sub_0215592C(int param0)
{
    sub_02155B68();

    switch (*(u32 *)(_021A8264 + 0x754)) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        sub_021554C8();
        return;
    case 7:
        if (param0 != 0) {
            sub_02155374(8);
        }

        if (*(u32 *)(_021A8264 + 0x75C) == 2 && *(s32 *)(_021A8264 + 0x770) >= 0
            && _021A8264[*(s32 *)(_021A8264 + 0x770) + 0x32C] != 6) {
            sub_02155374(12);
        }

        break;
    case 8:
    case 12:
        sub_0216B65C();
        sub_02155904();
        break;
    case 9: {
        u8 *v0 = sub_0203D798();

        if (*(s16 *)(_021A8264 + 0x782) != 0) {
            sub_02156344(*(u16 *)(v0 + 0x56));
        }

        *(u16 *)(_021A8264 + 0x794) = 0;
        sub_02155374(10);
        *(u32 *)(_021A8264 + 0x758) = 1000;
        return;
    }
    case 11:
        sub_02155374(6);
        *(u32 *)(_021A8264 + 0x760) = 0;
        *(s32 *)(_021A8264 + 0x774) = -1;
        *(u32 *)(_021A8264 + 0x758) = 1001;
        return;
    case 13:
        sub_02155374(6);
        *(u32 *)(_021A8264 + 0x760) = 0;
        *(s32 *)(_021A8264 + 0x774) = -1;
        *(u32 *)(_021A8264 + 0x758) = 1002;
        return;
    case 14:
        sub_02155F58();
        return;
    case 18:
        if (*(u32 *)(_021A8264 + 0x76C) == 0) {
            sub_0216B65C();
            sub_02155374(19);
            break;
        }
        /* fall through */
    case 6:
        if (sub_021561C0() == 0) {
            *(u32 *)(_021A8264 + 0x758) = 1007;
        }

        return;
    default:
        break;
    }

    sub_021561C0();
}
