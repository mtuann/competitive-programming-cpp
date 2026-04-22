# PRAVO

- Title: `Tam giác vuông`
- Judge: `VN SPOJ`
- Original URL: [https://vn.spoj.com/problems/PRAVO/](https://vn.spoj.com/problems/PRAVO/)
- Source contest: `Croatian Open 2007`
- Main topic: `Geometry`
- Likely subtype: `Counting right triangles`
- Secondary topics: `Normalized direction vectors`, `Sorting`, `Perpendicular directions`
- Status: `solved`
- Solution file: [pravo.cpp](/Users/mitu/Desktop/work/cp-cpp/solutions/geometry/right-triangles/pravo.cpp)
- Buffered-input variant: [pravo-buffered.cpp](/Users/mitu/Desktop/work/cp-cpp/solutions/geometry/right-triangles/pravo-buffered.cpp)
- Macro-buffered variant: [pravo-macro-buffer.cpp](/Users/mitu/Desktop/work/cp-cpp/solutions/geometry/right-triangles/pravo-macro-buffer.cpp)

## Why This Folder

This problem is placed under `practice/ladders/geometry/right-triangles/` because the key step is a geometric transformation:

- fix one vertex as the right-angle vertex
- count pairs of perpendicular rays from that point

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

## Direction Normalization

For a vector `(dx, dy)`:

1. divide by `gcd(|dx|, |dy|)`
2. flip the sign so the direction is stored canonically

That means:

- `(1, 0)` and `(-1, 0)` become the same line direction
- `(0, 1)` and `(0, -1)` become the same line direction

This is exactly what we want, because when the right angle is at `P`, the sign along a ray does not matter for perpendicularity.

## Why This Works

Suppose a normalized line direction is `(x, y)`.

A perpendicular line direction is:

`(-y, x)`

after canonical normalization.

If a pivot has:

- `c1` points on one line direction
- `c2` points on its perpendicular line direction

then it contributes:

`c1 * c2`

right triangles with the right angle at that pivot.

Summing over all directions counts every pair twice, so we divide by `2` for each pivot.

## Complexity

For each pivot:

- build `n - 1` directions
- sort them
- compress equal directions
- binary-search perpendicular partners

Overall complexity:

`O(n^2 log n)`

With `n <= 1500`, this is the intended range.

## Implementation Notes

- coordinates fit in `long long`
- normalized direction components fit in `int`
- the answer uses `long long`
- the implementation avoids floating point entirely
- the judge time limit is a bit tight, so the code uses sorting plus binary search instead of heavier hash/map logic
- an alternate version with `fread`-based buffered input is provided for judge environments where I/O overhead matters
- an additional macro-based buffer version is included for people who prefer the classic SPOJ/OI template style
