# Convex Hull

Convex hull is the first geometry algorithm that usually feels like a full contest technique rather than just a primitive.

Given a set of planar points, the convex hull throws away everything interior and keeps only the outer boundary. That one reduction is so powerful because many later problems become easier once only the extreme points remain:

- perimeter or area of the outer envelope
- farthest pair of points
- width / diameter style follow-ups
- point inclusion against the outer boundary

This page uses **Andrew's monotone chain** as the main route because it is the cleanest first hull algorithm in contests:

- no angle sorting
- no trigonometry
- one trusted orientation predicate
- a simple stack invariant on two monotone chains

## At A Glance

Reach for convex hull when:

- the statement asks for the outer boundary of a point set
- interior points seem irrelevant to the final quantity
- a later question talks about diameter, fence length, envelope, or extreme points
- the first simplification step feels like "keep only the boundary"

Strong contest triggers:

- "smallest convex polygon containing all points"
- "wrap a fence / rubber band around the points"
- "print all points on the hull"
- "farthest pair of points"
- "reduce to extreme points, then solve something on the boundary"

Strong anti-cues:

- the input is already a polygon and the task is about its own edges, not the hull of a point cloud
- the problem is really half-plane intersection, not point-set hull construction
- the hull is only a tiny subroutine and the true challenge is dynamic updates or higher dimensions

What success looks like after studying this page:

- you can explain why sorting plus orientation checks are enough
- you know what invariant the lower and upper chains maintain
- you can choose the correct collinear-point policy for the judge
- you know why Andrew monotone chain is usually the best first implementation
- you can see rotating calipers as the next step after hull construction

## Prerequisites

- [Vector And Orientation](../vector-orientation/README.md)
- [Sorting](../../foundations/patterns/sorting/README.md)

Helpful neighboring topics:

- [Polygon Area And Point Location](../polygon-area-point-location/README.md)
- [Point In Polygon template](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/point-in-polygon.cpp)

## Problem Model And Notation

We are given a finite set of planar points:

$$
P = \{p_1, p_2, \dots, p_n\}.
$$

Its convex hull is the smallest convex set containing all points in `P`.

In contest output, the hull is usually represented by its boundary vertices in cyclic order.

The core predicate is orientation:

$$
cross(b-a,\ c-a).
$$

Interpretation:

- positive: `a -> b -> c` is a counterclockwise turn
- negative: clockwise turn
- zero: collinear

Andrew's monotone chain begins by sorting all points lexicographically:

1. by `x`
2. then by `y`

Then it builds:

- a lower hull from left to right
- an upper hull from right to left

## From Brute Force To The Right Idea

### Brute Force

At a high level, a point lies on the hull if it is extreme in some direction.

That sounds simple, but a direct brute force approach is ugly:

- guess which points belong to the boundary
- try all possible supporting lines
- or test every edge candidate against all other points

These approaches are too slow or too awkward for contest use.

### The Structural Observation

After sorting points from left to right, the lower hull must appear in that same order.

So instead of solving "the whole hull" at once, we can solve:

- the lower boundary chain
- the upper boundary chain

separately.

That is the first major simplification.

### Why Local Turn Checks Are Enough

Suppose we are building the lower hull from left to right, and we currently have the last two chosen hull points `a` and `b`.

Now we want to add a new point `c`.

If the turn `a -> b -> c` is not compatible with the lower hull policy, then `b` cannot remain on that chain:

- either it creates a right turn
- or it is collinear and the judge wants only corners

So `b` can be popped immediately.

This is the key monotone-chain insight:

- global convexity reduces to repeated local orientation cleanup

### Why Sorting Is What Makes This Work

Without sorting, a local turn test would not be enough.

Sorting gives a left-to-right order in which:

- every candidate for the lower hull arrives in the only order it could appear on that chain
- every point popped from the stack has become provably redundant for that chain

So the algorithm is:

1. sort points
2. maintain a stack-like hull
3. pop while the last turn violates the chosen policy

That is the whole technique.

## Core Invariant And Why It Works

### Lower Hull Invariant

After processing the first `i` sorted points, the `lower` stack satisfies:

1. its points appear in increasing lexicographic order
2. every consecutive triple on the stack satisfies the chosen turn policy
3. the stack is exactly the lower convex chain of the processed prefix

