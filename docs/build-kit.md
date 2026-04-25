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
| harden a hack-sensitive or many-answer solution before trusting it | [Anti-Hack Workflow](../notebook/anti-hack-workflow.md) |
| interactive or simulator-style local loop | [Local judge workflow](../notebook/local-judge-workflow.md) |
| predicate-checked batch output or custom-judge legality | [Special Judge / Output Protocol Workflow](../notebook/special-judge-output-protocol-workflow.md) |
| before-contest checklist | [Contest checklist](../notebook/contest-checklist.md) |

## Exact Starter Routes

Use these when the topic is already mostly trusted and you want the shortest path back to code plus one concrete compare target.

| Need | Learn / check first | Reuse | Compare against |
| --- | --- | --- | --- |
| point updates plus prefix/range sums | [Fenwick hot sheet](../notebook/fenwick-hot-sheet.md) | [fenwick-point-prefix.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/fenwick-point-prefix.cpp) | [CVP00001](../practice/ladders/data-structures/fenwick-tree/cvp00001.md) |
| merge-only connectivity or Kruskal-style components | [DSU hot sheet](../notebook/dsu-hot-sheet.md) | [dsu-basic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/dsu-basic.cpp) | [C11XU](../practice/ladders/data-structures/dsu/c11xu.md) |
| offline connectivity under an add/remove edge timeline | [DSU Rollback hot sheet](../notebook/dsu-rollback-hot-sheet.md) | [dsu-rollback-dynamic-connectivity.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/dsu-rollback-dynamic-connectivity.cpp) | [Dynamic Connectivity](../practice/ladders/data-structures/dsu-rollback/dynamicconnectivity.md) |
| one versioned array with point assignment and old-version range sums | [Persistent Data Structures hot sheet](../notebook/persistent-data-structures-hot-sheet.md) | [persistent-segment-tree-point-set-sum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/persistent-segment-tree-point-set-sum.cpp) | [Range Queries and Copies](../practice/ladders/data-structures/persistent-data-structures/rangequeriesandcopies.md) |
| one mutable sequence with cut/paste, insert/erase by position, or split/merge sequence surgery | [Treap / Implicit Treap hot sheet](../notebook/treap-hot-sheet.md) | [implicit-treap-sequence.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/implicit-treap-sequence.cpp) | [Cut and Paste](../practice/ladders/data-structures/treap-implicit/cutandpaste.md) |
| one static array with subarray k-th / count `<= x` / count `== x` queries | [Wavelet Tree hot sheet](../notebook/wavelet-tree-hot-sheet.md) | [wavelet-tree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/wavelet-tree.cpp) | [MKTHNUM - K-th Number](../practice/ladders/data-structures/wavelet-tree/mkthnum.md) |
| one static array with many range queries where add/remove at one endpoint is cheap | [Mo's hot sheet](../notebook/mos-hot-sheet.md) | [mos-algorithm.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/mos-algorithm.cpp) | [Powerful Array](../practice/ladders/data-structures/mos-algorithm/powerfularray.md) |
| one live multiset of integers with insert / erase / max xor queries | [Binary Trie hot sheet](../notebook/binary-trie-hot-sheet.md) | [binary-trie-xor.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/binary-trie-xor.cpp) | [Vasiliy's Multiset](../practice/ladders/data-structures/binary-trie-xor/vasiliysmultiset.md) |
| static range minimum on immutable data | [Sparse Table hot sheet](../notebook/sparse-table-hot-sheet.md) | [sparse-table-rmq.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/sparse-table-rmq.cpp) | [Static Range Minimum Queries](../practice/ladders/data-structures/sparse-table/staticrangeminimumqueries.md) |
| online range add plus range sum on one array | [Lazy Segment Tree hot sheet](../notebook/lazy-segment-tree-hot-sheet.md) | [segment-tree-lazy-range-add-sum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/segment-tree-lazy-range-add-sum.cpp) | [HORRIBLE](../practice/ladders/data-structures/lazy-segment-tree/horriblequeries.md) |
| online range `chmin / chmax / add / sum` on one array | [Segment Tree Beats hot sheet](../notebook/segment-tree-beats-hot-sheet.md) | [segment-tree-beats.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/segment-tree-beats.cpp) | [Range Chmin Chmax Add Range Sum](../practice/ladders/data-structures/segment-tree-beats/rangechminchmaxaddrangesum.md) |
| merge one or many congruences into one residue modulo lcm | [Chinese Remainder hot sheet](../notebook/chinese-remainder-hot-sheet.md) | [chinese-remainder.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/chinese-remainder.cpp) | [General Chinese Remainder](../practice/ladders/math/chinese-remainder/generalchineseremainder.md) |
| large `nCk mod p` with one small prime modulus | [Lucas Theorem hot sheet](../notebook/lucas-hot-sheet.md) | [lucas-binomial.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/lucas-binomial.cpp) | [Binomial Coefficient (Prime Mod)](../practice/ladders/math/lucas-theorem/binomialcoefficientprimemod.md) |
| gcd-1 pair counts or divisor-side inclusion-exclusion over all `d <= MAX` | [Mobius hot sheet](../notebook/mobius-hot-sheet.md) | [mobius-linear-sieve.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/mobius-linear-sieve.cpp) | [Counting Coprime Pairs](../practice/ladders/math/mobius-multiplicative/countingcoprimepairs.md) |
| one fixed-order linear recurrence or repeated linear transition under modulo | [Linear Recurrence hot sheet](../notebook/linear-recurrence-hot-sheet.md) | [matrix-exponentiation.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/matrix-exponentiation.cpp) | [Throwing Dice](../practice/ladders/math/linear-recurrence/throwingdice.md) |
| subset xor span, representability, or maximum subset xor over any subset of inserted numbers | [XOR Basis hot sheet](../notebook/xor-basis-hot-sheet.md) | [xor-basis.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/xor-basis.cpp) | [XMAX - XOR Maximization](../practice/ladders/math/xor-basis/xmax.md) |
| independent heaps/components under one fixed impartial move set, combined by xor of Grundy values | [Sprague-Grundy hot sheet](../notebook/sprague-grundy-hot-sheet.md) | [sprague-grundy-subtract-set.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/sprague-grundy-subtract-set.cpp) | [S-Nim](../practice/ladders/math/game-theory/snim.md) |
| repeated discrete random steps with bounded sum/state and an exact probability query | [Probability hot sheet](../notebook/probability-hot-sheet.md) | [probability-distribution-dp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/probability-distribution-dp.cpp) | [Dice Probability](../practice/ladders/math/probability/diceprobability.md) |
| one-key monotone offline sweep | [Offline Tricks hot sheet](../notebook/offline-tricks-hot-sheet.md) | [offline-query-skeleton.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/offline-query-skeleton.cpp) | [Distinct Values Queries](../practice/ladders/data-structures/offline-tricks/distinctvaluesqueries.md) |
| critical roads or cities in one static undirected graph | [Low-Link hot sheet](../notebook/lowlink-hot-sheet.md) | [bridges-articulation-lowlink.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bridges-articulation-lowlink.cpp) | [Necessary Roads](../practice/ladders/graphs/bridges-articulation/necessaryroads.md) |
| one static graph walk that must use every edge exactly once | [Eulerian hot sheet](../notebook/eulerian-hot-sheet.md) | [eulerian-path-cycle.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/eulerian-path-cycle.cpp) | [Mail Delivery](../practice/ladders/graphs/eulerian-path-cycle/maildelivery.md) |
| one valid boolean assignment under binary clauses | [Two-SAT hot sheet](../notebook/two-sat-hot-sheet.md) | [two-sat.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/two-sat.cpp) | [Giant Pizza](../practice/ladders/graphs/two-sat/giantpizza.md) |
| one rooted subtree sum with point updates | [Subtree Queries hot sheet](../notebook/subtree-queries-hot-sheet.md) | [euler-tour-subtree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/euler-tour-subtree.cpp) | [Subtree Queries](../practice/ladders/graphs/euler-tour-subtree/subtreequeries.md) |
| bipartite maximum matching with explicit pairs | [Matching hot sheet](../notebook/matching-hot-sheet.md) | [hopcroft-karp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hopcroft-karp.cpp) | [School Dance](../practice/ladders/graphs/matching/schooldance.md) |
| centroid tree structure or one `O(log n)` centroid-ancestor chain per node | [Centroid hot sheet](../notebook/centroid-hot-sheet.md) | [centroid-decomposition.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/centroid-decomposition.cpp) | [Ciel the Commander](../practice/ladders/graphs/centroid-decomposition/cielthecommander.md) |
| exact one-pattern matching | [KMP](../topics/strings/kmp/README.md) | [kmp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/kmp.cpp) | [String Matching](../practice/ladders/strings/kmp/stringmatching.md) |
| one static string, longest palindrome, or all center radii | [Palindromes hot sheet](../notebook/palindromes-hot-sheet.md) | [manacher.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/manacher.cpp) | [Longest Palindrome](../practice/ladders/strings/palindromes/longestpalindrome.md) |
| one growing lowercase string, distinct palindromes, or longest palindromic suffix | [Eertree hot sheet](../notebook/eertree-hot-sheet.md) | [eertree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/eertree.cpp) | [Distinct Palindromic Substrings](../practice/ladders/strings/eertree/distinctpalindromicsubstrings.md) |
| many lowercase patterns against one text | [Aho-Corasick hot sheet](../notebook/aho-corasick-hot-sheet.md) | [aho-corasick.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/aho-corasick.cpp) | [Finding Patterns](../practice/ladders/strings/aho-corasick/findingpatterns.md) |
| exact suffix order plus LCP | [Suffix Array / LCP hot sheet](../notebook/suffix-array-lcp-hot-sheet.md) | [suffix-array.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/suffix-array.cpp) | [Repeating Substring](../practice/ladders/strings/suffix-array-lcp/repeatingsubstring.md) |
| static tree, point updates, path maximum | [HLD hot sheet](../notebook/hld-hot-sheet.md) | [hld-path-max.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hld-path-max.cpp) | [Path Queries II](../practice/ladders/graphs/hld/pathqueries2.md) |
| all-roots sum of distances on a tree | [Tree DP](../topics/dp/tree-dp/README.md) | [tree-dp-rerooting.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/tree-dp-rerooting.cpp) | [Tree Distances II](../practice/ladders/dp/tree-dp/treedistances2.md) |
| feasible circulation with lower / upper edge bounds | [Flow With Lower Bounds hot sheet](../notebook/flow-lower-bounds-hot-sheet.md) | [flow-lower-bounds.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/flow-lower-bounds.cpp) | [Reactor Cooling](../practice/ladders/graphs/flow/reactorcooling.md) |
| fixed-value costed flow with nonnegative initial forward costs | [Min-Cost Flow hot sheet](../notebook/min-cost-flow-hot-sheet.md) | [min-cost-flow.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/min-cost-flow.cpp) | [MINCOST](../practice/ladders/graphs/flow/mincost.md) |
| decimal range counting with a small digit state | [Digit DP hot sheet](../notebook/digit-dp-hot-sheet.md) | [digit-dp-skeleton.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/digit-dp-skeleton.cpp) | [Counting Numbers](../practice/ladders/dp/digit-dp/countingnumbers.md) |
| affine DP with online line insertion on one known integer x-domain | [CHT / Li Chao hot sheet](../notebook/cht-hot-sheet.md) | [li-chao-tree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/li-chao-tree.cpp) | [Monster Game II](../practice/ladders/dp/cht-li-chao/monstergame2.md) |
| fixed-size window minimum on a forward-only stream | [Data structures cheatsheet](../notebook/data-structures-cheatsheet.md) | [monotonic-deque-min.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/monotonic-deque-min.cpp) | [Sliding Window Minimum](../practice/ladders/dp/sliding-window/slidingwindowminimum.md) |
| same-length substring fingerprints | [String Hashing hot sheet](../notebook/string-hashing-hot-sheet.md) | [rolling-hash.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/rolling-hash.cpp) | [Finding Borders](../practice/ladders/strings/hashing/findingborders.md) |
| exact convolution modulo `998244353` | [FFT / NTT](../topics/math/fft-ntt/README.md) | [ntt.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/ntt.cpp) | [Convolution](../practice/ladders/math/fft/convolution.md) |
| one Bézout witness, or one inverse under composite modulus / `ax + by = c` | [Modular Arithmetic hot sheet](../notebook/modular-arithmetic-hot-sheet.md) | [extended-gcd-diophantine.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/extended-gcd-diophantine.cpp) | [Euclid Problem](../practice/ladders/math/gcd-lcm/euclidproblem.md) |

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
| “The idea seems right, but a hack or rejudge could still break it” | [Anti-Hack Workflow](../notebook/anti-hack-workflow.md) | [Stress testing workflow](../notebook/stress-testing-workflow.md) or [Local judge workflow](../notebook/local-judge-workflow.md) |
| “This task has a judge/protocol quirk” | [Local judge workflow](../notebook/local-judge-workflow.md) | the relevant playbook or note |
| “This batch task is checked by a predicate, validator, or score-aware output rule” | [Special Judge / Output Protocol Workflow](../notebook/special-judge-output-protocol-workflow.md) | [Local judge workflow](../notebook/local-judge-workflow.md) or the relevant clinic |

## Best Pairings

- Fenwick / dynamic prefix counts -> [Fenwick hot sheet](../notebook/fenwick-hot-sheet.md) + data-structures templates
- merge-only connectivity -> [DSU hot sheet](../notebook/dsu-hot-sheet.md) + graph/data-structure templates
- offline add/remove connectivity -> [DSU Rollback hot sheet](../notebook/dsu-rollback-hot-sheet.md) + [Offline Tricks hot sheet](../notebook/offline-tricks-hot-sheet.md)
- static current-range maintenance -> [Mo's hot sheet](../notebook/mos-hot-sheet.md) + [Offline Tricks hot sheet](../notebook/offline-tricks-hot-sheet.md)
- versioned array queries over old snapshots -> [Persistent Data Structures hot sheet](../notebook/persistent-data-structures-hot-sheet.md) + [Segment Tree hot sheet](../notebook/segment-tree-hot-sheet.md)
- mutable sequence edits by position -> [Treap / Implicit Treap hot sheet](../notebook/treap-hot-sheet.md) + [Lazy Segment Tree hot sheet](../notebook/lazy-segment-tree-hot-sheet.md)
- static subarray order statistics or threshold counts by value -> [Wavelet Tree hot sheet](../notebook/wavelet-tree-hot-sheet.md) + [Persistent Data Structures hot sheet](../notebook/persistent-data-structures-hot-sheet.md)
- live xor-max queries over one multiset of integers -> [Binary Trie hot sheet](../notebook/binary-trie-hot-sheet.md) + [Data structures cheatsheet](../notebook/data-structures-cheatsheet.md)
- subset xor span / maximum subset xor -> [XOR Basis hot sheet](../notebook/xor-basis-hot-sheet.md) + [Binary Trie hot sheet](../notebook/binary-trie-hot-sheet.md) when xor semantics are ambiguous
- static RMQ on immutable data -> [Sparse Table hot sheet](../notebook/sparse-table-hot-sheet.md) + data-structures templates
- reorderable query batches -> [Offline Tricks hot sheet](../notebook/offline-tricks-hot-sheet.md) + data-structures templates
- shortest paths -> [Shortest Paths hot sheet](../notebook/shortest-paths-hot-sheet.md) + graph templates
- critical edges / cut vertices -> [Low-Link hot sheet](../notebook/lowlink-hot-sheet.md) + [Graph cheatsheet](../notebook/graph-cheatsheet.md)
- use-every-edge-once graph tasks -> [Eulerian hot sheet](../notebook/eulerian-hot-sheet.md) + [Graph cheatsheet](../notebook/graph-cheatsheet.md)
- binary clause feasibility -> [Two-SAT hot sheet](../notebook/two-sat-hot-sheet.md) + [Graph cheatsheet](../notebook/graph-cheatsheet.md)
- subtree-only tree aggregation -> [Subtree Queries hot sheet](../notebook/subtree-queries-hot-sheet.md) + [Graph cheatsheet](../notebook/graph-cheatsheet.md)
- tree path queries -> [HLD hot sheet](../notebook/hld-hot-sheet.md) + [Heavy-Light Decomposition](../topics/graphs/hld/README.md)
- balanced recursive tree splits -> [Centroid hot sheet](../notebook/centroid-hot-sheet.md) + [Graph cheatsheet](../notebook/graph-cheatsheet.md)
- range-query structures -> [Segment Tree hot sheet](../notebook/segment-tree-hot-sheet.md) + [Data structures cheatsheet](../notebook/data-structures-cheatsheet.md)
- true online range updates -> [Lazy Segment Tree hot sheet](../notebook/lazy-segment-tree-hot-sheet.md) + [Segment Tree hot sheet](../notebook/segment-tree-hot-sheet.md)
- harder clamp-style range updates -> [Segment Tree Beats hot sheet](../notebook/segment-tree-beats-hot-sheet.md) + [Lazy Segment Tree hot sheet](../notebook/lazy-segment-tree-hot-sheet.md)
- flow or cuts -> [Flow hot sheet](../notebook/flow-hot-sheet.md) + graph templates
- mandatory lower / upper edge flow bounds -> [Flow With Lower Bounds hot sheet](../notebook/flow-lower-bounds-hot-sheet.md) + [Flow hot sheet](../notebook/flow-hot-sheet.md)
- fixed-value costed transport -> [Min-Cost Flow hot sheet](../notebook/min-cost-flow-hot-sheet.md) + graph templates
- matching -> [Matching hot sheet](../notebook/matching-hot-sheet.md) + [Flow hot sheet](../notebook/flow-hot-sheet.md) when the reduction is ambiguous
- digit-counting over huge ranges -> [Digit DP hot sheet](../notebook/digit-dp-hot-sheet.md) + DP templates
- affine DP / online line minimum -> [CHT / Li Chao hot sheet](../notebook/cht-hot-sheet.md) + DP templates
- congruence systems / composite-mod inverse -> [Chinese Remainder hot sheet](../notebook/chinese-remainder-hot-sheet.md) + [Modular Arithmetic hot sheet](../notebook/modular-arithmetic-hot-sheet.md)
- huge binomial queries under one prime modulus -> [Lucas Theorem hot sheet](../notebook/lucas-hot-sheet.md) + [Modular Arithmetic hot sheet](../notebook/modular-arithmetic-hot-sheet.md)
- gcd/divisor counting over all multiples -> [Mobius hot sheet](../notebook/mobius-hot-sheet.md) + [Number theory cheatsheet](../notebook/number-theory-cheatsheet.md)
- linear recurrence under one modulus -> [Linear Recurrence hot sheet](../notebook/linear-recurrence-hot-sheet.md) + [Modular Arithmetic hot sheet](../notebook/modular-arithmetic-hot-sheet.md)
- impartial normal-play heaps/components -> [Sprague-Grundy hot sheet](../notebook/sprague-grundy-hot-sheet.md) + [DP cheatsheet](../notebook/dp-cheatsheet.md)
- finite random process / exact event probability -> [Probability hot sheet](../notebook/probability-hot-sheet.md) + [DP cheatsheet](../notebook/dp-cheatsheet.md)
- modular arithmetic -> [Modular Arithmetic hot sheet](../notebook/modular-arithmetic-hot-sheet.md) + math templates
- one static palindrome scan -> [Palindromes hot sheet](../notebook/palindromes-hot-sheet.md) + string templates
- one append-only distinct-palindrome structure -> [Eertree hot sheet](../notebook/eertree-hot-sheet.md) + string templates
- substring fingerprints -> [String Hashing hot sheet](../notebook/string-hashing-hot-sheet.md) + string templates
- many exact patterns in one text -> [Aho-Corasick hot sheet](../notebook/aho-corasick-hot-sheet.md) + string templates
- exact static suffix structure -> [Suffix Array / LCP hot sheet](../notebook/suffix-array-lcp-hot-sheet.md) + string templates
- geometry predicates -> [Geometry cheatsheet](../notebook/geometry-cheatsheet.md) + geometry templates

## After This Page

- if trust in the snippet is still low, go back to `topics/`
- if you now need the next problem, go to [Problem Finder](problem-finder.md)
- if you want a contest-format workflow, go to [Contest Playbooks](../practice/contest-playbooks/README.md)
