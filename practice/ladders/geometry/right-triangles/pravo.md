# PRAVO

- Title: `Tam giác vuông`
- Judge / source: `VN SPOJ`
- Original URL: [https://vn.spoj.com/problems/PRAVO/](https://vn.spoj.com/problems/PRAVO/)
- Main topic: `Geometry -> Right Triangles`
- Secondary topics: `Normalized direction vectors`, `Sorting`, `Perpendicular directions`
- Difficulty: `medium`
- Subtype: `Counting right triangles`
- Source contest: `Croatian Open 2007`
- Status: `solved`
- Solution file: [pravo.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/right-triangles/pravo.cpp)
- Alternate solution variants: [pravo-buffered.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/right-triangles/pravo-buffered.cpp), [pravo-macro-buffer.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/right-triangles/pravo-macro-buffer.cpp)

## Why Practice This

This is a strong geometry practice problem because the winning idea is a transformation, not a formula hunt: fix the right-angle vertex and count perpendicular directions efficiently.

## Key Idea

For each point `P`, count how many right triangles have their right angle at `P`.

If two other points `A` and `B` form a right angle at `P`, then the vectors:

- `PA`
- `PB`

must be perpendicular.

So for a fixed pivot `P`, the problem becomes:

1. build the direction of every vector from `P` to another point
2. normalize each direction so opposite rays on the same line are merged
3. count pairs of directions that are perpendicular

## Complexity

For each pivot:

- build `n - 1` directions
- sort them
- compress equal directions
- binary-search perpendicular partners

Overall complexity:

`O(n^2 log n)`

With `n <= 1500`, this is the intended range.

## Pitfalls / Judge Notes

For a vector `(dx, dy)`:

1. divide by `gcd(|dx|, |dy|)`
2. flip the sign so the direction is stored canonically

That means:

- `(1, 0)` and `(-1, 0)` become the same line direction
- `(0, 1)` and `(0, -1)` become the same line direction

This is exactly what we want, because when the right angle is at `P`, the sign along a ray does not matter for perpendicularity.

- coordinates fit in `long long`
- normalized direction components fit in `int`
- the answer uses `long long`
- the implementation avoids floating point entirely
- the judge time limit is a bit tight, so the code uses sorting plus binary search instead of heavier hash/map logic

## Solutions

- Code: [pravo.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/right-triangles/pravo.cpp)
- Buffered variant: [pravo-buffered.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/right-triangles/pravo-buffered.cpp)
- Macro-buffered variant: [pravo-macro-buffer.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/right-triangles/pravo-macro-buffer.cpp)
