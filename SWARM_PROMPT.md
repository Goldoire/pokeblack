# Pokémon Black matching-decomp swarm

You are coordinating a multi-agent matching decompilation of Pokémon Black
(Nintendo DS, gamecode IRBO). The repo is ready: toolchain works, the verify
loop is proven, and the free wins are already taken. Your job is the grind:
turn unclaimed functions into C that compiles byte-identical to the ROM.

## Ground truth (do not rediscover this — it is verified)

- Compiler: `tools/mwccarm/dsi/1.1/mwccarm.exe`, flags in the Makefile's
  MWCFLAGS, proven byte-exact against the ROM (SDK source compiles 48/48
  identical). `LM_LICENSE_FILE` must point at `tools/mwccarm/license.dat`.
- Reference binaries: `make reference` (needs the ROM at ../rom/pokeblack.nds)
  fills `build/reference/` — main.bin + ov000..ov236.bin, all decompressed,
  with `manifest.json` mapping module → load address.
- Claim table: `build/reference/functions.json` — ~23,000 functions across 238
  modules with address, size estimate, and status. `matched_sdk` entries are
  done; `unclaimed` is your work queue.
- Judge: `python tools/scripts/verify_functions.py` byte-checks every object
  under `build/src/` against its module's reference. A function is DONE only
  when it reports N/N OK. There is no other definition of done.
- Nintendo's own library source exists in-tree: TwlSDK at
  `lib/NitroSDK/TwlSDK/build/libraries/`, NNS at `lib/TwlSystem/build/libraries/`.
  `tools/scripts/sdk_sweep.py` already matched everything that compiles
  verbatim; near-miss SDK functions should still be matched FROM that source
  (tweak flags/inlining), never hand-decompiled.

## Traps (each of these cost hours to learn; do not relearn them)

- Legacy `src/*.c` (35 files) is unverified Ghidra pseudo-C — exactly 1
  function matches. Treat as scratch notes, not ground truth. Do not extend it.
- Address bases are mixed in legacy artifacts: `symbols.txt` and legacy C
  names are file-offset+0x02000000; real RAM = module load address (main
  loads at 0x02004000). All NEW code and symbols use real RAM only.
- Overlay function sizes in functions.json are prologue-heuristic estimates;
  trust the start address, verify the size against the bytes.
- Much of the game code is Thumb (`push {..,lr}` prologues). Get the mode
  from the reference bytes before writing C.
- `dsd rom extract` rejects this dump (missing nitrocode footer). Use the
  repo's own scripts.
- mwldarm writes `build/main.sbin` itself; the ELF has no load data. Never
  objcopy it.

## Organization (this is what makes 20+ agents net-positive)

- **Shard by module.** One agent owns one module (or address range of main)
  at a time. Claim it by setting status `claimed:<agent>` in functions.json
  before starting. Never touch another module's rows.
- **One integrator agent owns shared state**: `include/` headers,
  `symbols.txt`, and functions.json merges. Worker agents PROPOSE struct
  layouts (with the evidence: which functions constrain which offsets) to the
  integrator; they never create a second definition of a struct that exists.
  This is the serial bottleneck — protect it.
- New code layout: main → `src/main/<area>.c`, overlays → `src/ov021/<area>.c`
  etc. One contiguous address range per file. Objects land in `build/src/...`
  mirroring the path, which is how the verifier knows the module.
- Commit per verified function or small verified group. Never commit a
  near-miss into src/; bank it in `build/attempts/` with a note.

## Worker loop

1. Claim an unclaimed function in your module (prefer: called by or calling
   already-matched functions; smaller first).
2. Slice its bytes from `build/reference/<module>.bin` (offset = ram −
   module load address). Disassemble; identify mode, callees, data refs.
3. Write C. Name unknown callees `sub_<realRAM>`, data `_<realRAM>` — the
   verifier resolves these by name when checking branch/literal words.
4. Compile with the game flags, run the verifier, diff, adjust idioms
   (order of operations, ternaries vs ifs, do/while, volatile, s16 casts —
   standard CW matching lore). Iterate until N/N OK.
5. Update functions.json status → `matched:<agent>`, commit.

## Priorities

1. Remainder of main (ARM9): shared engine code every overlay calls. Use
   pret/pokeheartgold (gen 4, ../pokeheartgold if present) as a translation
   oracle — gen 5 is an evolution of that engine; many functions are
   recognizable ports. Match its naming where the function corresponds.
2. ov021 (~346 KB, field system) and ov009/ov010 (~450 KB combined).
3. ov093 / ov016 (battle cluster).
4. Everything else by size, descending.

## Reporting

Track and report: functions matched / total, bytes matched / total, per
module. The number that matters is verified matches — never report a
near-miss as progress. If a function resists >10 serious attempts, bank the
best attempt in build/attempts/, mark status `wall:<agent>`, move on.
