# Build Kit

Use this page when the algorithm is mostly known and the bottleneck is now:

- implementing it cleanly
- reopening the right snippet quickly
- checking one invariant under pressure
- stabilizing a suspicious solution locally

This is the repo's `retrieve and execute` layer.

## Quick Split

- `Notebook` = recall the invariant, signal, or trap
- `Template Library` = retrieve the smallest reusable snippet
- `Build Kit` = choose between notebook, templates, and workflow pages

## What Lives Here

| Need | Best door |
| --- | --- |
| reusable contest code | [Template Library](../template-library.md) |
| short invariant/trap reminders | [Notebook](../notebook/README.md) |
| debug a suspicious implementation | [Stress testing workflow](../notebook/stress-testing-workflow.md) |
| validator-heavy / interactive / many-valid-answers local loop | [Local judge workflow](../notebook/local-judge-workflow.md) |
| before-contest checklist | [Contest checklist](../notebook/contest-checklist.md) |

## Exact Starter Routes

Use these when the topic is already mostly trusted and you want the shortest path back to code plus one concrete compare target.

| Need | Learn / check first | Reuse | Compare against |
| --- | --- | --- | --- |
| point updates plus prefix/range sums | [Fenwick hot sheet](../notebook/fenwick-hot-sheet.md) | [fenwick-point-prefix.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/fenwick-point-prefix.cpp) | [CVP00001](../practice/ladders/data-structures/fenwick-tree/cvp00001.md) |
| merge-only connectivity or Kruskal-style components | [DSU hot sheet](../notebook/dsu-hot-sheet.md) | [dsu-basic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/dsu-basic.cpp) | [C11XU](../practice/ladders/data-structures/dsu/c11xu.md) |
| static range minimum on immutable data | [Sparse Table hot sheet](../notebook/sparse-table-hot-sheet.md) | [sparse-table-rmq.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/sparse-table-rmq.cpp) | [Static Range Minimum Queries](../practice/ladders/data-structures/sparse-table/staticrangeminimumqueries.md) |
| one-key monotone offline sweep | [Offline Tricks hot sheet](../notebook/offline-tricks-hot-sheet.md) | [offline-query-skeleton.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/offline-query-skeleton.cpp) | [Distinct Values Queries](../practice/ladders/data-structures/offline-tricks/distinctvaluesqueries.md) |
| bipartite maximum matching with explicit pairs | [Matching hot sheet](../notebook/matching-hot-sheet.md) | [hopcroft-karp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hopcroft-karp.cpp) | [School Dance](../practice/ladders/graphs/matching/schooldance.md) |
| exact one-pattern matching | [KMP](../topics/strings/kmp/README.md) | [kmp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/kmp.cpp) | [String Matching](../practice/ladders/strings/kmp/stringmatching.md) |
| many lowercase patterns against one text | [Aho-Corasick hot sheet](../notebook/aho-corasick-hot-sheet.md) | [aho-corasick.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/aho-corasick.cpp) | [Finding Patterns](../practice/ladders/strings/aho-corasick/findingpatterns.md) |
| exact suffix order plus LCP | [Suffix Array / LCP hot sheet](../notebook/suffix-array-lcp-hot-sheet.md) | [suffix-array.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/suffix-array.cpp) | [Repeating Substring](../practice/ladders/strings/suffix-array-lcp/repeatingsubstring.md) |
| static tree, point updates, path maximum | [HLD hot sheet](../notebook/hld-hot-sheet.md) | [hld-path-max.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hld-path-max.cpp) | [Path Queries II](../practice/ladders/graphs/hld/pathqueries2.md) |
| all-roots sum of distances on a tree | [Tree DP](../topics/dp/tree-dp/README.md) | [tree-dp-rerooting.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/tree-dp-rerooting.cpp) | [Tree Distances II](../practice/ladders/dp/tree-dp/treedistances2.md) |
| fixed-value costed flow with nonnegative initial forward costs | [Min-Cost Flow hot sheet](../notebook/min-cost-flow-hot-sheet.md) | [min-cost-flow.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/min-cost-flow.cpp) | [MINCOST](../practice/ladders/graphs/flow/mincost.md) |
| decimal range counting with a small digit state | [Digit DP hot sheet](../notebook/digit-dp-hot-sheet.md) | [digit-dp-skeleton.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/digit-dp-skeleton.cpp) | [Counting Numbers](../practice/ladders/dp/digit-dp/countingnumbers.md) |
| fixed-size window minimum on a forward-only stream | [Data structures cheatsheet](../notebook/data-structures-cheatsheet.md) | [monotonic-deque-min.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/monotonic-deque-min.cpp) | [Sliding Window Minimum](../practice/ladders/dp/sliding-window/slidingwindowminimum.md) |
| same-length substring fingerprints | [String Hashing hot sheet](../notebook/string-hashing-hot-sheet.md) | [rolling-hash.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/rolling-hash.cpp) | [Finding Borders](../practice/ladders/strings/hashing/findingborders.md) |
| exact convolution modulo `998244353` | [FFT / NTT](../topics/math/fft-ntt/README.md) | [ntt.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/ntt.cpp) | [POST2](../practice/ladders/math/fft/post2.md) |
| one inverse under composite modulus or `ax + by = c` | [Modular Arithmetic hot sheet](../notebook/modular-arithmetic-hot-sheet.md) | [extended-gcd-diophantine.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/extended-gcd-diophantine.cpp) | no exact repo note yet; reopen [Modular Arithmetic](../topics/math/modular-arithmetic/README.md) |

