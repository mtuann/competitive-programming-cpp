# Fenwick Tree

Fenwick tree, or Binary Indexed Tree, is the lightest standard structure for dynamic prefix sums and several closely related patterns.

## Prerequisites

- [Prefix Sums](../../foundations/patterns/prefix-sums/README.md)

## When To Suspect It

- point updates and prefix or range-sum queries are interleaved
- the operation is additive and associative
- you need order statistics on frequencies
- a segment tree feels heavier than necessary

## Core Idea

Fenwick tree stores partial sums over ranges whose lengths are powers of two.

The key bit trick is:

```text
lowbit(x) = x & -x
```

That tells you the size of the block represented at index `x`.

## Theory / Proof Sketch

Each tree index covers a suffix of a prefix.

When you move:

- downward with `x -= lowbit(x)`, you peel off disjoint blocks to compute a prefix sum
- upward with `x += lowbit(x)`, you update exactly the blocks that include the modified position

Because those blocks partition the needed range, the sum is correct.

## Complexity And Tradeoffs

- point update: `O(log n)`
- prefix query: `O(log n)`
- memory: `O(n)`

Tradeoffs:

- smaller and simpler than a segment tree
- excellent for additive patterns
- not the right tool for arbitrary non-invertible range operations

## Canonical C++ Pattern

Template in this repo:

- [fenwick-point-prefix.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/fenwick-point-prefix.cpp)

Strong default conventions:

- use one-based indexing inside the structure
- expose `add(idx, delta)` and `sum_prefix(idx)`
- derive range sums from two prefix sums

## Worked Examples

Example 1: dynamic range sums

```text
sum(l..r) = sum_prefix(r) - sum_prefix(l - 1)
```

Example 2: inversion counting

- compress values
- scan from right to left
- count how many smaller values have already appeared

Example 3: order statistic on frequencies

- store counts instead of values
- find the first prefix where the cumulative count reaches `k`

## Common Mistakes

- mixing zero-based external indexes with one-based internal indexes
- forgetting that the default Fenwick tree supports prefix queries, not arbitrary segment merges
- using `int` when the total sum may overflow

## Practice Ladder

- [Data structures ladder](../../../practice/ladders/data-structures/README.md)
- [Fenwick tree ladder](../../../practice/ladders/data-structures/fenwick-tree/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Fenwick Tree](https://cp-algorithms.com/data_structures/fenwick.html)
- Reference: [USACO Guide - BIT / Fenwick Tree](https://usaco.guide/gold/PURS)
- Practice: [CSES Problem Set](https://cses.fi/problemset/)

## Related Topics

- [Prefix Sums](../../foundations/patterns/prefix-sums/README.md)
- [Difference Arrays](../../foundations/patterns/difference-arrays/README.md)
- [DSU](../dsu/README.md)
