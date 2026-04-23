# Graph Cheatsheet

## Choose By Edge Model

- unweighted shortest path: BFS
- `0/1` weights: `0-1 BFS`
- nonnegative weights: Dijkstra
- negative edges: Bellman-Ford if needed

## Core Families

- connectivity / traversal: BFS, DFS
- DAG dependencies: toposort
- undirected cheapest backbone: MST
- directed compression: SCC
- tree path queries: LCA
- capacities: flow
- pairing: matching