## Choose The Smallest Useful Tool

### Template Library

Open [Template Library](../template-library.md) when:

- you already know the family
- you want the smallest contest-ready implementation
- you need one fast chooser table, not a tutorial
- you already have a topic page or note anchor and now need the smallest reusable code shape

Do **not** open it first if you still do not trust the topic itself.

### Notebook

Open [Notebook](../notebook/README.md) when:

- you mostly know the idea
- you need the main invariant, trap, or signal fast
- you want the shortest route back to the right family

Do **not** use it as first exposure.

### Workflows

Open a workflow page when the algorithm feels right but the solution still feels unsafe:

- [Stress testing workflow](../notebook/stress-testing-workflow.md)
- [Local judge workflow](../notebook/local-judge-workflow.md)

## Build Kit Routes

| If the problem feels like... | Open first | Then |
| --- | --- | --- |
| “I know the topic, just give me the snippet” | [Template Library](../template-library.md) | the relevant topic page only if trust is low |
| “I know the topic, but I forgot the invariant” | [Notebook](../notebook/README.md) | the relevant template |
| “The code compiles, but I do not trust it” | [Stress testing workflow](../notebook/stress-testing-workflow.md) | the relevant note or template |
| “This task has a judge/protocol quirk” | [Local judge workflow](../notebook/local-judge-workflow.md) | the relevant playbook or note |

## Best Pairings

- Fenwick / dynamic prefix counts -> [Fenwick hot sheet](../notebook/fenwick-hot-sheet.md) + data-structures templates
- merge-only connectivity -> [DSU hot sheet](../notebook/dsu-hot-sheet.md) + graph/data-structure templates
- static RMQ on immutable data -> [Sparse Table hot sheet](../notebook/sparse-table-hot-sheet.md) + data-structures templates
- reorderable query batches -> [Offline Tricks hot sheet](../notebook/offline-tricks-hot-sheet.md) + data-structures templates
- shortest paths -> [Shortest Paths hot sheet](../notebook/shortest-paths-hot-sheet.md) + graph templates
- tree path queries -> [HLD hot sheet](../notebook/hld-hot-sheet.md) + [Heavy-Light Decomposition](../topics/graphs/hld/README.md)
- range-query structures -> [Segment Tree hot sheet](../notebook/segment-tree-hot-sheet.md) + [Data structures cheatsheet](../notebook/data-structures-cheatsheet.md)
- flow or cuts -> [Flow hot sheet](../notebook/flow-hot-sheet.md) + graph templates
- fixed-value costed transport -> [Min-Cost Flow hot sheet](../notebook/min-cost-flow-hot-sheet.md) + graph templates
- matching -> [Matching hot sheet](../notebook/matching-hot-sheet.md) + [Flow hot sheet](../notebook/flow-hot-sheet.md) when the reduction is ambiguous
- digit-counting over huge ranges -> [Digit DP hot sheet](../notebook/digit-dp-hot-sheet.md) + DP templates
- modular arithmetic -> [Modular Arithmetic hot sheet](../notebook/modular-arithmetic-hot-sheet.md) + math templates
- substring fingerprints -> [String Hashing hot sheet](../notebook/string-hashing-hot-sheet.md) + string templates
- many exact patterns in one text -> [Aho-Corasick hot sheet](../notebook/aho-corasick-hot-sheet.md) + string templates
- exact static suffix structure -> [Suffix Array / LCP hot sheet](../notebook/suffix-array-lcp-hot-sheet.md) + string templates
- geometry predicates -> [Geometry cheatsheet](../notebook/geometry-cheatsheet.md) + geometry templates

## After This Page

- if trust in the snippet is still low, go back to `topics/`
- if you now need the next problem, go to [Problem Finder](problem-finder.md)
- if you want a contest-format workflow, go to [Contest Playbooks](../practice/contest-playbooks/README.md)
