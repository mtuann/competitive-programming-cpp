# Minkowski Sum Ladder

## Who This Is For

Use this lane when the geometry object is the sum of convex regions, not one hull, one feasible intersection, or one plain polygon query.

## Warm-Up

- convex polygon order
- lowest-vertex normalization
- comparing edge directions with cross products

## Core

- linear merge of two convex polygons
- repeated sums of several convex polygons
- point-in-convex follow-up after the sum is built

## Repo Anchors

- [Mogohu-Rea Idol](mogohureaidol.md)
- [Convex Hull tutorial](../../../../topics/geometry/convex-hull/README.md)
- [Polygon Area And Point Location tutorial](../../../../topics/geometry/polygon-area-point-location/README.md)

## Stretch

- explain why `P + (-Q)` turns distance / collision questions into one query on the sum polygon
- compare convex polygon sum against half-plane intersection and say why they are different objects

## Compare Points

- outer boundary of a point set -> [Convex Hull](../../../../topics/geometry/convex-hull/README.md)
- feasible polygon from directed lines -> [Half-Plane Intersection](../../../../topics/geometry/half-plane-intersection/README.md)
- one final point query on a polygon you already have -> [Polygon Area And Point Location](../../../../topics/geometry/polygon-area-point-location/README.md)

This ladder is intentionally sparse. The point is not to collect many unrelated continuous-geometry problems. The point is to trust the convex-polygon sum route and recognize when it is the real model.

## Exit Criteria

You are ready to move on when you can:

- normalize two convex polygons into the same start-vertex convention
- explain why their edge directions can be merged like sorted lists
- use repeated Minkowski sums without losing the exact route
- recognize when one query point should be scaled / reflected before testing membership

## External Practice

- [Codeforces 87E - Mogohu-Rea Idol](https://codeforces.com/problemset/problem/87/E)
- [cp-algorithms - Minkowski sum of convex polygons](https://cp-algorithms.com/geometry/minkowski.html)

## Tutorial Link

- [Minkowski Sum](../../../../topics/geometry/minkowski-sum/README.md)
