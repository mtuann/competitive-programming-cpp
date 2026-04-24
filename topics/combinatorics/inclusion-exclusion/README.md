# Inclusion-Exclusion

Inclusion-exclusion is the correction tool for overcounting when many forbidden or required conditions overlap.

## Prerequisites

- [Counting Basics](../counting-basics/README.md)
- [Bitmask DP](../../dp/bitmask-dp/README.md)

## When To Suspect It

- direct counting overcounts objects that violate several constraints
- the constraints are easier to count when treated as a chosen subset
- the number of bad properties is small enough to iterate subsets
- the clean intersection size of a subset is much easier than the direct final count

## Core Idea

Count with alternating signs:

```text
good = total
     - sum(single bad sets)
     + sum(pair intersections)
     - sum(triple intersections)
     + ...
```

In practice, you rarely write the whole symbolic formula. You iterate subsets of conditions and give each subset a sign.

## Theory / Proof Sketch

Each object lying in exactly `k` bad sets contributes:

```text
1 - C(k, 1) + C(k, 2) - ... + (-1)^k C(k, k) = 0
```

unless it lies in no bad set, in which case it remains counted once.

That is why inclusion-exclusion is a correction mechanism, not a construction mechanism.

## Complexity And Tradeoffs

- often `O(2^m * cost)` where `m` is the number of bad conditions

Tradeoffs:

- powerful when `m` is small
- impractical when too many constraints must be enumerated directly
- often pairs naturally with bitmasks, lcm, or DP over subsets

## Canonical Pattern

Iterate subsets of conditions and compute the size of the intersection for that subset.

Typical structure:

```text
answer = total
for each non-empty subset S:
  contribution = size(intersection of conditions in S)
  if |S| is odd: answer -= contribution
  else: answer += contribution
```

Some problems count "good directly" instead, so the signs flip. The safe habit is to say out loud what your accumulator currently means.

## Worked Examples

Example 1: count strings avoiding certain letters

If each bad condition is "missing letter `c`", then a subset of bad conditions means several letters are missing at once.

Example 2: count numbers divisible by at least one of several values

For a subset of divisors, the intersection size becomes:

```text
floor(n / lcm(subset))
```

This is why lcm and overflow checks show up so often in inclusion-exclusion problems.

Example 3: combine with DP or bitmask preprocessing

Sometimes the subset intersection is not `O(1)` but can be precomputed or memoized.

## Recognition Cues

- "at least one of these conditions"
- "avoid all forbidden properties"
- there are `m <= 20` or similarly small properties
- subset lcm / subset mask reasoning appears naturally
- complementary counting is easy, but overlaps are the obstacle

## Common Mistakes

- losing track of whether the formula is counting good objects or bad objects
- using inclusion-exclusion when a simpler constructive count exists
- forgetting that subset intersections must be easy to evaluate
- overflow when taking lcm across a subset
- double-counting because the sign convention changed halfway through the derivation
- using it when `m` is too large and a DP / mobius / sieve approach is needed instead

## Standard Variants

- count bad and subtract from total
- count good directly with alternating signs
- lcm-based subset intersections
- inclusion-exclusion over letters, colors, or positions
- subset DP hybrid where intersections are precomputed once

## Practice Ladder

- [Inclusion-exclusion ladder](../../../practice/ladders/combinatorics/inclusion-exclusion/README.md)

## Repo Anchors

- [Prime Multiples](../../../practice/ladders/combinatorics/inclusion-exclusion/primemultiples.md): the cleanest subset-enumeration inclusion-exclusion problem with overflow-safe lcm/product handling.

## Go Deeper

- Course notes: [Princeton combinatorics notes](https://www.cs.princeton.edu/courses/archive/fall17/cos521/)
- Reference: [CP-Algorithms - Inclusion-Exclusion Principle](https://cp-algorithms.com/combinatorics/inclusion-exclusion.html)
- Reference: [OI Wiki - Inclusion-Exclusion Principle](https://en.oi-wiki.org/math/combinatorics/inclusion-exclusion/)
- Blog/reference: [USACO Guide - PIE](https://usaco.guide/plat/PIE?lang=cpp)
- Practice: [CSES Mathematics](https://cses.fi/problemset/list/)

## Related Topics

- [Counting Basics](../counting-basics/README.md)
- [Lexicographic Enumeration](../lexicographic-enumeration/README.md)
