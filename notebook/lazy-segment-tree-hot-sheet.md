# Lazy Segment Tree Hot Sheet

Use this page when the problem has true online range updates and interval queries, and a whole covered segment can absorb the update in closed form.

## Do Not Use When

- all updates happen first and one final reconstruction is enough
- range add is paired only with point query, so a lighter difference-array / Fenwick route already fits
- the statement mixes `range assign` with `range add`, but you only have an additive-tag skeleton in mind
- the structure is really a tree, and you have not flattened or decomposed it yet

## Choose By Signal

- range add + range sum online -> lazy segment tree -> [`segment-tree-lazy-range-add-sum.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/segment-tree-lazy-range-add-sum.cpp)
- point updates + range queries only -> ordinary [Segment Tree hot sheet](segment-tree-hot-sheet.md)
- many offline range adds, then read final values -> [Difference Arrays](../topics/foundations/patterns/difference-arrays/README.md)
- range add + point query only -> difference-array or Fenwick route before reaching for lazy
- range assign or add+assign -> reopen the full topic first; the starter here is too narrow
- range `chmin / chmax` style clamps matter -> [Segment Tree Beats hot sheet](segment-tree-beats-hot-sheet.md), not one additive-tag lazy tree

## Core Invariants

- `sum[v]` is already the true answer for the whole segment of node `v`
- `lazy[v]` means every element in that segment still owes one deferred additive update before the children become individually up to date
- full-cover update -> repair the node immediately and store the debt in `lazy[v]`
- partial overlap -> `push`, recurse, then `pull`

## Main Traps

- thinking “lazy” means the node itself is allowed to be wrong
- forgetting to multiply `delta` by segment length when repairing the segment sum
- pushing too early everywhere or not pushing before partial descent
- reusing a range-add starter on a problem that also has range assign
- mixing inclusive statement intervals with a half-open internal helper

## Exact Starters In This Repo

- exact starter -> [`segment-tree-lazy-range-add-sum.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/segment-tree-lazy-range-add-sum.cpp)
- flagship in-lane rep -> [HORRIBLE - Horrible Queries](../practice/ladders/data-structures/lazy-segment-tree/horriblequeries.md)
- parent structure refresher -> [Segment Tree hot sheet](segment-tree-hot-sheet.md)
- lighter neighboring route -> [Range Update Queries](../practice/ladders/foundations/difference-arrays/rangeupdatequeries.md)

## Reopen Paths

- full lesson and tag-semantics discussion -> [Lazy Segment Tree](../topics/data-structures/lazy-segment-tree/README.md)
- point-update-only baseline -> [Segment Tree](../topics/data-structures/segment-tree/README.md)
- harder clamp-update route -> [Segment Tree Beats](../topics/data-structures/segment-tree-beats/README.md)
- lighter structure chooser -> [Data structures cheatsheet](data-structures-cheatsheet.md)
- snippet chooser -> [Template Library](../template-library.md)
