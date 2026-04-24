# Geometry Cheatsheet

Use this page when the geometry problem is mostly about choosing the right exact predicate and boundary policy.

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

## Choose By Signal

- point is left / right / on line -> orientation
- two closed segments touch or overlap -> [segment-intersection-basic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/segment-intersection-basic.cpp)
- polygon area from ordered vertices -> [shoelace-area.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/shoelace-area.cpp)
- outside / boundary / inside -> [point-in-polygon.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/point-in-polygon.cpp)
- outer boundary of many points -> [convex-hull.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/convex-hull.cpp)

## Safety

- prefer integers when possible
- use `__int128` for large cross products
- define whether boundary counts as inside
- keep one strict vs non-strict intersection policy all the way through the solution

## Quick Anchors In This Repo

- orientation starter -> [Point Location Test](../practice/ladders/geometry/vector-orientation/pointlocationtest.md)
- segment predicate -> [Line Segment Intersection](../practice/ladders/geometry/segment-intersection/linesegmentintersection.md)
- convex hull -> [Convex Hull](../practice/ladders/geometry/convex-hull/convexhull.md)
- geometry-heavy sweep logic -> [KINGDOMS](../practice/ladders/geometry/sweep-line/kingdoms.md)

## Convex Hull

- sort points
- build lower hull
- build upper hull
- choose collinear policy once and keep it consistent
