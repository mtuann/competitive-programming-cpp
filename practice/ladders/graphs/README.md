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
8. de Bruijn sequence once overlap-string constructions clearly reduce to hidden Eulerian cycles
9. 2-SAT once implication graphs and SCCs feel natural
10. trees and subtree flattening
11. tree isomorphism when unordered rooted shape itself becomes the task
12. LCA
13. virtual tree when each query only marks a small subset of vertices but the union of marked paths still matters
14. heavy-light decomposition when path queries need a range structure
15. centroid decomposition when balanced recursive splits become the main tool
16. link-cut tree when the tree topology itself changes online
17. Euler tour tree when the topology changes online but the live query is still subtree-side
18. flow
19. global min-cut when one undirected weighted graph has no designated `s-t` and you only want the cheapest disconnection cut
20. Gomory-Hu once many undirected min-cuts must be compressed into one tree
21. stable marriage once one-to-one pairing is about blocking pairs under strict preferences, not size or cost
22. weighted assignment once one-to-one pairing is no longer only about cardinality
23. general matching once odd cycles kill the bipartite-first route

## Subtopic Ladders

- [Graph modeling](graph-modeling/README.md)
- [BFS / DFS](bfs-dfs/README.md)
- [Bridges / articulation / BCC](bridges-articulation/README.md)
- [Eulerian path / cycle](eulerian-path-cycle/README.md)
- [De Bruijn Sequence](de-bruijn-sequence/README.md)
- [Shortest paths](shortest-paths/README.md)
- [Minimum spanning tree](mst/README.md)
- [Toposort and SCC](scc-toposort/README.md)
- [Two-SAT](two-sat/README.md)
- [Trees](trees/README.md)
- [Tree Isomorphism](tree-isomorphism/README.md)
- [Euler Tour / Subtree Queries](euler-tour-subtree/README.md)
- [LCA](lca/README.md)
- [Virtual Tree / Auxiliary Tree](virtual-tree/README.md)
- [Heavy-light decomposition](hld/README.md)
- [Centroid decomposition](centroid-decomposition/README.md)
- [Link-cut tree](link-cut-tree/README.md)
- [Euler tour tree](euler-tour-tree/README.md)
- [Flow](flow/README.md)
- [Randomized / Global Min-Cut](global-min-cut/README.md)
- [Gomory-Hu tree](gomory-hu/README.md)
- [Matching](matching/README.md)
- [Stable Marriage](stable-marriage/README.md)
- [Hungarian / Assignment Problem](hungarian-assignment/README.md)
- [Edmonds Blossom / General Matching](general-matching/README.md)
- [Tree DP notes](tree-dp/README.md)

## Representative Solved Notes

- [Counting Rooms](graph-modeling/countingrooms.md)
- [Building Roads](graph-modeling/buildingroads.md)
- [Necessary Roads](bridges-articulation/necessaryroads.md)
- [Mail Delivery](eulerian-path-cycle/maildelivery.md)
- [De Bruijn Sequence](de-bruijn-sequence/debruijnsequence.md)
- [QOS](shortest-paths/qos.md)
- [Giant Pizza](two-sat/giantpizza.md)
- [Tree Isomorphism I](tree-isomorphism/treeisomorphism1.md)
- [Subtree Queries](euler-tour-subtree/subtreequeries.md)
- [Kingdom and its Cities](virtual-tree/kingdomanditscities.md)
- [Ciel the Commander](centroid-decomposition/cielthecommander.md)
- [Dynamic Tree Vertex Add Path Sum](link-cut-tree/dynamictreevertexaddpathsum.md)
- [Dynamic Tree Vertex Add Subtree Sum](euler-tour-tree/dynamictreevertexaddsubtreesum.md)
- [FFLOW](flow/fflow.md)
- [Minimum Cut](global-min-cut/globalmincut.md)
- [MCQUERY](gomory-hu/mcquery.md)
- [MINCOST](flow/mincost.md)
- [Path Queries II](hld/pathqueries2.md)
- [QBFLOWER](matching/qbflower.md)
- [Stable Marriage](stable-marriage/stablemarriage.md)
- [Task Assignment](hungarian-assignment/taskassignment.md)
- [General Matching](general-matching/generalmatching.md)
- [VOSTRIP](tree-dp/vostrip.md)
