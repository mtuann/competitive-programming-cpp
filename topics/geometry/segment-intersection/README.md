# Segment Intersection

Segment intersection is one of the first places where geometry primitives become an algorithm instead of a formula.

## Prerequisites

- [Vector And Orientation](../vector-orientation/README.md)

## When To Suspect It

- the problem asks whether two segments cross or touch
- sweep-line logic needs local segment ordering
- polygon validity depends on edge intersections

## Core Idea

Two segments intersect if their endpoints lie on different sides of each other, with careful collinear handling.

## Theory / Proof Sketch

Use orientation signs for the general case and bounding-box overlap for collinear cases. This is the standard robust integer approach.

## Complexity And Tradeoffs

- one pair check: `O(1)`
- all pairs naively: `O(n^2)`

## Canonical Pattern

Use:

- orientation
- `on_segment`
- careful inclusive comparisons

The same primitives are in:

- [geometry-primitives.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/geometry-primitives.cpp)

## Worked Examples

Example 1: strict vs non-strict intersection

Example 2: segment containment on a line

Example 3: event validation before sweep line

## Common Mistakes

- ignoring collinear overlap cases
- mixing strict and non-strict comparisons
- using EPS-style floating point for integer inputs

## Practice Ladder

- [Segment intersection ladder](../../../practice/ladders/geometry/segment-intersection/README.md)

## Go Deeper

- Reference: [CP-Algorithms - Check if Two Segments Intersect](https://cp-algorithms.com/geometry/check-segments-intersection.html)
- Reference: [OI Wiki - 2D Geometry Basics](https://en.oi-wiki.org/geometry/2d/)

## Related Topics

- [Sweep Line](../sweep-line/README.md)
- [Polygon Area And Point Location](../polygon-area-point-location/README.md)
