# QBFLOWER

- Title: `Tặng hoa`
- Judge / source: `VN SPOJ`
- Original URL: [https://vn.spoj.com/problems/QBFLOWER/](https://vn.spoj.com/problems/QBFLOWER/)
- Secondary topics: `Minimum edge cover`, `Edmonds blossom`
- Difficulty: `medium`
- Subtype: `General graph matching`
- Status: `solved`
- Solution file: [qbflower.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/matching/qbflower.cpp)

## Why Practice This

This is a good practice problem because it turns a story problem into a clean graph formulation. The important step is realizing that the statement is asking for a minimum edge cover in a general graph, not a bipartite matching problem.

## Recognition Cue

This is a `minimum cover in a general graph` disguise:

- people or objects in the story naturally become vertices
- each available helper or pair becomes one edge
- every vertex must be covered at least once
- the graph is not guaranteed to be bipartite

If the statement asks for the fewest chosen relationships so every vertex is touched, think edge cover before thinking matching implementation.

## Problem-Specific Transformation

We rewrite the story as:

- each girl is one vertex
- each boy who likes two girls is one undirected edge between those girls
- we need the minimum number of chosen edges that cover all vertices

That is exactly minimum edge cover. Since the graph is general, the reusable formula is:

```text
minimum edge cover = number of vertices - maximum matching
```

So the problem reduces to one blossom-based maximum matching computation.

## Core Idea

Treat each girl as a vertex and each boy as an undirected edge connecting the two girls on his list.

We need the smallest number of chosen edges so that every vertex is incident to at least one chosen edge. That is exactly the `minimum edge cover` problem on a general graph.

For any graph without isolated vertices:

`minimum edge cover size = number of vertices - maximum matching size`

So the task becomes:

1. compute a maximum matching in the general graph
2. print `N - matching_size`

Because the graph is not guaranteed to be bipartite, the solution uses Edmonds' blossom algorithm.

## Complexity

- Blossom-based maximum matching is acceptable for the judge limits here
- Final answer: `N - maximum_matching`

## Pitfalls / Judge Notes

The main trap is forgetting the precondition behind the clean graph-theory formula.

- In strict graph theory, an edge cover exists only when there is no isolated vertex.
- The accepted solution uses the direct formula because the judge data for this task supports that edge-cover precondition.

`answer = N - maximum_matching`

## Why The Formula Works

If we already have a maximum matching:

- every matched edge covers two different girls efficiently
- every girl left unmatched needs one more chosen edge to cover her

So the optimal count becomes:

`matched_edges + unmatched_vertices = maximum_matching + (N - 2 * maximum_matching) = N - maximum_matching`

## Reusable Pattern

- Topic page: [Matching](../../../../topics/graphs/matching/README.md)
- Practice ladder: [Matching ladder](README.md)
- Starter route: exact blossom starter -> [edmonds-blossom.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/edmonds-blossom.cpp); direct sibling lane -> [Edmonds Blossom / General Matching](../../../../topics/graphs/general-matching/README.md)
- Notebook refresher: [Graph cheatsheet](../../../../notebook/graph-cheatsheet.md)
- Carry forward: pin down whether the graph is bipartite or general before choosing a matching engine.
- This note adds: the transformation from edge-cover language to the matching formulation used here.

## Solutions

- The graph is a general graph, not a bipartite graph.
- So we cannot use Hopcroft-Karp here.
- The implementation uses Edmonds' blossom algorithm for maximum matching.
- Code: [qbflower.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/matching/qbflower.cpp)
