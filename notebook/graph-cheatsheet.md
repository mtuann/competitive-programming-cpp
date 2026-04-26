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
- delete one edge/vertex and connectivity changes -> [Low-Link hot sheet](lowlink-hot-sheet.md)
- use every edge exactly once -> [Eulerian hot sheet](eulerian-hot-sheet.md)
- connectivity under offline add/remove edge events -> [DSU Rollback hot sheet](dsu-rollback-hot-sheet.md)
- binary clauses over boolean choices -> [Two-SAT hot sheet](two-sat-hot-sheet.md)
- two rooted trees must match up to child permutation, or one unrooted comparison reduces to one or two center roots -> [Tree Isomorphism hot sheet](tree-isomorphism-hot-sheet.md)
- one rooted subtree aggregate becomes one contiguous interval -> [Subtree Queries hot sheet](subtree-queries-hot-sheet.md)
- one query marks only a small subset of vertices but still needs the union of their paths -> [Virtual Tree hot sheet](virtual-tree-hot-sheet.md)
- static tree problem split by one balanced pivot or `O(log n)` centroid ancestors -> [Centroid hot sheet](centroid-hot-sheet.md)
- tree topology changes online but path queries still survive -> [Link-Cut Tree hot sheet](link-cut-tree-hot-sheet.md)
- tree topology changes online but the live query is one subtree side of an existing edge -> [Euler Tour Tree hot sheet](euler-tour-tree-hot-sheet.md)
- one undirected weighted graph has no designated `s-t`, and you only need the cheapest disconnection cut -> [Global Min-Cut hot sheet](global-min-cut-hot-sheet.md)
- one undirected weighted graph needs many pairwise min-cuts -> [Gomory-Hu hot sheet](gomory-hu-hot-sheet.md)
- edge lower / upper bounds with conservation at every node -> [Flow With Lower Bounds hot sheet](flow-lower-bounds-hot-sheet.md)
- two equal-sized sides with full strict preference lists and a no-blocking-pair objective -> [Stable Marriage hot sheet](stable-marriage-hot-sheet.md)
- one dense square cost matrix with exact one-to-one pairing -> [Hungarian hot sheet](hungarian-hot-sheet.md)
- one undirected graph with odd cycles where the objective is still maximum matching size -> [General Matching hot sheet](general-matching-hot-sheet.md)

## Core Families

- connectivity / traversal -> BFS, DFS
- critical roads / cities -> [Low-Link hot sheet](lowlink-hot-sheet.md)
- use-every-edge-once walks -> [Eulerian hot sheet](eulerian-hot-sheet.md)
- DAG dependencies -> toposort
- undirected cheapest backbone -> MST
- directed compression -> SCC
- binary clause feasibility -> [Two-SAT hot sheet](two-sat-hot-sheet.md)
- rooted unordered tree shape comparison -> [Tree Isomorphism hot sheet](tree-isomorphism-hot-sheet.md)
- subtree-only rooted-tree aggregation -> [Subtree Queries hot sheet](subtree-queries-hot-sheet.md)
- marked-subset compression on one static rooted tree -> [Virtual Tree hot sheet](virtual-tree-hot-sheet.md)
- tree path queries -> LCA or [HLD hot sheet](hld-hot-sheet.md)
- balanced recursive tree splits / centroid ancestors -> [Centroid hot sheet](centroid-hot-sheet.md)
- dynamic-tree path queries / connectivity under online `link` and `cut` -> [Link-Cut Tree hot sheet](link-cut-tree-hot-sheet.md)
- dynamic-tree subtree-side queries under online `link` and `cut` -> [Euler Tour Tree hot sheet](euler-tour-tree-hot-sheet.md)
- capacities -> [Flow hot sheet](flow-hot-sheet.md)
- one global undirected cut with no designated pair -> [Global Min-Cut hot sheet](global-min-cut-hot-sheet.md)
- all-pairs min-cut compression on one undirected graph -> [Gomory-Hu hot sheet](gomory-hu-hot-sheet.md)
- lower-bounded circulation / mandatory edge throughput -> [Flow With Lower Bounds hot sheet](flow-lower-bounds-hot-sheet.md)
- pairing -> [Matching hot sheet](matching-hot-sheet.md)
- stable one-to-one pairing under strict preferences -> [Stable Marriage hot sheet](stable-marriage-hot-sheet.md)
- weighted one-to-one assignment -> [Hungarian hot sheet](hungarian-hot-sheet.md)
- non-bipartite maximum matching -> [General Matching hot sheet](general-matching-hot-sheet.md)

