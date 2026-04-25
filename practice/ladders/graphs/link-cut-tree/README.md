# Link-Cut Tree Ladder

This ladder is for the first time a tree problem says:

- the forest changes online
- path queries still remain
- rebuilding one static decomposition after each change is no longer acceptable

It is intentionally a thin lane:

- one exact starter
- one verifier-style flagship rep
- strong compare points back to static-tree routes

## Who This Is For

Use this lane if:

- [Heavy-Light Decomposition](../../../../topics/graphs/hld/README.md) already makes sense on static trees
- [Euler Tour / Subtree Queries](../../../../topics/graphs/euler-tour-subtree/README.md) already feels easy when the root and edges stay fixed
- your current problem changes the tree itself and static preprocessing is the thing that breaks

## Warm-Up

- static path aggregates -> [Path Queries II](../hld/pathqueries2.md)
- static rooted subtree intervals -> [Subtree Queries](../euler-tour-subtree/subtreequeries.md)
- offline dynamic connectivity contrast -> [Dynamic Connectivity](../../data-structures/dsu-rollback/dynamicconnectivity.md)

Target skill:

- explain clearly why the next problem is not "just harder HLD"

## Core

- auxiliary tree vs represented tree
- `access`, `makeroot`, `find_root`
- exact starter route: [`link-cut-tree-path-sum.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/link-cut-tree-path-sum.cpp)
- flagship rep: [Dynamic Tree Vertex Add Path Sum](dynamictreevertexaddpathsum.md)

Target skill:

- turn a dynamic-tree statement into `makeroot / access / link / cut / path aggregate` without guessing

## Stretch

- [Library Checker - Dynamic Tree Vertex Set Path Composite](https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite)
- [USACO Guide - Link Cut Tree](https://usaco.guide/adv/link-cut-tree?lang=cpp)
- [OI Wiki - Link-Cut Tree](https://en.oi-wiki.org/ds/lct/)

Target skill:

- know when the exact starter still fits and when the aggregate contract has drifted into non-commutative or more generic territory

## Retrieval Layer

- exact quick sheet -> [Link-Cut Tree hot sheet](../../../../notebook/link-cut-tree-hot-sheet.md)
- exact starter -> [`link-cut-tree-path-sum.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/link-cut-tree-path-sum.cpp)
- static-path compare point -> [HLD hot sheet](../../../../notebook/hld-hot-sheet.md)
- subtree-only compare point -> [Subtree Queries hot sheet](../../../../notebook/subtree-queries-hot-sheet.md)
- graph-family chooser -> [Graph cheatsheet](../../../../notebook/graph-cheatsheet.md)

## Repo Anchors And Compare Points

- topic page -> [Link-Cut Tree](../../../../topics/graphs/link-cut-tree/README.md)
- static path compare point -> [Heavy-Light Decomposition](../../../../topics/graphs/hld/README.md)
- static subtree compare point -> [Euler Tour / Subtree Queries](../../../../topics/graphs/euler-tour-subtree/README.md)
- offline connectivity compare point -> [DSU Rollback / Offline Dynamic Connectivity](../../../../topics/data-structures/dsu-rollback/README.md)
- broader routing -> [Graphs ladder](../README.md)

## Exit Criteria

You are ready to move on when:

- you can say why static HLD/Euler flattening are the wrong fit for the query stream
- you understand the difference between represented forest and auxiliary splay tree
- you can explain why `makeroot(u)` then `access(v)` exposes the path `u -> v`
- you can use the starter for one dynamic path-sum problem without treating it as black magic

## External Practice

- [Library Checker - Dynamic Tree Vertex Add Path Sum](https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum)
- [Library Checker - Dynamic Tree Vertex Set Path Composite](https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite)
- [USACO Guide - Link Cut Tree](https://usaco.guide/adv/link-cut-tree?lang=cpp)

## Tutorial Link

- [Link-Cut Tree](../../../../topics/graphs/link-cut-tree/README.md)
