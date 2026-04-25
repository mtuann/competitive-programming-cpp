# Geometry Cheatsheet

Use this page when the geometry problem is mostly about choosing the right exact predicate and boundary policy.

## Do Not Use When

- the main difficulty is sweep-line bookkeeping rather than predicates
- floating-point approximation is the true topic and exact integer predicates do not apply
- you have not fixed whether boundary counts as inside / intersecting / touching

## Choose By Signal

- point is left / right / on line -> orientation
- two closed segments touch or overlap -> [segment-intersection-basic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/segment-intersection-basic.cpp)
- polygon area from ordered vertices -> [shoelace-area.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/shoelace-area.cpp)
- outside / boundary / inside -> [point-in-polygon.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/point-in-polygon.cpp)
- outer boundary of many points -> [convex-hull.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/convex-hull.cpp)
- sum of two convex polygons in CCW order -> [minkowski-sum-convex.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/minkowski-sum-convex.cpp)
- bounded convex region from many directed lines -> [half-plane-intersection.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/half-plane-intersection.cpp)
- one static nearest Euclidean pair -> [closest-pair-sweep.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/closest-pair-sweep.cpp)

## Core Primitives

- point subtraction
- dot product
- cross product
- orientation sign

Template start:

- [geometry-primitives.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/geometry-primitives.cpp)

## Orientation

```text
cross(b - a, c - a) > 0  => counterclockwise
cross(b - a, c - a) < 0  => clockwise
cross(b - a, c - a) = 0  => collinear
```

## Safety

- prefer integers when possible
- use `__int128` for large cross products
- define whether boundary counts as inside
- keep one strict vs non-strict intersection policy all the way through the solution

## Main Trap

Most geometry wrong answers come from policy drift, not the formula:

- strict vs non-strict
- open vs closed segment
- boundary vs inside
- inconsistent kept-side policy across directed lines in half-plane intersection

Pick the policy once and keep it everywhere.

## Quick Anchors In This Repo

- orientation starter -> [Point Location Test](../practice/ladders/geometry/vector-orientation/pointlocationtest.md)
- segment predicate -> [Line Segment Intersection](../practice/ladders/geometry/segment-intersection/linesegmentintersection.md)
- convex hull -> [Convex Hull](../practice/ladders/geometry/convex-hull/convexhull.md)
- convex polygon sums / repeated-sum point queries -> [Mogohu-Rea Idol](../practice/ladders/geometry/minkowski-sum/mogohureaidol.md)
- bounded half-plane region / polygon kernel -> [Big Brother](../practice/ladders/geometry/half-plane-intersection/bigbrother.md)
- nearest pair sweep -> [Closest Pair](../practice/ladders/geometry/nearest-pair/closestpair.md)
- geometry-heavy sweep logic -> [KINGDOMS](../practice/ladders/geometry/sweep-line/kingdoms.md)

## Convex Hull / Half-Plane Split

- sort points
- build lower hull
- build upper hull
- choose collinear policy once and keep it consistent

If the boundary comes from **input points**, it is usually hull.

If the boundary comes from **directed line constraints**, it is usually [Half-Plane Intersection](../topics/geometry/half-plane-intersection/README.md).

If the goal is **one global closest distance**, it is usually [Nearest Pair of Points](../topics/geometry/nearest-pair/README.md).

If the goal is **pointwise addition of convex regions**, it is usually [Minkowski Sum](../topics/geometry/minkowski-sum/README.md).

## Reopen Paths

- topic pages -> [Segment Intersection](../topics/geometry/segment-intersection/README.md), [Polygon Area And Point Location](../topics/geometry/polygon-area-point-location/README.md), [Convex Hull](../topics/geometry/convex-hull/README.md), [Minkowski Sum](../topics/geometry/minkowski-sum/README.md), [Half-Plane Intersection](../topics/geometry/half-plane-intersection/README.md), [Nearest Pair of Points](../topics/geometry/nearest-pair/README.md)
- template layer -> [Template library](../template-library.md)
