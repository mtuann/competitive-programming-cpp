# Nearest Pair of Points

This lane starts when point-set geometry stops being:

```text
keep the outer boundary or test one predicate
```

and becomes:

```text
find the globally closest pair in one static planar point set
```

The repo keeps the first exact route deliberately narrow.

It starts with:

- one static batch of 2D points
- Euclidean distance
- one contest-clean algorithm:
  - **x-sorted sweep with an active strip ordered by y**
- one reusable output contract:
  - return the minimum squared distance, or take one final square root if the judge wants the true distance

This page does **not** start with:

- dynamic nearest-neighbor queries
- kd-trees or general nearest-neighbor data structures
- higher-dimensional closest-pair variants
- Delaunay triangulations or randomized expected-time approaches

The first reusable move is:

```text
sort points by x,
remove every point too far in x to help,
then scan only the small y-window that can still beat the current best
```

That same family later branches into:

- implementation-clinic versions like [Minimum Euclidean Distance](../../../practice/ladders/advanced/algorithm-engineering/minimumeuclideandistance.md)
- divide-and-conquer proofs of the same packing bound
- richer proximity problems

but the first snippet to trust is still:

```text
static point set -> one closest-pair sweep
```

## At A Glance

- **Use when:** the statement asks for one global closest pair or one minimum Euclidean distance over a static point set
- **Core worldview:** after sorting by `x`, only a narrow active strip can still improve the answer
- **Main tools:** sorting, active set ordered by `y`, strip pruning by current best distance, squared-distance bookkeeping
- **Typical complexity:** `O(n log n)`
- **Main trap:** mixing squared and unsquared distance when pruning the strip

Strong contest signals:

- "closest pair"
- "minimum Euclidean distance among all points"
- the input is just one static set of points
- the brute force is `O(n^2)` pair checking
- sorting by one coordinate and keeping a small active strip feels plausible

Strong anti-cues:

- the task asks for the outer envelope of the points -> [Convex Hull](../convex-hull/README.md)
- the statement is about one feasible region defined by lines -> [Half-Plane Intersection](../half-plane-intersection/README.md)
- the geometry is mostly event ordering over segments or rectangles -> [Sweep Line](../sweep-line/README.md)
- the data changes online, or there are many nearest-neighbor queries after preprocessing

## Prerequisites

- [Vector And Orientation](../vector-orientation/README.md)
- [Sorting](../../foundations/patterns/sorting/README.md)

Helpful nearby anchors:

- [Sweep Line](../sweep-line/README.md)
- [Convex Hull](../convex-hull/README.md)
- [Geometry cheatsheet](../../../notebook/geometry-cheatsheet.md)

## Problem Model And Notation

We are given points:

$$
P = \{p_1, p_2, \dots, p_n\}
$$

in the plane, and we want:

$$
\min_{i \ne j} \|p_i - p_j\|
$$

or sometimes its squared form:

$$
\min_{i \ne j} \|p_i - p_j\|^2
$$

The first exact route in this repo stores the best value as a **squared** distance. That keeps comparisons exact and postpones square roots to the very end when a judge truly asks for the ordinary distance.

## From Brute Force To The Right Idea

### Brute Force

The direct approach is:

- check every pair of points
- keep the smallest distance

That is:

$$
O(n^2)
$$

and dies immediately for contest-sized `n`.

### The Structural Observation

After sorting by `x`, a point can only be helped by earlier points whose horizontal distance is already small enough.

If the current best squared distance is `best2`, then any earlier point with:

$$
(x_i - x_j)^2 > best2
$$

is already too far away horizontally to improve the answer.

So the correct active set is not:

- all earlier points

It is:

- only the earlier points still within the active `x`-strip allowed by `best2`

### Why The Y-Window Becomes Small

Among the points still in that strip, we also only care about candidates with:

$$
|y_i - y_j| \le \sqrt{best2}
$$

because any larger `y` gap already loses.

This turns the all-pairs search into:

- one monotone sweep in `x`
- one active structure ordered by `y`
- one small candidate scan for each point

That is the exact route to `O(n log n)`.

## Core Technique

Sort all points by `(x, y)`, then sweep from left to right.

Maintain:

- `best2`: the smallest squared distance found so far
- `left`: the first point still inside the active `x`-strip
- one active set ordered by `y`

For each current point `p`:

