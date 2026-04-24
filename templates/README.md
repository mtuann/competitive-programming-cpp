# Templates

This folder contains reusable contest-ready code, not full tutorials.

## Contract

Each template should answer one practical question: "can I trust copying this, and what does it already assume?"

For now, every mature template should expose these six fields somewhere obvious:

- `Signal`: the shortest recognition cue for when to reach for it
- `Assumes`: the invariant, indexing policy, or problem shape it already depends on
- `Exposes`: the main function, struct, or return contract you are meant to reuse
- `Complexity`: the cost of the core operation or the standard usage mode
- `Main trap`: the failure mode most likely to survive into a wrong answer
- `Links`: the strongest topic page, notebook page, or repo note to reopen if trust is low

Rollout rule:

- keep the full retrieval cards in [template-library.md](../template-library.md)
- keep a compact version of the same metadata in the header comment of the template file itself
- do not let template headers turn into full tutorials

This layer is `evergreen`, but it should still be source-backed through the topic pages and notes it links to.

## Current Template Groups

- `foundations/`
  - contest main
  - fast I/O
  - sort / comparator
  - binary search
  - prefix sum
  - difference array
  - two pointers
- `data-structures/`
  - DSU
  - Fenwick tree
  - segment tree
  - sparse table
  - heaps / lazy deletion
  - offline-query skeleton
- `graphs/`
  - BFS
  - iterative DFS
  - Dijkstra
  - Kruskal
  - topological sort
  - SCC
  - LCA
  - Dinic
  - min-cost flow
  - Hopcroft-Karp
- `dp/`
  - `0/1` knapsack
  - bitmask DP
  - tree DP
  - digit DP
  - interval DP
- `math/`
  - modular arithmetic
  - number theory basics
  - FFT
- `strings/`
  - rolling hash
  - KMP
  - Z-function
  - trie
  - Aho-Corasick
  - suffix array
- `geometry/`
  - geometry primitives
  - convex hull

Each template should stay compact, compile on its own, and link back to the teaching page in `topics/`.

## Foundations Pilot

The first templates to hold the full contract are:

- `foundations/contest-main.cpp`
- `foundations/fast-io.cpp`
- `foundations/sort-and-comparator.cpp`
- `foundations/binary-search-last-false.cpp`
- `foundations/prefix-sum-1d.cpp`
- `foundations/binary-search-first-true.cpp`
- `foundations/difference-array.cpp`
- `foundations/two-pointers-variable-window.cpp`

Use these as the reference pattern before rolling the metadata style out to the rest of the repo.
