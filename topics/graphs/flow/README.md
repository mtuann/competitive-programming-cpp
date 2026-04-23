# Maximum Flow

Maximum flow is the standard tool when the real problem is sending as much quantity as possible through a capacitated network. It is one of the most powerful reduction targets in competitive programming.

## Summary

Suspect maximum flow when:

- capacities exist on edges or nodes
- you want to send as much as possible from source to sink
- the statement hides edge-disjoint or vertex-disjoint path structure
- cuts, bottlenecks, or assignment with capacities appear naturally

What success looks like:

- you can model the network cleanly
- you understand residual graphs and reverse edges
- you know when Dinic is the right default implementation

## Prerequisites

- [Graph Modeling](../graph-modeling/README.md)

## Core Idea

Build a residual graph and repeatedly push augmenting flow.

The residual graph stores:

- how much more can still be sent
- how much previously sent flow can be undone

The standard contest default is Dinic:

- BFS builds a level graph
- DFS pushes blocking flow on that level graph

## Theory / Proof Sketch

Residual edges are the key invariant:

- every residual path from `s` to `t` represents additional flow that can still be sent

The max-flow min-cut theorem explains correctness:

- once no augmenting path remains, the current flow is maximum

Dinic improves the basic augmenting-path idea by pushing many augmenting paths through one level graph before rebuilding it.

## Complexity And Tradeoffs

Dinic is fast enough for a large range of contest problems and is the best first implementation to internalize.

Tradeoffs:

- much stronger modeling power than simpler graph traversals
- heavier implementation than BFS/DFS/Dijkstra
- often unnecessary if the graph has no real capacity structure

## Canonical C++ Pattern

Template in this repo:

- [dinic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dinic.cpp)

Core ingredients:

- forward and reverse edges
- level graph from BFS
- pointer / current-edge optimization in DFS

## Standard Patterns

### 1. Plain Max Flow

Source, sink, capacities, maximize throughput.

### 2. Edge-Disjoint Or Vertex-Disjoint Paths

Use capacities:

- edge-disjoint: capacity `1` on each edge
- vertex-disjoint: split each vertex into `in` and `out`

### 3. Capacity-Constrained Assignment

Some assignment problems are really flow with capacities rather than pure matching.

### 4. Min-Cut Interpretation

A max-flow solution also gives a minimum cut.

This is often the real object the statement is asking about in disguise.

## Worked Examples

### Example 1: classic max flow

The direct network-flow problem.

### Example 2: node splitting

When vertices, not edges, have capacity limits:

- split a vertex into `vin -> vout`
- put the vertex capacity on that internal edge

### Example 3: [FFLOW](../../../practice/ladders/graphs/flow/fflow.md)

This is a good repo example of the standard max-flow layer before moving into costed flow.

## Recognition Cues

Strong clues:

- capacities
- bottlenecks
- disjoint paths
- assignment with capacities
- min cut or cut-like interpretation

Flow is often confused with:

- [Matching](../matching/README.md), because some matching problems reduce to flow
- [Shortest Paths](../shortest-paths/README.md), because both live on weighted-looking graphs but solve different structural questions

## Common Mistakes

- forgetting reverse edges
- mis-modeling undirected capacities
- confusing flow value with one path decomposition
- not checking whether the problem really needs full flow machinery

## Practice Ladder

- [Flow ladder](../../../practice/ladders/graphs/flow/README.md)

Suggested order:

1. plain max flow
2. edge-disjoint / vertex-disjoint reductions
3. cut interpretation
4. compare flow with matching-style reductions

## Go Deeper

- Reference: [CP-Algorithms - Dinic](https://cp-algorithms.com/graph/dinic.html)
- Practice: [FFLOW note](../../../practice/ladders/graphs/flow/fflow.md)
- Practice: [MINCOST note](../../../practice/ladders/graphs/flow/mincost.md)
- Next step: [Min-Cost Flow](../min-cost-flow/README.md)

## Related Topics

- [Min-Cost Flow](../min-cost-flow/README.md)
- [Matching](../matching/README.md)
- [Graph Modeling](../graph-modeling/README.md)
