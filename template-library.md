# Template Library

This page is the map for the repo's reusable contest-ready code. The actual implementations live under [`templates/`](https://github.com/mtuann/competitive-programming-cpp/tree/main/templates); this page is here so you can retrieve the right snippet quickly under contest pressure.

## Fast Pick By Signal

- smallest clean contest skeleton: [contest-main.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/contest-main.cpp)
- large input but ordinary batch stdin/stdout: [fast-io.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/fast-io.cpp)
- shortest path on unit edges: [bfs.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bfs.cpp)
- shortest path on `0/1` edges: [zero-one-bfs.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/zero-one-bfs.cpp)
- shortest path with negative edges: [bellman-ford.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bellman-ford.cpp)
- all-pairs shortest paths on small `n`: [floyd-warshall.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/floyd-warshall.cpp)
- predecessor / previous value in a multiset: [multiset-predecessor.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/multiset-predecessor.cpp)
- sliding median with duplicates: [sliding-median-two-multisets.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/sliding-median-two-multisets.cpp)
- sliding minimum or monotone-window DP: [monotonic-deque-min.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/monotonic-deque-min.cpp)
- many `nCk mod prime` queries: [factorial-binomial-mod.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/factorial-binomial-mod.cpp)
- inverse under composite modulus or `ax + by = c`: [extended-gcd-diophantine.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/extended-gcd-diophantine.cpp)
- exact convolution modulo a friendly prime: [ntt.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/ntt.cpp)
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

## Template Card Contract

For mature templates, this repo uses six short metadata fields:

- `Signal`: the fastest cue that this template is the right family
- `Assumes`: the boundary meaning, invariant, or data-shape contract already baked in
- `Exposes`: the function, struct, or return contract you are expected to reuse
- `Complexity`: the standard operation cost you should keep in your head while using it
- `Main trap`: the bug most likely to survive hand tests
- `Links`: the strongest reopening path when trust is low

The library page carries the fuller cards. The template file itself only keeps the compact version.

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
| [two-pointers-variable-window.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/two-pointers-variable-window.cpp) | monotone sliding window with forward-only boundaries | negative values or non-monotone validity break the window logic | [Two Pointers](topics/foundations/patterns/two-pointers/README.md) | [Apartments](practice/ladders/foundations/two-pointers/apartments.md) |

## Current Templates

### Foundations

- chooser table above; use the pilot cards plus the foundations chooser before browsing raw files

### Data Structures

- [dsu-basic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/dsu-basic.cpp)
- [fenwick-point-prefix.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/fenwick-point-prefix.cpp)
- [segment-tree-iterative.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/segment-tree-iterative.cpp)
- [sparse-table-rmq.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/sparse-table-rmq.cpp)
- [heap-lazy-delete.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/heap-lazy-delete.cpp)
- [multiset-predecessor.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/multiset-predecessor.cpp)
- [sliding-median-two-multisets.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/sliding-median-two-multisets.cpp)
- [monotonic-deque-min.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/monotonic-deque-min.cpp)
- [offline-query-skeleton.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/offline-query-skeleton.cpp)

### Graphs

- [bfs.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bfs.cpp)
- [dfs-iterative.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dfs-iterative.cpp)
- [zero-one-bfs.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/zero-one-bfs.cpp)
- [dijkstra.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dijkstra.cpp)
- [bellman-ford.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bellman-ford.cpp)
- [floyd-warshall.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/floyd-warshall.cpp)
- [kruskal.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/kruskal.cpp)
- [toposort-kahn.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/toposort-kahn.cpp)
- [scc-kosaraju.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/scc-kosaraju.cpp)
- [lca-binary-lifting.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/lca-binary-lifting.cpp)
- [dinic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dinic.cpp)
- [min-cost-flow.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/min-cost-flow.cpp)
- [hopcroft-karp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hopcroft-karp.cpp)

### Dynamic Programming

- [knapsack-01.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/knapsack-01.cpp)
- [bitmask-subset-iterate.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/bitmask-subset-iterate.cpp)
- [tree-dp-subtree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/tree-dp-subtree.cpp)
- [tree-dp-rerooting.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/tree-dp-rerooting.cpp)
- [digit-dp-skeleton.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/digit-dp-skeleton.cpp)
- [interval-dp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/interval-dp.cpp)

### Math

- [modular-arithmetic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/modular-arithmetic.cpp)
- [factorial-binomial-mod.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/factorial-binomial-mod.cpp)
- [extended-gcd-diophantine.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/extended-gcd-diophantine.cpp)
- [number-theory-basics.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/number-theory-basics.cpp)
- [fft.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/fft.cpp)
- [ntt.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/ntt.cpp)

### Strings

- [rolling-hash.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/rolling-hash.cpp)
- [kmp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/kmp.cpp)
- [z-function.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/z-function.cpp)
- [trie-basic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/trie-basic.cpp)
- [aho-corasick.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/aho-corasick.cpp)
- [suffix-array.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/suffix-array.cpp)
- [suffix-automaton.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/suffix-automaton.cpp)

### Geometry

- [geometry-primitives.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/geometry-primitives.cpp)
- [segment-intersection-basic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/segment-intersection-basic.cpp)
- [shoelace-area.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/shoelace-area.cpp)
- [point-in-polygon.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/point-in-polygon.cpp)
- [convex-hull.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/convex-hull.cpp)

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
- max flow / min-cost flow -> [FFLOW](practice/ladders/graphs/flow/fflow.md), [MINCOST](practice/ladders/graphs/flow/mincost.md)
- modular arithmetic helpers -> [Exponentiation II](practice/ladders/math/modular-arithmetic/exponentiation2.md), [CRYPTKEY](practice/ladders/math/gcd-lcm/cryptkey.md)
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
