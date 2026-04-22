# FFLOW

- Title: `Fast Maximum Flow`
- Judge: `VN SPOJ`
- Original URL: [https://vn.spoj.com/problems/FFLOW/](https://vn.spoj.com/problems/FFLOW/)
- English URL: [https://vn.spoj.com/problems/FFLOW/en/](https://vn.spoj.com/problems/FFLOW/en/)
- Main topic: `Graphs -> Flow`
- Likely subtype: `Maximum flow / minimum cut`
- Secondary topics: `Dinic`, `Undirected capacity graph`
- Status: `solved`
- Solution file: [fflow.cpp](/Users/mitu/Desktop/work/cp-cpp/solutions/graphs/flow/fflow.cpp)

## Why This Folder

This problem is placed under `practice/ladders/graphs/flow/` because the main skill is modeling and solving an `s-t maximum flow` problem.

The official `vn.spoj` statement describes an undirected weighted graph and asks for the maximum flow / minimum cut from vertex `1` to vertex `N`.

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

## Undirected Edge Modeling

For one undirected edge with capacity `c` between `u` and `v`, we add:

- a directed edge `u -> v` with capacity `c`
- a directed edge `v -> u` with capacity `c`

In the residual graph implementation, each of those directed edges also gets its own reverse edge of capacity `0`.

Self-loops can be ignored because they never help send flow from `1` to `N`, and they never affect an `s-t` cut.

## Why This Works

The statement already phrases the answer as:

- maximum flow
- or equivalently minimum cut

So once the graph is modeled correctly, the max-flow min-cut theorem gives the desired value.

## Implementation Notes

- `N <= 5000`, `M <= 30000`
- capacities can be up to `1e9`
- the answer may exceed `32-bit`, so the implementation uses `long long`
- duplicate edges are allowed and can be added directly
- the solution uses a capacity-scaling version of `Dinic's algorithm`

## Judge Note

No special judge mismatch was needed here.

The direct max-flow model matches the official statement, so the submission code follows the statement exactly.
