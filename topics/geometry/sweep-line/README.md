# Sweep Line

Sweep line is the algorithmic idea of turning a 2D geometric problem into a 1D event stream.

The mental picture is:

- move a conceptual line across the plane
- process only the coordinates where something changes
- maintain the current active objects in an ordered structure

This is one of the most powerful geometry paradigms in competitive programming, but also one of the easiest to get wrong, because correctness depends on:

- event ordering
- active-set meaning
- comparator validity
- before/after-event timing

So this topic is less about one formula and more about one disciplined worldview.

## At A Glance

- **Use when:** the geometry only changes at finitely many event coordinates
- **Core invariant:** between consecutive events, the combinatorial structure is stable
- **Typical pattern:** sort events, maintain active set, inspect only local neighbors
- **Typical complexity:** often `O(n log n)` or `O((n+k)\log n)` depending on the task
- **Main trap:** unstable event order or an active comparator that is not valid at the current sweep position

## Problem Model And Notation

A sweep algorithm chooses one axis as "time", usually `x`.

Then:

- the sweep line moves from left to right
- each object becomes active over some interval of `x`
- only certain `x`-coordinates matter, namely the event coordinates

Typical ingredients:

### Events

Discrete moments where the active set can change, such as:

- segment start
- segment end
- interval start/end
- polygon enter/leave event
- discovered intersection point

### Active Set

The collection of objects currently intersected or relevant at the current sweep position.

Typical data structures:

- ordered set / balanced BST
- Fenwick / segment tree after coordinate compression
- heap or multiset in simpler 1D sweep variants

### Local Order

At a fixed sweep position, active objects are often ordered by:

- current `y`-coordinate
- interval endpoint
- some problem-specific priority

The whole sweep-line trick is that this local order is often enough to avoid all-pairs checking.

## From Brute Force To The Right Idea

### Brute Force: Compare Everything With Everything

Many sweep-line problems start from a hopeless baseline:

- every segment against every segment
- every interval against every interval
- every polygon against every other polygon

This gives:

$$
O(n^2)
$$

or worse.

But usually the geometry is not changing everywhere at once.

### The Key Observation

As the sweep line moves continuously, the combinatorial state usually changes only when it reaches a critical coordinate.

Between two consecutive events:

- no object enters
- no object leaves
- no relevant order change happens

So it is wasteful to recompute the whole geometric configuration at every `x`.

Instead:

1. sort the event coordinates
2. jump from event to event
3. update only the local structure that changed

That is the sweep-line compression of 2D geometry into event processing.

### Why Local Neighbors Often Matter

In many sweep-line tasks, if two active objects can newly interact, they must become adjacent in the active order.

This is the key reason you often only inspect:

- predecessor
- successor
- or a few nearby active objects

That local-neighbor principle is what powers line-segment-intersection sweeps and many nesting or enclosure sweeps.

## Core Invariant And Why It Works

### The Stability Invariant

Between consecutive event coordinates, the active-set membership and its order are stable unless a new event occurs.

This means:

- we do not need to reason about every real-valued sweep position
- only the event coordinates matter

That is the high-level theorem behind the paradigm.

### Why Events Are Enough

Suppose nothing starts, ends, or swaps relevance in the open slab between `x_i` and `x_{i+1}`.

Then every object present in that slab:

- stays present throughout the slab
- preserves its relative structure relevant to the problem

So any answer that depends only on that combinatorial structure will also stay unchanged in that slab.

This is why processing only the event sequence is sound.

### Why Neighbor Checks Are Often Sufficient

For segment-intersection sweeps, the famous idea is:

- if two segments become the next pair that could intersect, they must become adjacent in the active order just before that event

So after an insertion, deletion, or swap, it is enough to inspect nearby neighbors.

This does **not** mean "neighbor checks are always enough" for every sweep-line problem. It means:

- for the right active-order invariant, global interactions reduce to local adjacency

Recognizing when that is true is the essence of sweep-line modeling.

### The Comparator Caveat

This is one of the most important correctness boundaries:

- the active-set comparator must describe order at the current sweep position

If you store segments in an ordered set by a comparator that silently changes as `x` moves, then:

- the container invariant may become invalid

So a sweep-line implementation must always be explicit about:

- what `x` the comparator is meant to represent
- whether updates happen just before or just after the event

## Event Ordering And Timing

This is where most implementation bugs live.

