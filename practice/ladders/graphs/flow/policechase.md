# Police Chase

- Title: `Police Chase`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1695](https://cses.fi/problemset/task/1695)
- Secondary topics: `Minimum cut`, `Cut certificate`, `Undirected unit-capacity flow`
- Difficulty: `medium`
- Subtype: `Output any minimum set of streets whose removal disconnects node 1 from node n`
- Status: `solved`
- Solution file: [policechase.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/flow/policechase.cpp)

## Why Practice This

This is one of the cleanest bridge problems between ordinary max-flow coding and the dual view behind `optimization-and-duality`.

You are not asked for the maximum amount of flow. You are asked for a **certificate** that blocks every route.

That is exactly where max-flow/min-cut becomes more than an algorithm:

- flow gives the value
- the residual graph reveals the cut
- the cut is the object the statement actually wants

## Key Idea

Each undirected street can be closed at most once, so give every street capacity `1`.

Model one undirected street `(u, v)` as:

- directed edge `u -> v` with capacity `1`
- directed edge `v -> u` with capacity `1`

Then compute the maximum flow from:

- source `s = 1`
- sink `t = n`

By the max-flow min-cut theorem, the maximum flow value equals the minimum number of streets that must be closed.

After the flow finishes:

1. run DFS/BFS from `s` in the **residual graph**
2. mark every reachable node
3. every original street `(u, v)` with:
   - `u` reachable and `v` unreachable, or
   - `v` reachable and `u` unreachable
   belongs to one minimum cut

Those are exactly the streets we print.

## Complexity

With `n <= 500` and `m <= 1000`, standard Dinic is easily fast enough:

- max flow: comfortably within limits
- final residual DFS: `O(n + m)`

## Pitfalls / Judge Notes

- The streets are **undirected**, but the flow model still uses two directed unit-capacity edges.
- Print streets from the original input graph, not residual edges.
- The residual DFS must happen **after** max flow is complete.
- Any minimum cut is accepted, so the order of printed streets does not matter.

## Reusable Pattern

- Topic page: [Maximum Flow](../../../../topics/graphs/flow/README.md)
- Practice ladder: [Maximum Flow ladder](README.md)
- Starter template: [dinic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dinic.cpp)
- Notebook refresher: [Graph cheatsheet](../../../../notebook/graph-cheatsheet.md)
- Carry forward: when the statement asks for edges to remove, think “compute max flow, then read the reachable side of the residual graph.”
- This note adds: the explicit min-cut certificate extraction step that makes the dual view concrete.

## Solutions

- Code: [policechase.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/flow/policechase.cpp)
