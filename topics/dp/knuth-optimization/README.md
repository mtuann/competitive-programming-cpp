# Knuth Optimization

Knuth optimization is the narrow interval-DP speedup for recurrences of the form:

$$
dp[l][r] = \min_{l \le k < r}\left(dp[l][k] + dp[k + 1][r] + cost(l, r)\right).
$$

The split point `k` is still the real choice.

The key difference from plain interval DP is that we do **not** scan every split point for every interval.

Instead, we use the monotonicity window:

$$
opt[l][r - 1] \le opt[l][r] \le opt[l + 1][r].
$$

That turns the classic `O(n^3)` merge-style interval DP into `O(n^2)`.

This page is not about generic interval DP.

It is about the exact stronger sibling that sits between:

- [Interval DP](../interval-dp/README.md)
- [Divide and Conquer DP](../divide-and-conquer-dp/README.md)

## At A Glance

- **Use when:** the state is one contiguous interval `[l, r]`, the transition is split-point based, and the added segment cost `cost(l, r)` is independent of the chosen split `k`
- **Core worldview:** keep the same interval recurrence, but search `k` only inside the already-proved optimal window
- **Main tools:** `dp[l][r]`, `opt[l][r]`, prefix sums or other `O(1)` interval-cost preprocessing, len-order iteration
- **Typical complexity:** `O(n^2)` after cost preprocessing
- **Main trap:** trying to use Knuth on a partition-row DP or on a transition where the extra cost still depends on `k`

Strong contest signals:

- "merge adjacent segments / files / slimes"
- "split one interval into two solved intervals"
- the naive recurrence is textbook `O(n^3)`
- editorials mention `quadrangle inequality`, `opt monotonicity`, or `Knuth-Yao`

Strong anti-cues:

- the state is `dp[g][i]` over prefixes -> [Divide and Conquer DP](../divide-and-conquer-dp/README.md)
- the transition becomes affine -> [Convex Hull Trick / Li Chao Tree](../cht-li-chao/README.md)
- the added cost depends on the split point itself
- constraints already allow ordinary `O(n^3)` interval DP and there is no monotonicity proof to import

## Prerequisites

- [DP Foundations](../foundations/README.md)
- [Interval DP](../interval-dp/README.md)
- [Prefix Sums](../../foundations/patterns/prefix-sums/README.md)

Helpful neighboring topics:

- [Divide and Conquer DP](../divide-and-conquer-dp/README.md)
- [Convex Hull Trick / Li Chao Tree](../cht-li-chao/README.md)

## Problem Model And Notation

The canonical recurrence is:

$$
dp[l][r] = \min_{l \le k < r}\left(dp[l][k] + dp[k + 1][r] + cost(l, r)\right).
$$

We write:

- `dp[l][r]` = best answer for interval `[l, r]`
- `opt[l][r]` = one split point `k` that attains the minimum

The optimization applies when:

$$
opt[l][r - 1] \le opt[l][r] \le opt[l + 1][r].
$$

CP-Algorithms gives a common sufficient condition: for `a <= b <= c <= d`,

$$
cost(b, c) \le cost(a, d)
$$

and

$$
cost(a, c) + cost(b, d) \le cost(a, d) + cost(b, c).
$$

You do not need to reprove these every contest if the problem is a standard lane and the source/editorial already establishes them.

But you do need to know **which recurrence family** the theorem belongs to.

## From O(n^3) To O(n^2)

### Baseline Interval DP

Without any optimization:

```text
for len = 2..n:
    for every interval [l, r] of that length:
        scan all split points k in [l, r-1]
```

That costs `O(n^3)`.

### What Knuth Actually Shrinks

Suppose we are computing `dp[l][r]`.

If `opt[l][r - 1]` and `opt[l + 1][r]` are already known, then we only search:

$$
k \in [opt[l][r - 1],\, opt[l + 1][r]].
$$

This is why the loop order matters:

- smaller intervals first
- so `opt[l][r - 1]` and `opt[l + 1][r]` already exist

### Why This Is Not Divide and Conquer DP

Knuth and divide-and-conquer DP both use monotone optimal split points, but the state shape is different:

- **Knuth:** one interval state `dp[l][r]`
- **Divide and Conquer DP:** one row over prefix states `cur[i]`

