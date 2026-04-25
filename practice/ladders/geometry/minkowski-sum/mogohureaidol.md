# Mogohu-Rea Idol

- Title: `Mogohu-Rea Idol`
- Judge / source: `Codeforces`
- Original URL: [https://codeforces.com/problemset/problem/87/E](https://codeforces.com/problemset/problem/87/E)
- Secondary topics: `Point in convex polygon`, `Convex polygons`
- Difficulty: `very-hard`
- Subtype: `Repeated Minkowski sum of convex polygons plus scaled point queries`
- Status: `solved`
- Solution file: [mogohureaidol.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/minkowski-sum/mogohureaidol.cpp)

## Why Practice This

This is the current in-repo **stretch anchor** for `Minkowski Sum`, not the first benchmark.

The first benchmark is still:

- two convex polygons
- one linear edge-direction merge

This note matters because the core model is exactly:

- choose one point from each of three convex polygons
- ask whether their sum can hit a target

That is the definition of a repeated Minkowski sum.

The point-query side is important, but the modeling unlock is the real lesson.

## Recognition Cue

Reach for Minkowski sum when:

- you are adding feasible points from several convex regions
- or an averaged / center-of-mass condition becomes an equation on sums of points

The strongest smell in this task is:

```text
pick one point from each city so that their center of mass equals the hill
```

## Problem-Specific Transformation

Let the three altar points be `a`, `b`, and `c`, with equal masses.

The center of mass condition is:

$$
\frac{a + b + c}{3} = h
$$

for the hill point `h`.

So equivalently:

$$
a + b + c = 3h
$$

The set of all achievable left-hand sides is exactly:

$$
P_1 + P_2 + P_3
$$

where each `P_i` is one convex city polygon.

Therefore each hill query becomes:

- scale the hill point by `3`
- test whether that scaled point lies in the convex polygon `P_1 + P_2 + P_3`

## Core Idea

### 1. Sum The Polygons, Not The Queries

Do **not** try to answer every hill independently by searching over altar placements.

The right object is the one shared feasible region:

$$
S = P_1 + P_2 + P_3
$$

Then all queries reuse that same polygon.

### 2. Repeated Sum Is Still Convex

Since every city is a convex polygon, the repeated sum is also convex.

That means:

- each pairwise Minkowski sum is linear in total boundary size
- the final query structure is still one convex polygon

### 3. Query With Point-In-Convex

Once `S` is built, every hill becomes one query:

$$
3h \in S\ ?
$$

So the follow-up should be:

- `point_in_convex` in `O(log |S|)` per hill

not a generic `O(|S|)` polygon scan repeated `10^5` times.

## Implementation Plan

1. read the three city polygons, already given in CCW order
2. compute:
   - `S12 = P1 + P2`
   - `S = S12 + P3`
3. preprocess `S` for inclusive point-in-convex queries
4. for each hill `h`, test whether `(3 * h.x, 3 * h.y)` lies in `S`
5. print `YES` / `NO`

## Complexity

If the three input sizes are `n1`, `n2`, `n3`, and `m` is the number of hills:

- repeated Minkowski sum: `O(n1 + n2 + n3)`
- each query: `O(log |S|)`
- total: `O(n1 + n2 + n3 + m log |S|)`

That is exactly the scale the problem wants.

## Main Traps

- forgetting to multiply the hill by `3`
- using ordinary point-in-polygon instead of point-in-convex for the query phase
- losing CCW / start-vertex conventions between repeated sums
- thinking only vertex sums matter online, instead of building the full convex sum once

## Reopen Path

- Topic page: [Minkowski Sum](../../../../topics/geometry/minkowski-sum/README.md)
- Practice ladder: [Minkowski Sum ladder](README.md)
- Starter template: [minkowski-sum-convex.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/minkowski-sum-convex.cpp)
- Notebook refresher: [Minkowski Sum hot sheet](../../../../notebook/minkowski-sum-hot-sheet.md)
- Compare points:
  - [Convex Hull](../../../../topics/geometry/convex-hull/README.md)
  - [Polygon Area And Point Location](../../../../topics/geometry/polygon-area-point-location/README.md)
  - [Half-Plane Intersection](../../../../topics/geometry/half-plane-intersection/README.md)

## Solutions

- Code: [mogohureaidol.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/minkowski-sum/mogohureaidol.cpp)
