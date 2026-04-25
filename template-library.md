# Template Library

This page is the map for the repo's reusable contest-ready code. The actual implementations live under [`templates/`](https://github.com/mtuann/competitive-programming-cpp/tree/main/templates), but the goal here is to keep you inside the repo's `learn -> practice -> retrieve -> reuse` loop for as long as possible before you jump from repo context into raw source.

## Fast Pick By Signal

- smallest clean contest skeleton: [contest-main.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/contest-main.cpp)
- large input but ordinary batch stdin/stdout: [fast-io.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/fast-io.cpp)
- shortest path on unit edges: [bfs.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bfs.cpp)
- shortest path on `0/1` edges: [zero-one-bfs.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/zero-one-bfs.cpp)
- shortest path with negative edges: [bellman-ford.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bellman-ford.cpp)
- all-pairs shortest paths on small `n`: [floyd-warshall.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/floyd-warshall.cpp)
- critical edges / cut vertices in one undirected graph: [bridges-articulation-lowlink.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bridges-articulation-lowlink.cpp)
- one static graph walk that must use every edge exactly once: [eulerian-path-cycle.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/eulerian-path-cycle.cpp)
- one valid boolean assignment under binary clauses: [two-sat.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/two-sat.cpp)
- one rooted subtree sum with point updates: [euler-tour-subtree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/euler-tour-subtree.cpp)
- static tree path maximum with point updates: [hld-path-max.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hld-path-max.cpp)
- centroid tree plus per-node centroid ancestors/distances on a static tree: [centroid-decomposition.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/centroid-decomposition.cpp)
- feasible circulation with lower / upper edge bounds, or one lower-bounded `s-t` reduction after adding `t -> s`: [flow-lower-bounds.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/flow-lower-bounds.cpp)
- offline connectivity under an add/remove edge timeline: [dsu-rollback-dynamic-connectivity.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/dsu-rollback-dynamic-connectivity.cpp)
- versioned point updates with old-version range sums: [persistent-segment-tree-point-set-sum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/persistent-segment-tree-point-set-sum.cpp)
- mutable sequence with cut/paste or insert/erase by position: [implicit-treap-sequence.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/implicit-treap-sequence.cpp)
- static subarray k-th / count `<= x` / count `== x` queries: [wavelet-tree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/wavelet-tree.cpp)
- one static array where range answers survive endpoint add/remove updates: [mos-algorithm.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/mos-algorithm.cpp)
- dynamic maximum xor against one live multiset of integers: [binary-trie-xor.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/binary-trie-xor.cpp)
- predecessor / previous value in a multiset: [multiset-predecessor.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/multiset-predecessor.cpp)
- sliding median with duplicates: [sliding-median-two-multisets.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/sliding-median-two-multisets.cpp)
- sliding minimum or monotone-window DP: [monotonic-deque-min.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/monotonic-deque-min.cpp)
- online range add plus range sum on one array: [segment-tree-lazy-range-add-sum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/segment-tree-lazy-range-add-sum.cpp)
- online range `chmin / chmax / add / sum` on one array: [segment-tree-beats.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/segment-tree-beats.cpp)
- merge one or many congruences into one residue modulo lcm: [chinese-remainder.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/chinese-remainder.cpp)
- large `nCk mod p` with one small prime modulus: [lucas-binomial.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/lucas-binomial.cpp)
- gcd-1 pair counts or divisor-side inclusion-exclusion over all `d <= MAX`: [mobius-linear-sieve.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/mobius-linear-sieve.cpp)
- small fixed-dimension linear recurrence or repeated linear transition under modulo: [matrix-exponentiation.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/matrix-exponentiation.cpp)
- subset xor span, representability, or maximum subset xor over any subset: [xor-basis.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/xor-basis.cpp)
- impartial normal-play heaps/components under one fixed subtraction move set: [sprague-grundy-subtract-set.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/sprague-grundy-subtract-set.cpp)
- many `nCk mod prime` queries: [factorial-binomial-mod.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/factorial-binomial-mod.cpp)
- inverse under composite modulus or `ax + by = c`: [extended-gcd-diophantine.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/extended-gcd-diophantine.cpp)
- exact convolution modulo a friendly prime: [ntt.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/ntt.cpp)
- one static string, longest palindrome, or all center radii: [manacher.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/manacher.cpp)
- one growing lowercase string, distinct palindromes, or longest palindromic suffix: [eertree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/eertree.cpp)
- affine DP minimum over online line insertions on a bounded integer domain: [li-chao-tree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/li-chao-tree.cpp)
- all-substrings state machine for one fixed base string: [suffix-automaton.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/suffix-automaton.cpp)
- robust closed-segment predicate: [segment-intersection-basic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/segment-intersection-basic.cpp)
- polygon area from ordered vertices: [shoelace-area.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/shoelace-area.cpp)
- classify `outside / boundary / inside`: [point-in-polygon.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/point-in-polygon.cpp)

## Retrieval Flow

Use the library in this order:

1. identify the smallest valid pattern from the topic page or cheatsheet
2. open the matching template and copy only the parts your problem really needs
3. sanity-check the invariant and boundary policy before integrating it into the solution

If you are still unsure which family to use, start from the [Notebook](notebook/README.md) instead of browsing files blindly.

If the template is integrated but still feels untrustworthy, switch immediately to the [Stress testing workflow](notebook/stress-testing-workflow.md) instead of guessing at bugs.

If you are still stabilizing the local C++ loop itself, pair these first:

- [C++ Language For Contests](topics/foundations/cpp-language/README.md)
- [Foundations Cheatsheet](notebook/foundations-cheatsheet.md)
- [Weird Algorithm](practice/ladders/foundations/cpp-language/weirdalgorithm.md)

## Exact Starter Routes

Use these route cards when you want stronger in-site context before touching raw template code.

