# Low-Link Hot Sheet

Use this page when an undirected graph asks about critical roads, critical cities, or "what survives after removing one edge/vertex."

## Do Not Use When

- the graph is directed and the real tool is SCC
- the graph is already a tree and plain parent/depth logic is enough
- the task is dynamic or online, not one static DFS pass
- the statement is really about shortest paths, not connectivity under deletions

## Choose By Signal

- one road whose removal disconnects the graph -> bridges -> [`bridges-articulation-lowlink.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bridges-articulation-lowlink.cpp)
- one city whose removal disconnects some other pair -> articulation points -> same starter, but watch the root case
- need to compress after deleting all bridges -> bridge tree / 2-edge-connected components
- need queries of the form "can `a` reach `b` without `c`?" -> think vertex-BCC / block-cut tree -> reopen the full topic

## Core Invariants

- `low[v]` is the highest ancestor level the subtree of `v` can still touch without using the parent edge of `v`
- tree edge `(v, to)` is a bridge iff `low[to] > tin[v]`
- non-root `v` is an articulation point iff some child has `low[to] >= tin[v]`
- root is an articulation point iff it has more than one DFS child

## Main Traps

- using `>=` for bridges or `>` for articulation points
- forgetting that the root rule is separate
- skipping by parent vertex instead of parent edge when parallel edges can exist
- mixing edge-biconnected and vertex-biconnected structure

## Exact Starters In This Repo

- critical edges / vertices in one static undirected graph -> [`bridges-articulation-lowlink.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bridges-articulation-lowlink.cpp)
- flagship in-lane rep -> [Necessary Roads](../practice/ladders/graphs/bridges-articulation/necessaryroads.md)
- simpler traversal prerequisite -> [BFS And DFS](../topics/graphs/bfs-dfs/README.md)
- graph-family chooser -> [Graph cheatsheet](graph-cheatsheet.md)

## Reopen Paths

- full bridge / articulation / BCC lesson -> [Bridges, Articulation Points, And Biconnected Components](../topics/graphs/bridges-articulation/README.md)
- if the graph is directed instead -> [Topological Sort And SCC](../topics/graphs/scc-toposort/README.md)
- if the next structure is a tree after compression -> [Trees](../topics/graphs/trees/README.md)
- practice lane -> [Bridges / Articulation ladder](../practice/ladders/graphs/bridges-articulation/README.md)
