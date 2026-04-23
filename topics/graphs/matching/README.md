# Matching

Matching is about selecting edges that do not share endpoints. It is one of the cleanest modeling tools for pairing problems and one of the most common places where graph modeling directly determines the algorithm.

## Summary

Suspect matching when:

- you must pair people, jobs, objects, or states
- each vertex can be used at most once
- you want the largest or cheapest compatible pairing

What success looks like:

- you can tell whether the graph is bipartite before choosing an algorithm
- you know that bipartite matching comes first, general matching later
- you can distinguish matching from related ideas like edge cover or flow with capacities

## Prerequisites

- [Graph Modeling](../graph-modeling/README.md)
- [Maximum Flow](../flow/README.md)

## Core Idea

Learn matching in layers:

- bipartite matching first
- weighted or flow-based reductions later
- general graph matching last

The central idea is augmenting paths:

- if you can find an alternating path from a free left node to a free right node, you can increase the matching size by one

## Theory / Proof Sketch

### Bipartite Matching

An augmenting path improves the current matching by one edge:

- matched edges on the path become unmatched
- unmatched edges on the path become matched

This preserves the matching property while increasing its size.

### General Matching

Odd cycles break the clean bipartite augmenting-path picture.

Blossom algorithms handle those obstacles, but they are much more advanced than Hopcroft-Karp and should come later.

## Complexity And Tradeoffs

Tradeoffs:

- bipartite matching is much easier than general matching
- Hopcroft-Karp is the right first serious implementation
- sometimes a flow model is easier if capacities beyond `1` appear naturally

## Canonical C++ Pattern

Template in this repo:

- [hopcroft-karp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hopcroft-karp.cpp)

Standard bipartite modeling:

- left part
- right part
- edges only across the partition

## Standard Patterns

### 1. Maximum Bipartite Matching

Classic form:

- people to jobs
- students to projects
- rows to columns

### 2. Matching As A Reduction Target

Some problems are not phrased as pairing, but after modeling they become a clean bipartite graph.

### 3. Matching Vs Flow

If every choice is capacity `1`, matching is often the clean model.

If capacities or multiple units matter, flow may be more natural.

### 4. Matching Vs Edge Cover

These are related but not the same.

The [QBFLOWER](../../../practice/ladders/graphs/matching/qbflower.md) note is a good example where general matching appears through minimum edge cover reasoning.

## Worked Examples

### Example 1: assign jobs to people

Vertices:

- people on the left
- jobs on the right

Edges:

- person can do job

Then maximum matching is the maximum number of assignments.

### Example 2: bipartite graph maximum matching

This is the direct textbook form and the best place to internalize augmenting paths or Hopcroft-Karp.

### Example 3: [QBFLOWER](../../../practice/ladders/graphs/matching/qbflower.md)

This is a strong stretch example because the statement is not phrased as “find a matching”, but matching still drives the solution through graph-theory structure.

## Recognition Cues

Strong clues:

- pairings with exclusivity
- one item can be used at most once
- compatibility edges between two groups
- choose maximum number of non-conflicting pairings

Matching is often confused with:

- [Flow](../flow/README.md), because flow can solve bipartite matching too
- edge cover, because the graph-theory formulas can be nearby

## Common Mistakes

- jumping to blossom before checking bipartiteness
- forgetting the difference between matching and edge cover
- using flow when plain matching is simpler
- forcing a matching model when capacities larger than `1` are essential

## Practice Ladder

- [Matching ladder](../../../practice/ladders/graphs/matching/README.md)

Suggested order:

1. bipartite modeling
2. augmenting-path intuition
3. Hopcroft-Karp
4. matching reductions and edge-cover relationships

## Go Deeper

- Reference: [CP-Algorithms - Kuhn / Bipartite Matching](https://cp-algorithms.com/graph/kuhn_maximum_bipartite_matching.html)
- Reference: [CP-Algorithms - Hopcroft-Karp](https://cp-algorithms.com/graph/kuhn_maximum_bipartite_matching.html)
- Practice: [QBFLOWER note](../../../practice/ladders/graphs/matching/qbflower.md)
- Next step: [Maximum Flow](../flow/README.md)

## Related Topics

- [Maximum Flow](../flow/README.md)
- [Min-Cost Flow](../min-cost-flow/README.md)
- [Graph Modeling](../graph-modeling/README.md)
