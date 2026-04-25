# Kingdom and its Cities

- Title: `Kingdom and its Cities`
- Judge / source: `Codeforces`
- Original URL: [https://codeforces.com/problemset/problem/613/D](https://codeforces.com/problemset/problem/613/D)
- Secondary topics: `Marked subset queries`, `Tree DP`, `Minimum separator`
- Difficulty: `very hard`
- Subtype: `Virtual tree + two-state query-local DP`
- Status: `solved`
- Solution file: [kingdomanditscities.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/virtual-tree/kingdomanditscities.cpp)

## Why Practice This

This is the cleanest classic rep for the first full `virtual tree` lane.

The statement gives:

- one static tree
- many queries
- each query marks a small set of important cities
- the answer depends on how those marked cities connect through the original tree

So the right workflow is exactly:

1. compress one query into its virtual tree
2. carry one small piece of metadata on each compressed edge
3. run one DP on the compressed tree instead of on all `n` cities

## Recognition Cue

Reach for virtual tree when:

- each query gives a set of important/special vertices
- the full tree is large, but total marked vertices over all queries is manageable
- only paths among the marked vertices matter
- the actual answer should come from a small DP after compression

The smell here is:

```text
for each query, only the important cities and their meeting LCAs are relevant
```

## Problem-Specific Transformation

For one query, let the important cities be the marked set `S`.

Two observations drive the whole solution:

1. if two important cities are adjacent in the original tree, the answer is immediately `-1`
2. otherwise, every useful separator lives on the compressed tree built from:
   - the important cities
   - plus the LCAs needed to glue their paths together

So the problem becomes:

- build the virtual tree of `S`
- for each compressed edge `u -> v`, ask whether that whole segment can be blocked by deleting one non-important city
- run a small DP that tracks whether one important component is still "active" and connected upward

## Core Idea

On the virtual tree, each subtree only needs two states:

- `dp0[u]`: minimal deletions so everything below `u` is already pairwise isolated and no important component still needs to connect upward through `u`
- `dp1[u]`: minimal deletions so everything below `u` is valid and exactly one important component is still connected upward through `u`

If `u` is important:

- `dp1[u]` starts as `0`
- `dp0[u]` starts impossible

If `u` is not important:

- you may keep `u` and allow at most one active child component to survive upward
- or delete `u` itself, which separates all child sides at once

The compressed-edge metadata is tiny but crucial:

- if the segment from parent `u` to child `v` contains at least one deletable non-important city, that whole branch can be sealed with cost `1`
- if `u` and important `v` are adjacent in the original tree, that segment has no safe internal cut, so the cost is effectively `INF`

That is exactly why the virtual tree is the right object:

```text
the query-local DP only needs the marked nodes, the LCAs, and one cutability fact per compressed edge
```

## Implementation Plan

1. preprocess the original tree for `tin/tout`, `depth`, and LCA
2. for each query:
   - mark the important cities
   - build the virtual tree from those marked nodes
   - compute one cut cost per compressed edge
   - run the two-state DP bottom-up on the compressed tree
3. clear the marks for the next query

The total size of all virtual trees stays linear in the total query input size, up to the LCA preprocessing factor.

## Complexity

- preprocessing: `O(n log n)`
- one query build + DP: `O(k log n)` where `k` is the number of important cities in that query
- total: `O((n + sum k) log n)`

This matches the official constraints because the sum of all `k` values is bounded.

## Main Traps

- forgetting the easy impossible case hidden inside the DP: an important city directly adjacent to another important city gives no deletable separator on that compressed segment
- building the virtual tree but not carrying enough metadata on the compressed edges
- trying to do the DP on the original tree for every query
- forgetting to clear per-query marks after the answer

## Reopen Path

- Topic page: [Virtual Tree / Auxiliary Tree](../../../../topics/graphs/virtual-tree/README.md)
- Practice ladder: [Virtual Tree ladder](README.md)
- Starter template: [virtual-tree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/virtual-tree.cpp)
- Notebook refresher: [Virtual Tree hot sheet](../../../../notebook/virtual-tree-hot-sheet.md)
- Compare points: [LCA](../../../../topics/graphs/lca/README.md), [Tree DP](../../../../topics/dp/tree-dp/README.md), [Heavy-Light Decomposition](../../../../topics/graphs/hld/README.md)

## Solution

- Code: [kingdomanditscities.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/virtual-tree/kingdomanditscities.cpp)

