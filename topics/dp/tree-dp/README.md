# Tree DP

Tree DP is the bridge between graph structure and dynamic programming. It appears whenever the graph is a tree and subtrees summarize the future cleanly.

## Prerequisites

- [DP Foundations](../foundations/README.md)
- [Trees](../../graphs/trees/README.md)

## When To Suspect It

- the input is a tree or becomes a rooted tree
- each node combines answers from its children
- the answer asks for counts, best values, or feasibility over connected structure

## Core Idea

Root the tree and define a state per node.

Typical forms:

```text
dp[u] = answer for the subtree of u
dp[u][take] = answer for subtree of u under one local choice
```

The merge step combines child summaries, and the parent only needs the merged result.

## Theory / Proof Sketch

Subtrees are independent once the parent-child boundary state is fixed. That is why rooted trees are so friendly to DP: each child contributes a summary that can be merged without revisiting the full subtree.

## Complexity And Tradeoffs

- simple subtree DP: often `O(n)`
- DP with multiple states or knapsack-style merges: `O(n * state)` or more

Tradeoffs:

- very powerful on trees
- easy to overcomplicate if the root state is not minimal

## Canonical Pattern

Use a DFS to process children before the parent.

Template in this repo:

- [tree-dp-subtree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/tree-dp-subtree.cpp)

## Worked Examples

Example 1: subtree sizes, sums, or counts

Example 2: take / skip node

Example 3: [VOSTRIP](../../../practice/ladders/graphs/tree-dp/vostrip.md)

## Common Mistakes

- forgetting to exclude the parent during DFS
- mixing "subtree answer" with "whole-tree answer" without rerooting
- defining too many local states before checking whether a simpler invariant works

## Practice Ladder

- [Tree DP ladder](../../../practice/ladders/dp/tree-dp/README.md)

## Go Deeper

- Reference: [USACO Guide - Tree DP](https://usaco.guide/gold/dp-trees)
- Reference: [CP-Algorithms - Tree Painting and Tree DP examples](https://cp-algorithms.com/graph/tree_painting.html)
- Practice: [VOSTRIP note](../../../practice/ladders/graphs/tree-dp/vostrip.md)

## Related Topics

- [Trees](../../graphs/trees/README.md)
- [Bitmask DP](../bitmask-dp/README.md)
- [Interval DP](../interval-dp/README.md)
