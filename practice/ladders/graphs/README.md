# Graph Ladders

These ladders follow the graph teaching spine from modeling to standard algorithms.

## Recommended Order

1. graph modeling
2. BFS / DFS
3. shortest paths
4. minimum spanning tree
5. toposort and SCC
6. bridges / articulation / low-link on undirected graphs
7. Eulerian path / cycle once "use every edge exactly once" becomes a repeated pattern
8. 2-SAT once implication graphs and SCCs feel natural
9. trees and subtree flattening
10. LCA
11. virtual tree when each query only marks a small subset of vertices but the union of marked paths still matters
12. heavy-light decomposition when path queries need a range structure
13. centroid decomposition when balanced recursive splits become the main tool
14. link-cut tree when the tree topology itself changes online
15. Euler tour tree when the topology changes online but the live query is still subtree-side
16. flow and matching

## Subtopic Ladders

- [Graph modeling](graph-modeling/README.md)
- [BFS / DFS](bfs-dfs/README.md)
- [Bridges / articulation / BCC](bridges-articulation/README.md)
- [Eulerian path / cycle](eulerian-path-cycle/README.md)
- [Shortest paths](shortest-paths/README.md)
- [Minimum spanning tree](mst/README.md)
- [Toposort and SCC](scc-toposort/README.md)
- [Two-SAT](two-sat/README.md)
- [Trees](trees/README.md)
- [Euler Tour / Subtree Queries](euler-tour-subtree/README.md)
- [LCA](lca/README.md)
- [Virtual Tree / Auxiliary Tree](virtual-tree/README.md)
- [Heavy-light decomposition](hld/README.md)
- [Centroid decomposition](centroid-decomposition/README.md)
- [Link-cut tree](link-cut-tree/README.md)
- [Euler tour tree](euler-tour-tree/README.md)
- [Flow](flow/README.md)
- [Matching](matching/README.md)
- [Tree DP notes](tree-dp/README.md)

## Representative Solved Notes

- [Counting Rooms](graph-modeling/countingrooms.md)
- [Building Roads](graph-modeling/buildingroads.md)
- [Necessary Roads](bridges-articulation/necessaryroads.md)
- [Mail Delivery](eulerian-path-cycle/maildelivery.md)
- [QOS](shortest-paths/qos.md)
- [Giant Pizza](two-sat/giantpizza.md)
- [Subtree Queries](euler-tour-subtree/subtreequeries.md)
- [Kingdom and its Cities](virtual-tree/kingdomanditscities.md)
- [Ciel the Commander](centroid-decomposition/cielthecommander.md)
- [Dynamic Tree Vertex Add Path Sum](link-cut-tree/dynamictreevertexaddpathsum.md)
- [Dynamic Tree Vertex Add Subtree Sum](euler-tour-tree/dynamictreevertexaddsubtreesum.md)
- [FFLOW](flow/fflow.md)
- [MINCOST](flow/mincost.md)
- [Path Queries II](hld/pathqueries2.md)
- [QBFLOWER](matching/qbflower.md)
- [VOSTRIP](tree-dp/vostrip.md)
