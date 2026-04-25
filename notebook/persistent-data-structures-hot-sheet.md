# Persistent Data Structures Hot Sheet

Use this sheet when the problem keeps **many versions alive** and updates should create a new version instead of overwriting the old one.

## Do Not Use When

- only the current state matters
- you just need undo along one DFS or time traversal -> compare [DSU Rollback hot sheet](dsu-rollback-hot-sheet.md)
- the starter would need range-update tags rather than point updates
- the real task is order statistics or another richer persistent variant that the first starter does not cover

## Choose By Signal

- "copy array `k`, then query or update the copy later" -> persistent segment tree
- "past snapshots stay queryable after later updates" -> persistent segment tree
- "undo the most recent changes while walking one recursion tree" -> rollback, not persistence
- "k-th smallest between versions / prefix roots" -> reopen the full topic before copying the starter

## Core Invariant

- one version is one root handle
- a point update clones only the root-to-leaf path
- every untouched subtree is shared between versions
- old roots are immutable and remain queryable forever

## Main Traps

- mutating a shared node and corrupting old versions
- forgetting that a copy query is often just `roots.push_back(roots[k])`
- mixing one-based statement indices with zero-based half-open internal intervals
- assuming the first starter supports lazy range updates or order-statistics variants

## Exact Starter Route

- exact starter -> [`persistent-segment-tree-point-set-sum.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/persistent-segment-tree-point-set-sum.cpp)
- flagship in-lane rep -> [Range Queries and Copies](../practice/ladders/data-structures/persistent-data-structures/rangequeriesandcopies.md)
- compare points -> [Segment Tree hot sheet](segment-tree-hot-sheet.md), [DSU Rollback hot sheet](dsu-rollback-hot-sheet.md)

## Reopen Paths

- full lesson and path-copying proof shape -> [Persistent Data Structures](../topics/data-structures/persistent-data-structures/README.md)
- one-current-version route -> [Segment Tree](../topics/data-structures/segment-tree/README.md)
- undo-over-time route -> [DSU Rollback / Offline Dynamic Connectivity](../topics/data-structures/dsu-rollback/README.md)
