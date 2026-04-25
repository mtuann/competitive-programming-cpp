# Shortest Paths Ladder

This ladder is about learning to choose the shortest-path algorithm from the edge model instead of memorizing Dijkstra as a default hammer.

Current repo shape: the unweighted branch has a cleaner internal anchor than the weighted branch. Treat this lane as `topic + template backed`, with [QOS](qos.md) as the weighted compare point rather than the first weighted warm-up.

## Who This Is For

Use this ladder if:

- weighted vs unweighted modeling still causes hesitation
- you know Dijkstra, but not when BFS or 0-1 BFS is cleaner
- path restoration and stale-entry handling still feel fragile

## Warm-Up

- BFS on an unweighted graph
- shortest path restoration with parents
- compare BFS against Dijkstra on the same model

Target skill:

- choose the lightest valid shortest-path method

## Core

- Dijkstra with nonnegative weights
- reverse shortest paths
- choose between BFS, 0-1 BFS, and Dijkstra

Target skill:

- reason from weight model first, implementation second

## Stretch

- bounded-near-shortest reconstruction
- [QOS - Chất lượng dịch vụ](qos.md)

Target skill:

- use shortest paths as a base layer for richer reconstruction or DP problems

## Repo Anchors And Compare Points

- unweighted shortest path anchor -> [Message Route](../bfs-dfs/messageroute.md)
- weighted reconstruction anchor -> [QOS](qos.md)
- modeling support -> [Graph Modeling](../../../../topics/graphs/graph-modeling/README.md)
- family chooser -> [Shortest Paths](../../../../topics/graphs/shortest-paths/README.md)

Use this ladder in two passes:

1. learn the family chooser from [Shortest Paths](../../../../topics/graphs/shortest-paths/README.md), then stabilize the unweighted baseline through [Message Route](../bfs-dfs/messageroute.md)
2. use [QOS](qos.md) as the weighted compare point after the family choice already feels plausible

## Retrieval Layer

- unit edges -> [bfs.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bfs.cpp)
- `0/1` edges -> [zero-one-bfs.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/zero-one-bfs.cpp)
- nonnegative weights -> [dijkstra.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dijkstra.cpp)
- negative edges -> [bellman-ford.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bellman-ford.cpp)
- quick reminder sheet -> [Shortest Paths hot sheet](../../../../notebook/shortest-paths-hot-sheet.md)

There is still only one direct weighted repo note in this ladder, so if the family feels thin do **not** browse randomly. Reopen:

- [Message Route](../bfs-dfs/messageroute.md) for the unweighted baseline
- [QOS](qos.md) for weighted reconstruction after the topic page has already framed the right algorithm
- [Shortest Paths](../../../../topics/graphs/shortest-paths/README.md) for the full chooser

## Exit Criteria

You are ready to move on when:

- you never use Dijkstra on negative edges
- you can explain stale heap entries and skip them confidently
- you know when reverse-graph shortest paths simplify the problem

## External Practice

- [CSES Graph Algorithms](https://cses.fi/problemset/)
- [CP-Algorithms - Dijkstra](https://cp-algorithms.com/graph/dijkstra.html)
- [CP-Algorithms - 0-1 BFS](https://cp-algorithms.com/graph/01_bfs.html)

## Tutorial Link

- [Shortest Paths](../../../../topics/graphs/shortest-paths/README.md)
