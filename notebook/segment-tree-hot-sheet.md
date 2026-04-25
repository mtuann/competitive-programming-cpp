# Segment Tree Hot Sheet

Use this page when a mutable array needs an associative range aggregate and you already trust the segment-tree idea.

## Do Not Use When

- the query is prefix-only, so a Fenwick tree is lighter
- the data is static and the query is idempotent, so a sparse table is enough
- one prefix array or one offline sweep already kills the whole problem

## Choose By Signal

- point assignment or point add plus range sum/min/max -> segment tree
- tree path aggregate plus updates -> HLD plus segment tree, not a plain array tree
- first position whose prefix/segment aggregate crosses a threshold and the node summary supports left-first monotone descent -> segment-tree walking
- true online range updates -> [Lazy Segment Tree hot sheet](lazy-segment-tree-hot-sheet.md); the repo's main point-update starter is **not** the right drop-in
- online `range chmin / chmax` plus sum -> [Segment Tree Beats hot sheet](segment-tree-beats-hot-sheet.md); one plain monoid tree is no longer enough

## Core Invariants

- every node stores one summary for one contiguous segment
- every query answer is the merge of disjoint canonical segments that exactly cover the target range
- the repo starter [`segment-tree-iterative.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/segment-tree-iterative.cpp) is a `long long` sum tree with point assignment and half-open query `[l, r)`

## Main Traps

- mixing inclusive statement ranges with a half-open helper
- copying the sum starter into a min/max/subarray/non-commutative problem without changing `merge`, `identity`, and query logic
- reaching for the iterative sum tree when the problem really needs lazy propagation
- forgetting that path queries on trees need decomposition first

## Exact Starters In This Repo

- array range sums with point updates -> [`segment-tree-iterative.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/segment-tree-iterative.cpp)
- array range add + range sum -> [`segment-tree-lazy-range-add-sum.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/segment-tree-lazy-range-add-sum.cpp)
- range `chmin / chmax / add / sum` -> [`segment-tree-beats.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/segment-tree-beats.cpp)
- static tree path maximum with point updates -> [`hld-path-max.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hld-path-max.cpp)
- baseline note -> [Dynamic Range Sum Queries](../practice/ladders/data-structures/segment-tree/dynamicrangesumqueries.md)

## Reopen Paths

- proof, variants, lazy, and descent queries -> [Segment Tree](../topics/data-structures/segment-tree/README.md)
- exact lazy route -> [Lazy Segment Tree hot sheet](lazy-segment-tree-hot-sheet.md)
- stronger clamp-update route -> [Segment Tree Beats hot sheet](segment-tree-beats-hot-sheet.md)
- lighter neighboring structures -> [Data structures cheatsheet](data-structures-cheatsheet.md)
- pasteable snippet route -> [Template Library](../template-library.md)
