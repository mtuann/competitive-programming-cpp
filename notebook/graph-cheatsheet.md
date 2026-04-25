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
- one rooted subtree aggregate becomes one contiguous interval -> [Subtree Queries hot sheet](subtree-queries-hot-sheet.md)
- one query marks only a small subset of vertices but still needs the union of their paths -> [Virtual Tree hot sheet](virtual-tree-hot-sheet.md)
- static tree problem split by one balanced pivot or `O(log n)` centroid ancestors -> [Centroid hot sheet](centroid-hot-sheet.md)
- tree topology changes online but path queries still survive -> [Link-Cut Tree hot sheet](link-cut-tree-hot-sheet.md)
- tree topology changes online but the live query is one subtree side of an existing edge -> [Euler Tour Tree hot sheet](euler-tour-tree-hot-sheet.md)
- edge lower / upper bounds with conservation at every node -> [Flow With Lower Bounds hot sheet](flow-lower-bounds-hot-sheet.md)

## Core Families

- connectivity / traversal -> BFS, DFS
- critical roads / cities -> [Low-Link hot sheet](lowlink-hot-sheet.md)
- use-every-edge-once walks -> [Eulerian hot sheet](eulerian-hot-sheet.md)
- DAG dependencies -> toposort
- undirected cheapest backbone -> MST
- directed compression -> SCC
- binary clause feasibility -> [Two-SAT hot sheet](two-sat-hot-sheet.md)
- subtree-only rooted-tree aggregation -> [Subtree Queries hot sheet](subtree-queries-hot-sheet.md)
- marked-subset compression on one static rooted tree -> [Virtual Tree hot sheet](virtual-tree-hot-sheet.md)
- tree path queries -> LCA or [HLD hot sheet](hld-hot-sheet.md)
- balanced recursive tree splits / centroid ancestors -> [Centroid hot sheet](centroid-hot-sheet.md)
- dynamic-tree path queries / connectivity under online `link` and `cut` -> [Link-Cut Tree hot sheet](link-cut-tree-hot-sheet.md)
- dynamic-tree subtree-side queries under online `link` and `cut` -> [Euler Tour Tree hot sheet](euler-tour-tree-hot-sheet.md)
- capacities -> [Flow hot sheet](flow-hot-sheet.md)
- lower-bounded circulation / mandatory edge throughput -> [Flow With Lower Bounds hot sheet](flow-lower-bounds-hot-sheet.md)
- pairing -> [Matching hot sheet](matching-hot-sheet.md)

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
- "every edge has both minimum and maximum allowed flow" -> [Flow With Lower Bounds hot sheet](flow-lower-bounds-hot-sheet.md)
- "remove one road or city and connectivity breaks" -> [Low-Link hot sheet](lowlink-hot-sheet.md)
- "use every road / teleporter exactly once" -> [Eulerian hot sheet](eulerian-hot-sheet.md)
- "every object has two modes and each constraint touches two literals" -> [Two-SAT hot sheet](two-sat-hot-sheet.md)
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
- MST -> [Road Reparation](../practice/ladders/graphs/mst/roadreparation.md)
- SCC / DAG ordering -> [Course Schedule](../practice/ladders/graphs/scc-toposort/courseschedule.md)
- 2-SAT / implication graph -> [Two-SAT hot sheet](two-sat-hot-sheet.md) + [Giant Pizza](../practice/ladders/graphs/two-sat/giantpizza.md) + [two-sat.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/two-sat.cpp)
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
- lower-bounded circulation -> [Flow With Lower Bounds hot sheet](flow-lower-bounds-hot-sheet.md) + [Reactor Cooling](../practice/ladders/graphs/flow/reactorcooling.md) + [flow-lower-bounds.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/flow-lower-bounds.cpp)
- min-cost transport -> [Min-Cost Flow hot sheet](min-cost-flow-hot-sheet.md) + [MINCOST](../practice/ladders/graphs/flow/mincost.md)
- matching / bipartite pairing -> [Matching hot sheet](matching-hot-sheet.md)
- general-matching / edge-cover boundary compare point -> [QBFLOWER](../practice/ladders/graphs/matching/qbflower.md)

## Next Stops

- [Shortest Paths topic](../topics/graphs/shortest-paths/README.md)
- [Graphs ladder](../practice/ladders/graphs/README.md)
- [Shortest Paths hot sheet](shortest-paths-hot-sheet.md)
- [HLD hot sheet](hld-hot-sheet.md)
- [Centroid hot sheet](centroid-hot-sheet.md)
- [Link-Cut Tree hot sheet](link-cut-tree-hot-sheet.md)
- [DSU Rollback hot sheet](dsu-rollback-hot-sheet.md)
- [Flow hot sheet](flow-hot-sheet.md)
- [Flow With Lower Bounds hot sheet](flow-lower-bounds-hot-sheet.md)
- [Min-Cost Flow hot sheet](min-cost-flow-hot-sheet.md)
- [Matching hot sheet](matching-hot-sheet.md)
- [Low-Link hot sheet](lowlink-hot-sheet.md)
- [Eulerian hot sheet](eulerian-hot-sheet.md)
- [Two-SAT hot sheet](two-sat-hot-sheet.md)
- [Subtree Queries hot sheet](subtree-queries-hot-sheet.md)
- [Virtual Tree hot sheet](virtual-tree-hot-sheet.md)
- [Euler Tour Tree hot sheet](euler-tour-tree-hot-sheet.md)
- [Template library](../template-library.md)
- [Flow topic](../topics/graphs/flow/README.md)
- [LCA topic](../topics/graphs/lca/README.md)
- [Virtual Tree topic](../topics/graphs/virtual-tree/README.md)
- [Link-Cut Tree topic](../topics/graphs/link-cut-tree/README.md)
- [Euler Tour Tree topic](../topics/graphs/euler-tour-tree/README.md)
