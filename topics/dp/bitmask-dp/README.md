# Bitmask DP

Bitmask DP is the standard way to represent a small chosen set, visited set, or assignment state when `n` is small enough for `2^n` states.

## Prerequisites

- [DP Foundations](../foundations/README.md)
- [C++ Language For Contests](../../foundations/cpp-language/README.md)

## When To Suspect It

- `n` is around `15` to `22`
- the state is "which items are already used?"
- you need Hamiltonian-style transitions, subset counting, or assignment DP

## Core Idea

Encode a subset by an integer mask.

Typical state forms:

```text
dp[mask] = best answer for this chosen set
dp[mask][last] = best answer for this chosen set ending at last
```

This turns subset evolution into fast bit operations.

## Theory / Proof Sketch

The mask stores exactly the information needed for future choices: which options remain available. If the next transition depends only on the current chosen set and a small extra parameter such as `last`, then the problem has overlapping subproblems over masks.

## Complexity And Tradeoffs

- number of states: `O(2^n)` or `O(n * 2^n)`
- transitions: often another factor of `n`

Tradeoffs:

- elegant and exact for small `n`
- impossible once `n` grows too large
- bit operations keep the constant factors manageable

## Canonical Pattern

Start with:

- iterate all masks
- iterate candidate next bits
- update the larger mask

Template in this repo:

- [bitmask-subset-iterate.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/bitmask-subset-iterate.cpp)

## Worked Examples

Example 1: traveling DP with `dp[mask][last]`

Example 2: assignment DP

Example 3: subset partition or compatibility DP

## Common Mistakes

- using `int` when `1 << n` overflows for `n >= 31`
- forgetting the iteration order for transitions from smaller masks to larger masks
- storing more state than necessary and making `O(n^2 * 2^n)` when `O(n * 2^n)` is enough

## Practice Ladder

- [Bitmask DP ladder](../../../practice/ladders/dp/bitmask-dp/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Enumerating Submasks](https://cp-algorithms.com/algebra/all-submasks.html)
- Reference: [USACO Guide - Bitmask DP](https://usaco.guide/gold/dp-bitmasks)
- Practice: [AtCoder Educational DP Contest](https://atcoder.jp/contests/dp)

## Related Topics

- [Knapsack Family](../knapsack-family/README.md)
- [Tree DP](../tree-dp/README.md)
