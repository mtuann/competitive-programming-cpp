# Gomory-Hu Ladder

This ladder is for the first time a cut problem says:

- many vertex pairs matter
- direct repeated max-flow is too expensive
- the graph is undirected, so one cut tree can compress the whole family

It is intentionally narrow:

- one exact starter
- one flagship solved rep
- strong compare points back to plain flow

## Who This Is For

Use this lane if:

- [Maximum Flow](../../../../topics/graphs/flow/README.md) already feels comfortable for one `s-t` cut
- residual reachability after max flow already makes sense
- your next problem is no longer about one cut, but about **many** cuts on the same undirected graph

## Warm-Up

- one max flow / min cut -> [FFLOW](../flow/fflow.md)
- explicit cut certificate -> [Police Chase](../flow/policechase.md)
- one global undirected cut before the pairwise layer -> [Minimum Cut](../global-min-cut/globalmincut.md)

Target skill:

- explain clearly why the new problem is not "just run Dinic for every pair"

## Core

- cut tree on the same vertex set
- `n - 1` max-flow calls
- residual reachable side drives reparenting
- exact starter route: [`gomory-hu-tree.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/gomory-hu-tree.cpp)
- flagship solved rep: [MCQUERY](mcquery.md)

Target skill:

- turn "many pairwise min cuts" into "build one weighted tree, then solve a tree problem"

## Stretch

- [Library Checker - Gomory-Hu Tree](https://judge.yosupo.jp/problem/gomory_hu_tree)
- [Pumping Stations](https://codeforces.com/problemset/problem/343/E)
- [All Pairs Maximum Flow](https://onlinejudge.org/external/115/11594.pdf)

Target skill:

- know when the exact starter still fits and when the real difficulty has moved into the query layer after the tree is built

## Retrieval Layer

- exact quick sheet -> [Gomory-Hu hot sheet](../../../../notebook/gomory-hu-hot-sheet.md)
- prerequisite cut engine -> [Flow hot sheet](../../../../notebook/flow-hot-sheet.md)
- exact starter -> [`gomory-hu-tree.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/gomory-hu-tree.cpp)
- DSU compare point for the first flagship aggregation -> [DSU hot sheet](../../../../notebook/dsu-hot-sheet.md)
- graph-family chooser -> [Graph cheatsheet](../../../../notebook/graph-cheatsheet.md)

## Repo Anchors And Compare Points

- topic page -> [Gomory-Hu Tree](../../../../topics/graphs/gomory-hu/README.md)
- flagship note -> [MCQUERY](mcquery.md)
- one-cut compare point -> [Maximum Flow](../../../../topics/graphs/flow/README.md)
- cut-family neighbor -> [Flow With Lower Bounds](../../../../topics/graphs/flow-lower-bounds/README.md)
- broader routing -> [Graphs ladder](../README.md)

## Exit Criteria

You are ready to move on when:

- you can say why the graph must be undirected
- you understand why `n - 1` cuts are enough
- you can explain why residual reachability after max flow changes the parent structure
- you can reduce one pairwise-cut aggregation problem to tree edges plus one second structure

## External Practice

- [Library Checker - Gomory-Hu Tree](https://judge.yosupo.jp/problem/gomory_hu_tree)
- [Pumping Stations](https://codeforces.com/problemset/problem/343/E)
- [All Pairs Maximum Flow](https://onlinejudge.org/external/115/11594.pdf)

## Tutorial Link

- [Gomory-Hu Tree](../../../../topics/graphs/gomory-hu/README.md)
