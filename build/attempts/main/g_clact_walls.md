clact.c holdouts (worker main-game).  All four are one scheduling/allocation
decision away; swept all 24 mwccarm builds (tools/scripts/cc.py --cc) and every
build produces the identical wrong code, so it is the C, not the compiler.

sub_0204B49C  63/76   `asr r6,r0,#0x10; mov r1,r6` in ROM, `asr r1,r0,#0x10`
              in mine -- ROM keeps the s16 result in the parameter's home
              register.  Tried: s16 param reassigned, separate s16 local,
              int param + explicit (s16) cast, declaration reordering.
              Best C:
              void sub_0204B49C(GClact *act, s16 v, u32 a2, u32 which) {
                  GClactVec2 off;
                  sub_0204CF74(act, a2, &off);
                  if (which == 0) v = v + off.x; else v = v + off.y;
                  sub_0204B550(act, v, which);
              }

sub_0204B658  28/48   ROM keeps the bitfield value in r0 and the boolean in r1,
              joining both arms on one `movne r1,#1; mov r0,r1`.  Mine
              duplicates `movne r0,#1` per arm.  Tried: two returns, shared
              local, `t != 0`, ternary in the condition, declaration order.

sub_0204B728  52/60   } identical problem: ROM emits `ldm r4!,{r0-r3}` BEFORE
sub_0204B784  60/68   } `add ip,r5,#0x40`; mwcc schedules the destination
              address first.  Body is certainly
                  sub_0206380C(src, 1); sub_0206380C(src, 2);
                  act->unk40 = *src;      /* 5-word struct assignment */
              Tried array-typed vs named-member blob structs, const on the
              source, both parameter orders.

sub_0204D0C4  33/60   ROM stashes the type in ip (`mov ip,r0`) and sinks the
              `str ip,[anim]` to immediately before the indirect call, after
              every argument register is loaded.  mwcc always hoists the store
              ahead of the vtable load.  Tried: separate `type`/`fn` locals,
              `anim->type = f(hdr); table[anim->type](...)`, and reading the
              field back for the index.  Best C:
              void sub_0204D0C4(GClactAnim *anim, const GClactResHeader *hdr,
                                u16 a2) {
                  u32 type = sub_0204D134(hdr);
                  void (*fn)(GClactAnim *, const GClactResHeader *, u16)
                      = _020A13DC[type];
                  anim->type = type;
                  fn(anim, hdr, a2);
              }

Note: the same "explicit temporaries force the ROM's register allocation"
trick that fixed sub_0204B09C (load both s16 fields into named s32 locals
before forming the destination pointer) was tried on sub_0204B49C and did not
help there.