## Core Invariants

- BFS: first visit gives minimum number of edges in an unweighted graph
- Dijkstra: settled distances stay optimal when all edge weights are nonnegative
- `0-1 BFS`: deque order stays nondecreasing by distance
- Bellman-Ford: one more relaxation after `n - 1` rounds signals a reachable negative cycle

## Retrieval Cues

- "fewest edges" or "minimum moves" -> start from BFS
- "weights are only 0 and 1" -> do not jump to Dijkstra first
- "negative edge" or "check for negative cycle" -> Bellman-Ford family
- "cheapest transport under capacities" -> [Min-Cost Flow hot sheet](min-cost-flow-hot-sheet.md)
- "each row and each column must be used exactly once, and the score is additive" -> [Hungarian hot sheet](hungarian-hot-sheet.md)
- "each side ranks the other side, and the answer must have no blocking pair" -> [Stable Marriage hot sheet](stable-marriage-hot-sheet.md)
- "the graph is undirected, odd cycles are allowed, and you still want the largest disjoint edge set" -> [General Matching hot sheet](general-matching-hot-sheet.md)
- "many or all vertex pairs ask for their undirected min cut" -> [Gomory-Hu hot sheet](gomory-hu-hot-sheet.md)
- "plain max flow is still the model, but you want a height/excess preflow engine rather than Dinic" -> [Push-Relabel hot sheet](push-relabel-hot-sheet.md)
- "every edge has both minimum and maximum allowed flow" -> [Flow With Lower Bounds hot sheet](flow-lower-bounds-hot-sheet.md)
- "remove one road or city and connectivity breaks" -> [Low-Link hot sheet](lowlink-hot-sheet.md)
- "use every road / teleporter exactly once" -> [Eulerian hot sheet](eulerian-hot-sheet.md)
- "every object has two modes and each constraint touches two literals" -> [Two-SAT hot sheet](two-sat-hot-sheet.md)
- "same unlabeled rooted tree shape, child order irrelevant" -> [Tree Isomorphism hot sheet](tree-isomorphism-hot-sheet.md)
- "same unrooted tree shape, and the only ambiguity should be one or two centers" -> [Tree Isomorphism hot sheet](tree-isomorphism-hot-sheet.md)
- "one rooted subtree" or "all descendants of one node" -> [Subtree Queries hot sheet](subtree-queries-hot-sheet.md)
- "one query marks a small subset of tree vertices, and only the branch points between them matter" -> [Virtual Tree hot sheet](virtual-tree-hot-sheet.md)
- "tree paths" -> LCA for ancestor/meet questions, HLD for repeated static path aggregates, Euler flattening for subtree-only aggregation
- "tree paths, but the split is through one balanced center or one logarithmic ancestor chain" -> [Centroid hot sheet](centroid-hot-sheet.md)
- "tree paths, but the edges themselves change online" -> [Link-Cut Tree hot sheet](link-cut-tree-hot-sheet.md)
- "link-cut tree still feels mysterious because the auxiliary splay tree is the missing piece" -> [Splay Tree hot sheet](splay-tree-hot-sheet.md) + [Link-Cut Tree hot sheet](link-cut-tree-hot-sheet.md)
- "the edges change online, but the query is still subtree-shaped on one incident edge" -> [Euler Tour Tree hot sheet](euler-tour-tree-hot-sheet.md)
- "same component after many merges" -> maybe DSU, not BFS/DFS
- "same component after adds and deletes, but all events are known first" -> [DSU Rollback hot sheet](dsu-rollback-hot-sheet.md)

## Invariants To Keep In Mind

- shortest-path code only updates `parent[v]` when `dist[v]` improves
- heap Dijkstra must skip stale entries
- `0-1 BFS` keeps deque order nondecreasing by distance
- Bellman-Ford only gives a valid shortest-path answer when no reachable negative cycle keeps improving the target

## Quick Anchors In This Repo

