# Convex Hull

Convex hull is the first major geometry algorithm most contestants should internalize. It turns a cloud of points into its outer boundary.

## Prerequisites

- [Vector And Orientation](../vector-orientation/README.md)
- [Sorting](../../foundations/patterns/sorting/README.md)

## When To Suspect It

- outer boundary of points
- farthest-pair or width-style follow-up questions
- remove interior points and keep only the envelope

## Core Idea

Sort points, then build lower and upper hulls while maintaining a convex turn invariant.

## Theory / Proof Sketch

When points are processed in sorted order, any point that causes a non-convex turn cannot belong to the final hull in that partial order and can be removed immediately.

## Complexity And Tradeoffs

- monotonic chain: `O(n log n)` from sorting

## Canonical Pattern

Template in this repo:

- [convex-hull.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/convex-hull.cpp)

## Worked Examples

Example 1: compute hull points in order

Example 2: handle collinear points on the boundary

Example 3: prepare for rotating calipers later

## Common Mistakes

- inconsistent choice on whether to keep collinear boundary points
- duplicate start/end point handling
- forgetting to sort and unique points before hull logic

## Practice Ladder

- [Convex hull ladder](../../../practice/ladders/geometry/convex-hull/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Convex Hull Construction](https://cp-algorithms.com/geometry/convex-hull.html)
- Reference: [KACTL Geometry section](https://github.com/kth-competitive-programming/kactl)

## Related Topics

- [Vector And Orientation](../vector-orientation/README.md)
- [Counting Geometry](../counting-geometry/README.md)
