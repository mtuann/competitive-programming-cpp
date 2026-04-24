# Road Reparation

- Title: `Road Reparation`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1675](https://cses.fi/problemset/task/1675)
- Secondary topics: `Kruskal`, `DSU`, `Connectivity check`
- Difficulty: `medium`
- Subtype: `Minimum spanning tree cost in an undirected weighted graph`
- Status: `solved`
- Solution file: [roadreparation.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/mst/roadreparation.cpp)

## Why Practice This

This is the canonical first MST problem on CSES. Nothing fancy is hiding behind the statement, so the whole point is to practice the real invariant behind Kruskal:

- sort edges by weight
- only take an edge if it connects two different components
- verify the graph actually becomes one connected tree

## Key Idea

For an undirected weighted graph, Kruskal's algorithm says:

1. Sort all edges by increasing weight.
2. Scan them in that order.
3. Take an edge `(u, v)` exactly when `u` and `v` currently belong to different DSU components.

Why is that safe?

At the moment we consider an edge that joins two different components, it is the lightest remaining edge crossing that cut between those components. By the cut property, such an edge can belong to some MST, so taking it is always safe.

If an edge would connect two vertices already in the same component, then adding it would create a cycle, so Kruskal skips it.

The algorithm finishes with:

- exactly `n - 1` chosen edges if the graph is fully connectable
- fewer than `n - 1` chosen edges if the graph is disconnected

So after the scan, we only need one extra check:

```text
did we choose n - 1 edges?
```

If not, print `IMPOSSIBLE`.

## Complexity

- sorting edges: `O(m log m)`
- DSU operations: `O(m alpha(n))`
- total: `O(m log m)`

This is the intended complexity for the CSES limits.

## Pitfalls / Judge Notes

- The graph is undirected, so each input edge is already one usable undirected edge for Kruskal. Do not duplicate it.
- Use `long long` for the total MST cost.
- The final connectivity check is essential. Kruskal can finish scanning edges without having built a spanning tree.
- MST is about minimum total connection cost, not shortest paths from one source.

## Reusable Pattern

- Topic page: [Minimum Spanning Tree](../../../../topics/graphs/mst/README.md)
- Practice ladder: [Minimum Spanning Tree ladder](README.md)
- Starter template: [kruskal.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/kruskal.cpp)
- Notebook refresher: [Graph cheatsheet](../../../../notebook/graph-cheatsheet.md)
- Carry forward: sort edges by weight and let the cut property justify every accepted edge.
- This note adds: the connectivity or output requirement attached to this MST instance.

## Solutions

- Code: [roadreparation.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/mst/roadreparation.cpp)
