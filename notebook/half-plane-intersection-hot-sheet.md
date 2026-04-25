# Half-Plane Intersection Hot Sheet

Use this page when the task is really:

```text
many directed line constraints -> one bounded feasible polygon
```

and you want the shortest route back to angle sorting, parallel tie-breaking, and deque cleanup.

## Do Not Use When

- the input is a point set and you need its outer envelope
- the real task is event ordering over many moving intersections
- one polygon area / inside test already solves the problem
- the intersection is unbounded and you have not decided on a bounding-box or alternate output policy

## Choose By Signal

- bounded convex region from many directed lines -> [`half-plane-intersection.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/half-plane-intersection.cpp)
- camera / visibility region inside one simple polygon -> [Big Brother](../practice/ladders/geometry/half-plane-intersection/bigbrother.md)
- outer boundary of many points -> [Convex Hull](../topics/geometry/convex-hull/README.md)
- event ordering or active-set geometry -> [Sweep Line](../topics/geometry/sweep-line/README.md)

## Core Invariants

- every half-plane keeps the **left** side of its directed boundary line
- after sorting by direction angle, the surviving boundary lines appear in cyclic order
- equal-direction lines must be deduplicated by keeping only the most restrictive one
- if the newest half-plane kills feasibility, the bad intersections can only appear at the deque ends

## Main Traps

- forgetting to reverse polygon edges when the interior is on the right side
- mixing strict and non-strict sidedness tests
- letting same-angle lines survive in arbitrary order
- treating an unbounded intersection like a valid polygon output

## Exact Starters In This Repo

- exact starter -> [`half-plane-intersection.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/geometry/half-plane-intersection.cpp)
- flagship in-lane rep -> [Big Brother](../practice/ladders/geometry/half-plane-intersection/bigbrother.md)
- nearby chooser -> [Geometry cheatsheet](geometry-cheatsheet.md)
- compare point -> [Convex Hull](../topics/geometry/convex-hull/README.md)

## Reopen Paths

- full lesson -> [Half-Plane Intersection](../topics/geometry/half-plane-intersection/README.md)
- broader geometry chooser -> [Geometry cheatsheet](geometry-cheatsheet.md)
- snippet chooser -> [Template Library](../template-library.md)
