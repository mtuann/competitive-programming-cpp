# Counting Geometry

Counting geometry problems are the place where simple predicates meet huge tuple spaces.

The geometry itself is often local and exact:

- orientation
- perpendicularity
- same line
- same slope
- point inside polygon

The hard part is usually elsewhere:

- there are too many pairs, triples, or quadruples to test directly
- one local geometric relation repeats across many candidate tuples
- the winning move is to convert geometry into grouping, frequency counting, or sweep-order counting

So this page is not about one algorithm.

It is about one modeling habit:

> normalize the geometric relation first, then count on the normalized objects.

## At A Glance

- **Use when:** the statement asks for numbers of triangles, right angles, intersections, visible relations, or lattice-point quantities, and the raw tuple space is too large.
- **Core worldview:** many geometry-counting tasks collapse into one of three families:
  - fix an anchor and count normalized directions
  - sort or sweep an event order and count structural changes
  - convert polygon data into arithmetic counts such as area and lattice-boundary formulas
- **Main tools:** direction normalization, complementary class counting, sweep-order counting, shoelace area, `gcd`-based boundary counts, Pick's theorem on lattice polygons.
- **Main trap:** using a non-canonical key or a fuzzy boundary policy and then blaming the counting logic.
- **Success after studying this page:** you can decide whether the problem is really about direction classes, order changes, or lattice arithmetic before writing any heavy code.

Current repo support is strongest for:

- normalized-direction counting
- polygon/lattice arithmetic primitives

The sweep-order branch is taught here as a real family, but its heavier implementation detail still lives mainly in [Sweep Line](../sweep-line/README.md).

## Quick Route

```text
1. The property is local to one chosen point.
   Fix that point, normalize vectors to all others, and count matching or perpendicular classes.

2. The answer depends on the order of many geometric objects as a sweep moves.
   Reopen Sweep Line and count events or order changes instead of all pairs.

3. The polygon has integer coordinates and the question asks about area or lattice points.
   Use shoelace, boundary-point counts, and possibly Pick's theorem.
   In this repo, this branch is currently primitive-backed more than note-backed.

4. The problem is only asking one exact predicate on one pair or one query point.
   This page is too big; reopen Vector/Orientation, Segment Intersection, or Polygon Area first.
```

## Prerequisites

- [Vector And Orientation](../vector-orientation/README.md)
- [Segment Intersection](../segment-intersection/README.md)
- [Polygon Area And Point Location](../polygon-area-point-location/README.md)
- [Counting Basics](../../combinatorics/counting-basics/README.md)

Helpful neighboring topics:

- [Sweep Line](../sweep-line/README.md)
- [Lexicographic Enumeration](../../combinatorics/lexicographic-enumeration/README.md)

## Problem Model And Notation

Let the input be a set of geometric objects:

$$
\mathcal{O} = \{o_1, o_2, \dots, o_n\}.
$$

A counting-geometry problem usually asks for the number of tuples satisfying some predicate:

$$
\#\{(o_{i_1}, \dots, o_{i_k}) : \Phi(o_{i_1}, \dots, o_{i_k})\}.
$$

The brute force is often:

$$
O(n^k).
$$

The compression step is to replace raw objects by one smaller counting representation:

- a **normalized key** such as slope, direction, or line class
- an **event order** under a sweep
- an **arithmetic summary** such as doubled area or number of lattice points on an edge

Two formulas recur often enough to state explicitly.

### Direction Normalization

For a nonzero vector `(dx, dy)`, a common canonical direction key is:

$$
\left(\frac{dx}{g}, \frac{dy}{g}\right),
\qquad
g = \gcd(|dx|, |dy|),
$$

plus one fixed sign convention.

If the problem is about **undirected lines through an anchor**, then opposite directions should be merged into the same key.

If the problem is about **oriented rays**, they should not.

### Lattice Boundary Counts

For one lattice edge from `p_i = (x_i, y_i)` to `p_{i+1} = (x_{i+1}, y_{i+1})`, the number of lattice points on that closed segment is:

$$
\gcd(|x_{i+1} - x_i|, |y_{i+1} - y_i|) + 1.
$$

When summing polygon boundary points edge-by-edge, the shared vertices are naturally double-counted once each, so the total boundary-point count of a simple lattice polygon becomes:

$$
B = \sum_i \gcd(|\Delta x_i|, |\Delta y_i|).
$$

