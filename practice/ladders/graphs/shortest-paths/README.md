# Shortest Paths Ladder

This ladder is about learning to choose the shortest-path algorithm from the edge model instead of memorizing Dijkstra as a default hammer.

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
