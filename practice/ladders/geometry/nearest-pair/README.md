# Nearest Pair Ladder

## Who This Is For

Use this lane when pairwise checking is too slow and the geometry really is just one global nearest-pair question on a static point set.

## Warm-Up

- sort points by `x`
- store candidates in one active set by `y`
- distinguish squared answer from true Euclidean distance

## Core

- active `x`-strip invariant
- `y`-window scan around the current point
- duplicate-point shortcut to `0`
- flagship canonical rep: [Closest Pair](closestpair.md)

## Stretch

- explain why the same family can appear as an algorithm-engineering case study in [Minimum Euclidean Distance](../../advanced/algorithm-engineering/minimumeuclideandistance.md)
- compare sweep retrieval against a divide-and-conquer proof of the same `O(n log n)` bound
- say when the problem is really generic sweep-line, not the dedicated nearest-pair lane

## Retrieval Layer

- exact starter -> [`closest-pair-sweep.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/closest-pair-sweep.cpp)
- quick reminder sheet -> [Nearest Pair hot sheet](../../../../notebook/nearest-pair-hot-sheet.md)
- compare point -> [Sweep Line](../../../../topics/geometry/sweep-line/README.md)

## Repo Anchors

- [Closest Pair](closestpair.md)
- [Minimum Euclidean Distance](../../advanced/algorithm-engineering/minimumeuclideandistance.md)

## Exit Criteria

You are ready to move on when you can:

- state exactly what lives in the active strip
- explain why candidate scanning happens in `y`, not `x`
- keep squared and unsquared distances straight
- tell when a closest-pair task belongs in the dedicated lane instead of generic sweep-line notes

## External Practice

- [AOJ CGL_5_A - Closest Pair](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A)
- [CSES - Minimum Euclidean Distance](https://cses.fi/problemset/task/2194/)

## Tutorial Link

- [Nearest Pair of Points](../../../../topics/geometry/nearest-pair/README.md)