If the polygon is simple and all vertices lie on the integer lattice, Pick's theorem says:

$$
A = I + \frac{B}{2} - 1,
$$

where:

- $A$ is the area
- $I$ is the number of interior lattice points
- $B$ is the number of boundary lattice points

This gives the integer-only formula:

$$
I = A - \frac{B}{2} + 1.
$$

If you already have doubled area `area2 = 2A`, then:

$$
I = \frac{area2 - B + 2}{2}.
$$

## From Brute Force To The Right Idea

### Brute Force: Test Every Tuple

Naively, many geometry-counting tasks say:

- try every pair
- try every triple
- try every quadruple

and test the geometric predicate directly.

That is often correct and completely unusable.

### The Real Compression

Most workable solutions make one of three moves.

#### 1. Fix One Anchor

If the geometric condition is local to one vertex, point, or line, fix it first.

Then the remaining candidates become:

- vectors from the anchor
- directions around the anchor
- distances from the anchor

This is the trick behind counting:

- right triangles by right-angle vertex
- equal-angle or equal-slope configurations around one point

#### 2. Replace Geometry By Ordered Events

If the statement is really about:

- crossings
- nesting
- visible order
- active intervals under a moving line

then the right model is often a sweep, not tuple testing.

You stop asking "which pairs intersect?" and start asking:

- "when does the order change?"
- "which objects are active now?"

#### 3. Replace Shapes By Arithmetic Summaries

If the objects are lattice polygons or ordered polygon boundaries, the geometry often collapses into:

- cross sums
- `gcd` boundary counts
- area + boundary formulas

Then the hard geometry is already gone; what remains is exact arithmetic.

## Core Invariant And Why It Works

This page is really about five reusable counting-geometry moves.

### 1. Canonicalization Must Happen Before Counting

If two geometric objects represent the same relation, they must map to the same key.

Examples:

- slopes differing by a common scale factor
- vectors `(2, 4)` and `(1, 2)`
- opposite rays that should collapse into one undirected line direction

The invariant is:

> equal geometric relations must become equal keys, and unequal relations that matter to the count must stay distinguishable.

If this fails, the counting is wrong even when the hash table or sort is flawless.

### 2. Anchor-First Counting Works When The Predicate Is Local

Suppose the property depends on one chosen pivot `P`.

Then:

- fix `P`
- rewrite all other objects relative to `P`
- count compatible pairs or groups in that local representation

This is why [PRAVO](../../../practice/ladders/geometry/right-triangles/pravo.md) becomes a direction-counting problem instead of a triangle-enumeration problem.

The correctness argument is usually:

- every desired configuration has exactly one anchor of the chosen type
- for that anchor, the local compatibility relation is complete

That turns a global geometric count into many local frequency counts.

### 3. Complementary Classes Are Often The Whole Counting Problem

After normalization, many tasks reduce to:

- same direction
- opposite direction
- perpendicular direction
- same line class
- same active-order bucket

At that point, the geometry is over.

The problem is now:

- frequency counting
- two-sum style complementary counting
- map/sort + group

The essential proof obligation is not geometric anymore. It is:

- why every valid tuple is represented exactly once in the counting decomposition

### 4. Sweep-Order Counting Works When Only Local Changes Matter

For crossing-like tasks, the key invariant is often:

> between consecutive events, the combinatorial order is stable.

Then the answer is not counted by raw pair testing.

It is counted by:

- event insertions / removals
- neighbor swaps
- order statistics in the active structure

This is the natural bridge to [Sweep Line](../sweep-line/README.md).

Counting geometry often needs sweep line not for reporting one intersection, but for counting many of them without enumerating all tuples explicitly.

### 5. Lattice Geometry Adds Arithmetic Certificates

For lattice polygons, exact arithmetic gives stronger structure.

Two particularly useful facts are:

- boundary-point count per edge comes from `gcd(|dx|, |dy|)`
- area comes from shoelace

When both are available, Pick's theorem turns geometry into counting:

$$
I = A - \frac{B}{2} + 1.
$$

This is not a generic polygon theorem.

It needs:

- simple polygon
- integer-coordinate vertices

Under those assumptions, many "count lattice points" problems become arithmetic post-processing on top of area and boundary counts.

## Complexity And Tradeoffs

Typical tradeoffs:

