# Visual Roadmap

- Purpose: phased plan for diagrams, interactive teaching widgets, and visual infrastructure across the docs site
- Scope: `topics/`, route pages, overview pages, and the supporting site asset pipeline under `docs-assets/`
- Doc type: planning
- Owner: repo maintainer
- Status: active
- Last reviewed: 2026-04-26
- Update triggers: after any new visual wave, major site-asset change, or reprioritization of the visualization backlog
- Canonical companion docs: [Roadmap](roadmap.md), [Expansion Roadmap](expansion-roadmap.md), [Content Blueprint](content-blueprint.md), [Topic Template](topic-template.md), [Visual Content Contract](visual-content-contract.md), [Source Map](source-map.md)

This file exists so the repo’s visual layer grows like the curriculum does: deliberately, with clear tool choices and maintenance boundaries.

## Current Position

The repo already has the first proof that interactive visuals are useful here:

- [BFS And DFS](../topics/graphs/bfs-dfs/README.md)
- [Fenwick Tree](../topics/data-structures/fenwick-tree/README.md)
- [Segment Tree](../topics/data-structures/segment-tree/README.md)
- [Binary Search](../topics/foundations/patterns/binary-search/README.md)
- [Lazy Segment Tree](../topics/data-structures/lazy-segment-tree/README.md)
- [Euler Tour / Subtree Queries](../topics/graphs/euler-tour-subtree/README.md)
- [Two Pointers And Sliding Window](../topics/foundations/patterns/two-pointers/README.md)
- [Bridges, Articulation Points, And Biconnected Components](../topics/graphs/bridges-articulation/README.md)
- [Aho-Corasick](../topics/strings/aho-corasick/README.md)
- [Maximum Flow](../topics/graphs/flow/README.md)
- [Suffix Automaton](../topics/strings/suffix-automaton/README.md)

Those pages confirm two things:

1. small page-local widgets can materially improve understanding
2. the site should not drift into a full frontend app

The visual stack should therefore optimize for:

- static GitHub Pages deployment
- low maintenance overhead
- reusable patterns
- page-scoped loading
- visuals that teach invariants, not decorative chrome

## Tool Policy

Use the lightest tool that still teaches the idea cleanly.

| Tool | Default job | Best for | Avoid when |
| --- | --- | --- | --- |
| `Mermaid` or Mermaid-authored SVG | low-maintenance static concept diagram | chooser pages, dependency chains, route diagrams, one-picture-before-code blocks | step-through state, geometry motion, or dense per-step logic |
| `Cytoscape.js` | graph/state-network widget | DFS trees, SCC/2-SAT, automata, flow residual graphs, matching-style exchange graphs | arrays, interval trees, matrix steps, or simple range structures |
| `D3.js` | default interactive explainer | arrays, interval decompositions, rooted trees, masks, matrix elimination, sweep-of-state widgets | pages that only need one static concept diagram |
| `Observable Plot` | chart / compare visual | probability mass, convergence curves, compare pages, cost/benefit charts, envelope plots | graph/network structure or algorithm traces with many local state transitions |
| `p5.js` | motion-heavy geometry fallback | moving sweeps, point motion, candidate-window geometry, turn/pop hull animation | anything that can be taught just as well with SVG or D3 |

Rule of thumb:

- `Mermaid/SVG` first
- `D3.js` second
- `Cytoscape.js` only for true graph objects
- `Observable Plot` only for chart-first explanations
- `p5.js` only when motion is the lesson

## Phase 0: Infrastructure

This is the mandatory foundation pass before many more visuals are added.

### Goals

- make visuals scale without bloating every page
- keep the site fast on GitHub Pages
- keep authoring simple for future topic passes

### Required Outcomes

- move from many global `extra_javascript` entries to one small page-asset loader
- load `MathJax`, `Problem Finder`, and page-local widgets only when the current page actually needs them
- switch Mermaid from runtime page rendering to build-time SVG generation
- document the page-marker pattern for future widgets

### Preferred Architecture

