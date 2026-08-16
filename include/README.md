# `include/` — shared state, and what is actually known

**Owned by the integrator agent.** Workers never write here (WORKER_GUIDE.md,
"Never touch shared state"). Send struct proposals to the coordinator with the
evidence — which functions constrain which offsets, and what the accesses look
like — and they land here verified.

This file is the ledger: what is verified, what is a guess, and what pinned it.

---

## The rule that makes headers worth having

A wrong struct layout that compiles is worse than no struct at all. It turns a
loud compile error into a silent near-miss, and near-misses cost afternoons.

So: **every field below is either marked VERIFIED with the instruction that
pinned it, or it is not in a header.** Speculation lives in a comment or in a
worker's own `.c`, never in a shipped layout.

## The rule that protects the verifier — read this even if you read nothing else

`verify_functions.py` derives a call target's address from the *symbol name*.
Only these resolve:

    sub_XXXXXXXX   FUN_XXXXXXXX   DAT_XXXXXXXX   _XXXXXXXX

A relocation against **any other name is masked** — and masked bytes are
subtracted from *both* sides of the score (`total = fsize - len(masked)`). So a
function that calls a nicely-named `Heap_Alloc` can report **N/N OK while its
call target was never checked**. Friendly names silently buy you a false
positive.

The house idiom, used throughout `heap.h`:

```c
void *sub_02030098(HeapID heapID, u32 size);   /* prototype: address symbol */
#define Heap_Alloc sub_02030098                /* alias:     what you type  */
```

You write `Heap_Alloc(...)`, the object records `sub_02030098`, the verifier
checks the branch word. Never declare a prototype under a friendly name alone.

---

## Header status

| Header | Confidence | What it is |
|---|---|---|
| `types.h` | **verified by construction** | `#include <nitro/types.h>` plus `bool8`/`bool32`/`NELEMS` |
| `global.h` | **verified by construction** | umbrella: `<nitro.h>` + `<nnsys.h>` + `types.h`; start new files with this |
| `heap.h` | **read-from-ROM** | GameFreak heap layer, every offset cited by address |
| `pokemon.h` | **proven twice over** | `Pokemon` / `BoxPokemon` / `Party` + the MON_DATA_* map |
| `ov021.h` | **proven-by-match** | the whole field system: `FieldSystem`, `FieldPlayer`, `FieldCamera`, `FieldEncount`, `MsgBg` |
| `g_clact.h` | **proven-by-match** | `clact.c`, the 2D sprite system |
| `main_types.h` | **proven-by-match** | `MainRec` `MainSub` `Fifo` and the three main globals |
| `ov009.h` `ov010.h` `ov093.h` `ov094.h` `ov114.h` `ov119.h` `ov135.h` `ov170.h` | **proven-by-match** | per-module models, see the reconciliation section |
| `gf_fwd.h` | safe by design | opaque `typedef struct X X;` registry — no fields at all |
| `msl/*.h` | build plumbing | minimal `stddef/stdlib/string/stdio/stdarg` so SDK and NNS headers can be included |
| `init.h`, `overlay_stubs.h` | unverified | loose Ghidra-era prototypes; harmless but unaudited |
| `ghidra_legacy.h` | **wrong, quarantined** | the old unverified structs, kept only so `src/*.c` scratch files still build |
| `globals.h`, `resource.h`, `intro_types.h` | tombstones | see below |

### `types.h` changed — this matters

It used to typedef `u32` as `unsigned int`. The SDK spells it `unsigned long`.
Both are 32 bits so codegen is identical, but the two typedefs cannot coexist
in one translation unit, which made `"types.h"` and `<nitro.h>` mutually
exclusive. `types.h` now includes `<nitro/types.h>` instead of redefining it.
All existing matches were rebuilt and re-verified across the change.

### Tombstoned headers

- **`globals.h`** — was 4000 `extern u32 DAT_xxxxxxxx;` lines auto-generated
  from `symbols.txt`. It **did not compile**: function-pointer entries were
  emitted as `extern void (*)(void) DAT_020011C4;`, a declarator with no name.
  Every address in it was also on the legacy Ghidra base (file offset +
  `0x02000000`) rather than real RAM, so all of them were `0x4000` low, and
  many "variables" were actually instructions (`0x0200080C = 0xE3A00000` is
  `mov r0, #0`). Nothing to salvage.
- **`resource.h`**, **`intro_types.h`** — unverified Ghidra / straight
  transcriptions of pokeheartgold with no Black evidence. Contents moved to
  `ghidra_legacy.h`; the type names they forward-declared are now opaque in
  `gf_fwd.h`.

### `symbols.txt`

Still on the legacy base and still mostly `DAT_` noise mistaking code for data.
**Do not use it to name anything.** Not yet rewritten; it has no consumers in
`tools/`, so it is inert rather than dangerous.

