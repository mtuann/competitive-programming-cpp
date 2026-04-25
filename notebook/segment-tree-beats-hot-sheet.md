# Segment Tree Beats Hot Sheet

Use this page when a mutable array needs online `range chmin / chmax / add / sum`, and an ordinary lazy tag family is no longer expressive enough.

## Do Not Use When

- the updates are only `range add` / `range assign`, so [Lazy Segment Tree hot sheet](lazy-segment-tree-hot-sheet.md) already fits
- the task is static
- the statement is really one narrow beats-like pruning route such as `range modulo + sum`, not the canonical `chmin/chmax/add/sum` family
- the structure lives on a tree and you have not done Euler flattening or HLD yet

## Choose By Signal

- point updates with merge-only queries -> [Segment Tree hot sheet](segment-tree-hot-sheet.md)
- range add / assign with one honest lazy-tag algebra -> [Lazy Segment Tree hot sheet](lazy-segment-tree-hot-sheet.md)
- range cap / floor updates where only current maxima or minima might change -> Segment Tree Beats
- modulo-only pruning by current maximum -> reopen the full topic; the repo starter here is too broad, not too narrow

## Core Invariants

- each node stores `sum`, top two maxima with count of the top maximum, and bottom two minima with count of the bottom minimum
- `range_chmin(x)` can stop in `O(1)` at a covered node only when `max2 < x < max1`
- `range_chmax(x)` can stop in `O(1)` at a covered node only when `min1 < x < min2`
- `range_add(delta)` still behaves like an ordinary lazy tag because every value in the segment shifts together

## Main Traps

- forgetting that `max2` / `min2` are **strict** second extrema
- using the `O(1)` node clamp when the second-extremum condition does not hold
- assuming this starter also covers modulo, historic, or GCD-enhanced beats variants
- treating the structure like a free upgrade over lazy segment tree; constants and bug surface are much worse

## Exact Starter In This Repo

- exact starter -> [segment-tree-beats.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/segment-tree-beats.cpp)
- flagship verifier-style rep -> [Range Chmin Chmax Add Range Sum](../practice/ladders/data-structures/segment-tree-beats/rangechminchmaxaddrangesum.md)
- compare simpler route -> [HORRIBLE](../practice/ladders/data-structures/lazy-segment-tree/horriblequeries.md)
- compare beats-like custom pruning -> [The Child and Sequence](https://codeforces.com/problemset/problem/438/D)

## Reopen Paths

- full invariant and amortization intuition -> [Segment Tree Beats](../topics/data-structures/segment-tree-beats/README.md)
- simpler online range updates -> [Lazy Segment Tree hot sheet](lazy-segment-tree-hot-sheet.md)
- parent chooser -> [Data structures cheatsheet](data-structures-cheatsheet.md)
- snippet chooser -> [Template Library](../template-library.md)
