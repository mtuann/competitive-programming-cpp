# Sorting

Sorting is one of the most common “hidden preprocess” moves in competitive programming. Many greedy, sweep-line, and binary-search solutions only become visible after the data is ordered.

## Prerequisites

- [C++ Language For Contests](../../cpp-language/README.md)
- [Reasoning And Implementation Discipline](../../reasoning/README.md)

## When To Suspect It

- you only care about relative order
- nearby or consecutive elements matter after ordering
- the proof sounds like “take the smallest first” or “after sorting by x”
- you want to turn a hard search into a monotone pass

## Core Idea

Sorting creates structure:

- monotonicity
- adjacency relationships
- a consistent order for greedy decisions

Many problems are really:

1. sort the data
2. scan once or twice
3. maintain a small invariant

## Theory / Proof Sketch

The most common proof tool after sorting is an exchange argument.

Typical pattern:

- take any optimal solution
- show that swapping an inversion or reordering one pair never hurts
- conclude that some sorted order is compatible with optimality

## Complexity And Tradeoffs

- standard comparison sort: `O(n log n)`
- memory depends on the container and implementation

Tradeoffs:

- `sort` is the default
- `stable_sort` is only needed when preserving equal-key order matters
- custom comparators should define a strict weak ordering

## Canonical C++ Pattern

- store records as `pair` or `struct`
- sort by the main key
- break ties explicitly if the problem needs a deterministic order

Template in this repo:

- [sort-and-comparator.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/sort-and-comparator.cpp)

## Worked Examples

Example 1: interval scheduling

- sort by ending time
- greedily take the earliest finishing compatible interval

Example 2: closest values after sorting

- after sorting, the best adjacent pair is often enough to inspect

Example 3: sweeping events

- sort all events by position or time
- process them in order with one active structure

## Common Mistakes

- forgetting to define tie behavior
- using `stable_sort` when regular `sort` is enough
- writing a comparator that is inconsistent
- sorting too late, after already building the wrong model

## Practice Ladder

- [Sorting ladder](../../../../practice/ladders/foundations/sorting/README.md)

## Go Deeper

- Course: [Princeton COS 226](https://www.cs.princeton.edu/~cos226)
- Reference: [CP-Algorithms](https://cp-algorithms.com/)
- Practice: [CSES Sorting and Searching](https://cses.fi/problemset/)

## Related Topics

- [Binary Search](../binary-search/README.md)
- [Two Pointers](../two-pointers/README.md)
- [Graph Modeling](../../../graphs/graph-modeling/README.md)