- author Mermaid diagrams as `.mmd` files under `docs-assets/mermaid/`
- render those sources into committed SVGs under `docs/assets/figures/mermaid/` during CI and local build work
- embed the generated SVGs in docs pages like ordinary images
- keep one global loader script in `extra_javascript`
- use page markers such as:
  - `.arithmatex`
  - `#problem-finder-root`
  - `data-*-visualizer` roots
- keep small page-local widget files under `docs-assets/javascripts/`
- lazy-load external runtimes only when the current page actually needs them

### Phase 0 Guardrails

- no frontend framework
- no global graph/chart runtime on every page
- no data-heavy fetches on ordinary topic pages
- no visual that exists only to look impressive

## Phase 1: Static Diagram Wave

Goal: improve readability fast with very low maintenance cost.

Primary targets:

- [docs/start-here.md](start-here.md)
- [docs/route-map.md](route-map.md)
- [topics/dp/foundations/README.md](../topics/dp/foundations/README.md)
- [topics/graphs/shortest-paths/README.md](../topics/graphs/shortest-paths/README.md)
- [topics/foundations/patterns/difference-arrays/README.md](../topics/foundations/patterns/difference-arrays/README.md)
- overview pages in `topics/*/README.md` that still benefit from one route diagram

Default tool:

- `Mermaid` during authoring, with a bias toward stable rendered output

## Phase 2: Core D3 Wave

Goal: establish one reusable pattern for array / interval / tree-state visuals.

Highest-value targets:

- [topics/foundations/patterns/binary-search/README.md](../topics/foundations/patterns/binary-search/README.md)
- [topics/data-structures/lazy-segment-tree/README.md](../topics/data-structures/lazy-segment-tree/README.md)
- [topics/graphs/euler-tour-subtree/README.md](../topics/graphs/euler-tour-subtree/README.md)
- [topics/foundations/patterns/two-pointers/README.md](../topics/foundations/patterns/two-pointers/README.md)

Strong next tier:

- [topics/data-structures/persistent-data-structures/README.md](../topics/data-structures/persistent-data-structures/README.md)
- [topics/data-structures/wavelet-tree/README.md](../topics/data-structures/wavelet-tree/README.md)
- [topics/graphs/hld/README.md](../topics/graphs/hld/README.md)
- [topics/data-structures/dsu-rollback/README.md](../topics/data-structures/dsu-rollback/README.md)

## Phase 3: Graph-State Cytoscape Wave

Goal: give the repo one strong visual language for graph-state algorithms.

Highest-value targets:

- [topics/graphs/bridges-articulation/README.md](../topics/graphs/bridges-articulation/README.md)
- [topics/strings/aho-corasick/README.md](../topics/strings/aho-corasick/README.md)
- [topics/graphs/flow/README.md](../topics/graphs/flow/README.md)
- [topics/strings/suffix-automaton/README.md](../topics/strings/suffix-automaton/README.md)

Strong next tier:

- [topics/graphs/two-sat/README.md](../topics/graphs/two-sat/README.md)
- [topics/math/game-theory/README.md](../topics/math/game-theory/README.md)
- [topics/advanced/matroid-intersection/README.md](../topics/advanced/matroid-intersection/README.md)
- [topics/dp/tree-dp/README.md](../topics/dp/tree-dp/README.md)

## Phase 4: Heavy DP / Math Wave

Goal: add visual support where the state mechanics are the real bottleneck.

Highest-value targets:

- [topics/dp/digit-dp/README.md](../topics/dp/digit-dp/README.md)
- [topics/math/fft-ntt/README.md](../topics/math/fft-ntt/README.md)
- [topics/dp/broken-profile/README.md](../topics/dp/broken-profile/README.md)
- [topics/math/gaussian-elimination/README.md](../topics/math/gaussian-elimination/README.md)

Strong next tier:

