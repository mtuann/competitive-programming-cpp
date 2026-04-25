# Divide and Conquer DP

This lane is about one very specific optimization pattern:

$$
dp[g][i] = \min_{0 \le k < i} \left(prev[k] + cost(k + 1, i)\right)
$$

where:

- one row `prev` is already known
- the transition is over one split point `k`
- and the optimal split indices are monotone:

$$
opt[g][i] \le opt[g][i + 1]
$$

When that monotonicity is true, the whole row no longer needs `O(n^2)` transitions.

It becomes:

- solve the middle state
- remember its best split
- recurse left and right with narrower candidate ranges

That is the exact meaning of `divide and conquer DP` in contest discussion.

This page is not about generic divide-and-conquer as a paradigm.

It is about the narrow partition-DP optimization lane that sits next to:

- [DP Foundations](../foundations/README.md)
- [Interval DP](../interval-dp/README.md)
- [Convex Hull Trick / Li Chao Tree](../cht-li-chao/README.md)

## At A Glance

- **Use when:** one DP row has the form `cur[i] = min_k(prev[k] + cost(k+1, i))` and the argmin indices are monotone
- **Core worldview:** compute one DP row recursively, and use the midpoint winner to shrink the split-search range on both sides
- **Main tools:** one partition recurrence, `opt` monotonicity, `O(1)` or cheap interval cost, recursive row computation
- **Typical complexity:** `O(n log n)` per row after cost preprocessing
- **Main trap:** seeing a partition DP and reaching for divide-and-conquer before proving or importing the monotone-opt property

Strong contest signals:

- "partition the first `i` items into `g` groups"
- "one split point `k` decides the last segment"
- cost of the last segment is fast to query after preprocessing
- the naive DP is `O(m n^2)` and editorial hints at monotone decisions / quadrangle inequality / Monge structure

Strong anti-cues:

- the transition turns affine after expansion -> [Convex Hull Trick / Li Chao Tree](../cht-li-chao/README.md)
- the state is literally one interval `[l, r]` -> [Interval DP](../interval-dp/README.md)
- there is no proven monotonicity for the best split points
- the bottleneck is one sliding-window min/max, not one partition split

## Prerequisites

- [DP Foundations](../foundations/README.md)
- [Prefix Sums](../../foundations/patterns/prefix-sums/README.md)

Helpful neighboring topics:

- [Interval DP](../interval-dp/README.md)
- [Convex Hull Trick / Li Chao Tree](../cht-li-chao/README.md)
- [Knuth Optimization](../knuth-optimization/README.md), because it is a stronger and narrower sibling of this pattern

## Problem Model And Notation

The canonical recurrence is:

$$
dp[g][i] = \min_{0 \le k < i}\left(dp[g - 1][k] + cost(k + 1, i)\right)
$$

where:

- `g` is the number of groups / partitions already used
- `i` is the first `i` items covered
- `k` is the split before the last segment
- `cost(l, r)` is the cost of making items `l..r` one segment

We will write:

- `prev[k] = dp[g - 1][k]`
- `cur[i] = dp[g][i]`
- `opt[i]` = one minimizing split index for `cur[i]`

The optimization applies when:

$$
opt[i] \le opt[i + 1]
$$

for the current row.

That monotonicity may come from:

- a known theorem on the cost structure
- a Monge / quadrangle-inequality argument
- or a problem-specific proof

The repo's first exact starter assumes:

- `cost(l, r)` is available in `O(1)`
- indices are 1-indexed on the segment side
- the caller already knows the valid candidate range for each recursive slice

## From Brute Force To The Right Idea

### Brute Force

For one fixed row `g`, the naive computation is:

```text
for i in 1..n:
    cur[i] = min over all valid k < i
```

That is:

$$
O(n^2)
$$

per row.

With `m` rows, the whole DP becomes:

$$
O(m n^2)
$$

which is too slow once both dimensions get large.

### Structural Observation

Suppose we are computing `cur[mid]`.

If its best split is `best_k`, and the row has monotone argmins, then:

- every state left of `mid` only needs to search up to `best_k`
- every state right of `mid` only needs to search from `best_k` onward

So solving one midpoint gives information about the whole interval around it.

That is why divide-and-conquer works here.

### The Row-By-Row View

This optimization is not usually applied to the full DP table at once.

It is applied **one row at a time**:

1. compute `prev`
2. compute `cur` by a recursive helper
3. swap rows

So the real skill is not "write a recursive DP."

It is:

- keep the partition recurrence exact
- preprocess `cost`
- know why the search window shrinks recursively

## Core Invariants And Why They Work

## 1. Midpoint Contract

When we solve an interval `[L, R]` with candidate split range `[optL, optR]`, we first compute:

$$
mid = \left\lfloor \frac{L + R}{2} \right\rfloor
$$

and scan only:

$$
k \in [optL, \min(mid - 1, optR)]
$$

to find the best split for `cur[mid]`.

That best split is the only new information the recursion needs.

## 2. Monotone-Opt Shrink

If the row satisfies:

$$
opt[i] \le opt[i + 1]
$$

and `best_k = opt[mid]`, then:

- the left half `[L, mid - 1]` only needs candidate splits in `[optL, best_k]`
- the right half `[mid + 1, R]` only needs candidate splits in `[best_k, optR]`

