# Interval DP

Interval DP is the right tool when the problem is about subarrays, substrings, or polygon/parenthesization-style splits.

## Prerequisites

- [DP Foundations](../foundations/README.md)
- [Prefix Sums](../../foundations/patterns/prefix-sums/README.md)

## When To Suspect It

- the answer for `[l, r]` combines answers from smaller intervals
- the transition tries a split point `k`
- the structure resembles matrix chain multiplication, bracket merging, or optimal partitioning on a line

## Core Idea

Define:

```text
dp[l][r] = answer for the interval [l, r]
```

Then process intervals by increasing length.

## Theory / Proof Sketch

When an interval solution depends only on smaller nested intervals, increasing length order guarantees those smaller answers are already known. This is the interval analogue of prefix DP.

## Complexity And Tradeoffs

- common baseline: `O(n^3)`
- some variants improve with problem-specific structure

Tradeoffs:

- clean when the dependency truly stays inside the interval
- often too slow unless `n` is moderate or the transition is optimized

## Canonical Pattern

Loop over `len`, then `l`, compute `r`, then try split positions.

Template in this repo:

- [interval-dp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/interval-dp.cpp)

## Worked Examples

Example 1: matrix chain multiplication

Example 2: remove or merge items on a segment

Example 3: polygon triangulation style costs

## Common Mistakes

- wrong length order
- off-by-one errors for `l`, `r`, and split ranges
- forgetting to precompute fast interval values such as sums

## Practice Ladder

- [Interval DP ladder](../../../practice/ladders/dp/interval-dp/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Knuth Optimization](https://cp-algorithms.com/dynamic_programming/knuth-optimization.html)
- Reference: [USACO Guide - Range DP](https://usaco.guide/gold/dp-ranges)
- Practice: [AtCoder Educational DP Contest](https://atcoder.jp/contests/dp)

## Related Topics

- [DP Foundations](../foundations/README.md)
- [Knapsack Family](../knapsack-family/README.md)
