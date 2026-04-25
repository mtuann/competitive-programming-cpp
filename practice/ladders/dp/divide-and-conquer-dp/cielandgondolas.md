# Ciel and Gondolas

- Title: `Ciel and Gondolas`
- Judge / source: `Codeforces`
- Original URL: [https://codeforces.com/problemset/problem/321/E](https://codeforces.com/problemset/problem/321/E)
- Secondary topics: `Partition DP`, `2D prefix sums`, `Monotone-opt`
- Difficulty: `very hard`
- Subtype: `Contiguous group partitioning with divide-and-conquer DP`
- Status: `solved`
- Solution file: [cielandgondolas.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/divide-and-conquer-dp/cielandgondolas.cpp)

## Why Practice This

This is the cleanest in-repo anchor for the first exact `divide-and-conquer DP` lane.

The problem gives you:

- `n` people in a fixed order
- `k` contiguous gondolas
- one symmetric discomfort matrix

So the real lesson is not some abstract optimization theorem.

It is:

- derive the partition recurrence
- preprocess interval discomfort into `cost(l, r)`
- then optimize the split-point search for each DP row

## Recognition Cue

Reach for divide-and-conquer DP when:

- `dp[g][i]` ends with one last segment `k + 1 .. i`
- the naive transition is a full scan over all `k < i`
- cost of one interval can be made cheap first
- the optimization is about monotone best split points, not affine lines

The strongest smell here is:

- "partition prefixes into contiguous groups" with one quadratic row transition

## Problem-Specific Transformation

Let:

$$
dp[g][i]
$$

be the minimum discomfort for the first `i` people split into `g` contiguous gondolas.

Then:

$$
dp[g][i] = \min_{0 \le k < i}\left(dp[g - 1][k] + cost(k + 1, i)\right)
$$

where `cost(l, r)` is the total pairwise discomfort inside one group `l..r`.

Using a 2D prefix sum over the matrix, that interval cost becomes `O(1)`.

So the whole remaining bottleneck is the split search.

That is the exact divide-and-conquer DP route.

## Core Idea

For one fixed row `g`, compute:

$$
cur[i] = \min_{k < i}(prev[k] + cost(k + 1, i))
$$

If the best split indices are monotone, then after solving the midpoint `mid`:

- the left half only needs split candidates up to `best_k`
- the right half only needs split candidates from `best_k`

So one row is computed by recursively solving intervals of states while shrinking the split-search range.

The matrix prefix sum is only the cost-precompute layer.

The actual optimization layer is:

- recursive row computation over monotone argmins

## Implementation Notes

The repo solution uses:

- a 2D prefix sum of the input matrix
- inclusive interval cost:

$$
cost(l, r) = \frac{sum(l..r, l..r)}{2}
$$

because the matrix is symmetric and pair discomfort is otherwise counted twice
- one divide-and-conquer helper per DP row

The exact helper contract is:

- `prev[k]` is already valid
- `cost(l, r)` is `O(1)`
- solve `cur[i]` for a state interval `[L, R]`
- search only candidate splits in `[optL, optR]`

## Complexity

- matrix prefix preprocessing: `O(n^2)`
- each DP row with divide-and-conquer optimization: `O(n log n)`
- total: `O(n^2 + k n log n)`

That is the intended route for the Codeforces limits.

## Pitfalls / Judge Notes

- The matrix is symmetric, so raw submatrix sums double-count each pair.
- Use 1-indexed interval endpoints carefully in `cost(l, r)`.
- For row `g`, states `i < g` are invalid because each group must be nonempty.
- The optimization is only correct if the monotone-opt property really holds for this recurrence.

## Reusable Pattern

- Topic page: [Divide and Conquer DP](../../../../topics/dp/divide-and-conquer-dp/README.md)
- Practice ladder: [Divide and Conquer DP ladder](README.md)
- Starter template: [divide-and-conquer-dp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/divide-and-conquer-dp.cpp)
- Notebook refresher: [Divide and Conquer DP hot sheet](../../../../notebook/divide-and-conquer-dp-hot-sheet.md)
- Compare points: [Interval DP](../../../../topics/dp/interval-dp/README.md), [Convex Hull Trick / Li Chao Tree](../../../../topics/dp/cht-li-chao/README.md)
- This note adds: the exact route where interval-cost preprocessing and monotone split decisions combine into one optimized partition DP.

## Solutions

- Code: [cielandgondolas.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/divide-and-conquer-dp/cielandgondolas.cpp)
