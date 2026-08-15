# The "unspecialised loop entry test" wall — investigation result

Worker `compiler-hunt`, 2nd wave. Targets:

- `build/attempts/ov094/sub_021FFD6C.c` (48 ROM bytes, best 44)
- `build/attempts/ov094/sub_02200608.c` (76 ROM bytes, best 72)
- `build/attempts/ov135/sub_021F8908.c` (72 ROM bytes, best 40)

## Verdict

**The hypothesis "the ROM's compiler propagates a loop induction variable's
initial value into the loop guard less aggressively than any build we have" is
FALSE. It is not a compiler-build question and it is not an optimisation-flag
question. Do not sweep compilers for this again.**

The three walls are a *source* question, and the remaining unknown is narrow and
precisely stated below. I did not crack it; the walls stand.

## Two decisive pieces of evidence against the compiler hypothesis

**1. One ROM function contains both shapes.** `func_02206E28` (ov094) has two
constant-count loops, compiled by one compiler with one flag set in one pass:

```
02206e2a: movs r4,#0        <- loop 1: guard KEPT, unspecialised
02206e2c: adds r5,r0,#0
02206e2e: cmp  r4,#8
02206e30: bge  0x2206e48
   ... body: two calls taking (sys, i) ...
02206e46: blt  0x2206e32

02206e5e: movs r4,#0        <- loop 2: guard DELETED, same function
02206e60: lsls r0,r4,#2        (mwcc's own -O4,p output shape)
   ...
02206e6e: blt  0x2206e60
```

No compiler build or flag can produce a different answer for two loops in the
same function. The difference has to be in how the two loops were spelled.

**2. ROM-wide census.** A byte scan of every module in `build/reference`
(`movs rN,#0` reaching a loop whose bottom test is `cmp rN,#imm ; b<cond>`):

| shape | count |
|---|---|
| guard folded away (what every mwccarm build emits) | **1698** |
| guard kept, compared against the counter register | **12** |
| loop entered by `b` to the bottom test, no guard at all | **1** |

The ROM's compiler folds `0 < N` at the loop guard 1698 times out of 1710. It
behaves exactly like `tools/mwccarm` does. The 12 + 1 exceptions are the
anomaly, not the rule.

The 12 unfolded-guard sites (each is a wall of the same kind):

```
main   0x02007126 0x0200E0BE 0x02010DCC 0x02010DF6 0x02010F18 0x0202BB02
ov094  0x021FC78C 0x021FE4FA 0x021FE522 0x021FEB7A 0x021FFD6E 0x02206E2A
```
(plus `0x021FC7B4`, which is the same idiom with `movs r4,#8` as the initial
value, and `0x022077AE` in ov195 under a looser scan.)

The single un-rotated site is `ov135 0x021F8922` — i.e. `sub_021F8908`, one of
the walls, is a **one-of-one** in the entire ROM.

## Best reduced test case — use this, not the three walls

`main 0x02010DF4` is the same wall in 28 bytes with no parameters, no struct, no
confounds. It is the cheapest possible probe:

```c
extern UnkStruct02146228 _02146228;      /* u8 unk1C at +0x1C */
void sub_02010F50(int a0);

void sub_02010DF4(void)
{
    int i;
    for (i = 0; i < 13; i++) { sub_02010F50(i); }
    _02146228.unk1C = 13;
}
```

Everything matches except the 4-byte guard:

```
EMITTED (28B, mwcc -O4,p)          ROM (32B)
push {r4,lr}                       push {r4,lr}
movs r4,#0                         movs r4,#0
                                   cmp  r4,#0xd          <- the whole
                                   bge  0x2010e08        <- difference
adds r0,r4,#0                      adds r0,r4,#0
bl   sub_02010F50                  bl   sub_02010F50
adds r4,r4,#1                      adds r4,r4,#1
cmp  r4,#0xd                       cmp  r4,#0xd
blt  .body                         blt  .body
ldr  r0,=_02146228                 ldr  r0,=_02146228
movs r1,#0xd                       movs r1,#0xd
strb r1,[r0,#0x1c]                 strb r1,[r0,#0x1c]
pop  {r4,pc}                       pop  {r4,pc}
```

The neighbouring case `main 0x02010DCC` additionally shows the loop-invariant
`ldr r2,=_021461E8` sitting in the **preheader**, between the guard and the loop
body. That is LICM, which only happens at `-opt level>=3` — so these functions
are high-optimisation output that kept a guard, not low-optimisation output.

