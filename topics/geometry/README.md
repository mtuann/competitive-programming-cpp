# Geometry

<div class="badge-row" markdown>
  <span class="route-badge route-badge--deep">Deep</span>
</div>

Geometry becomes much easier once you treat it as a small set of trusted primitives plus a few recurring structures.

## Use This Area When

- the clean solution is about points, lines, orientation, or area relations
- most of the difficulty is in conventions, predicates, and degeneracy handling
- the problem can stay integer if you choose the right primitives

## Start With One Route

| If your bottleneck is... | Open first | Then |
| --- | --- | --- |
| basic predicates and conventions | [Vector And Orientation](vector-orientation/README.md) | [Segment Intersection](segment-intersection/README.md), [Polygon Area And Point Location](polygon-area-point-location/README.md) |
| hull and convex reasoning | [Convex Hull](convex-hull/README.md) | [Minkowski Sum](minkowski-sum/README.md), then [Half-Plane Intersection](half-plane-intersection/README.md) |
| event ordering and global distance | [Sweep Line](sweep-line/README.md) | [Nearest Pair of Points](nearest-pair/README.md), [Counting Geometry](counting-geometry/README.md) |

## Core Progression

1. `Core first`
- Vector And Orientation
- Segment Intersection
- Polygon Area And Point Location

2. `Then add`
- Convex Hull
- Sweep Line
- Nearest Pair of Points
- Counting Geometry

3. `Deep later`
- Minkowski Sum
- Half-Plane Intersection
- circle and precision-heavy extensions outside the current core

## Good First Repo Anchors

- [Polygon Area](../../practice/ladders/geometry/polygon-area-point-location/polygonarea.md)
- [Point in Polygon](../../practice/ladders/geometry/polygon-area-point-location/pointinpolygon.md)
- [Closest Pair](../../practice/ladders/geometry/nearest-pair/closestpair.md)
- [KINGDOMS](../../practice/ladders/geometry/sweep-line/kingdoms.md)
- [Big Brother](../../practice/ladders/geometry/half-plane-intersection/bigbrother.md)

## Browse All Subtopics

- [Vector And Orientation](vector-orientation/README.md)
- [Segment Intersection](segment-intersection/README.md)
- [Polygon Area And Point Location](polygon-area-point-location/README.md)
- [Convex Hull](convex-hull/README.md)
- [Minkowski Sum](minkowski-sum/README.md)
- [Sweep Line](sweep-line/README.md)
- [Nearest Pair of Points](nearest-pair/README.md)
- [Counting Geometry](counting-geometry/README.md)
- [Half-Plane Intersection](half-plane-intersection/README.md)

## Go Deeper

- Reference: [CP-Algorithms](https://cp-algorithms.com/)
- Reference: [OI Wiki](https://en.oi-wiki.org/)
- Practice: [ICPC Problem Archive](https://foundation.icpc.global/archive/)
- Reference: [KACTL](https://github.com/kth-competitive-programming/kactl)
