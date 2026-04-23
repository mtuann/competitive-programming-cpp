# Maximum Flow

Maximum flow is the standard tool when the problem is really about sending as much quantity as possible through a network with capacities.

## Prerequisites

- [Graph Modeling](../graph-modeling/README.md)

## When To Suspect It

- capacities on edges or nodes
- send as much as possible from source to sink
- edge-disjoint or vertex-disjoint path reductions

## Core Idea

Build a residual graph and repeatedly push augmenting flow.

The canonical contest implementation is Dinic.

## Theory / Proof Sketch

Residual edges track how much more flow can be pushed or undone.

The max-flow min-cut theorem explains correctness:

- once no augmenting path remains, the current flow is maximum

## Complexity And Tradeoffs

Dinic is fast enough for a large range of contest problems and is the best default implementation to learn first.

## Canonical Pattern

Template in this repo:

- [dinic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dinic.cpp)

## Worked Examples

Example 1: classic max flow

Example 2: node splitting

Example 3: [FFLOW](../../../practice/ladders/graphs/flow/fflow.md)

## Common Mistakes

- forgetting reverse edges
- mis-modeling undirected capacities
- confusing flow value with the path-by-path decomposition

## Practice Ladder

- [Flow ladder](../../../practice/ladders/graphs/flow/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Dinic](https://cp-algorithms.com/graph/dinic.html)
- Practice: [FFLOW note](../../../practice/ladders/graphs/flow/fflow.md)

## Related Topics

- [Min-Cost Flow](../min-cost-flow/README.md)
- [Matching](../matching/README.md)
