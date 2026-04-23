# Inclusion-Exclusion

Inclusion-exclusion is the correction tool for overcounting when many forbidden or required conditions overlap.

## Prerequisites

- [Counting Basics](../counting-basics/README.md)
- [Bitmask DP](../../dp/bitmask-dp/README.md)

## When To Suspect It

- direct counting overcounts objects that violate several constraints
- the constraints are easier to count when treated as a chosen subset
- the number of bad properties is small enough to iterate subsets

## Core Idea

Count with alternating signs:

```text
good = total
     - sum(single bad sets)
     + sum(pair intersections)
     - sum(triple intersections)
     + ...
```

## Theory / Proof Sketch

Each object lying in exactly `k` bad sets contributes:

```text
1 - C(k, 1) + C(k, 2) - ... + (-1)^k C(k, k) = 0
```

unless it lies in no bad set, in which case it remains counted once.

## Complexity And Tradeoffs

- often `O(2^m * cost)` where `m` is the number of bad conditions

Tradeoffs:

- powerful when `m` is small
- impractical when too many constraints must be enumerated directly

## Canonical Pattern

Iterate subsets of conditions and compute the size of the intersection for that subset.

## Worked Examples

Example 1: count strings avoiding certain letters

Example 2: count numbers divisible by at least one of several values

Example 3: combine with DP or bitmask preprocessing

## Common Mistakes

- losing track of whether the formula is counting good objects or bad objects
- using inclusion-exclusion when a simpler constructive count exists
- forgetting that subset intersections must be easy to evaluate

## Practice Ladder

- [Inclusion-exclusion ladder](../../../practice/ladders/combinatorics/inclusion-exclusion/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Inclusion-Exclusion Principle](https://cp-algorithms.com/combinatorics/inclusion-exclusion.html)
- Reference: [OI Wiki - Inclusion-Exclusion Principle](https://en.oi-wiki.org/math/combinatorics/inclusion-exclusion/)
- Practice: [CSES Mathematics](https://cses.fi/problemset/list/)

## Related Topics

- [Counting Basics](../counting-basics/README.md)
- [Lexicographic Enumeration](../lexicographic-enumeration/README.md)
