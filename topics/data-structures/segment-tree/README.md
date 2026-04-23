# Segment Tree

Segment tree is the default “heavy but general” range-query structure. Reach for it when Fenwick is too limited and the array changes over time.

## Summary

Suspect segment tree when:

- range queries and updates are interleaved
- the merge operation is associative
- you need more than prefix sums
- you want minimum, maximum, gcd, count, or a custom merged state

What success looks like:

- you can define the node value, merge function, and identity element clearly
- you know whether you need point updates, lazy propagation, or a descent query
- you can explain why Fenwick is insufficient for the problem

## Prerequisites

- [Fenwick Tree](../fenwick-tree/README.md)
- [C++ Language For Contests](../../foundations/cpp-language/README.md)

## Core Idea

Split the array into intervals and store one summary per interval.

The key invariant is:

```text
tree[node] stores the correct merged answer for its interval
```

Queries decompose the target interval into a small number of disjoint covered segments. Updates only affect the nodes whose intervals contain the changed positions.

## Theory / Proof Sketch

If the merge operation is associative, then:

```text
answer on [l, r]
= merge(answer on left covered piece, answer on right covered piece, ...)
```

That is why segment trees work for:

- sum
- min / max
- gcd
- counts
- custom structs with associative merge

Each point update changes only one leaf and the `O(log n)` ancestors above it. Each range query touches only `O(log n)` nodes in the canonical decomposition.

## Complexity And Tradeoffs

- point update: `O(log n)`
- range query: `O(log n)`
- memory: `O(n)` for iterative style, often written as about `4n` in recursive style

Tradeoffs:

- more general than Fenwick
- larger constants
- requires a clean merge function and identity value

## Canonical C++ Pattern

Template in this repo:

- [segment-tree-iterative.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/segment-tree-iterative.cpp)

Good first choice:

- iterative segment tree for point update + range query

Three things to define before coding:

1. node meaning
2. merge function
3. identity element

If any of those is fuzzy, the implementation usually becomes fragile.

## Standard Patterns

### 1. Point Update + Range Query

The entry-level segment tree:

- update one position
- query sum/min/max/gcd on `[l, r]`

### 2. Descent Queries

Use the tree structure itself to find:

- first position where prefix sum reaches `k`
- first position with value at least `x`

This is a major reason segment tree is broader than Fenwick.

### 3. Lazy Propagation

Needed when updates themselves affect whole ranges and must stay online:

- range add
- range assign
- query afterward

This is important, but should be learned after the simple version is stable.

### 4. Custom Node States

Some problems store more than one number per node, for example:

- max subarray information
- bracket sequence validity data
- counts plus best prefix/suffix information

## Worked Examples

### Example 1: range minimum with point updates

Each node stores the minimum on its interval.

Merge:

```text
merge(a, b) = min(a, b)
```

This is the cleanest non-sum example.

### Example 2: range sum with point updates

This works too, but if you only need sums, Fenwick is usually lighter.

That comparison is part of learning the structure well.

### Example 3: first position where prefix sum reaches `k`

Instead of querying prefixes one by one, descend the tree:

- check the left child’s sum
- if it already reaches `k`, stay left
- otherwise subtract and go right

This is one of the most useful segment-tree-specific tricks.

## Recognition Cues

Strong clues:

- dynamic interval queries
- custom merge over ranges
- point updates plus something more general than prefix sums
- “first position satisfying...” with online updates

Segment tree is often confused with:

- [Fenwick Tree](../fenwick-tree/README.md), which is lighter but narrower
- [Sparse Table](../sparse-table/README.md), which is static only
- [Prefix Sums](../../foundations/patterns/prefix-sums/README.md), which are static and additive only

## Common Mistakes

- no correct identity element
- wrong half-open vs closed interval convention
- using segment tree before checking whether prefix sums or Fenwick is simpler
- trying to do range updates without lazy propagation
- writing a merge that is not actually associative

## Practice Ladder

- [Segment tree ladder](../../../practice/ladders/data-structures/segment-tree/README.md)

Suggested order:

1. point update + range min
2. point update + range sum
3. descent queries
4. lazy propagation later

## Go Deeper

- Reference: [CP-Algorithms - Segment Tree](https://cp-algorithms.com/data_structures/segment_tree.html)
- Reference: [USACO Guide - Segment Tree](https://usaco.guide/plat/segtree-ext/)
- Practice: [CSES Range Queries](https://cses.fi/problemset/)
- Next step: [Sparse Table](../sparse-table/README.md)

## Related Topics

- [Fenwick Tree](../fenwick-tree/README.md)
- [Sparse Table](../sparse-table/README.md)
- [Offline Tricks](../offline-tricks/README.md)
