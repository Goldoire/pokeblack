# Worker guide — the proven loop

Read `SWARM_PROMPT.md` for strategy and the traps. This file is the mechanics,
and every command in it has been run and verified in this repo. Follow it
literally; do not invent a different build path.

Working directory for every command: `C:\Users\pranav\decomp\pokeblack\repo`.

## The loop

**1. Pick a function.** Your assignment names a module and (for `main`) an
address range. Use the triage table, not the raw claim table:

```bash
python -c "
import json
t=json.load(open('build/reference/triage.json'))
m=[f for f in t['ov021'] if f['status']=='unclaimed' and f['kind']=='thumb' and f['size']<=64]
m.sort(key=lambda f:f['size'])
for f in m[:30]: print(f['name'], hex(f['ram']), f['size'])"
```

`kind` is `thumb` / `arm` (real C — work these), or `veneer` / `trivial` /
`data` (linker stubs and misidentified data — **skip them**, they are not C and
cannot be written as C). Prefer small functions and functions adjacent to ones
you have already matched: neighbours share structs and idioms, so the second
function in a file is much cheaper than the first.

**2. Look at the bytes.**

```bash
python tools/scripts/fn.py ov021 0x021d0f00
```

Prints the file offset, the instruction set, the raw bytes, and an annotated
disassembly with call targets resolved against the claim table. Sizes in the
claim table are prologue-heuristic estimates — trust the start address and read
the bytes to find the real end (the function's literal pool counts as part of
it). Pass an explicit size as a third argument to override.

**3. Write C.** One contiguous address range per file:

- `main` → `src/main/<area>.c`
- overlay → `src/ov021/<area>.c`

Name the function for its address so the verifier can find its home:
`sub_021D0F00`. Unknown callees are `sub_<realRAM>`, data is `_<realRAM>`; the
verifier resolves both by name. Addresses are **real RAM** (the `ram` field in
the claim table) — never the Ghidra file-offset base.

```c
#include "types.h"

void sub_020055F8(void)
{
    sub_02034F5C();
}
```

**4. Compile and verify.**

```bash
python tools/scripts/cc.py src/ov021/field.c --thumb
python tools/scripts/verify_functions.py ov021/field
```

**Check the mode before you compile; do not assume Thumb.** Getting it wrong
produces a 0% match, not a near-miss. 81% of the game is Thumb, but whole
regions are not, and they are not marked on a map you can guess from:

- `main` 0x02023FD8–0x0204A39C is ARM — 359 of 364 entries. Compile with no
  `--thumb`. Only 0x02023FD8–0x0202744C at the bottom is Thumb.
