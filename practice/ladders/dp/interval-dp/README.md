# Interval DP Ladder

This ladder should make interval-based recurrences feel systematic instead of like a pile of index tricks.

## Who This Is For

Use this ladder if:

- you see `dp[l][r]`, but still get lost in loop order
- split-point transitions still feel ad hoc
- you want stronger instinct for when interval DP is the right abstraction

## Warm-Up

- matrix-chain style transitions
- simple merge-cost intervals

Target skill:

- process intervals by increasing length without index bugs

## Core

- `dp[l][r]`
- increasing length order
- split-point transitions

Target skill:

- express the interval recurrence before worrying about optimizations

## Stretch

- [Knuth Optimization](../../../../topics/dp/knuth-optimization/README.md)
- [Divide and Conquer DP](../../../../topics/dp/divide-and-conquer-dp/README.md)
- connect interval DP with prefix-sum precomputations

Target skill:

- know when the baseline `O(n^3)` form is acceptable and when it needs help

## Exit Criteria

You are ready to move on when:

- you can write the loop order from memory
- you can justify the split range for `k`
- you know when interval sums or static helpers should be precomputed first

## External Practice

- [USACO Guide - Range DP](https://usaco.guide/gold/dp-ranges)
- [AtCoder Educational DP Contest](https://atcoder.jp/contests/dp)
- [CP-Algorithms - Knuth Optimization](https://cp-algorithms.com/dynamic_programming/knuth-optimization.html)

## Tutorial Link

- [Interval DP](../../../../topics/dp/interval-dp/README.md)
- [Knuth Optimization](../../../../topics/dp/knuth-optimization/README.md)
