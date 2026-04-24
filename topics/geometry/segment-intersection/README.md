# Segment Intersection

Segment intersection is one of the first geometry topics where a tiny predicate has to carry a lot of weight.

On paper, the statement sounds small:

- do two closed segments intersect?

In practice, almost every bug comes from one of these:

- endpoint touching
- collinearity
- overlap on the same supporting line
- mixing strict and non-strict policies

This is why segment intersection is such an important topic. Once this predicate is trustworthy, many larger geometry algorithms become much less scary.

## At A Glance

- **Use when:** you must decide whether two closed segments cross or touch
- **Core invariant:** orientation signs handle the general case; `on_segment` handles degeneracies
- **Typical complexity:** `O(1)` per pair
- **Main trap:** the hard part is not the crossing case, but the collinear policy
- **Do not use floating point when:** inputs are integers and the task is purely combinatorial

## Problem Model And Notation

Let the two closed segments be:

$$
\overline{ab}
\quad\text{and}\quad
\overline{cd}.
$$

We work with the orientation predicate

$$
\mathrm{orient}(a,b,c) = \mathrm{cross}(b-a, c-a).
$$

Its sign tells where `c` lies relative to the directed line `a -> b`:

- positive: `c` is to the left
- negative: `c` is to the right
- zero: `a, b, c` are collinear

The intersection policy on this page is for **closed segments**:

- touching at an endpoint counts
- collinear overlap counts

This is the default policy for most contest segment-intersection predicates, including CSES `Line Segment Intersection`.

If a problem wants **strict intersection only**, you will need a stricter version later. But the right way to learn the topic is:

1. get the closed-segment predicate perfectly correct
2. then derive strict variants from it

## From Brute Force To The Right Idea

### Brute Force Through Line Equations

A tempting first approach is:

- compute the intersection point of the two infinite lines
- then check whether that point lies inside both segments

This is mathematically valid, but it is a poor contest default because:

- parallel and collinear cases branch awkwardly
- rational coordinates appear even when inputs are integers
- boundary precision becomes annoying if you switch to floating point

So the better question is:

- can we decide intersection using only exact sign tests and interval checks?

Yes. That is exactly what orientation gives us.

### The Geometric Picture

For the general case, two segments intersect if:

- `c` and `d` lie on different sides of the line through `ab`
- and `a` and `b` lie on different sides of the line through `cd`

This suggests computing:

```text
o1 = orient(a, b, c)
o2 = orient(a, b, d)
o3 = orient(c, d, a)
o4 = orient(c, d, b)
```

If:

- `o1` and `o2` have opposite signs
- `o3` and `o4` have opposite signs

then the two segments cross properly.

That solves the clean case. The whole difficulty of the topic is what to do when one or more of these values is zero.

## Core Invariant And Why It Works

### The General Case

Assume none of the four orientations is zero. Then:

- `c` and `d` lie on opposite sides of line `ab` iff `o1` and `o2` have opposite signs
- `a` and `b` lie on opposite sides of line `cd` iff `o3` and `o4` have opposite signs

So the proper-crossing test is:

$$
o1 \cdot o2 < 0
\quad\text{and}\quad
o3 \cdot o4 < 0.
$$

Geometrically:

- each segment must pierce the supporting line of the other

If either pair is on the same side, the segments cannot cross in the interior.

### Why Collinearity Breaks The Sign Test

If one orientation is zero, then one point lies exactly on the supporting line of the other segment.

At that point, "different sides" is no longer the right language. The question becomes:

- is the collinear point actually inside the finite segment?

That is why every robust segment-intersection predicate has two layers:

1. orientation for the non-collinear case
2. `on_segment` for degenerate collinear cases

### The `on_segment` Predicate

Suppose `a, b, p` are collinear. Then `p` lies on the closed segment `ab` iff:

$$
\min(a_x, b_x) \le p_x \le \max(a_x, b_x)
$$

and

$$
\min(a_y, b_y) \le p_y \le \max(a_y, b_y).
$$

This bounding-box check is enough only after collinearity is already known.

So the correct logic is:

- first check `orient(a,b,p) == 0`
- only then apply the coordinate box test

