# Static Range Minimum Queries

- Title: `Static Range Minimum Queries`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1647](https://cses.fi/problemset/task/1647)
- Main topic: `Data Structures -> Sparse Table`
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

## Key Idea

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

## Solutions

- Code: [staticrangeminimumqueries.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/sparse-table/staticrangeminimumqueries.cpp)