- shortest-path family -> [Shortest Paths hot sheet](shortest-paths-hot-sheet.md) + [Message Route](../practice/ladders/graphs/bfs-dfs/messageroute.md) + [QOS](../practice/ladders/graphs/shortest-paths/qos.md)
- bridges / cut vertices / block-cut entry -> [Low-Link hot sheet](lowlink-hot-sheet.md) + [Necessary Roads](../practice/ladders/graphs/bridges-articulation/necessaryroads.md) + [bridges-articulation-lowlink.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bridges-articulation-lowlink.cpp)
- Eulerian trail / cycle -> [Eulerian hot sheet](eulerian-hot-sheet.md) + [Mail Delivery](../practice/ladders/graphs/eulerian-path-cycle/maildelivery.md) + [eulerian-path-cycle.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/eulerian-path-cycle.cpp)
- overlap-state sequence construction -> [De Bruijn Sequence hot sheet](de-bruijn-sequence-hot-sheet.md) + [De Bruijn Sequence](../practice/ladders/graphs/de-bruijn-sequence/debruijnsequence.md) + [de-bruijn-sequence-binary.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/de-bruijn-sequence-binary.cpp)
- MST -> [Road Reparation](../practice/ladders/graphs/mst/roadreparation.md)
- SCC / DAG ordering -> [Course Schedule](../practice/ladders/graphs/scc-toposort/courseschedule.md)
- 2-SAT / implication graph -> [Two-SAT hot sheet](two-sat-hot-sheet.md) + [Giant Pizza](../practice/ladders/graphs/two-sat/giantpizza.md) + [two-sat.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/two-sat.cpp)
- rooted tree shape comparison -> [Tree Isomorphism hot sheet](tree-isomorphism-hot-sheet.md) + [Tree Isomorphism I](../practice/ladders/graphs/tree-isomorphism/treeisomorphism1.md) + [tree-isomorphism-rooted.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/tree-isomorphism-rooted.cpp)
- subtree-only tree aggregation -> [Subtree Queries hot sheet](subtree-queries-hot-sheet.md) + [Subtree Queries](../practice/ladders/graphs/euler-tour-subtree/subtreequeries.md) + [euler-tour-subtree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/euler-tour-subtree.cpp)
- marked-subset tree compression -> [Virtual Tree hot sheet](virtual-tree-hot-sheet.md) + [Kingdom and its Cities](../practice/ladders/graphs/virtual-tree/kingdomanditscities.md) + [virtual-tree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/virtual-tree.cpp)
- tree path decomposition -> [Heavy-Light Decomposition](../topics/graphs/hld/README.md) + [Path Queries II](../practice/ladders/graphs/hld/pathqueries2.md) + [hld-path-max.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hld-path-max.cpp)
- HLD retrieval route -> [HLD hot sheet](hld-hot-sheet.md)
- centroid-tree recursion -> [Centroid hot sheet](centroid-hot-sheet.md) + [Ciel the Commander](../practice/ladders/graphs/centroid-decomposition/cielthecommander.md) + [centroid-decomposition.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/centroid-decomposition.cpp)
- dynamic tree path aggregate -> [Link-Cut Tree hot sheet](link-cut-tree-hot-sheet.md) + [Dynamic Tree Vertex Add Path Sum](../practice/ladders/graphs/link-cut-tree/dynamictreevertexaddpathsum.md) + [link-cut-tree-path-sum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/link-cut-tree-path-sum.cpp)
- auxiliary-splay refresher before dynamic trees -> [Splay Tree hot sheet](splay-tree-hot-sheet.md) + [Splay Tree](../topics/data-structures/splay-tree/README.md)
- dynamic tree subtree-side aggregate -> [Euler Tour Tree hot sheet](euler-tour-tree-hot-sheet.md) + [Dynamic Tree Vertex Add Subtree Sum](../practice/ladders/graphs/euler-tour-tree/dynamictreevertexaddsubtreesum.md) + [euler-tour-tree-subtree-sum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/euler-tour-tree-subtree-sum.cpp)
- offline dynamic connectivity -> [DSU Rollback hot sheet](dsu-rollback-hot-sheet.md) + [Dynamic Connectivity](../practice/ladders/data-structures/dsu-rollback/dynamicconnectivity.md)
- flow / cuts -> [Flow hot sheet](flow-hot-sheet.md) + [Police Chase](../practice/ladders/graphs/flow/policechase.md)
- preflow / height-label max-flow sibling -> [Push-Relabel hot sheet](push-relabel-hot-sheet.md) + [Maximum Flow](../practice/ladders/graphs/flow/maximumflowpushrelabel.md) + [push-relabel-max-flow.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/push-relabel-max-flow.cpp)
- one global undirected cut with no designated pair -> [Global Min-Cut hot sheet](global-min-cut-hot-sheet.md) + [Minimum Cut](../practice/ladders/graphs/global-min-cut/globalmincut.md) + [stoer-wagner-global-mincut.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/stoer-wagner-global-mincut.cpp)
- all-pairs cut compression -> [Gomory-Hu hot sheet](gomory-hu-hot-sheet.md) + [MCQUERY](../practice/ladders/graphs/gomory-hu/mcquery.md) + [gomory-hu-tree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/gomory-hu-tree.cpp)
- lower-bounded circulation -> [Flow With Lower Bounds hot sheet](flow-lower-bounds-hot-sheet.md) + [Reactor Cooling](../practice/ladders/graphs/flow/reactorcooling.md) + [flow-lower-bounds.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/flow-lower-bounds.cpp)
- min-cost transport -> [Min-Cost Flow hot sheet](min-cost-flow-hot-sheet.md) + [MINCOST](../practice/ladders/graphs/flow/mincost.md)
- matching / bipartite pairing -> [Matching hot sheet](matching-hot-sheet.md)
- stable bipartite pairing under strict preferences -> [Stable Marriage hot sheet](stable-marriage-hot-sheet.md) + [Stable Marriage](../practice/ladders/graphs/stable-marriage/stablemarriage.md) + [gale-shapley-stable-marriage.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/gale-shapley-stable-marriage.cpp)
- weighted assignment / dense cost matrix -> [Hungarian hot sheet](hungarian-hot-sheet.md) + [Task Assignment](../practice/ladders/graphs/hungarian-assignment/taskassignment.md) + [hungarian-assignment.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hungarian-assignment.cpp)
- general non-bipartite matching -> [General Matching hot sheet](general-matching-hot-sheet.md) + [General Matching](../practice/ladders/graphs/general-matching/generalmatching.md) + [edmonds-blossom.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/edmonds-blossom.cpp)
- general-matching / edge-cover transformation compare point -> [QBFLOWER](../practice/ladders/graphs/matching/qbflower.md)

