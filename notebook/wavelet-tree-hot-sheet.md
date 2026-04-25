# Wavelet Tree Hot Sheet

Use this page when one **static** array gets many subarray queries whose answer depends on value order inside the range:

- k-th smallest
- count `<= x`
- count `== x`

## Do Not Use When

- updates happen between queries
- the task is just static RMQ / min / gcd, so [Sparse Table hot sheet](sparse-table-hot-sheet.md) already fits
- the real invariant is one active interval maintained by endpoint add/remove, so [Mo's hot sheet](mos-hot-sheet.md) is the better lens
- the task is about versions / snapshots, so [Persistent Data Structures hot sheet](persistent-data-structures-hot-sheet.md) is the right compare point

## Choose By Signal

- static RMQ / idempotent aggregate -> [Sparse Table hot sheet](sparse-table-hot-sheet.md)
- one active window with cheap add/remove -> [Mo's hot sheet](mos-hot-sheet.md)
- old versions or prefix roots are the natural story -> [Persistent Data Structures hot sheet](persistent-data-structures-hot-sheet.md)
- static subarray k-th / value counting by rank -> Wavelet Tree

## Core Invariants

- each node owns one compressed value interval `[lo, hi]`
- each node stores the subsequence of array elements whose values lie in that interval, **with original order preserved**
- `pref[i]` means: among the first `i` subsequence elements at this node, how many go to the left child
- for a node-local query interval `[l, r)`, the child ranges become:
  - left -> `[pref[l], pref[r))`
  - right -> `[l - pref[l], r - pref[r))`

## Main Query Rules

- `kth_smallest`: compute how many queried elements go left; go left if `k < left_count`, otherwise go right with `k -= left_count`
- `count_leq(x)`: prune whole value intervals that are fully above or fully below `x`
- `count_equal(x)`: follow only the unique leaf path for `x`

## Main Traps

- mixing original-array positions with node-local subsequence positions after the first descent
- forgetting to convert statement `k` from one-based to zero-based
- skipping coordinate compression when values are large
- stretching the starter to dynamic updates or wavelet-matrix-only variants

## Exact Starter In This Repo

- exact starter -> [wavelet-tree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/wavelet-tree.cpp)
- flagship static k-th rep -> [MKTHNUM - K-th Number](../practice/ladders/data-structures/wavelet-tree/mkthnum.md)
- best compare point -> [Persistent Data Structures](../topics/data-structures/persistent-data-structures/README.md)
- lighter static route when value order does not matter -> [Sparse Table hot sheet](sparse-table-hot-sheet.md)

## Reopen Paths

- full tutorial -> [Wavelet Tree](../topics/data-structures/wavelet-tree/README.md)
- compare against versions / prefix roots -> [Persistent Data Structures hot sheet](persistent-data-structures-hot-sheet.md)
- compare against current-window offline maintenance -> [Mo's hot sheet](mos-hot-sheet.md)
- parent chooser -> [Data structures cheatsheet](data-structures-cheatsheet.md)
- snippet chooser -> [Template Library](../template-library.md)
