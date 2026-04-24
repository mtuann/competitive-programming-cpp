# Line Segment Intersection

- Title: `Line Segment Intersection`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/2190](https://cses.fi/problemset/task/2190)
- Main topic: `Geometry -> Segment Intersection`
- Secondary topics: `Orientation test`, `On-segment check`, `Collinear overlap`
- Difficulty: `easy`
- Subtype: `Decide whether two closed line segments intersect or touch`
- Status: `solved`
- Solution file: [linesegmentintersection.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/segment-intersection/linesegmentintersection.cpp)

## Why Practice This

This is the standard first segment-intersection problem:

- the geometry primitive is tiny
- the edge cases are the whole problem
- you want one predicate you can later trust inside bigger geometry code

If this note feels annoyingly case-heavy, that is normal. Segment intersection is exactly where "just use cross products" turns into "define the touching policy and handle degeneracies carefully".

## Key Idea

For segments `ab` and `cd`, compute the orientation signs:

```text
o1 = orient(a, b, c)
o2 = orient(a, b, d)
o3 = orient(c, d, a)
o4 = orient(c, d, b)
```

There are two cases.

### 1. Proper crossing

If `c` and `d` lie on opposite sides of line `ab`, then `o1` and `o2` have opposite signs.

Likewise, if `a` and `b` lie on opposite sides of line `cd`, then `o3` and `o4` have opposite signs.

So the strict crossing test is:

```text
o1 * o2 < 0 and o3 * o4 < 0
```

### 2. Touching / collinear cases

CSES counts touching as intersection, so we also need the inclusive cases:

- one endpoint lies exactly on the other segment
- both segments are collinear and overlap

That is what `on_segment` is for.

For example, if `orient(a, b, c) == 0`, then `c` is collinear with segment `ab`. It intersects `ab` exactly when its coordinates lie inside the bounding box of `a` and `b`.

So the full predicate is:

1. handle the four collinear endpoint cases with `on_segment`
2. otherwise use the strict opposite-side test

Everything stays in integer arithmetic. No floating point, no epsilon.

## Complexity

- one test case: `O(1)`
- total for `t` test cases: `O(t)`

This is optimal. The only real difficulty is correctness on edge cases.

## Pitfalls / Judge Notes

- CSES wants **non-strict** intersection, so endpoint touching must print `YES`.
- Collinear does **not** automatically mean intersecting. The 1D projections still need to overlap.
- Use integer arithmetic throughout. Floating point is unnecessary here and only makes boundary cases less reliable.
- With coordinates up to about `1e9`, a cross product is still fine in integer arithmetic, but using `__int128` for the intermediate multiplication makes the orientation primitive comfortably robust.

## Reusable Pattern

- Topic page: [Segment Intersection](../../../../topics/geometry/segment-intersection/README.md)
- Practice ladder: [Segment Intersection ladder](README.md)
- Starter template: [geometry-primitives.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/geometry-primitives.cpp)
- Notebook refresher: [Geometry cheatsheet](../../../../notebook/geometry-cheatsheet.md)
- Carry forward: get orientation and collinearity logic correct before handling overlap cases.
- This note adds: the exact on-segment and overlap handling used by this judge task.

## Solutions

- Code: [linesegmentintersection.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/segment-intersection/linesegmentintersection.cpp)
