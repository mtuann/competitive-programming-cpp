# Segment Tree

Segment tree is the default “heavy but general” range-query structure. Use it when Fenwick is too limited and the array changes over time.

## Prerequisites

- [Fenwick Tree](../fenwick-tree/README.md)
- [C++ Language For Contests](../../foundations/cpp-language/README.md)

## When To Suspect It

- many range queries with interleaved updates
- the merge operation is associative
- you need more than prefix sums
- you want range minimum, maximum, gcd, count, or a custom merged state

## Core Idea

Split the array into segments and store one summary per segment.

Each node answers for one interval. Queries and updates touch only `O(log n)` nodes.

## Theory / Proof Sketch

The invariant is:

```text
tree[node] stores the correct merged answer for its interval
```

When updating one position, only nodes whose intervals contain that position need recomputation. When querying, the answer interval is decomposed into disjoint covered segments whose stored summaries merge to the final answer.

## Complexity And Tradeoffs

- point update: `O(log n)`
- range query: `O(log n)`
- memory: `O(n)` or about `4n` in recursive implementations

Tradeoffs:

- more general than Fenwick
- heavier constants
- requires you to define a clean merge function and identity element

## Canonical Pattern

Template in this repo:

- [segment-tree-iterative.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/segment-tree-iterative.cpp)

Good first choice:

- iterative segment tree for point update + range query

## Worked Examples

Example 1: range minimum query with point updates

Example 2: range sum with point updates

Example 3: descent query

- first position where prefix sum reaches `k`
- first value at least `x`

## Common Mistakes

- no proper identity element
- wrong half-open or closed interval convention
- using segment tree when prefix sums or Fenwick would be simpler

## Practice Ladder

- [Segment tree ladder](../../../practice/ladders/data-structures/segment-tree/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Segment Tree](https://cp-algorithms.com/data_structures/segment_tree.html)
- Reference: [USACO Guide - Segment Tree](https://usaco.guide/plat/segtree-ext/)
- Practice: [CSES Range Queries](https://cses.fi/problemset/)

## Related Topics

- [Fenwick Tree](../fenwick-tree/README.md)
- [Sparse Table](../sparse-table/README.md)
- [Offline Tricks](../offline-tricks/README.md)