---

## Verified: the GameFreak heap layer (`heap.h`)

Everything here was read out of Black's own instructions. The chain that
anchored it: the SDK sweep places NNS `expheap`/`allocator`/`heapcommon`
byte-exactly in `main`, and the only callers of those NNS entry points are the
GameFreak wrappers.

**Anchors (byte-exact NNS/SDK placements in `main`):**

| symbol | address |
|---|---|
| `NNS_FndCreateExpHeapEx` | `0x02060C5C` |
| `NNS_FndAllocFromExpHeapEx` | `0x02060CA0` |
| `NNS_FndFreeToExpHeap` | `0x02060E30` |
| `NNS_FndInitAllocatorForExpHeap` | `0x02061358` |
| `OS_AllocFromArenaLo` | `0x02086788` |
| `OS_DisableInterrupts` / `OS_RestoreInterrupts` | `0x02087988` / `0x0208799C` |

**The file:** `main`, **ARM** (compile it without `--thumb`),
`0x0202FBAC .. 0x020304B8`.

| address | name | how it was identified |
|---|---|---|
| `0x0202FBAC` | `Heap_GetHandle` | 36 B; `slot[+0x00]` |
| `0x0202FBD0` | `Heap_GetParentHandle` | 36 B; `slot[+0x04]` |
| `0x0202FBF8` | `Heap_GetRawPtr` | 36 B; `slot[+0x08]` |
| `0x0202FC20` | `Heap_GetNumMemBlocks` | 36 B; `ldrh slot[+0x0C]` |
| `0x0202FC48` | `Heap_InitSystem` | allocates the tables, calls `NNS_FndCreateExpHeapEx` |
| `0x0202FDC4` | `Heap_Create` | calls `NNS_FndAllocFromExpHeapEx` then `0x0202FED8` |
| `0x0202FED8` | (registers a new child heap) | not yet named |
| `0x02030098` | `Heap_Alloc` | `NNS_FndAllocFromExpHeapEx` under `OS_DisableInterrupts` |
| `0x02030164` | `Heap_Free` | `NNS_FndFreeToExpHeap`, checks the block magic |
| `0x02030238` | `Heap_InitAllocator` | `NNS_FndInitAllocatorForExpHeap` |
| `0x020302A4` | free/realloc variant | **not identified** — signature deliberately not shipped |

### `HeapInfo` at `0x02146954` — VERIFIED

The literal `0x02146954` is the PC-relative constant in every function of the
file (`0x0202FBCC`, `0x0202FDC0`, `0x02030158`, `0x02030234`, `0x0203029C`, …).

| off | field | evidence |
|---|---|---|
| `+0x00` | `HeapSlot *heaps` | `0x0202FCB4  str r0, [r1]` after `OS_AllocFromArenaLo(0, maxHeaps*0x10, 4)` |
| `+0x04` | `u8 *heapIdxs` | `0x0202FD1C  str r0, [r1, #4]`; filled with `0xFF` at `0x0202FD28` |
| `+0x08` | `u16 totalNumHeaps` | `0x0202FD44  strh r5, [r8, #8]`; re-read as the bounds check at `0x020300B4` |
| `+0x0A` | `u16 nTemplates` | `0x0202FD48  strh r6, [r8, #0xa]` |
| `+0x0C` | `u16 maxHeaps` | `0x0202FD4C  strh sb, [r8, #0xc]`, where `sb = nTemplates + 24` |
| `+0x0E` | `u16 lastError` | `0x0202FD50  strh r4, [r8, #0xe]`; written on every failure path |

Nothing past `+0x0F` has been observed.

### `HeapSlot` — 0x10 bytes — VERIFIED

Size is fixed by the allocation (`0x0202FCA0  lsl r1, sb, #4`) and by every
access using `lsl #4`. Four sibling accessors read one field each; the init
loop at `0x0202FCBC` writes `str/str/str/strh/strb` across `+0x00 +0x04 +0x08
+0x0C +0x0E`, which is what fixes `+0x0E` as a **byte** rather than a halfword.

| off | field | evidence |
|---|---|---|
| `+0x00` | `NNSFndHeapHandle handle` | `0x0202FBAC` accessor: `ldr r0, [r0, r2, lsl #4]` |
| `+0x04` | `NNSFndHeapHandle parentHandle` | `0x0202FBD0` accessor: `ldr r0, [r0, #4]` |
| `+0x08` | `void *rawPtr` | `0x0202FBF8` accessor: `ldr r0, [r0, #8]` |
| `+0x0C` | `u16 numMemBlocks` | `0x0202FC20` accessor `ldrh`; `++` at `0x02030138`, `--` at `0x02030200` |
| `+0x0E` | `u8 unk_0E` | written by `strb` at `0x0202FCF4`; **purpose unknown** |
| `+0x0F` | — | never observed |

