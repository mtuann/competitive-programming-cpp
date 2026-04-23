# Topological Sort And SCC

Topological sort and strongly connected components are the two standard ways to simplify directed graphs.

## Prerequisites

- [BFS And DFS](../bfs-dfs/README.md)

## When To Suspect It

- directed dependencies
- prerequisite graphs
- cycles matter
- you want to compress directed graph structure

## Core Idea

Two core tasks:

- topological sort for DAGs
- SCC decomposition for general directed graphs

After SCC compression, every directed graph becomes a DAG of components.

## Theory / Proof Sketch

Toposort:

- an order exists if and only if the graph is acyclic

SCC:

- inside one component, every vertex reaches every other
- contracting each SCC yields a DAG

That DAG is the right structure for many later DP or reachability arguments.

## Complexity And Tradeoffs

- Kahn topological sort: `O(n + m)`
- Kosaraju / Tarjan SCC: `O(n + m)`

## Canonical Pattern

Templates in this repo:

- [toposort-kahn.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/toposort-kahn.cpp)
- [scc-kosaraju.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/scc-kosaraju.cpp)

## Worked Examples

Example 1: dependency order in a DAG

Example 2: detect impossible scheduling because of a cycle

Example 3: SCC condensation followed by DAG DP

## Common Mistakes

- using topological sort on a graph without checking for cycles
- forgetting reverse graph construction in Kosaraju
- not distinguishing SCC ids from original vertex ids

## Practice Ladder

- [SCC and toposort ladder](../../../practice/ladders/graphs/scc-toposort/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Topological Sort](https://cp-algorithms.com/graph/topological-sort.html)
- Reference: [CP-Algorithms - SCC](https://cp-algorithms.com/graph/strongly-connected-components.html)
- Practice: [CSES Graph Algorithms](https://cses.fi/problemset/)

## Related Topics

- [BFS And DFS](../bfs-dfs/README.md)
- [Shortest Paths](../shortest-paths/README.md)
