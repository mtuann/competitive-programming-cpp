# Vector And Orientation

This is the foundation layer of contest geometry.

If these primitives feel stable, then many later topics stop feeling like "geometry problems" and start feeling like ordinary algorithm problems with a trusted predicate layer underneath:

- segment intersection
- convex hull
- polygon area
- sweep line
- point-in-polygon

The most important shift is this:

- geometry becomes much easier once you stop thinking in terms of pictures alone
- and start thinking in terms of a few exact algebraic predicates

For most contest problems with integer coordinates, those predicates are:

- vector subtraction
- dot product
- cross product
- orientation sign

## At A Glance

- **Use when:** the statement talks about left/right turn, clockwise/counterclockwise, area, angle order, or side-of-line tests
- **Core invariant:** `cross(b - a, c - a)` decides the orientation of the triple `(a, b, c)`
- **Typical complexity:** `O(1)` for the primitive predicates themselves
- **Main trap:** inconsistent sign conventions or careless overflow in the cross product
- **Default policy:** prefer exact integer arithmetic when the input coordinates are integers

## Problem Model And Notation

We work in the plane with points

$$
p = (x, y).
$$

In contest geometry, the same data type often plays two roles:

- **point**: a location
- **vector**: a displacement

That is why code usually defines one struct `Point`, then reuses it for vector operations too.

Given two points `a` and `b`, the vector from `a` to `b` is:

$$
b - a = (b_x - a_x, b_y - a_y).
$$

The two core bilinear operations are:

### Dot Product

$$
u \cdot v = u_x v_x + u_y v_y
$$

It answers questions about:

- projection
- angle acuteness/obtuseness
- squared lengths when `u = v`

### 2D Cross Product / Determinant

In 2D, we use the scalar quantity

$$
u \times v = u_x v_y - u_y v_x.
$$

This is the signed area of the parallelogram formed by `u` and `v`.

Its sign is what makes orientation possible.

It is worth saying this explicitly:

- in 3D, the cross product is a vector
- in 2D contest geometry, "`cross`" usually means this scalar determinant

That scalar is the right object for sidedness and area predicates.

### Orientation Predicate

For three points `a, b, c`, define

$$
\mathrm{orient}(a,b,c) = (b-a) \times (c-a).
$$

Then:

- `orient(a,b,c) > 0` means `a -> b -> c` is counterclockwise
- `orient(a,b,c) < 0` means clockwise
- `orient(a,b,c) = 0` means collinear

This single predicate is the workhorse for most first-layer geometry.

## From Brute Force To The Right Idea

### The Wrong Mental Model: Casework By Picture

Many beginners first attack geometry by visual intuition alone:

- "this point looks left of the line"
- "these segments seem to cross"
- "this polygon seems clockwise"

That quickly breaks down because contest geometry is full of:

- degenerate cases
- collinearity
- large coordinates
- exact boundary decisions

So the right mindset is:

- reduce the picture to one small exact predicate

### Why Cross Product Is The Right Predicate

Take two vectors `u` and `v`.

The sign of

$$
u \times v
$$

tells whether `v` lies to the left or to the right of `u`.

Geometrically:

- positive means a left turn
- negative means a right turn
- zero means no turn at all, i.e. collinear

That means many "geometric" questions are really just sign questions on determinants.

### Why Integer Geometry Is So Friendly

If all coordinates are integers, then:

- vector subtraction stays integral
- dot and cross products stay integral
- orientation is exact

So a surprising number of geometry tasks can be solved without:

- trigonometry
- floating point
- `EPS`

That is a major reason contest geometry is tractable.

## Core Invariant And Why It Works

### Cross Product As Signed Area

For vectors

$$
u = (u_x, u_y), \qquad v = (v_x, v_y),
$$

the determinant

$$
u_x v_y - u_y v_x
$$

is the signed area of the parallelogram spanned by `u` and `v`.

So:

- positive area means one orientation
- negative area means the opposite orientation
- zero area means the two vectors are linearly dependent

This is the real reason orientation works.

### Why `orient(a,b,c)` Decides Left Versus Right

The vectors

$$
b-a \quad \text{and} \quad c-a
$$

share the same tail at `a`.

So their signed area tells whether the ray `a -> c` is:

- to the left of ray `a -> b`
- to the right
- or collinear

That is why:

$$
\mathrm{orient}(a,b,c) = \mathrm{cross}(b-a, c-a)
$$

is the standard orientation predicate.

### Why Dot Product Answers Different Questions

