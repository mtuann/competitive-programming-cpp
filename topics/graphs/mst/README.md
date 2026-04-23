# Minimum Spanning Tree

Minimum spanning tree is the standard way to connect all vertices of an undirected weighted graph as cheaply as possible. It is one of the cleanest examples of greedy reasoning in graph algorithms.

## Summary

Suspect MST when:

- you must connect all nodes with minimum total cost
- the graph is undirected and weighted
- the goal is to build a cheapest backbone, network, or clustering structure

What success looks like:

- you can decide between Kruskal and Prim from the input form
- you can explain the cut or cycle property in words
- you remember to check whether the graph is actually fully connectable

## Prerequisites

- [DSU](../../data-structures/dsu/README.md)
- [Sorting](../../foundations/patterns/sorting/README.md)

## Core Idea

The two classic MST algorithms are:

- Kruskal
- Prim

Kruskal is usually the better first implementation:

- sort edges by weight
- add an edge if it joins two different components

Prim is often more natural when:

- the graph is already stored as adjacency lists
- you want to grow one connected tree outward from a start vertex

## Theory / Proof Sketch

Two key facts power MST correctness:

### Cut Property

For any cut of the graph, the lightest edge crossing that cut can belong to some MST.

This is the core reason Kruskal is safe.

### Cycle Property

Inside any cycle, the heaviest edge cannot be necessary for every MST.

This explains why edges that would create a cycle can be skipped in Kruskal.

Kruskal view:

- when processing edges in increasing order, the first edge that can connect two different components is always safe to take

## Complexity And Tradeoffs

- Kruskal: `O(m log m)` from sorting edges
- Prim with heap: `O(m log n)`

Tradeoffs:

- Kruskal is simpler when the edge list is explicit
- Prim is natural on dense adjacency-style input or when starting from one root feels more direct

## Canonical C++ Pattern

Template in this repo:

- [kruskal.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/kruskal.cpp)

Typical Kruskal structure:

1. sort edges by weight
2. initialize DSU
3. iterate edges
4. if endpoints are in different components, take the edge and unite them

## Standard Patterns

### 1. Cheapest Full Connection

The direct MST problem.

### 2. Connectivity Check Plus Minimum Cost

After running MST, verify you actually used `n - 1` edges or that all vertices ended in one component.

### 3. MST As A Subroutine

Examples:

- clustering by stopping early
- threshold questions on the MST edges
- “minimum maximum edge” style reformulations

## Worked Examples

### Example 1: cheapest network connection

Classic MST:

- use Kruskal if edges come as a flat list

### Example 2: detect whether a graph is fully connectable

Even if Kruskal runs, the graph may be disconnected.

So at the end:

- check that exactly `n - 1` edges were chosen
- or confirm one connected component remains

### Example 3: clustering by MST

Sometimes the true goal is not the whole tree, but the moment before the graph becomes one component, or the maximum edge used in the MST.

That is still an MST-flavored problem.

## Recognition Cues

Strong clues:

- undirected weighted graph
- connect everything as cheaply as possible
- build a backbone network
- no need for shortest paths between all pairs, only total connection cost

MST is often confused with:

- [Shortest Paths](../shortest-paths/README.md), because both use weighted graphs
- [DSU](../../data-structures/dsu/README.md), because DSU is the helper structure, not the algorithm itself

## Common Mistakes

- trying to use MST ideas on directed graphs
- forgetting to verify connectivity at the end
- confusing MST cost with shortest-path tree cost
- rebuilding DSU incorrectly between test cases

## Practice Ladder

- [MST ladder](../../../practice/ladders/graphs/mst/README.md)

Suggested order:

1. Kruskal on simple graphs
2. connectivity check after MST
3. compare Kruskal and Prim
4. solve one clustering or threshold variant

## Go Deeper

- Reference: [CP-Algorithms - Kruskal](https://cp-algorithms.com/graph/mst_kruskal.html)
- Reference: [CP-Algorithms - Prim](https://cp-algorithms.com/graph/mst_prim.html)
- Practice: [CSES Graph Algorithms](https://cses.fi/problemset/)
- Next step: [Trees](../trees/README.md)

## Related Topics

- [DSU](../../data-structures/dsu/README.md)
- [Graph Modeling](../graph-modeling/README.md)
- [Shortest Paths](../shortest-paths/README.md)
