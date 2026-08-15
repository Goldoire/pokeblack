#!/usr/bin/env python3
"""Render the progress dashboard as a self-contained HTML page.

Every number is read from the verifier via progress.collect(), never typed by
hand, so a redeploy cannot drift from what the ROM actually says.

  python tools/scripts/make_dashboard.py [out.html]

The climb chart is drawn from build/reference/progress_history.jsonl, which
progress.py appends to on each run.
"""
import datetime
import json
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import progress  # noqa: E402

REF = "build/reference"
OUT = sys.argv[1] if len(sys.argv) > 1 else "build/dashboard.html"

CSS = """
:root {
  --ground:#edeff3; --surface:#ffffff; --sunken:#e3e7ee; --ink:#131923;
  --muted:#5c6779; --faint:#98a1b2; --rule:#d3d9e3;
  --verified:#0e7c63; --hand:#3b4ec0; --accent:#3b4ec0;
  --shadow:0 1px 2px rgba(19,25,35,.06), 0 8px 24px -16px rgba(19,25,35,.35);
  --mono:ui-monospace,"Cascadia Mono","SF Mono",Menlo,Consolas,monospace;
  --sans:"Segoe UI",system-ui,-apple-system,"Helvetica Neue",sans-serif;
}
@media (prefers-color-scheme: dark) {
  :root:not([data-theme="light"]) {
    --ground:#0e121a; --surface:#171d28; --sunken:#10151e; --ink:#e6eaf2;
    --muted:#8b95a8; --faint:#5a6579; --rule:#262e3d;
    --verified:#2fbf9e; --hand:#8291f5; --accent:#8291f5;
    --shadow:0 1px 2px rgba(0,0,0,.4), 0 8px 24px -16px rgba(0,0,0,.8);
  }
}
:root[data-theme="dark"] {
  --ground:#0e121a; --surface:#171d28; --sunken:#10151e; --ink:#e6eaf2;
  --muted:#8b95a8; --faint:#5a6579; --rule:#262e3d;
  --verified:#2fbf9e; --hand:#8291f5; --accent:#8291f5;
  --shadow:0 1px 2px rgba(0,0,0,.4), 0 8px 24px -16px rgba(0,0,0,.8);
}
* { box-sizing:border-box; }
body { margin:0; background:var(--ground); color:var(--ink);
  font-family:var(--sans); font-size:15px; line-height:1.6;
  -webkit-font-smoothing:antialiased; }
.wrap { max-width:1080px; margin:0 auto; padding:40px 24px 80px;
  display:flex; flex-direction:column; gap:40px; }
.eyebrow { font-family:var(--mono); font-size:11px; letter-spacing:.14em;
  text-transform:uppercase; color:var(--muted); margin:0; }
header { display:flex; flex-direction:column; gap:6px; }
header h1 { font-family:var(--mono); font-size:clamp(26px,4vw,38px); font-weight:600;
  letter-spacing:-.02em; margin:0; text-wrap:balance; }
header .sub { color:var(--muted); margin:0; max-width:64ch; }
.hero { background:var(--surface); border:1px solid var(--rule); border-radius:4px;
  box-shadow:var(--shadow); padding:28px; display:flex; flex-direction:column; gap:20px; }
.readout { display:flex; align-items:baseline; gap:16px; flex-wrap:wrap; }
.pct { font-family:var(--mono); font-size:clamp(48px,9vw,78px); font-weight:600;
  letter-spacing:-.04em; line-height:.9; color:var(--verified);
  font-variant-numeric:tabular-nums; }
.readout .of { color:var(--muted); font-size:15px; }
.readout .of b { color:var(--ink); font-family:var(--mono); font-weight:600; }
.territory { position:relative; height:26px; background:var(--sunken);
  border:1px solid var(--rule); border-radius:2px; overflow:hidden; }
.territory .fill { position:absolute; inset:0 auto 0 0; background:var(--verified); }
.territory .ticks { position:absolute; inset:0; display:flex; }
.territory .ticks span { flex:1; border-right:1px solid var(--rule); opacity:.55; }
.territory .ticks span:last-child { border-right:0; }
.scale { display:flex; justify-content:space-between; font-family:var(--mono);
  font-size:11px; color:var(--faint); font-variant-numeric:tabular-nums; padding-top:5px; }
.stats { display:grid; grid-template-columns:repeat(auto-fit,minmax(150px,1fr));
  gap:1px; background:var(--rule); border:1px solid var(--rule);
  border-radius:3px; overflow:hidden; }
.stat { background:var(--surface); padding:14px 16px; display:flex;
  flex-direction:column; gap:2px; }
.stat .k { font-family:var(--mono); font-size:10.5px; letter-spacing:.12em;
  text-transform:uppercase; color:var(--muted); }
.stat .v { font-family:var(--mono); font-size:21px; font-weight:600;
  font-variant-numeric:tabular-nums; letter-spacing:-.02em; }
.stat .n { font-size:12.5px; color:var(--faint); }
.stat .v.good { color:var(--verified); } .stat .v.hand { color:var(--hand); }
section { display:flex; flex-direction:column; gap:14px; }
section > h2 { font-family:var(--mono); font-size:13px; font-weight:600;
  letter-spacing:.1em; text-transform:uppercase; margin:0; padding-bottom:8px;
  border-bottom:1px solid var(--rule); }
section > .lede { margin:0; color:var(--muted); max-width:70ch; }
.climb { background:var(--surface); border:1px solid var(--rule); border-radius:4px;
  padding:20px; box-shadow:var(--shadow); overflow-x:auto; }
.climb svg { display:block; width:100%; min-width:520px; height:180px; }
.modules { border:1px solid var(--rule); border-radius:4px; overflow:hidden;
  background:var(--surface); box-shadow:var(--shadow); }
.mrow { display:grid; grid-template-columns:74px 1fr 96px 66px; align-items:center;
  gap:14px; padding:9px 16px; border-bottom:1px solid var(--rule); }
.mrow:last-child { border-bottom:0; }
.mrow .name { font-family:var(--mono); font-size:13px; font-weight:600; }
.mrow .name.rest { font-weight:400; color:var(--muted); }
.mrow .size { font-family:var(--mono); font-size:11.5px; color:var(--faint);
  text-align:right; font-variant-numeric:tabular-nums; }
.mrow .pctcell { font-family:var(--mono); font-size:12px; text-align:right;
  font-variant-numeric:tabular-nums; color:var(--muted); }
.mrow .pctcell.on { color:var(--verified); font-weight:600; }
.track { position:relative; height:15px; background:var(--sunken); border-radius:2px; }
.track .span { position:absolute; inset:0 auto 0 0; background:var(--rule); border-radius:2px; }
.track .done { position:absolute; inset:0 auto 0 0; background:var(--verified);
  border-radius:2px; min-width:2px; }
.track .handpip { position:absolute; top:-3px; bottom:-3px; width:2px;
  background:var(--hand); border-radius:1px; }
.legend { display:flex; gap:18px; flex-wrap:wrap; font-size:12.5px; color:var(--muted); }
.legend i { display:inline-block; width:10px; height:10px; border-radius:2px;
  margin-right:6px; vertical-align:-1px; }
.tablewrap { overflow-x:auto; border:1px solid var(--rule); border-radius:4px;
  background:var(--surface); box-shadow:var(--shadow); }
table { border-collapse:collapse; width:100%; font-variant-numeric:tabular-nums; }
th, td { text-align:right; padding:9px 14px; border-bottom:1px solid var(--rule);
  white-space:nowrap; }
th:first-child, td:first-child { text-align:left; }
th { font-family:var(--mono); font-size:10.5px; letter-spacing:.1em;
  text-transform:uppercase; color:var(--muted); font-weight:600; }
td { font-family:var(--mono); font-size:12.5px; }
tbody tr:last-child td { border-bottom:0; }
td.mod { font-weight:600; } td.hand { color:var(--hand); font-weight:600; }
td.zero { color:var(--faint); }
.notes { display:grid; grid-template-columns:repeat(auto-fit,minmax(258px,1fr)); gap:12px; }
.note { background:var(--surface); border:1px solid var(--rule);
  border-left:2px solid var(--accent); border-radius:3px; padding:14px 16px;
  display:flex; flex-direction:column; gap:4px; }
.note h3 { font-family:var(--mono); font-size:12px; margin:0; letter-spacing:.04em; }
.note p { margin:0; font-size:13.5px; color:var(--muted); }
code.cmd { font-family:var(--mono); font-size:12.5px; background:var(--sunken);
  border:1px solid var(--rule); padding:1px 5px; border-radius:3px; color:var(--ink); }
.cmdblock { font-family:var(--mono); font-size:13px; background:var(--sunken);
  border:1px solid var(--rule); border-radius:4px; padding:12px 14px;
  overflow-x:auto; color:var(--ink); }
footer { color:var(--faint); font-size:12.5px; border-top:1px solid var(--rule);
  padding-top:16px; }
footer .mono { font-family:var(--mono); }
"""


