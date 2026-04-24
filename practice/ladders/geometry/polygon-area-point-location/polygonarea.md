# Polygon Area

- Title: `Polygon Area`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/2191](https://cses.fi/problemset/task/2191)
- Secondary topics: `Shoelace formula`, `Signed area`, `Cross product sum`
- Difficulty: `easy`
- Subtype: `Compute twice the area of a simple polygon from ordered vertices`
- Status: `solved`
- Solution file: [polygonarea.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/polygon-area-point-location/polygonarea.cpp)

## Why Practice This

This is the cleanest first polygon-area problem:

- the polygon is already given in cyclic order
- the intended method is exactly the shoelace formula
- the only real implementation trap is handling the closing edge and large intermediate values correctly

It is the right first anchor for this topic because it turns cross products into a full closed-shape invariant.

## Recognition Cue

Reach for shoelace when:

- polygon vertices are already given in cyclic order
- you need area or doubled area
- the polygon is static and simple
- the intended solution should stay entirely in integer arithmetic

The strongest smell is:

- "compute area from boundary vertices"

That usually means summing oriented edge contributions, not triangulating explicitly.

## Problem-Specific Transformation

The statement is about one polygon, but the reusable rewrite is:

- treat every directed edge `(p[i], p[i+1])` as contributing one signed cross product
- sum these contributions around the boundary

So instead of thinking about area as a global shape quantity, we turn it into:

- one linear pass over edges
- one final absolute value

## Core Idea

For polygon vertices `p[0], p[1], ..., p[n-1]`, the shoelace formula says:

```text
2 * area = abs(sum cross(p[i], p[i+1]))
```

where `p[n]` means `p[0]`.

So the algorithm is:

1. Walk once around the polygon.
2. Add the signed cross product of each directed edge contribution.
3. Take the absolute value at the end.

The sign depends on orientation:

- counterclockwise order gives positive signed area
- clockwise order gives negative signed area

Because the judge wants `2a` instead of `a`, we can stay entirely in integer arithmetic and print the absolute doubled area directly.

## Complexity

- one pass over the vertices
- total: `O(n)`

## Pitfalls / Judge Notes

- Do not forget the closing edge from the last vertex back to the first.
- The answer may exceed `long long` if you only trust 64-bit intermediate multiplication, so `__int128` keeps the cross-sum comfortably safe.
- The polygon may be listed clockwise or counterclockwise, so take the absolute value at the end.
- The judge wants `2 * area`, not the floating-point area itself.

## Reusable Pattern

- Topic page: [Polygon Area And Point Location](../../../../topics/geometry/polygon-area-point-location/README.md)
- Practice ladder: [Polygon Area And Point-Location ladder](README.md)
- Starter template: [shoelace-area.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/shoelace-area.cpp)
- Notebook refresher: [Geometry cheatsheet](../../../../notebook/geometry-cheatsheet.md)
- Carry forward: when vertices already come in boundary order, many global polygon quantities are just a sum over edges.
- This note adds: the exact doubled-area output convention and safe integer accumulation.

## Solutions

- Code: [polygonarea.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/polygon-area-point-location/polygonarea.cpp)
