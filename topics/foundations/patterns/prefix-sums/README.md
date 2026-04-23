# Prefix Sums

Prefix sums are the first major “precompute once, answer many times” tool. They turn repeated range aggregation into `O(1)` queries after `O(n)` preprocessing.

## Prerequisites

- [Reasoning And Implementation Discipline](../../reasoning/README.md)

## When To Suspect It

- many range-sum or range-count queries
- repeated aggregation over prefixes
- you can express the target range as “everything up to r minus everything before l”

## Core Idea

Define:

```text
pref[i] = pref[i - 1] + a[i]
sum(l..r) = pref[r] - pref[l - 1]
```

The whole pattern is about choosing the right prefix meaning.

## Theory / Proof Sketch

Invariant:

```text
pref[i] stores the sum of the first i values.
```

Then:

```text
sum(1..r) - sum(1..l-1) = sum(l..r)
```

The same pattern works for counts, frequencies, and many “how many up to here?” questions.

## Complexity And Tradeoffs

- preprocessing: `O(n)`
- range query: `O(1)`
- memory: `O(n)`

Tradeoffs:

- prefix sums are static; they do not support arbitrary point updates cheaply
- once updates are frequent, Fenwick or segment tree may be better

## Canonical C++ Pattern

Template in this repo:

- [prefix-sum-1d.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/prefix-sum-1d.cpp)

Good habits:

- use one-based prefix arrays for cleaner formulas
- define whether `pref[0] = 0`
- choose `long long` when sums may grow large

## Worked Examples

Example 1: range sums

- the direct pattern above

Example 2: count values in a prefix

- store a frequency prefix instead of a sum

Example 3: 2D prefix sums

- extend the same idea to rectangles
- use inclusion-exclusion carefully

## Common Mistakes

- mixing zero-based and one-based formulas
- forgetting `pref[0] = 0`
- using `int` for large sums
- reaching for segment trees before checking whether the array is static

## Practice Ladder

- [Prefix sums ladder](../../../../practice/ladders/foundations/prefix-sums/README.md)

## Go Deeper

- Reference: [CP-Algorithms](https://cp-algorithms.com/)
- Practice: [CSES Problem Set](https://cses.fi/problemset/)
- Next step: [Fenwick Tree](../../../data-structures/fenwick-tree/README.md)

## Related Topics

- [Difference Arrays](../difference-arrays/README.md)
- [Fenwick Tree](../../../data-structures/fenwick-tree/README.md)
