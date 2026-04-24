# Static Range Sum Queries

- Title: `Static Range Sum Queries`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1646](https://cses.fi/problemset/task/1646)
- Secondary topics: `1D prefix sum`, `Range subtraction`, `Immutable array`
- Difficulty: `easy`
- Subtype: `Answer many range-sum queries on an array that never changes`
- Status: `solved`
- Solution file: [staticrangesumqueries.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/prefix-sums/staticrangesumqueries.cpp)

## Why Practice This

This is the cleanest first prefix-sum problem in CSES.

The problem statement gives exactly the pattern we want to recognize early:

- many range-sum queries
- no updates
- each answer should come from one precomputation

If this problem does not feel automatic yet, prefix-sum indexing discipline probably still needs a bit more repetition.

## Key Idea

Build a prefix array where:

```text
pref[i] = sum of the first i elements
pref[0] = 0
```

Then for a query `[l, r]` in one-based indexing:

```text
sum(l..r) = pref[r] - pref[l - 1]
```

Why does that work?

Because `pref[r]` contains everything up to `r`, while `pref[l - 1]` contains exactly the part before the query range. Subtracting removes the left prefix and leaves only the sum on `[l, r]`.

This is the core prefix-sum pattern:

- preprocess once in `O(n)`
- answer every static range query in `O(1)`

## Complexity

- prefix build: `O(n)`
- each query: `O(1)`
- memory: `O(n)`

## Pitfalls / Judge Notes

- Use `long long` because sums can exceed `int`.
- The safest convention is `pref[0] = 0` and `pref[i] = sum of first i elements`.
- Queries are one-based and inclusive, so `pref[r] - pref[l - 1]` works directly.
- This is static data. If updates appeared, prefix sums would no longer be enough on their own.

## Reusable Pattern

- Topic page: [Prefix Sums](../../../../topics/foundations/patterns/prefix-sums/README.md)
- Practice ladder: [Prefix Sums ladder](README.md)
- Starter template: [prefix-sum-1d.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/prefix-sum-1d.cpp)
- Notebook refresher: [Foundations cheatsheet](../../../../notebook/foundations-cheatsheet.md)
- Carry forward: default to `pref[r] - pref[l - 1]` for static 1D range sums once the indexing is fixed.
- This note adds: the exact preprocessing and query convention used by this problem.

## Solutions

- Code: [staticrangesumqueries.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/foundations/prefix-sums/staticrangesumqueries.cpp)
