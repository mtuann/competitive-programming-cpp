# Graph Cheatsheet

Use this page when the graph model is mostly clear but the algorithm family still feels ambiguous.

## Do Not Use When

- the graph model itself is still unclear
- the task is really a tree DP, flow modeling, or DSU structure question, not a generic graph-family choice
- you need proofs or full algorithm derivations more than a chooser

## Choose By Edge Model

- unweighted shortest path -> BFS -> [bfs.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bfs.cpp)
- `0/1` weights -> `0-1 BFS` -> [zero-one-bfs.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/zero-one-bfs.cpp)
- nonnegative weights -> Dijkstra -> [dijkstra.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dijkstra.cpp)
- negative edges -> Bellman-Ford -> [bellman-ford.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bellman-ford.cpp)

## Core Families

- connectivity / traversal -> BFS, DFS
- DAG dependencies -> toposort
- undirected cheapest backbone -> MST
- directed compression -> SCC
- tree path queries -> LCA or HLD
- capacities -> flow
- pairing -> matching

## Core Invariants

- BFS: first visit gives minimum number of edges in an unweighted graph
- Dijkstra: settled distances stay optimal when all edge weights are nonnegative
- `0-1 BFS`: deque order stays nondecreasing by distance
- Bellman-Ford: one more relaxation after `n - 1` rounds signals a reachable negative cycle

## Retrieval Cues

- "fewest edges" or "minimum moves" -> start from BFS
- "weights are only 0 and 1" -> do not jump to Dijkstra first
- "negative edge" or "check for negative cycle" -> Bellman-Ford family
- "queries on tree paths" -> LCA if static, HLD if the path also needs updates or aggregates

## Invariants To Keep In Mind

- shortest-path code only updates `parent[v]` when `dist[v]` improves
- heap Dijkstra must skip stale entries
- `0-1 BFS` keeps deque order nondecreasing by distance
- Bellman-Ford only gives a valid shortest-path answer when no reachable negative cycle keeps improving the target

## Quick Anchors In This Repo

- unweighted shortest path -> [Message Route](../practice/ladders/graphs/bfs-dfs/messageroute.md)
- weighted shortest path / reconstruction -> [QOS](../practice/ladders/graphs/shortest-paths/qos.md)
- MST -> [Road Reparation](../practice/ladders/graphs/mst/roadreparation.md)
- SCC / DAG ordering -> [Course Schedule](../practice/ladders/graphs/scc-toposort/courseschedule.md)
- tree path decomposition -> [Heavy-Light Decomposition](../topics/graphs/hld/README.md) + [Path Queries II](../practice/ladders/graphs/hld/pathqueries2.md) + [hld-path-max.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hld-path-max.cpp)

## Next Stops

- [Shortest Paths topic](../topics/graphs/shortest-paths/README.md)
- [Graphs ladder](../practice/ladders/graphs/README.md)
- [Template library](../template-library.md)
- [Flow topic](../topics/graphs/flow/README.md)
- [LCA topic](../topics/graphs/lca/README.md)