When a new point `p` arrives:

- if the last turn is still valid, append `p`
- otherwise pop the middle point and try again

Why is popping correct?

If the triple `(a, b, p)` makes a forbidden turn for the lower chain, then point `b` lies inside or on the wrong side of the boundary formed by `a` and `p`. It cannot be a vertex of the lower hull of the processed prefix anymore.

So removing it is safe.

It also can never become useful again later in the same lower pass. Future points only move farther right in sorted order, so once `b` has become redundant between `a` and `p`, no later point can force `b` back onto that lower chain.

### Upper Hull Invariant

The same idea works from right to left for the upper hull.

Nothing fundamentally new happens there; it is the same chain-cleanup logic in the opposite direction.

So the full correctness argument is:

1. the lower pass constructs the correct lower chain
2. the upper pass constructs the correct upper chain
3. removing the duplicated endpoints and concatenating the chains gives the full hull boundary in cyclic order

### Why The Whole Algorithm Is Linear After Sorting

Each point is:

- pushed onto a chain at most once
- popped from that chain at most once

So the total chain-construction work is `O(n)`.

The full complexity is therefore dominated by the sort:

$$
O(n \log n).
$$

### The Collinear Policy Is Part Of The Algorithm

This is the most important implementation choice.

If your pop condition is:

```text
while cross(...) <= 0: pop
```

then you remove collinear middle points and keep only the extreme corners.

If your pop condition is:

```text
while cross(...) < 0: pop
```

then collinear boundary points are kept.

Neither is "more correct" in general. The judge decides which hull representation is wanted.

That means collinear handling is not a cosmetic choice. It is part of the problem specification.

In this repo, the two most useful anchors are:

- [convex-hull.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/convex-hull.cpp): a corner-only default
- [Convex Hull practice note](../../../practice/ladders/geometry/convex-hull/convexhull.md): boundary-all-points policy for the CSES task

## Complexity And Tradeoffs

For Andrew's monotone chain:

- sorting: `O(n log n)`
- lower + upper construction: `O(n)`
- total: `O(n log n)`
- memory: `O(n)`

Practical tradeoffs:

| Algorithm | Best when | Time | Main tradeoff |
| --- | --- | --- | --- |
| Andrew monotone chain | standard contest hull construction | `O(n log n)` | must decide collinear policy carefully |
| Graham scan | angle-sorting viewpoint is more natural for you | `O(n log n)` | angle sort and tie-breaking are easier to get wrong |
| Jarvis march / gift wrapping | hull size `h` is tiny and output-sensitive behavior matters | `O(nh)` | worst-case quadratic |
| hull as preprocessing for rotating calipers | later task is diameter / antipodal pairs | hull build `+` linear follow-up | only helps after hull is already correct |

Rule of thumb:

- for static 2D contest input, Andrew monotone chain is usually the best first implementation
- Graham scan is historically important, but Andrew is usually cleaner in code
- Jarvis march is conceptually simple, but rarely the first contest choice at large `n`

## Variant Chooser

| Variant | Use it when | Sort key | Main pitfall |
| --- | --- | --- | --- |
| Andrew monotone chain | default contest hull | lexicographic `(x, y)` | wrong pop condition for collinear policy |
| Graham scan | you want an angle-sorted radial view | polar angle around a pivot | tie-breaking among equal angles |
| keep-only-corners hull | judge wants polygon vertices only | same as chosen algorithm | accidentally removing necessary extreme endpoints |
| keep-all-boundary-points hull | judge wants every collinear boundary point | same as chosen algorithm | duplicates when all points are collinear |
| hull + rotating calipers | next task is diameter / farthest pair / width | hull first | forgetting that calipers expects cyclic hull order |

## Worked Examples

### Example 1: A Small Lower-Hull Trace

Take the sorted points:

$$
(0,0),\ (1,1),\ (2,0),\ (3,2).
$$

Build the lower hull with the policy "remove clockwise turns and also remove collinear middle points", so the pop condition is `cross <= 0`.

Start:

- lower = `[(0,0), (1,1)]`

Now add `(2,0)`.

Compute:

$$
cross((1,1)-(0,0),\ (2,0)-(1,1)) = cross((1,1), (1,-1)) = -2.
$$