| Strategy | Typical win | Main risk |
| --- | --- | --- |
| fix anchor + hash/sort normalized directions | `O(n^2)` or `O(n^2 \log n)` instead of `O(n^3)` | wrong canonical key or double-counting |
| sweep-order counting | `O((n+k)\log n)` or `O(n \log n)` style event processing | event policy and active-order bugs |
| lattice formulas | exact `O(n)` or `O(n \log C)` arithmetic after geometry preprocessing | applying Pick's theorem outside its assumptions |

Sorting versus hashing:

- sorting is often easier to trust and debug
- hashing may remove a `log n`, but only after the canonical key is obviously correct

Integer versus floating-point geometry:

- counting geometry strongly prefers exact integer representations whenever the input allows it
- floating equality is almost always the wrong default for exact-input contest tasks

## Variant Chooser

| Situation | Default move | When to choose it | Where it fails |
| --- | --- | --- | --- |
| right-angle / local-angle counting around one point | fix anchor + normalize directions | the property is local to one distinguished vertex | if no unique local anchor exists |
| same-slope / parallel / perpendicular grouping | canonical direction or line key | geometry relation can be expressed as a reduced integer pair | if the sign convention is ambiguous or inconsistent |
| crossing / nesting / visible-order counting | sweep line | only event coordinates matter and local order drives the count | if the active comparator is unstable or events are ill-defined |
| lattice polygon area / boundary / interior counts | shoelace + boundary gcd + Pick | polygon is simple and vertices are integral | if polygon is non-lattice, self-intersecting, or has holes without extra care |

Anti-cues:

- if one exact predicate on one pair solves the whole task, reopen [Vector And Orientation](../vector-orientation/README.md) or [Segment Intersection](../segment-intersection/README.md) instead
- if the problem is really polygon membership or area only, reopen [Polygon Area And Point Location](../polygon-area-point-location/README.md)
- if the hard part is maintaining a moving order, use [Sweep Line](../sweep-line/README.md) as the main topic and use this page only as a counting bridge

## Worked Examples

### Example 1: Right Triangles By Fixed Pivot

Take [PRAVO](../../../practice/ladders/geometry/right-triangles/pravo.md).

Brute force would try all triples of points and test whether one angle is right.

That is `O(n^3)`.

The right compression is:

1. fix one point `P` as the candidate right-angle vertex
2. replace every other point by the vector from `P`
3. normalize those vectors into undirected direction classes
4. count perpendicular class pairs

Why does this work?

- every right triangle has exactly one right-angle vertex
- once that vertex is fixed, the remaining condition is purely about two perpendicular directions

So the geometry reduces to local complementary counting.

### Example 2: Lattice Polygon Interior Points

Suppose a problem gives a simple polygon with integer coordinates and asks for the number of lattice points strictly inside it.

The direct brute force idea:

- scan a bounding box
- test every lattice point with point-in-polygon

is usually terrible.

The right route is:

1. compute doubled area `area2` by shoelace
2. compute

$$
B = \sum_i \gcd(|\Delta x_i|, |\Delta y_i|)
$$

3. apply

$$
I = \frac{area2 - B + 2}{2}
$$

This is a counting-geometry solution because:

- geometry provided the exact formulas
- the final answer is obtained by arithmetic counting, not region enumeration

### Example 3: Counting Intersections By Sweep Order

Take the classic problem:

- count intersections between many horizontal segments and many vertical segments

The brute force is:

- test every horizontal segment against every vertical segment

which is quadratic.

The right sweep picture is:

1. sweep from left to right
2. when a horizontal segment starts, activate its `y`
3. when a horizontal segment ends, deactivate its `y`
4. when a vertical segment at `x` is processed, count how many active horizontals have `y` inside its vertical span

Now the answer is no longer "sum over all segment pairs."

It becomes:

- insert/delete active horizontal levels
- range-count active `y` values on each vertical event

So the geometry has been compressed into:

- event ordering
- active-set maintenance
- one range counting query per vertical segment

That is the sweep-order branch in its purest counting form.

For a repo-native bridge where sweep order supports a harder geometry structure, see [KINGDOMS](../../../practice/ladders/geometry/sweep-line/kingdoms.md).

## Algorithm And Pseudocode

Because this is a family page, the right pseudocode is a chooser skeleton.

### Anchor-Based Counting

```text
answer = 0
for each anchor P:
    clear frequency structure
    for each other point Q:
        key = normalize(Q - P)
        record key
    for each key class:
        add the contribution of matching/complementary classes
```