Knuth is the stronger and narrower lane.

If the recurrence is truly interval-shaped and Knuth conditions hold, use Knuth.

## Core Invariants

## 1. The Extra Cost Must Ignore `k`

The recurrence must look like:

$$
dp[l][k] + dp[k + 1][r] + cost(l, r),
$$

not:

$$
dp[l][k] + dp[k + 1][r] + cost(l, k, r).
$$

If the extra term still changes with `k`, this exact optimization does not apply.

## 2. `opt` Window Bounds Must Already Be Valid

When we compute `dp[l][r]`, we search:

```text
start = opt[l][r-1]
end   = opt[l+1][r]
```

and clamp `end` to at most `r - 1`.

If those bounds are not valid for your recurrence, the code may still compile and silently return nonsense.

## 3. Tie Handling Must Be Consistent

The standard implementation often stores the **rightmost** minimizing split by updating on `<=` instead of `<`.

That keeps `opt` conventions aligned with common statements of the theorem and with the CP-Algorithms generic implementation.

## Worked Example: Knuth Division

In [Knuth Division](../../../practice/ladders/dp/knuth-optimization/knuthdivision.md), the interval meaning is:

$$
dp[l][r] = \text{minimum cost to fully split subarray } [l, r].
$$

If we first split at `k`, then:

- left side becomes `[l, k]`
- right side becomes `[k + 1, r]`
- and we pay the whole interval sum once:

$$
sum(l, r).
$$

So the recurrence is:

$$
dp[l][r] = \min_{l \le k < r}\left(dp[l][k] + dp[k+1][r] + sum(l, r)\right).
$$

This is the exact first route for Knuth:

- interval DP baseline
- `sum(l, r)` from prefix sums
- `opt` window monotonicity

## Pseudocode Skeleton

```text
for i in 0..n-1:
    dp[i][i] = 0
    opt[i][i] = i

for len in 2..n:
    for l in 0..n-len:
        r = l + len - 1
        dp[l][r] = INF
        start = opt[l][r - 1]
        end = min(r - 1, opt[l + 1][r])
        for k in start..end:
            cand = dp[l][k] + dp[k + 1][r] + cost(l, r)
            if cand <= dp[l][r]:
                dp[l][r] = cand
                opt[l][r] = k
```

## Variant Chooser

### Use Plain Interval DP When

- the recurrence is interval-shaped
- but constraints still allow `O(n^3)`
- or you do not have a safe monotonicity proof

### Use Knuth Optimization When

- the recurrence is split-point interval DP
- the added cost is `cost(l, r)` only
- and the `opt` window monotonicity is known or imported

### Use Divide and Conquer DP When

- the state is one partition row like `dp[g][i]`
- not one interval `[l, r]`

### Use CHT / Li Chao When

- previous states become lines
- and the transition is really affine

## Implementation Notes

- precompute interval cost first; Knuth only shrinks the split search
- initialize `opt[i][i] = i`
- for each interval, search from `opt[l][r-1]` to `opt[l+1][r]`
- use `long long`
- keep the interval convention consistent everywhere: inclusive `[l, r]`

## Common Failure Modes

- using Knuth on a partition DP row that should be [Divide and Conquer DP](../divide-and-conquer-dp/README.md)
- forgetting that `cost(l, r)` must not depend on `k`
- mixing `0`-indexed DP with `1`-indexed prefix sums incorrectly
- using the optimization because the problem "looks like merging", without any monotonicity evidence

## Sources

- reference: [CP-Algorithms - Knuth's Optimization](https://cp-algorithms.com/dynamic_programming/knuth-optimization.html)
- practice statement: [CSES - Knuth Division](https://cses.fi/problemset/task/2088/)
- compare point: [AtCoder DP N - Slimes](https://atcoder.jp/contests/dp/tasks/dp_n?lang=en)

## Repo Routes

- starter: [knuth-optimization.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/knuth-optimization.cpp)
- hot sheet: [Knuth Optimization hot sheet](../../../notebook/knuth-optimization-hot-sheet.md)
- flagship note: [Knuth Division](../../../practice/ladders/dp/knuth-optimization/knuthdivision.md)
- compare point: [Interval DP](../interval-dp/README.md)
- compare point: [Divide and Conquer DP](../divide-and-conquer-dp/README.md)
