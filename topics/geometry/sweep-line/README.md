# Sweep Line

Sweep line is the geometry version of event processing: turn a 2D question into a sorted sequence of 1D updates and local neighbor checks.

## Prerequisites

- [Segment Intersection](../segment-intersection/README.md)
- [Sorting](../../foundations/patterns/sorting/README.md)

## When To Suspect It

- events happen as a vertical or horizontal line moves
- you need active set maintenance among segments, intervals, or polygons
- local order changes matter more than all-pairs comparison

## Core Idea

Sort events by one coordinate and maintain the active objects in a structure ordered by the other coordinate or by geometric position.

## Theory / Proof Sketch

Many geometric interactions only change when the sweep line reaches an event. Between events, the combinatorial structure is stable, so only local updates are required.

## Complexity And Tradeoffs

- often `O(n log n)` if event sorting and active-set updates are logarithmic

Tradeoffs:

- powerful and elegant
- easy to get wrong if event ordering or active comparison is unstable

## Canonical Pattern

Standard ingredients:

- event list
- active ordered set
- careful tie-breaking

## Worked Examples

Example 1: segment intersection candidates

Example 2: nested region parent-child relationships

Example 3: [KINGDOMS](../../../practice/ladders/geometry/sweep-line/kingdoms.md)

## Common Mistakes

- unstable event ordering at equal coordinates
- using a comparator that changes in invalid ways inside ordered containers
- forgetting to think about closed vs open event boundaries

## Practice Ladder

- [Sweep-line ladder](../../../practice/ladders/geometry/sweep-line/README.md)

## Go Deeper

- Practice: [KINGDOMS](../../../practice/ladders/geometry/sweep-line/kingdoms.md)
- Reference: [USACO Guide - Sweep Line](https://usaco.guide/plat/sweep-line)
- Reference: [OI Wiki - Scanline](https://en.oi-wiki.org/geometry/scanning/)

## Related Topics

- [Segment Intersection](../segment-intersection/README.md)
- [Counting Geometry](../counting-geometry/README.md)
