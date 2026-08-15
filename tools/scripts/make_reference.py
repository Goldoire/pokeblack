#!/usr/bin/env python3
"""Extract byte-exact reference binaries for every module of Pokemon Black.

Produces build/reference/ containing:
  main.bin            decompressed ARM9 (loads at 0x02004000)
  ov000.bin..ov236.bin  each overlay, BLZ-decompressed where flagged
  manifest.json       {module: {ram, size, rom_offset, compressed, file_id}}

Also writes build/arm9_decompressed.bin for backwards compatibility.

The ARM9 and most overlays are stored BLZ-compressed (backward LZSS).

Usage: python tools/scripts/make_reference.py <rom.nds> [outdir]
"""
import hashlib
import json
import os
import struct
import sys


def blz_decompress(data: bytes) -> bytearray:
    compinfo, extra = struct.unpack("<II", data[-8:])
    header_len = compinfo >> 24
    comp_len = compinfo & 0xFFFFFF
    n = len(data)
    out = bytearray(n + extra)
    out[:n] = data
    src = n - header_len
    dst = n + extra
    stop = n - comp_len
    while src > stop:
        src -= 1
        flags = out[src]
        for _ in range(8):
            if src <= stop:
                break
            if flags & 0x80:
                src -= 2
                info = out[src] | (out[src + 1] << 8)
                length = ((info >> 12) & 0xF) + 3
                disp = (info & 0xFFF) + 3
                for _ in range(length):
                    dst -= 1
                    out[dst] = out[dst + disp]
            else:
                src -= 1
                dst -= 1
                out[dst] = out[src]
            flags = (flags << 1) & 0xFF
    if src != stop or dst != stop:
        raise ValueError(f"BLZ did not converge (src={src:#x} dst={dst:#x} stop={stop:#x})")
    return out


def main() -> int:
    rom_path = sys.argv[1]
    outdir = sys.argv[2] if len(sys.argv) > 2 else "build/reference"
    os.makedirs(outdir, exist_ok=True)
    rom = open(rom_path, "rb").read()

    manifest = {}

    arm9_off, _, arm9_ram, arm9_size = struct.unpack("<4I", rom[0x20:0x30])
    fat_off, fat_size = struct.unpack("<2I", rom[0x48:0x50])
    ov9_off, ov9_size = struct.unpack("<2I", rom[0x50:0x58])

    arm9 = blz_decompress(rom[arm9_off : arm9_off + arm9_size])
    open(os.path.join(outdir, "main.bin"), "wb").write(arm9)
    open("build/arm9_decompressed.bin", "wb").write(arm9)
    manifest["main"] = dict(ram=arm9_ram, size=len(arm9), rom_offset=arm9_off,
                            compressed=True, file_id=None,
                            sha1=hashlib.sha1(arm9).hexdigest())
    print(f"main   ram {arm9_ram:#010x}  {arm9_size:#x} -> {len(arm9):#x}  sha1 {manifest['main']['sha1'][:12]}")

    def fat_entry(fid):
        o = fat_off + fid * 8
        start, end = struct.unpack("<2I", rom[o : o + 8])
        return start, end

    n_ov = ov9_size // 32
    failed = []
    for i in range(n_ov):
        e = rom[ov9_off + i * 32 : ov9_off + (i + 1) * 32]
        ov_id, ram, ram_size, bss, si0, si1, fid, flags = struct.unpack("<8I", e)
        start, end = fat_entry(fid)
        raw = rom[start:end]
        comp_size = flags & 0xFFFFFF
        is_comp = bool(flags & 0x01000000)
        try:
            data = blz_decompress(raw[:comp_size] if comp_size else raw) if is_comp else bytearray(raw)
        except Exception as ex:
            failed.append((ov_id, str(ex)))
            continue
        name = f"ov{ov_id:03d}"
        open(os.path.join(outdir, name + ".bin"), "wb").write(data)
        manifest[name] = dict(ram=ram, size=len(data), rom_offset=start,
                              compressed=is_comp, file_id=fid,
                              bss=bss, static_init=[si0, si1],
                              sha1=hashlib.sha1(data).hexdigest())

    with open(os.path.join(outdir, "manifest.json"), "w") as f:
        json.dump(manifest, f, indent=1)

    total = sum(m["size"] for m in manifest.values())
    print(f"extracted {len(manifest)} modules ({total} bytes / {total/2**20:.2f} MiB) -> {outdir}")
    if failed:
        print(f"FAILED overlays: {failed}")
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
