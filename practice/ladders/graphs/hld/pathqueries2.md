# PATHQUERIES2

- Title: `PATHQUERIES2 - Path Queries II`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/2134](https://cses.fi/problemset/task/2134)
- Main topic: `Graphs -> Heavy-Light Decomposition`
- Secondary topics: `Segment tree`, `Path maximum queries`, `Point updates`
- Difficulty: `medium`
- Subtype: `Node updates and maximum queries on arbitrary tree paths`
- Status: `solved`
- Solution file: [pathqueries2.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/hld/pathqueries2.cpp)

## Why Practice This

This is the clean CSES entry point for heavy-light decomposition.

You need exactly the two operations that make HLD useful:

- update one vertex value online
- query an aggregate on the path between any two vertices

Nothing extra is hiding in the statement, so the main skill is learning how to turn a tree path into a few segment-tree intervals.

## Core Idea

Heavy-light decomposition groups every node into a heavy chain.

When we flatten those chains into one base array:

- each chain becomes a contiguous interval
- a point update becomes one segment-tree update
- any path `u -> v` breaks into `O(log N)` chain intervals

So a query works like this:

1. while `u` and `v` are on different chains, move up from the deeper chain head and query that whole segment
2. once both nodes are on the same chain, query the final interval between them
3. take the maximum over all touched segments

The segment tree only needs range maximum and point assignment.

## Implementation Notes

The repo solution uses two iterative passes:

1. compute `parent`, `depth`, subtree sizes, and the heavy child of each node
2. walk every chain head-to-tail to assign `head[u]` and `pos[u]`

Using iterative traversals avoids recursion-depth issues on a degenerate tree with `N = 2 * 10^5`.

## Complexity

- preprocessing: `O(N)`
- each update: `O(log N)`
- each path query: `O(log^2 N)`
- memory: `O(N)`

This is comfortably fast for the CSES limits.

## Pitfalls / Judge Notes

- Values live on vertices, not edges, so the final same-chain query includes both endpoints.
- Store the value of node `u` at exactly one position `pos[u]` in the base array.
- When chain heads differ, always climb from the deeper head.
- You do not need a separate LCA routine here; the final same-chain interval handles the meeting point naturally.

## Reusable Pattern

- Topic page: [Heavy-Light Decomposition](../../../../topics/graphs/hld/README.md)
- Practice ladder: [Heavy-Light Decomposition ladder](README.md)
- Starter template: [segment-tree-iterative.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/segment-tree-iterative.cpp)
- Notebook refresher: [Data structures cheatsheet](../../../../notebook/data-structures-cheatsheet.md)
- Carry forward: climb by deeper chain heads so every path becomes only a few contiguous segments.
- This note adds: the tree flattening and chain bookkeeping layered on top of the segment-tree core.

## Solutions

- Code: [pathqueries2.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/hld/pathqueries2.cpp)
