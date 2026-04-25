# Divide and Conquer DP Hot Sheet

Use this page when one partition-DP row has the form:

$$
cur[i] = \min_{k < i}(prev[k] + cost(k + 1, i))
$$

and the best split indices are monotone.

## Do Not Use When

- the transition becomes affine in one query point -> [CHT / Li Chao hot sheet](cht-hot-sheet.md)
- the state is literally one interval `[l, r]` -> [Interval DP](../topics/dp/interval-dp/README.md)
- there is no proof or imported fact that `opt[i] <= opt[i + 1]`
- the real bottleneck is one deque / sliding-window min rather than one partition split

## Choose By Signal

- partition prefix into groups, last segment is `cost(k + 1, i)` -> divide-and-conquer DP
- same partition flavor, but stronger Knuth conditions hold -> [Knuth Optimization hot sheet](knuth-optimization-hot-sheet.md)
- affine `m_j x_i + b_j` transitions -> [CHT / Li Chao hot sheet](cht-hot-sheet.md)
- interval split inside `[l, r]` states -> [Interval DP](../topics/dp/interval-dp/README.md)

## Core Invariants

- one row is computed from `prev`, not from the whole DP table at once
- `opt[i] <= opt[i + 1]` is the enabling invariant
- solving `mid` gives one `best_k`
- left recursion only needs candidate splits up to `best_k`
- right recursion only needs candidate splits from `best_k` onward
- the helper only optimizes split search; `cost(l, r)` still must already be cheap

## Main Traps

- using the optimization without proving monotone argmins
- mixing `cost(k, i)` and `cost(k + 1, i)` conventions
- forgetting that `k < i`, so the scan upper bound is `mid - 1`
- overclaiming the starter as a full problem solver instead of one row helper

## Exact Starter Route

- exact starter -> [divide-and-conquer-dp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/divide-and-conquer-dp.cpp)
- flagship rep -> [Ciel and Gondolas](../practice/ladders/dp/divide-and-conquer-dp/cielandgondolas.md)
- compare point -> [CHT / Li Chao hot sheet](cht-hot-sheet.md)
- compare point -> [DP cheatsheet](dp-cheatsheet.md)

## Reopen Paths

- full lesson -> [Divide and Conquer DP](../topics/dp/divide-and-conquer-dp/README.md)
- affine optimization instead -> [Convex Hull Trick / Li Chao Tree](../topics/dp/cht-li-chao/README.md)
- interval-state DP instead -> [Interval DP](../topics/dp/interval-dp/README.md)
- snippet chooser -> [Template Library](../template-library.md)
- retrieval router -> [Build Kit](../docs/build-kit.md)