## The mechanism, established by probe

mwcc keeps the loop-entry guard, comparing the counter *register*, exactly when
the induction variable's initial value is **not a compile-time constant** at the
loop pass. Demonstrated (dsi/1.1, `-O4,p`, Thumb):

```c
static int sStart = 0;                       /* file static, never written */
void f(void) { int i; for (i = sStart; i < 13; i++) g(i); }
```
emits precisely the ROM's shape, with `ldr r4,[r0]` where the ROM has
`movs r4,#0`:
```
ldr r0,=sStart / ldr r4,[r0] / cmp r4,#0xd / bge end / ...body... / cmp r4,#0xd / blt
```
Same for `for (i = param; ...)` and `for (i = h(); ...)`.

**So the missing piece is a source spelling that makes the initial value opaque
to mwcc's propagation while still materialising as `movs rN,#imm`.**

## What was ruled out (do not redo)

Everything below was run against the 28-byte reduced case and/or the three
walls, Thumb, verified byte-for-byte.

**Compiler builds.** All 24 in `tools/mwccarm` (`1.2/{base,sp2,sp2p3,sp3,sp4}`,
`2.0/{base,sp1,sp1p2,sp1p5,sp1p6,sp1p7,sp2,sp2p2,sp2p3,sp2p4}`,
`dsi/{1.1,1.1p1,1.2,1.2p1,1.2p2,1.3,1.3p1,1.6sp1,1.6sp2}`), each with and
without `-ipa file`, each crossed with `-O0/-O1/-O2/-O3/-O4` × `{,p}`. **No
build emits the guard at any level >= 3.** The `1.2/*` builds do compile once
`-ipa file` is dropped; `1.2/{base,sp2,sp2p3}` emit 32 bytes for the reduced
case, but the extra 4 bytes are an ARMv4T `pop {r4}/pop {r3}/bx r3` epilogue,
not the guard. Version gaps relative to what CodeWarrior shipped are only the
`1.1/*` series and `1.2/sp1`, `1.2/sp2p2` — all *older* than 2.0/dsi, and
irrelevant given evidence (1) above.

**Optimisation sub-options are no-ops.** `-opt [no]cse / [no]prop / [no]loop /
[no]strength / [no]deadcode / [no]deadstore / [no]lifetimes` produce
**bit-identical** output at every level. Verified exhaustively: levels 1-4 ×
{speed,space} × all 1- and 2-element subsets of those seven keywords — every
combination at a given `level,space|speed` gives the same bytes. The compiler's
own `-help` says so ("superceded by use of `-opt level=xxx`"); it is literally
true. Only `level=` and `space|speed` do anything.

**Pragmas.** `#pragma opt_propagation / opt_loop_invariants /
opt_strength_reduction / opt_unroll_loops / opt_vectorize_loops /
opt_common_subs / opt_dead_code / opt_dead_assignments / opt_lifetimes /
peephole / global_optimizer / scheduling / opt_pointer_analysis` — all no-ops.
Only `#pragma optimization_level N` and `#pragma optimize_for_size on` change
anything, and they are exactly equivalent to `-opt level=N` / `-opt space`.

**Every other flag.** `-ipa off|function`, `-inline off|auto|all|deferred|
noauto`, `-sym off|on|full`, `-g`, `-lang c89|c++`, `-gccext off`, `-enum min`,
`-char unsigned`, `-nointerworking`, `-proc arm7tdmi|v5te|arm926ej`, `-rostr`,
`-constpool|-noconstpool`, `-align8`, `-pic`, `-pid`, `-strict on`,
`-ansi strict`, `-relax_pointers`, `-sdatathreshold 0`. None affect the guard.

**A lower `-O` level for the whole TU.** This is the one that looks tempting and
is *disproved by the neighbours*:

- `src/ov094/btlv_mcss_021FFCB0.c` — the TU that owns `sub_021FFD6C`
  (`sub_021FFCB0` at 0x021FFCB0 and `sub_021FFD9C` at 0x021FFD9C bracket it) —
  is **10/10 OK at `-O4,p`**; at `-O1` 3 functions break, at `-O2` 5 break.
- `src/ov135/unk_021F7F14.c` — the TU that owns `sub_021F8908`
  (`sub_021F87E0` and `sub_021F89B4` bracket it) — is **17/17 OK at `-O4,p`**;
  at `-O2`, `sub_021F87E0` and `sub_021F89B4` break.

