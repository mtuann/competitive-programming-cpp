# Convex Hull

- Title: `Convex Hull`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/2195](https://cses.fi/problemset/task/2195)
- Main topic: `Geometry -> Convex Hull`
- Secondary topics: `Andrew monotone chain`, `Orientation test`, `Boundary collinear points`
- Difficulty: `medium`
- Subtype: `Construct the convex hull and print every point on its boundary`
- Status: `solved`
- Solution file: [convexhull.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/convex-hull/convexhull.cpp)

## Why Practice This

This is the canonical first full hull-construction problem:

- the core primitive is still just orientation
- sorting points turns local turn tests into a global boundary
- the only subtle part is the judge policy for collinear boundary points

That last point matters here: CSES wants **all** points on the hull, not only the extreme corners.

## Key Idea

Sort all points lexicographically by `(x, y)` and build the hull in two passes:

- `lower`: walk from left to right
- `upper`: walk from right to left

Each pass keeps a stack-like list of boundary points. When the last three points make a **clockwise** turn, the middle point cannot belong to that side of the hull, so we pop it.

The important policy choice is:

```text
while cross(last2, last1, p) < 0:
    pop last1
```

Notice the strict `< 0`, not `<= 0`.

- `< 0` removes only genuine right turns
- `== 0` keeps collinear points on the boundary

That is exactly what this problem asks for.

After building both chains:

- drop the duplicate endpoint from each chain
- concatenate `lower` and `upper`

The result is the full boundary in counterclockwise order, with every hull point included once.

## Complexity

- sorting: `O(n log n)`
- lower + upper scan: `O(n)`
- total: `O(n log n)`

This is optimal for comparison-based hull construction.

## Pitfalls / Judge Notes

- CSES explicitly says to print **all points that lie on the convex hull**, so do not discard boundary-collinear points.
- Keep the pop condition strict (`< 0`). If you use `<= 0`, you will keep only corner points and fail.
- Use integer geometry only. Coordinates go up to `1e9`, so cross products should use `__int128` for safe intermediate arithmetic.
- The judge accepts the hull points in any order, but outputting them in boundary order is the cleanest and easiest way to avoid duplicates.

## Solutions

- Code: [convexhull.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/convex-hull/convexhull.cpp)
