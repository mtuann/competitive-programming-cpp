# Vector And Orientation

This is the foundation of contest geometry. If these primitives feel stable, most geometry problems become much less scary.

## Prerequisites

- [C++ Language For Contests](../../foundations/cpp-language/README.md)

## When To Suspect It

- points, segments, polygons, or direction tests
- the solution needs clockwise / counterclockwise reasoning
- floating point seems avoidable
- every later geometry step depends on getting a few tiny predicates right

## Core Idea

Represent points as vectors and rely on:

- dot product
- cross product
- orientation sign

Key rules:

```text
dot(a, b) = |a| |b| cos(theta)
cross(a, b) = signed area of parallelogram
cross(b - a, c - a) > 0  =>  a -> b -> c is counterclockwise
```

These primitives answer most first-layer geometry questions exactly when coordinates are integers.

## Theory / Proof Sketch

Cross product sign encodes sidedness and area orientation. This is enough to power segment intersection, hull construction, and many polygon formulas using exact integer arithmetic.

Geometrically:

- positive cross: `c` is to the left of ray `a -> b`
- negative cross: `c` is to the right
- zero cross: points are collinear

That is why orientation becomes the universal predicate in contest geometry.

## Complexity And Tradeoffs

- primitive operations: `O(1)`
- nearly every geometry algorithm depends on getting these primitives right

Tradeoffs:

- exact integer arithmetic is ideal when available
- floating point is often convenient but easier to break near degeneracies
- a small, trusted primitive library is more important than clever formulas

## Canonical Pattern

Template in this repo:

- [geometry-primitives.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/geometry-primitives.cpp)

Standard workflow:

1. define `Point`
2. implement `+`, `-`, dot, cross
3. implement orientation as `sign(cross(b - a, c - a))`
4. decide early whether you are working with integer-exact or floating-point geometry

## Worked Examples

Example 1: orientation test

For three points `a, b, c`:

```text
cross(b - a, c - a)
```

tells left turn, right turn, or collinear.

Example 2: area of triangle by cross product

```text
2 * area = abs(cross(b - a, c - a))
```

Example 3: sorting by angle with half-plane split

To sort vectors by polar angle robustly, first split them into upper/lower half-planes, then tie-break by cross product.

## Recognition Cues

- "left of line", "clockwise", "counterclockwise"
- polygon area or boundary reasoning
- segment, hull, or sweep-line geometry
- integer coordinates large enough that overflow discipline matters

## Common Mistakes

- using floating point when integer coordinates allow exact arithmetic
- forgetting `__int128` when products can exceed `long long`
- inconsistent orientation conventions across helper functions
- forgetting that zero cross means collinear, not automatically "inside"
- mixing screen coordinates with mathematical coordinates

## Standard Variants

- integer geometry with exact predicates
- floating-point geometry with EPS
- angle sorting by half-plane + cross
- dot-product angle reasoning
- area reasoning via signed cross sums

## Practice Ladder

- [Vector and orientation ladder](../../../practice/ladders/geometry/vector-orientation/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Basic Geometry](https://cp-algorithms.com/geometry/basic-geometry.html)
- Reference: [KACTL Geometry section](https://github.com/kth-competitive-programming/kactl)
- Blog/reference: [OI Wiki - 2D Geometry Basics](https://en.oi-wiki.org/geometry/2d/)
- Practice note: [PRAVO](../../../practice/ladders/geometry/right-triangles/pravo.md)

## Related Topics

- [Segment Intersection](../segment-intersection/README.md)
- [Convex Hull](../convex-hull/README.md)