| Need | Learn / check first | Reuse | Compare against |
| --- | --- | --- | --- |
| one exact pattern against one text | [KMP](topics/strings/kmp/README.md) | [kmp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/kmp.cpp) | [String Matching](practice/ladders/strings/kmp/stringmatching.md) |
| one static string, longest palindrome, or all center radii | [Palindromes / Manacher](topics/strings/palindromes/README.md) | [manacher.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/manacher.cpp) | [Longest Palindrome](practice/ladders/strings/palindromes/longestpalindrome.md) |
| one growing lowercase string, distinct palindromes, or longest palindromic suffix | [Eertree / Palindromic Tree](topics/strings/eertree/README.md) | [eertree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/eertree.cpp) | [Distinct Palindromic Substrings](practice/ladders/strings/eertree/distinctpalindromicsubstrings.md) |
| critical roads or cut vertices in one static undirected graph | [Bridges, Articulation Points, And Biconnected Components](topics/graphs/bridges-articulation/README.md) | [bridges-articulation-lowlink.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bridges-articulation-lowlink.cpp) | [Necessary Roads](practice/ladders/graphs/bridges-articulation/necessaryroads.md) |
| one static graph walk that must use every edge exactly once | [Eulerian Path / Cycle](topics/graphs/eulerian-path-cycle/README.md) | [eulerian-path-cycle.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/eulerian-path-cycle.cpp) | [Mail Delivery](practice/ladders/graphs/eulerian-path-cycle/maildelivery.md) |
| one valid boolean assignment under binary clauses | [2-SAT](topics/graphs/two-sat/README.md) | [two-sat.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/two-sat.cpp) | [Giant Pizza](practice/ladders/graphs/two-sat/giantpizza.md) |
| one rooted subtree sum with point updates | [Euler Tour / Subtree Queries](topics/graphs/euler-tour-subtree/README.md) | [euler-tour-subtree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/euler-tour-subtree.cpp) | [Subtree Queries](practice/ladders/graphs/euler-tour-subtree/subtreequeries.md) |
| static tree, point updates, path maximum | [Heavy-Light Decomposition](topics/graphs/hld/README.md) | [hld-path-max.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hld-path-max.cpp) | [Path Queries II](practice/ladders/graphs/hld/pathqueries2.md) |
| centroid tree plus per-node centroid ancestors/distances | [Centroid Decomposition](topics/graphs/centroid-decomposition/README.md) | [centroid-decomposition.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/centroid-decomposition.cpp) | [Ciel the Commander](practice/ladders/graphs/centroid-decomposition/cielthecommander.md) |
| connectivity under an offline add/remove edge timeline | [DSU Rollback / Offline Dynamic Connectivity](topics/data-structures/dsu-rollback/README.md) | [dsu-rollback-dynamic-connectivity.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/dsu-rollback-dynamic-connectivity.cpp) | [Dynamic Connectivity](practice/ladders/data-structures/dsu-rollback/dynamicconnectivity.md) |
| one versioned array with point assignment and old-version range sums | [Persistent Data Structures](topics/data-structures/persistent-data-structures/README.md) | [persistent-segment-tree-point-set-sum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/persistent-segment-tree-point-set-sum.cpp) | [Range Queries and Copies](practice/ladders/data-structures/persistent-data-structures/rangequeriesandcopies.md) |
| one mutable sequence with cut/paste or insert/erase by position | [Treap / Implicit Treap](topics/data-structures/treap-implicit/README.md) | [implicit-treap-sequence.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/implicit-treap-sequence.cpp) | [Cut and Paste](practice/ladders/data-structures/treap-implicit/cutandpaste.md) |
| one static array with subarray k-th / count `<= x` / count `== x` queries | [Wavelet Tree](topics/data-structures/wavelet-tree/README.md) | [wavelet-tree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/wavelet-tree.cpp) | [MKTHNUM - K-th Number](practice/ladders/data-structures/wavelet-tree/mkthnum.md) |
| one static array with many range queries where add/remove at one endpoint is cheap | [Mo's Algorithm](topics/data-structures/mos-algorithm/README.md) | [mos-algorithm.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/mos-algorithm.cpp) | [Powerful Array](practice/ladders/data-structures/mos-algorithm/powerfularray.md) |
| one live multiset of integers with insert / erase / maximum xor queries | [Binary Trie / XOR Queries](topics/data-structures/binary-trie-xor/README.md) | [binary-trie-xor.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/binary-trie-xor.cpp) | [Vasiliy's Multiset](practice/ladders/data-structures/binary-trie-xor/vasiliysmultiset.md) |
| affine DP with online line insertion on one known integer x-domain | [Convex Hull Trick / Li Chao Tree](topics/dp/cht-li-chao/README.md) | [li-chao-tree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/li-chao-tree.cpp) | [Monster Game II](practice/ladders/dp/cht-li-chao/monstergame2.md) |
| merge one or many congruences into one residue modulo lcm | [Chinese Remainder / Linear Congruences](topics/math/chinese-remainder/README.md) | [chinese-remainder.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/chinese-remainder.cpp) | [General Chinese Remainder](practice/ladders/math/chinese-remainder/generalchineseremainder.md) |
| large `nCk mod p` with one small prime modulus | [Lucas Theorem / Large Binomial Mod Prime](topics/math/lucas-theorem/README.md) | [lucas-binomial.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/lucas-binomial.cpp) | [Binomial Coefficient (Prime Mod)](practice/ladders/math/lucas-theorem/binomialcoefficientprimemod.md) |
| gcd-1 pair counts or divisor-side inclusion-exclusion over bounded values | [Mobius And Multiplicative Counting](topics/math/mobius-multiplicative/README.md) | [mobius-linear-sieve.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/mobius-linear-sieve.cpp) | [Counting Coprime Pairs](practice/ladders/math/mobius-multiplicative/countingcoprimepairs.md) |
| one fixed-order linear recurrence or repeated linear transition under modulo | [Linear Recurrence / Matrix Exponentiation](topics/math/linear-recurrence/README.md) | [matrix-exponentiation.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/matrix-exponentiation.cpp) | [Throwing Dice](practice/ladders/math/linear-recurrence/throwingdice.md) |
| subset xor span, representability, or maximum subset xor from any subset of inserted numbers | [XOR Basis / Linear Basis](topics/math/xor-basis/README.md) | [xor-basis.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/xor-basis.cpp) | [XMAX - XOR Maximization](practice/ladders/math/xor-basis/xmax.md) |
| impartial normal-play heaps/components under one fixed move set, combined by xor of Grundy values | [Game Theory / Sprague-Grundy](topics/math/game-theory/README.md) | [sprague-grundy-subtract-set.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/sprague-grundy-subtract-set.cpp) | [S-Nim](practice/ladders/math/game-theory/snim.md) |
| exact convolution modulo `998244353` | [FFT / NTT](topics/math/fft-ntt/README.md) | [ntt.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/ntt.cpp) | [Convolution](practice/ladders/math/fft/convolution.md) |
| point updates plus range sums on an array | [Segment Tree](topics/data-structures/segment-tree/README.md) | [segment-tree-iterative.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/segment-tree-iterative.cpp) | [Dynamic Range Sum Queries](practice/ladders/data-structures/segment-tree/dynamicrangesumqueries.md) |
| online range add plus range sum on an array | [Lazy Segment Tree](topics/data-structures/lazy-segment-tree/README.md) | [segment-tree-lazy-range-add-sum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/segment-tree-lazy-range-add-sum.cpp) | [HORRIBLE](practice/ladders/data-structures/lazy-segment-tree/horriblequeries.md) |
| online range `chmin / chmax / add / sum` on one array | [Segment Tree Beats](topics/data-structures/segment-tree-beats/README.md) | [segment-tree-beats.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/segment-tree-beats.cpp) | [Range Chmin Chmax Add Range Sum](practice/ladders/data-structures/segment-tree-beats/rangechminchmaxaddrangesum.md) |
| one inverse under composite modulus or `ax + by = c` | [Modular Arithmetic](topics/math/modular-arithmetic/README.md) | [extended-gcd-diophantine.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/extended-gcd-diophantine.cpp) | [Euclid Problem](practice/ladders/math/gcd-lcm/euclidproblem.md) |

## Template Card Contract

For mature templates, this repo uses six short metadata fields:

- `Signal`: the fastest cue that this template is the right family
- `Assumes`: the boundary meaning, invariant, or data-shape contract already baked in
- `Exposes`: the function, struct, or return contract you are expected to reuse
- `Complexity`: the standard operation cost you should keep in your head while using it
- `Main trap`: the bug most likely to survive hand tests
- `Links`: the strongest reopening path when trust is low

The library page carries fuller cards for the pilot family and chooser tables for the rest. The template file itself only keeps the compact version.

## Foundations Pilot Cards

### [contest-main.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/contest-main.cpp)

- `Signal`: start a normal single-file batch solution with the smallest clean skeleton
- `Assumes`: standard C++ streams, one-file submission, logic still needs to be written from scratch
- `Exposes`: one minimal `main()` with fast iostream setup already in place
- `Complexity`: no algorithmic cost; this is a starter scaffold
- `Main trap`: copying the skeleton and then letting local debug prints leak into judged output
- `Links`: [C++ Language For Contests](topics/foundations/cpp-language/README.md), [Foundations Cheatsheet](notebook/foundations-cheatsheet.md), [Weird Algorithm](practice/ladders/foundations/cpp-language/weirdalgorithm.md)

### [fast-io.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/fast-io.cpp)

- `Signal`: large ordinary stdin/stdout input, but still no interactive or custom-judge behavior
- `Assumes`: C++ streams only; no casual mixing with `scanf` / `printf` after disabling sync
- `Exposes`: one reusable `init_fast_io()` helper plus a minimal `main()`
- `Complexity`: same asymptotic complexity as ordinary iostream code; this is about constant-factor stream setup
- `Main trap`: mixing unsynchronized iostreams with C stdio and then debugging ghosts that are really I/O policy bugs
- `Links`: [C++ Language For Contests](topics/foundations/cpp-language/README.md), [Foundations Cheatsheet](notebook/foundations-cheatsheet.md)

### [sort-and-comparator.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/sort-and-comparator.cpp)

- `Signal`: records need to be ordered by one main key plus an explicit tie rule
- `Assumes`: the comparator is a strict weak ordering and the tie behavior matters enough to spell out
- `Exposes`: one record `struct` plus one lambda comparator pattern
- `Complexity`: `O(n log n)` sorting plus linear scan after sorting in the common use case
- `Main trap`: incomplete or inconsistent comparator logic that makes the proof and the implementation quietly disagree
- `Links`: [Sorting](topics/foundations/patterns/sorting/README.md), [Ferris Wheel](practice/ladders/foundations/sorting/ferriswheel.md), [Movie Festival](practice/ladders/foundations/sorting/moviefestival.md)

### [prefix-sum-1d.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/prefix-sum-1d.cpp)

- `Signal`: many static range sums or counts, no updates
- `Assumes`: one stable indexing convention and `pref[0] = 0`
- `Exposes`: a `PrefixSum1D` struct with `sum(l, r)` over a half-open-style internal prefix layout
- `Complexity`: `O(n)` preprocessing, `O(1)` per query
- `Main trap`: mixing inclusive and half-open interval formulas in the same solution
- `Links`: [Prefix Sums](topics/foundations/patterns/prefix-sums/README.md), [Static Range Sum Queries](practice/ladders/foundations/prefix-sums/staticrangesumqueries.md)

### [binary-search-first-true.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/binary-search-first-true.cpp)

- `Signal`: monotone predicate, want the first feasible answer
- `Assumes`: `l` is bad, `r` is good, and the answer stays in `(l, r]`
- `Exposes`: a `first_true(l, r, is_good)` helper that returns the first good integer
- `Complexity`: `O(log range)` predicate calls
- `Main trap`: writing a check that is not really monotone, or forgetting what `l` and `r` mean after two iterations
- `Links`: [Binary Search](topics/foundations/patterns/binary-search/README.md), [Factory Machines](practice/ladders/foundations/binary-search/factorymachines.md), [Foundations Cheatsheet](notebook/foundations-cheatsheet.md)

## Foundations Chooser

| Template | Signal | Avoid when | Teaching anchor | Representative use |
| --- | --- | --- | --- | --- |
| [contest-main.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/contest-main.cpp) | start a clean single-file batch solution | you already need a protocol harness or a real reusable data structure | [C++ Language](topics/foundations/cpp-language/README.md) | [Weird Algorithm](practice/ladders/foundations/cpp-language/weirdalgorithm.md) |
| [fast-io.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/fast-io.cpp) | large ordinary stdin/stdout input | interactive tasks or mixed stdio policy | [C++ Language](topics/foundations/cpp-language/README.md) | [Missing Number](practice/ladders/foundations/cpp-language/missingnumber.md) |
| [sort-and-comparator.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/sort-and-comparator.cpp) | sort records by one main key plus ties | the proof does not depend on sorted order yet | [Sorting](topics/foundations/patterns/sorting/README.md) | [Movie Festival](practice/ladders/foundations/sorting/moviefestival.md) |
| [binary-search-first-true.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/binary-search-first-true.cpp) | monotone predicate, first feasible answer | the predicate is not monotone | [Binary Search](topics/foundations/patterns/binary-search/README.md) | [Factory Machines](practice/ladders/foundations/binary-search/factorymachines.md) |
| [binary-search-last-false.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/binary-search-last-false.cpp) | monotone predicate, want the last bad point | you are really reasoning in first-true semantics | [Binary Search](topics/foundations/patterns/binary-search/README.md) | [Factory Machines](practice/ladders/foundations/binary-search/factorymachines.md) |
| [prefix-sum-1d.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/prefix-sum-1d.cpp) | many static range sums or counts | updates happen between queries | [Prefix Sums](topics/foundations/patterns/prefix-sums/README.md) | [Static Range Sum Queries](practice/ladders/foundations/prefix-sums/staticrangesumqueries.md) |
| [difference-array.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/difference-array.cpp) | many offline range additions, final reconstruction only | online queries or updates interleave with answers | [Difference Arrays](topics/foundations/patterns/difference-arrays/README.md) | [Range Update Queries](practice/ladders/foundations/difference-arrays/rangeupdatequeries.md) |
| [two-pointers-variable-window.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/two-pointers-variable-window.cpp) | monotone sliding window with forward-only boundaries | negative values or non-monotone validity break the window logic | [Two Pointers](topics/foundations/patterns/two-pointers/README.md) | [TFIELD](practice/ladders/dp/sliding-window/tfield.md) |

## Data Structures Chooser

| Template | Signal | Avoid when | Teaching anchor | Representative use |
| --- | --- | --- | --- | --- |
| [dsu-basic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/dsu-basic.cpp) | merge-only connectivity or component tracking | deletions, rollback, parity constraints, or path aggregates | [DSU](topics/data-structures/dsu/README.md) | [C11XU](practice/ladders/data-structures/dsu/c11xu.md) |
| [dsu-rollback-dynamic-connectivity.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/dsu-rollback-dynamic-connectivity.cpp) | connectivity or component count under an offline add/remove edge timeline | the problem is truly online, or one monotone sweep already removes the need for rollback | [DSU Rollback / Offline Dynamic Connectivity](topics/data-structures/dsu-rollback/README.md) | [Dynamic Connectivity](practice/ladders/data-structures/dsu-rollback/dynamicconnectivity.md) |
| [persistent-segment-tree-point-set-sum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/persistent-segment-tree-point-set-sum.cpp) | branching versions with point assignment and range sums over old snapshots | range updates dominate, only one current state matters, or the aggregate is not the ordinary segment-tree one | [Persistent Data Structures](topics/data-structures/persistent-data-structures/README.md) | [Range Queries and Copies](practice/ladders/data-structures/persistent-data-structures/rangequeriesandcopies.md) |
| [implicit-treap-sequence.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/implicit-treap-sequence.cpp) | one mutable sequence where split/merge by position is the cleanest way to express cut/paste or insert/erase edits | fixed-length interval updates already fit segment trees, or ordered-set predecessor/successor is the only need | [Treap / Implicit Treap](topics/data-structures/treap-implicit/README.md) | [Cut and Paste](practice/ladders/data-structures/treap-implicit/cutandpaste.md) |
| [wavelet-tree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/wavelet-tree.cpp) | one static array with subarray order statistics or value-threshold counts where the query descends by value partitions | updates happen, one active current range is the real invariant, or version roots / prefix trees are the intended story | [Wavelet Tree](topics/data-structures/wavelet-tree/README.md) | [MKTHNUM - K-th Number](practice/ladders/data-structures/wavelet-tree/mkthnum.md) |
| [mos-algorithm.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/mos-algorithm.cpp) | one static array where the exact current-range answer can be maintained by endpoint add/remove updates | a monotone sweep already works, updates happen between queries, or the problem is still in tree/time-reduction territory | [Mo's Algorithm](topics/data-structures/mos-algorithm/README.md) | [Powerful Array](practice/ladders/data-structures/mos-algorithm/powerfularray.md) |
| [binary-trie-xor.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/binary-trie-xor.cpp) | one live multiset of non-negative integers where xor optimization against one stored element is the whole query | the task is subset xor, plain ordered-set logic, or a richer counting-trie variant than this starter advertises | [Binary Trie / XOR Queries](topics/data-structures/binary-trie-xor/README.md) | [Vasiliy's Multiset](practice/ladders/data-structures/binary-trie-xor/vasiliysmultiset.md) |
| [fenwick-point-prefix.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/fenwick-point-prefix.cpp) | point updates plus prefix or range sums | range assignment, min/max merges, or mixed lazy operations | [Fenwick Tree](topics/data-structures/fenwick-tree/README.md) | [CVP00001](practice/ladders/data-structures/fenwick-tree/cvp00001.md) |
| [segment-tree-iterative.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/segment-tree-iterative.cpp) | point updates with range sums on a mutable array | you need a generic monoid, lazy propagation, or a fully static structure | [Segment Tree](topics/data-structures/segment-tree/README.md) | [Dynamic Range Sum Queries](practice/ladders/data-structures/segment-tree/dynamicrangesumqueries.md) |
| [segment-tree-lazy-range-add-sum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/segment-tree-lazy-range-add-sum.cpp) | online range add plus range sum on a mutable array | range-assign tags, affine updates, or problems that are really offline difference-array tasks | [Lazy Segment Tree](topics/data-structures/lazy-segment-tree/README.md) | [HORRIBLE](practice/ladders/data-structures/lazy-segment-tree/horriblequeries.md) |
| [segment-tree-beats.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/segment-tree-beats.cpp) | online range `chmin / chmax / add / sum` where clamp updates depend on current extrema distribution | a plain lazy-tag algebra already works, or the task is only one narrower beats-like modulo/historic variant than this starter advertises | [Segment Tree Beats](topics/data-structures/segment-tree-beats/README.md) | [Range Chmin Chmax Add Range Sum](practice/ladders/data-structures/segment-tree-beats/rangechminchmaxaddrangesum.md) |
| [sparse-table-rmq.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/sparse-table-rmq.cpp) | static range minimum query | online updates or any non-RMQ aggregate | [Sparse Table](topics/data-structures/sparse-table/README.md) | [Static Range Minimum Queries](practice/ladders/data-structures/sparse-table/staticrangeminimumqueries.md) |
| [heap-lazy-delete.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/heap-lazy-delete.cpp) | min-heap behavior with delayed deletions by value | predecessor/order-statistics queries or deletes that do not correspond to live values | [Heaps And Ordered Sets](topics/data-structures/heaps-and-ordered-sets/README.md) | [Heaps And Ordered Sets Ladder](practice/ladders/data-structures/heaps-and-ordered-sets/README.md) |
| [multiset-predecessor.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/multiset-predecessor.cpp) | predecessor or floor queries with duplicates | you need rank / order statistics or heap-only behavior | [Heaps And Ordered Sets](topics/data-structures/heaps-and-ordered-sets/README.md) | [Concert Tickets](practice/ladders/data-structures/heaps-and-ordered-sets/concerttickets.md) |
| [sliding-median-two-multisets.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/sliding-median-two-multisets.cpp) | maintain a lower median under insert/erase with duplicates | you need arbitrary quantiles or a different median convention | [Heaps And Ordered Sets](topics/data-structures/heaps-and-ordered-sets/README.md) | [Heaps And Ordered Sets Ladder](practice/ladders/data-structures/heaps-and-ordered-sets/README.md) |
| [monotonic-deque-min.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/monotonic-deque-min.cpp) | sliding minimum or DP over a moving interval | the valid set is not a forward-only window | [Heaps And Ordered Sets](topics/data-structures/heaps-and-ordered-sets/README.md) | [Sliding Window Minimum](practice/ladders/dp/sliding-window/slidingwindowminimum.md) |
| [offline-query-skeleton.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/offline-query-skeleton.cpp) | sort events and queries by one monotone key, then sweep once | answers depend on previous answers or truly online updates | [Offline Tricks](topics/data-structures/offline-tricks/README.md) | [Distinct Values Queries](practice/ladders/data-structures/offline-tricks/distinctvaluesqueries.md) |

## Graphs Chooser

| Template | Signal | Avoid when | Teaching anchor | Representative use |
| --- | --- | --- | --- | --- |
| [bfs.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bfs.cpp) | unweighted shortest path or layer exploration | weighted edges matter | [BFS And DFS](topics/graphs/bfs-dfs/README.md) | [Message Route](practice/ladders/graphs/bfs-dfs/messageroute.md) |
| [dfs-iterative.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dfs-iterative.cpp) | traversal/components without recursion risk | layer distance is the proof-critical object | [BFS And DFS](topics/graphs/bfs-dfs/README.md) | [Counting Rooms](practice/ladders/graphs/graph-modeling/countingrooms.md) |
| [zero-one-bfs.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/zero-one-bfs.cpp) | shortest paths with edge weights only `0/1` | arbitrary nonnegative weights | [Shortest Paths](topics/graphs/shortest-paths/README.md) | [Shortest Paths Ladder](practice/ladders/graphs/shortest-paths/README.md) |
| [dijkstra.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dijkstra.cpp) | nonnegative weighted shortest paths | any reachable negative edge survives after modeling | [Shortest Paths](topics/graphs/shortest-paths/README.md) | [QOS](practice/ladders/graphs/shortest-paths/qos.md) |
| [bellman-ford.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bellman-ford.cpp) | negative edges or reachable negative-cycle detection | all weights are nonnegative and sparse enough for Dijkstra | [Shortest Paths](topics/graphs/shortest-paths/README.md) | [Shortest Paths Ladder](practice/ladders/graphs/shortest-paths/README.md) |
| [floyd-warshall.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/floyd-warshall.cpp) | all-pairs shortest paths on small `n` | sparse large graphs or one-source queries only | [Shortest Paths](topics/graphs/shortest-paths/README.md) | [Shortest Paths Ladder](practice/ladders/graphs/shortest-paths/README.md) |
| [kruskal.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/kruskal.cpp) | MST from an edge list | directed reachability or path-distance questions | [MST](topics/graphs/mst/README.md) | [Road Reparation](practice/ladders/graphs/mst/roadreparation.md) |
| [toposort-kahn.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/toposort-kahn.cpp) | explicit DAG ordering from indegrees | you need SCC condensation or cyclic-component structure, not just cycle detection | [Topological Sort And SCC](topics/graphs/scc-toposort/README.md) | [Course Schedule](practice/ladders/graphs/scc-toposort/courseschedule.md) |
| [scc-kosaraju.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/scc-kosaraju.cpp) | compress directed cycles into SCC ids | the graph is undirected or plain topo order already exists | [Topological Sort And SCC](topics/graphs/scc-toposort/README.md) | [SCC / Toposort Ladder](practice/ladders/graphs/scc-toposort/README.md) |
| [bridges-articulation-lowlink.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bridges-articulation-lowlink.cpp) | undirected graph with critical edges, critical vertices, or low-link preprocessing before deeper BCC work | the graph is directed, dynamic, or already a tree | [Bridges, Articulation Points, And Biconnected Components](topics/graphs/bridges-articulation/README.md) | [Necessary Roads](practice/ladders/graphs/bridges-articulation/necessaryroads.md) |
| [eulerian-path-cycle.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/eulerian-path-cycle.cpp) | one static graph walk or ordering that must use every edge exactly once, in either the undirected or directed setting | the task is subtree flattening, shortest path, or online graph updates rather than all-edge traversal | [Eulerian Path / Cycle](topics/graphs/eulerian-path-cycle/README.md) | [Mail Delivery](practice/ladders/graphs/eulerian-path-cycle/maildelivery.md) |
| [two-sat.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/two-sat.cpp) | boolean variables with binary clauses and one witness assignment | clauses are not binary, variables are not boolean, or optimization dominates the task | [2-SAT](topics/graphs/two-sat/README.md) | [Giant Pizza](practice/ladders/graphs/two-sat/giantpizza.md) |
| [euler-tour-subtree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/euler-tour-subtree.cpp) | one rooted subtree interval with point updates and subtree sums | arbitrary path queries, dynamic tree changes, or child-merge DP are the real bottleneck | [Euler Tour / Subtree Queries](topics/graphs/euler-tour-subtree/README.md) | [Subtree Queries](practice/ladders/graphs/euler-tour-subtree/subtreequeries.md) |
| [lca-binary-lifting.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/lca-binary-lifting.cpp) | many static ancestor or LCA queries on one rooted tree | dynamic trees or path aggregates are the real bottleneck | [LCA](topics/graphs/lca/README.md) | [Company Queries II](practice/ladders/graphs/lca/companyqueries2.md) |
| [hld-path-max.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hld-path-max.cpp) | static tree with node updates and path maximum queries | edge-valued paths, lazy range updates, or non-commutative path aggregates | [Heavy-Light Decomposition](topics/graphs/hld/README.md) | [Path Queries II](practice/ladders/graphs/hld/pathqueries2.md) |
| [centroid-decomposition.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/centroid-decomposition.cpp) | static tree problems that need a centroid tree, balanced recursive splits, or one `O(log n)` centroid-ancestor chain per node | subtree-only flattening, HLD-style path aggregates, or dynamic tree changes are the real fit | [Centroid Decomposition](topics/graphs/centroid-decomposition/README.md) | [Ciel the Commander](practice/ladders/graphs/centroid-decomposition/cielthecommander.md) |
| [dinic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dinic.cpp) | max-flow / min-cut on a moderate network | edge costs matter or pure bipartite matching is the only goal | [Maximum Flow](topics/graphs/flow/README.md) | [Police Chase](practice/ladders/graphs/flow/policechase.md) |
| [flow-lower-bounds.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/flow-lower-bounds.cpp) | feasible circulation where every directed edge has `lower <= flow <= upper`, or one lower-bounded `s-t` model after adding `t -> s` | costs dominate, the task is still plain max flow, or you forgot to close the `s-t` model into a circulation | [Flow With Lower Bounds](topics/graphs/flow-lower-bounds/README.md) | [Reactor Cooling](practice/ladders/graphs/flow/reactorcooling.md) |
| [min-cost-flow.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/min-cost-flow.cpp) | flow value and edge costs both matter, with nonnegative initial residual costs in this snippet | max-flow value alone is enough or negative-cost edges need an initial potential pass | [Maximum Flow](topics/graphs/flow/README.md) | [MINCOST](practice/ladders/graphs/flow/mincost.md) |
| [hopcroft-karp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hopcroft-karp.cpp) | bipartite maximum matching at scale | matching is not bipartite or costs/weights matter | [Matching](topics/graphs/matching/README.md) | [School Dance](practice/ladders/graphs/matching/schooldance.md) |

## Strings Chooser

| Template | Signal | Avoid when | Teaching anchor | Representative use |
| --- | --- | --- | --- | --- |
| [rolling-hash.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/rolling-hash.cpp) | same-length substring fingerprints, borders, or LCP via binary search | exact proof-critical matching needs zero collision risk by itself | [String Hashing](topics/strings/hashing/README.md) | [Finding Borders](practice/ladders/strings/hashing/findingborders.md) |
| [kmp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/kmp.cpp) | one exact pattern against one text, plus border-chain reuse | many patterns or all-substring aggregation | [KMP](topics/strings/kmp/README.md) | [String Matching](practice/ladders/strings/kmp/stringmatching.md) |
| [z-function.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/z-function.cpp) | one-string diagnostics, prefix matches, borders, or periods | dictionary matching over many patterns | [Z-Function](topics/strings/z-function/README.md) | [Finding Periods](practice/ladders/strings/z-function/findingperiods.md) |
| [manacher.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/manacher.cpp) | one static string where longest palindrome or all odd/even center radii matter | dynamic updates or many arbitrary palindrome queries are the real task | [Palindromes / Manacher](topics/strings/palindromes/README.md) | [Longest Palindrome](practice/ladders/strings/palindromes/longestpalindrome.md) |
| [eertree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/eertree.cpp) | one growing lowercase string where distinct palindromes or longest palindromic suffixes matter | the string is static and `Manacher` already solves it, or the task is arbitrary substring palindrome checks | [Eertree / Palindromic Tree](topics/strings/eertree/README.md) | [Distinct Palindromic Substrings](practice/ladders/strings/eertree/distinctpalindromicsubstrings.md) |
| [trie-basic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/trie-basic.cpp) | many words with shared-prefix transitions | a sort/lower_bound pass already solves the task | [Trie](topics/strings/trie/README.md) | [Word Combinations](practice/ladders/strings/trie/wordcombinations.md) |
| [aho-corasick.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/aho-corasick.cpp) | many patterns against one text | only one pattern matters or you need all substrings of one base string instead | [Aho-Corasick](topics/strings/aho-corasick/README.md) | [Finding Patterns](practice/ladders/strings/aho-corasick/findingpatterns.md) |
| [suffix-array.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/suffix-array.cpp) | global suffix order, LCP, repeated substring queries | online extension or state-based substring aggregation is the core need | [Suffix Array And LCP](topics/strings/suffix-array-lcp/README.md) | [Repeating Substring](practice/ladders/strings/suffix-array-lcp/repeatingsubstring.md) |
| [suffix-automaton.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/suffix-automaton.cpp) | one base string, all substrings matter, and state aggregation helps | many independent patterns are matched against one long text | [Suffix Automaton](topics/strings/suffix-automaton/README.md) | [Distinct Substrings](practice/ladders/strings/suffix-automaton/distinctsubstrings.md) |

## Current Templates

### Foundations

- chooser table above; use the pilot cards plus the foundations chooser before browsing raw files

### Data Structures

- chooser table above; this group now carries the same compact contract style as foundations

### Graphs

- chooser table above; use it before browsing raw graph templates under contest pressure

### Dynamic Programming

## Dynamic Programming Chooser

| Template | Signal | Avoid when | Teaching anchor | Representative use |
| --- | --- | --- | --- | --- |
| [knapsack-01.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/knapsack-01.cpp) | `0/1` item choices with one capacity axis | items are unbounded or the state is not a capacity DP | [Knapsack Family](topics/dp/knapsack-family/README.md) | [Book Shop](practice/ladders/dp/knapsack-family/bookshop.md) |
| [bitmask-subset-iterate.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/bitmask-subset-iterate.cpp) | forward subset DP that adds one missing bit at a time | `n` is too large for `2^n`, or transitions need arbitrary submasks instead of one added bit | [Bitmask DP](topics/dp/bitmask-dp/README.md) | [VMMARBLE](practice/ladders/dp/bitmask-dp/vmmarble.md) |
| [tree-dp-subtree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/tree-dp-subtree.cpp) | child-to-parent subtree states solved in one postorder DFS | each node also needs parent-side information | [Tree DP](topics/dp/tree-dp/README.md) | [Tree Matching](practice/ladders/dp/tree-dp/treematching.md) |
| [tree-dp-rerooting.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/tree-dp-rerooting.cpp) | sum-of-distances rerooting where every node needs an answer | the reroot transition is not this distance-sum formula or you only need one rooted answer | [Tree DP](topics/dp/tree-dp/README.md) | [Tree Distances II](practice/ladders/dp/tree-dp/treedistances2.md) |
| [digit-dp-skeleton.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/digit-dp-skeleton.cpp) | count over digits with `tight` and `started` flags | the state is not prefix-closed by decimal digits | [Digit DP](topics/dp/digit-dp/README.md) | [Counting Numbers](practice/ladders/dp/digit-dp/countingnumbers.md) |
| [interval-dp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/interval-dp.cpp) | split-point interval DP with contiguous intervals `[l, r]` | transitions are endpoint-choice style or dependencies are not interval-shaped | [Interval DP](topics/dp/interval-dp/README.md) | [Interval DP Ladder](practice/ladders/dp/interval-dp/README.md) |
| [li-chao-tree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/li-chao-tree.cpp) | affine DP or line-container queries with online insertion and a known integer x-domain | monotone hull is enough, or lines are only active on x-subsegments | [Convex Hull Trick / Li Chao Tree](topics/dp/cht-li-chao/README.md) | [Monster Game II](practice/ladders/dp/cht-li-chao/monstergame2.md) |

### Math

## Math Chooser

| Template | Signal | Avoid when | Teaching anchor | Representative use |
| --- | --- | --- | --- | --- |
| [modular-arithmetic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/modular-arithmetic.cpp) | repeated `powmod` and inverse under one fixed prime modulus | modulus is composite or changes per query | [Modular Arithmetic](topics/math/modular-arithmetic/README.md) | [Exponentiation](practice/ladders/math/modular-arithmetic/exponentiation.md) |
| [matrix-exponentiation.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/matrix-exponentiation.cpp) | small fixed-dimension linear recurrence or repeated linear transition under one modulus | the transition is not linear, the dimension is too large, or a specialized recurrence trick is cleaner | [Linear Recurrence / Matrix Exponentiation](topics/math/linear-recurrence/README.md) | [Throwing Dice](practice/ladders/math/linear-recurrence/throwingdice.md) |
| [xor-basis.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/xor-basis.cpp) | subset xor span, representability, or maximum subset xor under xor-any-subset semantics | the query is best xor against one stored value, or you need order-statistics / merge variants this starter does not advertise | [XOR Basis / Linear Basis](topics/math/xor-basis/README.md) | [XMAX - XOR Maximization](practice/ladders/math/xor-basis/xmax.md) |
| [sprague-grundy-subtract-set.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/sprague-grundy-subtract-set.cpp) | impartial normal-play game where each component is one bounded integer state and several components combine by xor of Grundy values | the game is misere, score-based, partisan, cyclic without reduction, or the intended route is a closed form not advertised by this starter | [Game Theory / Sprague-Grundy](topics/math/game-theory/README.md) | [S-Nim](practice/ladders/math/game-theory/snim.md) |
| [factorial-binomial-mod.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/factorial-binomial-mod.cpp) | one or many `nCk mod prime` queries after one precompute | `max_n >= mod` or the modulus is not prime | [Counting Basics](topics/combinatorics/counting-basics/README.md) | [Distributing Apples](practice/ladders/combinatorics/counting-basics/distributingapples.md) |
| [extended-gcd-diophantine.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/extended-gcd-diophantine.cpp) | need Bezout coefficients, one inverse under composite modulus, or solve `ax + by = c` | prime-mod inverses with many queries are the real task | [Modular Arithmetic](topics/math/modular-arithmetic/README.md) | [Euclid Problem](practice/ladders/math/gcd-lcm/euclidproblem.md) |
| [chinese-remainder.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/chinese-remainder.cpp) | merge one or many congruences, including non-coprime moduli with gcd consistency checks | you only need one inverse or one Bézout witness and not a whole congruence system | [Chinese Remainder / Linear Congruences](topics/math/chinese-remainder/README.md) | [General Chinese Remainder](practice/ladders/math/chinese-remainder/generalchineseremainder.md) |
| [lucas-binomial.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/lucas-binomial.cpp) | huge `nCk mod p` queries where one factorial table fails but base-`p` digit decomposition works | the modulus is composite, or `p` is too large for `O(p)` precompute to be sane | [Lucas Theorem / Large Binomial Mod Prime](topics/math/lucas-theorem/README.md) | [Binomial Coefficient (Prime Mod)](practice/ladders/math/lucas-theorem/binomialcoefficientprimemod.md) |
| [mobius-linear-sieve.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/mobius-linear-sieve.cpp) | divisor-side inclusion-exclusion where `cnt[d]` over multiples and Mobius weights recover exact gcd structure | the prime set is tiny enough for ordinary inclusion-exclusion, or you only need one monotone divisor-frequency scan | [Mobius And Multiplicative Counting](topics/math/mobius-multiplicative/README.md) | [Counting Coprime Pairs](practice/ladders/math/mobius-multiplicative/countingcoprimepairs.md) |
| [number-theory-basics.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/number-theory-basics.cpp) | gcd/lcm, SPF sieve, and factorization are the real primitives | you mainly need modular inverses or convolution | [Number Theory Basics](topics/math/number-theory-basics/README.md) | [CRYPTKEY](practice/ladders/math/gcd-lcm/cryptkey.md) |
| [fft.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/fft.cpp) | approximate real/complex FFT or integer convolution with acceptable floating error | you need exact modular/integer convolution guarantees | [FFT / NTT](topics/math/fft-ntt/README.md) | [POST2](practice/ladders/math/fft/post2.md) |
| [ntt.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/ntt.cpp) | exact convolution modulo `998244353` | modulus is incompatible or convolution is over reals | [FFT / NTT](topics/math/fft-ntt/README.md) | [Convolution](practice/ladders/math/fft/convolution.md) |

### Strings

- chooser table above; this group now exposes the same contract fields as the mature foundations templates

### Geometry

## Geometry Chooser

| Template | Signal | Avoid when | Teaching anchor | Representative use |
| --- | --- | --- | --- | --- |
| [geometry-primitives.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/geometry-primitives.cpp) | orientation, cross/dot, and exact integer predicates are the real base layer | the problem is already at polygon or hull level and a higher template fits directly | [Vector And Orientation](topics/geometry/vector-orientation/README.md) | [Point Location Test](practice/ladders/geometry/vector-orientation/pointlocationtest.md) |
| [segment-intersection-basic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/segment-intersection-basic.cpp) | closed-segment intersection with endpoints and overlap counted | you need sweep-line over many segments, not one pair predicate | [Segment Intersection](topics/geometry/segment-intersection/README.md) | [Line Segment Intersection](practice/ladders/geometry/segment-intersection/linesegmentintersection.md) |
| [shoelace-area.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/shoelace-area.cpp) | polygon area from ordered boundary vertices | vertices are not in boundary order or the polygon is self-intersecting | [Polygon Area And Point Location](topics/geometry/polygon-area-point-location/README.md) | [Polygon Area](practice/ladders/geometry/polygon-area-point-location/polygonarea.md) |
| [point-in-polygon.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/point-in-polygon.cpp) | classify `outside / boundary / inside` for a simple polygon | the polygon is not simple or you need a higher-dimensional predicate | [Polygon Area And Point Location](topics/geometry/polygon-area-point-location/README.md) | [Point in Polygon](practice/ladders/geometry/polygon-area-point-location/pointinpolygon.md) |
| [convex-hull.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/convex-hull.cpp) | hull of static points in the plane | dynamic hull maintenance or keep-all-collinear-boundary policy is required | [Convex Hull](topics/geometry/convex-hull/README.md) | [Convex Hull](practice/ladders/geometry/convex-hull/convexhull.md) |

## Standard

Each template should stay compact, contest-usable, and linked back to the teaching page that explains:

- when to use it
- why it works
- the main implementation invariants
- the common failure cases

## Representative Uses In This Repo

- Fenwick tree -> [CVP00001](practice/ladders/data-structures/fenwick-tree/cvp00001.md)
- ordered multiset / predecessor -> [Concert Tickets](practice/ladders/data-structures/heaps-and-ordered-sets/concerttickets.md)
- shortest-path family -> [Message Route](practice/ladders/graphs/bfs-dfs/messageroute.md), [QOS](practice/ladders/graphs/shortest-paths/qos.md)
- low-link critical structure -> [Necessary Roads](practice/ladders/graphs/bridges-articulation/necessaryroads.md)
- 2-SAT / implication graph -> [Giant Pizza](practice/ladders/graphs/two-sat/giantpizza.md)
- lazy segment tree -> [HORRIBLE](practice/ladders/data-structures/lazy-segment-tree/horriblequeries.md)
- rollback DSU / offline dynamic connectivity -> [Dynamic Connectivity](practice/ladders/data-structures/dsu-rollback/dynamicconnectivity.md)
- centroid decomposition -> [Ciel the Commander](practice/ladders/graphs/centroid-decomposition/cielthecommander.md)
- max flow / lower-bounded circulation / min-cost flow -> [FFLOW](practice/ladders/graphs/flow/fflow.md), [Reactor Cooling](practice/ladders/graphs/flow/reactorcooling.md), [MINCOST](practice/ladders/graphs/flow/mincost.md)
- modular arithmetic helpers -> [Exponentiation](practice/ladders/math/modular-arithmetic/exponentiation.md), [CRYPTKEY](practice/ladders/math/gcd-lcm/cryptkey.md)
- congruence-system merges -> [General Chinese Remainder](practice/ladders/math/chinese-remainder/generalchineseremainder.md)
- large binomial modulo one prime -> [Binomial Coefficient (Prime Mod)](practice/ladders/math/lucas-theorem/binomialcoefficientprimemod.md)
- Mobius-weighted gcd counting -> [Counting Coprime Pairs](practice/ladders/math/mobius-multiplicative/countingcoprimepairs.md)
- matrix exponentiation / linear recurrence -> [Throwing Dice](practice/ladders/math/linear-recurrence/throwingdice.md)
- xor basis / maximum subset xor -> [XMAX - XOR Maximization](practice/ladders/math/xor-basis/xmax.md)
- Sprague-Grundy / impartial-game sums -> [S-Nim](practice/ladders/math/game-theory/snim.md)
- segment / polygon geometry -> [Point Location Test](practice/ladders/geometry/vector-orientation/pointlocationtest.md), [Line Segment Intersection](practice/ladders/geometry/segment-intersection/linesegmentintersection.md)

### `__int128` helper

Use `__int128` when a single multiplication may already be near `10^18`, or when many such products are accumulated exactly.

Typical examples:

- shoelace area for geometry
- modular multiplication before taking `%`
- prefix sums of large products

Minimal print helper:

```cpp
static void print_int128(__int128 x) {
    if (x == 0) {
        cout << 0;
        return;
    }
    if (x < 0) {
        cout << '-';
        x = -x;
    }
    string s;
    while (x > 0) {
        s.push_back(char('0' + x % 10));
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}
```

Keep in mind:

- `__int128` is a GCC/Clang extension, not standard C++
- it has no normal `cin` / `cout` overloads
- it is great for exact integer arithmetic, but it still has finite range
