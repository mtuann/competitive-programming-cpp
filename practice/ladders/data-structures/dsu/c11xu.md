# C11XU

- Title: `C11XU - Bộ sưu tập đồng xu`
- Judge / source: `VN SPOJ / VNOI`
- Original URL: [https://vn.spoj.com/problems/C11XU/](https://vn.spoj.com/problems/C11XU/)
- Mirror URL: [https://oj.vnoi.info/problem/c11xu](https://oj.vnoi.info/problem/c11xu)
- Secondary topics: `Graphic matroid`, `Forest independence`, `Augmenting path`
- Difficulty: `hard`
- Subtype: `Choose at most one envelope per pair-group so the chosen envelope-edges stay acyclic`
- Status: `solved`
- Solution file: [c11xu.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/dsu/c11xu.cpp)

## Why Practice This

This is a strong modeling problem.

The statement is about envelopes and parity, but the accepted reduction is:

- each envelope becomes one edge between coin types
- a bad subset is exactly a subset whose xor-parity is zero
- in graph language, that means a cycle / even subgraph

So the chosen envelopes must form a forest.

## Core Idea

For an envelope containing coin types `u` and `v`:

- if `u = v`, its parity vector is zero, so choosing it is immediately bad
- otherwise it behaves like the incidence vector of an undirected edge `(u, v)`

A nonempty chosen subset is bad exactly when every type appears an even number of times inside that subset.

For edge-incidence vectors over `GF(2)`, that means:

- the chosen subset has xor-sum `0`
- equivalently, it contains a cycle / Eulerian subgraph

So valid chosen envelopes are exactly a forest in the type graph.

There is one more rule:

- from each consecutive pair of envelopes, you may choose at most one

That is the intersection of:

- a `partition matroid` on envelope-pairs
- a `graphic matroid` on the type graph

With at most `1000` envelopes total, a small augmenting-path solver is fine.

## Complexity

Let `E = N / 2` be the number of envelopes.

The repo solution runs a cardinality matroid-intersection style augmentation in a size that is small enough for the judge:

- time: good enough for `E <= 1000`
- memory: `O(E + M)`

## Pitfalls / Judge Notes

- An envelope with two equal coin types can never be chosen.
- “No bad subset” is stronger than “the whole chosen set is not bad”. You must forbid **every** nonempty chosen subset from having even parity on all types.
- The right graph view is forest independence, not just DSU-greedy. A naive greedy choice can block a better later choice.

## Reusable Pattern

- Topic page: [DSU](../../../../topics/data-structures/dsu/README.md)
- Practice ladder: [DSU ladder](README.md)
- Starter template: [dsu-basic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/dsu-basic.cpp)
- Notebook refresher: [Data structures cheatsheet](../../../../notebook/data-structures-cheatsheet.md)
- Carry forward: state the set invariant first, then use DSU only for the merge logic it really supports.
- This note adds: the extra problem-specific state layered on top of the basic union-find scaffold.

## Solutions

- Code: [c11xu.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/dsu/c11xu.cpp)
