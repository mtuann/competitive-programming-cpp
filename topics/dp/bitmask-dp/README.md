# Bitmask DP

Bitmask DP is the standard way to represent a small chosen set, visited set, or assignment state when `n` is small enough that `2^n` states are feasible.

## Summary

Suspect bitmask DP when:

- `n` is around `15` to `22`
- the state is “which items are already used?”
- you need Hamiltonian-style transitions, subset partitioning, or assignment DP

What success looks like:

- you can choose between `dp[mask]` and `dp[mask][last]`
- you can estimate `n * 2^n` quickly from the constraints
- you know when the state is too large and another idea is needed

## Prerequisites

- [DP Foundations](../foundations/README.md)
- [C++ Language For Contests](../../foundations/cpp-language/README.md)

## Core Idea

Encode a subset as an integer mask.

Typical state forms:

```text
dp[mask] = best answer for this chosen set
dp[mask][last] = best answer for this chosen set ending at last
```

This converts subset evolution into fast bit operations and overlapping subproblems over masks.

## Theory / Proof Sketch

The mask stores exactly the part of history that still matters:

- which items are already used
- optionally, one extra small parameter like the last chosen item

If every future decision depends only on that summary, the problem has the right subproblem structure for DP.

## Complexity And Tradeoffs

- number of states: `O(2^n)` or `O(n * 2^n)`
- transitions: often another factor of `n`

Tradeoffs:

- elegant and exact for small `n`
- impossible once `n` grows too large
- bit operations keep constant factors manageable, but the exponential wall is real

## Canonical C++ Pattern

Template in this repo:

- [bitmask-subset-iterate.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/bitmask-subset-iterate.cpp)

Common patterns:

- iterate all masks
- iterate candidate next bits
- update the larger mask

Useful bit tricks:

```text
mask & (1 << bit)        => test whether bit is present
mask | (1 << bit)        => add bit
mask ^ (1 << bit)        => toggle bit
mask & -mask             => lowest set bit
```

## Standard Patterns

### 1. Assignment DP

Each mask represents which jobs / positions are already used.

### 2. Hamiltonian-Style DP

State:

```text
dp[mask][last]
```

This is the standard route for TSP-like or path-cover-like small-`n` problems.

### 3. Subset Partitioning

Bitmask DP often appears when the set is small but grouping or partitioning choices are expensive to brute force directly.

## Worked Examples

### Example 1: traveling DP with `dp[mask][last]`

This is the canonical example:

- current set of visited nodes
- current endpoint

### Example 2: assignment DP

At step `k`, the mask records which targets have already been used.

### Example 3: subset compatibility DP

Precompute whether a subset is valid, then run DP over submasks or partitions.

## Recognition Cues

Strong clues:

- small `n`
- subsets or used / unused choices
- permutations or paths over all items
- state naturally looks like a boolean vector

Bitmask DP is often confused with:

- [Knapsack Family](../knapsack-family/README.md), because both can look like subset reasoning
- [BFS on states](../../graphs/bfs-dfs/README.md), because some small-state problems can be solved as state graphs instead

## Common Mistakes

- using `int` when `1 << n` overflows for large `n`
- forgetting whether transitions go from smaller masks to larger masks or the reverse
- storing more state than necessary and accidentally turning `O(n * 2^n)` into `O(n^2 * 2^n)` or worse

## Practice Ladder

- [Bitmask DP ladder](../../../practice/ladders/dp/bitmask-dp/README.md)

Suggested order:

1. subset iteration
2. assignment DP
3. `dp[mask][last]`
4. submask and partition variants

## Go Deeper

- Reference: [CP-Algorithms - Enumerating Submasks](https://cp-algorithms.com/algebra/all-submasks.html)
- Reference: [USACO Guide - Bitmask DP](https://usaco.guide/gold/dp-bitmasks)
- Practice: [AtCoder Educational DP Contest](https://atcoder.jp/contests/dp)

## Related Topics

- [Knapsack Family](../knapsack-family/README.md)
- [Tree DP](../tree-dp/README.md)
- [Graph Modeling](../../graphs/graph-modeling/README.md)