## Next Stops

- [Shortest Paths topic](../topics/graphs/shortest-paths/README.md)
- [Graphs ladder](../practice/ladders/graphs/README.md)
- [Shortest Paths hot sheet](shortest-paths-hot-sheet.md)
- [HLD hot sheet](hld-hot-sheet.md)
- [Centroid hot sheet](centroid-hot-sheet.md)
- [Link-Cut Tree hot sheet](link-cut-tree-hot-sheet.md)
- [DSU Rollback hot sheet](dsu-rollback-hot-sheet.md)
- [Flow hot sheet](flow-hot-sheet.md)
- [Push-Relabel hot sheet](push-relabel-hot-sheet.md)
- [Global Min-Cut hot sheet](global-min-cut-hot-sheet.md)
- [Gomory-Hu hot sheet](gomory-hu-hot-sheet.md)
- [Flow With Lower Bounds hot sheet](flow-lower-bounds-hot-sheet.md)
- [Min-Cost Flow hot sheet](min-cost-flow-hot-sheet.md)
- [Matching hot sheet](matching-hot-sheet.md)
- [Stable Marriage hot sheet](stable-marriage-hot-sheet.md)
- [Hungarian hot sheet](hungarian-hot-sheet.md)
- [General Matching hot sheet](general-matching-hot-sheet.md)
- [Low-Link hot sheet](lowlink-hot-sheet.md)
- [Eulerian hot sheet](eulerian-hot-sheet.md)
- [Two-SAT hot sheet](two-sat-hot-sheet.md)
- [Tree Isomorphism hot sheet](tree-isomorphism-hot-sheet.md)
- [Subtree Queries hot sheet](subtree-queries-hot-sheet.md)
- [Virtual Tree hot sheet](virtual-tree-hot-sheet.md)
- [Euler Tour Tree hot sheet](euler-tour-tree-hot-sheet.md)
- [Template library](../template-library.md)
- [Flow topic](../topics/graphs/flow/README.md)
- [Global Min-Cut topic](../topics/graphs/global-min-cut/README.md)
- [Gomory-Hu topic](../topics/graphs/gomory-hu/README.md)
- [LCA topic](../topics/graphs/lca/README.md)
- [Tree Isomorphism topic](../topics/graphs/tree-isomorphism/README.md)
- [Virtual Tree topic](../topics/graphs/virtual-tree/README.md)
- [Link-Cut Tree topic](../topics/graphs/link-cut-tree/README.md)
- [Euler Tour Tree topic](../topics/graphs/euler-tour-tree/README.md)
