# Learning Areas

This folder is the teaching-first layer of the repository.

Do not try to open all areas at once.

Pick the area that matches your current bottleneck, then stay inside that family until one ladder note feels routine.

## Tier Guide

<div class="badge-row" markdown>
  <span class="route-badge route-badge--core">Core</span>
  <span class="route-badge route-badge--bridge">Bridge</span>
  <span class="route-badge route-badge--deep">Deep</span>
  <span class="route-badge route-badge--enrichment">Enrichment</span>
</div>

## Start With One Area

### Core-first areas

| Area | Tier | Start here if you need... | First stop |
| --- | --- | --- |
| `Foundations` | <span class="route-badge route-badge--core">Core</span> | cleaner C++, complexity habits, and bread-and-butter patterns | [Foundations](foundations/README.md) |
| `Data Structures` | <span class="route-badge route-badge--core">Core</span> | standard tools for range queries, connectivity, and updates | [Data Structures](data-structures/README.md) |
| `Graphs` | <span class="route-badge route-badge--core">Core</span> <span class="route-badge route-badge--bridge">Bridge</span> | modeling, traversals, shortest paths, trees, flow, and matching | [Graphs](graphs/README.md) |
| `Dynamic Programming` | <span class="route-badge route-badge--core">Core</span> <span class="route-badge route-badge--deep">Deep</span> | state design, transitions, and optimization over structure | [Dynamic Programming](dp/README.md) |
| `Math` | <span class="route-badge route-badge--core">Core</span> <span class="route-badge route-badge--deep">Deep</span> | modular arithmetic, combinatorics, and number theory tools | [Math](math/README.md) |
| `Strings` | <span class="route-badge route-badge--core">Core</span> <span class="route-badge route-badge--deep">Deep</span> | pattern matching, hashing, tries, and suffix structures | [Strings](strings/README.md) |

### Extension and follow-up areas

| Area | Tier | Start here if you need... | First stop |
| --- | --- | --- |
| `Combinatorics` | <span class="route-badge route-badge--bridge">Bridge</span> <span class="route-badge route-badge--deep">Deep</span> | counting, bounded distributions, and lexicographic enumeration | [Combinatorics](combinatorics/README.md) |
| `Geometry` | <span class="route-badge route-badge--deep">Deep</span> | vectors, orientation, hulls, and geometric counting | [Geometry](geometry/README.md) |
| `Greedy` | <span class="route-badge route-badge--core">Core</span> <span class="route-badge route-badge--bridge">Bridge</span> | exchange arguments, feasibility-first thinking, and locally safe choices | [Greedy](greedy/README.md) |
| `Advanced` | <span class="route-badge route-badge--enrichment">Enrichment</span> | randomized algorithms, approximation, complexity, and algorithm design depth | [Advanced](advanced/README.md) |

## Learn -> Practice -> Retrieve

Use the repo layers in this order whenever possible:

| Layer | Main question | Best door |
| --- | --- | --- |
| `Learn` | what is the idea and why does it work? | one area page here, then one leaf topic |
| `Practice` | where do I solve the idea on purpose? | the corresponding [ladder](../practice/ladders/README.md), then one anchored note |
| `Retrieve` | what is the shortest way back under pressure? | [Build Kit](../docs/build-kit.md) |

If you already know the weak topic and just need the next problem set, jump to [Problem Finder](../docs/problem-finder.md) instead of browsing area pages.

## High-Value Bridge Pages

When one family feels wider than your mental map, reopen the bridge page first instead of clicking random leaf topics.

| Family starts feeling fragmented | Tier | Reopen this bridge | Then branch into... |
| --- | --- | --- |
| trees | <span class="route-badge route-badge--bridge">Bridge</span> | [Trees](graphs/trees/README.md) | subtree queries, LCA, HLD, virtual tree, tree DP |
| flow and cuts | <span class="route-badge route-badge--bridge">Bridge</span> | [Maximum Flow](graphs/flow/README.md) | lower bounds, Gomory-Hu, global min-cut, min-cost flow |
| divisibility and congruences | <span class="route-badge route-badge--bridge">Bridge</span> | [GCD / LCM](math/gcd-lcm/README.md) | CRT, modular arithmetic, prime-exponent constructions |
| transform-heavy algebra | <span class="route-badge route-badge--bridge">Bridge</span> | [FFT / NTT](math/fft-ntt/README.md) | polynomial / FPS |
| bit-state techniques | <span class="route-badge route-badge--bridge">Bridge</span> | [Bit Tricks](foundations/bit-tricks/README.md) | bitmask DP, SOS, FWHT, xor basis, bit-parallelism |
| explicit search trees | <span class="route-badge route-badge--bridge">Bridge</span> | [Recursion And Backtracking](foundations/recursion-backtracking/README.md) | bitmask DP, meet-in-the-middle, complexity triage |
| monotone scans | <span class="route-badge route-badge--bridge">Bridge</span> | [Monotonic Stack / Queue](data-structures/monotonic-stack-queue/README.md) | nearest boundary, sliding extrema, histogram-style problems |

If you want the whole non-foundational surface in one visual instead of one area at a time, use [Deep Topic Taxonomy](../docs/deep-topic-taxonomy.md).
