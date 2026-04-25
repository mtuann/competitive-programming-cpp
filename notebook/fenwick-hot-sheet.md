# Fenwick Hot Sheet

Use this page when the real structure is still a prefix machine, but updates are now online and a plain prefix array is no longer enough.

## Do Not Use When

- the query is a static range aggregate, so prefix sums or a sparse table already solve it
- the merge is not additive or prefix-reducible
- the task needs arbitrary segment summaries or lazy range updates that do not reduce cleanly to BIT variants

## Choose By Signal

- point add plus prefix or range sum -> [`fenwick-point-prefix.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/fenwick-point-prefix.cpp)
- dynamic frequency table after coordinate compression -> Fenwick
- inversion counting by processed-prefix frequencies -> Fenwick
- k-th alive or k-th inserted by prefix counts -> Fenwick with binary lifting on counts
- range-update variants -> reopen the topic page first; the starter is the one-BIT point-add family

## Core Invariants

- `bit[i]` stores one suffix block ending at `i`
- the repo starter is 1-based, additive, and exposes `add`, `sum_prefix`, and `sum_range`
- query walks peel disjoint suffix blocks from right to left
- update walks climb through exactly the cached blocks that contain the changed position

## Main Traps

- mixing 0-based statement indices with a 1-based BIT helper
- copying the additive BIT into min/max/custom-merge problems
- forgetting that order-statistic tricks only work when the stored counts stay nonnegative and prefix-monotone

## Exact Starters In This Repo

- point add plus range sum -> [`fenwick-point-prefix.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/fenwick-point-prefix.cpp)
- flagship repo note -> [CVP00001](../practice/ladders/data-structures/fenwick-tree/cvp00001.md)
- compare against heavier range structures -> [Segment Tree hot sheet](segment-tree-hot-sheet.md)

## Reopen Paths

- invariant, range-update variants, and frequency view -> [Fenwick Tree](../topics/data-structures/fenwick-tree/README.md)
- nearby structure chooser -> [Data structures cheatsheet](data-structures-cheatsheet.md)
- snippet map -> [Template Library](../template-library.md)