Both TUs are `-O4,p`, settled.

**Source spellings that all fold the guard** (all give byte-identical output to
the plain `for`): `while`; `do/while`; `goto` to a bottom test; `while(1)+break`;
`i = 0; if (i < N) do {...} while (i < N);` (the guard written by hand);
`!(i<N)`; `N>i`; `i<=N-1`; `!=` bound; pre-increment; C99 `for (int i = 0; ...)`;
counter as a struct member / union member / array element / `long` / `register`;
counter reused by a second loop; counter's address taken; two counters; comma
init; bound from `enum` / `#define` / `static const int` / `const int` /
`sizeof` / `static const` array element / `static const` struct member;
init from `static const` scalar/array/struct member / `(int)(void*)0`;
constant argument reaching the loop through an inlined or static helper
(`-inline on,noauto` inlines it and then folds).

Spellings that *do* keep the guard but emit a load or a register copy instead of
`movs` (so they are the mechanism, not the answer): init from a non-const
`static`, from an `extern`, from a parameter, from a call, from a `volatile`.

## The surviving hypothesis

> The ROM's C initialises these loop counters with something that mwcc's
> propagation treats as opaque at the loop-optimisation pass but that later
> materialises as an immediate `movs rN,#imm`. It is a per-loop property of the
> source, not a per-file or per-compiler one.

Supporting shape detail worth keeping: in the two ov094 walls the ROM emits
`movs r4,#0` **before** the parameter copy `adds r5,r0,#0`. Every mwcc output
we can produce emits the parameter copy first, at any level. Whatever produces
the guard very likely also explains that ordering — treat them as one clue, not
two.

Note also `ov094 0x021FC78C`: the same function has two guarded loops, the
second starting at 8 (`movs r4,#8 / cmp r4,#0xe / bge`). So the construct is not
specific to a zero start.

## How the next person should test it

1. Work on `main 0x02010DF4` (28 vs 32 bytes, no parameters), not on the three
   walls. Iterate with:
   ```
   python tools/scripts/cc.py <file> --thumb
   python tools/scripts/verify_functions.py <module>
   ```
2. Success criterion: `-O4,p`, `dsi/1.1`, Thumb, emitted size 32, `32/32 OK`.
   Anything that needs a different `-O` level is wrong — the neighbouring TUs
   prove the level.
3. Promising unexplored directions, in order:
   - a value that mwcc folds *after* the loop pass: address arithmetic that
     cancels, an `__asm`/`asm { }` barrier, a `#pragma` GF may have used that we
     have not guessed;
   - `-ipa program` (link-time IPA), which we cannot run from `cc.py` today and
     which is the only IPA mode untested;
   - a header in the real build that defines the loop as a macro with an
     unusual expansion — look for a shared `for` macro in the pret Gen-4 oracle
     at `C:\Users\pranav\decomp\pokeheartgold`.
4. When it is found, it unlocks at least 13 known ROM sites at once. Re-run the
   census scan to find the rest.

## Best current state of the three walls

Unchanged. The banked attempts remain the best known:

| function | best | note |
|---|---|---|
| `ov094/sub_021FFD6C` | 44 of 48, 4 bytes short | body and registers exact |
| `ov094/sub_02200608` | 72 of 76, 4 bytes short | body and registers exact |
| `ov135/sub_021F8908` | 40/72 | do/while form; registers exact |

Diagnostic only, not a fix: with the guard written by hand in the source
(`i = 0; if (i < N) do {...} while (i < N);`) and `-O1`, `sub_021FFD6C` reaches
**44/48 byte-aligned** and `main 0x02010DF4` reaches **28/32** — in both cases
the *only* remaining difference is a two-instruction ordering in the entry
block. That is the closest anyone has got, and it is not usable, because `-O1`
is disproved for these TUs by their neighbours. Record it only as a hint about
what the correct `-O4,p` construct must look like.

## Also ruled out (coordinator, after the investigation above)

**Loop variable live after the loop.** The reproducer's trailing store writes a
literal 13, but the source could have written the counter's exit value —
liveness past the loop is a plausible reason the specialiser would leave the
guard alone, while the value still folds to an immediate:

```c
int i;
for (i = 0; i < 13; i++) { sub_02010F50(i); }
_02146228.unk1C = i;          /* instead of = 13 */
```

Result: **4/28, first diff +0x4** — substantially worse than writing the
literal (28/32). mwcc folds the exit value and specialises anyway. Not the
answer; do not retry.