### The Complete Closed-Segment Predicate

For closed segments, the logic is:

1. if `c` lies on segment `ab`, return true
2. if `d` lies on segment `ab`, return true
3. if `a` lies on segment `cd`, return true
4. if `b` lies on segment `cd`, return true
5. otherwise return whether the strict opposite-side test holds

This is exactly the structure used in the repo starter.

### Why This Is Sufficient

There are only two possibilities:

- the segments are not collinear in the relevant local configuration
- or at least one endpoint is collinear with the other segment

If they are not collinear, the opposite-side test fully decides the answer.

If some endpoint is collinear, then intersection can happen only through:

- endpoint touching
- or collinear overlap

and those are exactly what the four `on_segment` checks cover.

So the combined predicate is complete.

## Strict Versus Non-Strict Intersection

This is the policy choice that most often causes bugs.

### Non-Strict / Closed-Segment Intersection

Return true for:

- proper crossing
- endpoint touching
- one segment endpoint lying on the other
- collinear overlap

This is the default page policy.

### Strict Intersection

If a problem wants only interior crossing, then these should usually count as false:

- touching at one endpoint
- collinear overlap

The easiest safe workflow is:

1. implement the closed-segment predicate first
2. then specialize carefully for the strict statement

Do not start by trying to write the strict version from scratch.

## Worked Examples

### Example 1: Proper Crossing

Take:

$$
a=(0,0), \; b=(4,4), \; c=(0,4), \; d=(4,0).
$$

Then:

- `c` is on one side of line `ab`
- `d` is on the other side
- `a` and `b` are also on opposite sides of line `cd`

So the segments intersect properly.

This is the clean case where the sign test alone is enough.

### Example 2: Endpoint Touching

Take:

$$
a=(0,0), \; b=(4,0), \; c=(4,0), \; d=(7,3).
$$

The segments touch at `(4,0)`.

One orientation involving `c` becomes zero, and:

- `c` is collinear with `ab`
- `c` lies inside the box of `ab`

So `on_segment(a,b,c)` returns true.

That is why endpoint touching is handled by the collinear branch, not by the strict sign test.

### Example 3: Collinear But Disjoint

Take:

$$
a=(0,0), \; b=(2,0), \; c=(5,0), \; d=(8,0).
$$

All four points are collinear, but the projections do not overlap.

So:

- orientation values are zero
- none of the `on_segment` checks succeeds

Hence the segments do not intersect.

This is the standard counterexample to the incorrect rule:

- "collinear implies intersecting"

### Example 4: Full Collinear Overlap

Take:

$$
a=(0,0), \; b=(5,0), \; c=(2,0), \; d=(4,0).
$$

Again all points are collinear, but now the second segment lies inside the first.

Then:

- `c` is on segment `ab`
- `d` is also on segment `ab`

So the predicate returns true.

This is why one-dimensional overlap after collinearity is the real degeneracy test.

### Example 5: Degenerate Segment (A Single Point)

Take:

$$
a=b=(2,2), \quad c=(0,0), \quad d=(4,4).
$$

The first segment is really just one point.

This still fits the same predicate:

- the point `(2,2)` is collinear with segment `cd`
- and it lies on that segment

So the closed-segment predicate correctly returns true.

This is worth remembering because some geometry libraries special-case zero-length segments, while the orientation-plus-`on_segment` formulation usually handles them naturally.

## Algorithm And Pseudocode

Repo starter template:

- [segment-intersection-basic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/segment-intersection-basic.cpp)

### Closed-Segment Predicate

```text
o1 = sign(orient(a, b, c))
o2 = sign(orient(a, b, d))
o3 = sign(orient(c, d, a))
o4 = sign(orient(c, d, b))

if o1 == 0 and on_segment(a, b, c): return true
if o2 == 0 and on_segment(a, b, d): return true
if o3 == 0 and on_segment(c, d, a): return true
if o4 == 0 and on_segment(c, d, b): return true

return (o1 * o2 < 0) and (o3 * o4 < 0)
```

### `on_segment`

```text
on_segment(a, b, p):
    if orient(a, b, p) != 0:
        return false
    return min(ax, bx) <= px <= max(ax, bx)
       and min(ay, by) <= py <= max(ay, by)
```

