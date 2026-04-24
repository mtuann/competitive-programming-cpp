# KINGDOMS

- Title: `VM 10 Bài 14 - KINGDOMS`
- Judge / source: `VN SPOJ / VNOI`
- Original URL: [https://vn.spoj.com/ranks/KINGDOMS/](https://vn.spoj.com/ranks/KINGDOMS/)
- Mirror URL: [https://oj.vnoi.info/problem/kingdoms](https://oj.vnoi.info/problem/kingdoms)
- Secondary topics: `Nested convex polygons`, `Laminar intervals`, `Point location`
- Difficulty: `hard`
- Subtype: `Find the deepest convex polygon containing each query point`
- Status: `solved`
- Solution file: [kingdoms.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/sweep-line/kingdoms.cpp)

## Why Practice This

This is a good geometry problem because the polygons are convex, disjoint-or-nested, and numerous enough that repeated point-in-polygon checks are too slow. The important structural observation is that a vertical sweep line sees a laminar family of intervals.

## Key Idea

For a fixed `x`, every active convex polygon intersects the vertical line in one interval:

`[lower(x), upper(x)]`

Because polygons are either disjoint or nested, these intervals form a laminar family.

So during a left-to-right sweep:

- maintain all active kingdoms ordered by `lower(x)`
- for a query `(x, y)`, take the active kingdom whose lower boundary is the largest one still below `y`
- if its upper boundary is also above `y`, that is the deepest containing kingdom
- otherwise, climb parent kingdoms until the upper boundary contains `y`

The containment tree itself can also be built during the sweep:

- when a polygon starts at its leftmost `x`
- its parent is exactly the active polygon immediately below its lower boundary

## Complexity

- preprocessing convex chains: `O(total_vertices log total_vertices_per_polygon)`
- sweep: `O((N + Q) log N)`
- ancestor climbing per query: `O(log N)`

This fits the small time limit only because we avoid checking polygons one by one.

## Pitfalls / Judge Notes

- Queries are guaranteed not to lie on polygon borders.
- Start/end `x` values are boundary-only positions, so event order matters:
  - remove ending polygons first
  - answer queries
  - insert starting polygons
- The answer is the **deepest** kingdom containing the house, not just any containing kingdom.
- Using `long long` is necessary for coordinates; use careful comparisons for line-vs-point checks.

## Reusable Pattern

- Topic page: [Sweep Line](../../../../topics/geometry/sweep-line/README.md)
- Practice ladder: [Sweep Line ladder](README.md)
- Starter template: [Template library overview](../../../../template-library.md)
- Notebook refresher: [Geometry cheatsheet](../../../../notebook/geometry-cheatsheet.md)
- Carry forward: sort events first, then make the active-set invariant explicit.
- This note adds: the event meaning and state maintenance for this geometric sweep.

## Solutions

- Code: [kingdoms.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/sweep-line/kingdoms.cpp)
