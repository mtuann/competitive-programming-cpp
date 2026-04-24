# Point Location Test

- Title: `Point Location Test`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/2189](https://cses.fi/problemset/task/2189)
- Main topic: `Geometry -> Vector Orientation`
- Secondary topics: `Cross product sign`, `Directed line side test`, `Integer geometry`
- Difficulty: `easy`
- Subtype: `Classify a point as LEFT / RIGHT / TOUCH relative to a directed segment`
- Status: `solved`
- Solution file: [pointlocationtest.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/vector-orientation/pointlocationtest.cpp)

## Why Practice This

This is the smallest useful geometry predicate in the whole track:

- one cross product decides the answer
- the sign convention matters more than the arithmetic
- the same primitive reappears in segment intersection, convex hull, and polygon work

If this test feels automatic, a lot of later geometry gets much less scary.

## Key Idea

For points `a`, `b`, and `p`, look at the directed segment `a -> b`.

Compute:

```text
cross((b - a), (p - a))
```

Equivalently:

```text
(b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x)
```

Interpret the sign:

- positive: `p` is to the `LEFT`
- negative: `p` is to the `RIGHT`
- zero: `p` is collinear, so print `TOUCH`

This is exactly the orientation test for the ordered triple `(a, b, p)`.

## Complexity

- one query: `O(1)`
- total for `t` queries: `O(t)`

The whole problem is just a reliable primitive.

## Pitfalls / Judge Notes

- The direction matters: `a -> b` and `b -> a` flip `LEFT` and `RIGHT`.
- `TOUCH` here means collinear with the infinite line through `a` and `b`; the point does not need to lie between them.
- With coordinates around `1e9`, use `__int128` for the cross-product intermediate to stay comfortably safe.
- No floating point or epsilon is needed.

## Reusable Pattern

- Topic page: [Vector And Orientation](../../../../topics/geometry/vector-orientation/README.md)
- Practice ladder: [Vector And Orientation ladder](README.md)
- Starter template: [geometry-primitives.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/geometry-primitives.cpp)
- Notebook refresher: [Geometry cheatsheet](../../../../notebook/geometry-cheatsheet.md)
- Carry forward: the sign of one cross product is the first geometry fact to trust automatically.
- This note adds: the exact classification or predicate layered on top of the orientation primitive.

## Solutions

- Code: [pointlocationtest.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/vector-orientation/pointlocationtest.cpp)
