# Half-Plane Intersection

This lane starts when geometry stops being:

```text
reason about one point, one segment, or one polygon boundary
```

and becomes:

```text
recover the whole feasible region cut out by many directed lines
```

The repo keeps the first exact route deliberately narrow.

It starts with:

- one static set of directed lines
- one convention:
  - each half-plane keeps the **left** side of its directed boundary line
- one target:
  - return the bounded convex polygon of the intersection, or detect that it is empty
- one contest-clean algorithm:
  - **angle sort + deque maintenance**

This page does **not** start with:

- generic linear programming duality
- arbitrary unbounded half-plane outputs
- polygon clipping against many windows as the first implementation
- three-dimensional half-space intersection

The first reusable move is:

```text
sort half-planes by boundary angle,
deduplicate equal directions,
then maintain the surviving intersection with a deque
```

That same family later connects to:

- polygon kernels
- convex clipping viewpoints
- precision-heavy continuous geometry

but the first snippet to trust is still:

```text
directed half-planes -> bounded polygon output
```

## At A Glance

- **Use when:** the statement is really asking for the common feasible region cut out by many directed lines
- **Core worldview:** the answer is a convex polygon described by supporting lines, not by an input point cloud
- **Main tools:** orientation / sidedness, angle sorting, parallel tie-breaking, deque cleanup, polygon area
- **Typical complexity:** `O(n log n)` for sorting plus linear deque processing
- **Main trap:** mixing up the kept side, or pretending a bounded-polygon snippet automatically handles every unbounded variant

Strong contest signals:

- "find the region where all constraints hold"
- "camera can be placed anywhere that sees the whole polygon"
- "intersect all inward edge half-planes"
- the output is an area, polygon, or emptiness check of a feasible region
- the correct boundary is made from **lines**, not from selecting extreme input points

Strong anti-cues:

- the input is a set of points and you want the outer envelope -> [Convex Hull](../convex-hull/README.md)
- the real bottleneck is event ordering over many intersections -> [Sweep Line](../sweep-line/README.md)
- the task is only polygon area or inside / boundary / outside classification -> [Polygon Area And Point Location](../polygon-area-point-location/README.md)
- the input is already one convex polygon and clipping is easier than re-deriving a full half-plane engine

## Prerequisites

- [Vector And Orientation](../vector-orientation/README.md)
- [Polygon Area And Point Location](../polygon-area-point-location/README.md)

Helpful nearby anchors:

- [Convex Hull](../convex-hull/README.md)
- [Sweep Line](../sweep-line/README.md)
- [Geometry cheatsheet](../../../notebook/geometry-cheatsheet.md)

## Problem Model And Notation

Each half-plane is represented by one directed boundary line:

$$
p + t \cdot d
$$

and the legal side is:

$$
\operatorname{cross}(d,\ x - p) \ge 0
$$

That means:

- points on the line are legal
- points to the **left** of the directed line are legal
- points to the right are forbidden

The full feasible set is:

$$
H_1 \cap H_2 \cap \dots \cap H_n
$$

and, when bounded and nonempty, this intersection is a convex polygon.

That convexity fact is what makes the deque route possible.

## From Brute Force To The Right Idea

### Brute Force Thinking

The naive instinct is:

- intersect every pair of boundary lines
- keep only pairwise intersection points that satisfy all constraints
- somehow recover the polygon from those survivors

This is too slow and too fragile:

- `O(n^2)` line intersections already hurts
- reordering the valid vertices is annoying
- parallel-line handling becomes messy immediately

### The Structural Observation

The final feasible polygon is supported by lines in cyclic angle order.

So instead of guessing vertices directly, the correct route is:

1. sort the half-planes by the angle of their boundary direction
2. keep only the most restrictive half-plane among equal directions
3. maintain the current feasible boundary in a deque

This is the exact same kind of simplification that makes convex hull easy:

- global geometry becomes local cleanup once the order is correct

### Why Local Cleanup Works

Suppose the deque currently stores the active boundary lines of the intersection.

When a new half-plane arrives:

- if the last intersection point is outside the new half-plane, the back line cannot remain
- if the first intersection point is outside the new half-plane, the front line cannot remain

So each new constraint only needs local popping from the ends.

That is the central invariant:

```text
after angle ordering, invalidity can only appear at the deque ends
```

## Core Technique

The first exact route in this repo is:

