# Convex Hull

Convex hull is the first major geometry algorithm most contestants should internalize. It turns a cloud of points into its outer boundary.

## Prerequisites

- [Vector And Orientation](../vector-orientation/README.md)
- [Sorting](../../foundations/patterns/sorting/README.md)

## When To Suspect It

- outer boundary of points
- farthest-pair or width-style follow-up questions
- remove interior points and keep only the envelope
- the geometry becomes easier once only extreme points remain

## Core Idea

Sort points, then build lower and upper hulls while maintaining a convex-turn invariant.

For monotonic chain, while processing points in sorted order:

```text
while hull has at least 2 points and last turn is not acceptable:
  pop last point
push current point
```

The acceptance rule depends on whether you want to keep collinear boundary points.

## Theory / Proof Sketch

When points are processed in sorted order, any point that causes a non-convex turn cannot belong to the final hull in that partial order and can be removed immediately.

That is the monotonic-chain invariant:

- the partial hull stays convex
- every removed point is provably inside or redundant for that chain
- sorting ensures local turn checks are enough

## Complexity And Tradeoffs

- monotonic chain: `O(n log n)` from sorting
- hull construction after sorting: `O(n)`

Tradeoffs:

- simple and reliable once orientation is trusted
- edge-case policy on collinear points matters a lot
- usually the right first hull algorithm in contests

## Canonical Pattern

Template in this repo:

- [convex-hull.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/convex-hull.cpp)

Standard workflow:

1. sort points lexicographically
2. erase duplicates if needed
3. build lower hull
4. build upper hull
5. merge them carefully without duplicating endpoints

## Worked Examples

Example 1: compute hull points in order

The output hull is usually returned in counterclockwise order, without repeating the first point at the end.

Example 2: handle collinear points on the boundary

Using:

```text
cross <= 0
```

versus:

```text
cross < 0
```

changes whether collinear boundary points are removed.

Example 3: prepare for rotating calipers later

Many diameter, width, and antipodal-pair problems first reduce to the hull, then apply a second algorithm on that smaller polygon.

## Recognition Cues

- "outer fence", "boundary", "envelope", "keep only extreme points"
- later metric queries like diameter or perimeter over a point set
- a large cloud of points where interior points seem irrelevant

## Common Mistakes

- inconsistent choice on whether to keep collinear boundary points
- duplicate start/end point handling
- forgetting to sort and unique points before hull logic
- mixing clockwise and counterclockwise conventions between helpers
- returning a repeated first point when downstream code does not expect it

## Standard Variants

- monotonic chain
- Graham scan
- keep-only-corners hull
- keep-all-boundary-points hull
- hull as preprocessing for rotating calipers

## Practice Ladder

- [Convex hull ladder](../../../practice/ladders/geometry/convex-hull/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Convex Hull Construction](https://cp-algorithms.com/geometry/convex-hull.html)
- Reference: [KACTL Geometry section](https://github.com/kth-competitive-programming/kactl)
- Blog/reference: [USACO Guide - Convex Hull](https://usaco.guide/plat/convex-hull?lang=cpp)

## Related Topics

- [Vector And Orientation](../vector-orientation/README.md)
- [Counting Geometry](../counting-geometry/README.md)
