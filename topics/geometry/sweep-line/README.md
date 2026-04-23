# Sweep Line

Sweep line is the geometry version of event processing: turn a 2D question into a sorted sequence of 1D updates and local neighbor checks.

## Prerequisites

- [Segment Intersection](../segment-intersection/README.md)
- [Sorting](../../foundations/patterns/sorting/README.md)

## When To Suspect It

- events happen as a vertical or horizontal line moves
- you need active set maintenance among segments, intervals, or polygons
- local order changes matter more than all-pairs comparison
- the geometry changes only at a finite set of x- or y-coordinates

## Core Idea

Sort events by one coordinate and maintain the active objects in a structure ordered by the other coordinate or by geometric position.

Standard ingredients:

- event list
- active ordered set
- stable tie-breaking rules
- local-neighbor updates after insert/remove

## Theory / Proof Sketch

Many geometric interactions only change when the sweep line reaches an event. Between events, the combinatorial structure is stable, so only local updates are required.

That is why sweep line replaces `O(n^2)` global checking with:

- sorted event processing
- logarithmic active-set maintenance
- local adjacency checks

The hard part is usually not the theorem but keeping the event ordering and active comparator valid.

## Complexity And Tradeoffs

- often `O(n log n)` if event sorting and active-set updates are logarithmic

Tradeoffs:

- powerful and elegant
- easy to get wrong if event ordering or active comparison is unstable
- usually requires more implementation discipline than the underlying geometry formulas

## Canonical Pattern

Standard workflow:

1. define event types and tie-break order
2. sort events
3. maintain active objects in an ordered structure
4. on each event, update active set and inspect only nearby objects that can now matter

For nested regions or polygon-parent problems, the active order is often by current y-position at sweep x.

## Worked Examples

Example 1: segment intersection candidates

Only newly adjacent segments in the active order need to be tested after updates.

Example 2: nested region parent-child relationships

At a polygon start event, the current nearest enclosing active object often determines the parent after careful boundary handling.

Example 3: [KINGDOMS](../../../practice/ladders/geometry/sweep-line/kingdoms.md)

`KINGDOMS` is a good example of how event ordering and active ordering both need precise conventions.

## Recognition Cues

- "line moves from left to right"
- many intervals/segments/regions enter and leave activity
- all-pairs checking is too slow, but local order is meaningful
- the relevant relation only changes at endpoints

## Common Mistakes

- unstable event ordering at equal coordinates
- using a comparator that changes in invalid ways inside ordered containers
- forgetting to think about closed vs open event boundaries
- not checking whether "just before x" or "just after x" is the correct comparison point
- assuming predecessor in the active set is automatically the desired parent or neighbor

## Standard Variants

- interval sweep
- segment-intersection sweep
- nesting/containment sweeps
- rectangle union/area sweeps with segment trees
- offline event processing framed as sweep line

## Practice Ladder

- [Sweep-line ladder](../../../practice/ladders/geometry/sweep-line/README.md)

## Go Deeper

- Practice: [KINGDOMS](../../../practice/ladders/geometry/sweep-line/kingdoms.md)
- Reference: [USACO Guide - Sweep Line](https://usaco.guide/plat/sweep-line)
- Reference: [OI Wiki - Scanline](https://en.oi-wiki.org/geometry/scanning/)
- Blog/reference: [KACTL geometry/event-processing notes](https://github.com/kth-competitive-programming/kactl)

## Related Topics

- [Segment Intersection](../segment-intersection/README.md)
- [Counting Geometry](../counting-geometry/README.md)
