# Pokémon Black

A matching decompilation of Pokémon Black (Nintendo DS, gamecode **IRBO**).

It targets the following ROM:

**pokeblack.nds** `sha1: 26ad0b9967aa279c4a266ee69f52b9b2332399a5` (Version 1.0 USA/EUR, DSi-enhanced)

"Matching" means every function here compiles to bytes identical to the retail
ROM. A function counts as done only when `tools/scripts/verify_functions.py`
reports it byte-for-byte identical; near-misses are never merged.

## Credit

This repository builds on [pokemodding/pokeblack](https://github.com/pokemodding/pokeblack)
by **red031000** and **squiddonaut**, whose commits are preserved here with
their original authorship. Their work is the foundation everything else stands
on: the CodeWarrior build, the reference-binary pipeline, the linker
configuration, and the initial function index. Run `git log` to see it.

## What you need to supply

Nothing Nintendo owns is committed here, which is why a fresh clone is ~7 MB.
You provide these locally and the build consumes them; all are gitignored:

| path | what |
|---|---|
| `../rom/pokeblack.nds` | your own ROM, used to generate `build/reference/` |
| `files/`, `data/**/*.bin` | game data extracted from that ROM |
| `lib/NitroSDK/`, `lib/TwlSystem/` | Nintendo SDK / NitroSystem source |
| `tools/mwccarm/` | the CodeWarrior ARM toolchain and its licence |

## Status

Run `python tools/scripts/progress.py` for the current per-module table, or
`python tools/scripts/watch_progress.py` for a live view. Both re-verify against
the ROM rather than reading any status field, so the number cannot drift from
reality.

## Working on it

Read [`WORKER_GUIDE.md`](WORKER_GUIDE.md) first. It is the mechanics — the exact
commands, the per-region instruction set, per-translation-unit compiler
selection, and a matching-lore section covering the CodeWarrior idioms that
have cost the most time to rediscover. [`SWARM_PROMPT.md`](SWARM_PROMPT.md)
covers strategy and the traps already paid for.

The short version of the loop:

```bash
python tools/scripts/fn.py ov021 0x021d0f00      # disassemble a function
python tools/scripts/cc.py src/ov021/field.c --thumb
python tools/scripts/verify_functions.py ov021   # N/N OK or it is not done
```
