# Minkowski Sum

This lane starts when the geometry object is no longer:

```text
one polygon boundary by itself
```

and becomes:

```text
the convex polygon formed by adding every point of one convex polygon
to every point of another
```

The repo keeps the first exact route deliberately narrow:

- two **convex** polygons
- vertices already in **counterclockwise** order
- integer coordinates
- output the convex polygon of their Minkowski sum in linear time after normalization

This page does **not** start with:

- non-convex polygons
- polygon decomposition
- three-dimensional polytope sums
- generic motion planning

The first reusable move is:

```text
rotate both convex polygons to the same lowest-vertex convention,
then merge their edge-direction sequences
```

That same family later connects to:

- collision / intersection checks via `P + (-Q)`
- distance between convex polygons
- repeated sums of several convex polygons

but the first snippet to trust is still:

```text
two CCW convex polygons -> one CCW convex Minkowski sum
```

## At A Glance

- **Use when:** the statement is really about all sums `a + b` with `a in P`, `b in Q`, or about one follow-up that reduces to that object
- **Core worldview:** the sum of two convex polygons is itself one convex polygon whose edge directions are the merged edge directions of the inputs
- **Main tools:** convex polygon order, lowest-vertex normalization, cross-product angle comparison, optional point-in-convex follow-up
- **Typical complexity:** `O(|P| + |Q|)` after the polygons are already in cyclic CCW order
- **Main trap:** forgetting that the route assumes **convex + CCW**, not arbitrary polygon clipping

Strong contest signals:

- "sum of two convex polygons"
- "choose one point from each convex region and ask what positions are possible"
- "distance / collision between convex polygons" after reflecting one polygon
- a point query naturally turns into `q in P + Q` or `q in P + (-Q)`

Strong anti-cues:

- the boundary comes from input points -> [Convex Hull](../convex-hull/README.md)
- the region comes from directed line constraints -> [Half-Plane Intersection](../half-plane-intersection/README.md)
- the polygons are not convex and decomposition would dominate the problem
- the real problem is just one point-in-polygon query -> [Polygon Area And Point Location](../polygon-area-point-location/README.md)

## Prerequisites

- [Vector And Orientation](../vector-orientation/README.md)
- [Convex Hull](../convex-hull/README.md)
- [Polygon Area And Point Location](../polygon-area-point-location/README.md)

Helpful neighboring anchors:

- [Half-Plane Intersection](../half-plane-intersection/README.md)
- [Geometry cheatsheet](../../../notebook/geometry-cheatsheet.md)

## Problem Model And Notation

For two point sets `A` and `B` in the plane, the Minkowski sum is:

$$
A + B = \{a + b \mid a \in A,\ b \in B\}.
$$

In this lane we restrict to convex polygons `P` and `Q`, represented by their vertices in CCW cyclic order.

Then:

- `P + Q` is also a convex polygon
- its number of vertices is at most `|P| + |Q|`

The key structural fact is:

- if both polygons start at the same canonical lowest vertex
- then their directed edge vectors are already sorted by polar angle
- so the edge list of `P + Q` is just the merge of those two angle-sorted edge lists

## From Brute Force To The Right Idea

### Brute Force Thinking

The naive definition suggests:

- take every vertex of `P`
- take every vertex of `Q`
- form all pairwise sums
- then hull those points

That works conceptually, but it is `O(|P||Q|)` points before the hull.

### The Structural Observation

For convex polygons in CCW order, the boundary edges already come in cyclic angle order.

So instead of summing all vertices, the correct route is:

1. rotate each polygon so it starts at the lowest `(y, x)` vertex
2. walk around both polygons with two pointers
3. compare the cross product of the current edge vectors
4. advance the smaller-angle edge (or both on equal angle)

This is the exact same kind of simplification as merging two sorted arrays:

- the hard global geometry becomes one linear local merge

## Core Technique

The first exact route in this repo is:

1. normalize both polygons to start from the lowest `(y, x)` vertex
2. treat edges cyclically
3. append the current point sum `P[i] + Q[j]`
4. compare `(P[i + 1] - P[i])` with `(Q[j + 1] - Q[j])` by cross product
5. advance:
   - `P` if cross `>= 0`
   - `Q` if cross `<= 0`
