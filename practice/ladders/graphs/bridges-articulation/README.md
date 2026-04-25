# Bridges / Articulation / BCC Ladder

This ladder should make `low-link` feel like one reusable family, not three unrelated graph tricks.

## Who This Is For

Use this lane if:

- "critical road" and "critical city" still feel like different algorithms
- you know DFS, but `tin / low` still feels slippery
- bridge trees or block-cut trees seem magical instead of structural

This lane is intentionally staged:

- one flagship bridge rep in-repo
- one exact starter
- strong compare points back to traversal, trees, and SCC boundaries

## Warm-Up

- DFS tree
- entry times
- back edges to ancestors

Target skill:

- explain what `low[v]` means in words before writing code

## Core

- [Necessary Roads](necessaryroads.md)
- bridge test `low[child] > tin[parent]`
- articulation test `low[child] >= tin[parent]`
- root special case

Target skill:

- move from one DFS invariant to critical-edge / critical-vertex output cleanly

## Stretch

- compare against [Trees](../trees/README.md) after bridge compression
- compare against [Topological Sort And SCC](../scc-toposort/README.md) so directed-vs-undirected separation stays clear
- use [Necessary Cities](https://cses.fi/problemset/task/2077) as the first articulation-only stretch
- use [Forbidden Cities](https://cses.fi/problemset/task/1705) as the first block-cut-tree stretch

Target skill:

- know when plain bridge/articulation is enough, and when the task really wants a block-cut or bridge-tree reduction

## Retrieval Layer

- quickest in-repo reminder -> [Low-Link hot sheet](../../../../notebook/lowlink-hot-sheet.md)
- exact starter -> [bridges-articulation-lowlink.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bridges-articulation-lowlink.cpp)
- flagship in-lane rep -> [Necessary Roads](necessaryroads.md)
- tree compare point after compression -> [Trees](../../../../topics/graphs/trees/README.md)

## Repo Anchors And Compare Points

- topic page -> [Bridges, Articulation Points, And Biconnected Components](../../../../topics/graphs/bridges-articulation/README.md)
- traversal prerequisite -> [BFS And DFS](../../../../topics/graphs/bfs-dfs/README.md)
- directed-graph boundary -> [Topological Sort And SCC](../../../../topics/graphs/scc-toposort/README.md)
- broader graph routing -> [Graphs ladder](../README.md)

The strongest in-repo loop here is:

1. learn the `tin / low` invariant from the [topic page](../../../../topics/graphs/bridges-articulation/README.md)
2. solve or revisit [Necessary Roads](necessaryroads.md) as the clean bridge rep
3. reopen the [Low-Link hot sheet](../../../../notebook/lowlink-hot-sheet.md) until the bridge/articulation inequalities are automatic
4. then move to `Necessary Cities` and `Forbidden Cities`

## Exit Criteria

You are ready to move on when:

- you can explain `low[v]` without formula-chasing
- you no longer mix up `>` and `>=`
- you remember the root articulation rule automatically
- you can say whether the next structure should be a bridge tree or a block-cut tree

## External Practice

- [CSES - Necessary Roads](https://cses.fi/problemset/task/2076)
- [CSES - Necessary Cities](https://cses.fi/problemset/task/2077)
- [CSES - Forbidden Cities](https://cses.fi/problemset/task/1705)
- [Library Checker - Two-Edge-Connected Components](https://judge.yosupo.jp/problem/two_edge_connected_components)

## Tutorial Link

- [Bridges, Articulation Points, And Biconnected Components](../../../../topics/graphs/bridges-articulation/README.md)
