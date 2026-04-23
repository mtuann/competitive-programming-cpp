# Minimum Spanning Tree

MST is the standard way to connect all vertices as cheaply as possible in an undirected weighted graph.

## Prerequisites

- [DSU](../../data-structures/dsu/README.md)
- [Sorting](../../foundations/patterns/sorting/README.md)

## When To Suspect It

- connect all nodes with minimum total cost
- build a cheapest backbone network
- the graph is undirected and weighted

## Core Idea

The two classic algorithms are:

- Kruskal
- Prim

Kruskal is the better first implementation because it connects directly to DSU.

## Theory / Proof Sketch

The key facts are the cut and cycle properties.

Kruskal view:

- sort edges by weight
- add an edge if it joins two different components

This is safe because the lightest crossing edge of a cut can be part of some MST.

## Complexity And Tradeoffs

- Kruskal: `O(m log m)`
- Prim with heap: `O(m log n)`

Tradeoffs:

- Kruskal is usually simpler when edges are already explicit
- Prim is natural on dense adjacency-style input

## Canonical Pattern

Template in this repo:

- [kruskal.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/kruskal.cpp)

## Worked Examples

Example 1: cheapest network connection

Example 2: detect whether a graph is fully connectable

Example 3: MST as a subroutine inside a threshold or clustering problem

## Common Mistakes

- using MST on directed graphs
- forgetting to verify connectivity at the end
- rebuilding DSU incorrectly between test cases

## Practice Ladder

- [MST ladder](../../../practice/ladders/graphs/mst/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Kruskal](https://cp-algorithms.com/graph/mst_kruskal.html)
- Reference: [CP-Algorithms - Prim](https://cp-algorithms.com/graph/mst_prim.html)
- Practice: [CSES Graph Algorithms](https://cses.fi/problemset/)

## Related Topics

- [DSU](../../data-structures/dsu/README.md)
- [Graph Modeling](../graph-modeling/README.md)