### `MemBlockHeader` — 0x1C bytes — size and first two fields VERIFIED

`Heap_Alloc` adds `0x1C` to the request (`0x020300F8  add r1, r6, #0x1c`) and
advances the returned pointer by `0x1C` (`0x02030118  strh r7, [r5], #0x1c`);
`Heap_Free` subtracts it back (`0x02030168  sub r6, r0, #0x1c`).

| off | field | evidence |
|---|---|---|
| `+0x00` | `u16 heapID` | stored at `0x02030118`; read back as `ldrh r4, [r0, #-0x1c]` at `0x02030174` |
| `+0x02` | `u16 magic` | `0x194E` stored at `0x02030114`; compared at `0x0203016C`/`0x02030178`; poisoned to `0x194D` at `0x02030204` |
| `+0x04..+0x1B` | **UNKNOWN** | 24 bytes the heap layer never touches. Probably gen 5 alloc tracking. Left as filler on purpose. |

Note this differs from gen 4: pokeheartgold's header is `0x10` bytes with an
8-bit heap id. Do not carry gen 4 numbers across.

### Conventions — VERIFIED

- Bit 15 of a heap id (`HEAP_AT_END`, `0x8000`) selects tail allocation:
  `tst r7, #0x8000` → alignment `-4` else `+4`, at `0x020300AC` (`Heap_Alloc`)
  and `0x0202FDD4` (`Heap_Create`). The id is masked with `0x7FFF` first
  (literals at `0x0203015C`, `0x0202FE64`).
- `0xFF` in `heapIdxs` means "no heap for this id" (`0x0202FD24`, `0x0202FBB8`).
- `lastError`: `1` bad id / `2` no handle / `3` allocation failed, from
  `Heap_Alloc`; `Heap_Free` adds `1` bad magic and `4` refcount already zero.

### SPECULATIVE, and marked as such in the header

- **`enum HeapID` values.** Only the mechanics are verified. The id → purpose
  mapping is unknown for Black and gen 5 renumbered it, so `HeapID` is a plain
  `u32` and pokeheartgold's enum was deliberately **not** ported. Pass the raw
  number the call site uses.
- **`HeapParam.arena` (`+0x04`).** The stride is provably 8
  (`0x0202FD64  ldr r1, [r7, r4, lsl #3]` loads `size` at `+0x00`), so a second
  word exists — but Black never reads it: the arena argument to
  `OS_AllocFromArenaLo` is a hard `0` from `mov sb, r4` at `0x0202FD5C`. Named
  after the gen 4 field, not confirmed.

---

## Not yet verified — deliberately absent

`String`, `MsgData`, `SaveData`, `BgConfig`, `Window`, `SpriteList`,
`SpriteRenderer`, `Sprite`, `OverlayManager`, `TaskManager`, `SysTask`,
`SysTaskQueue`, `FieldSystem`, `NARC`.

These exist **only as opaque typedefs** in `gf_fwd.h`. pokeheartgold has full
layouts for all of them and they are a good starting hypothesis — gen 5 is an
evolution of that engine — but the heap layer above is the cautionary tale:
Black changed the slot array shape, the header size, and the id encoding
relative to gen 4. Transcribing gen 4 offsets would have been wrong three
times in one small file.

If you are working one of these, keep a private `struct UnkStruct021D0F00` in
your own `.c`, or use raw pointer arithmetic, and send the integrator the
constraining accesses. The layout lands here with citations and everyone
recompiles.

---

## Three grades of evidence

The heap layer above is **read-from-ROM**: someone disassembled the function
and wrote down the instruction. The module headers below are **proven-by-match**
and **inferred**, which are weaker but still very different from a guess:

| grade | meaning |
|---|---|
| **read-from-ROM** | the displacement was read out of a disassembly and cited by address. Strongest. |
| **PROVEN** (proven-by-match) | the field is used by a function that `verify_functions.py` reports N/N OK. The compiler emitted the displacement and the ROM agrees, so the offset and the access width are right. |
| **INFERRED** | filler. It exists only to place the next PROVEN field. Nothing reads it, so its name, width and internal boundaries are guesses. |

`tools/scripts/evidence.py --module <mod>` is a fourth, independent check: it
disassembles verified functions and reports constant-offset accesses off an
untouched argument register. When it agrees with a worker's declaration, say
so — that is two methods converging. When it reports nothing, that is **not**
counter-evidence: its liveness heuristic loses arguments across call sequences
and in Thumb code that shuffles registers. It found nothing at all for ov114,
whose 49 functions all match.

## Reconciled worker structs

