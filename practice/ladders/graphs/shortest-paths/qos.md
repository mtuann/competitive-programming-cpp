# QOS

- Title: `Chất lượng dịch vụ`
- Judge / source: `VN SPOJ`
- Original URL: [https://vn.spoj.com/problems/QOS/](https://vn.spoj.com/problems/QOS/)
- Secondary topics: `Reverse Dijkstra`, `DP with slack`, `K-th lexicographic path`
- Difficulty: `hard`
- Subtype: `K-th lexicographic path under a near-shortest bound`
- Source contest: `VOI 2014 Day 2`
- Status: `solved`
- Solution file: [qos.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/shortest-paths/qos.cpp)
- Alternate solution variants: [qos-oldstyle.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/shortest-paths/qos-oldstyle.cpp)

## Why Practice This

This is a strong shortest-paths practice problem because the shortest-path computation is only the first step. The real work is turning the QoS bound into a tiny extra-state DP, then using those counts to recover the `k`-th valid path in lexicographic order.

## Recognition Cue

This is a strong `shortest path first, tiny extra-state DP later` signal:

- the path bound is only slightly above the shortest path
- the problem asks for the `k`-th lexicographic valid path, not just one optimum
- a direct path enumeration would explode
- one global minimum edge weight gives a very small slack budget

Whenever a path constraint is "shortest path plus a tiny allowance," try to express the remaining freedom as a small integer state.

## Problem-Specific Transformation

The statement is rewritten in two stages:

1. run reverse Dijkstra to compute `dist[u]`, the shortest suffix cost from `u` to `t`
2. replace the path-length limit `<= Tmin + Cmin` with a slack parameter `p` that measures how far above `dist[u]` we may still spend

Then:

- `dp[u][p]` counts valid suffixes from `u`
- outgoing edges are filtered by whether they keep the next slack nonnegative
- the counted subtrees let us skip lexicographically whole groups during reconstruction

So the hard part is not shortest paths alone. It is shortest paths plus a tiny bounded-slack DP.

## Core Idea

Let:

- `dist[u]` be the shortest distance from `u` to the target `t`
- `Tmin = dist[1]`
- `Cmin` be the minimum edge weight in the whole graph

A valid path from `1` to `t` must have total length at most:

`Tmin + Cmin`

So once we know `dist[u]`, we only need to track how much extra slack above the shortest possible suffix is still available.

Define:

`dp[u][p] = number of valid paths from u to t with total length <= dist[u] + p`

The starting state is `dp[1][Cmin]`.

For an edge `u -> v` with weight `w`, the remaining slack becomes:

`next_p = p + dist[u] - w - dist[v]`

If `next_p >= 0`, then that edge can still lead to a valid path, and we add `dp[v][next_p]`.

Because `Cmin < 100`, the slack dimension is tiny. After counting all valid paths, we reconstruct the answer lexicographically by scanning outgoing edges in increasing destination order and skipping entire groups of suffixes using the DP counts.

### Why The Slack DP Is Exact

For every edge `u -> v` with weight `w`, shortest-path optimality gives:

`dist[u] <= w + dist[v]`

So the quantity:

`w + dist[v] - dist[u]`

is the extra cost paid by taking that edge instead of following a shortest suffix immediately. It is always nonnegative.

That means the whole path budget can be tracked as a small nonnegative slack variable, and once the total allowed overhead is only `Cmin`, the DP needs only states `0..Cmin`.

## Complexity

- reverse Dijkstra: `O((n + m) log n)`
- DP counting: `O(m * Cmin)`
- reconstruction: linear in the output path length times the scanned outgoing edges

With `n <= 1000`, `m <= 100000`, and `Cmin < 100`, this fits comfortably.

## Pitfalls / Judge Notes

- `Cmin` is the minimum edge weight in the whole graph, not only on shortest paths.
- Count paths with saturation at `k`, because `k <= 10^9` and we only need to know whether a subtree contributes at least `k`.
- Lexicographic reconstruction must treat `stop at t` as its own first option. In code, that means the target state contributes one empty suffix before any extendable outgoing transitions are considered.
- Sort outgoing edges by destination to match the problem's lexicographic order on node sequences.
- If `dist[1]` is infinite or the total number of valid paths is less than `k`, print `-1`.

## Old Version Notes

The repo also keeps a minimal-diff rewrite of an older matrix-based submission:

- [qos-oldstyle.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/shortest-paths/qos-oldstyle.cpp)

That version stays close to the original style, but fixes several real correctness issues:

- it no longer does arithmetic through fake `INF` values, which could invent nonexistent transitions
- it uses `long long` counts and caps them at `k` to avoid overflow
- it does not skip self-loops, because paths like `u -> u` can still matter under the QoS bound
- it treats reaching `t` as one valid `stop here` option before considering any valid continuation
- it computes the DP directly with the intended `<=` meaning instead of building exact counts first and prefixing later
- it uses a stable tie-break when sorting nodes by `minT`

So the main accepted file:

- [qos.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/shortest-paths/qos.cpp)

is the cleaner implementation, while `qos-oldstyle.cpp` is the closer “patched old submission” version for study.

## Reusable Pattern

- Topic page: [Shortest Paths](../../../../topics/graphs/shortest-paths/README.md)
- Practice ladder: [Shortest Paths ladder](README.md)
- Starter template: [dijkstra.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dijkstra.cpp)
- Notebook refresher: [Graph cheatsheet](../../../../notebook/graph-cheatsheet.md)
- Carry forward: pick the lightest shortest-path primitive that fits the edge weights and graph model.
- This note adds: the DP and lexicographic reconstruction logic added after shortest paths.

## Solutions

- Code: [qos.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/shortest-paths/qos.cpp)
- Minimal-diff oldstyle patch: [qos-oldstyle.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/shortest-paths/qos-oldstyle.cpp)
