# Graphs

Graphs are one of the central contest areas because many problems are really about states and transitions in disguise.

## Use This Area When

- the clean model is vertices plus edges, even if the story hides that fact
- you are being asked about reachability, cuts, trees, paths, or pairings
- the main difficulty is choosing the right graph family, not writing raw loops

## Start With One Route

| If your bottleneck is... | Open first | Then |
| --- | --- | --- |
| basic modeling and traversals | [Graph Modeling](graph-modeling/README.md) | [BFS And DFS](bfs-dfs/README.md), [Shortest Paths](shortest-paths/README.md), [Minimum Spanning Tree](mst/README.md) |
| tree topics feel fragmented | [Trees](trees/README.md) | [Euler Tour / Subtree Queries](euler-tour-subtree/README.md), [LCA](lca/README.md), [Heavy-Light Decomposition](hld/README.md) |
| cut, flow, and circulation topics feel fragmented | [Maximum Flow](flow/README.md) | [Flow With Lower Bounds](flow-lower-bounds/README.md), [Gomory-Hu Tree](gomory-hu/README.md), [Min-Cost Flow](min-cost-flow/README.md) |
| matching or assignment is the real family | [Matching](matching/README.md) | [Stable Marriage](stable-marriage/README.md), [Hungarian / Assignment Problem](hungarian-assignment/README.md), [Edmonds Blossom / General Matching](general-matching/README.md) |

## Core Progression

1. `Core first`
- Graph Modeling
- BFS / DFS
- Shortest Paths
- Minimum Spanning Tree
- Topological Sort / SCC

2. `Then add`
- Bridges / Articulation / BCC
- Eulerian Path / Cycle
- Trees / Euler Tour / LCA
- Two-SAT

3. `Deep later`
- Virtual Tree / HLD / Centroid Decomposition
- Link-Cut Tree / Euler Tour Tree
- Maximum Flow / Lower Bounds / Min-Cost Flow
- Global Min-Cut / Gomory-Hu
- Stable Marriage / Hungarian / Blossom
- Tree Isomorphism / De Bruijn Sequence

## Good First Repo Anchors

- [Counting Rooms](../../practice/ladders/graphs/graph-modeling/countingrooms.md)
- [QOS](../../practice/ladders/graphs/shortest-paths/qos.md)
- [Mail Delivery](../../practice/ladders/graphs/eulerian-path-cycle/maildelivery.md)
- [Kingdom and its Cities](../../practice/ladders/graphs/virtual-tree/kingdomanditscities.md)
- [MCQUERY](../../practice/ladders/graphs/gomory-hu/mcquery.md)
- [Task Assignment](../../practice/ladders/graphs/hungarian-assignment/taskassignment.md)

## Browse All Subtopics

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

## Go Deeper

- Course: [Stanford CS161](https://cs161-stanford.github.io)
- Course: [Cornell CS 4820](https://www.cs.cornell.edu/courses/cs4820/2025sp/syllabus/)
- Reference: [CP-Algorithms](https://cp-algorithms.com/)
- Practice: [ICPC Curriculum](https://curriculum.u.icpc.global/curriculum/)
