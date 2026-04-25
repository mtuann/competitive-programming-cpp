# Closest Pair

- Title: `Closest Pair`
- Judge / source: `AOJ`
- Original URL: [https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A)
- Secondary topics: `Nearest pair`, `Sweep line`, `Active strip`
- Difficulty: `medium`
- Subtype: `Sweep one static point set and output the minimum Euclidean distance`
- Status: `solved`
- Solution file: [closestpair.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/nearest-pair/closestpair.cpp)

## Why Practice This

This is the cleanest first nearest-pair benchmark in the repo:

- the statement is exactly the canonical problem
- there is no extra modeling noise
- the only job is to trust the active-strip sweep and print the final distance correctly

So this problem is not about inventing a new geometry trick.

It is about recognizing:

```text
static point set + global minimum Euclidean pair
=> nearest-pair sweep
```

## Recognition Cue

Reach for the nearest-pair sweep when:

- the input is just one batch of points
- the answer is one minimum Euclidean distance
- `O(n^2)` pair scanning is too slow
- sorting by `x` and keeping a small active strip feels plausible

The strongest smell is:

- "find the distance of the closest points"

That is usually the dedicated nearest-pair lane, not hull geometry and not graph shortest paths.

## Problem-Specific Transformation

The statement is about geometry distance, but the reusable rewrite is:

- sort points by `x`
- keep only the earlier points still close enough in `x` to matter
- organize that strip by `y`
- scan only the local `y` window around the current point

So the original all-pairs problem becomes:

- one monotone sweep
- one active strip invariant
- one bounded candidate scan per point

## Core Idea

Sort all points by `(x, y)`, then sweep from left to right.

Keep:

- `best2`: the current minimum squared distance
- `left`: first point still alive in the active strip
- one active set ordered by `y`

For the current point `p`:

1. remove every old point whose horizontal distance from `p` already exceeds the current best radius
2. among the survivors, only inspect points with `y` in:

$$
[p.y - \sqrt{best2},\ p.y + \sqrt{best2}]
$$

3. update `best2`
4. insert `p`

The key invariant is:

- the active set contains exactly the points that can still beat the current answer

At the end, print:

$$
\sqrt{best2}
$$

because this judge wants the true Euclidean distance, not the squared answer.

## Complexity

- sorting: `O(n log n)`
- each active-set insert / erase / range start: `O(log n)`
- total: `O(n log n)`

The candidate scan stays bounded by the standard closest-pair packing argument.

## Pitfalls / Judge Notes

- AOJ wants the actual Euclidean distance, so take one final square root at the end.
- It is still safer to keep the internal best value as a squared distance.
- Duplicate points make the answer `0`.
- The active set should be ordered by `y`, not by `x`.
- This is a dedicated nearest-pair problem; if you reopen [Minimum Euclidean Distance](../../advanced/algorithm-engineering/minimumeuclideandistance.md), remember that note is the implementation-clinic sibling, not the first exposure.

## Reusable Pattern

- Topic page: [Nearest Pair of Points](../../../../topics/geometry/nearest-pair/README.md)
- Practice ladder: [Nearest Pair ladder](README.md)
- Starter template: [`closest-pair-sweep.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/closest-pair-sweep.cpp)
- Notebook refresher: [Nearest Pair hot sheet](../../../../notebook/nearest-pair-hot-sheet.md)
- Carry forward: sort by `x`, maintain the active strip by `y`, and keep squared distances internally.
- This note adds: how to switch cleanly from squared bookkeeping to the true distance output contract.

## Solutions

- Code: [closestpair.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/geometry/nearest-pair/closestpair.cpp)