- [topics/dp/sos-dp/README.md](../topics/dp/sos-dp/README.md)
- [topics/dp/interval-dp/README.md](../topics/dp/interval-dp/README.md)
- [topics/dp/cht-li-chao/README.md](../topics/dp/cht-li-chao/README.md)
- [topics/math/chinese-remainder/README.md](../topics/math/chinese-remainder/README.md)
- [topics/math/linear-recurrence/README.md](../topics/math/linear-recurrence/README.md)

## Phase 5: Chart Layer

Goal: use low-overhead charts where a simulator is unnecessary.

Primary targets:

- [topics/math/probability/README.md](../topics/math/probability/README.md)
- [topics/advanced/gradient-descent/README.md](../topics/advanced/gradient-descent/README.md)
- [topics/greedy/prefix-constraints/README.md](../topics/greedy/prefix-constraints/README.md)
- [topics/data-structures/balanced-bsts/README.md](../topics/data-structures/balanced-bsts/README.md)

Default tool:

- `Observable Plot`

## Phase 6: Geometry Motion Wave

Goal: open the motion-heavy pages only after the rest of the visual stack is stable.

Primary targets:

- [topics/geometry/sweep-line/README.md](../topics/geometry/sweep-line/README.md)
- [topics/geometry/nearest-pair/README.md](../topics/geometry/nearest-pair/README.md)
- [topics/geometry/convex-hull/README.md](../topics/geometry/convex-hull/README.md)
- [topics/geometry/half-plane-intersection/README.md](../topics/geometry/half-plane-intersection/README.md)

Default tool:

- `D3.js` first
- `p5.js` only if D3 becomes awkward for the interaction

## De-Prioritized Or Minimal-Only Pages

These pages should stay mostly text-first, or at most get one tiny static diagram:

- [topics/foundations/cpp-language/README.md](../topics/foundations/cpp-language/README.md)
- [topics/foundations/reasoning/README.md](../topics/foundations/reasoning/README.md)
- [topics/foundations/bit-tricks/README.md](../topics/foundations/bit-tricks/README.md)
- [topics/data-structures/pbds-order-statistics/README.md](../topics/data-structures/pbds-order-statistics/README.md)
- [topics/data-structures/heaps-and-ordered-sets/README.md](../topics/data-structures/heaps-and-ordered-sets/README.md)
- [topics/graphs/graph-modeling/README.md](../topics/graphs/graph-modeling/README.md)
- [topics/math/modular-arithmetic/README.md](../topics/math/modular-arithmetic/README.md)
- [topics/math/gcd-lcm/README.md](../topics/math/gcd-lcm/README.md)
- [topics/combinatorics/counting-basics/README.md](../topics/combinatorics/counting-basics/README.md)
- [topics/combinatorics/inclusion-exclusion/README.md](../topics/combinatorics/inclusion-exclusion/README.md)

## Authoring Rules

Every new visual should answer at least one of these questions better than prose alone:

- what invariant is preserved?
- what structure is cached?
- how does state move from one step to the next?
- why is this chooser page splitting into these child techniques?

If the visual does not clearly improve one of those, do not ship it.

For the content-level quality bar, use [Visual Content Contract](visual-content-contract.md). This roadmap governs sequencing and tooling; the contract governs whether the visual itself is rich enough to teach.

### Visual Contract

- static first, widget second
- page-scoped loading only
- prefer deterministic, replayable demos over random toys
- keep controls small and task-oriented
- every interactive should degrade gracefully if JS fails

### Build Contract

Before visual work is considered shipped:

- `python3 scripts/render_mermaid.py`
- `python3 scripts/build_site_docs.py`
- `. .venv/bin/activate && mkdocs build --strict`
- `git diff --check`

If the stack grows further, add CI checks for:

- total custom JS size
- largest generated JSON file
- pages that load heavyweight runtimes

## Current Execution Order

If work starts from this file directly, the default order should be:

1. finish `Phase 0`
2. ship one small `Phase 1` diagram wave
3. ship one `Phase 2` D3 widget
4. ship one `Phase 3` Cytoscape widget
5. only then open the heavy DP / math or geometry phases