This is the key invariant that removes one dimension from the search.

Without it, the optimization is not justified.

## 3. Cost Preprocessing Must Already Be Done

The divide-and-conquer helper is only the **search optimization**.

It does not make an expensive cost oracle disappear.

If `cost(l, r)` itself is slow, then:

- the row helper may still be too expensive
- or the real missing trick is earlier cost preprocessing

So the lane usually comes in two layers:

1. preprocess `cost(l, r)`
2. optimize the partition DP over split points

## 4. One Row Is Independent From Future Rows

The helper only reads:

- `prev`
- `cost`

and writes:

- `cur`

So one row can be reasoned about in isolation.

That is why the starter in this repo exposes a row-computation helper instead of a problem-specific full solver.

## Variant Chooser

### Use Classic Partition DP Without Optimization When

- `n` is small enough
- or only one small row count exists
- or monotone argmins have not been proved

### Use Divide and Conquer DP When

- the recurrence is one partition split over prefixes
- `cost(l, r)` is already cheap
- optimal split indices are monotone

### Use Knuth Optimization Instead When

- the state is interval/partition flavored
- and the stronger Knuth conditions hold
- because then one row can often be reduced to `O(n)` and the full table to `O(n^2)`

### Use CHT / Li Chao Instead When

- the transition becomes:

$$
m_j x_i + b_j
$$

- so previous states are really lines, not split points

## Worked Examples

### Example 1: Segment-Length Cost

Suppose:

$$
cost(l, r) = (r - l + 1)^2
$$

and `prev[k]` is already known.

Then:

$$
cur[i] = \min_{0 \le k < i}(prev[k] + (i - k)^2)
$$

This is still a partition recurrence:

- `k` means "where the last segment starts"
- the optimization question is about the best split index

The first exact starter in the repo uses this kind of row interface.

### Example 2: Ciel and Gondolas

This is the flagship rep:

- [Ciel and Gondolas](../../../practice/ladders/dp/divide-and-conquer-dp/cielandgondolas.md)

You must partition people into `k` contiguous groups.

The discomfort of one group is:

- sum of pairwise incompatibilities inside that interval

After a 2D prefix precompute, each group cost becomes `O(1)`.

So the remaining recurrence is exactly:

$$
dp[g][i] = \min_{k < i}(dp[g - 1][k] + cost(k + 1, i))
$$

and the whole optimization lives in the split-point search.

## Algorithm And Pseudocode

```text
solve_row(L, R, optL, optR):
    if L > R:
        return

    mid = (L + R) / 2
    best_value = +INF
    best_k = -1

    for k in [optL .. min(mid - 1, optR)]:
        cand = prev[k] + cost(k + 1, mid)
        if cand < best_value:
            best_value = cand
            best_k = k

    cur[mid] = best_value

    solve_row(L, mid - 1, optL, best_k)
    solve_row(mid + 1, R, best_k, optR)
```

Typical outer loop:

```text
initialize prev for one group
for g in 2..m:
    compute cur row with divide-and-conquer helper
    swap(prev, cur)
```

## Complexity And Tradeoffs

If the recursion scans `O(optR - optL + 1)` candidates per midpoint and monotonicity holds, one row costs:

$$
O(n \log n)
$$

in the standard contest implementation.

So the full DP is often:

$$
O(m n \log n)
$$

after any cost preprocessing.

Tradeoffs:

- lighter than naive `O(m n^2)`
- often heavier than Knuth when Knuth applies
- completely different from `CHT / Li Chao`, which optimizes affine transitions rather than partition splits

## Implementation Notes

- The starter is a **row helper**, not a full DP framework.
- It assumes **inclusive** segment cost `cost(l, r)` with 1-indexed segment endpoints.
- The caller must pass valid:
  - state interval `[L, R]`
  - candidate split interval `[optL, optR]`
- Always clamp the scanned split range by `mid - 1`.
- Use `long long` or wider for the transition value.
- The most important non-code task is proving monotonicity honestly.

## Practice Archetypes

- partition into `k` contiguous groups
- one last segment cost plus previous row
- matrix / prefix / pairwise interval costs after preprocessing
- "editorial says decisions are monotone"

## References And Repo Anchors

- reference: [CP-Algorithms - Divide and Conquer DP](https://cp-algorithms.com/dynamic_programming/divide-and-conquer-dp.html)
- reference: [USACO Guide - Divide & Conquer - DP](https://usaco.guide/plat/DC-DP)
- flagship problem: [Codeforces 321E - Ciel and Gondolas](https://codeforces.com/problemset/problem/321/E)

Repo anchors:

- starter: [divide-and-conquer-dp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/divide-and-conquer-dp.cpp)
- hot sheet: [Divide and Conquer DP hot sheet](../../../notebook/divide-and-conquer-dp-hot-sheet.md)
- flagship note: [Ciel and Gondolas](../../../practice/ladders/dp/divide-and-conquer-dp/cielandgondolas.md)
- compare point: [Convex Hull Trick / Li Chao Tree](../cht-li-chao/README.md)
- compare point: [Interval DP](../interval-dp/README.md)

## Related Topics

- [DP Foundations](../foundations/README.md)
- [Interval DP](../interval-dp/README.md)
- [Convex Hull Trick / Li Chao Tree](../cht-li-chao/README.md)
