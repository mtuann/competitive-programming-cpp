# Polygon Area And Point Location

This page is the first full "polygon toolkit" layer in the repo.

Up to this point, the geometry story was mostly local:

- vectors
- orientation
- segment intersection

Polygon problems are where those local predicates finally become global structure.

Two questions dominate the beginner-to-intermediate polygon layer:

1. what is the area of this polygon?
2. where is this query point relative to the polygon?

Both questions look larger than the primitive tools they use. But in contest geometry, the right surprise is:

- polygon area is just a sum over edges
- point location is just boundary policy plus a crossing or winding rule

## At A Glance

- **Use when:** the input is a polygon in boundary order and the task asks for area, inside/outside/boundary, or nesting
- **Core invariants:** shoelace for area; boundary-first plus parity/winding logic for point location
- **Typical complexity:** `O(n)` for one polygon area or one point-in-polygon query
- **Main trap:** boundary policy and vertex handling, not the big idea itself
- **Default policy on this page:** simple polygons, integer coordinates, exact arithmetic whenever possible

## Problem Model And Notation

Let the polygon vertices be

$$
p_0, p_1, \dots, p_{n-1}
$$

in cyclic boundary order, with the implicit closing edge

$$
p_n = p_0.
$$

This "boundary order" assumption matters a lot. The standard formulas here assume:

- edges are listed in polygon order
- the polygon is simple unless stated otherwise

The two main derived quantities are:

### Signed Polygon Area

$$
2A_{\mathrm{signed}}
=
\sum_{i=0}^{n-1} p_i \times p_{i+1}.
$$

Then:

- counterclockwise order gives positive signed area
- clockwise order gives negative signed area
- absolute area is

$$
A = \frac{|2A_{\mathrm{signed}}|}{2}.
$$

### Point Classification

For a query point `q`, the usual contest output categories are:

- `INSIDE`
- `OUTSIDE`
- `BOUNDARY`

The page policy is:

- boundary is checked first
- only then do we run a global inside/outside test

That avoids many corner-case bugs.

## From Brute Force To The Right Idea

### Area: From Triangulation To Edge Sum

A naive geometric thought is:

- triangulate the polygon
- sum triangle areas

That is mathematically fine, but you do not need explicit triangulation.

The shoelace formula gives the same answer directly from the boundary walk:

$$
\sum p_i \times p_{i+1}.
$$

So polygon area becomes an edge-accumulation problem.

### Point Location: From Drawing Rays To A Parity Invariant

For point-in-polygon, the naive picture is:

- draw a ray from the query point
- count how many times it crosses the polygon boundary

That picture is actually the right algorithmic intuition, but it needs one careful refinement:

- polygon vertices cannot be double-counted

So the mature contest version is:

1. boundary check first
2. then use a half-open crossing rule for parity

The Jordan-curve intuition behind this is simple:

- a ray from an outside point crosses the boundary an even number of times
- a ray from an inside point crosses it an odd number of times

For simple polygons, that is the core parity invariant.

## Core Invariant And Why It Works

### Why Shoelace Works

Each term

$$
p_i \times p_{i+1}
$$

is the signed area contribution of the directed edge from `p_i` to `p_{i+1}`.

When you sum all edge contributions around the polygon, interior cancellations leave exactly the oriented area of the whole closed curve.

So:

$$
2A_{\mathrm{signed}}
=
\sum_{i=0}^{n-1} p_i \times p_{i+1}.
$$

This is why shoelace is best understood as:

- a boundary sum
- not a memorized coordinate trick

### Why Signed Area Is Useful

Signed area does more than compute size.

It also tells orientation:

- positive -> counterclockwise
- negative -> clockwise

That means one pass can simultaneously answer:

- polygon area
- boundary orientation

### Why Point-In-Polygon Needs Boundary First

Before any parity or winding logic, ask:

- does the query lie on some edge?

Because if it does, then:

- the correct answer is `BOUNDARY`
- and any later crossing logic is both unnecessary and easy to mis-handle

So the clean invariant is:

1. boundary is resolved first
2. parity / winding only decides inside vs outside for non-boundary points

### Why Ray Casting Works

Fix a ray from the query point, usually horizontally to the right.

For a simple polygon:

- every proper boundary crossing flips whether you are currently inside or outside

So:

- odd number of crossings -> inside
- even number of crossings -> outside

The entire implementation challenge is making "proper crossing" precise enough that polygon vertices are not counted twice.

### Why Vertex Handling Needs A Half-Open Rule

Suppose the ray passes exactly through a polygon vertex.

Two adjacent edges meet there. If both are counted as crossings, parity breaks.

The standard repair is:

- count one endpoint of each edge
- exclude the other

That is why implementations usually test something like:

