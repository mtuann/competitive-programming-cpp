# Counting Basics

Counting basics is where many combinatorics problems should start. Before reaching for heavier formulas, check whether the object can be built as a clean sequence of independent choices.

## Prerequisites

- [Modular Arithmetic](../../math/modular-arithmetic/README.md)
- [Reasoning And Proof Habits](../../foundations/reasoning/README.md)

## When To Suspect It

- the problem asks "how many?"
- the object can be built step by step
- the main issue is choosing the right decomposition, not advanced algebra

## Core Idea

Use the multiplication and addition principles carefully.

Standard building blocks:

- ordered selections
- unordered selections
- permutations
- combinations
- stars and bars
- splitting by a first special event

## Theory / Proof Sketch

The art is not memorizing formulas. It is identifying whether two construction paths count disjoint sets, the same set, or the same set multiple times.

Typical rules:

```text
sum: combine disjoint cases
product: combine independent choices
```

## Complexity And Tradeoffs

- often `O(1)` or `O(n)` once the formula is known
- the hard part is modeling, not runtime

## Canonical Pattern

Write:

1. what object is being counted
2. one construction
3. why each object is counted exactly once

## Worked Examples

Example 1: choose positions then fill values

Example 2: count runs of colors

Example 3: reduce a distribution problem to stars and bars

## Common Mistakes

- multiplying when the cases are not independent
- adding cases that overlap
- forgetting whether order matters

## Practice Ladder

- [Counting basics ladder](../../../practice/ladders/combinatorics/counting-basics/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Binomial Coefficients](https://cp-algorithms.com/combinatorics/binomial-coefficients.html)
- Reference: [USACO Guide - Intro to Combinatorics](https://usaco.guide/gold/combo)
- Practice: [CSES Mathematics](https://cses.fi/problemset/list/)

## Related Topics

- [Bounded Compositions](../bounded-compositions/README.md)
- [Inclusion-Exclusion](../inclusion-exclusion/README.md)
