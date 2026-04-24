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

## Key Idea

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

The main trap is mixing up the clean graph-theory statement with the judge-facing output rule.

- In strict graph theory, an edge cover exists only when there is no isolated vertex.
- This judge does not ask for a special impossible-case output, so the accepted submission uses the direct formula:

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
- Starter template: [Template library overview](../../../../template-library.md)
- Notebook refresher: [Graph cheatsheet](../../../../notebook/graph-cheatsheet.md)
- Carry forward: pin down whether the graph is bipartite or general before choosing a matching engine.
- This note adds: the transformation from edge-cover language to the matching formulation used here.

## Solutions

- The graph is a general graph, not a bipartite graph.
- So we cannot use Hopcroft-Karp here.
- The implementation uses Edmonds' blossom algorithm for maximum matching.
- Code: [qbflower.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/matching/qbflower.cpp)
