# BFS And DFS

BFS and DFS are the first two graph traversals you should recognize quickly. They solve different problems, but they share the same starting point: a graph model and a systematic visit order.

## Prerequisites

- [Graph Modeling](../graph-modeling/README.md)

## When To Suspect It

- reachability or connectivity is the main question
- the graph is unweighted and you need shortest paths
- you need components, traversal order, or cycle detection

## Core Idea

- BFS explores in layers from a source
- DFS explores one branch deeply before backtracking

Use BFS when layer distance matters.
Use DFS when structure and traversal order matter.

## Theory / Proof Sketch

BFS invariant:

```text
When a node is popped from the queue, its recorded distance is the shortest number of edges from the source.
```

DFS invariant:

```text
When DFS enters a node, all recursive or stack descendants belong to the current active search branch.
```

These invariants explain why BFS solves unweighted shortest path and why DFS is useful for components, cycle detection, and ordering.

## Complexity And Tradeoffs

- BFS: `O(n + m)`
- DFS: `O(n + m)`
- memory depends on the graph representation plus queue or stack

Tradeoffs:

- BFS is best for unweighted shortest paths
- DFS is often better for structural decompositions and search-tree reasoning

## Canonical C++ Pattern

Templates in this repo:

- [bfs.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bfs.cpp)
- [dfs-iterative.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dfs-iterative.cpp)

Useful stored arrays:

- `visited`
- `dist`
- `parent`
- `tin`, `tout`, or `color` for DFS variants

## Worked Examples

Example 1: connected components

- repeated BFS or DFS over unvisited nodes

Example 2: shortest path in an unweighted graph

- BFS from the source
- restore the path using `parent`

Example 3: bipartite check

- BFS or DFS with alternating colors

## Common Mistakes

- using DFS for unweighted shortest path
- forgetting to reset state between components
- recursive DFS stack overflow on very deep graphs
- marking nodes too late and pushing duplicates

## Practice Ladder

- [Graphs ladder overview](../../../practice/ladders/graphs/README.md)
- [BFS / DFS ladder](../../../practice/ladders/graphs/bfs-dfs/README.md)

## Go Deeper

- Reference: [CP-Algorithms - BFS](https://cp-algorithms.com/graph/breadth-first-search.html)
- Reference: [CP-Algorithms - DFS](https://cp-algorithms.com/graph/depth-first-search.html)
- Practice: [CSES Graph Algorithms](https://cses.fi/problemset/)

## Related Topics

- [Graph Modeling](../graph-modeling/README.md)
- [Shortest Paths](../shortest-paths/README.md)
