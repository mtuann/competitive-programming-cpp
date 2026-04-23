# DP Foundations

Dynamic programming starts when you can describe exactly what information from the past still matters.

## Prerequisites

- [Reasoning And Implementation Discipline](../../foundations/reasoning/README.md)

## When To Suspect It

- the problem has overlapping subproblems
- greedy feels unsafe
- the answer can be built from smaller prefixes, suffixes, subsets, or subtrees

## Core Idea

A good DP state answers:

1. what has already been decided?
2. what still matters for the future?
3. what transition choices exist next?

Typical first forms:

- prefix DP
- last-choice DP
- counting DP
- optimization DP

## Theory / Proof Sketch

DP is correct when:

- the state captures all relevant history
- transitions cover all legal next steps
- no state depends on future information it does not store

Write the state meaning first. Then write transitions.

## Complexity And Tradeoffs

Estimate:

```text
number of states * transitions per state
```

Also decide:

- top-down vs bottom-up
- whether reconstruction is needed
- whether memory compression is safe

## Canonical Pattern

Useful checklist:

- exact state meaning
- base case
- transition formula
- iteration order
- answer location

Notebook:

- [DP cheatsheet](../../../notebook/dp-cheatsheet.md)

## Worked Examples

Example 1: maximum sum over prefixes

- one-dimensional optimization DP

Example 2: count ways to reach sum `S`

- one-dimensional counting DP

Example 3: stretch example

- [TFIELD](../../../practice/ladders/dp/sliding-window/tfield.md) is a later example of turning a structured optimization into a compact state process

## Common Mistakes

- state is too vague
- transition double-counts or misses cases
- iteration order breaks dependencies
- memory compression is applied before correctness is stable

## Practice Ladder

- [DP foundations ladder](../../../practice/ladders/dp/foundations/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Intro to DP](https://cp-algorithms.com/dynamic_programming/intro-to-dp.html)
- Practice: [AtCoder Educational DP Contest](https://atcoder.jp/contests/dp)
- Practice: [USACO Guide](https://usaco.guide/)

## Related Topics

- [Knapsack Family](../knapsack-family/README.md)
- [VOSTRIP note](../../../practice/ladders/graphs/tree-dp/vostrip.md)