### Equal-Coordinate Events Need A Policy

At the same sweep coordinate, the order of events matters.

Typical examples:

- should a segment ending at `x` be removed before another starting at the same `x` is inserted?
- if two polygons share a boundary coordinate, which enter/leave event comes first?
- for interval sweeps, should opening events come before closing events?

There is no universal answer. The rule must match the statement's boundary convention.

### Before-Event Versus After-Event Semantics

Many sweeps implicitly need one of these viewpoints:

- active set means objects relevant just **before** processing `x`
- active set means objects relevant just **after** processing `x`

If you do not choose this explicitly, predecessor/successor logic becomes slippery very quickly.

### Closed Versus Open Boundaries

A recurring modeling question is:

- if two objects meet exactly at one event coordinate, should they count as simultaneously active?

This is the sweep-line analogue of strict vs non-strict geometry predicates.

## Variant Chooser

### Use Sweep Line When

- the problem is geometric or interval-like
- changes happen only at endpoints / event coordinates
- local order matters more than full pairwise comparison

Canonical examples:

- segment-intersection reporting
- interval overlap counting
- rectangle union / covered length
- enclosure or nesting sweeps

### Use Simpler Sorting / Prefix Methods Instead When

- the active state can be represented by one counter or one prefix sum
- no dynamic ordered set is really needed

Many "sweep line" problems in easier contests are really just:

- sort endpoints
- scan once
- maintain a count

### Use Full Geometry Predicate Sweeps When

- active objects need a geometric order, not just a numeric count
- local neighbor relations drive correctness

That is the harder, more delicate sweep-line family.

### Use Offline Event Processing As A Sweep Mindset

Not every sweep is geometric.

The same idea appears in:

- offline query processing by value
- interval stabbing queries
- rectangle-add / point-query transforms

So it is useful to think of sweep line as a general event-processing paradigm, not only a geometry trick.

## Worked Examples

### Example 1: Interval Sweep

Suppose each interval contributes:

- `+1` at its left endpoint
- `-1` at its right endpoint

Sort those events, scan left to right, and maintain the active count.

This is the simplest sweep:

- event list
- one scalar active state
- no geometric comparator

It is the best entry point before harder geometry sweeps.

### Example 2: Segment-Intersection Detection

For line segments:

- left endpoint = insert into active set
- right endpoint = remove from active set

The active set is ordered by segment height at one chosen sweep position consistent with the event policy.

In practice, that usually means one of two viewpoints:

- order segments just after processing all events at coordinate `x`
- or order them in the open slab immediately to the right of `x`

After insertion or deletion, only predecessor/successor pairs need to be checked as new candidates.

This is the classical local-neighbor sweep insight.

### Example 3: Why Event Order Matters

Suppose one segment ends exactly where another starts.

If the statement counts touching as intersection, then the event policy must preserve that possibility.

If the policy instead treats one endpoint as inactive too early, the algorithm may silently miss a valid interaction.

So "sort by `x`" is not enough. You also need:

- a tie-break order consistent with the problem's closed/open semantics

### Example 4: Nested Region / Parent-Child Sweep

In polygon nesting or kingdom-enclosure style problems, the active set may mean:

- which regions currently contain the sweep point
- ordered by the `y`-position of the lower boundary where each region meets the sweep line

Then the predecessor or nearest enclosing active object can determine:

- the parent region
- or the next containment relation

This is a different use of sweep line than segment intersection, but the event-processing skeleton is the same.

## Algorithm And Pseudocode

There is no single "starter template" for all sweep-line problems in this repo, because the active structure depends heavily on the problem family.

The generic skeleton is:

```text
build event list
sort events by primary coordinate and tie-break policy
initialize active structure

for each batch of equal-coordinate events:
    interpret active set according to chosen timing policy
    process the batch in the tie-break order required by the proof
    update answer / check local neighbors if needed
    insert, remove, or modify active objects
```

For geometry-heavy sweeps, the real work is defining:

- event type
- tie-break order
- active-set meaning
- local-neighbor invariant

## Implementation Notes

### 1. The Comparator Must Match One Sweep Position

If the active-set comparator depends on the current sweep coordinate, then you must be precise about:

- which `x` it represents
- when the structure is updated

An ordered container with a comparator that changes meaning silently is a recipe for undefined behavior or logical corruption.

### 2. Tie-Break Policy Is Part Of The Algorithm

