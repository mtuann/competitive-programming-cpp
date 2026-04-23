# Tree DP

Tree DP is the bridge between graph structure and dynamic programming. It appears whenever the input is a tree and subtrees summarize the future cleanly.

## Summary

Suspect tree DP when:

- the input is a tree or can be rooted as one
- each node combines information from its children
- the answer asks for counts, best values, or feasibility over connected structure

What success looks like:

- you can define the subtree state precisely
- you know when child contributions are independent
- you can separate subtree DP from rerooting or all-tree answers

## Prerequisites

- [DP Foundations](../foundations/README.md)
- [Trees](../../graphs/trees/README.md)

## Core Idea

Root the tree and define a state per node.

Typical forms:

```text
dp[u] = answer for the subtree of u
dp[u][take] = answer for subtree of u under one local choice
```

The merge step combines child summaries, and the parent only needs the merged result.

## Theory / Proof Sketch

Subtrees are independent once the parent-child boundary state is fixed.

That is why rooted trees are so friendly to DP:

- each child contributes a summary
- the parent merges those summaries
- no child subtree needs to be revisited in full

The proof style is induction over subtree size or DFS order.

## Complexity And Tradeoffs

- simple subtree DP: often `O(n)`
- DP with several local states: `O(n * state)`
- knapsack-style child merges can be heavier

Tradeoffs:

- very powerful on trees
- easy to overcomplicate if the root state is not minimal
- sometimes a simple traversal invariant is enough and full DP is unnecessary

## Canonical C++ Pattern

Template in this repo:

- [tree-dp-subtree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/tree-dp-subtree.cpp)

Standard workflow:

1. root the tree
2. DFS children first
3. merge child answers into the node state

## Standard Patterns

### 1. Subtree Aggregation

Examples:

- subtree sums
- subtree counts
- best value in a subtree

### 2. Take / Skip States

Examples:

- independent-set style tree problems
- choose or do not choose the current node

### 3. Rerooting Later

Some problems first compute subtree answers, then need whole-tree answers for every root. That is a next step after basic tree DP.

## Worked Examples

### Example 1: subtree sizes, sums, or counts

The lightest tree DP form:

```text
dp[u] = combine(dp[child_1], dp[child_2], ...)
```

### Example 2: take / skip node

State:

```text
dp[u][0], dp[u][1]
```

This is a classic first nontrivial tree DP pattern.

### Example 3: [VOSTRIP](../../../practice/ladders/graphs/tree-dp/vostrip.md)

This is a strong repo example where tree structure and DP-style local aggregation interact.

## Recognition Cues

Strong clues:

- rooted tree language
- child contributions combine independently
- path uniqueness makes subtree summaries meaningful

Tree DP is often confused with:

- plain tree traversal, when the real problem only needs one aggregate
- rerooting, which is a later extension rather than the default first move

## Common Mistakes

- forgetting to exclude the parent during DFS
- mixing “subtree answer” with “whole-tree answer”
- defining too many local states before checking whether a simpler invariant works

## Practice Ladder

- [Tree DP ladder](../../../practice/ladders/dp/tree-dp/README.md)

Suggested order:

1. subtree aggregations
2. take / skip states
3. child-merge reasoning
4. stretch examples with richer local constraints

## Go Deeper

- Reference: [USACO Guide - Tree DP](https://usaco.guide/gold/dp-trees)
- Reference: [CP-Algorithms - Tree Painting and Tree DP examples](https://cp-algorithms.com/graph/tree_painting.html)
- Practice: [VOSTRIP note](../../../practice/ladders/graphs/tree-dp/vostrip.md)

## Related Topics

- [Trees](../../graphs/trees/README.md)
- [Bitmask DP](../bitmask-dp/README.md)
- [Interval DP](../interval-dp/README.md)