def chart_svg(hist, W=720, H=180):
    padL, padR, padT, padB = 48, 18, 16, 30
    if len(hist) < 2:
        return ('<svg viewBox="0 0 720 180"><text x="360" y="90" text-anchor="middle" '
                'font-family="var(--mono)" font-size="12" fill="var(--faint)">'
                'not enough history yet</text></svg>')
    vals = [p["hand"] for p in hist]
    top = max(max(vals) * 1.18, 1)
    n = len(hist)

    def X(i):
        return padL + (W - padL - padR) * (i / (n - 1))

    def Y(v):
        return H - padB - (H - padT - padB) * (v / top)

    g = []
    for i in range(4):
        v = round(top * i / 3)
        g.append(f'<line x1="{padL}" y1="{Y(v):.1f}" x2="{W - padR}" y2="{Y(v):.1f}" '
                 f'stroke="var(--rule)" stroke-width="1"/>')
        g.append(f'<text x="{padL - 8}" y="{Y(v) + 4:.1f}" text-anchor="end" '
                 f'font-family="var(--mono)" font-size="10" fill="var(--faint)">{v}</text>')
    line = " ".join(("M" if i == 0 else "L") + f"{X(i):.1f},{Y(p['hand']):.1f}"
                    for i, p in enumerate(hist))
    g.append(f'<path d="{line} L{X(n - 1):.1f},{Y(0):.1f} L{X(0):.1f},{Y(0):.1f} Z" '
             f'fill="var(--hand)" opacity=".13"/>')
    g.append(f'<path d="{line}" fill="none" stroke="var(--hand)" stroke-width="2" '
             f'stroke-linejoin="round" stroke-linecap="round"/>')
    for i, p in enumerate(hist):
        last = i == n - 1
        g.append(f'<circle cx="{X(i):.1f}" cy="{Y(p["hand"]):.1f}" r="{5 if last else 3}" '
                 f'fill="{"var(--hand)" if last else "var(--surface)"}" '
                 f'stroke="var(--hand)" stroke-width="2"/>')
        g.append(f'<text x="{X(i):.1f}" y="{H - 9}" text-anchor="middle" '
                 f'font-family="var(--mono)" font-size="10" fill="var(--faint)">'
                 f'{p["label"]}</text>')
    lastp = hist[-1]
    g.append(f'<text x="{X(n - 1) - 12:.1f}" y="{Y(lastp["hand"]) - 13:.1f}" '
             f'text-anchor="end" font-family="var(--mono)" font-size="12" '
             f'font-weight="600" fill="var(--hand)">{lastp["hand"]} hand-written</text>')
    return (f'<svg viewBox="0 0 {W} {H}" role="img" aria-label="Hand-written verified '
            f'functions across successive measurements">' + "".join(g) + "</svg>")