This is a right turn, so `(1,1)` cannot stay on the lower hull. Pop it.

Now:

- lower = `[(0,0)]`

Append `(2,0)`:

- lower = `[(0,0), (2,0)]`

Then add `(3,2)`.

Compute:

$$
cross((2,0)-(0,0),\ (3,2)-(2,0)) = cross((2,0), (1,2)) = 4 > 0.
$$

This is a valid left turn for the lower hull, so keep it.

Final lower hull:

$$
(0,0),\ (2,0),\ (3,2).
$$

### Example 2: Why Collinear Policy Changes The Output

Take three collinear points:

$$
(0,0),\ (1,0),\ (2,0).
$$

If the judge wants only the corner hull, the middle point should disappear.

Then the pop condition should remove collinear middle points, typically using `<= 0` in a CCW-formulation.

If the judge wants **all** boundary points, as in [Convex Hull](../../../practice/ladders/geometry/convex-hull/convexhull.md), then the middle point must remain.

Then the pop condition must be strict enough to pop only real right turns.

This one detail is responsible for many accepted-vs-wrong-answer geometry submissions.

### Example 3: Upper Hull Uses The Same Invariant

Take the sorted points:

$$
(0,0),\ (1,2),\ (2,1),\ (3,0).
$$

For the upper hull, we scan from right to left:

$$
(3,0),\ (2,1),\ (1,2),\ (0,0).
$$

The logic is exactly the same as the lower pass:

- keep appending points
- if the last turn violates the upper-chain policy, pop the middle point
- continue until every consecutive triple satisfies the chosen orientation rule

So Andrew's algorithm is really one invariant used twice, not two different algorithms glued together.

### Example 4: Why Duplicates Must Be Removed Early

Suppose the input contains repeated copies of the same point.

If duplicates remain:

- the orientation logic may see fake zero-length steps
- the output may repeat boundary points
- all-collinear special cases become harder to reason about

So a standard safe workflow is:

1. sort
2. erase duplicates
3. build lower and upper hulls

### Example 5: The Bridge To Rotating Calipers

Suppose the problem asks for the farthest pair of points.

Brute force over all pairs is `O(n^2)`.

But after convex hull:

- all interior points are irrelevant
- the farthest pair must lie on the hull

Then rotating calipers can solve the follow-up on the hull in linear time.

This is why convex hull is often a preprocessing step rather than the final destination.

## Algorithm And Pseudocode

The repo starter implementation is:

- [convex-hull.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/convex-hull.cpp)

### Andrew Monotone Chain

```text
convex_hull(points):
    sort points lexicographically
    erase duplicates
    if size <= 1:
        return points

    lower = empty list
    for p in points from left to right:
        while lower has at least 2 points and last turn violates policy:
            pop lower.back()
        push p to lower

    upper = empty list
    for p in points from right to left:
        while upper has at least 2 points and last turn violates policy:
            pop upper.back()
        push p to upper

    remove duplicated endpoints from lower and upper
    concatenate lower and upper
    return hull in cyclic order
```

The only algorithmic choice hidden inside "violates policy" is the collinear rule:

- `<= 0` style pop for corner-only hull
- `< 0` style pop for keeping boundary-collinear points

Make this choice explicit in code comments. It is one of the highest-value comments in the implementation.

### All-Collinear Inputs

This edge case deserves explicit thought.

If all points are collinear:

- the corner-only hull is just the two extreme endpoints
- the boundary-all-points hull should include every distinct boundary point exactly once

Many bugs here come from concatenating lower and upper blindly and printing the same line segment twice.

### Repo Default Versus Problem-Specific Policy

The repo intentionally keeps two reference flavors side by side:

- [convex-hull.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/convex-hull.cpp) is the safer **corner-only** default for downstream geometry work
- [Convex Hull note](../../../practice/ladders/geometry/convex-hull/convexhull.md) shows the **keep all boundary points** policy required by the CSES task

That split is deliberate.

If the next step is:

- rotating calipers
- diameter / antipodal pairs
- polygon-style downstream geometry

then the corner-only hull is usually the cleaner default.

If the judge literally asks for every boundary point, switch the pop condition and handle the all-collinear case carefully.

## Implementation Notes

