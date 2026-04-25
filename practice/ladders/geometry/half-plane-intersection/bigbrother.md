# Big Brother

- Title: `Big Brother`
- Judge / source: `Kattis`
- Original URL: [https://open.kattis.com/problems/bigbrother](https://open.kattis.com/problems/bigbrother)
- Secondary topics: `Polygon kernel`, `Half-plane intersection`, `Polygon orientation`
- Difficulty: `medium`
- Subtype: `Intersect inward edge half-planes of a simple polygon and output the kernel area`
- Status: `solved`
- Solution file: [bigbrother.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/half-plane-intersection/bigbrother.cpp)

## Why Practice This

This is the cleanest first polygon-kernel benchmark in the repo:

- the statement is geometric, but the reusable core is one exact HPI lane
- every polygon edge becomes one inward half-plane
- the final answer is just the area of the resulting convex intersection

So this problem is not about inventing a visibility algorithm from scratch.

It is about recognizing:

```text
camera can see the whole polygon
=> point lies in the kernel
=> point satisfies every inward edge half-plane
```

## Recognition Cue

Reach for half-plane intersection when:

- the answer is the whole region where all geometric constraints hold
- the input is a simple polygon and the task asks for all valid observation points
- each boundary edge naturally contributes one local "must stay on this side" rule
- the output is an area, not one yes/no visibility query

The strongest smell is:

- "find where a camera can be placed so the whole polygon is visible"

For a simple polygon, that is the kernel.

## Problem-Specific Transformation

Rewrite the statement as:

- take every polygon edge
- orient it so the interior lies on the **left**
- build one half-plane from that directed edge
- intersect all those half-planes
- compute the area of the resulting polygon

That means the hard part is not visibility-ray simulation.

It is:

- choosing the inward orientation correctly
- then running one bounded half-plane intersection

## Core Idea

Let the polygon vertices be `p[0], p[1], ..., p[n-1]`.

For each edge `(p[i], p[i+1])`:

- if the polygon is counterclockwise, the interior is already on the left of the edge
- if the polygon is clockwise, reverse the edge before turning it into a half-plane

Now every legal camera position must satisfy all of these inward half-planes.

So the camera region is exactly:

$$
\bigcap_i H_i
$$

where each `H_i` is the inward half-plane of one edge.

Run the standard route:

1. sort half-planes by angle
2. keep only the most restrictive one among equal directions
3. maintain the surviving intersection with a deque
4. close the polygon and compute its shoelace area

If the intersection is empty, the answer is `0`.

## Complexity

- build half-planes: `O(n)`
- sort by angle: `O(n log n)`
- deque intersection: `O(n)`
- area: `O(k)` where `k` is the kernel polygon size

Total:

$$
O(n \log n)
$$

which is exactly the intended contest route for `n` up to `5 * 10^5`.

## Pitfalls / Judge Notes

- Kattis gives the polygon in clockwise order, so blindly keeping the left side of `(a -> b)` is wrong; you must reverse each edge or detect orientation first.
- This is a **polygon kernel** problem, not a convex-hull problem. The polygon already exists; you are intersecting inward constraints, not wrapping points.
- Keep the side test non-strict so points on the boundary remain legal.
- The answer is an area of a continuous region, so use floating / continuous geometry and print with enough precision.
- If the surviving polygon has fewer than `3` vertices, its area is `0`.

## Reusable Pattern

- Topic page: [Half-Plane Intersection](../../../../topics/geometry/half-plane-intersection/README.md)
- Practice ladder: [Half-Plane Intersection ladder](README.md)
- Starter template: [`half-plane-intersection.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/half-plane-intersection.cpp)
- Notebook refresher: [Half-Plane Intersection hot sheet](../../../../notebook/half-plane-intersection-hot-sheet.md)
- Carry forward: polygon-kernel tasks often reduce directly to inward edge half-planes.
- This note adds: how polygon orientation determines whether each edge must be used as `(a -> b)` or `(b -> a)`.

## Solutions

- Code: [bigbrother.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/half-plane-intersection/bigbrother.cpp)
