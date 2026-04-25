# Necessary Roads

- Title: `Necessary Roads`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/2076](https://cses.fi/problemset/task/2076)
- Secondary topics: `Bridge detection`, `DFS tree`, `Low-link`
- Difficulty: `medium`
- Subtype: `List all bridge edges in an undirected graph`
- Status: `solved`
- Solution file: [necessaryroads.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/bridges-articulation/necessaryroads.cpp)

## Why Practice This

This is the cleanest in-repo anchor for the low-link bridge test.

The statement is almost ideal:

- the graph is undirected
- connectivity is already guaranteed
- the task only asks which roads are critical
- any valid order is accepted

So you can focus directly on:

- DFS tree edges
- back edges
- `tin / low`
- the strict bridge test

## Recognition Cue

Reach for bridge detection when:

- the statement asks for roads or edges whose removal disconnects the graph
- "still connected after deleting one road" is the core question
- the graph is undirected and static
- the task wants a full list of critical edges, not shortest paths or flows

The strong smell here is:

- each road is called necessary exactly when deleting it destroys some route

That is almost the definition of a bridge.

## Problem-Specific Transformation

Turn the city map directly into:

- one undirected graph
- one DFS tree

For each DFS tree edge `(v, to)`:

- if the subtree of `to` cannot reconnect upward without using `(v, to)`, then that road is necessary

The low-link invariant expresses that as:

$$
low[to] > tin[v]
$$

So the original task becomes:

- run one DFS
- compute `tin` and `low`
- output every tree edge satisfying the strict bridge inequality

## Core Idea

For each vertex `v`:

- `tin[v]` is when DFS first enters `v`
- `low[v]` is the smallest entry time reachable from the subtree of `v` using at most one back edge

Then a tree edge `(v, to)` is a bridge iff:

$$
low[to] > tin[v]
$$

Why is the comparison strict?

- if `low[to] <= tin[v]`, the subtree of `to` can still reach `v` or an ancestor by another route
- so deleting `(v, to)` does not disconnect it
- only when `low[to] > tin[v]` is the parent edge the unique attachment upward

That is exactly what "necessary road" means in this statement.

## Complexity

- `O(n + m)` time
- `O(n + m)` memory for adjacency plus DFS state

This fits the CSES limits comfortably.

## Pitfalls / Judge Notes

- This is the **bridge** test `low[child] > tin[parent]`, not the articulation test.
- The graph is undirected, so use edge ids if you want a reusable multiedge-safe skeleton.
- Output order does not matter, so do not waste time sorting unless the statement asks for it.
- The graph is connected, but a general starter should still DFS from every unvisited root.

## Reusable Pattern

- Topic page: [Bridges, Articulation Points, And Biconnected Components](../../../../topics/graphs/bridges-articulation/README.md)
- Practice ladder: [Bridges / Articulation / BCC ladder](README.md)
- Starter template: [bridges-articulation-lowlink.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/bridges-articulation-lowlink.cpp)
- Notebook refresher: [Low-Link hot sheet](../../../../notebook/lowlink-hot-sheet.md)
- Compare points: [Trees](../../../../topics/graphs/trees/README.md), [Topological Sort And SCC](../../../../topics/graphs/scc-toposort/README.md)
- This note adds: the cleanest bridge-only interpretation of the low-link invariant.

## Solutions

- Code: [necessaryroads.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/bridges-articulation/necessaryroads.cpp)
