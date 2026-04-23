# DSU

Disjoint Set Union is the standard tool for maintaining connected components under merge operations.

## Prerequisites

- [Foundations](../../foundations/README.md)

## When To Suspect It

- edges are added over time
- the question is about connectivity or component membership
- you need to merge groups efficiently
- Kruskal or offline connectivity is nearby

## Core Idea

Each component has a representative called its root.

Two operations matter:

- `find(x)`: return the representative of `x`
- `unite(a, b)`: merge the two components if they differ

The standard performance tricks are:

- path compression
- union by size or rank

## Theory / Proof Sketch

The invariant is:

- every node points, directly or indirectly, to the root of its component

Path compression keeps the same connected components while making future `find` operations faster.

Union by size keeps the trees shallow by attaching the smaller root under the larger one.

Together they make DSU effectively constant time per operation for contest purposes.

## Complexity And Tradeoffs

- amortized time per operation: effectively `O(1)`
- memory: `O(n)`

Tradeoffs:

- DSU handles merges well
- DSU does not support arbitrary deletions well
- DSU is great for connectivity, but not for general path queries

## Canonical C++ Pattern

Template in this repo:

- [dsu-basic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/dsu-basic.cpp)

Useful fields:

- `parent[x]`
- `size[x]`
- optional component metadata

## Worked Examples

Example 1: static connectivity with edge additions

- process edges
- answer whether two vertices share the same root

Example 2: cycle detection in an undirected graph

- if an edge joins two vertices already in the same component, a cycle exists

Example 3: Kruskal

- sort edges by weight
- take an edge only if it joins different components

## Common Mistakes

- forgetting to initialize each node as its own parent
- mixing root size with node size
- writing `find` recursively without thinking about stack limits in very unusual cases
- using DSU when deletions are central to the problem

## Practice Ladder

- [Data structures ladder](../../../practice/ladders/data-structures/README.md)
- [DSU ladder](../../../practice/ladders/data-structures/dsu/README.md)

## Go Deeper

- Reference: [CP-Algorithms - DSU](https://cp-algorithms.com/data_structures/disjoint_set_union.html)
- Reference: [USACO Guide - DSU](https://usaco.guide/gold/dsu)
- Practice: [CSES Problem Set](https://cses.fi/problemset/)

## Related Topics

- [Fenwick Tree](../fenwick-tree/README.md)
- [Graphs](../../graphs/README.md)
- [Shortest Paths](../../graphs/shortest-paths/README.md)
