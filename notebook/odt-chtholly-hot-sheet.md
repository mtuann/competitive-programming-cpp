# ODT / Chtholly Hot Sheet

Use this sheet when the array is better modeled as an ordered partition of
constant intervals than as one point-by-point structure.

## Do Not Use When

- you need hard worst-case online guarantees -> [Lazy Segment Tree](../topics/data-structures/lazy-segment-tree/README.md)
- clamp-style range updates are the real job -> [Segment Tree Beats](../topics/data-structures/segment-tree-beats/README.md)
- all queries are reorderable and offline processing kills the problem sooner
- there is no interval-collapsing assign operation and fragmentation can grow
  adversarially

## Choose By Signal

- range assign keeps collapsing equal-value runs -> `ODT / Chtholly`
- hard range algebra over all points -> lazy / beats segment tree
- one ordered active set, not one interval partition -> `set / multiset`
- one current best element only -> heap

## Core Invariants

- nodes are disjoint intervals ordered by left endpoint
- every node stores one constant value on its whole interval
- `split(x)` isolates boundaries before every range touch
- `assign(l, r, v)` is the operation that usually keeps the structure viable by
  collapsing many intervals back into one

## Main Traps

- calling `split(l)` before `split(r + 1)`
- mutating interval boundaries inside the set
- claiming `O(log n)` when the true cost depends on the number of touched runs
- using the route on adversarial updates with no collapse mechanism

## Exact Starter Route

- exact starter -> [odt-interval-set.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/odt-interval-set.cpp)
- flagship in-lane rep -> [Willem, Chtholly and Seniorious](../practice/ladders/data-structures/odt-chtholly/willemchthollyandseniorious.md)
- deterministic bridge -> [915E - Physical Education Lessons](https://codeforces.com/problemset/problem/915/E)

## Reopen Paths

- full topic page -> [ODT / Chtholly](../topics/data-structures/odt-chtholly/README.md)
- broader chooser -> [Data structures cheatsheet](data-structures-cheatsheet.md)
- reusable snippet map -> [Template Library](../template-library.md)
- retrieval router -> [Build Kit](../docs/build-kit.md)
