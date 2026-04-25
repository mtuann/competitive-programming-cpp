# Graph Cheatsheet

Use this page when the graph model is mostly clear but the algorithm family still feels ambiguous.

## Do Not Use When

- the graph model itself is still unclear
- the task is really a tree DP, flow modeling, or DSU structure question, not a generic graph-family choice
- you need proofs or full algorithm derivations more than a chooser

## Choose By Edge Model

- unweighted shortest path -> BFS -> [Shortest Paths hot sheet](shortest-paths-hot-sheet.md)
- trusted topological order on a DAG -> [Shortest Paths hot sheet](shortest-paths-hot-sheet.md)
- `0/1` weights -> `0-1 BFS` -> [Shortest Paths hot sheet](shortest-paths-hot-sheet.md)
- nonnegative weights -> Dijkstra -> [Shortest Paths hot sheet](shortest-paths-hot-sheet.md)
- negative edges -> Bellman-Ford -> [Shortest Paths hot sheet](shortest-paths-hot-sheet.md)

## Core Families

- connectivity / traversal -> BFS, DFS
- DAG dependencies -> toposort
- undirected cheapest backbone -> MST
- directed compression -> SCC
- tree path queries -> LCA or [HLD hot sheet](hld-hot-sheet.md)
- capacities -> [Flow hot sheet](flow-hot-sheet.md)
- pairing -> [Matching hot sheet](matching-hot-sheet.md)

## Core Invariants

- BFS: first visit gives minimum number of edges in an unweighted graph
- Dijkstra: settled distances stay optimal when all edge weights are nonnegative
- `0-1 BFS`: deque order stays nondecreasing by distance
- Bellman-Ford: one more relaxation after `n - 1` rounds signals a reachable negative cycle

## Retrieval Cues

- "fewest edges" or "minimum moves" -> start from BFS
- "weights are only 0 and 1" -> do not jump to Dijkstra first
- "negative edge" or "check for negative cycle" -> Bellman-Ford family
- "tree paths" -> LCA for ancestor/meet questions, HLD for repeated path aggregates, Euler flattening for subtree-only aggregation
- "same component after many merges" -> maybe DSU, not BFS/DFS

## Invariants To Keep In Mind

- shortest-path code only updates `parent[v]` when `dist[v]` improves
- heap Dijkstra must skip stale entries
- `0-1 BFS` keeps deque order nondecreasing by distance
- Bellman-Ford only gives a valid shortest-path answer when no reachable negative cycle keeps improving the target

## Quick Anchors In This Repo

- shortest-path family -> [Shortest Paths hot sheet](shortest-paths-hot-sheet.md) + [Message Route](../practice/ladders/graphs/bfs-dfs/messageroute.md) + [QOS](../practice/ladders/graphs/shortest-paths/qos.md)
- MST -> [Road Reparation](../practice/ladders/graphs/mst/roadreparation.md)
- SCC / DAG ordering -> [Course Schedule](../practice/ladders/graphs/scc-toposort/courseschedule.md)
- tree path decomposition -> [Heavy-Light Decomposition](../topics/graphs/hld/README.md) + [Path Queries II](../practice/ladders/graphs/hld/pathqueries2.md) + [hld-path-max.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hld-path-max.cpp)
- HLD retrieval route -> [HLD hot sheet](hld-hot-sheet.md)
- flow / cuts -> [Flow hot sheet](flow-hot-sheet.md) + [Police Chase](../practice/ladders/graphs/flow/policechase.md)
- matching / bipartite pairing -> [Matching hot sheet](matching-hot-sheet.md)
- general-matching / edge-cover boundary compare point -> [QBFLOWER](../practice/ladders/graphs/matching/qbflower.md)

## Next Stops

- [Shortest Paths topic](../topics/graphs/shortest-paths/README.md)
- [Graphs ladder](../practice/ladders/graphs/README.md)
- [Shortest Paths hot sheet](shortest-paths-hot-sheet.md)
- [HLD hot sheet](hld-hot-sheet.md)
- [Flow hot sheet](flow-hot-sheet.md)
- [Matching hot sheet](matching-hot-sheet.md)
- [Template library](../template-library.md)
- [Flow topic](../topics/graphs/flow/README.md)
- [LCA topic](../topics/graphs/lca/README.md)
