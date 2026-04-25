# DSU Hot Sheet

Use this page when the statement is really about merge-only components and you want the fastest route back to a safe union-find model.

## Do Not Use When

- components must split or edges are deleted online
- the real question is path aggregate, shortest path, or subtree structure
- parity, rollback, or dynamic-connectivity variants are the actual point of the problem

## Choose By Signal

- repeated `same component?` or `merge these groups` -> [`dsu-basic.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/dsu-basic.cpp)
- Kruskal / cheapest edge that joins two components -> DSU
- component size or metadata that only depends on merges -> DSU with root-only metadata
- offline connectivity with additions only -> DSU
- rollback, parity, or deletions -> reopen the topic page before copying the plain starter
- offline edge deletions plus connectivity queries -> [DSU Rollback hot sheet](dsu-rollback-hot-sheet.md)

## Core Invariants

- every component has one representative root
- `find(x)` returns the current representative of `x`'s component
- metadata lives on roots only
- union by size and path compression change tree shape, not the partition itself

## Main Traps

- storing component metadata on non-root nodes
- assuming plain DSU supports deletions or rollback “with a few tweaks”
- forgetting that `same(a, b)` and `component_size(x)` are only meaningful through `find`

## Exact Starters In This Repo

- merge-only connectivity -> [`dsu-basic.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/dsu-basic.cpp)
- component-boundary note -> [C11XU](../practice/ladders/data-structures/dsu/c11xu.md)
- Kruskal compare point -> [Road Reparation](../practice/ladders/graphs/mst/roadreparation.md)
- rollback compare point -> [Dynamic Connectivity](../practice/ladders/data-structures/dsu-rollback/dynamicconnectivity.md)

## Reopen Paths

- representative invariant and variant boundaries -> [DSU](../topics/data-structures/dsu/README.md)
- deletions / undo route -> [DSU Rollback / Offline Dynamic Connectivity](../topics/data-structures/dsu-rollback/README.md)
- neighboring graph choice -> [Graph cheatsheet](graph-cheatsheet.md)
- broader structure chooser -> [Data structures cheatsheet](data-structures-cheatsheet.md)