Twenty-five struct names were declared in more than one file, across eight
modules. All are now single definitions. **Delete the local copies and include
the header**, otherwise the local one wins the quoted-include search and the
promotion does nothing.

| header | what it covers | evidence |
|---|---|---|
| `heap.h` | GameFreak heap layer | read-from-ROM, every offset cited |
| `main_types.h` | `MainRec` `MainSub` `Unk020AA1AC` `Unk020A9E80` `Unk020AA260` `Fifo` | main-A / main-B, all files N/N OK |
| `ov009.h` | `Ov009RapAlloc` | dwc_rapcommon.c, 64/64 OK |
| `ov010.h` | `Ov010Record` `Ov010Vtable` `Ov010Sub88` | 4 files, 76 functions, all OK |
| `ov093.h` | `BattleSystem` `BattleCore` `BattleOrderList` `BattleSlot*` | 61 functions, all OK |
| `ov094.h` | `AnimMgr` `AnimSprite` `BattleAnimSys` `BattleAnimScript` `AnimVec3` +4 | 21 files |
| `ov114.h` | `Ov114Mgr` `Ov114Ctx` `Ov114Entry` `Ov114Sock` `Ov114Sess` `Ov114Buffer` +9 | 9 files, 49+ OK |
| `ov119.h` | `PokemonTradeWork` | promoted verbatim |
| `ov135.h` | `WorldTradeWork` `WorldTradeSlot` `WorldTradeAdapter` | promoted verbatim |
| `ov170.h` | `Ov170Ctx` `Ov170Panel` `Ov170Anim` `Ov170Save` `Ov170Sub00` +4 | 40 files, 51/51 OK |

Every size and every load-bearing offset above is checked by a static
assertion in a scratch TU that compiles clean in **both ARM and Thumb**.

### The merges that changed something

Most apparent conflicts were not conflicts: one file wrote `u8 unk00[0x70]`
and another `u8 unk00[0x74]` because they cared about different later fields.
These are the ones where the merge produced knowledge no single file had.

- **`Ov114Buffer` — three names, one object.** `Node` (unk_021B9D8C.c),
  `Pool` (unk_021BEC74.c) and the large `Conn` (unk_021BF184.c) all put a
  32-bit counter at `+0x8048` and contradict each other nowhere. `Node`'s
  reading explains the whole shape — a 0x40 header, a 0x8000-byte data area,
  then cursor / available / refcount — and `Conn`'s named fields at
  `+0x00..+0x18` all land inside `Node`'s opaque header. Three files were each
  carrying a partial view of the same 32 KB buffer node. (The *small* `Conn`,
  0x2C, is a genuinely different object and is `Ov114Conn`.)
- **`AnimMgr` — arithmetic settled it, not the vote.** Six files put
  `sprites[14]` at `+0x008` behind `u32 unk000; void *unk004`, one at `+0x000`.
  With the array at `+0x008` it ends at `0x510`, exactly where another file
  reads a bitfield word, and the layout closes with no unexplained filler; the
  `+0x000` reading needs a 12-byte hole and leaves `0x510` unaccounted for.
  The tail is self-checking too: `0x542 + 7*14 == 0x5A4`, the struct end, one
  byte per sprite per row.
- **`Ov170Anim` — the merge added a field.** Three files declare
  `u8 unk00[8]` at the front; `unk_021E2020.c` separately declares
  `u32 (*unk58)(void *)` on the panel at `+0x58`, which is exactly where that
  opaque run begins. Both files match, so the first word of the "filler" is a
  callback.
- **`Ov010Record` — four files, one record.** The join is
  `src/ov010/unk_0216D910.c`, which passes one pointer to both accessor
  families (`sub_0216D4D4` reads `+0x00`, `sub_0216D67C` reads `+0x88`) in the
  same byte-exact function. Flagged in the header as the one claim here
  carrying risk: that file spells the parameter `void *`, so the compiler
  never checked the identification. The offsets themselves are all proven.
- **`Ov170Ctx+0x00` — left unresolved, on purpose.** Eight files type it
  `Ov170Sub00 *`, three `Ov170Save *`. Neither pointee contradicts the other,
  and they are probably the same object read at two depths — but nothing
  proves it, so the pointer takes the majority type and `Ov170Save` stays a
  separate declaration. Cast at the three call sites.

### Upgrades: worker byte-runs replaced by SDK types

Each of these turns a layout that rested on transcription into one that is
verified by construction. All were confirmed by static assertion first.

- `Ov114Lock`: `u8 mutex[0x18]; u32 queueHead; u32 queueTail` **is**
  `OSMutex` + `OSThreadQueue`, and `&lock->mutex` goes to `OS_InitMutex`.
