# HLD Hot Sheet

Use this page when the tree is static, path queries or updates are many, and the missing step is recalling how one tree path becomes a few array intervals.

## Do Not Use When

- the task is subtree-only, so Euler-tour flattening is enough
- the path query is static and LCA or one offline trick already finishes the job
- the aggregate is non-commutative or edge-valued and you have not fixed the convention yet

## Choose By Signal

- static tree, point updates on vertices, path maximum -> [`hld-path-max.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hld-path-max.cpp)
- many path aggregates on a static tree -> HLD plus a range structure
- subtree-only updates or queries -> do not default to HLD first
- path queries with heavy updates or non-commutative folds -> reopen the topic page before copying the starter

## Core Invariants

- each node belongs to exactly one heavy chain
- any root-to-node route crosses only `O(log n)` light edges
- every query path breaks into `O(log n)` chain intervals
- the repo starter assumes node values, commutative `max`, and 0-based nodes

## Main Traps

- mixing node-valued and edge-valued conventions
- forgetting the final same-chain segment
- copying a commutative max starter into a sum/non-commutative path problem without fixing the accumulator logic
- using HLD where subtree flattening or LCA alone is lighter

## Exact Starters In This Repo

- static tree, point updates, path maximum -> [`hld-path-max.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hld-path-max.cpp)
- flagship note -> [Path Queries II](../practice/ladders/graphs/hld/pathqueries2.md)
- compare against array-only range structures -> [Segment Tree hot sheet](segment-tree-hot-sheet.md)

## Reopen Paths

- decomposition proof, conventions, and path-loop boundaries -> [Heavy-Light Decomposition](../topics/graphs/hld/README.md)
- lighter tree-family choice -> [Graph cheatsheet](graph-cheatsheet.md)
- exact snippet map -> [Template Library](../template-library.md)
