# FFLOW

- Title: `Fast Maximum Flow`
- Judge / source: `VN SPOJ`
- Original URL: [https://vn.spoj.com/problems/FFLOW/](https://vn.spoj.com/problems/FFLOW/)
- Mirror / English URL: [https://vn.spoj.com/problems/FFLOW/en/](https://vn.spoj.com/problems/FFLOW/en/)
- Main topic: `Graphs -> Flow`
- Secondary topics: `Dinic`, `Undirected capacity graph`
- Difficulty: `medium`
- Subtype: `Maximum flow / minimum cut`
- Status: `solved`
- Solution file: [fflow.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/flow/fflow.cpp)

## Why Practice This

This is a useful flow problem because the statement looks like an undirected weighted graph problem, but the clean solution is still a standard `s-t` max-flow model with careful edge construction.

## Key Idea

Treat the graph as a flow network with:

- source `s = 1`
- sink `t = N`
- each undirected edge `(u, v, c)` represented by capacity `c` in both directions

Then the task is exactly the `maximum flow` problem.

Because the graph is sparse enough for a standard flow algorithm and the capacities are large, a good fit is `Dinic's algorithm` with `long long` capacities.

For `vn.spoj`, the implementation uses a more performance-oriented version:

- flat edge arrays
- manual BFS queue
- capacity scaling

## Complexity

- Dinic is fast enough for the judge limits here
- capacities use `long long`

## Pitfalls / Judge Notes

For one undirected edge with capacity `c` between `u` and `v`, we add:

- a directed edge `u -> v` with capacity `c`
- a directed edge `v -> u` with capacity `c`

In the residual graph implementation, each of those directed edges also gets its own reverse edge of capacity `0`.

Self-loops can be ignored because they never help send flow from `1` to `N`, and they never affect an `s-t` cut.

- `N <= 5000`, `M <= 30000`
- capacities can be up to `1e9`
- the answer may exceed `32-bit`, so the implementation uses `long long`
- duplicate edges are allowed and can be added directly
- the solution uses a capacity-scaling version of `Dinic's algorithm`

## Reusable Pattern

- Topic page: [Maximum Flow](../../../../topics/graphs/flow/README.md)
- Practice ladder: [Maximum Flow ladder](README.md)
- Starter template: [dinic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dinic.cpp)
- Notebook refresher: [Graph cheatsheet](../../../../notebook/graph-cheatsheet.md)
- Carry forward: separate the reusable residual-network engine from the problem-specific source/sink modeling.
- This note adds: the capacity-scaling and undirected-edge handling needed by this judge task.

## Solutions

- Code: [fflow.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/flow/fflow.cpp)
