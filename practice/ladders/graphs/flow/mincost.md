# MINCOST

- Title: `Luồng với chi phí nhỏ nhất`
- Judge / source: `VN SPOJ / VNOI`
- Original URL: [https://vn.spoj.com/problems/MINCOST/](https://vn.spoj.com/problems/MINCOST/)
- Mirror URL: [https://oj.vnoi.info/problem/mincost](https://oj.vnoi.info/problem/mincost)
- Main topic: `Graphs -> Flow`
- Secondary topics: `Min-cost max-flow`, `Shortest augmenting path`, `Flow reconstruction`
- Difficulty: `hard`
- Subtype: `Send exactly k units with minimum transportation cost`
- Status: `solved`
- Solution file: [mincost.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/flow/mincost.cpp)

## Why Practice This

This is the standard min-cost flow pattern with one extra responsibility: you must also reconstruct an explicit transportation plan on the original undirected edges.

## Key Idea

Model each undirected road `(u, v)` with capacity `d` and cost `c` as two directed edges:

- `u -> v` with capacity `d`, cost `c`
- `v -> u` with capacity `d`, cost `c`

Then run successive shortest augmenting path with potentials:

1. find the shortest path in reduced costs
2. push as much flow as possible through that path
3. update potentials
4. repeat until `k` units are sent or no augmenting path exists

Because all costs are nonnegative, an optimal solution never needs positive flow in both directions on the same original road. So after the flow is finished, the net direction on each original edge is:

`flow(u -> v) - flow(v -> u)`

and that is exactly what we print.

## Complexity

With `n <= 100`, the standard implementation is fast enough:

- each augmentation uses Dijkstra on reduced costs
- total complexity is easily acceptable for this constraint range

## Pitfalls / Judge Notes

- If fewer than `k` units can reach the sink, print only `-1`.
- Use `long long` for distances and total cost.
- Reconstruct the answer on the **original** undirected edges, not on residual edges.
- The printed edge list can be any valid optimal transportation plan.

## Solutions

- Code: [mincost.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/flow/mincost.cpp)
## Judge Note

- `VN SPOJ` hidden tests may contain duplicate undirected edges.
- For the accepted version in [mincost.cpp](/Users/mitu/Desktop/work/competitive-programming-cpp/solutions/graphs/flow/mincost.cpp), only the **last occurrence** of each undirected pair is kept before building the flow network.
- The min-cost flow model itself is still the standard one: each undirected road becomes two directed edges with the same capacity and cost.
- The earlier `WA` came from treating repeated roads as separate parallel edges when this judge expects overwrite-by-last-input behavior.
