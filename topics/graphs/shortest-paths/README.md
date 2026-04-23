# Shortest Paths

Shortest-path problems are about choosing the right relaxation model, not about memorizing one algorithm. The first question is always what kind of edge weights the graph allows.

## Prerequisites

- [Graph Modeling](../graph-modeling/README.md)
- [BFS And DFS](../bfs-dfs/README.md)

## When To Suspect It

- the task asks for minimum distance, time, cost, or number of moves
- the graph is weighted or unweighted
- you need path reconstruction, not only the distance

## Core Idea

Choose the tool by the edge model:

- unweighted graph: BFS
- weights `0` or `1`: 0-1 BFS
- nonnegative weights: Dijkstra
- negative edges: Bellman-Ford or a more specialized method

All of them are based on relaxation:

```text
dist[v] <= dist[u] + w
```

## Theory / Proof Sketch

Dijkstra invariant:

```text
When the minimum-distance unprocessed node u is finalized,
dist[u] is already the true shortest distance.
```

That is only valid when edge weights are nonnegative.

BFS is the same idea in unit-weight layers:

```text
The first time a node is reached, it is reached with the minimum number of edges.
```

## Complexity And Tradeoffs

- BFS: `O(n + m)`
- Dijkstra with a heap: `O((n + m) log n)`
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
- `used` or heap-based lazy skipping

## Worked Examples

Example 1: road network with nonnegative weights

- standard Dijkstra

Example 2: grid with equal move cost

- plain BFS is enough

Example 3: bounded-near-shortest reconstruction

- [QOS](../../../practice/ladders/graphs/shortest-paths/qos.md) is a stretch example where shortest paths become the base layer for a richer DP and reconstruction problem

## Common Mistakes

- using Dijkstra with negative edges
- forgetting to skip stale heap entries
- storing distances in `int` when the total path length may overflow
- solving an unweighted task with heavier weighted machinery

## Practice Ladder

- [Graphs ladder overview](../../../practice/ladders/graphs/README.md)
- [Shortest paths ladder](../../../practice/ladders/graphs/shortest-paths/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Dijkstra](https://cp-algorithms.com/graph/dijkstra.html)
- Reference: [CP-Algorithms - 0-1 BFS](https://cp-algorithms.com/graph/01_bfs.html)
- Practice: [CSES Graph Algorithms](https://cses.fi/problemset/)

## Related Topics

- [BFS And DFS](../bfs-dfs/README.md)
- [Flow](../README.md)
- [QOS note](../../../practice/ladders/graphs/shortest-paths/qos.md)
