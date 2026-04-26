# Graphs

Graphs are one of the central contest areas because many problems are really about states and transitions in disguise. This section should teach graph modeling first, then standard algorithms, then deeper tree, cut, and matching ideas.

## Subtopics

- [Graph Modeling](graph-modeling/README.md)
- [BFS And DFS](bfs-dfs/README.md)
- [Bridges, Articulation Points, And Biconnected Components](bridges-articulation/README.md)
- [Eulerian Path / Cycle](eulerian-path-cycle/README.md)
- [De Bruijn Sequence](de-bruijn-sequence/README.md)
- [Shortest Paths](shortest-paths/README.md)
- [Minimum Spanning Tree](mst/README.md)
- [Topological Sort And SCC](scc-toposort/README.md)
- [2-SAT](two-sat/README.md)
- [Trees](trees/README.md)
- [Tree Isomorphism](tree-isomorphism/README.md)
- [Euler Tour / Subtree Queries](euler-tour-subtree/README.md)
- [LCA](lca/README.md)
- [Virtual Tree / Auxiliary Tree](virtual-tree/README.md)
- [Heavy-Light Decomposition](hld/README.md)
- [Centroid Decomposition](centroid-decomposition/README.md)
- [Link-Cut Tree](link-cut-tree/README.md)
- [Euler Tour Tree](euler-tour-tree/README.md)
- [Maximum Flow](flow/README.md)
- [Randomized / Global Min-Cut](global-min-cut/README.md)
- [Gomory-Hu Tree](gomory-hu/README.md)
- [Flow With Lower Bounds](flow-lower-bounds/README.md)
- [Min-Cost Flow](min-cost-flow/README.md)
- [Matching](matching/README.md)
- [Stable Marriage](stable-marriage/README.md)
- [Hungarian / Assignment Problem](hungarian-assignment/README.md)
- [Edmonds Blossom / General Matching](general-matching/README.md)

## Entry

- Prereqs: [Foundations](../foundations/README.md), [Data Structures](../data-structures/README.md)
- Defer for later: flow, matching, and advanced tree decompositions

## Learn In Order

1. Core now
- graph modeling
- BFS / DFS
- topological sort
- MST with DSU
- shortest paths

2. Contest core
- SCC
- bridges, articulation points, and low-link structure
- Eulerian path / cycle when edge-exhaustion walks start repeating
- de Bruijn modeling when the hard part is hiding an Eulerian cycle inside an overlap-string construction
- 2-SAT once SCC condensation is comfortable
- trees, tree-isomorphism canonicalization, subtree flattening, LCA, virtual-tree compression on marked subsets, and rerooting-style thinking

3. Advanced later
- heavy-light, centroid decomposition, and dynamic-tree machinery such as link-cut trees and Euler tour trees
- flow, global cut structure, cut-tree compression via Gomory-Hu, lower-bounded circulation, and min-cost flow
- matching, stable-preference pairing, weighted assignment, and general non-bipartite pairing

## Recognition Cues

- the problem has objects connected by edges, dependencies, or transitions
- you are asked about connectivity, reachability, shortest routes, cuts, or tree structure
- the story sounds unrelated, but the clean model is still vertices plus edges

## Common Pitfalls

- spending too long on the story instead of drawing the graph
- using weighted shortest-path machinery when BFS is enough
- treating all graph topics as flat difficulty instead of learning them in layers

## Exit Criteria

After this section, you should be able to recognize the common graph models, choose the standard algorithm family quickly, and explain why a chosen graph representation is the right one.

## Solved Examples In This Repo

