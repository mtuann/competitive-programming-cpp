# Sparse Table

Sparse table is the clean static-range-query structure for idempotent operations like `min`, `max`, or `gcd`.

## Prerequisites

- [Prefix Sums](../../foundations/patterns/prefix-sums/README.md)

## When To Suspect It

- the array is static
- there are many range queries
- the merge operation is idempotent, like `min(x, x) = x`

## Core Idea

Precompute answers for intervals of length `2^k`.

For idempotent operations, any query can be answered by combining two overlapping blocks of equal length.

## Theory / Proof Sketch

Let `st[k][i]` store the answer on `[i, i + 2^k - 1]`.

Then for a range `[l, r]`, choose:

```text
k = floor(log2(r - l + 1))
```

and combine:

```text
[l, l + 2^k - 1]` and `[r - 2^k + 1, r]
```

For idempotent operations, overlap is harmless.

## Complexity And Tradeoffs

- build: `O(n log n)`
- query: `O(1)`
- memory: `O(n log n)`

Tradeoffs:

- unbeatable for static RMQ-like queries
- useless once updates matter

## Canonical Pattern

Template in this repo:

- [sparse-table-rmq.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/sparse-table-rmq.cpp)

## Worked Examples

Example 1: static range minimum

Example 2: static range gcd

Example 3: LCA via Euler tour + RMQ

## Common Mistakes

- applying sparse table to non-idempotent operations with the same two-block trick
- getting the log table wrong
- forgetting that updates break the whole structure

## Practice Ladder

- [Sparse table ladder](../../../practice/ladders/data-structures/sparse-table/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Sparse Table](https://cp-algorithms.com/data_structures/sparse-table.html)
- Practice: [CSES Range Queries](https://cses.fi/problemset/)

## Related Topics

- [Segment Tree](../segment-tree/README.md)
- [LCA](../../graphs/lca/README.md)
