# DSU Rollback / Offline Dynamic Connectivity Ladder

This lane is for the first time deletions break plain DSU, but the whole event timeline is still known in advance.

## Who This Is For

Use this lane if:

- merge-only [DSU](../dsu/README.md) already feels stable
- you can recognize offline processing, but "rollback over time" still feels magical
- deletions are the only thing stopping a clean connectivity model

This is a thin lane on purpose:

- one exact starter
- one direct in-repo flagship rep
- strong compare points back into `DSU` and `Offline Tricks`

## Warm-Up

- explain why plain DSU fails on deletions
- explain why the offline move is legal
- extract one edge lifetime interval `[l, r)` by hand

Target skill:

- see the problem as "edge lifetimes over time", not "mysterious dynamic graph maintenance"

Warm-up compare points:

- [DSU ladder](../dsu/README.md)
- [Offline Tricks ladder](../offline-tricks/README.md)

## Core

- rollback-friendly DSU without ordinary path compression
- one snapshot / rollback per DFS node
- segment tree over time
- exact flagship rep: [Dynamic Connectivity](dynamicconnectivity.md)

Target skill:

- say clearly why each edge is applied on only `O(log q)` time-tree nodes and why rollback restores the parent state exactly

## Stretch

- component-value variant -> [Library Checker: Dynamic Graph Vertex Add Component Sum](https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum)
- compare against pure sorted sweeps in [Offline Tricks](../../../../topics/data-structures/offline-tricks/README.md)
- revisit tree or graph routes later, where the real problem is no longer just connectivity

Target skill:

- distinguish "rollback DSU is enough" from "the maintained state is no longer DSU-shaped"

## Retrieval Layer

- exact quick sheet -> [DSU Rollback hot sheet](../../../../notebook/dsu-rollback-hot-sheet.md)
- exact starter -> [dsu-rollback-dynamic-connectivity.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/dsu-rollback-dynamic-connectivity.cpp)
- merge-only compare point -> [DSU hot sheet](../../../../notebook/dsu-hot-sheet.md)
- family compare point -> [Offline Tricks hot sheet](../../../../notebook/offline-tricks-hot-sheet.md)

## Repo Anchors And Compare Points

- topic page -> [DSU Rollback / Offline Dynamic Connectivity](../../../../topics/data-structures/dsu-rollback/README.md)
- merge-only baseline -> [DSU](../../../../topics/data-structures/dsu/README.md)
- family compare point -> [Offline Tricks](../../../../topics/data-structures/offline-tricks/README.md)
- broader routing -> [Data Structures ladder](../README.md)

The cleanest in-repo loop here is:

1. trust the merge-only boundary in [DSU](../../../../topics/data-structures/dsu/README.md)
2. learn the time-interval model from [DSU Rollback / Offline Dynamic Connectivity](../../../../topics/data-structures/dsu-rollback/README.md)
3. solve or revisit [Dynamic Connectivity](dynamicconnectivity.md)
4. compare the lane back against [Distinct Values Queries](../offline-tricks/distinctvaluesqueries.md) so the difference between `sorted sweep` and `rollback over time` becomes crisp

## Exit Criteria

You are ready to move on when:

- you can explain why ordinary path compression is not the default rollback choice
- you can derive edge intervals `[l, r)` from an add/remove timeline without off-by-one mistakes
- you know when to stay in this lane and when the problem has escaped plain connectivity

## External Practice

- [CSES - Dynamic Connectivity](https://cses.fi/problemset/task/2133)
- [Library Checker - Dynamic Graph Vertex Add Component Sum](https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum)
- [USACO Guide - Offline Deletion](https://usaco.guide/adv/offline-del)

## Tutorial Link

- [DSU Rollback / Offline Dynamic Connectivity](../../../../topics/data-structures/dsu-rollback/README.md)
