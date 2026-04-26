# Learning Areas

This folder is the teaching-first layer of the repository.

Do not try to open all areas at once.

Pick the area that matches your current bottleneck, then stay inside that family until one ladder note feels routine.

## Start With One Area

### Core-first areas

| Area | Start here if you need... | First stop |
| --- | --- | --- |
| `Foundations` | cleaner C++, complexity habits, and bread-and-butter patterns | [Foundations](foundations/README.md) |
| `Data Structures` | standard tools for range queries, connectivity, and updates | [Data Structures](data-structures/README.md) |
| `Graphs` | modeling, traversals, shortest paths, trees, flow, and matching | [Graphs](graphs/README.md) |
| `Dynamic Programming` | state design, transitions, and optimization over structure | [Dynamic Programming](dp/README.md) |
| `Math` | modular arithmetic, combinatorics, and number theory tools | [Math](math/README.md) |
| `Strings` | pattern matching, hashing, tries, and suffix structures | [Strings](strings/README.md) |

### Extension and follow-up areas

| Area | Start here if you need... | First stop |
| --- | --- | --- |
| `Combinatorics` | counting, bounded distributions, and lexicographic enumeration | [Combinatorics](combinatorics/README.md) |
| `Geometry` | vectors, orientation, hulls, and geometric counting | [Geometry](geometry/README.md) |
| `Greedy` | exchange arguments, feasibility-first thinking, and locally safe choices | [Greedy](greedy/README.md) |
| `Advanced` | randomized algorithms, approximation, complexity, and algorithm design depth | [Advanced](advanced/README.md) |

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

| Family starts feeling fragmented | Reopen this bridge | Then branch into... |
| --- | --- | --- |
| trees | [Trees](graphs/trees/README.md) | subtree queries, LCA, HLD, virtual tree, tree DP |
| flow and cuts | [Maximum Flow](graphs/flow/README.md) | lower bounds, Gomory-Hu, global min-cut, min-cost flow |
| divisibility and congruences | [GCD / LCM](math/gcd-lcm/README.md) | CRT, modular arithmetic, prime-exponent constructions |
| transform-heavy algebra | [FFT / NTT](math/fft-ntt/README.md) | polynomial / FPS |
| bit-state techniques | [Bit Tricks](foundations/bit-tricks/README.md) | bitmask DP, SOS, FWHT, xor basis, bit-parallelism |
| explicit search trees | [Recursion And Backtracking](foundations/recursion-backtracking/README.md) | bitmask DP, meet-in-the-middle, complexity triage |
| monotone scans | [Monotonic Stack / Queue](data-structures/monotonic-stack-queue/README.md) | nearest boundary, sliding extrema, histogram-style problems |

## Representative Repo Anchors

Use these if you want one concrete repo-native anchor before diving into a whole area:

- Data Structures: [CVP00001](../practice/ladders/data-structures/fenwick-tree/cvp00001.md)
- Graphs: [QOS](../practice/ladders/graphs/shortest-paths/qos.md), [MINCOST](../practice/ladders/graphs/flow/mincost.md)
- Dynamic Programming: [TFIELD](../practice/ladders/dp/sliding-window/tfield.md)
- Math: [CRYPTKEY](../practice/ladders/math/gcd-lcm/cryptkey.md), [POST2](../practice/ladders/math/fft/post2.md)
- Geometry: [PRAVO](../practice/ladders/geometry/right-triangles/pravo.md), [KINGDOMS](../practice/ladders/geometry/sweep-line/kingdoms.md)
- Greedy: [Lemonade Line](../practice/ladders/greedy/prefix-constraints/lemonadeline.md)
- Advanced: [Minimum Euclidean Distance](../practice/ladders/advanced/algorithm-engineering/minimumeuclideandistance.md)

Use [docs/topic-template.md](../docs/topic-template.md) as the source of truth for mature single-topic pages. The area hubs in this folder should stay lighter and focus on routing first.

If you want the whole non-foundational surface in one visual instead of one area at a time, use [Deep Topic Taxonomy](../docs/deep-topic-taxonomy.md).
