# Polygon Area And Point Location

This page bundles the most common polygon basics: shoelace area, winding/ray ideas, and basic point-in-polygon reasoning.

## Prerequisites

- [Vector And Orientation](../vector-orientation/README.md)

## When To Suspect It

- polygon area or lattice-like shape aggregation
- point location with respect to polygon boundaries
- nested-region reasoning
- a geometry task looks global, but the real work is just summing edges or counting crossings

## Core Idea

Use the shoelace formula for area:

```text
2 * area = abs(sum(x[i] * y[i+1] - y[i] * x[i+1]))
```

And reduce point location to consistent side tests or crossing counts.

Two early policy choices matter:

- signed area vs absolute area
- whether boundary counts as inside

## Theory / Proof Sketch

The shoelace sum is the accumulated signed area of edge-based parallelograms. Point-in-polygon methods rely on how a ray or winding count changes when crossing edges.

Intuitively:

- area comes from summing edge contributions
- point location comes from tracking how the polygon wraps around the query point or how often a ray crosses the boundary

## Complexity And Tradeoffs

- polygon area: `O(n)`
- point in one polygon: often `O(n)`

Tradeoffs:

- area is simple and exact with integer arithmetic
- point location is easy to get subtly wrong on boundary and horizontal-edge cases
- for many repeated point queries on one polygon, preprocessing-based approaches may be better

## Canonical Pattern

Keep geometry exact with integer arithmetic whenever possible.

Template help:

- [geometry-primitives.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/geometry-primitives.cpp)

Standard workflow:

1. store polygon vertices in cyclic order
2. remember the closing edge from last point to first
3. use signed cross sums for area
4. choose one precise boundary convention for point location and keep it everywhere

## Worked Examples

Example 1: polygon area by shoelace

For every edge `(p[i], p[i+1])`, add:

```text
cross(p[i], p[i+1])
```

then take absolute value at the end.

Example 2: point on boundary vs strictly inside

Before ray casting or winding, check whether the point lies on any boundary segment. This avoids many ambiguous corner cases.

Example 3: nested polygons with ordering by area

Area is often a cheap first key for nesting logic, but containment still needs a point-location test.

## Recognition Cues

- polygon area, interior, or boundary
- many edge contributions summed around a closed shape
- "inside / outside / on boundary" classification
- nested regions or laminar polygons

## Common Mistakes

- forgetting the closing edge from last point to first
- overflow in cross-product sums
- not defining whether boundary counts as inside
- double-counting ray hits at polygon vertices
- using floating point for exact integer-input area logic

## Standard Variants

- shoelace signed/absolute area
- ray-casting point in polygon
- winding-number point in polygon
- convex-polygon point location with orientation tests
- nested polygon ordering with area plus containment

## Practice Ladder

- [Polygon area and point-location ladder](../../../practice/ladders/geometry/polygon-area-point-location/README.md)

## Go Deeper

- Practice: [TFIELD](../../../practice/ladders/dp/sliding-window/tfield.md)
- Reference: [CP-Algorithms - Oriented Area of a Triangle](https://cp-algorithms.com/geometry/oriented-triangle-area.html)
- Reference: [OI Wiki - Polygon Area](https://en.oi-wiki.org/geometry/basic/)
- Blog/reference: [USACO Guide geometry modules](https://usaco.guide/plat/geo-primitives?lang=cpp)

## Related Topics

- [Sweep Line](../sweep-line/README.md)
- [Counting Geometry](../counting-geometry/README.md)
