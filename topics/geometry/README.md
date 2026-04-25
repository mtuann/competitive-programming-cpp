# Geometry

Geometry is rewarding but unforgiving. This section should start with robust integer geometry and only later expand into broader continuous or implementation-heavy ideas.

## What This Area Covers

Contest geometry becomes much easier once you stop treating it as a huge bag of formulas and start treating it as a small set of trusted primitives plus a few recurring structures:

- vector operations
- orientation and sidedness
- exact boundary handling
- hull and sweep structures
- counting after geometric normalization

Most failures in geometry are not from "not knowing the theorem." They are from inconsistent conventions or fragile predicates.

## Subtopics

- [Vector And Orientation](vector-orientation/README.md)
- [Segment Intersection](segment-intersection/README.md)
- [Polygon Area And Point Location](polygon-area-point-location/README.md)
- [Convex Hull](convex-hull/README.md)
- [Minkowski Sum](minkowski-sum/README.md)
- [Sweep Line](sweep-line/README.md)
- [Nearest Pair of Points](nearest-pair/README.md)
- [Counting Geometry](counting-geometry/README.md)
- [Half-Plane Intersection](half-plane-intersection/README.md)

## Entry

- Prereqs: [Foundations](../foundations/README.md)
- Start here if: you want exact integer geometry before touching precision-heavy topics
- Defer for later: circle-heavy and precision-sensitive topics until orientation and hull basics are stable

## Learn In Order

1. Core now
- vectors, dot product, cross product
- orientation tests
- segment and line intersection basics
- polygon area and boundary conventions

2. Contest core
- convex hull
- Minkowski sum on convex polygons
- sweep-line basics
- nearest-pair sweeps
- counting geometry by normalization

3. Advanced later
- rotating calipers extensions
- half-plane intersection
- circle geometry
- precision-heavy continuous cases

## Recognition Cues

- the statement is really about points, lines, angles, or area relations
- the clean solution uses orientation, projection, or ordering by angle
- integer-only formulas might avoid floating-point headaches
- most of the difficulty is in degeneracy and convention handling

## Common Pitfalls

- mixing floating point into problems that can stay integer
- skipping convention choices for orientation and line representation
- treating geometry as memorization instead of a small set of invariants
- writing predicates once but using inconsistent strict/non-strict policies later

## Exit Criteria

After this section, you should be comfortable with:

- standard vector-based reasoning
- implementing robust integer geometry primitives
- moving from primitives to hull/sweep/counting geometry
- recognizing when precision changes the nature of the problem

## Solved Examples In This Repo

- [Polygon Area](../../practice/ladders/geometry/polygon-area-point-location/polygonarea.md): shoelace accumulation around a closed polygon with exact integer output
- [Point in Polygon](../../practice/ladders/geometry/polygon-area-point-location/pointinpolygon.md): boundary-aware ray casting for inside, outside, and on-edge queries
- [Mogohu-Rea Idol](../../practice/ladders/geometry/minkowski-sum/mogohureaidol.md): stretch anchor after the first two-polygon Minkowski merge route is already trusted
- [Closest Pair](../../practice/ladders/geometry/nearest-pair/closestpair.md): active-strip sweep for the global nearest Euclidean pair
- [PRAVO - Tam giác vuông](../../practice/ladders/geometry/right-triangles/pravo.md): normalized directions and right-triangle counting
- [KINGDOMS - Các vương quốc lồng nhau](../../practice/ladders/geometry/sweep-line/kingdoms.md): sweep-line ordering for nested polygons
- [Big Brother](../../practice/ladders/geometry/half-plane-intersection/bigbrother.md): polygon kernel as the intersection of inward edge half-planes

## Go Deeper

- Reference: [CP-Algorithms](https://cp-algorithms.com/)
- Reference: [OI Wiki](https://en.oi-wiki.org/)
- Practice: [ICPC Problem Archive](https://foundation.icpc.global/archive/)
- Reference: [KACTL](https://github.com/kth-competitive-programming/kactl)
