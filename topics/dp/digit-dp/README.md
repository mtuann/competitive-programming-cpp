# Digit DP

Digit DP is the standard counting tool when a constraint is stated over decimal representation and the bound can be processed digit by digit.

## Summary

Suspect digit DP when:

- the problem asks to count numbers in `[0, x]` or `[l, r]`
- the property depends on digits, digit sums, adjacency of digits, or automaton-like restrictions
- brute force over all values is impossible, but the decimal length is tiny

What success looks like:

- you can define the tight and started flags confidently
- you can decide what extra state the property needs
- you can solve `[l, r]` by turning it into `solve(r) - solve(l - 1)`

## Prerequisites

- [DP Foundations](../foundations/README.md)
- [Modular Arithmetic](../../math/modular-arithmetic/README.md)

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

The DP only remembers the information future digits still need.

## Theory / Proof Sketch

At each position, the only information that matters for the future is:

- whether we are still equal to the upper bound
- whether the number has started yet
- the small summary needed by the property

That creates overlapping subproblems across prefixes of the decimal string.

For interval queries:

```text
answer(l..r) = solve(r) - solve(l - 1)
```

because `solve(x)` counts valid numbers up to `x`.

## Complexity And Tradeoffs

- roughly `digits * states * alphabet`
- usually manageable because there are at most around `19` digits for `long long`

Tradeoffs:

- ideal for digit-defined properties
- awkward if the property is not actually tied to representation

## Canonical C++ Pattern

Template in this repo:

- [digit-dp-skeleton.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/dp/digit-dp-skeleton.cpp)

Common implementation styles:

- memoized DFS on positions
- iterative DP over digits

Memoized DFS is usually the clearer first choice.

## Standard Patterns

### 1. Digit Sum Constraints

Examples:

- count numbers with digit sum `s`

### 2. Modulo Constraints

Examples:

- count numbers whose value modulo `m` is `0`

### 3. Adjacent-Digit Restrictions

Examples:

- no two equal adjacent digits
- no forbidden local pattern

### 4. Automaton-Enhanced Digit DP

If the restriction is substring-like, combine digit DP with an automaton state such as Aho-Corasick.

## Worked Examples

### Example 1: count numbers with digit sum `s`

Extra state:

- current sum so far

### Example 2: count numbers whose remainder modulo `m` is `0`

Extra state:

- current remainder

### Example 3: forbid adjacent equal digits

Extra state:

- previous digit

This is a good first example of local digit-memory constraints.

## Recognition Cues

Strong clues:

- count numbers in a numeric interval
- the property is about decimal digits
- small number of digit positions, huge numeric range

Digit DP is often confused with:

- combinatorics, when the property might be countable directly
- brute force with pruning, when the real structure is only `19` positions wide

## Common Mistakes

- mishandling leading zeros
- forgetting to clear memoization between bounds when needed
- using digit DP for a property that has a simpler direct formula
- forgetting that `[l, r]` usually becomes `solve(r) - solve(l - 1)`

## Practice Ladder

- [Digit DP ladder](../../../practice/ladders/dp/digit-dp/README.md)

Suggested order:

1. digit-sum counting
2. modulo-state counting
3. previous-digit restrictions
4. automaton-enhanced variants later

## Go Deeper

- Reference: [USACO Guide - Digit DP](https://usaco.guide/gold/digit-dp)
- Reference: [OI Wiki - Digit DP](https://en.oi-wiki.org/dp/number/)
- Practice: [AtCoder Educational DP Contest](https://atcoder.jp/contests/dp)

## Related Topics

- [DP Foundations](../foundations/README.md)
- [Modular Arithmetic](../../math/modular-arithmetic/README.md)
- [Aho-Corasick](../../strings/aho-corasick/README.md)
