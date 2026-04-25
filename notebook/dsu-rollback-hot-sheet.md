# DSU Rollback Hot Sheet

Use this page when the problem is still fundamentally about connectivity, but deletions or undo now block plain DSU.

## Do Not Use When

- only additions exist, so plain [DSU hot sheet](dsu-hot-sheet.md) already fits
- the problem is truly online and future events are unknown
- the real question is path aggregate, shortest path, or subtree structure
- one monotone offline sweep already solves the problem without rollback

## Choose By Signal

- add/remove edge timeline is fully known, and you need connectivity or component counts after each step -> [`dsu-rollback-dynamic-connectivity.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/dsu-rollback-dynamic-connectivity.cpp)
- the real blocker is deletions, not graph modeling -> reopen [DSU Rollback / Offline Dynamic Connectivity](../topics/data-structures/dsu-rollback/README.md)
- the problem is offline, but one sorted sweep is enough -> compare [Offline Tricks hot sheet](offline-tricks-hot-sheet.md)
- components only merge -> back down to [DSU hot sheet](dsu-hot-sheet.md)

## Core Invariants

- ordinary path compression is not the default here because every change must be undoable exactly
- each successful union records one reversible change on a stack
- an edge active on `[l, r)` is assigned to `O(log q)` nodes of a segment tree over time
- at DFS leaf `t`, the DSU represents exactly the graph after the first `t` events

## Main Traps

- getting the time model wrong: add at `i` means active from state `i`, remove at `i` means inactive at state `i`
- forgetting that initial edges start at time `0`
- using ordinary path compression and then being unable to rollback cleanly
- not taking one snapshot per DFS node before applying that node's batch

## Exact Starters In This Repo

- exact starter -> [`dsu-rollback-dynamic-connectivity.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/dsu-rollback-dynamic-connectivity.cpp)
- flagship in-lane rep -> [Dynamic Connectivity](../practice/ladders/data-structures/dsu-rollback/dynamicconnectivity.md)
- merge-only compare point -> [DSU hot sheet](dsu-hot-sheet.md)
- family compare point -> [Offline Tricks hot sheet](offline-tricks-hot-sheet.md)

## Reopen Paths

- full lesson and time-segmentation proof shape -> [DSU Rollback / Offline Dynamic Connectivity](../topics/data-structures/dsu-rollback/README.md)
- merge-only baseline -> [DSU](../topics/data-structures/dsu/README.md)
- family chooser -> [Offline Tricks](../topics/data-structures/offline-tricks/README.md)
- broader structure chooser -> [Data structures cheatsheet](data-structures-cheatsheet.md)
