# Knuth Division

- Title: `Knuth Division`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/2088/](https://cses.fi/problemset/task/2088/)
- Secondary topics: `Interval DP`, `Prefix sums`, `Opt monotonicity`
- Difficulty: `hard`
- Subtype: `Split-point interval DP with additive interval cost and Knuth opt window`
- Status: `solved`
- Solution file: [knuthdivision.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/knuth-optimization/knuthdivision.cpp)

## Why This Note Matters

This is the cleanest in-repo first anchor for the exact Knuth lane.

The recurrence is the standard merge-style interval DP:

$$
dp[l][r] = \min_{l \le k < r}(dp[l][k] + dp[k+1][r] + sum(l, r)).
$$

Nothing here is disguised.

That makes it the right flagship for:

- seeing the plain interval recurrence first
- then shrinking the split search with Knuth windows

## Recognition Cue

Reach for Knuth optimization when:

- the state is a contiguous interval `[l, r]`
- choosing one split `k` produces two smaller solved intervals
- the extra price is the total interval sum, independent of `k`
- the intended optimization is stronger than generic [Interval DP](../../../../topics/dp/interval-dp/README.md), but not a prefix-row optimization like [Divide and Conquer DP](../../../../topics/dp/divide-and-conquer-dp/README.md)

## Problem-Specific Transformation

Let:

$$
dp[l][r] = \text{minimum cost to fully split subarray } [l, r] \text{ into singletons}.
$$

If the first split happens between `k` and `k + 1`, then:

- left subarray `[l, k]` is solved optimally
- right subarray `[k + 1, r]` is solved optimally
- we pay the current segment sum once

So:

$$
dp[l][r] = \min_{l \le k < r}\left(dp[l][k] + dp[k+1][r] + sum(l, r)\right).
$$

This is exactly the Knuth form because the added term `sum(l, r)` does not depend on `k`.

## Precomputation

Use prefix sums:

$$
sum(l, r) = pref[r + 1] - pref[l].
$$

Then every candidate split costs:

```text
left answer + right answer + one O(1) interval sum
```

## Exact Knuth Route

Keep:

- `dp[l][r]`
- `opt[l][r]`

Base:

- `dp[i][i] = 0`
- `opt[i][i] = i`

Transition window:

```text
start = opt[l][r - 1]
end   = opt[l + 1][r]
```

and only test `k` inside that range.

## Why The Optimization Fits

This note is not about proving the full theorem from scratch.

It is about recognizing the exact standard lane:

- merge-cost interval DP
- additive interval sum
- monotone split windows imported from the Knuth optimization family

That is enough to route safely to the exact starter.

## Implementation Plan

1. read `n` and the array
2. build prefix sums
3. initialize `dp[i][i] = 0`, `opt[i][i] = i`
4. iterate interval length from `2` to `n`
5. for each interval `[l, r]`, scan only `k in [opt[l][r-1], opt[l+1][r]]`
6. output `dp[0][n-1]`

## Complexity

- prefix sums: `O(n)`
- DP states: `O(n^2)`
- total transition work with Knuth windows: `O(n^2)`

## Main Traps

- mixing inclusive `[l, r]` intervals with prefix sums incorrectly
- forgetting `opt[i][i] = i`
- using this route when the extra cost still depends on `k`
- confusing it with [Divide and Conquer DP](../../../../topics/dp/divide-and-conquer-dp/README.md), which is a different state shape

## Reopen Path

- Topic page: [Knuth Optimization](../../../../topics/dp/knuth-optimization/README.md)
- Practice ladder: [Knuth Optimization ladder](README.md)
- Starter template: [knuth-optimization.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/knuth-optimization.cpp)
- Notebook refresher: [Knuth Optimization hot sheet](../../../../notebook/knuth-optimization-hot-sheet.md)
- Compare points: [Interval DP](../../../../topics/dp/interval-dp/README.md), [Divide and Conquer DP](../../../../topics/dp/divide-and-conquer-dp/README.md)

## Solution

- Code: [knuthdivision.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/knuth-optimization/knuthdivision.cpp)
