# TFIELD

- Title: `Ruộng bậc thang`
- Judge / source: `VN SPOJ`
- Original URL: [https://vn.spoj.com/problems/TFIELD/](https://vn.spoj.com/problems/TFIELD/)
- Secondary topics: `Polygon area`, `Sorting nested polygons`, `Two pointers`
- Difficulty: `hard`
- Subtype: `Maximum weighted monochromatic contiguous segment`
- Source contest: `VOI 2015 Day 1`
- Status: `solved`
- Solution file: [tfield.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/sliding-window/tfield.cpp)

## Why Practice This

This is a nice mixed problem because the geometry part is only there to extract the real data model. After sorting the nested polygons and turning them into terrace-ring areas, the core task becomes a weighted recoloring problem on a line.

## Recognition Cue

This is a classic `geometry first, line problem later` disguise:

- the input objects are nested polygons
- the scoring depends only on visible ring areas after sorting
- after geometric preprocessing, every object becomes one weighted position on a line
- the final optimization is "best contiguous segment with at most k bad elements"

When nested geometry only serves to extract ordered ring weights, treat the geometry as preprocessing and solve the real one-dimensional problem afterward.

## Problem-Specific Transformation

The statement becomes much cleaner after two rewrites:

1. sort polygons by area and replace them with terrace-ring weights `W[i]`
2. for each target color `x`, scan for the maximum-weight contiguous segment containing at most `k` rings whose color is not `x`

So the final model is:

- one color per ring
- one positive weight per ring
- one sliding window per chosen target color

That is why the actual core is not geometry-heavy DP, but a weighted same-color window after geometric normalization.

## Core Idea

Each input polygon is the **outer boundary** of one terrace compartment. Since the polygons are convex and nested but listed in arbitrary order, we:

1. compute the doubled area of every polygon
2. sort the polygons by increasing area
3. convert them into ring areas

If `A[i]` is the doubled area of the `i`-th polygon in sorted order, then the doubled visible area of terrace `i` is:

- `W[0] = A[0]`
- `W[i] = A[i] - A[i - 1]` for `i > 0`

Now we only have:

- a color `C[i]`
- a positive weight `W[i]`

for each terrace ring.

Any visible same-color region must be a **contiguous block of rings** after sorting. So we want the maximum total weight of a segment that can be turned into one color by recoloring at most `k` rings.

For a fixed color `x`, this means:

- keep a sliding window
- count how many rings inside the window are **not** color `x`
- while that count is greater than `k`, move the left end

Because all ring weights are positive, the best window for each right endpoint is the leftmost one that still satisfies the recolor limit.

Run this two-pointer scan for every color that appears.

### Why The One-Dimensional Reduction Is Safe

Because the polygons are nested, after sorting by area every visible terrace is exactly one ring between two consecutive boundaries. Any monochromatic visible region therefore occupies consecutive rings only; it cannot skip an inner ring and reappear outside it.

So once the geometry is compressed into ring weights, the rest of the problem is genuinely a contiguous-segment problem on a line, not an approximation.

For example, if the sorted visible rings have colors:

```text
red, blue, blue, red
```

then any visible all-blue region must be one contiguous subarray such as rings `2..3`. It cannot use rings `2` and `4` while skipping ring `3`, because the terraces are nested annuli.

## Complexity

- polygon area computation: `O(sum n_i)`
- sorting polygons: `O(m log m)`
- sliding windows for all colors: `O(m^2)`

With `m, n_i <= 1000`, this is easily fast enough.

## Pitfalls / Judge Notes

- The input order is shuffled. You must sort the polygons by area first.
- The visible area of a terrace is **not** the polygon area itself except for the innermost terrace. Use area differences between consecutive sorted polygons.
- Coordinates can be as large as `10^9`, so doubled polygon areas can exceed `64-bit` during shoelace summation. Use `__int128`.
- The answer is always a multiple of `0.5`, so printing from doubled area is the safest approach.
- You only need to try target colors that already appear. Recoloring a segment to a brand-new color is never better than recoloring it to one of its existing colors.

## Reusable Pattern

- Topic page: [Sliding Window And Window DP](../../../../topics/foundations/patterns/two-pointers/README.md)
- Practice ladder: [Sliding Window And Window DP ladder](README.md)
- Starter template: [Template library overview](../../../../template-library.md)
- Notebook refresher: [DP cheatsheet](../../../../notebook/dp-cheatsheet.md)
- Carry forward: make the window or frontier monotone before you optimize the DP transitions.
- This note adds: the geometry normalization and weighted sliding-window logic specific to this terrace model.

## Solutions

- Code: [tfield.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/dp/sliding-window/tfield.cpp)