The dot product does **not** encode sidedness. Instead it encodes angular alignment:

$$
u \cdot v = |u||v|\cos\theta.
$$

So it is the right primitive for:

- checking whether an angle is acute / right / obtuse
- projection lengths
- distance formulas with squared norms

This gives the clean division of labor:

- cross -> side / turn / area
- dot -> angle / projection / length interaction

### The 2D Contest Geometry Meta-Rule

Most first-layer geometry problems can be reduced to one of these:

- sign of a cross product
- value of a dot product
- sum of signed cross products

That is why a tiny primitive library carries so much of the subject.

## Worked Examples

### Example 1: Orientation Test

Take:

$$
a=(0,0), \quad b=(3,0), \quad c=(2,1).
$$

Then:

$$
b-a = (3,0), \qquad c-a = (2,1).
$$

So:

$$
\mathrm{orient}(a,b,c)
=
3 \cdot 1 - 0 \cdot 2
= 3 > 0.
$$

So the turn `a -> b -> c` is counterclockwise.

If instead

$$
c=(2,-1),
$$

then:

$$
\mathrm{orient}(a,b,c) = -3 < 0,
$$

so the turn is clockwise.

### Example 2: Triangle Area

For triangle `(a, b, c)`, the doubled signed area is:

$$
\mathrm{orient}(a,b,c).
$$

So the ordinary area is:

$$
\frac{|\mathrm{orient}(a,b,c)|}{2}.
$$

This is why polygon area and convex hull both rest on the same primitive.

### Example 3: Collinearity

Take:

$$
a=(1,1), \quad b=(3,3), \quad c=(7,7).
$$

Then:

$$
b-a = (2,2), \qquad c-a = (6,6),
$$

so:

$$
\mathrm{orient}(a,b,c)
=
2 \cdot 6 - 2 \cdot 6
= 0.
$$

The three points are collinear.

This is the exact predicate behind:

- on-segment tests
- collinear overlap checks
- many geometry degeneracies

### Example 4: Dot Product And Angle Type

Let

$$
u=(2,1), \qquad v=(1,-2).
$$

Then:

$$
u \cdot v = 2 \cdot 1 + 1 \cdot (-2) = 0.
$$

So the two vectors are perpendicular.

This is the standard contest way to detect:

- right angles
- orthogonality constraints

without any trigonometry.

### Example 5: Angle Sorting Without `atan2`

Suppose you want to sort vectors by polar angle.

The naive approach is:

- compute `atan2(y, x)`
- sort by that floating-point angle

The contest-safe exact approach is:

1. split vectors into two half-planes
2. sort within the same half-plane by cross-product sign

The usual half-plane predicate is something like:

```text
upper(v) = (v.y > 0) or (v.y == 0 and v.x >= 0)
```

Then for two vectors in the same half-plane:

- `u` comes before `v` if `u × v > 0`

If `u × v = 0`, then they are collinear as rays, and the remaining tie-break depends on the task:

- by squared length if you want near-to-far order on the same ray
- by stable index / original position if only a deterministic total order is needed

This is one of the nicest examples of replacing floating-point geometry with exact predicates.

## Variant Chooser

### Use Cross Product / Orientation When

- you need left/right-of-line reasoning
- the problem is about clockwise / counterclockwise order
- you need triangle or polygon area
- you are preparing a segment / hull / polygon predicate

### Use Dot Product When

- you need angle-type reasoning
- projection matters
- perpendicularity matters
- the geometry is really about lengths and angles, not sidedness

### Use Both Together When

- the problem mixes orientation with length/projection
- for example, point-to-segment distance or angle classification inside a polygonal task

### Prefer Exact Integer Geometry When

- coordinates are integers
- the answer is combinatorial (`YES/NO`, inside/outside, clockwise/counterclockwise)
- no actual floating-point coordinates are requested

### Use Floating Point Only When The Problem Truly Demands It

Typical cases:

- actual intersection coordinates
- distances with square roots
- optimization over angles or continuous geometry

Even then, keep integer predicates where possible and isolate the floating-point layer.

## Algorithm And Pseudocode

Repo starter template:

- [geometry-primitives.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/geometry-primitives.cpp)

### Orientation

```text
orient(a, b, c):
    return cross(b - a, c - a)
```

### Sign Wrapper

```text
sgn(x):
    if x > 0: return 1
    if x < 0: return -1
    return 0
```

### Triangle Area

```text
twice_area(a, b, c):
    return abs(orient(a, b, c))
```

