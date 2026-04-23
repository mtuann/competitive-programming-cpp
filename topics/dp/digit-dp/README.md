# Digit DP

Digit DP is the standard counting tool when a constraint is stated over decimal representation and the bound can be processed digit by digit.

## Prerequisites

- [DP Foundations](../foundations/README.md)
- [Modular Arithmetic](../../math/modular-arithmetic/README.md)

## When To Suspect It

- the problem asks to count numbers in `[0, x]` or `[l, r]`
- the property depends on digits, digit sum, adjacent digits, or automaton-like restrictions
- brute force over all values is impossible but the decimal structure is small

## Core Idea

Build the number from left to right with a tight flag.

Typical state:

```text
dp[pos][tight][started][other_state]
```

Where `other_state` might be:

- digit sum
- remainder modulo `m`
- previous digit
- automaton state

## Theory / Proof Sketch

At each position, the only information that matters for future digits is:

- whether we are still equal to the upper bound
- whether the number has started
- the small summary needed by the property

That creates overlapping subproblems across prefixes of the decimal string.

## Complexity And Tradeoffs

- roughly `digits * states * alphabet`
- usually very manageable because digits are at most around `19` for `long long`

Tradeoffs:

- ideal for digit-defined properties
- unnatural if the property is not actually representation-based

## Canonical Pattern

Memoized DFS or iterative DP over positions.

Template in this repo:

- [digit-dp-skeleton.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/digit-dp-skeleton.cpp)

## Worked Examples

Example 1: count numbers with digit sum `s`

Example 2: count numbers whose remainder modulo `m` is `0`

Example 3: forbid adjacent equal digits

## Common Mistakes

- mishandling leading zeros
- forgetting to clear memoization between different bounds
- using digit DP for a property that is easier to count combinatorially

## Practice Ladder

- [Digit DP ladder](../../../practice/ladders/dp/digit-dp/README.md)

## Go Deeper

- Reference: [USACO Guide - Digit DP](https://usaco.guide/gold/digit-dp)
- Practice: [AtCoder Educational DP Contest](https://atcoder.jp/contests/dp)
- Reference: [OI Wiki - Digit DP](https://en.oi-wiki.org/dp/number/)

## Related Topics

- [DP Foundations](../foundations/README.md)
- [Bitmask DP](../bitmask-dp/README.md)