### 1. Trust Orientation More Than Geometry Intuition

In contest geometry, the hull algorithm should reduce to:

- sorting
- orientation signs
- stack pops

If your reasoning needs floating angles or visual guesswork, the implementation is probably becoming less reliable.

### 2. Use Exact Integer Arithmetic When Coordinates Are Integral

If coordinates can be as large as `10^9`, then a cross product may exceed `long long` during intermediate multiplication.

So for robust contest code:

- keep coordinates as `long long`
- compute cross products in `__int128`

This is exactly the policy used in the repo note [Convex Hull](../../../practice/ladders/geometry/convex-hull/convexhull.md).

### 3. Pick One Orientation Convention And Keep It Everywhere

For example:

- positive cross = counterclockwise
- negative cross = clockwise

Then keep the same meaning in:

- geometry primitives
- hull pop condition
- segment intersection
- point-in-polygon helpers

Mixing conventions is one of the fastest ways to produce geometry bugs that look random.

### 4. Output Convention Matters

Some downstream algorithms expect:

- cyclic order
- no repeated first point at the end

Others are happy with a repeated first point.

Choose one convention and document it. The repo templates and notes usually prefer:

- counterclockwise order
- no repeated starting point

If a downstream routine expects the first point repeated at the end, do that conversion at the boundary of that routine, not inside the base hull builder.

### 5. Graham Scan Versus Andrew

Graham scan and Andrew monotone chain are both `O(n log n)` hull algorithms.

Andrew is often easier because:

- it sorts by `(x, y)`, not by angle
- it builds lower and upper hulls symmetrically
- it handles the first implementation with fewer tie-breaking headaches

That is why this page teaches Andrew first.

### 6. Hull Policy Should Be Named In Code Comments

Do not leave the pop condition unexplained.

Write something like:

- `// pop on clockwise or collinear turn -> keep only corners`
- `// pop only on clockwise turn -> keep boundary-collinear points`

It prevents future-you from "fixing" the comparator into the wrong problem policy.

## After The Hull

Once the hull is available in cyclic order, many point-cloud problems become polygon problems.

That is the real payoff.

Common next steps:

- **rotating calipers** for diameter, width, or antipodal-pair style tasks
- **shoelace area** on the resulting hull polygon
- **point-in-polygon** or boundary reasoning on the outer envelope

So convex hull is best viewed as a gateway:

- from an unordered point cloud
- to an ordered boundary polygon

That bridge is why hull construction appears so often as the first stage of a larger geometry solution.

## Practice Archetypes

The most common hull-flavored tasks are:

- **print the hull**
- **keep only extreme points first, then continue**
- **diameter / farthest pair after hull**
- **boundary policy matters**: all boundary points vs corners only
- **geometry cleanup**: remove interior points before another algorithm

The strongest contest smell is:

- a large cloud of points
- the objective depends only on the boundary or extreme points

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Course:

- [USACO Guide: Convex Hull](https://usaco.guide/plat/convex-hull)
- [UIUC notes: Convex Hulls](https://jeffe.cs.illinois.edu/teaching/compgeom/2022/notes/14-convexhull.pdf)
- [TJHSST notes: Convex Hull Algorithms](https://activities.tjhsst.edu/sct/lectures/1415/SCT_Convex_Hull.pdf)

Reference:

- [CP-Algorithms: Convex Hull Construction](https://cp-algorithms.com/geometry/convex-hull.html)

Practice:

- [CSES Problem Set](https://cses.fi/problemset/)
- [Kattis: Convex Hull](https://open.kattis.com/problems/convexhull)

Repo anchors:

- practice ladder: [Convex Hull ladder](../../../practice/ladders/geometry/convex-hull/README.md)
- practice note: [Convex Hull](../../../practice/ladders/geometry/convex-hull/convexhull.md)
- starter template: [convex-hull.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/convex-hull.cpp)
- primitives: [geometry-primitives.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/geometry-primitives.cpp)
- notebook refresher: [Geometry cheatsheet](../../../notebook/geometry-cheatsheet.md)

## Related Topics

- [Vector And Orientation](../vector-orientation/README.md)
- [Segment Intersection](../segment-intersection/README.md)
- [Polygon Area And Point Location](../polygon-area-point-location/README.md)
