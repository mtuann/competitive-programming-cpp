# Sparse Table

Sparse table is the clean static-range-query structure for idempotent operations such as `min`, `max`, and `gcd`. It is one of the nicest examples of paying `O(n log n)` preprocessing to get `O(1)` query time.

## Summary

Suspect sparse table when:

- the array is static
- there are many range queries
- the merge operation is idempotent, such as `min(x, x) = x`
- you want faster queries than a segment tree on immutable data

What success looks like:

- you know why the two-block query trick works only for idempotent operations
- you can build the table and log array from memory
- you can tell when sparse table beats segment tree and when it does not

## Prerequisites

- [Prefix Sums](../../foundations/patterns/prefix-sums/README.md)

## Core Idea

Precompute answers for intervals of length `2^k`.

Let:

```text
st[k][i] = answer on interval [i, i + 2^k - 1]
```

For an idempotent operation, any query `[l, r]` can be answered by combining two overlapping blocks of equal length:

```text
k = floor(log2(r - l + 1))
answer = merge(st[k][l], st[k][r - 2^k + 1])
```

The overlap is harmless because applying an idempotent operation twice changes nothing.

## Theory / Proof Sketch

The table is built by doubling:

```text
st[k][i] = merge(st[k - 1][i], st[k - 1][i + 2^(k-1)])
```

This is valid because the length-`2^k` interval splits into two adjacent length-`2^(k-1)` intervals.

For a query:

- choose the largest power of two not exceeding the range length
- cover the query with the leftmost and rightmost blocks of that size

Why overlap is okay:

- for `min`, `max`, `gcd`, and similar idempotent operations, repeated coverage of the middle part does not change the answer

Why this fails for sums:

- overlap would count the same elements twice

## Complexity And Tradeoffs

- build: `O(n log n)`
- query: `O(1)`
- memory: `O(n log n)`

Tradeoffs:

- excellent for static RMQ-like problems
- bad for updates
- heavier preprocessing than prefix sums, but broader query power

## Canonical C++ Pattern

Template in this repo:

- [sparse-table-rmq.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/sparse-table-rmq.cpp)

Typical extra helper:

- `lg[len]` or `__lg(len)` to find the largest usable block length quickly

## Standard Patterns

### 1. Static Range Minimum / Maximum

The classic use.

### 2. Static Range GCD

Another good idempotent example.

### 3. Euler Tour + RMQ For LCA

After converting the tree to an Euler tour, LCA can be reduced to RMQ on depths. Sparse table is one clean way to answer those RMQ queries quickly.

## Worked Examples

### Example 1: static range minimum

Build once, then answer every RMQ in `O(1)`.

This is the canonical sparse-table problem.

### Example 2: static range gcd

Same table idea, different merge:

```text
merge(a, b) = gcd(a, b)
```

This works because `gcd` is associative and idempotent.

### Example 3: LCA via Euler tour + RMQ

Build an Euler tour of the tree and record depths.

Then the LCA query becomes:

- find the minimum-depth position in a static range

That is exactly RMQ.

## Recognition Cues

Strong clues:

- static array
- many queries
- query asks for min/max/gcd style aggregation
- updates do not exist

Sparse table is often confused with:

- [Segment Tree](../segment-tree/README.md), which supports updates but has slower queries
- [Prefix Sums](../../foundations/patterns/prefix-sums/README.md), which are cheaper but only for additive aggregates

## Common Mistakes

- applying the overlapping two-block trick to non-idempotent operations
- building the log table incorrectly
- forgetting that updates invalidate the whole structure
- using sparse table where a simple prefix preprocessing is enough

## Practice Ladder

- [Sparse table ladder](../../../practice/ladders/data-structures/sparse-table/README.md)

Suggested order:

1. static RMQ
2. static range gcd
3. LCA as RMQ viewpoint
4. compare sparse table with segment tree on the same static task

## Go Deeper

- Reference: [CP-Algorithms - Sparse Table](https://cp-algorithms.com/data_structures/sparse-table.html)
- Practice: [CSES Range Queries](https://cses.fi/problemset/)
- Next step: [LCA](../../graphs/lca/README.md)

## Related Topics

- [Segment Tree](../segment-tree/README.md)
- [Prefix Sums](../../foundations/patterns/prefix-sums/README.md)
- [LCA](../../graphs/lca/README.md)
