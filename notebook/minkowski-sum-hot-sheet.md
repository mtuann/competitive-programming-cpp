# Minkowski Sum Hot Sheet

Use this page when the honest route is:

- convex polygons
- CCW boundary order
- linear-time sum by merging edge directions

## Do Not Use When

- the polygons are non-convex
- the region is defined by line constraints instead of point addition
- the task is only one point-in-polygon query on an already given polygon
- the real route is convex hull of a point set, not Minkowski sum of polygons

## Exact Route In This Repo

- rotate both polygons to the same lowest `(y, x)` vertex
- edges are then already in cyclic angle order
- merge edge directions with cross-product comparison
- append `P[i] + Q[j]`
- advance both pointers on equal-angle edges

## Recognition Cues

- `a + b` with `a in P`, `b in Q`
- collision / overlap after reflecting one convex polygon
- repeated convex polygon sums
- center-of-mass or averaged-point constraints that become an equation on sums of points

## Core Invariants

- both polygons are convex and CCW
- normalization to the same lowest-vertex convention is part of correctness
- angle comparison is by cross product, not `atan2`
- `P + Q` stays convex, so point queries later can use point-in-convex

## Main Traps

- forgetting to negate one polygon in distance / collision transforms
- mixing open / closed polygon conventions with a starter that expects no repeated last vertex
- using the linear merge on non-convex input
- skipping collinear cleanup if your follow-up query helper expects a cleaner convex boundary

## Exact Starter In This Repo

- starter -> [`minkowski-sum-convex.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/minkowski-sum-convex.cpp)
- flagship rep -> [Mogohu-Rea Idol](../practice/ladders/geometry/minkowski-sum/mogohureaidol.md)
- compare point -> [Convex Hull](../topics/geometry/convex-hull/README.md)

## Reopen Paths

- full tutorial -> [Minkowski Sum](../topics/geometry/minkowski-sum/README.md)
- geometry refresher -> [Geometry cheatsheet](geometry-cheatsheet.md)
- convex follow-up query layer -> [Polygon Area And Point Location](../topics/geometry/polygon-area-point-location/README.md)
- retrieve layer -> [Build Kit](../docs/build-kit.md) and [Template Library](../template-library.md)