1. remove every old point whose horizontal distance from `p` is already larger than `sqrt(best2)`
2. among the remaining active points, only inspect those with `y` in:

$$
[p.y - \sqrt{best2},\ p.y + \sqrt{best2}]
$$

3. update `best2`
4. insert `p` into the active set

The packing argument guarantees that this local scan stays bounded overall, so the full algorithm remains `O(n log n)`.

## Exact Starter Route In This Repo

- Topic: this page
- Hot sheet: [Nearest Pair hot sheet](../../../notebook/nearest-pair-hot-sheet.md)
- Starter template: [`closest-pair-sweep.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/closest-pair-sweep.cpp)
- Flagship anchor: [Closest Pair](../../../practice/ladders/geometry/nearest-pair/closestpair.md)

The starter is intentionally honest:

- static points only
- Euclidean metric only
- one global answer only
- active strip ordered by `y`

If the real task is dynamic nearest neighbor, many queries, or higher dimensions, this is not the right first tool.

## Flagship Modeling

The cleanest first rep in this lane is:

- [Closest Pair](../../../practice/ladders/geometry/nearest-pair/closestpair.md)

Why it fits:

- the statement is exactly the canonical problem
- there is no extra modeling noise
- the only job is to trust the sweep invariant and output the distance correctly

For a harder engineering-flavored sibling, compare against:

- [Minimum Euclidean Distance](../../../practice/ladders/advanced/algorithm-engineering/minimumeuclideandistance.md)

That note is about implementation discipline on the same family, not the first geometry route itself.

## Complexity And Tradeoffs

For the sweep route:

- sorting: `O(n log n)`
- active-set insert / erase / range start: `O(log n)` each
- total: `O(n log n)`
- memory: `O(n)`

Practical tradeoffs:

| Route | Best when | Main tradeoff |
| --- | --- | --- |
| x-sorted sweep with y-ordered active set | one static nearest pair in 2D | careful squared-vs-unsquared strip logic |
| divide-and-conquer closest pair | you want the textbook recursive proof | harder to retrieve quickly under contest pressure |
| brute force | `n` is tiny | useless at contest scale |

## Main Pitfalls

- mixing `best2` with `sqrt(best2)` inconsistently
- storing the active set by `x` instead of `y`
- forgetting duplicate points imply answer `0`
- using floating point unnecessarily when the judge asks for squared distance on integer coordinates
- pretending this is a hull problem because the input is a point set

## Variant Chooser

| If the task feels like... | Open first | Why |
| --- | --- | --- |
| "one global minimum distance over a static point set" | this page | nearest pair is the exact family |
| "many segment / rectangle events" | [Sweep Line](../sweep-line/README.md) | event logic dominates more than proximity itself |
| "outer envelope / extreme points" | [Convex Hull](../convex-hull/README.md) | the answer is a boundary, not a closest pair |
| "same nearest-pair family, but code robustness is the real lesson" | [Minimum Euclidean Distance](../../../practice/ladders/advanced/algorithm-engineering/minimumeuclideandistance.md) | that note is the implementation-clinic compare point |

## Practice Roadmap

1. reopen [Geometry cheatsheet](../../../notebook/geometry-cheatsheet.md) if coordinate or metric conventions still drift
2. trust the exact sweep route on [Closest Pair](../../../practice/ladders/geometry/nearest-pair/closestpair.md)
3. only after that reopen the engineering case study on [Minimum Euclidean Distance](../../../practice/ladders/advanced/algorithm-engineering/minimumeuclideandistance.md)

## Solved Example In This Repo

- [Closest Pair](../../../practice/ladders/geometry/nearest-pair/closestpair.md): the canonical closest-pair sweep over a static 2D point set

## Reusable Pattern

Carry forward:

- x-sorting plus one active `y`-structure is enough
- the active strip should contain exactly the points still capable of improving the answer
- squared distances are often the safest internal contract

This lane adds:

- one trusted nearest-pair starter
- one explicit bridge from brute-force pair checking to sweep-line pruning

## Go Deeper

- Reference: [cp-algorithms closest pair](https://cp-algorithms.com/geometry/nearest_points.html)
- Practice: [AOJ CGL_5_A - Closest Pair](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A)
- Compare point: [Minimum Euclidean Distance](../../../practice/ladders/advanced/algorithm-engineering/minimumeuclideandistance.md)
