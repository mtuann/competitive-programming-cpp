# Message Route

- Title: `Message Route`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1667](https://cses.fi/problemset/task/1667)
- Main topic: `Graphs -> BFS And DFS`
- Secondary topics: `Unweighted shortest path`, `Parent reconstruction`, `Layered BFS`
- Difficulty: `easy`
- Subtype: `Recover one shortest path in an unweighted undirected graph`
- Status: `solved`
- Solution file: [messageroute.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/bfs-dfs/messageroute.cpp)

## Why Practice This

This is the standard BFS path-reconstruction problem. The graph part is simple on purpose, so the real lesson is to trust the BFS layer invariant and turn the traversal tree into an actual shortest route.

## Key Idea

Because every edge has unit cost, BFS explores nodes in nondecreasing distance from node `1`.

That gives two crucial facts:

- the first time BFS reaches a node, it has found a shortest path to that node
- if we remember the predecessor that first discovered the node, then those predecessors form a shortest-path tree

So the algorithm is:

1. Run BFS from `1`.
2. When we first discover `v` from `u`, set `parent[v] = u`.
3. If node `n` is never reached, answer `IMPOSSIBLE`.
4. Otherwise walk backward from `n` through `parent` until `1`, then reverse that list.

The important discipline is to assign `parent[v]` only once, at the moment `v` enters the queue. That keeps the stored route aligned with the first, and therefore shortest, visit.

## Complexity

- BFS: `O(n + m)`
- route reconstruction: `O(length of answer path)`
- total: `O(n + m)`

This is optimal for a single shortest-path query in an unweighted graph.

## Pitfalls / Judge Notes

- The graph is undirected, so every edge must be added in both directions.
- Mark a node as visited when you push it into the queue, not when you pop it.
- Do not overwrite `parent[v]` after the first visit.
- The output wants the number of vertices in the route, not the number of edges.
- Early exit is optional; correctness does not depend on stopping as soon as `n` is reached.

## Solutions

- Code: [messageroute.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/bfs-dfs/messageroute.cpp)
