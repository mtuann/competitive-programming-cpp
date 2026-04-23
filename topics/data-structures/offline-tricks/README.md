# Offline Tricks

Offline techniques reorder work so a hard online problem becomes a simpler sort, sweep, or divide-and-conquer pass. They are some of the highest-ROI modeling tools in the repo because they often replace heavy dynamic structures with much lighter ones.

## Summary

Suspect offline tricks when:

- all queries are known in advance
- online maintenance looks awkward or expensive
- sorting by one coordinate, threshold, or endpoint would simplify the state

What success looks like:

- you can decide when query order does not matter
- you can sweep in a monotone direction and answer queries when their prerequisites are ready
- you can restore answers to the original query order at the end

## Prerequisites

- [Fenwick Tree](../fenwick-tree/README.md)
- [DSU](../dsu/README.md)
- [Sorting](../../foundations/patterns/sorting/README.md)

## Core Idea

“Offline” means:

- you know the whole input first
- you may reorder computation
- you still output answers in original query order later

Typical offline patterns:

- sort queries by right endpoint
- sort edges by threshold
- process events left to right
- batch many decision problems together

## Theory / Proof Sketch

Correctness usually comes from a monotone sweep invariant.

Typical shape:

```text
After processing all events up to x,
the data structure exactly represents everything relevant up to x.
```

Then:

- answer each query when the sweep has processed all data that should affect it
- store the answer in the query’s original index

This makes the reordered computation equivalent to the original online question set.

## Complexity And Tradeoffs

Offline methods often trade:

- more modeling work
- for much simpler dynamic state

Common benefits:

- replacing a segment tree with Fenwick
- replacing online connectivity with sorted DSU merges
- using one global sort instead of many local updates

## Canonical C++ Pattern

Template in this repo:

- [offline-query-skeleton.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/offline-query-skeleton.cpp)

Standard ingredients:

- attach an original index to each query
- sort events and queries by the sweep key
- process in monotone order
- write answers back by original index

## Standard Patterns

### 1. Queries Sorted By Right Endpoint

Examples:

- count distinct values in ranges
- prefix-constrained counting
- Fenwick-assisted offline interval answers

### 2. Threshold Connectivity With DSU

Examples:

- edges become active when weight `<= x`
- process queries sorted by threshold
- unite edges as they become available

### 3. Parallel Binary Search And Mo's Algorithm

These are more advanced offline techniques. They belong to the same mindset:

- batch work
- reorder computation
- reduce online complexity

## Worked Examples

### Example 1: range queries by right endpoint

Sort queries by `r`.

Sweep from left to right, updating a Fenwick tree or other structure as elements become active.

Answer each query once the sweep reaches its right endpoint.

### Example 2: threshold connectivity

Sort edges by weight and queries by threshold.

As the threshold grows:

- unite all edges now allowed
- answer whether endpoints lie in the same component

This is much simpler than trying to maintain fully dynamic connectivity online.

### Example 3: restoring original order

Even after reordering queries for processing, the output is correct because each answer is stored with its original index.

That bookkeeping step is part of the algorithm, not an afterthought.

## Recognition Cues

Strong clues:

- all queries are given before any output
- sorting by one key seems to make updates monotone
- the online version feels much harder than the actual intended difficulty

Offline tricks are often confused with:

- [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md), because both manage evolving state
- [Graph Modeling](../../graphs/graph-modeling/README.md), because offline processing often starts from a model cleanup

## Common Mistakes

- forgetting to restore original query order
- processing events and queries in the wrong order at equal coordinates or thresholds
- using a heavy dynamic structure when a sorted sweep would do
- assuming every query problem can be reordered safely

## Practice Ladder

- [Offline tricks ladder](../../../practice/ladders/data-structures/offline-tricks/README.md)

Suggested order:

1. offline sort by endpoint
2. threshold queries with DSU
3. BIT-assisted offline counting
4. read about Mo’s algorithm and parallel binary search after the basics feel natural

## Go Deeper

- Reference: [CP-Algorithms](https://cp-algorithms.com/)
- Practice: [USACO Guide](https://usaco.guide/)
- Next step: [Graph Modeling](../../graphs/graph-modeling/README.md)

## Related Topics

- [Fenwick Tree](../fenwick-tree/README.md)
- [DSU](../dsu/README.md)
- [Sorting](../../foundations/patterns/sorting/README.md)
- [Graph Modeling](../../graphs/graph-modeling/README.md)
