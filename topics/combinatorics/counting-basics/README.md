# Counting Basics

Counting basics is where many combinatorics problems should start. Before reaching for heavier formulas, check whether the object can be built as a clean sequence of independent choices.

## Prerequisites

- [Modular Arithmetic](../../math/modular-arithmetic/README.md)
- [Reasoning And Proof Habits](../../foundations/reasoning/README.md)

## When To Suspect It

- the problem asks "how many?"
- the object can be built step by step
- the main issue is choosing the right decomposition, not advanced algebra
- a small amount of clean casework seems more natural than DP

## Core Idea

Use the multiplication and addition principles carefully.

Standard building blocks:

- ordered selections
- unordered selections
- permutations
- combinations
- stars and bars
- splitting by a first special event
- complementary counting

## Theory / Proof Sketch

The art is not memorizing formulas. It is identifying whether two construction paths count disjoint sets, the same set, or the same set multiple times.

Typical rules:

```text
sum: combine disjoint cases
product: combine independent choices
```

The most useful question is:

```text
What is the exact combinatorial object, and how can I build it once?
```

If you can describe a construction that maps bijectively to the answer set, the formula usually falls out naturally.

## Complexity And Tradeoffs

- often `O(1)` or `O(n)` once the formula is known
- the hard part is modeling, not runtime

Tradeoffs:

- direct constructive counting is often cleaner than inclusion-exclusion
- formula-heavy solutions are fast but easy to get subtly wrong
- brute force on tiny cases is extremely helpful for validating a counting argument

## Canonical Pattern

Write:

1. what object is being counted
2. one construction
3. why each object is counted exactly once
4. whether order matters
5. whether repetition is allowed

## Worked Examples

Example 1: choose positions then fill values

If you want binary strings of length `n` with exactly `k` ones:

```text
choose the k positions of the ones
answer = C(n, k)
```

Example 2: count runs of colors

This pattern appears in fence, strip, and coloring problems. First decide the run lengths, then decide the colors or transitions.

Example 3: reduce a distribution problem to stars and bars

If:

```text
x1 + x2 + ... + xm = s
xi >= 0
```

then the count is:

```text
C(s + m - 1, m - 1)
```

This formula is only correct after you verify the variables really are indistinguishable units separated into ordered bins.

## Recognition Cues

- the statement asks "how many" but constraints are too small to justify heavy machinery
- objects can be built left to right, slot by slot, or run by run
- order / repetition / adjacency are the real decisions
- you can partition the answer into a few disjoint structural cases

## Common Mistakes

- multiplying when the cases are not independent
- adding cases that overlap
- forgetting whether order matters
- using stars and bars when lower/upper bounds are not handled correctly
- treating "choose positions" and "assign labels" as the same step
- not checking tiny cases by hand before trusting the formula

## Standard Variants

- choose positions then fill values
- split by first / last special event
- count by number of runs or transitions
- complementary counting
- bounded distributions that later lead into inclusion-exclusion or DP

## Practice Ladder

- [Counting basics ladder](../../../practice/ladders/combinatorics/counting-basics/README.md)

## Repo Anchors

- [Distributing Apples](../../../practice/ladders/combinatorics/counting-basics/distributingapples.md): the standard stars-and-bars model with one modular binomial answer.

## Go Deeper

- Course notes: [Stanford CS103 combinatorics notes](https://web.stanford.edu/class/archive/cs/cs103/cs103.1254/)
- Reference: [CP-Algorithms - Binomial Coefficients](https://cp-algorithms.com/combinatorics/binomial-coefficients.html)
- Reference: [USACO Guide - Intro to Combinatorics](https://usaco.guide/gold/combo)
- Blog/reference: [Brilliant - Stars and Bars](https://brilliant.org/wiki/integer-equations-star-and-bars/)
- Practice: [CSES Mathematics](https://cses.fi/problemset/list/)

## Related Topics

- [Bounded Compositions](../bounded-compositions/README.md)
- [Inclusion-Exclusion](../inclusion-exclusion/README.md)