def main():
    fns = json.load(open(os.path.join(REF, "functions.json")))
    verified, pending = progress.collect()

    rows = []
    for mod, lst in fns.items():
        by_ram = {f["ram"]: f["size"] for f in lst}
        sdk = {f["ram"] for f in lst if f["status"].startswith("matched_sdk")}
        hand = {a for a in verified.get(mod, {}) if a in by_ram}
        addrs = sdk | hand
        rows.append(dict(m=mod, fns=len(lst), bytes=sum(by_ram.values()),
                         done=len(addrs), done_bytes=sum(by_ram[a] for a in addrs),
                         hand=len(hand), sdk=len(sdk)))
    rows.sort(key=lambda r: -r["bytes"])
    tb = sum(r["bytes"] for r in rows)
    db = sum(r["done_bytes"] for r in rows)
    tf = sum(r["fns"] for r in rows)
    df = sum(r["done"] for r in rows)
    th = sum(r["hand"] for r in rows)
    pct = 100.0 * db / tb

    shown = [r for r in rows if r["done"]][:16]
    shown_set = {r["m"] for r in shown}
    rest = [r for r in rows if r["m"] not in shown_set]
    widest = max(r["bytes"] for r in shown) if shown else 1

    hist = []
    hp = os.path.join(REF, "progress_history.jsonl")
    if os.path.exists(hp):
        with open(hp) as fh:
            for line in fh:
                line = line.strip()
                if line:
                    hist.append(json.loads(line))
    for i, p in enumerate(hist):
        p["label"] = p.get("label") or (
            "start" if i == 0 else ("now" if i == len(hist) - 1 else f"#{i + 1}"))

    def N(x):
        return f"{x:,}"

    mrows = []
    for r in shown:
        share = 100.0 * r["bytes"] / widest
        filled = 100.0 * r["done_bytes"] / r["bytes"] if r["bytes"] else 0
        donew = share * filled / 100.0
        p = filled
        pip = (f'<span class="handpip" style="left:{max(donew, 0.35):.3f}%"></span>'
               if r["hand"] else "")
        mrows.append(f"""      <div class="mrow">
        <span class="name">{r['m']}</span>
        <span class="track"><span class="span" style="width:{share:.3f}%"></span>
          <span class="done" style="width:{donew:.3f}%"></span>{pip}</span>
        <span class="size">{N(r['bytes'])} B</span>
        <span class="pctcell{' on' if p >= 0.5 else ''}">{p:.2f}%</span>
      </div>""")
    rb = sum(r["bytes"] for r in rest)
    if rest:
        mrows.append(f"""      <div class="mrow">
        <span class="name rest">+{len(rest)} more</span>
        <span class="track"><span class="span"
          style="width:{100.0 * rb / widest:.3f}%"></span></span>
        <span class="size">{N(rb)} B</span>
        <span class="pctcell">0.00%</span>
      </div>""")

    trows = []
    for r in shown:
        p = 100.0 * r["done_bytes"] / r["bytes"] if r["bytes"] else 0
        trows.append(
            f'<tr><td class="mod">{r["m"]}</td><td>{N(r["fns"])}</td>'
            f'<td>{N(r["done"])}</td>'
            f'<td class="{"hand" if r["hand"] else "zero"}">{r["hand"] or "&mdash;"}</td>'
            f'<td class="{"" if r["sdk"] else "zero"}">{r["sdk"] or "&mdash;"}</td>'
            f'<td>{N(r["bytes"])}</td><td>{N(r["done_bytes"])}</td>'
            f'<td>{p:.2f}%</td></tr>')

    stamp = datetime.datetime.now().strftime("%Y-%m-%d %H:%M")
    html = f"""<title>Reclaiming IRBO</title>
<style>{CSS}</style>
<div class="wrap">
  <header>
    <p class="eyebrow">Pok&eacute;mon Black &middot; gamecode IRBO &middot; matching decompilation</p>
    <h1>Reclaiming IRBO</h1>
    <p class="sub">Every byte below was compiled from C and byte-compared against the
      retail ROM. Nothing counts until the verifier reports it identical &mdash;
      near-misses score zero.</p>
  </header>

  <div class="hero">
    <div class="readout">
      <span class="pct">{pct:.3f}%</span>
      <span class="of">of the ROM's machine code reproduced exactly<br>
        <b>{N(db)}</b> of <b>{N(tb)}</b> bytes</span>
    </div>
    <div>
      <div class="territory">
        <div class="fill" style="width:{max(pct, 0.25):.3f}%"></div>
        <div class="ticks">{'<span></span>' * 24}</div>
      </div>
      <div class="scale"><span>0</span><span>{N(tb)} bytes across {len(rows)} modules</span></div>
    </div>
    <div class="stats">
      <div class="stat"><span class="k">Bytes verified</span>
        <span class="v good">{N(db)}</span><span class="n">of {N(tb)}</span></div>
      <div class="stat"><span class="k">Functions verified</span>
        <span class="v">{N(df)}</span><span class="n">of {N(tf)}</span></div>
      <div class="stat"><span class="k">Hand-written</span>
        <span class="v hand">{N(th)}</span><span class="n">decompiled, not swept</span></div>
      <div class="stat"><span class="k">Modules touched</span>
        <span class="v">{len(shown)}</span><span class="n">of {len(rows)}</span></div>
    </div>
  </div>

  <section>
    <h2>The climb</h2>
    <p class="lede">Hand-written verified functions across successive measurements.
      The flat opening is the pipeline being built and proven; the steep part is
      twelve worker agents landing matches against a loop that works.</p>
    <div class="climb">{chart_svg(hist)}</div>
  </section>

  <section>
    <h2>Territory</h2>
    <p class="lede">Bar extent is the module's share of the ROM &mdash; largest first,
      which is also the work queue. Fill is what has been verified byte-exact. The
      indigo pip marks modules with hand-decompiled code, as opposed to functions
      recovered by matching Nintendo's own SDK source.</p>
    <div class="modules">
{chr(10).join(mrows)}
    </div>
    <div class="legend">
      <span><i style="background:var(--verified)"></i>verified byte-exact</span>
      <span><i style="background:var(--rule)"></i>module extent</span>
      <span><i style="background:var(--hand)"></i>hand-decompiled</span>
    </div>
  </section>

  <section>
    <h2>Modules with verified code</h2>
    <div class="tablewrap"><table>
      <thead><tr><th>Module</th><th>Functions</th><th>Verified</th><th>Hand</th>
        <th>SDK</th><th>Bytes</th><th>Verified</th><th>%</th></tr></thead>
      <tbody>{''.join(trows)}</tbody>
    </table></div>
  </section>

  <section>
    <h2>Settled &mdash; do not re-investigate</h2>
    <div class="notes">
      <div class="note"><h3>Game code is Thumb</h3>
        <p>81.6% of claim-table entries. The Makefile's flags are ARM-only, and
           compiling a Thumb function as ARM scores 0%, not a near-miss.</p></div>
      <div class="note"><h3>The verifier had a bug</h3>
        <p>It recomputed every Thumb call as <code class="cmd">BL</code>, but the linker
           emits <code class="cmd">BLX</code> for Thumb&rarr;ARM. Any function calling SDK
           code failed however correct the C was.</p></div>
      <div class="note"><h3>The Thumb SDK sweep is a dud</h3>
        <p>Recompiling the SDK as Thumb yields 31 new placements / 760 bytes against
           the ARM sweep's 638. Closed.</p></div>
      <div class="note"><h3>174 entries aren't C</h3>
        <p>Linker veneers, jump islands and misidentified data sit in the claim table.
           Triage labels them so workers skip them.</p></div>
    </div>
  </section>

  <section>
    <h2>Watch it move</h2>
    <p class="lede">This page is a snapshot &mdash; a published page cannot reach the
      local build. For a live readout, run the watcher in the repo; it re-verifies
      against the ROM and redraws on an interval.</p>
    <div class="cmdblock">python tools/scripts/watch_progress.py 30</div>
  </section>

  <footer>generated {stamp} from
    <span class="mono">tools/scripts/verify_functions.py</span> &middot;
    branch <span class="mono">decomp/swarm</span> &middot;
    {len(pending)} unverified objects excluded</footer>
</div>
"""
    os.makedirs(os.path.dirname(OUT) or ".", exist_ok=True)
    with open(OUT, "w", encoding="utf-8") as fh:
        fh.write(html)
    print(f"wrote {OUT}  ({pct:.3f}%, {db:,}/{tb:,} bytes, {th} hand-written)")


if __name__ == "__main__":
    main()
