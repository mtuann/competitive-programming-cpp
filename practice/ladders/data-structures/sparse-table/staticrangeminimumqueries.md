# Static Range Minimum Queries

- Title: `Static Range Minimum Queries`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1647](https://cses.fi/problemset/task/1647)
- Secondary topics: `Idempotent queries`, `Overlapping blocks`, `Log-table preprocessing`
- Difficulty: `easy`
- Subtype: `Answer many minimum queries on an immutable array`
- Status: `solved`
- Solution file: [staticrangeminimumqueries.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/sparse-table/staticrangeminimumqueries.cpp)

## Why Practice This

This is the canonical sparse-table problem. Nothing is hidden behind the statement:

- the array never changes
- there are many range-minimum queries
- `min` is idempotent

That makes it the cleanest place to learn why sparse table is lighter than a segment tree on static data.

## Recognition Cue

Reach for sparse table when:

- the array is immutable
- there are many range queries
- the operation is idempotent, such as `min`, `max`, or `gcd`
- you want `O(1)` query time after `O(n log n)` preprocessing

The strongest anti-cues are:

- updates
- non-idempotent operations like sum

Those push you away from this exact tool.

## Problem-Specific Transformation

The statement is really asking one repeated primitive:

- `RMQ(l, r)` on static data

So the reusable rewrite is:

- precompute answers on power-of-two intervals
- answer each query by stitching together two largest equal-size blocks

That reduces a seemingly arbitrary interval query to one fixed table lookup pattern.

## Core Idea

Precompute answers for all intervals whose length is a power of two:

```text
st[k][i] = minimum on [i, i + 2^k - 1]
```

The doubling recurrence is:

```text
st[k][i] = min(st[k - 1][i], st[k - 1][i + 2^(k - 1)])
```

For one query `[l, r]`, let:

```text
len = r - l + 1
k = floor(log2(len))
```

Then answer with two blocks of equal size:

```text
min(st[k][l], st[k][r - 2^k + 1])
```

Why can the two blocks overlap?

Because `min` is idempotent:

```text
min(x, x) = x
```

So covering the middle part twice does not change the answer. That is exactly why sparse table gives `O(1)` query time for RMQ but not for something like range sum.

## Complexity

- build log table: `O(n)`
- build sparse table: `O(n log n)`
- each query: `O(1)`
- memory: `O(n log n)`

## Pitfalls / Judge Notes

- Convert the input queries from `1`-based to `0`-based before indexing the table.
- The overlapping two-block query trick works for `min`, `max`, and `gcd`, but not for non-idempotent operations like `sum`.
- Precompute the log table carefully so `lg[len]` is valid for every query length.
- This is a static-query problem. If updates existed, sparse table would be the wrong tool.

## Reusable Pattern

- Topic page: [Sparse Table](../../../../topics/data-structures/sparse-table/README.md)
- Practice ladder: [Sparse Table ladder](README.md)
- Starter template: [sparse-table-rmq.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/sparse-table-rmq.cpp)
- Notebook refresher: [Data structures cheatsheet](../../../../notebook/data-structures-cheatsheet.md)
- Carry forward: reach for sparse table only when the operation is static and idempotent.
- This note adds: the exact query interpretation and preprocessing choices for this range primitive.

## Solutions

- Code: [staticrangeminimumqueries.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/sparse-table/staticrangeminimumqueries.cpp)
