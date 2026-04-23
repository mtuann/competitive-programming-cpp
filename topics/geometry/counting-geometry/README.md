# Counting Geometry

Counting geometry problems ask for numbers of triangles, right angles, intersections, or visible configurations. The geometry is often simple, but the counting structure is the real challenge.

## Prerequisites

- [Vector And Orientation](../vector-orientation/README.md)
- [Counting Basics](../../combinatorics/counting-basics/README.md)

## When To Suspect It

- count triangles, right angles, crossings, or special configurations
- brute force over all triples or quadruples is too slow
- slopes, directions, or canonical geometric features can be grouped
- the geometry predicate is simple, but the number of candidate tuples is enormous

## Core Idea

Normalize the geometric invariant first, then count by groups.

Typical invariants:

- direction vectors
- slopes
- perpendicular classes
- relative order on a sweep line
- canonical line or angle representations

## Theory / Proof Sketch

Most counting geometry problems become feasible only after collapsing equivalent geometric relations into canonical representations. Then the task becomes frequency counting, matching, or prefix/sweep processing.

The usual pattern is:

1. fix an anchor point, line, or event order
2. convert geometry relations into normalized keys
3. count complementary or matching keys

That is why exact normalization matters more than fancy formulas.

## Complexity And Tradeoffs

- depends on the normalization strategy
- often `O(n^2 log n)` instead of `O(n^3)`
- sometimes `O(n^2)` with hashing after careful canonicalization

Tradeoffs:

- the geometry itself may be easy, but representation bugs are common
- exact integer normalization is usually worth the effort
- hashing can beat sorting, but sorting is often simpler to trust

## Canonical Pattern

Sort or hash normalized directions and combine complementary classes.

Typical normalizations:

```text
(dx, dy) / gcd(|dx|, |dy|)
```

with a fixed sign convention, or a reduced slope / line representation.

## Worked Examples

Example 1: [PRAVO](../../../practice/ladders/geometry/right-triangles/pravo.md)

Fix a point as the right-angle vertex, normalize directions to all other points, then count perpendicular pairs.

Example 2: count equal slopes or perpendicular directions

After canonicalization, this becomes a frequency problem.

Example 3: count configurations under sweep ordering

Some intersection or visibility counts become event-order counting after a sweep.

## Recognition Cues

- "count all right triangles / special pairs / special triples"
- slopes or directions repeat across many point pairs
- exact floating-point comparisons feel dangerous
- one anchor point at a time makes the problem local

## Common Mistakes

- non-canonical slope representation
- forgetting signs or gcd normalization
- floating-point comparisons when exact normalized integers are possible
- forgetting duplicates, opposite directions, or zero vectors
- choosing hashing before clearly defining the canonical key

## Standard Variants

- fix one point and count direction pairs
- group by slope or line
- complementary direction counting
- sweep-order counting of crossings/intersections
- angle-sorted local counting around one anchor

## Practice Ladder

- [Counting-geometry ladder](../../../practice/ladders/geometry/counting-geometry/README.md)

## Go Deeper

- Practice: [PRAVO](../../../practice/ladders/geometry/right-triangles/pravo.md)
- Reference: [CP-Algorithms - Basic Geometry](https://cp-algorithms.com/geometry/basic-geometry.html)
- Blog/reference: [OI Wiki geometry section](https://en.oi-wiki.org/geometry/)

## Related Topics

- [Sweep Line](../sweep-line/README.md)
- [Vector And Orientation](../vector-orientation/README.md)