### Angle Sort Comparator Skeleton

```text
upper(v):
    return (v.y > 0) or (v.y == 0 and v.x >= 0)

compare(u, v):
    if upper(u) != upper(v):
        return upper(u) > upper(v)
    return cross(u, v) > 0
```

## Implementation Notes

### 1. `__int128` Is Often The Right Default

If coordinates can be around `10^9`, then a cross product may involve terms near:

$$
10^{18}.
$$

That is close enough to `long long` limits that `__int128` is the safer contest default for intermediate products.

### 2. Fix One Orientation Convention And Never Drift

This repo uses:

- positive -> counterclockwise / left turn
- negative -> clockwise / right turn

If one helper flips that convention, everything built on top becomes fragile.

### 3. Zero Cross Means Collinear, Not Automatically "Inside"

This is one of the most common mistakes.

From:

$$
\mathrm{orient}(a,b,c) = 0
$$

you may conclude only:

- the three points are collinear

You still need more checks for:

- on-segment
- overlap
- containment

### 4. Screen Coordinates Are Not Math Coordinates

In some UI / graphics contexts, the `y` axis increases downward.

That reverses many visual intuitions.

In contest geometry, coordinates normally use the standard mathematical orientation, but if a custom statement flips the axis, your sign intuition must flip too.

### 5. Keep The Primitive Layer Tiny

The ideal geometry primitive layer is:

- `Point`
- `+` / `-`
- dot
- cross
- sign
- maybe norm squared

Small and trusted beats clever and sprawling.

### 6. Orientation Is A Predicate, Not Just A Formula

Do not memorize:

$$
x_1 y_2 - y_1 x_2
$$

as a raw expression only.

Interpret it as:

- a decision procedure about sidedness
- a signed-area primitive
- the foundation of later geometry algorithms

That interpretation is what makes the topic reusable.

### 7. Angle Sorting Needs A Half-Plane Split

Using only `cross(u, v) > 0` is not enough for a total order on all vectors.

You need to separate upper and lower half-planes first. Otherwise opposite directions cannot be ordered consistently.

Also remember that equal-angle vectors still need a tie-break if the sort key must be total.

## Beyond Basic Vector Geometry

The core contest layer is:

- exact 2D vectors
- dot product
- cross product
- orientation
- triangle / polygon area basics

Important next-layer directions include:

- line and segment intersection
- convex hull
- sweep-line ordering
- point-in-polygon
- distance and projection formulas

The right study order is:

1. stabilize orientation and cross-product intuition
2. learn segment intersection
3. then build hull / polygon / sweep-line algorithms on top

## Practice Archetypes

The most common vector-orientation-shaped tasks are:

- **clockwise / counterclockwise test**
- **left/right of line**
- **triangle or polygon area**
- **angle sorting**
- **small exact geometry predicates inside a larger algorithm**

The strongest contest smell is:

- geometry with integer coordinates
- and the solution depends on one exact sign predicate more than on numeric approximation

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Course:

- [Iowa State: Geometric Basics](https://faculty.sites.iastate.edu/jia/files/inline-files/1.%20geometric%20basics.pdf)
- [UCF Programming Team: Basics of Computational Geometry](https://www.cs.ucf.edu/~dmarino/progcontests/cop4516/notes/Geometry-Nadeem.pdf)
- [Purdue Computational Geometry Predicates](https://www.cs.purdue.edu/homes/cs53100/slides/predicates.pdf)

Reference:

- [CP-Algorithms: Basic Geometry](https://cp-algorithms.com/geometry/basic-geometry.html)
- [OI Wiki: 2D Geometry Basics](https://en.oi-wiki.org/geometry/2d/)
- [KACTL Geometry Section](https://github.com/kth-competitive-programming/kactl)

Practice:

- [CSES Geometry](https://cses.fi/problemset/list/)

Repo anchors:

- practice ladder: [Vector and orientation ladder](../../../practice/ladders/geometry/vector-orientation/README.md)
- practice note: [Point Location Test](../../../practice/ladders/geometry/vector-orientation/pointlocationtest.md)
- starter template: [geometry-primitives.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/geometry-primitives.cpp)
- notebook refresher: [Geometry cheatsheet](../../../notebook/geometry-cheatsheet.md)

## Related Topics

- [Segment Intersection](../segment-intersection/README.md)
- [Convex Hull](../convex-hull/README.md)
- [Polygon Area And Point Location](../polygon-area-point-location/README.md)
- [Sweep Line](../sweep-line/README.md)
