# Counting Geometry

Counting geometry problems ask for numbers of triangles, right angles, intersections, or visible configurations. The geometry is often simple, but the counting structure is the real challenge.

## Prerequisites

- [Vector And Orientation](../vector-orientation/README.md)
- [Counting Basics](../../combinatorics/counting-basics/README.md)

## When To Suspect It

- count triangles, right angles, crossings, or special configurations
- brute force over all triples or quadruples is too slow
- slopes, directions, or canonical geometric features can be grouped

## Core Idea

Normalize the geometric invariant first, then count by groups.

Typical invariants:

- direction vectors
- slopes
- perpendicular classes
- relative order on a sweep line

## Theory / Proof Sketch

Most counting geometry problems become feasible only after collapsing equivalent geometric relations into canonical representations. Then the task becomes frequency counting, matching, or prefix/sweep processing.

## Complexity And Tradeoffs

- depends on the normalization strategy
- often `O(n^2 log n)` instead of `O(n^3)`

## Canonical Pattern

Sort or hash normalized directions and combine complementary classes.

## Worked Examples

Example 1: [PRAVO](../../../practice/ladders/geometry/right-triangles/pravo.md)

Example 2: count equal slopes or perpendicular directions

Example 3: count configurations under sweep ordering

## Common Mistakes

- non-canonical slope representation
- forgetting signs or gcd normalization
- floating-point comparisons when exact normalized integers are possible

## Practice Ladder

- [Counting-geometry ladder](../../../practice/ladders/geometry/counting-geometry/README.md)

## Go Deeper

- Practice: [PRAVO](../../../practice/ladders/geometry/right-triangles/pravo.md)
- Reference: [CP-Algorithms - Basic Geometry](https://cp-algorithms.com/geometry/basic-geometry.html)

## Related Topics

- [Sweep Line](../sweep-line/README.md)
- [Vector And Orientation](../vector-orientation/README.md)