- one endpoint strictly below the ray
- the other not strictly below

or the symmetric half-open variant.

In the repo starter, this appears as a half-open comparison on the edge endpoints' `y` coordinates against the query `y`, followed by an orientation-side test.

### Winding Number Versus Parity

There are two classic point-in-polygon viewpoints:

- **parity / even-odd rule**
- **winding number**

For simple polygons and ordinary contest queries:

- parity is usually enough

Winding number becomes attractive when:

- orientation matters
- self-intersection or signed wrapping ideas matter
- you want the stronger "how many times does the polygon wrap around the point?" interpretation

This page focuses on parity first, since it is the cleaner default for contest implementation.

## Variant Chooser

### Use Shoelace When

- vertices are already given in cyclic order
- the task asks for area or doubled area
- exact integer arithmetic is available

Canonical examples:

- polygon area
- orientation of polygon boundary
- cheap first key for nesting / sorting polygons

### Use Boundary-First + Ray Casting When

- the polygon is simple
- queries ask for inside / outside / boundary
- you want a straightforward linear-time method

This is the default contest point-in-polygon tool.

### Think About Winding Number When

- the polygon orientation matters
- the notion of wrapping around the point matters
- the setting is slightly more topological than pure parity

For most standard judge tasks, parity is simpler and enough.

### Think About Convex-Polygon Point Location When

- the polygon is guaranteed convex
- there are many queries

Then you can often do better than `O(n)` per query using orientation structure and binary search.

### Think About Sweep Line Or Planar Subdivision Structures Only Later

If you need:

- many segments
- many polygons
- many point-location queries

then heavier preprocessing or sweep structures may be appropriate. But this page is about the first exact polygon toolkit, not about large-scale spatial data structures.

## Worked Examples

### Example 1: Shoelace On A Rectangle

Take the polygon:

$$
(0,0), (4,0), (4,3), (0,3).
$$

Then:

$$
\sum p_i \times p_{i+1}
=
(0,0)\times(4,0)
 + (4,0)\times(4,3)
 + (4,3)\times(0,3)
 + (0,3)\times(0,0).
$$

This gives:

$$
0 + 12 + 12 + 0 = 24.
$$

So:

$$
2A = 24, \qquad A = 12.
$$

This is why CSES `Polygon Area` can ask for doubled area and stay entirely in integer arithmetic.

### Example 2: Boundary First In Point-In-Polygon

Take the square:

$$
(0,0), (4,0), (4,4), (0,4)
$$

and query point

$$
q=(4,2).
$$

The point lies on the right edge.

So before any ray-casting logic, `on_segment` returns true, and the answer is immediately:

```text
BOUNDARY
```

This is the correct workflow. If you skip this step and jump to parity first, you will eventually fight edge-case bugs around horizontal or vertex-adjacent rays.

### Example 3: Parity For An Interior Point

Take the same square and query:

$$
q=(2,2).
$$

Cast a ray to the right.

It crosses the polygon boundary once before escaping to infinity, so the number of crossings is odd.

Therefore the point is:

```text
INSIDE
```

### Example 4: Why Vertex Double Counting Is Dangerous

Imagine a ray that passes through a polygon vertex.

If both incident edges are counted as crossings, then one geometric event flips parity twice and cancels itself incorrectly.

This is exactly why a half-open rule is used:

- count one endpoint conventionally
- exclude the other

Without that convention, parity-based point location is fragile.

### Example 5: Area As A Nesting Hint, Not A Proof

Suppose you have several simple polygons and want to reason about containment.

Area is useful as:

- a cheap sorting key

But larger area alone does not prove containment.

The right workflow is often:

1. sort or group by area as a heuristic/ordering aid
2. verify containment with point location

This is where shoelace and point-in-polygon become a natural pair.

## Algorithm And Pseudocode

Repo starter templates:

- [shoelace-area.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/shoelace-area.cpp)
- [point-in-polygon.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/point-in-polygon.cpp)

### Shoelace Area

```text
area2 = 0
for i in [0, n):
    j = (i + 1) mod n
    area2 += cross(p[i], p[j])

signed_area = area2 / 2
absolute_area = abs(area2) / 2
```

### Boundary-First Point In Polygon

```text
point_in_polygon(poly, q):
    inside = false

    for each edge (a, b):
        if on_segment(a, b, q):
            return BOUNDARY

        if edge passes the half-open vertical filter for q.y:
            inside = not inside

    return INSIDE if inside else OUTSIDE
```

That half-open filter is exactly what prevents one polygon vertex from contributing two crossings at once.

## Implementation Notes

### 1. Do Not Forget The Closing Edge

Polygon formulas are cyclic.

That means:

