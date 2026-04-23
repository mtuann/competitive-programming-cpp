# Vector And Orientation

This is the foundation of contest geometry. If these primitives feel stable, most geometry problems become much less scary.

## Prerequisites

- [C++ Language For Contests](../../foundations/cpp-language/README.md)

## When To Suspect It

- points, segments, polygons, or direction tests
- the solution needs clockwise / counterclockwise reasoning
- floating point seems avoidable

## Core Idea

Represent points as vectors and rely on:

- dot product
- cross product
- orientation sign

Key rule:

```text
cross(b - a, c - a) > 0  =>  a -> b -> c is counterclockwise
```

## Theory / Proof Sketch

Cross product sign encodes sidedness and area orientation. This is enough to power segment intersection, hull construction, and many polygon formulas using exact integer arithmetic.

## Complexity And Tradeoffs

- primitive operations: `O(1)`
- nearly every geometry algorithm depends on getting these primitives right

## Canonical Pattern

Template in this repo:

- [geometry-primitives.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/geometry-primitives.cpp)

## Worked Examples

Example 1: orientation test

Example 2: area of triangle by cross product

Example 3: sorting by angle with half-plane split

## Common Mistakes

- using floating point when integer coordinates allow exact arithmetic
- forgetting `__int128` when products can exceed `long long`
- inconsistent orientation conventions across helper functions

## Practice Ladder

- [Vector and orientation ladder](../../../practice/ladders/geometry/vector-orientation/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Basic Geometry](https://cp-algorithms.com/geometry/basic-geometry.html)
- Reference: [KACTL Geometry section](https://github.com/kth-competitive-programming/kactl)

## Related Topics

- [Segment Intersection](../segment-intersection/README.md)
- [Convex Hull](../convex-hull/README.md)
