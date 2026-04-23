# Offline Tricks

Offline techniques reorder work so a hard online problem becomes a simpler sweep, sort, or divide-and-conquer pass.

## Prerequisites

- [Fenwick Tree](../fenwick-tree/README.md)
- [DSU](../dsu/README.md)
- [Sorting](../../foundations/patterns/sorting/README.md)

## When To Suspect It

- all queries are known in advance
- online maintenance looks hard
- sorting events or processing by one coordinate would simplify the logic

## Core Idea

“Offline” means:

- you are allowed to reorder computation
- you still return answers in original query order later

Typical patterns:

- sort queries by right endpoint
- sort edges by threshold
- process events left to right

## Theory / Proof Sketch

Correctness usually comes from one monotone sweep invariant:

- after processing all events up to position `x`, the data structure exactly represents everything relevant up to `x`

If each query is answered when its prerequisites are fully processed, the reordered pass is equivalent to the original set of queries.

## Complexity And Tradeoffs

Offline methods often trade:

- harder modeling
- for much simpler data structures

## Canonical Pattern

Template in this repo:

- [offline-query-skeleton.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/offline-query-skeleton.cpp)

## Worked Examples

Example 1: answer range queries by right endpoint with Fenwick

Example 2: threshold connectivity with DSU

Example 3: parallel binary search or Mo’s algorithm as later extensions

## Common Mistakes

- forgetting to restore original query order
- processing events and queries in the wrong order at equal coordinates
- using a heavy dynamic structure when an offline sweep would do

## Practice Ladder

- [Offline tricks ladder](../../../practice/ladders/data-structures/offline-tricks/README.md)

## Go Deeper

- Reference: [CP-Algorithms](https://cp-algorithms.com/)
- Practice: [USACO Guide](https://usaco.guide/)

## Related Topics

- [Fenwick Tree](../fenwick-tree/README.md)
- [DSU](../dsu/README.md)
- [Graph Modeling](../../graphs/graph-modeling/README.md)