- `ov114` is ARM, 368 of 424 entries: it is linked GameSpy/DWC library code.
- `ov009` is Thumb only for its first ~8 KB (0x02155160–0x02157170, Game
  Freak's own code); everything above that is ARM DWC/GameSpy library code.

`fn.py` prints the mode per function, and `triage.json` records it per entry.
Read one of them first. The argument to the verifier is any substring of the
object path, so you see only your own work.

Done means `N/N OK`. Anything else is not progress and is never committed to
`src/`.

**5. Iterate.** The verifier prints the offset of the first differing byte;
`fn.py` shows you what the ROM has there. Standard CodeWarrior matching lore
applies: order of evaluation, `do/while` vs `while`, ternary vs `if`, `s16`/`u8`
casts at assignment, `volatile` for hardware and for loads the compiler wants
to hoist, early `return` vs a single exit, and struct field offsets. Change one
thing at a time.

## Matching lore, paid for by wave 1

Each of these cost an agent multiple attempts. Reach for them before grinding.

**Shape of the source**
- An early `return` compiles to *predicated* instructions. If the ROM branches
  forward to a shared exit instead, the source is `if (cond) { body } return 0;`
  — not `if (!cond) return 0;`.
- `if (x) return FALSE; return TRUE;` never emits `beq/0/1` with an `int`
  return; CW canonicalises to `bne/1/0`. It preserves source order when the
  return type is an **enum** or a pointer.
- `return f(...)` from a frameless function tail-calls as `ldr r3,=target|1;
  bx r3`, not `bl`. A one-line forwarder with ≤3 args does this; with 4 args
  CW cannot spare r3 and emits `push/bl/pop`. Those are free 8-byte matches,
  not linker veneers.
- An `if/else if` chain and a `switch` over the same cases lower differently.
  A dead 4th `case` label flips CW from a linear chain to a binary search.
  Dense switches need every case in `[0..max]` written out, and `default:`
  is emitted in its source position.

**Types**
- `lsls #29 / lsrs #31` after `ldrb` is a `u8 x:1` **bitfield** read, not a
  shift-and-mask. Bitfields are LSB-first and are the only way to get the
  `bic`/`orr` write idiom. A mask constant materialised fresh at each use
  instead of hoisted is the tell.
- `& 0x3FFF` gives an AND with a literal; a `u16 x : 14` bitfield gives the
  `lsl #18 / lsr #18` pair.
- One `volatile` field stops CW from CSE-ing a value the ROM re-loads.
  Store-then-reload of the same field means volatile; no reload across an
  out-pointer store means the struct pointer is `const`.
- A bitfield setter taking a **wider** parameter than the field's base type is
  what reproduces the ROM's truncation (`u32 a` where you expected `u16 a`).

**Placement and allocation**
- Stack locals are laid out first-declared-highest. Reverse declaration order
  to move a local from `sp+0` to `sp+0x10`.
- Declaring a temp inside an inner `{ }` block changes register allocation.
- Reassigning a *parameter* pins it to a callee-saved register at entry.
- Globals must be `extern <type> _020AAxxx;`, never `(T *)0x020AAxxx` — a cast
  constant lets CW fold `base+offset` into the literal.
- `arr[i].field`, not `((u8 *)p)[i * size + off]`.
- Split call arguments into sequenced locals when the ROM loads a field before
  the call: `v = p->x; h = g(a); f(h, v);`.
- Zeroing a local `VecFx32` before passing its address: the type-punned alias
  `u32 *q = (u32 *)&v; q[0] = q[1] = q[2] = 0;` is what matches.

## Rules

- **Never run git.** The coordinator commits. Twenty agents sharing one index
  is a lock fight, and your module's files never collide with anyone else's.
- **Never touch shared state**: `include/`, `symbols.txt`,
  `build/reference/functions.json`. If you need a struct, a global, or an enum,
  send the integrator agent a proposal with the evidence — which functions
  constrain which offsets and what the accesses look like. Until it lands, use
  a local `struct UnkStruct021D0F00` in your own file, or raw pointer
  arithmetic. Never define a struct that already exists in `include/`.
- **Never extend `src/*.c`** (the 35 legacy top-level files). That is
  unverified Ghidra pseudo-C; exactly one function in it matches. Read it for
  hints, never build on it.
- **Never report a near-miss as a match.** 97% is 0%.
- **Ten serious attempts, then move on.** Write the best attempt to
  `build/attempts/<module>/<name>.c` with a one-line note on what differs, and
  pick a different function.

## Translation oracle

`C:\Users\pranav\decomp\pokeheartgold` is the pret Gen 4 decomp (389 matched
`.c` files, 564 headers). Gen 5 is an evolution of that engine and many
functions are recognizable ports — same shape, extra fields. Grep it for the
call pattern you are looking at before writing anything from scratch, and reuse
its naming when a function clearly corresponds. Its `include/` is also the best
available guess for struct layouts; propose those to the integrator rather than
copying them in silently.

## Known-good reference matches

Three hand-written functions verify today; read them for the house style:
`src/main/unk_02005230.c`, `src/main/unk_0200566C.c`, `src/main/unk_020055F8.c`.

## Settled questions — do not re-investigate

- Game code is Thumb. `cc.py --thumb` is the flag set; it is already correct.
- Recompiling the SDK as Thumb does **not** unlock SDK matches inside overlays.
  It was swept (`sdk_sweep.py --thumb`) and yields 31 new placements / 760
  bytes against the ARM sweep's 638. That side quest is closed.
- The verifier reproduces the linker's interworking: Thumb→ARM calls become
  `BLX(1)`, ARM→Thumb calls become ARM `BLX`, and a pointer to a Thumb function
  has bit 0 set. If a call site still mismatches, the bug is in your C, not in
  the verifier.
- `dsd rom extract` does not work on this dump. Use the repo's scripts.

## Reporting back

Report only verified counts: how many functions and how many bytes now pass
`N/N OK` in your module, and which addresses. `python tools/scripts/progress.py`
gives the authoritative per-module table. List the walls you banked separately.
