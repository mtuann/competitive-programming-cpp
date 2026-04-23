# Knapsack Family

Knapsack is the standard training ground for DP state design. It teaches transition direction, capacity states, and how small wording changes in the statement create different recurrences.

## Summary

Suspect knapsack when:

- each item can be taken zero, one, or many times
- there is a capacity, weight, volume, or budget
- the problem asks for maximum value, number of ways, or feasibility

What success looks like:

- you know which variant the statement is describing
- you can justify the capacity-loop direction
- you recognize when a problem is “knapsack in disguise”

## Prerequisites

- [DP Foundations](../foundations/README.md)

## Core Idea

Canonical compressed state:

```text
dp[j] = best answer for capacity j
```

Main variants:

- `0/1` knapsack
- complete knapsack
- bounded knapsack
- grouped or multiple-choice knapsack

The key idea is that iteration direction is part of the logic, not just an implementation detail.

## Theory / Proof Sketch

### `0/1` Knapsack

For each item:

```text
iterate capacity downward
```

Why:

- the current item must not be reused inside the same iteration

### Complete Knapsack

For each item:

```text
iterate capacity upward
```

Why:

- reuse of the current item is allowed

That simple change in direction is one of the most important DP lessons in the repo.

## Complexity And Tradeoffs

Classic complexity:

```text
O(n * capacity)
```

Tradeoffs:

- capacity-based DP is natural when capacity is moderate
- value-based or bitset variants may be better when capacity is large
- compression from 2D to 1D is common, but only when dependencies allow it

## Canonical C++ Pattern

Template in this repo:

- [knapsack-01.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/knapsack-01.cpp)

Useful rule:

- write the full 2D recurrence once on paper first
- compress to 1D only after you understand the dependence direction

## Standard Patterns

### 1. `0/1` Knapsack

Each item is used at most once.

### 2. Complete Knapsack

Each item may be used unlimited times.

### 3. Bounded Knapsack

Each item has a limited count.

### 4. Grouped / Multiple-Choice Knapsack

Choose at most one item from each group.

This is one of the most common “knapsack in disguise” variants.

## Worked Examples

### Example 1: `0/1` maximize value

Each item contributes once at most.

This is the canonical form.

### Example 2: subset sum as boolean DP

Now the DP stores feasibility instead of maximum value.

The state shape is the same, but the interpretation changes.

### Example 3: complete knapsack

The only change may be loop direction, but the meaning changes substantially because repeated use is now legal.

## Recognition Cues

Strong clues:

- capacity / budget / weight
- choose items under resource limits
- each item used zero, one, or many times
- maximize benefit or count feasible ways

Knapsack is often confused with:

- generic subset DP, because both may use capacities or sums
- greedy packing, when the real dependency still needs DP

## Common Mistakes

- wrong capacity iteration direction
- compressing dimensions before understanding the recurrence
- using `int` when counts or values overflow
- missing that grouped constraints change the whole transition logic

## Practice Ladder

- [Knapsack ladder](../../../practice/ladders/dp/knapsack-family/README.md)

Suggested order:

1. `0/1` knapsack
2. subset sum
3. complete knapsack
4. bounded / grouped variants

## Go Deeper

- Reference: [CP-Algorithms - Knapsack](https://cp-algorithms.com/dynamic_programming/knapsack.html)
- Reference: [OI Wiki - Knapsack](https://en.oi-wiki.org/dp/knapsack/)
- Practice: [AtCoder Educational DP Contest](https://atcoder.jp/contests/dp)
- Practice: [USACO Guide](https://usaco.guide/)

## Related Topics

- [DP Foundations](../foundations/README.md)
- [Bitmask DP](../bitmask-dp/README.md)
- [Modular Arithmetic](../../math/modular-arithmetic/README.md)
