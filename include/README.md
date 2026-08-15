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
| `types.h` | **verified by construction** | now just `#include <nitro/types.h>` plus `bool8`/`bool32`/`NELEMS` |
| `global.h` | **verified by construction** | umbrella: `<nitro.h>` + `<nnsys.h>` + `types.h`; start new files with this |
| `heap.h` | **verified** | GameFreak heap layer, every offset cited below |
| `gf_fwd.h` | safe by design | opaque `typedef struct X X;` name registry — no fields at all |
| `msl/*.h` | build plumbing | minimal `stddef/stdlib/string/stdio/stdarg` so the SDK and NNS headers can be included |
| `ov114.h`, `ov170.h`, `ov094.h` | **proven-by-match** | merged worker structs, see the reconciliation section |
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

Six struct names were declared in more than one file. All are now single
definitions; **delete the local copies** and include the header instead.

### `include/ov114.h` — socket / connection library (`verify_functions.py ov114`: 49/49 OK)

Renamed, because `Lock`/`Mgr`/`Entry`/`Sock`/`Ctx`/`Conn`/`Handle` are far too
generic for a header shared by 238 modules — ov009 is also networking code and
will want `Sock`:

| worker name | header name |
|---|---|
| `Lock` | `Ov114Lock` |
| `Mgr` | `Ov114Mgr` |
| `Entry` | `Ov114Entry` |
| `Sock` | `Ov114Sock` |
| `Ctx` | `Ov114Ctx` |
| `Conn` | `Ov114Conn` |
| `Handle` | `Ov114Handle` |

- **`Lock`** — both files identical, safe merge. *Upgraded*: the workers' `u8
  mutex[0x18]; u32 queueHead; u32 queueTail;` is exactly the SDK's `OSMutex`
  (0x18) followed by `OSThreadQueue` (0x08), so the real types are used and the
  0x24 size is now verified by construction. All four offsets PROVEN.
- **`Mgr`** — *the one real conflict.* `unk_021BE8E8.c` had `void *ctx` at
  `+0x04`, `unk_021BEC74.c` had `Ctx *ctx`. Resolved to the **typed** form:
  `unk_021BEC74.c` is the file that constructs and walks the context
  (`sub_021BEF08` / `sub_021BEEC4`), so it is the one with information; `void *`
  was the other file's shrug. Both files still compile, because a typed pointer
  converts to a `void *` parameter freely.
- **`Entry`** — length disagreement, not an offset disagreement: 0x24 vs 0x30.
  Strict superset, longer wins. `unk_10`/`unk_14` typed `Ov114Sock *`.

### `include/ov170.h` — menu / panel overlay (`verify_functions.py ov170`: 51/51 OK)

- **`Ov170Ctx`** — both files identical. `unk2c` (+0x2C) PROVEN.
- **`Ov170Panel`** — superset/subset, not a contradiction: the two-field
  version is `u8 unk00[0x74]; void *unk74;`, i.e. the five-field version with
  `+0x70` folded back into the leading filler. Five-field form wins; nothing
  is lost.
  **`+0x74` is confirmed twice**: by the 51/51 match, and independently by
  `evidence.py --module ov170`, which reports `run 0x021ef670..0x021ef68c
  (2 functions) +0x074:4B` — a 4-byte access at a constant `+0x74` off an
  untouched argument register, inside functions that matched.
  `+0x70` and `+0xA168` are PROVEN by match only. The 41200-byte `unk78`
  filler is INFERRED — the claim being made is the `0xA168` offset, not that
  the region between is one object.

### `include/ov094.h` — battle animation script commands (`verify_functions.py ov094/anim_scrcmd`: 26/26 OK)

- **`BattleAnimScript`** — declared in all four files; a typing difference
  only, every named offset agreed. Three files had a flat
  `pad_008[0x238-0x008]`; `anim_scrcmd_021FB6F4.c` split it into
  `pad_008[0xCC-0x08]` + `void *unk0CC[(0x238-0x0CC)/4]` because that file
  indexes the pointer table. Split version wins — strictly more informative,
  identical layout.
  `unk000`, `unk004`, `unk0CC[]`, `unk23C` PROVEN. **`unk238`/`unk23A` are
  INFERRED**: nothing touches them, only their combined 4 bytes matter (they
  place `unk23C` at `0x23C`). Do not build on that split.
- **`AnimVec3`** — two files agreed on `{s32 x, y, z}`; the third declared the
  same shape as `UnkVec3` with `u32`. *Upgraded*: `anim_scrcmd_021FB6F4.c`
  passes one to `sub_0206DF3C`, which is
  `NNS_G3dWorldPosToScrPos(const VecFx32 *, int *, int *)`. So this type **is**
  the SDK's `VecFx32`, and the header aliases it — layout verified by
  construction rather than by two workers agreeing.
  **Action:** `anim_scrcmd_021FB034.c` should rename `UnkVec3` → `AnimVec3`.
- **`BattleAnimScript`** was also flagged with "0 fields" in three files —
  that was the scraper not parsing the `/* 0x000 */` comment style, not a
  forward declaration.
- **`ScriptContext`** stays opaque and moved to `gf_fwd.h`: the script VM is in
  `main` (`sub_0201134C` is `ScriptReadWord`), so it is shared, not ov094's.

Single-file types folded into the same headers so each module has one home:
`Ov170Rec12`, `AnimPoint16`, `AnimParamsA18`, `Ov114Conn`.

All of the above is compile-checked in both ARM and Thumb with static
assertions on every size and every load-bearing offset.

---

## Claim-table reconciliation

`build/reference/functions.json` is rewritten from verifier output only, by
`build/scratch/reconcile.py` (dry run by default, `--write` to apply):

- verified N/N → `status: "matched:<module>/<file>"`, naming the source file
  that produced it;
- a verified address the table does not list as a function start gets a new
  row, and the row it was fused into is **shrunk** to end where it begins, so
  the same bytes are not counted twice;
- a `matched:` row that stops verifying is demoted to `unclaimed` and reported;
- `matched_sdk` and `claimed:*` rows are never touched unless they verify.

Nothing is marked matched on bookkeeping. `python tools/scripts/progress.py`
remains the authority.
