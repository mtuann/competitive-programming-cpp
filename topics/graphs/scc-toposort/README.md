# Topological Sort And SCC

Topological sort and strongly connected components are the two standard ways to simplify directed graphs. One works when the graph is already acyclic; the other tells you how to compress a general directed graph into a DAG.

## Summary

Suspect this topic when:

- edges represent directed dependencies
- cycles matter
- you want to process a directed graph in dependency order
- compressing mutually reachable parts would simplify the problem

What success looks like:

- you know when topological sort alone is enough
- you know when SCC decomposition must come first
- you can explain why SCC condensation is always a DAG

## Prerequisites

- [BFS And DFS](../bfs-dfs/README.md)

## Core Idea

Two core tasks:

- topological sort for DAGs
- SCC decomposition for general directed graphs

After SCC compression:

- every directed graph becomes a DAG of components

That condensation DAG is often the real object you want for DP, reachability, or counting.

## Theory / Proof Sketch

### Topological Sort

A topological order exists if and only if the directed graph is acyclic.

Why Kahn’s algorithm works:

- nodes with indegree `0` have no remaining prerequisites
- removing them preserves the same property on the smaller graph

### SCC

Inside one strongly connected component, every vertex reaches every other.

If you contract each SCC into one node:

- you cannot get a directed cycle among components

Why:

- any cycle among components would imply those components were mutually reachable and should have been one SCC

## Complexity And Tradeoffs

- Kahn topological sort: `O(n + m)`
- Kosaraju SCC: `O(n + m)`
- Tarjan SCC: `O(n + m)`

Tradeoffs:

- Kahn is very readable for DAG processing
- Kosaraju is conceptually clean if reverse-graph handling is comfortable
- Tarjan is one-pass but trickier to internalize at first

## Canonical C++ Pattern

Templates in this repo:

- [toposort-kahn.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/toposort-kahn.cpp)
- [scc-kosaraju.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/scc-kosaraju.cpp)

Kahn ingredients:

- indegree array
- queue of current indegree-zero vertices

Kosaraju ingredients:

- original graph
- reverse graph
- first DFS order
- second DFS on reversed order

## Standard Patterns

### 1. Dependency Order In A DAG

Examples:

- task scheduling
- prerequisite ordering
- DAG DP

### 2. Detect Impossible Scheduling

If topological sort processes fewer than `n` nodes, a cycle exists.

### 3. SCC Condensation

Compress SCCs first, then solve on the condensation DAG.

This is often the correct first move for directed graphs with cycles.

## Worked Examples

### Example 1: schedule tasks with prerequisites

Model tasks as vertices and prerequisites as directed edges.

If a topological order exists, it is a valid schedule.

### Example 2: detect impossible scheduling

Run Kahn:

- if not all nodes are output, the graph has a cycle

This is one of the simplest directed-cycle tests.

### Example 3: SCC condensation followed by DAG DP

When cycles exist, compress SCCs:

- each SCC becomes one node
- run DP or reachability on the condensation DAG

This is the standard “compress first, solve later” pattern.

## Recognition Cues

Strong clues:

- directed dependencies
- “must be done before”
- cycles make the answer impossible or change the structure
- many mutually reachable vertices should be grouped

This topic is often confused with:

- [BFS And DFS](../bfs-dfs/README.md), because the implementation is traversal-based
- [Shortest Paths](../shortest-paths/README.md), because both live on directed graphs but solve different structural questions

## Common Mistakes

- using topological sort without checking whether the graph is a DAG
- forgetting reverse-graph construction in Kosaraju
- confusing SCC ids with original vertex ids
- doing DP on the original cyclic graph instead of the condensation DAG

## Practice Ladder

- [SCC and toposort ladder](../../../practice/ladders/graphs/scc-toposort/README.md)

Suggested order:

1. Kahn topological sort
2. cycle detection by failed topological sort
3. SCC decomposition
4. condensation DAG reasoning

## Go Deeper

- Reference: [CP-Algorithms - Topological Sort](https://cp-algorithms.com/graph/topological-sort.html)
- Reference: [CP-Algorithms - SCC](https://cp-algorithms.com/graph/strongly-connected-components.html)
- Practice: [CSES Graph Algorithms](https://cses.fi/problemset/)
- Next step: [Shortest Paths](../shortest-paths/README.md)

## Related Topics

- [BFS And DFS](../bfs-dfs/README.md)
- [Graph Modeling](../graph-modeling/README.md)
- [Shortest Paths](../shortest-paths/README.md)
