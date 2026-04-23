# BFS And DFS

BFS and DFS are the first two graph traversals you should recognize quickly. They solve different problems, but they share the same starting point: a graph model and a systematic visit order.

## Summary

Suspect BFS or DFS when:

- reachability or connectivity is the main question
- the graph is unweighted and you need shortest paths in number of edges
- you need components, coloring, traversal order, or cycle detection

What success looks like:

- you know when BFS is required because distances matter
- you know when DFS is natural because structure or recursion order matters
- you can write either traversal with clean visited-state discipline

## Prerequisites

- [Graph Modeling](../graph-modeling/README.md)

## Core Idea

- BFS explores in layers from a source
- DFS explores one branch deeply before backtracking

Use BFS when layer distance matters.

Use DFS when structural decomposition, recursion, or search-tree reasoning matters.

## Theory / Proof Sketch

### BFS Invariant

```text
When a node is popped from the queue,
its recorded distance is the shortest number of edges from the source.
```

Why:

- BFS processes nodes in nondecreasing distance order
- every edge has equal cost in an unweighted graph

### DFS Invariant

```text
When DFS enters a node,
all recursive or stack descendants belong to the current active search branch.
```

Why this matters:

- entry/exit order becomes meaningful
- subtree reasoning becomes possible
- cycle and ancestor logic can be expressed via colors or timestamps

## Complexity And Tradeoffs

- BFS: `O(n + m)`
- DFS: `O(n + m)`
- memory: graph plus queue or stack / recursion

Tradeoffs:

- BFS is best for unweighted shortest paths
- DFS is often better for components, cycle detection, and later graph algorithms based on traversal order
- recursive DFS is concise, but iterative DFS is safer on very deep graphs

## Canonical C++ Pattern

Templates in this repo:

- [bfs.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bfs.cpp)
- [dfs-iterative.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dfs-iterative.cpp)

Common arrays:

- `visited`
- `dist`
- `parent`
- `color`
- `tin`, `tout`

Good rule:

- mark visited at the moment you commit to exploring the node, not later

## Standard Patterns

### 1. Connected Components

Repeat BFS or DFS from every unvisited node.

### 2. Unweighted Shortest Path

Run BFS from the source and store `dist` and optionally `parent`.

### 3. Bipartite Check

Assign alternating colors using BFS or DFS. Any edge between equal colors breaks bipartiteness.

### 4. Cycle Detection

Use parent checks in undirected graphs or color states / recursion-stack logic in directed graphs.

## Worked Examples

### Example 1: connected components

Each new BFS/DFS from an unvisited node discovers exactly one component.

That is why repeated traversals partition the graph.

### Example 2: shortest path in an unweighted graph

Run BFS from the source.

Store:

- `dist[v]`
- `parent[v]`

Then reconstruct the path by walking parents backward.

### Example 3: bipartite check

Color the graph with `0/1` while traversing.

If an edge joins equal colors, the graph is not bipartite.

This is one of the most common BFS/DFS follow-up applications.

## Recognition Cues

Strong clues:

- unweighted graph
- connected components
- reachability
- “minimum number of moves”
- traversal order or search tree matters

BFS/DFS is often confused with:

- [Shortest Paths](../shortest-paths/README.md), because BFS is itself the shortest-path tool for unweighted graphs
- [Graph Modeling](../graph-modeling/README.md), because many failures here actually start with a bad model

## Common Mistakes

- using DFS for unweighted shortest path
- forgetting to reset state between components
- recursive DFS stack overflow on deep graphs
- marking visited too late and pushing duplicates into the BFS queue
- mixing directed and undirected cycle logic

## Practice Ladder

- [Graphs ladder overview](../../../practice/ladders/graphs/README.md)
- [BFS / DFS ladder](../../../practice/ladders/graphs/bfs-dfs/README.md)

Suggested order:

1. reachability and components
2. shortest path in unweighted graphs
3. bipartite check
4. cycle detection and traversal-order reasoning

## Go Deeper

- Reference: [CP-Algorithms - BFS](https://cp-algorithms.com/graph/breadth-first-search.html)
- Reference: [CP-Algorithms - DFS](https://cp-algorithms.com/graph/depth-first-search.html)
- Practice: [CSES Graph Algorithms](https://cses.fi/problemset/)
- Practice: [USACO Guide](https://usaco.guide/)

## Related Topics

- [Graph Modeling](../graph-modeling/README.md)
- [Shortest Paths](../shortest-paths/README.md)
- [Topological Sort And SCC](../scc-toposort/README.md)