- [Counting Rooms](../../practice/ladders/graphs/graph-modeling/countingrooms.md): grid cells become vertices, and rooms become connected components
- [Building Roads](../../practice/ladders/graphs/graph-modeling/buildingroads.md): component representatives turn a connectivity repair task into a clean constructive graph solution
- [Necessary Roads](../../practice/ladders/graphs/bridges-articulation/necessaryroads.md): low-link bridge detection and critical-edge reasoning
- [Mail Delivery](../../practice/ladders/graphs/eulerian-path-cycle/maildelivery.md): undirected Eulerian cycle via degree parity and iterative Hierholzer
- [De Bruijn Sequence](../../practice/ladders/graphs/de-bruijn-sequence/debruijnsequence.md): overlap-state graph modeling turned into one Eulerian-cycle construction
- [QOS - Chất lượng dịch vụ](../../practice/ladders/graphs/shortest-paths/qos.md): shortest paths plus lexicographic constrained reconstruction
- [Giant Pizza](../../practice/ladders/graphs/two-sat/giantpizza.md): binary clause modeling and SCC-based assignment extraction
- [Tree Isomorphism I](../../practice/ladders/graphs/tree-isomorphism/treeisomorphism1.md): rooted unordered tree comparison by bottom-up canonical subtree types
- [Subtree Queries](../../practice/ladders/graphs/euler-tour-subtree/subtreequeries.md): subtree intervals reduced to one Fenwick-backed range query
- [Kingdom and its Cities](../../practice/ladders/graphs/virtual-tree/kingdomanditscities.md): marked-subset compression via LCAs before a query-local tree DP
- [Ciel the Commander](../../practice/ladders/graphs/centroid-decomposition/cielthecommander.md): build the centroid tree itself and use centroid depth as the answer
- [Dynamic Tree Vertex Add Path Sum](../../practice/ladders/graphs/link-cut-tree/dynamictreevertexaddpathsum.md): online `link / cut` plus vertex-add path-sum queries on one changing forest
- [Dynamic Tree Vertex Add Subtree Sum](../../practice/ladders/graphs/euler-tour-tree/dynamictreevertexaddsubtreesum.md): online `link / cut` plus subtree-side sums via a dynamic Euler-tour sequence
- [FFLOW - Fast Maximum Flow](../../practice/ladders/graphs/flow/fflow.md): max-flow implementation and judge-facing performance engineering
- [Minimum Cut](../../practice/ladders/graphs/global-min-cut/globalmincut.md): one undirected weighted graph with no designated `s-t`, solved by Stoer-Wagner phase cuts
- [MCQUERY](../../practice/ladders/graphs/gomory-hu/mcquery.md): compress all pairwise undirected min-cuts into one cut tree, then count pairs by threshold
- [Reactor Cooling](../../practice/ladders/graphs/flow/reactorcooling.md): feasible circulation under lower and upper edge bounds
- [MINCOST - Luồng với chi phí nhỏ nhất](../../practice/ladders/graphs/flow/mincost.md): min-cost flow with judge-specific duplicate-edge handling
- [QBFLOWER - Tặng hoa](../../practice/ladders/graphs/matching/qbflower.md): general matching and edge-cover modeling
- [Stable Marriage](../../practice/ladders/graphs/stable-marriage/stablemarriage.md): canonical Gale-Shapley deferred acceptance under full strict preferences
- [Task Assignment](../../practice/ladders/graphs/hungarian-assignment/taskassignment.md): dense square weighted assignment with one optimal employee-task matching
- [General Matching](../../practice/ladders/graphs/general-matching/generalmatching.md): blossom shrinking for one maximum-cardinality matching in a non-bipartite graph
- [VOSTRIP - VOSTRIP](../../practice/ladders/graphs/tree-dp/vostrip.md): tree usage aggregation and endpoint accounting
- [PATHQUERIES2 - Path Queries II](../../practice/ladders/graphs/hld/pathqueries2.md): heavy-light decomposition for point updates and path maximum

## Go Deeper

- Course: [Stanford CS161](https://cs161-stanford.github.io)
- Course: [Cornell CS 4820](https://www.cs.cornell.edu/courses/cs4820/2025sp/syllabus/)
- Reference: [CP-Algorithms](https://cp-algorithms.com/)
- Practice: [ICPC Curriculum](https://curriculum.u.icpc.global/curriculum/)
