# Segment Intersection

Segment intersection is one of the first places where geometry primitives become an algorithm instead of a formula.

## Prerequisites

- [Vector And Orientation](../vector-orientation/README.md)

## When To Suspect It

- the problem asks whether two segments cross or touch
- sweep-line logic needs local segment ordering
- polygon validity depends on edge intersections
- collinear edge cases are the real source of difficulty

## Core Idea

Two segments intersect if their endpoints lie on different sides of each other, with careful collinear handling.

For segments `ab` and `cd`, compute:

```text
o1 = orient(a, b, c)
o2 = orient(a, b, d)
o3 = orient(c, d, a)
o4 = orient(c, d, b)
```

General crossing is handled by opposite signs. Collinear cases need `on_segment` checks.

## Theory / Proof Sketch

Use orientation signs for the general case and bounding-box overlap for collinear cases. This is the standard robust integer approach.

The key split is:

- non-collinear case: segments intersect if each segment's endpoints lie on different sides of the other segment's supporting line
- collinear case: reduce to 1D overlap on coordinates or bounding boxes

## Complexity And Tradeoffs

- one pair check: `O(1)`
- all pairs naively: `O(n^2)`

Tradeoffs:

- exact and reliable with integer predicates
- degeneracies dominate the implementation complexity
- this predicate is usually reused inside larger geometry algorithms

## Canonical Pattern

Use:

- orientation
- `on_segment`
- careful inclusive comparisons

The same primitives are in:

- [geometry-primitives.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/geometry-primitives.cpp)

## Worked Examples

Example 1: strict vs non-strict intersection

Decide early whether endpoint touching counts as intersection. That changes the comparison logic.

Example 2: segment containment on a line

If all four points are collinear, test whether the projections overlap.

Example 3: event validation before sweep line

Many sweep-line solutions assume local comparisons and candidate intersections rely on a trusted pairwise segment-intersection predicate.

## Recognition Cues

- "do these segments touch?"
- polygons, planar graphs, or sweep-line neighbor checks
- many bugs come from collinear or endpoint-touching edge cases
- the input is integer and exactness matters

## Common Mistakes

- ignoring collinear overlap cases
- mixing strict and non-strict comparisons
- using EPS-style floating point for integer inputs
- forgetting endpoint-touching policy in the statement
- writing `on_segment` with inconsistent axis checks

## Standard Variants

- strict intersection
- non-strict intersection including touching
- intersection point after confirming non-parallel crossing
- pair predicate reused inside sweep line
- segment-vs-ray / segment-vs-line adaptations

## Practice Ladder

- [Segment intersection ladder](../../../practice/ladders/geometry/segment-intersection/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Check if Two Segments Intersect](https://cp-algorithms.com/geometry/check-segments-intersection.html)
- Reference: [OI Wiki - 2D Geometry Basics](https://en.oi-wiki.org/geometry/2d/)
- Blog/reference: [KACTL geometry notes](https://github.com/kth-competitive-programming/kactl)

## Related Topics

- [Sweep Line](../sweep-line/README.md)
- [Polygon Area And Point Location](../polygon-area-point-location/README.md)
