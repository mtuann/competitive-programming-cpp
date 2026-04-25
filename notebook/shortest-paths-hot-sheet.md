# Shortest Paths Hot Sheet

Use this page when the graph model is already clear and the remaining question is which shortest-path family actually matches the edge model.

## Do Not Use When

- the graph model itself is still the hard part
- the task is really flow, matching, or tree-path decomposition
- you need a slower proof page more than a chooser

## Choose By Signal

- fewest edges / minimum moves / unit weights -> [`bfs.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bfs.cpp)
- DAG with a trusted topological order -> DAG relaxation, not Dijkstra
- only `0/1` weights -> [`zero-one-bfs.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/zero-one-bfs.cpp)
- nonnegative weights -> [`dijkstra.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dijkstra.cpp)
- negative edges or negative-cycle witness questions -> [`bellman-ford.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bellman-ford.cpp)
- dense small-`n` all-pairs -> [`floyd-warshall.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/floyd-warshall.cpp)

## Core Invariants

- BFS: the first visit gives the minimum number of edges
- DAG relaxation: topological order means every predecessor is final before the node is processed
- Dijkstra: once a node is settled, its distance is final if all edge weights are nonnegative
- `0-1 BFS`: deque order stays nondecreasing by distance
- Bellman-Ford: after `k` full rounds, all paths using at most `k` edges are accounted for

## Main Traps

- using Dijkstra on graphs with negative edges
- forgetting stale-entry skips in heap Dijkstra
- treating `0/1` weights as “close enough” to ordinary weighted graphs and missing the deque win
- mixing unreachable `INF` handling with real distances during reconstruction

## Exact Starters In This Repo

- unweighted shortest path -> [`bfs.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bfs.cpp)
- `0/1` edge costs -> [`zero-one-bfs.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/zero-one-bfs.cpp)
- nonnegative weighted graph -> [`dijkstra.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dijkstra.cpp)
- negative edges / cycle detection -> [`bellman-ford.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bellman-ford.cpp)
- all-pairs on small dense graphs -> [`floyd-warshall.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/floyd-warshall.cpp)

## Repo Anchors

- unweighted baseline -> [Message Route](../practice/ladders/graphs/bfs-dfs/messageroute.md)
- weighted path reconstruction and extra state -> [QOS](../practice/ladders/graphs/shortest-paths/qos.md)
- family router -> [Shortest Paths ladder](../practice/ladders/graphs/shortest-paths/README.md)

## Reopen Paths

- proofs, DAG branch, and family boundaries -> [Shortest Paths](../topics/graphs/shortest-paths/README.md)
- broader graph family chooser -> [Graph cheatsheet](graph-cheatsheet.md)
- snippet map -> [Template Library](../template-library.md)
