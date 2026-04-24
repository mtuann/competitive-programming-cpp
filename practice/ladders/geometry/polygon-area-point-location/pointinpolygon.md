# Point in Polygon

- Title: `Point in Polygon`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/2192](https://cses.fi/problemset/task/2192)
- Secondary topics: `Ray casting`, `Boundary handling`, `On-segment check`
- Difficulty: `medium`
- Subtype: `Classify query points as inside, outside, or on the boundary of a simple polygon`
- Status: `solved`
- Solution file: [pointinpolygon.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/polygon-area-point-location/pointinpolygon.cpp)

## Why Practice This

This is the first full point-location problem where geometry policy matters more than the outer loop.

You need to get three things right:

- exact boundary detection
- a crossing rule that does not double-count polygon vertices
- a classification convention that stays consistent throughout the implementation

That makes it the natural second anchor after `Polygon Area`.

## Recognition Cue

Reach for point-in-polygon logic when:

- the polygon is static
- many query points must be classified
- the first real decision is boundary policy, not optimization
- a ray-casting or winding-number test is the intended primitive

The strongest smell is:

- `INSIDE / OUTSIDE / BOUNDARY`

That means your classification convention must be fixed before you start coding.

## Problem-Specific Transformation

The statement sounds like full geometric reasoning, but the reusable rewrite is:

- check boundary first with orientation + on-segment
- otherwise reduce the question to parity of ray crossings

So the problem becomes:

- one exact boundary predicate
- one consistent half-open crossing rule

The implementation difficulty is almost entirely in making those two rules agree.

## Core Idea

For each query point `p`, do two checks.

### 1. Boundary first

If `p` lies on any polygon edge, the answer is immediately `BOUNDARY`.

That means:

- `orient(a, b, p) == 0`
- and `p` lies inside the bounding box of segment `ab`

### 2. Otherwise use parity of ray crossings

Cast a horizontal ray to the right from `p`.

Whenever one polygon edge crosses that ray, flip an `inside` bit.

At the end:

- odd number of crossings -> `INSIDE`
- even number of crossings -> `OUTSIDE`

The subtle part is vertex handling. The standard fix is to use a half-open vertical test so one endpoint counts and the other does not. That prevents double-counting when the ray passes through a polygon vertex.

## Complexity

- one query: `O(n)`
- all `m` queries: `O(nm)`

This is fully fine for the CSES limits.

## Pitfalls / Judge Notes

- Check `BOUNDARY` before doing parity logic.
- Horizontal edges and vertex hits are where most wrong answers come from. Use one consistent half-open crossing rule.
- Keep everything in integer arithmetic. Cross products and on-segment checks are exact here.
- `__int128` is a good default for cross-product intermediates with coordinates up to `1e9`.

## Reusable Pattern

- Topic page: [Polygon Area And Point Location](../../../../topics/geometry/polygon-area-point-location/README.md)
- Practice ladder: [Polygon Area And Point-Location ladder](README.md)
- Starter template: [point-in-polygon.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/point-in-polygon.cpp)
- Notebook refresher: [Geometry cheatsheet](../../../../notebook/geometry-cheatsheet.md)
- Carry forward: define your boundary policy first, then make the ray-crossing rule serve that policy.
- This note adds: the exact inclusive boundary classification used by this judge.

## Solutions

- Code: [pointinpolygon.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/polygon-area-point-location/pointinpolygon.cpp)
