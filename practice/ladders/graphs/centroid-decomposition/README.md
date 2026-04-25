# Centroid Decomposition Ladder

This ladder is for the first tree lane where balanced recursive splitting becomes the main algorithm, not just a detail.

## Who This Is For

Use this lane if:

- subtree flattening already makes sense
- HLD feels too path-segment oriented for the statement in front of you
- you keep seeing static-tree problems whose clean split is “through one pivot or not”

This is a thin lane on purpose:

- one exact starter
- one direct in-repo flagship rep
- strong compare points back into `Trees`, `Euler Tour / Subtree`, and `HLD`

## Warm-Up

- one-centroid existence and subtree-size balance
- walk toward the too-large side
- why every recursive component shrinks by at least half

Target skill:

- explain why centroid-tree depth is only `O(log n)`

Warm-up compare point:

- [Finding a Centroid](https://cses.fi/problemset/task/2079)

## Core

- build the centroid tree
- store centroid parent / centroid depth
- understand per-node centroid ancestors
- exact flagship rep: [Ciel the Commander](cielthecommander.md)

Target skill:

- know when the problem wants the decomposition tree itself, not subtree intervals or heavy paths

## Stretch

- nearest-marked-node pattern -> [Xenia and Tree](https://codeforces.com/problemset/problem/342/E)
- path counting through one centroid -> [Fixed-Length Paths I](https://cses.fi/problemset/task/2080)
- longer path-counting variants -> [Fixed-Length Paths II](https://cses.fi/problemset/task/2081)
- only move to those after the decomposition structure itself feels routine

Target skill:

- distinguish “walk centroid ancestors” problems from “count paths through current centroid” problems

## Retrieval Layer

- exact quick sheet -> [Centroid hot sheet](../../../../notebook/centroid-hot-sheet.md)
- exact starter -> [centroid-decomposition.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/centroid-decomposition.cpp)
- subtree-only compare point -> [Subtree Queries hot sheet](../../../../notebook/subtree-queries-hot-sheet.md)
- path-query compare point -> [HLD hot sheet](../../../../notebook/hld-hot-sheet.md)

## Repo Anchors And Compare Points

- topic page -> [Centroid Decomposition](../../../../topics/graphs/centroid-decomposition/README.md)
- rooted-tree base -> [Trees](../../../../topics/graphs/trees/README.md)
- subtree-only compare point -> [Euler Tour / Subtree Queries](../../../../topics/graphs/euler-tour-subtree/README.md)
- path-query compare point -> [Heavy-Light Decomposition](../../../../topics/graphs/hld/README.md)
- broader routing -> [Graphs ladder](../README.md)

The cleanest in-repo loop here is:

1. learn the structural invariant from the [Centroid Decomposition topic](../../../../topics/graphs/centroid-decomposition/README.md)
2. solve or revisit [Ciel the Commander](cielthecommander.md) to trust the decomposition tree itself
3. compare the lane against [Subtree Queries](../euler-tour-subtree/subtreequeries.md) and [Path Queries II](../hld/pathqueries2.md)
4. only then jump to `Xenia and Tree` or path-counting variants

## Exit Criteria

You are ready to move on when:

- you can find a centroid and explain why recursive depth is `O(log n)`
- you can say clearly when centroid decomposition beats subtree flattening or HLD
- you can explain how one query/update becomes a walk over `O(log n)` centroid ancestors

## External Practice

- [CSES - Finding a Centroid](https://cses.fi/problemset/task/2079)
- [Codeforces - Ciel the Commander](https://codeforces.com/problemset/problem/321/C)
- [Codeforces - Xenia and Tree](https://codeforces.com/problemset/problem/342/E)
- [CSES - Fixed-Length Paths I](https://cses.fi/problemset/task/2080)
- [USACO Guide - Centroid Decomposition](https://usaco.guide/plat/centroid?lang=java)

## Tutorial Link

- [Centroid Decomposition](../../../../topics/graphs/centroid-decomposition/README.md)