6. compress any redundant collinear points if needed

The reusable data flow is:

- `normalize_convex_polygon`
- `minkowski_sum_convex(P, Q)`
- optional `point_in_convex` when the final task is one query problem on the sum polygon

## Exact Starter Route In This Repo

- Topic: this page
- Hot sheet: [Minkowski Sum hot sheet](../../../notebook/minkowski-sum-hot-sheet.md)
- Starter template: [`minkowski-sum-convex.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/minkowski-sum-convex.cpp)
- Current stretch anchor: [Mogohu-Rea Idol](../../../practice/ladders/geometry/minkowski-sum/mogohureaidol.md)

The starter is intentionally honest:

- it is a **two convex polygons** route
- it assumes CCW boundary order
- it uses integer geometry with `__int128` cross products
- it does **not** promise non-convex polygon support

If the true task needs:

- arbitrary polygons
- decomposition
- or repeated interval/range queries over many polygons

then more machinery is required than this first route advertises.

## Current Stretch Anchor: Mogohu-Rea Idol

The current in-repo stretch anchor is:

- [Mogohu-Rea Idol](../../../practice/ladders/geometry/minkowski-sum/mogohureaidol.md)

Why it fits:

- choose one altar point from each of three convex cities
- their center of mass must equal the hill point `h`
- with equal masses this means:

$$
a + b + c = 3h
$$

So the set of all achievable `a + b + c` is exactly:

$$
P_1 + P_2 + P_3
$$

That turns every hill query into:

- scale the hill by `3`
- test whether that point lies in the repeated Minkowski sum polygon

So the flagship is:

- repeated Minkowski sum
- then one `point_in_convex` query family

It is intentionally **not** the first benchmark for the lane.

The first benchmark is still:

- two convex polygons
- one merged sum polygon
- one trusted edge-direction merge

## Complexity And Tradeoffs

For the exact starter route:

- normalize + merge: `O(|P| + |Q|)`
- memory: `O(|P| + |Q|)`

Practical tradeoffs:

| Route | Best when | Main tradeoff |
| --- | --- | --- |
| convex Minkowski merge | polygons are convex and already ordered | wrong if the real issue is non-convexity or missing order |
| convex hull of all pairwise sums | tiny inputs or brute-force verification | too slow for contest-scale convex polygons |
| half-plane intersection | the answer is defined by line constraints, not by point addition | not the same geometric object |
| point-in-polygon only | you already have the final polygon and only need classification | does not construct the sum polygon |

## Main Pitfalls

- forgetting that the route assumes **convex polygons in CCW order**
- failing to rotate both polygons to the same lowest-vertex convention
- comparing edge angles by floating-point angle instead of by cross product
- forgetting that many collision / distance tricks require `P + (-Q)`, not `P + Q`
- treating non-convex input as if this linear merge still applied

## Variant Chooser

| If the task feels like... | Open first | Why |
| --- | --- | --- |
| "outer envelope of input points" | [Convex Hull](../convex-hull/README.md) | the boundary comes from points, not from polygon addition |
| "feasible region cut by lines" | [Half-Plane Intersection](../half-plane-intersection/README.md) | the object is one intersection, not one sum |
| "add convex polygons / reflect one / query the sum polygon" | this page | the edge-merge route is the right abstraction |
| "just classify points in one polygon" | [Polygon Area And Point Location](../polygon-area-point-location/README.md) | you do not need to build a Minkowski sum first |

## Practice Roadmap

1. trust [Convex Hull](../convex-hull/README.md) and cyclic convex order first
2. trust the exact starter route on two convex polygons
3. then use repeated sums plus point-in-convex on the stretch anchor [Mogohu-Rea Idol](../../../practice/ladders/geometry/minkowski-sum/mogohureaidol.md)

## References And Practice

- [cp-algorithms - Minkowski sum of convex polygons](https://cp-algorithms.com/geometry/minkowski.html)
- [Codeforces 87E - Mogohu-Rea Idol](https://codeforces.com/problemset/problem/87/E)