Do not treat equal-coordinate event ordering as a small implementation detail.

It is part of the proof.

Whenever two events share the same sweep coordinate, ask:

- which must happen first for the active-set invariant to stay true?

### 3. Local Neighbors Are Powerful But Conditional

In the right problems, checking only predecessor/successor is enough.

In the wrong problems, it is not.

So never cargo-cult "check neighbors only" without stating why the active order makes that valid.

### 4. Simpler Sweeps Exist

Not every sweep line needs:

- balanced BST
- geometric comparator
- neighbor swaps

Sometimes the correct solution is only:

- sort events
- maintain a count

That still counts as sweep line.

### 5. Equal-Coordinate Events Often Need Batch Reasoning

When many events share the same coordinate, thinking one event at a time can be misleading.

Often the right invariant is about the whole batch:

- remove all objects that should already be inactive
- answer queries at this coordinate
- then insert all objects that become active here

or the opposite order, depending on the problem's boundary convention.

So "equal `x`" is not a tiny implementation detail. It is frequently a proof obligation.

### 6. Closed/Open Semantics Decide Correctness

Many bugs are really policy bugs:

- is an object active at its left endpoint?
- at its right endpoint?
- both?
- neither?

This is the sweep-line version of boundary policy in point-in-polygon or segment intersection.

### 7. Sweep Line Is Often A Modeling Tool First

The biggest contest value of sweep line is not memorizing Bentley–Ottmann.

It is learning to ask:

- what is the sweep coordinate?
- what are the events?
- what stays stable between them?
- what is the smallest active structure that captures the needed local information?

## Beyond Basic Sweep Line

The core contest layer is:

- interval sweeps
- event sorting
- active-set maintenance
- local-neighbor reasoning

Important next-layer directions include:

- Bentley–Ottmann reporting all segment intersections
- rectangle union area with segment trees
- Fortune-style Voronoi sweeps
- topological sweep and more advanced arrangement algorithms

The right study order is:

1. master simple interval/event sweeps
2. internalize active-set semantics and tie-break policies
3. then move to geometry-heavy neighbor-based sweeps

## Practice Archetypes

The most common sweep-line-shaped tasks are:

- **interval overlap or coverage counting**
- **segment-intersection candidate detection**
- **nested region or polygon parent-child sweeps**
- **rectangle union / active coverage**
- **offline queries reinterpreted as sorted events**

The strongest contest smell is:

- all-pairs checking looks too slow
- only endpoints or discrete coordinates seem to matter
- and a local active order looks meaningful between those coordinates

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Course / notes:

- [Tufts Computational Geometry: Segment Intersection Using a Sweep Line](https://www.cs.tufts.edu/comp/163/notes05/seg_intersection_handout.pdf)
- [Carleton Notes: Bentley–Ottmann Sweep](https://people.scs.carleton.ca/~michiel/lecturenotes/ALGGEOM/bentley-ottmann.pdf)
- [CMU Computational Geometry Lecture 4](https://www.cs.cmu.edu/afs/cs/academic/class/15456-s10/ClassNotes/lecture4.pdf)

Reference:

- [USACO Guide: Sweep Line](https://usaco.guide/plat/sweep-line)
- [OI Wiki: Scanline](https://en.oi-wiki.org/geometry/scanning/)
- [Wikipedia: Sweep Line Algorithm](https://en.wikipedia.org/wiki/Sweep_line_algorithm)

Essay / visualization:

- [Ken Clarkson lecture notes on line-segment intersections](https://kenclarkson.org/cis677/lecture/3/index.html)

Practice:

- [Sweep-Line ladder](../../../practice/ladders/geometry/sweep-line/README.md)
- [KINGDOMS](../../../practice/ladders/geometry/sweep-line/kingdoms.md)
- [VOTELPH](../../../practice/ladders/geometry/sweep-line/votelph.md)

Repo anchors:

- topic prerequisite: [Segment Intersection](../segment-intersection/README.md)
- topic prerequisite: [Polygon Area And Point Location](../polygon-area-point-location/README.md)
- notebook refresher: [Geometry cheatsheet](../../../notebook/geometry-cheatsheet.md)

## Related Topics

- [Segment Intersection](../segment-intersection/README.md)
- [Polygon Area And Point Location](../polygon-area-point-location/README.md)
- [Counting Geometry](../counting-geometry/README.md)
