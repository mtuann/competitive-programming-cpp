# Nearest Pair Hot Sheet

Use this page when the task is:

```text
one static set of planar points -> one global closest Euclidean pair
```

and you want the shortest route back to the active strip invariant.

## Do Not Use When

- the points change online
- the task is really event ordering over segments or rectangles
- the statement wants the outer boundary of the points
- the metric or dimension changed enough that the usual 2D packing argument no longer applies directly

## Choose By Signal

- one static nearest Euclidean pair -> [`closest-pair-sweep.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/closest-pair-sweep.cpp)
- same family, but the repo note you want is implementation-heavy -> [Minimum Euclidean Distance](../practice/ladders/advanced/algorithm-engineering/minimumeuclideandistance.md)
- outer boundary of many points -> [Convex Hull](../topics/geometry/convex-hull/README.md)
- many geometric events, active objects, and local neighbor rules -> [Sweep Line](../topics/geometry/sweep-line/README.md)

## Core Invariants

- points are processed in increasing `x`
- the active set contains exactly the points still close enough in `x` to matter
- the active set is ordered by `y`, because the surviving candidate window is a `y` interval
- internal comparisons are safest in squared distance, even if the final answer needs one square root

## Main Traps

- mixing squared and unsquared distance in the strip test
- forgetting duplicate points imply answer `0`
- ordering the active set by the wrong coordinate
- treating this as a hull or generic geometry-predicate problem

## Exact Starters In This Repo

- exact starter -> [`closest-pair-sweep.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/closest-pair-sweep.cpp)
- flagship in-lane rep -> [Closest Pair](../practice/ladders/geometry/nearest-pair/closestpair.md)
- compare point -> [Minimum Euclidean Distance](../practice/ladders/advanced/algorithm-engineering/minimumeuclideandistance.md)
- nearby chooser -> [Geometry cheatsheet](geometry-cheatsheet.md)

## Reopen Paths

- full lesson -> [Nearest Pair of Points](../topics/geometry/nearest-pair/README.md)
- broader geometry chooser -> [Geometry cheatsheet](geometry-cheatsheet.md)
- snippet chooser -> [Template Library](../template-library.md)
