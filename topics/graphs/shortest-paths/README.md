# Shortest Paths

Shortest-path problems are about choosing the right relaxation model, not memorizing one favorite algorithm. The first question is always what kind of edge weights and transitions the graph allows.

## Summary

Suspect shortest paths when:

- the task asks for minimum distance, time, cost, or number of moves
- the graph may be weighted or unweighted
- you need path reconstruction, not only the final distance

What success looks like:

- you choose BFS, 0-1 BFS, Dijkstra, or Bellman-Ford from the weight model
- you know when reverse shortest paths are useful
- you can write relaxation-based code with correct distance types and stale-entry handling

## Prerequisites

- [Graph Modeling](../graph-modeling/README.md)
- [BFS And DFS](../bfs-dfs/README.md)

## Core Idea

Choose the tool by the edge model:

- unweighted graph: BFS
- weights `0` or `1`: 0-1 BFS
- nonnegative weights: Dijkstra
- negative edges: Bellman-Ford or a more specialized method

All of them rely on relaxation:

```text
dist[v] <= dist[u] + w
```

The algorithm differs only in how it decides which tentative state to process next.

## Theory / Proof Sketch

### BFS

In an unweighted graph:

```text
The first time a node is reached,
it is reached with the minimum number of edges.
```

This works because the queue processes nodes layer by layer.

### Dijkstra

For nonnegative weights:

```text
When the minimum-distance unprocessed node u is finalized,
dist[u] is already the true shortest distance.
```

This fails if negative edges exist, because a later path could still improve `dist[u]`.

### Bellman-Ford View

If negative edges exist, shortest paths are still about repeated relaxations, but you lose Dijkstra’s greedy-finalization guarantee.

## Complexity And Tradeoffs

- BFS: `O(n + m)`
- 0-1 BFS: `O(n + m)`
- Dijkstra with heap: `O((n + m) log n)`
- Bellman-Ford: `O(nm)`

Tradeoffs:

- use the simplest valid model
- weighted algorithms are not automatically better
- path restoration usually costs only one `parent` array

## Canonical C++ Pattern

Template in this repo:

- [dijkstra.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dijkstra.cpp)

Core arrays:

- `dist`
- `parent`
- `used` or heap-based stale skipping

Important habits:

- initialize distances with a large sentinel
- use `long long` when path totals may overflow `int`
- in heap Dijkstra, skip stale entries

## Standard Patterns

### 1. Single-Source Shortest Path

The direct version:

- one source
- all distances from it

### 2. Reverse Shortest Paths

Sometimes you want distances to a target instead of from a source.

For directed graphs, reverse edges and run the same algorithm from the target.

### 3. Path Reconstruction

Store `parent[v]` whenever `dist[v]` improves.

Then rebuild the chosen shortest path by walking backward.

### 4. Near-Shortest Or Constrained Variants

Some harder problems build on shortest paths instead of ending there.

Example:

- [QOS](../../../practice/ladders/graphs/shortest-paths/qos.md)

## Worked Examples

### Example 1: road network with nonnegative weights

Use standard Dijkstra.

The key correctness condition is the absence of negative edges.

### Example 2: grid with equal move cost

Use plain BFS.

This is a common place where people overcomplicate with Dijkstra unnecessarily.

### Example 3: reverse shortest paths

If many queries or a later DP need distance to the same target:

- reverse the edges
- run one shortest-path computation from the target

This is a high-value modeling trick.

## Recognition Cues

Strong clues:

- minimum distance / cost / time / moves
- explicit weights or implicit move costs
- many states but local transitions
- later logic depends on shortest distances as a foundation

Shortest paths is often confused with:

- [BFS And DFS](../bfs-dfs/README.md), because BFS itself is the shortest-path tool for unit weights
- [Graph Modeling](../graph-modeling/README.md), because the wrong graph model makes the algorithm choice meaningless

## Common Mistakes

- using Dijkstra with negative edges
- forgetting to skip stale heap entries
- storing distances in `int` when totals may overflow
- solving an unweighted problem with heavier weighted machinery
- forgetting reverse-graph modeling when distances to a single target are needed

## Practice Ladder

- [Graphs ladder overview](../../../practice/ladders/graphs/README.md)
- [Shortest paths ladder](../../../practice/ladders/graphs/shortest-paths/README.md)

Suggested order:

1. BFS shortest path
2. Dijkstra with path restoration
3. choose between BFS, 0-1 BFS, and Dijkstra
4. reverse shortest-path preprocessing

## Go Deeper

- Reference: [CP-Algorithms - Dijkstra](https://cp-algorithms.com/graph/dijkstra.html)
- Reference: [CP-Algorithms - 0-1 BFS](https://cp-algorithms.com/graph/01_bfs.html)
- Practice: [CSES Graph Algorithms](https://cses.fi/problemset/)
- Practice: [QOS note](../../../practice/ladders/graphs/shortest-paths/qos.md)

## Related Topics

- [BFS And DFS](../bfs-dfs/README.md)
- [Graph Modeling](../graph-modeling/README.md)
- [Minimum Spanning Tree](../mst/README.md)