- `AnimVec3` / `Vec3` / `UnkVec3`: all three **are** `VecFx32` — the type is
  passed to `sub_0206DF3C`, i.e.
  `NNS_G3dWorldPosToScrPos(const VecFx32 *, int *, int *)`.
- `TPData` in `src/main/b_unk_020358a0.c` is byte-for-byte the SDK's own
  `TPData`; redeclaring it is a hard compile error once `global.h` is in.

And one upgrade **declined**: `Ov114Worker::thread` is `u8 thread[0xB4]` in the
matched code, but `sizeof(OSThread)` is `0xC0`. Swapping the type in would
assert a size the evidence does not support. Recorded, not resolved.

### Actions for workers

| file | change |
|---|---|
| `src/ov094/btlv_effvm_021FB034.c` | rename `UnkVec3` → `AnimVec3` |
| `src/main/b_unk_020358a0.c` | delete local `TPData`; the SDK's is in scope |
| `src/ov135/*.c` | `#include "worldtrade.h"` → `"ov135.h"`, delete the private header |
| `src/ov119/*.c` | `#include "pokemontrade.h"` → `"ov119.h"`, delete the private header |
| ov114 | `Lock`→`Ov114Lock`, `Mgr`→`Ov114Mgr`, `Entry`→`Ov114Entry`, `Sock`→`Ov114Sock`, `Ctx`→`Ov114Ctx`, `Handle`→`Ov114Handle`, `Sess`→`Ov114Sess`, `Node`/`Pool`/big `Conn`→`Ov114Buffer`, small `Conn`→`Ov114Conn` |
| ov170 | four files name fields at panel `+0x60/+0x68/+0x6C`, which fall inside the `Ov170Anim` now embedded at `+0x58`. Reach them through `panel->anim`; do not re-add overlapping fields. |

## Claim-table reconciliation (wave 2)

Two tools, both idempotent, both dry-run by default:

**`tools/scripts/recover_starts.py`** recovers real function boundaries. The
claim table came from a prologue heuristic and systematically fuses adjacent
functions that do not open with a recognisable prologue -- `0x0202FBAC` is one
116-byte entry and is really four 36-byte accessors. Generalises ov093's
`build/attempts/ov093/recover_starts.py` to all 238 modules, and grades the
evidence instead of pooling it:

| tier | evidence | found |
|---|---|---|
| `verified` | a byte-exact hand match at that address | 704 |
| `sdk` | a byte-exact SDK/NNS sweep placement | 84 |
| `callsite` | a BL/BLX target | 6595 |
| `ptr` | an odd (Thumb-flagged) word-aligned pointer into the module | 1236 |

The callsite scan follows `callsite_modes.py`'s discipline, **not** the ov093
script's: only bytes inside a known code extent are decoded, and only in that
extent's recorded mode. Scanning a module image linearly as Thumb mines rodata
for phantom branches, and a phantom start is not free -- it splits a real
function and makes both halves unmatchable. Three further guards: a candidate
strictly inside a *verified* function is dropped (we know that extent), a
candidate inside a `status: "data"` row is dropped, and candidates must be
2-byte aligned and inside the image.

**`tools/scripts/reconcile.py`** sets `status` from verifier output only:
verified N/N → `matched:<module>/<file>`; a verified address with no row gets
one; a `matched:` row that stops verifying is demoted to `unclaimed` and
reported. `matched_sdk`, `claimed:*` and `data` are never touched unless they
verify. Nothing is marked matched on bookkeeping.

Both shrink a fused parent to end where a new child begins, so the same bytes
are never double-counted.

Result: **23,400 → 32,071 rows**, 3,780 fused rows shrunk, 0 overlapping rows,
0 rows past a module end, 0 schema violations.

### Rows marked `data`

`status: "data"` in the claim table is an explicit declaration that a row is
not code, and `triage.py` now honours it (a three-line change; it previously
derived `kind` from bytes alone). This is the durable place to record it --
`triage.json` is regenerated from the claim table, so a correction recorded
only in `triage.json` is lost on the next run.

- `ov170 0x021EF770` (7376 B)
- `ov094 0x02209F30` (4080 B) -- its first words are a jump table of odd
  (Thumb) function pointers, so `classify()` saw clean Thumb and called it
  code. The verifier was then stamping Thumb bits into ABS32 words pointing
  into the block.

**After any `triage.py` run, re-run `python tools/scripts/callsite_modes.py
--apply`** -- regeneration drops its derived entries.

### Names corrected in the claim table

`verify_functions.py` resolves friendly names to addresses via `symbols.txt`
first, then the claim table. A wrong name silently retargets every call that
uses it -- and the relocation still verifies, against the wrong target. These
were wrong (found by main-C):

