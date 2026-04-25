# Graphs

Graphs are one of the central contest areas because many problems are really about states and transitions in disguise. This section should teach graph modeling first, then standard algorithms, then deeper tree, cut, and matching ideas.

## Subtopics

- [Graph Modeling](graph-modeling/README.md)
- [BFS And DFS](bfs-dfs/README.md)
- [Shortest Paths](shortest-paths/README.md)
- [Minimum Spanning Tree](mst/README.md)
- [Topological Sort And SCC](scc-toposort/README.md)
- [2-SAT](two-sat/README.md)
- [Trees](trees/README.md)
- [LCA](lca/README.md)
- [Heavy-Light Decomposition](hld/README.md)
- [Maximum Flow](flow/README.md)
- [Min-Cost Flow](min-cost-flow/README.md)
- [Matching](matching/README.md)

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
- 2-SAT once SCC condensation is comfortable
- trees, LCA, and rerooting-style thinking
- bridge and articulation ideas

3. Advanced later
- flow
- matching
- heavy-light and more specialized tree machinery

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
- [QOS - Chất lượng dịch vụ](../../practice/ladders/graphs/shortest-paths/qos.md): shortest paths plus lexicographic constrained reconstruction
- [Giant Pizza](../../practice/ladders/graphs/two-sat/giantpizza.md): binary clause modeling and SCC-based assignment extraction
- [FFLOW - Fast Maximum Flow](../../practice/ladders/graphs/flow/fflow.md): max-flow implementation and judge-facing performance engineering
- [MINCOST - Luồng với chi phí nhỏ nhất](../../practice/ladders/graphs/flow/mincost.md): min-cost flow with judge-specific duplicate-edge handling
- [QBFLOWER - Tặng hoa](../../practice/ladders/graphs/matching/qbflower.md): general matching and edge-cover modeling
- [VOSTRIP - VOSTRIP](../../practice/ladders/graphs/tree-dp/vostrip.md): tree usage aggregation and endpoint accounting
- [PATHQUERIES2 - Path Queries II](../../practice/ladders/graphs/hld/pathqueries2.md): heavy-light decomposition for point updates and path maximum

## Go Deeper

- Course: [Stanford CS161](https://cs161-stanford.github.io)
- Course: [Cornell CS 4820](https://www.cs.cornell.edu/courses/cs4820/2025sp/syllabus/)
- Reference: [CP-Algorithms](https://cp-algorithms.com/)
- Practice: [ICPC Curriculum](https://curriculum.u.icpc.global/curriculum/)