## Implementation Notes

### 1. Integer Arithmetic Is The Default

For contest tasks with integer coordinates, the best habit is:

- stay entirely in integer arithmetic
- avoid `EPS` unless the problem is genuinely floating-point geometry

This predicate is fundamentally combinatorial. Floating point only makes the boundary cases harder.

### 2. Use `__int128` For Safety

If coordinates can be around `10^9`, then a cross product can involve terms around:

$$
10^{18}.
$$

That is close enough to `long long` boundaries that using `__int128` for intermediate products is the safer contest default.

### 3. `on_segment` Must Be Inclusive

For closed segments, the comparisons must be inclusive:

- `<=`, not `<`

Otherwise endpoint touching breaks immediately.

### 4. Do Not Test Bounding Boxes Before Collinearity

The box check is not a standalone intersection test.

It is only valid after you already know the point is collinear with the segment.

Otherwise many non-collinear points inside the axis-aligned box would be false positives.

### 5. Decide The Touching Policy Early

Before coding, answer:

- does touching count?
- does collinear overlap count?

If you leave this vague, you will mix strict and non-strict branches halfway through the implementation.

### 6. Zero-Length Segments Need A Conscious Policy

Sometimes a "segment" may degenerate to a single point.

For closed-segment intersection, the standard predicate on this page already handles that case correctly through:

- collinearity
- `on_segment`

So you usually do not need a separate branch, but you should be aware that the input model may allow it.

### 7. This Predicate Is A Geometry Primitive

Segment intersection is rarely the final goal. More often it is reused inside:

- sweep line
- polygon validation
- planar graph checks
- point-in-polygon edge handling

So it is worth writing once and trusting afterward.

### 8. Line Intersection Point Is A Different Topic

This page is about deciding whether the segments intersect.

Computing the actual intersection point is a separate step, and it needs extra branching for:

- parallel lines
- collinear overlap
- exact-rational or floating-point output policy

Do not mix those two tasks unless the problem explicitly asks for the point.

## Beyond Basic Segment Intersection

The core contest layer is:

- orientation sign
- `on_segment`
- closed-segment predicate
- strict vs non-strict policy

Important next-layer directions include:

- segment-line and segment-ray intersection
- computing the actual intersection point
- sweep-line algorithms for many segments
- polygon self-intersection checks

The right study order is:

1. master pairwise closed-segment intersection
2. internalize why collinear cases are separate
3. only then build bigger geometry algorithms on top

## Practice Archetypes

The most common segment-intersection-shaped tasks are:

- **does this pair of segments intersect or touch?**
- **do polygon edges self-intersect?**
- **does a sweep-line candidate pair really intersect?**
- **is one segment endpoint on another segment?**

The strongest contest smell is:

- geometry with exact integer input
- boundary cases dominate correctness
- and one trusted pair predicate is clearly reusable in a larger solution

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Course:

- [Iowa State Computational Geometry Notes: Segment Intersect](https://faculty.sites.iastate.edu/jia/files/inline-files/2.%20segment%20intersect.pdf)

Reference:

- [CP-Algorithms: Check if two segments intersect](https://cp-algorithms.com/geometry/check-segments-intersection.html)
- [OI Wiki: 2D Geometry Basics](https://en.oi-wiki.org/geometry/2d/)

Practice:

- [CSES Geometry](https://cses.fi/problemset/list/)

Repo anchors:

- practice ladder: [Segment Intersection ladder](../../../practice/ladders/geometry/segment-intersection/README.md)
- practice note: [Line Segment Intersection](../../../practice/ladders/geometry/segment-intersection/linesegmentintersection.md)
- starter template: [segment-intersection-basic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/segment-intersection-basic.cpp)
- notebook refresher: [Geometry cheatsheet](../../../notebook/geometry-cheatsheet.md)

## Related Topics

- [Vector And Orientation](../vector-orientation/README.md)
- [Convex Hull](../convex-hull/README.md)
- [Polygon Area And Point Location](../polygon-area-point-location/README.md)
- [Sweep Line](../sweep-line/README.md)
