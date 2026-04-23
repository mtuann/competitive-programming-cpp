# Fenwick Tree

Fenwick tree, or Binary Indexed Tree, is the lightest standard structure for dynamic prefix sums and several closely related patterns. It is often the best first “real” dynamic data structure after prefix sums.

## Summary

Suspect Fenwick tree when:

- point updates and prefix or range queries are interleaved
- the operation is additive and associative
- you need frequency prefixes or order statistics on counts
- a segment tree feels heavier than necessary

What success looks like:

- you understand the `lowbit` decomposition instead of memorizing loops blindly
- you can derive range sums from prefix sums naturally
- you know when BIT is enough and when segment tree is the better choice

## Prerequisites

- [Prefix Sums](../../foundations/patterns/prefix-sums/README.md)

## Core Idea

Fenwick tree stores partial sums on power-of-two-sized blocks.

Key bit trick:

```text
lowbit(x) = x & -x
```

Interpretation:

- index `x` stores the sum of the last `lowbit(x)` positions ending at `x`

That is why:

- querying a prefix repeatedly removes the lowest block
- updating a point repeatedly climbs to all blocks containing that point

## Theory / Proof Sketch

Each tree entry represents a disjoint suffix of a prefix.

For a prefix query:

- start at `x`
- add the block stored at `x`
- move to `x - lowbit(x)`

These visited blocks are disjoint and cover exactly the prefix `1..x`.

For a point update:

- start at the updated index
- add `delta` to every Fenwick node whose covered block contains that index
- those nodes are exactly the ones reached by repeatedly doing `x += lowbit(x)`

That is why both operations are correct.

## Complexity And Tradeoffs

- point update: `O(log n)`
- prefix query: `O(log n)`
- range sum: `O(log n)` via two prefix sums
- memory: `O(n)`

Tradeoffs:

- much smaller and simpler than a segment tree
- ideal for additive or invertible prefix-style operations
- weaker than segment tree for arbitrary custom range aggregates

## Canonical C++ Pattern

Template in this repo:

- [fenwick-point-prefix.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/fenwick-point-prefix.cpp)

Strong default conventions:

- use one-based indexing inside the structure
- expose `add(idx, delta)` and `sum_prefix(idx)`
- derive interval sums as:

```text
sum(l..r) = sum_prefix(r) - sum_prefix(l - 1)
```

## Standard Patterns

### 1. Dynamic Prefix And Range Sums

The most direct use:

- point update
- prefix or interval sum query

### 2. Frequency Structure

Store counts instead of values.

This gives:

- number of values `<= x`
- k-th order statistic on frequencies
- online counting after coordinate compression

### 3. Inversion Counting

Coordinate-compress values, then scan from right to left or left to right while querying how many smaller or larger values have already appeared.

### 4. Range-Update Variants

Fenwick can also support:

- range add + point query
- range add + range query

but those are best learned after the basic point-update / prefix-query version is automatic.

## Worked Examples

### Example 1: dynamic range sums

Maintain values under point updates:

```text
update(i, delta)
query(l, r) = prefix(r) - prefix(l - 1)
```

This is the clean “dynamic prefix sums” upgrade from static prefix arrays.

### Example 2: inversion counting

Compress values.

Then while scanning:

- query how many smaller values are already present
- add the current value into the Fenwick tree

The tree is being used as a dynamic frequency table.

### Example 3: order statistic on counts

If the Fenwick tree stores frequencies, you can binary-lift or descend on the implicit prefix sums to find the first index whose cumulative count reaches `k`.

That is a great example of using BIT for more than just sums.

## Recognition Cues

Strong clues:

- dynamic prefix sums
- frequency prefixes
- inversion counting after compression
- “point update, range query”

Fenwick tree is often confused with:

- [Prefix Sums](../../foundations/patterns/prefix-sums/README.md), which are static
- [Difference Arrays](../../foundations/patterns/difference-arrays/README.md), which are offline
- [Segment Tree](../segment-tree/README.md), which is heavier but more general

## Common Mistakes

- mixing zero-based and one-based indexing
- forgetting that the basic BIT is a prefix structure first
- using `int` when cumulative totals may overflow
- reaching for segment tree before checking if additive prefix structure is enough
- memorizing the loops without understanding what block each index stores

## Practice Ladder

- [Data structures ladder](../../../practice/ladders/data-structures/README.md)
- [Fenwick tree ladder](../../../practice/ladders/data-structures/fenwick-tree/README.md)

Suggested order:

1. point update + prefix sum
2. range sum via two prefixes
3. inversion counting with compression
4. frequency BIT and order-statistic queries

## Go Deeper

- Reference: [CP-Algorithms - Fenwick Tree](https://cp-algorithms.com/data_structures/fenwick.html)
- Reference: [USACO Guide - BIT / Fenwick Tree](https://usaco.guide/gold/PURS)
- Practice: [CSES Problem Set](https://cses.fi/problemset/)
- Practice: [CVP00001 note](../../../practice/ladders/data-structures/fenwick-tree/cvp00001.md)

## Related Topics

- [Prefix Sums](../../foundations/patterns/prefix-sums/README.md)
- [Difference Arrays](../../foundations/patterns/difference-arrays/README.md)
- [Segment Tree](../segment-tree/README.md)
