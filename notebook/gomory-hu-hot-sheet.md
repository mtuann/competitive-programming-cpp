# Gomory-Hu Hot Sheet

Use this page when the graph is undirected, the expensive part is repeated min-cut work, and the right compression is "build one cut tree first."

## Do Not Use When

- only one source-sink cut matters -> [Flow hot sheet](flow-hot-sheet.md)
- the graph is directed
- the task is lower-bounded circulation or min-cost transport, not repeated min cuts
- the graph changes online

## Choose By Signal

- one `s-t` max flow / min cut certificate -> [Flow hot sheet](flow-hot-sheet.md)
- many pairwise min-cuts on one undirected graph -> gomory-hu tree -> [`gomory-hu-tree.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/gomory-hu-tree.cpp)
- all-pairs threshold counting after one cut-tree build -> [MCQUERY](../practice/ladders/graphs/gomory-hu/mcquery.md)
- tree path minima after cut compression -> build the GH tree first, then layer one tree-query structure

## Core Invariants

- the cut tree uses the same vertex set as the original graph
- each iteration solves one `s-parent[s]` min cut
- residual reachability from `s` after max flow tells which vertices are reparented under `s`
- after build, `minCut(u, v)` equals the minimum edge weight on the unique tree path `u -> v`
- zero-weight tree edges naturally represent disconnected cut value `0`

## Main Traps

- trying to use GH on a directed graph
- forgetting that each undirected edge still needs both directed residual arcs in the flow engine
- reading the wrong residual side after max flow
- summing tree edge weights instead of taking the path minimum
- overclaiming that the exact repo starter already solves fast path-min queries by itself

## Exact Starter Route

- exact starter -> [`gomory-hu-tree.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/gomory-hu-tree.cpp)
- flagship solved rep -> [MCQUERY](../practice/ladders/graphs/gomory-hu/mcquery.md)
- prerequisite engine -> [Flow hot sheet](flow-hot-sheet.md)
- query-layer compare point -> [DSU hot sheet](dsu-hot-sheet.md)

## Reopen Paths

- full lesson -> [Gomory-Hu Tree](../topics/graphs/gomory-hu/README.md)
- underlying cut primitive -> [Maximum Flow](../topics/graphs/flow/README.md)
- threshold counting rep -> [MCQUERY](../practice/ladders/graphs/gomory-hu/mcquery.md)
- graph-family chooser -> [Graph cheatsheet](graph-cheatsheet.md)
- snippet chooser -> [Template Library](../template-library.md)
