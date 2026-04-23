# Graph Modeling

Many contest problems become much easier once you stop following the story and instead decide what the vertices, edges, and edge directions should mean.

## Prerequisites

- [Foundations](../../foundations/README.md)

## When To Suspect It

- objects are connected, dependent, or reachable
- the story involves roads, states, transitions, or dependencies
- the same move or relation is repeated many times

## Core Idea

Before choosing an algorithm, answer:

1. what is a vertex?
2. what is an edge?
3. is the graph directed or undirected?
4. is it weighted or unweighted?
5. do I need an explicit graph or an implicit state graph?

Good graph solutions begin with a good model, not with a favorite algorithm.

## Theory / Proof Sketch

The model is correct if:

- every valid object or state becomes a reachable vertex configuration
- every legal move becomes an edge
- every forbidden move is absent

Once that correspondence is right, graph algorithms can solve the original problem without losing information.

## Complexity And Tradeoffs

Representation choices matter:

- adjacency list: default for sparse graphs
- adjacency matrix: only for dense graphs or tiny `n`
- implicit graph: good when generating all edges explicitly is too expensive

## Canonical C++ Pattern

A clean adjacency-list pattern is:

```text
struct Edge { int to; int w; };
vector<vector<Edge>> graph(n);
```

If the graph is unweighted, a simpler `vector<vector<int>>` is often enough.

## Worked Examples

Example 1: cities and roads

- vertices are cities
- edges are roads

Example 2: grid shortest path

- vertices are cells
- edges are moves to neighboring cells

Example 3: word transformations

- vertices are states
- edges connect states reachable by one legal change

## Common Mistakes

- keeping too much story detail inside the model
- using weighted machinery on an unweighted graph
- building a dense representation when the graph is sparse
- forgetting that a state graph may be the real graph

## Practice Ladder

- [Graphs ladder overview](../../../practice/ladders/graphs/README.md)
- [Graph modeling ladder](../../../practice/ladders/graphs/graph-modeling/README.md)

## Go Deeper

- Course: [Stanford CS161](https://cs161-stanford.github.io)
- Reference: [CP-Algorithms](https://cp-algorithms.com/)
- Practice: [ICPC Curriculum](https://curriculum.u.icpc.global/curriculum/)

## Related Topics

- [BFS And DFS](../bfs-dfs/README.md)
- [Shortest Paths](../shortest-paths/README.md)