The key design choice is what `normalize` means:

- directed or undirected
- slope or full direction
- complementary by negation, rotation, or equality

### Lattice-Polygon Counting

```text
area2 = shoelace(vertices)
B = 0
for each edge (p[i], p[i+1]):
    B += gcd(abs(dx), abs(dy))
I = (abs(area2) - B + 2) / 2
```

Use this only when the assumptions of Pick's theorem hold.

## Implementation Notes

- Normalize integer directions with one fixed sign convention before counting.
- Decide whether opposite directions should merge or stay distinct.
- Handle the zero vector explicitly when duplicate points are possible.
- Prefer `long long` for coordinates and counts; prefer `__int128` for large cross products or doubled areas.
- In lattice formulas, keep everything in doubled-area integer form as long as possible.
- Sorting is usually easier to debug than hashing when the canonical key is new.
- In this repo, the lattice-counting branch is currently backed mainly by polygon primitives rather than a dedicated solved note, so treat it as a geometry-to-arithmetic bridge, not yet as its own mature note cluster.
- Good starter templates:
  - [geometry-primitives.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/geometry-primitives.cpp)
  - [shoelace-area.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/shoelace-area.cpp)
- If the active-order invariant becomes the real difficulty, reopen [Sweep Line](../sweep-line/README.md) instead of overloading this page.

## Practice Archetypes

- **Warm-up**
  - [Point Location Test](../../../practice/ladders/geometry/vector-orientation/pointlocationtest.md)
    Why: reinforces the exact orientation predicate that many counting tasks build on.
  - [Polygon Area](../../../practice/ladders/geometry/polygon-area-point-location/polygonarea.md)
    Why: first exact polygon-arithmetic primitive before moving to lattice counting formulas.
- **Core**
  - [PRAVO](../../../practice/ladders/geometry/right-triangles/pravo.md)
    Why: canonical anchor-and-direction counting problem.
- **Stretch**
  - [KINGDOMS](../../../practice/ladders/geometry/sweep-line/kingdoms.md)
    Why: good bridge from counting geometry into full sweep-line state maintenance; the main implementation ownership still belongs to the sweep-line family.
  - [Point in Polygon](../../../practice/ladders/geometry/polygon-area-point-location/pointinpolygon.md)
    Why: not a counting problem by itself, but a useful reminder that exact boundary policy often decides whether counting reductions are trustworthy.

## References And Repo Anchors

- **Course**
  - [MIT 6.046J lecture notes on computational geometry](https://courses.csail.mit.edu/6.046/spring03/handouts/lec19.pdf)
  - [CMU computational geometry notes on line-segment intersection / sweep line](https://www.cs.cmu.edu/afs/cs/academic/class/15456-s10/ClassNotes/lecture4.pdf)
- **Reference**
  - [CP-Algorithms: Basic Geometry](https://cp-algorithms.com/geometry/basic-geometry.html)
  - [CP-Algorithms: Pick's Theorem](https://cp-algorithms.com/geometry/picks-theorem.html)
  - [OI Wiki: Geometry](https://en.oi-wiki.org/geometry/)
- **Practice**
  - [CSES Geometry tasks](https://cses.fi/problemset/list/)
  - [VN SPOJ / VNOI geometry practice](https://oj.vnoi.info/problems/)
- **Repo anchors**
  - [Counting-Geometry Ladder](../../../practice/ladders/geometry/counting-geometry/README.md) (currently strongest on the normalization branch)
  - [PRAVO](../../../practice/ladders/geometry/right-triangles/pravo.md)
  - [Polygon Area](../../../practice/ladders/geometry/polygon-area-point-location/polygonarea.md)
  - [Polygon Area And Point Location](../polygon-area-point-location/README.md)
  - [Sweep Line](../sweep-line/README.md)
  - [Geometry Cheatsheet](../../../notebook/geometry-cheatsheet.md)
  - [geometry-primitives.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/geometry-primitives.cpp)
  - [shoelace-area.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/shoelace-area.cpp)

## Related Topics

- [Vector And Orientation](../vector-orientation/README.md)
- [Segment Intersection](../segment-intersection/README.md)
- [Polygon Area And Point Location](../polygon-area-point-location/README.md)
- [Sweep Line](../sweep-line/README.md)
- [Counting Basics](../../combinatorics/counting-basics/README.md)
