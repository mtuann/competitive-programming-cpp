# Knapsack Family

Knapsack is the standard training ground for DP state design. It teaches transition direction, capacity states, and how small changes in the problem statement change the recurrence.

## Prerequisites

- [DP Foundations](../foundations/README.md)

## When To Suspect It

- each item can be taken zero, one, or many times
- there is a capacity, weight, or budget
- the problem is about maximizing value, counting ways, or checking feasibility

## Core Idea

Canonical state:

```text
dp[j] = best answer for capacity j
```

Main variants:

- `0/1` knapsack
- complete knapsack
- bounded knapsack
- grouped or multiple-choice knapsack

The iteration order is part of the logic.

## Theory / Proof Sketch

`0/1` knapsack:

```text
for each item:
    iterate capacity downward
```

Complete knapsack:

```text
for each item:
    iterate capacity upward
```

The direction prevents illegal reuse or allows legal reuse exactly when intended.

## Complexity And Tradeoffs

- classic complexity: `O(n * capacity)`
- bitset or value-based variants may be better when capacities are large

## Canonical Pattern

Template in this repo:

- [knapsack-01.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/knapsack-01.cpp)

## Worked Examples

Example 1: `0/1` maximize value

Example 2: subset sum as boolean DP

Example 3: complete knapsack with unlimited copies

## Common Mistakes

- wrong capacity iteration direction
- using `int` when values or counts overflow
- compressing dimensions before understanding the full recurrence

## Practice Ladder

- [Knapsack ladder](../../../practice/ladders/dp/knapsack-family/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Knapsack](https://cp-algorithms.com/dynamic_programming/knapsack.html)
- Reference: [OI Wiki - Knapsack](https://en.oi-wiki.org/dp/knapsack/)
- Practice: [AtCoder Educational DP Contest](https://atcoder.jp/contests/dp)

## Related Topics

- [DP Foundations](../foundations/README.md)
- [Modular Arithmetic](../../math/modular-arithmetic/README.md)
