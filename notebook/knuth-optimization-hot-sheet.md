# Knuth Optimization Hot Sheet

Use this when the recurrence is:

$$
dp[l][r] = \min_{l \le k < r}\left(dp[l][k] + dp[k + 1][r] + cost(l, r)\right)
$$

and you already know:

$$
opt[l][r - 1] \le opt[l][r] \le opt[l + 1][r].
$$

## Use When

- the state is one contiguous interval `[l, r]`
- the transition is split-point interval DP
- the added cost is `cost(l, r)`, independent of `k`
- the baseline is `O(n^3)` and Knuth monotonicity is valid

## Do Not Use When

- the state is one partition row over prefixes -> [Divide and Conquer DP](../topics/dp/divide-and-conquer-dp/README.md)
- the transition becomes affine -> [CHT / Li Chao](../topics/dp/cht-li-chao/README.md)
- the extra cost still depends on the split point
- you have no monotonicity proof and `O(n^3)` already fits

## Core Window

For interval `[l, r]`, only search:

```text
k in [opt[l][r - 1], opt[l + 1][r]]
```

with `opt[i][i] = i`.

## Checklist

1. Is the DP truly interval-shaped?
2. Is the transition `dp[l][k] + dp[k+1][r] + cost(l, r)`?
3. Is `cost(l, r)` cheap after preprocessing?
4. Do you have `opt` monotonicity from theorem/editorial/problem structure?
5. Are all intervals using the same inclusive convention?

## Main Traps

- using Knuth where plain [Interval DP](../topics/dp/interval-dp/README.md) was the real lane
- using it on partition DP rows that belong to [Divide and Conquer DP](../topics/dp/divide-and-conquer-dp/README.md)
- forgetting consistent tie handling for `opt`

## Exact Route

- topic: [Knuth Optimization](../topics/dp/knuth-optimization/README.md)
- starter: [knuth-optimization.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/knuth-optimization.cpp)
- flagship: [Knuth Division](../practice/ladders/dp/knuth-optimization/knuthdivision.md)
- compare points: [Interval DP](../topics/dp/interval-dp/README.md), [Divide and Conquer DP](../topics/dp/divide-and-conquer-dp/README.md)
