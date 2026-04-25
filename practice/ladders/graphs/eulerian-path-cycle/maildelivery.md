# Mail Delivery

- Title: `Mail Delivery`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1691](https://cses.fi/problemset/task/1691)
- Secondary topics: `Eulerian cycle`, `Hierholzer`, `Degree parity`
- Difficulty: `medium`
- Subtype: `Undirected all-edge traversal`
- Status: `solved`
- Solution file: [maildelivery.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/eulerian-path-cycle/maildelivery.cpp)

## Why Practice This

This is the cleanest in-repo anchor for the first exact `Eulerian Path / Cycle` lane.

The statement is almost perfect:

- roads are undirected edges
- you must use every road exactly once
- you must end where you started
- any valid route is accepted

So the whole problem reduces directly to:

- undirected Eulerian **cycle** conditions
- one iterative `Hierholzer` traversal
- one final `m + 1` length check

## Recognition Cue

Reach for the Eulerian lane when:

- the walk must consume every edge exactly once
- the graph is static
- the output is one route, not one minimum distance
- the real question is degree feasibility plus constructive traversal

The strongest smell here is:

- "every street exactly once, return to the starting city"

That is almost the textbook definition of an undirected Eulerian cycle.

## Problem-Specific Transformation

Model:

- cities -> vertices
- roads -> undirected edges

The return-to-start requirement means the answer must be an Eulerian **cycle**, not just an open trail.

So the feasibility test is:

- every non-isolated vertex has even degree

After that, run `Hierholzer` from any vertex with degree `> 0`.

If the produced vertex list does not have length:

$$
m + 1
$$

then some used-edge component was disconnected and the answer is impossible.

## Core Idea

Use iterative `Hierholzer`.

1. build the undirected multigraph with one shared edge id per road
2. reject immediately if some degree is odd
3. start from one non-isolated vertex
4. while the current stack top still has an unused road, follow it
5. once a vertex has no unused incident edge left, pop it into the answer
6. reverse the finished answer
7. accept only if the answer length is exactly `m + 1`

The invariant is:

```text
when a vertex is appended to the reversed answer,
its local unused-edge work is already finished forever
```

That is why arbitrary unused-edge choices still produce one valid Eulerian cycle.

## Complexity

- `O(n + m)`

Every edge is marked used exactly once.

## Pitfalls / Judge Notes

- Undirected edges need **one shared edge id**; do not mark adjacency entries separately.
- Even degrees alone are not enough. You still need the final `m + 1` guard.
- Isolated vertices do not matter.
- If `m = 0`, the statement's expected behavior is special-case territory, but the normal CSES path never needs that branch.
- This is **not** an Euler-tour-on-tree problem.

## Reusable Pattern

- Topic page: [Eulerian Path / Cycle](../../../../topics/graphs/eulerian-path-cycle/README.md)
- Practice ladder: [Eulerian Path / Cycle ladder](README.md)
- Starter template: [eulerian-path-cycle.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/eulerian-path-cycle.cpp)
- Notebook refresher: [Eulerian hot sheet](../../../../notebook/eulerian-hot-sheet.md)
- Compare points:
  - [Euler Tour / Subtree Queries](../../../../topics/graphs/euler-tour-subtree/README.md)
  - [Graph Modeling](../../../../topics/graphs/graph-modeling/README.md)
- This note adds: the clean undirected-cycle flagship for the `Hierholzer` route.

## Solutions

- Code: [maildelivery.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/eulerian-path-cycle/maildelivery.cpp)