| name | was on | is |
|---|---|---|
| `PXI_Init` | only in ov114/ov125 (main's copy was `FUN_02088498`) | `0x02088498` |
| `FSi_GetFilePositionIfProc` | `0x0207A528` | `0x0207A568` |
| `FSi_GetFileLengthIfProc` | absent | `0x0207A528` |
| `RtcSendPxiCommand` | `0x02088F2C` | `0x02084614` |
| `MicWaitBusy` | `0x02088ED4` | `0x0208B798` |
| `FX_DivAsync` | `0x0207C930` | `0x0207C8A0` (was `FX_InvAsync`) |

Five stale duplicates were renamed to `sub_XXXXXXXX` so no wrong mapping
survives.

`PXI_Init` exposed a **whole class** of this bug: overlays link their own
copies of the SDK under the same names, and `_named()` is one global
name → address map, so any duplicated SDK name was a coin flip. `symbols.txt`
is now generated main-first — 24 names deduped to main's copy, and the 2 that
exist only in overlays are omitted rather than guessed, because the name does
not identify one address. Call those by `sub_<addr>`.

`0x02004490` is triaged `arm` but the ROM calls it with `BLX`, so it is Thumb;
`callsite_modes.py --apply` is what fixes that class and it has been re-run.


---

# Wave 3

## Promoted data models

| header | from | evidence |
|---|---|---|
| `pokemon.h` | `src/main/pk_pokemon.h` | **proven twice over** |
| `ov021.h` | `src/ov021/fld_fieldsys.h` + `fld_player_core.h` + `fld_camera.h` | 49 of 85 word slots pinned to a named accessor |
| `g_clact.h` | `src/main/g_clact.h` | a bitfield partition that sums to exactly 32 bits |
| `ov093.h` | `src/ov093/battle.h` folded into the existing header | ~60 accessors |

**Delete the private headers.** While a local copy exists it wins the quoted
include search and shadows the shared one, so promotion does nothing.

`pokemon.h` is the strongest evidence in the repo and the only structure so far
proven by two *independent* derivations: every field of all four 0x20-byte
substructs is pinned separately by the jump table of `GetBoxMonDataInternal`
(0x02018E34, 1224/1224 OK) and by that of `SetBoxMonDataInternal` (0x02019388,
1736/1736 OK), and the two agree everywhere. `sizeof(Pokemon)` = 0xDC is
confirmed a third time by the party stride wave 1 measured independently.

`ov021.h` carries a **do not reconcile against gen 4** warning: pokeheartgold's
`FieldSystem` is 0x128 and gen 5 reordered the head. The subsystem *set* is
recognisable, which is exactly what makes it dangerous — the names transfer and
the offsets do not.

`ov093.h`: `BattleCore::unk_04` is the battle format. 0x021B8670 switches it
0..3 and answers 1, 2, 3, 1 battlers per side; 0x021B8640 answers 1, 3, 5, 5
target slots — single / double / triple / rotation, exactly gen 5's set. A
purely internal derivation landing on a known external fact.

Note a name trap now in that header: `BattleSystemSlot` (0x28, at
`BattleSystem+0x020`) is **not** `BattleSlotRecord` (0x1C). Unrelated objects.

## Defects fixed in wave 2's headers

- **`Ov114Sock` was not the superset it claimed.** `filler_1C` ran to 0x30 and
  swallowed `unk_28`, which `src/ov114/unk_021B9D8C.c` needs, so that file
  could not migrate. The union had been assembled from the widest three of the
  four declarations and this offset only appears in the fourth.
- **`Ov170Anim` had `u8 filler_10[0x08]`**, so the three files reaching
  panel+0x68 / +0x6C had to keep private structs — going through the shared
  header would have meant punning through a byte array. Now `u32 unk10` and
  `void *unk14`; reach them as `panel->anim.unk10` / `.unk14`.
- **`ov009.h` had the instruction set wrong.** It repeated the guide's rule
  that everything above 0x02157170 in ov009 is ARM. `dwc_rapcommon.c` verifies
  **88/88 as Thumb** and only 84/88 as ARM. The guide's rule is a good default
  for the module but not a boundary to trust per file.

## Mode corrections are now durable

`tools/scripts/persist_modes.py`. **Do not regenerate `triage.json`** — it is
derived, and a regeneration discards every correction that lives only there.
`callsite_modes.py` restores only `main` targets, so overlay-internal errors
come straight back; one regeneration cost ov016 three functions to gain ov170
one.

This script writes those corrections into the claim table, where `triage.py`'s
explicit `mode` override keeps them (the same mechanism as `status: "data"`).
It has two passes:

1. every place `triage.json` currently disagrees with a fresh `classify()`;
2. **intra-module call-site derivation** — the gap `callsite_modes.py` leaves
   open. It restricts itself to `main` because overlays alias in RAM, but that
   reasoning does not apply when decoding one module's own bytes and accepting
   only targets inside that same module's image: the callee can only be that
   module's code.

**1,001 modes are now pinned** (ov095 510, ov093 394, main 30, ov021 14,
ov170 7, ov016 3, …). Guards: only inside known code extents, only in the
extent's recorded mode, unanimous votes only, never `data`/`veneer`, and
**never a row that already verifies** — its mode is settled by something
stronger than a vote and its callers were encoded against the current value.
8 such disagreements are reported rather than applied.

`triage.json` was then patched **in place** from the claim table (970 modes, 52
rows added), not regenerated.

The claim-table schema now allows an optional fifth key, `mode`.

## Translation-unit map

`tools/scripts/tu_map.py` swept across all 238 modules:
**107 modules produced a map, 566 translation units resolved to an address
span**, merged into `build/reference/tu_map.json`. 131 modules have no `.c`
strings — that trick needs a TU that asserts or allocates.

Two spot checks landed on facts derived independently by other agents:
`fieldmap.c` at 0x02188030 (the FieldSystem_New address ov021 cited) and
`clact.c` at 0x0204A39C..0x0204E130 (the range the g_clact worker gave).

## Actions for workers (wave 3)

| file / module | change |
|---|---|
| `src/main/pk_pokemon.h` | delete; `#include "pokemon.h"` |
| `src/ov021/fld_fieldsys.h`, `fld_player_core.h`, `fld_camera.h` | delete; `#include "ov021.h"` |
| `src/main/g_clact.h` | delete; `#include "g_clact.h"` (now the shared one) |
| `src/ov093/battle.h` | delete; `#include "ov093.h"` |
| `src/ov114/unk_021B9D8C.c` | can migrate now — `Ov114Sock::unk_28` exists |
| ov170 `unk_021DCDB8.c`, `unk_021E2020.c`, `unk_021E8F60.c` | can migrate now — use `panel->anim.unk10` / `.unk14` |
| `src/ov009/dwc_rapcommon.c` | compile `--thumb` (88/88, vs 84/88 as ARM) |


---

# Wave 4

## Promoted

- **`ov021.h` rebuilt from all five `src/ov021/fld_*.h`** — adds `FieldEncount`
  0x14, `FieldEncountStep` 0x0C, `FieldEncountInfo`, `MsgBg` 0x17C and the
  message-layer records, and `FieldCamera` went from mostly filler to mostly
  proven: seven contiguous `VecFx32` at 0x24..0x6C each pinned by a whole-struct
  ldm/stm copy, three parallel mode-dispatch tables, and a 4 x 0x18 entry table
  at +0x88 whose count byte sits at +0xE8. `FieldSystem` gained `FieldSysBuf` at
  +0x118.
- **`ov093.h`: `BattleScriptCtx` is identified.** It IS one of
  `BattleSystem::unk_010[4]` — the per-battler controller — so that array is now
  `BattleScriptCtx *[4]` rather than `void *[4]`. The proof chains two matched
  functions: `sub_021B9B10` is exactly `sub_021CD9F4(bsys->unk_010[a1], a2)`,
  and `0x021D3C44` calls `sub_021CD9F4(ctx, ...)` directly when the command is
  addressed to `ctx`'s own battler (`args[0] == ctx->unk_1A6`) and routes it
  through `sub_021B9B10` otherwise. Same callee, same object. `+0x058` is an
  embedded 0x54-byte text-format buffer, not a pointer.

  The 92-entry opcode map in that header is a **naming proposal only**. The
  handlers stay spelled `sub_<ram>` because that spelling is what
  `verify_functions.py` resolves — renaming them would silently mask every call
  site and turn real checks into free passes.

### The MsgBg conflict is recorded, not resolved

`0x02190708` writes a u16 at `+0x06` of its first argument, which cannot
coexist with `MsgBgWinSet::win` being a pointer at `+0x04`. The worker read the
argument as a `MsgBg` (whose `+0x06` is free) and that reading verifies, so it
is what the header records — but that is one function's argument type inferred
from a field being available, which is weaker than everything around it.
`MsgBgWinSet` and `MsgBg` stay separate and neither absorbs the other. Resolve
it with a call site that types `0x02190708`'s first argument, not a preference.

### One more SDK type reclaimed

`src/ov021/fld_encount.h` transcribed `RTCTime` as three `s32`. That is the
SDK's own `RTCTime` (`<nitro/rtc/ARM9/api.h>`, three `u32`, same 0x0C layout),
which arrives via `global.h` — so redeclaring it is a hard compile error. Third
time this pattern has appeared, after `TPData` and `OSMutex`: **when a worker's
byte-run or scalar triple has the same shape as an SDK type, it usually is that
type**, and using it makes the layout verified by construction. Worth checking
before adding any new struct that looks like an SDK one.

## The 43 KB hole: heuristic `kind: data` was hiding the whole MSL region

`main 0x02091588` was a **single claim row of 43,652 bytes** covering
0x02091588..0x0209C00C, triaged `kind: data`. It is clean ARM code — MSL.

The cause is a systematic asymmetry in `triage.classify()`: it calls a blob
data when more than an eighth of it fails to decode, and *any* multi-kilobyte
fused row trips that on its literal pools alone. So **the more code a fused row
hides, the more likely it is to be labelled data** — and `recover_starts.py`
skipped `data` rows, which is exactly the pass that would have broken it up.
Nothing had ever looked inside it.

The guard is now asymmetric to match:

- an explicit `status: "data"` is a *declaration* and is always honoured;
- a heuristic `kind: data` is honoured only for rows `<= 0x2000` bytes, where
  it is usually right (ov094's 0x02209F30 jump table is 4080 bytes).

Result: the MSL region went from **1 row to 77**, the recovery pass added
**1,193 starts** repo-wide, and 29 already-verified functions that had no row
got credit. 32,076 -> 33,269 rows; 4.35% -> 4.50%.

## `verify_data.py` — and the trap it comes with

`verify_functions.py` filters on STT_FUNC, so a `.data`/`.rodata` definition
was invisible: you could write the bytes, compile, and nothing would tell you
whether they were right. `tools/scripts/verify_data.py` is the same judge for
STT_OBJECT symbols, sharing the ELF reader, the name->address rule, the
relocation model and the masking discipline so the two cannot drift.

Two deliberate differences: a symbol in `.bss` is reported **UNPROVABLE**, never
as a pass (there are no bytes to compare, in the object or in the ROM —
`errno` at 0x02153FAC is the live case); and only `R_ARM_ABS32` is applied,
since data does not branch.

**It does not feed `progress.py`.** "Functions verified" is the headline metric
and its meaning should not change because data started counting.

**The trap, and it is a real one.** For code, a match means something because
the C is an independent derivation — the compiler chose the encoding and the
ROM agreed, and you cannot fake the compiler. For data there is no compiler in
the loop: paste a byte table out of `main.bin` into a `const u8 _020A60DC[512]`
and this tool reports 512/512 OK having compared the ROM to itself. That is a
transcription, not a match. A data object is genuinely matched only when its
definition comes from elsewhere — real library source, or a generator that
derives the table from its inputs. Transcribed tables are useful as
placeholders that stay correct under later edits; mark those
`transcribed:<who>`, never `matched:`.

This is why **the ~1,500 MSL data bytes are not claimed here.** `lib/MSL_C` is
not in the tree, so those definitions cannot be independently derived in-repo.
They are located in `build/reference/msl_matches.json`, named in `symbols.txt`
so references resolve, and explicitly marked NOT verified.

Today the tool finds 2 verified data objects (22 bytes, ov016) that nothing had
ever checked, and correctly refuses to score 5 `.bss` symbols.

## MSL region facts (recorded so nobody re-runs the sweep)

| range | what |
|---|---|
| `0x020913D0`-`0x0209A524` | MSL |
| `0x0209A524`-`0x0209D850` | CodeWarrior runtime |
| `0x020A60DC` +512 | the ctype tables, one contiguous block (`__lower_mapC`, `__upper_mapC`, `__msl_digit`) |

Black links the **same MSL as pret but a different build**, so only the
coincidentally byte-identical subset is ever claimable. 25 functions verified;
the rest is not a matter of trying harder.

## triage.json: sync, never regenerate

`persist_modes.py --sync-triage` brings triage.json into line with the claim
table in place. Adding a triage entry for a new claim row is **not free**: an
entry in `_MODES` overrides the `_enclosing()` fallback the verifier would
otherwise use, so a wrongly-defaulted mode is worse than no entry at all.
Defaulting one wave's 1,198 new rows to `thumb` cost 5 verified functions and
4,824 bytes until they were re-derived from the bytes. Order of authority:
explicit `mode` on the claim row, then `classify()` on the actual bytes.

## Actions for workers (wave 4)

| file / module | change |
|---|---|
| `src/ov021/fld_*.h` (all five) | delete; `#include "ov021.h"` |
| `src/ov093/battle.h` | delete; `#include "ov093.h"` |
| `src/ov021/*.c` using `RTCTime` | delete the local one; the SDK's is in scope via `global.h` |
| ov093 | `BattleSystem::unk_010[4]` is now `BattleScriptCtx *[4]` — drop the casts |
| anyone writing data | `tools/scripts/verify_data.py`, and read its header before claiming a byte |
