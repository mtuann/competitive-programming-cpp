# Polygon Area And Point Location

This page bundles the most common polygon basics: shoelace area, winding / ray ideas, and basic point-in-polygon reasoning.

## Prerequisites

- [Vector And Orientation](../vector-orientation/README.md)

## When To Suspect It

- polygon area or lattice-like shape aggregation
- point location with respect to polygon boundaries
- nested-region reasoning

## Core Idea

Use the shoelace formula for area:

```text
2 * area = abs(sum(x[i] * y[i+1] - y[i] * x[i+1]))
```

And reduce point location to consistent side tests or crossing counts.

## Theory / Proof Sketch

The shoelace sum is the accumulated signed area of edge-based parallelograms. Point-in-polygon methods rely on how a ray or winding count changes when crossing edges.

## Complexity And Tradeoffs

- polygon area: `O(n)`
- point in one polygon: often `O(n)`

## Canonical Pattern

Keep geometry exact with integer arithmetic whenever possible.

Template help:

- [geometry-primitives.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/geometry-primitives.cpp)

## Worked Examples

Example 1: polygon area by shoelace

Example 2: point on boundary vs strictly inside

Example 3: nested polygons with ordering by area

## Common Mistakes

- forgetting the closing edge from last point to first
- overflow in cross-product sums
- not defining whether boundary counts as inside

## Practice Ladder

- [Polygon area and point-location ladder](../../../practice/ladders/geometry/polygon-area-point-location/README.md)

## Go Deeper

- Practice: [TFIELD](../../../practice/ladders/dp/sliding-window/tfield.md)
- Reference: [CP-Algorithms - Oriented Area of a Triangle](https://cp-algorithms.com/geometry/oriented-triangle-area.html)
- Reference: [OI Wiki - Polygon Area](https://en.oi-wiki.org/geometry/basic/)

## Related Topics

- [Sweep Line](../sweep-line/README.md)
- [Counting Geometry](../counting-geometry/README.md)
