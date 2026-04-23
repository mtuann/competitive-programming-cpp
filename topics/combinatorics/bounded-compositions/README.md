# Bounded Compositions

Bounded compositions are the right lens when you distribute an integer quantity across slots with lower and upper bounds.

## Prerequisites

- [Prefix Sums](../../foundations/patterns/prefix-sums/README.md)
- [Modular Arithmetic](../../math/modular-arithmetic/README.md)

## When To Suspect It

- distribute `W` identical items into several slots
- each slot has a lower bound or upper bound
- the count is constrained by adjacency or run structure first, then by slot filling

## Core Idea

The base form is:

```text
x1 + x2 + ... + xn = S
```

Then refine it with:

- `xi >= 0`
- `xi >= 1`
- `xi <= K`

Two standard moves are:

- subtract the forced minimum first
- count bounded solutions by DP or inclusion-exclusion

## Theory / Proof Sketch

If a slot must contain at least `1`, write:

```text
yi = xi - 1
```

and solve the transformed nonnegative system.

If each slot also has an upper bound, the cleanest contest solution is often:

- bounded-count DP when constraints are small
- inclusion-exclusion when the formula stays manageable

## Complexity And Tradeoffs

- DP is straightforward and safe for small totals
- inclusion-exclusion is faster in some parameter regimes, but easier to misuse

## Canonical Pattern

Common subproblems:

- choose the skeleton first
- classify the gaps or groups
- count distributions into those slots

## Worked Examples

Example 1: split `W` identical items into `n` nonnegative slots

Example 2: split after forcing some gaps to be positive

Example 3: count fence colorings with white-gap limits

- [VOSFENCE](../../../practice/ladders/combinatorics/bounded-compositions/vosfence.md) is a strong stretch example

## Common Mistakes

- forgetting to subtract the forced minimum
- mixing strict `< K` with non-strict `<= K`
- counting the same slot classification twice

## Practice Ladder

- [Bounded compositions ladder](../../../practice/ladders/combinatorics/bounded-compositions/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Stars and Bars](https://cp-algorithms.com/combinatorics/stars_and_bars.html)
- Reference: [CP-Algorithms - Inclusion-Exclusion](https://cp-algorithms.com/combinatorics/inclusion-exclusion.html)
- Practice: [VOSFENCE note](../../../practice/ladders/combinatorics/bounded-compositions/vosfence.md)

## Related Topics

- [DP Foundations](../../dp/foundations/README.md)
- [Modular Arithmetic](../../math/modular-arithmetic/README.md)
