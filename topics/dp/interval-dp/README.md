# Interval DP

Interval DP is the right tool when the problem is about subarrays, substrings, polygons, or parenthesization-style splits. The subproblem is literally “solve this interval.”

## Summary

Suspect interval DP when:

- the answer on `[l, r]` combines answers from smaller intervals
- the transition tries a split point `k`
- the structure resembles matrix-chain multiplication, bracket merging, or optimal partitioning on a line

What success looks like:

- you know the right interval meaning before writing loops
- you process intervals in a dependency-safe order
- you know when `O(n^3)` is acceptable and when optimization is needed

## Prerequisites

- [DP Foundations](../foundations/README.md)
- [Prefix Sums](../../foundations/patterns/prefix-sums/README.md)

## Core Idea

Define:

```text
dp[l][r] = answer for the interval [l, r]
```

Then process intervals by increasing length.

This is the interval analogue of prefix DP: smaller intervals must be solved before larger ones that depend on them.

## Theory / Proof Sketch

When an interval solution depends only on smaller nested intervals, processing by increasing length guarantees that all needed subproblems are already known.

Typical recurrence shape:

```text
dp[l][r] = best over split points k of combine(dp[l][k], dp[k+1][r], extra_cost)
```

The DP is correct if:

- every legal decomposition appears in the transition
- every smaller interval dependency is processed first

## Complexity And Tradeoffs

Common baseline:

```text
O(n^3)
```

Tradeoffs:

- clean when the dependency really stays inside the interval
- often too slow unless `n` is moderate or the transition has extra structure

This is where optimizations like Knuth or divide-and-conquer DP may appear later.

## Canonical C++ Pattern

Template in this repo:

- [interval-dp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/interval-dp.cpp)

Canonical loop order:

1. iterate interval length
2. iterate left endpoint
3. compute right endpoint
4. try split points

## Standard Patterns

### 1. Split-Point Optimization

Examples:

- matrix chain multiplication
- partitioning / triangulation style costs

### 2. Merge Or Remove On A Segment

Examples:

- remove boxes style logic
- merging items with local costs

### 3. String And Parenthesis Intervals

Examples:

- bracket matching style DP
- substring transformation costs

## Worked Examples

### Example 1: matrix chain multiplication

Classic interval DP:

- split at every `k`
- combine left and right costs

### Example 2: merge-cost intervals

The extra cost often depends on a precomputed interval sum, which is why prefix sums frequently pair with interval DP.

### Example 3: polygon triangulation style costs

The geometry story hides a pure interval split structure.

## Recognition Cues

Strong clues:

- intervals, substrings, or contiguous segments
- split point `k`
- recursive formulation over smaller intervals

Interval DP is often confused with:

- [Knapsack Family](../knapsack-family/README.md), because both can be `O(n^2)` or `O(n^3)` DP tables
- generic recursion, when the real reusable structure is specifically interval-based

## Common Mistakes

- wrong length order
- off-by-one errors in `l`, `r`, and split ranges
- forgetting to precompute interval sums or other static helpers
- using interval DP when the structure is not truly contiguous

## Practice Ladder

- [Interval DP ladder](../../../practice/ladders/dp/interval-dp/README.md)

Suggested order:

1. simple split DP
2. interval sums plus DP
3. bracket / substring interval logic
4. read optimization topics only after the baseline form is comfortable

## Go Deeper

- Reference: [CP-Algorithms - Knuth Optimization](https://cp-algorithms.com/dynamic_programming/knuth-optimization.html)
- Reference: [USACO Guide - Range DP](https://usaco.guide/gold/dp-ranges)
- Practice: [AtCoder Educational DP Contest](https://atcoder.jp/contests/dp)

## Related Topics

- [DP Foundations](../foundations/README.md)
- [Knapsack Family](../knapsack-family/README.md)
- [Prefix Sums](../../foundations/patterns/prefix-sums/README.md)