1. represent every constraint as a directed half-plane that keeps the left side
2. sort by boundary angle
3. for equal directions, keep only the most restrictive one
4. process the sorted half-planes with a deque
5. drop lines whose consecutive intersection points are outside the new half-plane
6. after the sweep, close the polygon from the surviving deque

The reusable data flow is:

- `HalfPlane`
- `outside(point)`
- `line_intersection(a, b)`
- `halfplane_intersection(...) -> vector<Point>`

## Exact Starter Route In This Repo

- Topic: this page
- Hot sheet: [Half-Plane Intersection hot sheet](../../../notebook/half-plane-intersection-hot-sheet.md)
- Starter template: [`half-plane-intersection.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/half-plane-intersection.cpp)
- Flagship anchor: [Big Brother](../../../practice/ladders/geometry/half-plane-intersection/bigbrother.md)

The starter is intentionally honest:

- it is a **bounded polygon output** route
- it uses floating / continuous geometry with `long double`
- it assumes you already fixed the directed-side convention correctly

If the true task is an unbounded intersection, you usually need:

- a bounding box trick
- a different output contract
- or a clipping-style reduction

## Flagship Modeling: Polygon Kernel

The cleanest first rep in this repo is:

- [Big Brother](../../../practice/ladders/geometry/half-plane-intersection/bigbrother.md)

Why it fits so well:

- the camera region is exactly the polygon kernel
- the kernel is the intersection of all inward edge half-planes
- the final answer is the area of that intersection polygon

The one modeling detail you must get right is edge direction:

- if the polygon boundary is counterclockwise, the interior is already on the left of each edge
- if the polygon boundary is clockwise, reverse each edge before creating the half-plane

That one orientation choice is the whole bridge from polygon input to generic HPI.

## Complexity And Tradeoffs

For the deque-based route:

- sorting: `O(n log n)`
- deque processing: `O(n)`
- total: `O(n log n)`
- memory: `O(n)`

Practical tradeoffs:

| Route | Best when | Main tradeoff |
| --- | --- | --- |
| angle sort + deque HPI | static directed half-planes, bounded convex output | precision and parallel-line policy matter a lot |
| convex hull | outer envelope of points | wrong family if the input is already constraints, not points |
| sweep line | event ordering dominates | not the right abstraction for one static feasible region |

## Main Pitfalls

- forgetting that the starter keeps the **left** side of each directed line
- using inconsistent strict / non-strict side tests
- sorting equal-angle half-planes without keeping only the most restrictive one
- feeding a bounded-polygon snippet an unbounded instance and expecting a meaningful polygon back
- building polygon-kernel half-planes from edges without first checking boundary orientation

## Variant Chooser

| If the task feels like... | Open first | Why |
| --- | --- | --- |
| "outer boundary of points" | [Convex Hull](../convex-hull/README.md) | the boundary comes from input points, not line constraints |
| "area / inside / boundary on one polygon" | [Polygon Area And Point Location](../polygon-area-point-location/README.md) | you do not need a global feasible-region engine |
| "camera / visibility region inside a simple polygon" | this page | polygon kernel is a direct HPI model |
| "many event endpoints and active-set ordering" | [Sweep Line](../sweep-line/README.md) | the geometry is dynamic over one sweep parameter, not one static convex intersection |

## Practice Roadmap

1. reopen [Geometry cheatsheet](../../../notebook/geometry-cheatsheet.md) if side conventions still feel shaky
2. trust the exact starter route on [Big Brother](../../../practice/ladders/geometry/half-plane-intersection/bigbrother.md)
3. only after that treat half-plane intersection as a compare point in harder continuous geometry

## Solved Example In This Repo

- [Big Brother](../../../practice/ladders/geometry/half-plane-intersection/bigbrother.md): polygon kernel as the intersection of inward edge half-planes, then area of the resulting convex region

## Reusable Pattern

Carry forward:

- angle order turns a global polygon reconstruction problem into deque cleanup
- same-direction tie-breaking is part of correctness, not formatting
- polygon-kernel tasks are often just HPI in disguise

This lane adds:

- one trusted bounded HPI template
- the habit of expressing visibility / feasible-region problems as inward half-plane intersections

## Go Deeper

- Reference: [cp-algorithms half-plane intersection](https://cp-algorithms.com/geometry/halfplane-intersection.html)
- Practice: [Kattis Big Brother](https://open.kattis.com/problems/bigbrother)
- Reference: [Masaryk University half-plane intersection notes](https://is.muni.cz/do/sci/UMS/el/geometricke-alg/pages/05-intersection.html?lang=en)
