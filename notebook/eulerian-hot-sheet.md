# Eulerian Path / Cycle Hot Sheet

Use this page when the statement wants one walk that uses every edge exactly once and you want the shortest route back to the right feasibility checks plus `Hierholzer`.

## Do Not Use When

- the task is subtree flattening or rooted-tree interval logic
- vertices, not edges, are the things that must be visited once
- the real target is shortest path, not all-edge traversal
- the graph changes online

## Choose By Signal

- undirected graph, closed walk through every edge -> all non-isolated degrees even -> [`eulerian-path-cycle.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/eulerian-path-cycle.cpp)
- undirected graph, open walk through every edge -> exactly two odd-degree vertices -> [`eulerian-path-cycle.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/eulerian-path-cycle.cpp)
- directed graph, use every edge once from fixed source to fixed sink -> `out-in` balance plus `Hierholzer` -> reopen [Eulerian Path / Cycle](../topics/graphs/eulerian-path-cycle/README.md)
- string reconstruction from overlaps -> build a de Bruijn graph first, then reopen [Eulerian Path / Cycle](../topics/graphs/eulerian-path-cycle/README.md)

## Core Invariants

- undirected cycle: every non-isolated vertex has even degree
- undirected path: exactly two odd-degree vertices
- directed cycle: `in[v] = out[v]` for every used vertex
- directed path: one start with `out = in + 1`, one end with `in = out + 1`, all others balanced
- `Hierholzer`: pop a vertex into the answer only when it has no unused incident / outgoing edge left
- final guard: valid answer must have length `m + 1`

## Main Traps

- degree checks pass, but one edge-component is disconnected from the chosen start
- forgetting that isolated vertices do not matter, but disconnected used-edge components do
- confusing this lane with [Euler Tour / Subtree Queries](../topics/graphs/euler-tour-subtree/README.md)
- using one visited-vertex array instead of edge ids, so multiedges break

## Exact Starters In This Repo

- exact starter for directed + undirected trails -> [`eulerian-path-cycle.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/eulerian-path-cycle.cpp)
- flagship in-lane rep -> [Mail Delivery](../practice/ladders/graphs/eulerian-path-cycle/maildelivery.md)
- name-clash compare point -> [Euler Tour / Subtree Queries](../topics/graphs/euler-tour-subtree/README.md)
- graph-family chooser -> [Graph cheatsheet](graph-cheatsheet.md)

## Reopen Paths

- full feasibility split and `Hierholzer` proof -> [Eulerian Path / Cycle](../topics/graphs/eulerian-path-cycle/README.md)
- if the graph model itself is still fuzzy -> [Graph Modeling](../topics/graphs/graph-modeling/README.md)
- if the statement is subtree-only and you only got baited by the word `Euler` -> [Subtree Queries hot sheet](subtree-queries-hot-sheet.md)
- practice lane -> [Eulerian Path / Cycle ladder](../practice/ladders/graphs/eulerian-path-cycle/README.md)
