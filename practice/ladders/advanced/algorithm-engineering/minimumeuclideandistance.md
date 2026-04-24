# Minimum Euclidean Distance

- Title: `Minimum Euclidean Distance`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/2194/](https://cses.fi/problemset/task/2194/)
- Secondary topics: `Closest pair`, `Sweep line`, `Ordered active set`
- Difficulty: `hard`
- Subtype: `Maintain an active strip and report the minimum squared distance between points`
- Status: `solved`
- Solution file: [minimumeuclideandistance.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/algorithm-engineering/minimumeuclideandistance.cpp)

## Why Practice This

This is a strong algorithm-engineering anchor because the high-level idea is standard, but accepted code still depends on getting many small details exactly right.

The intended closest-pair sweep is only `O(n log n)` if the implementation preserves the correct active strip, searches candidates in the right order, and avoids floating-point mistakes.

That makes this problem a good benchmark for turning a geometric theorem into reliable contest code.

## Recognition Cue

Reach for the closest-pair sweep when:

- the object is an unweighted set of points
- the naive `O(n^2)` pair scan is too large
- the answer is one global nearest-neighbor distance
- sorting by one coordinate and maintaining a narrow active strip feels plausible

The strongest smell is:

- "minimum Euclidean distance among all pairs of points"

That is usually a divide-and-conquer or sweep-line closest-pair problem, not graph shortest paths or hull geometry.

## Problem-Specific Transformation

The statement is about geometric distance, but the reusable rewrite is:

- sort by `x`
- maintain exactly the points still capable of improving the current best answer
- organize them by `y` so the candidate scan stays local

So the original all-pairs problem becomes:

- one monotone sweep
- one active strip invariant
- one bounded candidate window per point

## Core Idea

Sort all points by `x`, then sweep from left to right.

Keep:

- `best`: the smallest squared distance found so far
- an active set ordered by `y`
- a left pointer for removing points that are already too far in `x`

For the current point `p`:

1. remove every old point whose horizontal distance from `p` already exceeds `sqrt(best)`
2. among the remaining active points, only inspect those with `y` in `[p.y - sqrt(best), p.y + sqrt(best)]`
3. update `best` with any closer candidate
4. insert `p` into the active set

Why is this enough?

After sorting by `x`, any point too far away horizontally cannot improve the answer.

Among the remaining points, we only need the narrow `y` window because if `|dy| > sqrt(best)`, then the squared distance is already larger than `best`.

The sweep-line invariant is that the active set contains exactly the points still capable of beating the current answer.

This repo solution stays entirely in integer arithmetic:

- distances are stored as squared distances
- the output is already the squared answer
- `sqrt(best)` is used only as an integer radius for pruning, with a corrected floor-sqrt helper

## Complexity

- sorting: `O(n log n)`
- each insertion/removal in the active set: `O(log n)`
- total: `O(n log n)`

The candidate scan inside the strip is bounded by the standard closest-pair packing argument.

## Pitfalls / Judge Notes

- The judge asks for the **minimum squared distance**, so do not take a square root at the end.
- Use `long long` for coordinates and answers, and use wider intermediate arithmetic when squaring differences.
- If duplicate points exist, the answer becomes `0`; the sweep handles that naturally.
- The active set needs a unique key even when two points share the same `(x, y)`, so storing an `id` is the safest choice.
- Be careful with the strip radius: use a floor square root of `best`, then fix any rounding drift explicitly instead of trusting floating point alone.

## Reusable Pattern

- Topic page: [Algorithm Engineering](../../../../topics/advanced/algorithm-engineering/README.md)
- Practice ladder: [Algorithm Engineering ladder](README.md)
- Starter template: [contest-main.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/foundations/contest-main.cpp)
- Notebook refresher: [Geometry cheatsheet](../../../../notebook/geometry-cheatsheet.md)
- Carry forward: keep the active structure as small as the proof allows, and stay in integer arithmetic when the judge already wants a squared metric.
- This note adds: the exact sweep-line invariant and pruning rules for closest-pair code that is both fast and trustworthy.

## Solutions

- Code: [minimumeuclideandistance.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/advanced/algorithm-engineering/minimumeuclideandistance.cpp)
