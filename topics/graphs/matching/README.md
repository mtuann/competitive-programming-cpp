# Matching

Matching is about selecting edges that do not share endpoints. It is one of the cleanest modeling tools for pairing problems.

## Prerequisites

- [Graph Modeling](../graph-modeling/README.md)
- [Maximum Flow](../flow/README.md)

## When To Suspect It

- pair people, jobs, objects, or states
- each vertex can be used only once
- choose the largest or cheapest compatible pairing

## Core Idea

Learn in layers:

- bipartite matching first
- weighted or flow-based reductions later
- general graph matching last

## Theory / Proof Sketch

In bipartite matching, augmenting paths improve the current solution by one edge.

For general graphs, blossoms are the key obstacle; Edmonds’ blossom algorithm handles odd cycles correctly.

## Complexity And Tradeoffs

- bipartite matching is much easier than general matching
- learn Hopcroft-Karp before blossom

## Canonical Pattern

Template in this repo:

- [hopcroft-karp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hopcroft-karp.cpp)

## Worked Examples

Example 1: assign jobs to people

Example 2: bipartite graph maximum matching

Example 3: [QBFLOWER](../../../practice/ladders/graphs/matching/qbflower.md) as a stretch example of general matching and edge cover

## Common Mistakes

- jumping to blossom before confirming the graph is not bipartite
- forgetting the difference between matching and edge cover
- modeling capacities with matching when flow would be more natural

## Practice Ladder

- [Matching ladder](../../../practice/ladders/graphs/matching/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Kuhn / Bipartite Matching](https://cp-algorithms.com/graph/kuhn_maximum_bipartite_matching.html)
- Practice: [QBFLOWER note](../../../practice/ladders/graphs/matching/qbflower.md)

## Related Topics

- [Maximum Flow](../flow/README.md)
- [Min-Cost Flow](../min-cost-flow/README.md)