- after `p[n-1]`
- you must include the edge back to `p[0]`

This is the single easiest shoelace bug.

### 2. Prefer `__int128` For Cross-Sum Safety

With coordinates around `10^9`, a single cross product can already be near:

$$
10^{18}.
$$

Summing many such terms can exceed a comfortable `long long` safety margin, so `__int128` is the safer contest default for intermediate accumulation.

### 3. Decide Signed Versus Absolute Area Early

Some tasks want:

- signed area
- doubled area
- absolute area

Do not normalize too early if the sign still contains useful information.

### 4. Boundary Policy Must Be Explicit

For point location, the first question is not "inside or outside?" It is:

- what does the statement want for boundary points?

The usual contest policy is a three-way answer:

- `INSIDE`
- `OUTSIDE`
- `BOUNDARY`

### 5. Horizontal Edges Are Where Ray Casting Gets Slippery

The parity idea is easy.

The correct implementation is not.

Horizontal edges and vertex hits are exactly why:

- you should use a consistent half-open crossing rule
- and check boundary first

### 6. Simple Polygon Assumption Matters

This page assumes a simple polygon.

If the polygon self-intersects, then:

- area interpretation changes
- winding and parity semantics become more subtle

Do not silently extend simple-polygon logic beyond its intended model.

### 7. Shoelace And Point Location Reuse The Same Primitive Layer

This topic is a good example of why the earlier geometry pages matter:

- shoelace uses cross sums
- point location uses orientation and `on_segment`

So polygon problems often feel easier once the primitive layer is already trusted.

### 8. Convex Polygons Are A Special, Faster Subcase

If the polygon is convex and there are many point queries, you should think about:

- orientation-based binary search

instead of doing `O(n)` ray casting every time.

## Beyond Basic Polygon Toolkit

The core contest layer is:

- shoelace area
- boundary-aware point location
- parity and winding intuition

Important next-layer directions include:

- convex-polygon point queries
- polygon clipping
- sweep-line polygon interaction
- planar subdivision point location
- Pick's theorem and lattice-geometry add-ons

The right study order is:

1. learn shoelace as a boundary sum
2. master boundary-first point-in-polygon
3. then move to convex-specific or many-query optimizations

## Practice Archetypes

The most common polygon-shaped tasks are:

- **compute polygon area**
- **classify a point as inside / outside / boundary**
- **sort or compare polygons by area**
- **nesting / containment reasoning**
- **use polygon predicates as building blocks inside a larger geometry solution**

The strongest contest smell is:

- the polygon is already given in cyclic order
- the solution is global in appearance
- but every real step is still an edge-based primitive

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Course / notes:

- [HKOI Training Geometry Notes](https://assets.hkoi.org/training2023/geom.pdf)
- [Tufts Computational Geometry Notes: Point Inclusion in a Polygon](https://www.cs.tufts.edu/comp/163/notes05/)
- [Rice COMP 360: Some Applications of Vector Geometry](https://www.clear.rice.edu/comp360/lectures/old/ApplicationsofVG.pdf)

Reference:

- [CP-Algorithms: Oriented Area of a Triangle](https://cp-algorithms.com/geometry/oriented-triangle-area.html)
- [Wikipedia: Shoelace Formula](https://en.wikipedia.org/wiki/Shoelace_formula)
- [Wikipedia: Point in Polygon](https://en.wikipedia.org/wiki/Point_in_polygon)

Essay / theorem context:

- [Jeff Erickson: The Jordan Polygon Theorem](https://jeffe.cs.illinois.edu/teaching/comptop/2023/notes/01-simple-polygons.pdf)
- [Sidvind: Point-in-polygon and the Jordan Curve Theorem intuition](https://sidvind.com/wiki/Point-in-polygon%3A_Jordan_Curve_Theorem)

Practice:

- [CSES Geometry](https://cses.fi/problemset/list/)

Repo anchors:

- practice ladder: [Polygon Area And Point-Location ladder](../../../practice/ladders/geometry/polygon-area-point-location/README.md)
- practice note: [Polygon Area](../../../practice/ladders/geometry/polygon-area-point-location/polygonarea.md)
- practice note: [Point in Polygon](../../../practice/ladders/geometry/polygon-area-point-location/pointinpolygon.md)
- starter template: [shoelace-area.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/shoelace-area.cpp)
- starter template: [point-in-polygon.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/point-in-polygon.cpp)
- notebook refresher: [Geometry cheatsheet](../../../notebook/geometry-cheatsheet.md)

## Related Topics

- [Vector And Orientation](../vector-orientation/README.md)
- [Segment Intersection](../segment-intersection/README.md)
- [Convex Hull](../convex-hull/README.md)
- [Sweep Line](../sweep-line/README.md)
