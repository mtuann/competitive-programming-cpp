# Graph Modeling

Many contest problems become much easier once you stop following the story and instead decide what the vertices, edges, directions, and weights should mean. Good graph solutions begin with a good model, not with a favorite algorithm.

## Summary

Suspect graph modeling when:

- objects are connected, dependent, reachable, or transformable
- the story involves roads, states, transitions, constraints, or dependencies
- the same move or relation appears repeatedly

What success looks like:

- you can say what a vertex means in one sentence
- you can justify whether edges are directed, undirected, weighted, or implicit
- once the model is set, the algorithm choice becomes much clearer

## Prerequisites

- [Foundations](../../foundations/README.md)

## Core Idea

Before choosing an algorithm, answer:

1. what is a vertex?
2. what is an edge?
3. is the graph directed or undirected?
4. is it weighted or unweighted?
5. do I need an explicit graph or an implicit state graph?

The graph is correct if it preserves the real problem’s legal objects and legal moves without adding fake ones.

## Theory / Proof Sketch

A graph model is valid when:

- every relevant state or object becomes a vertex
- every legal move becomes an edge
- every illegal move is absent

Once that correspondence is right, graph algorithms solve the original problem because path, reachability, or dependency questions in the graph now match the original statement.

This is why graph modeling is often the true problem-solving step, while BFS/DFS/Dijkstra are just the execution step afterward.

## Complexity And Tradeoffs

Representation choices matter:

- adjacency list: default for sparse graphs
- adjacency matrix: only for dense graphs or tiny `n`
- implicit graph: best when generating all edges explicitly is too expensive

Modeling tradeoffs:

- explicit graphs are easier to debug
- implicit state graphs may be necessary when the state space is large but only a small frontier is explored

## Canonical C++ Pattern

Weighted adjacency list:

```cpp
struct Edge {
    int to;
    int w;
};
vector<vector<Edge>> g(n);
```

Unweighted adjacency list:

```cpp
vector<vector<int>> g(n);
```

Useful rule:

- do not put story-heavy names into the graph structure itself
- keep the model small and generic once the translation is clear

## Standard Patterns

### 1. Real-Object Graph

Examples:

- cities and roads
- people and friendships
- tasks and dependencies

### 2. Grid Graph

Examples:

- cells as vertices
- moves to neighboring cells as edges

### 3. State Graph

Examples:

- number transformations
- board configurations
- shortest sequence of legal moves

This is where many “not obviously graph” problems secretly live.

### 4. Bipartite Modeling

Examples:

- workers and jobs
- boys and girls
- left/right partitioned compatibility

Modeling the two sides correctly is what makes matching or flow possible later.

## Worked Examples

### Example 1: cities and roads

Vertices:

- cities

Edges:

- roads

Then connectivity, shortest paths, or MST become natural follow-up questions.

### Example 2: grid shortest path

Vertices:

- grid cells

Edges:

- legal moves to neighboring cells

If every move has equal cost, the right next step is BFS, not Dijkstra.

### Example 3: word transformations

Vertices:

- words or encoded states

Edges:

- one legal transformation

This is a classic example of a state graph: the story may not say “graph”, but the structure is still reachability over transitions.

## Recognition Cues

Strong clues:

- “can move from A to B”
- “depends on”
- “reachable”
- “connected”
- repeated local legal transitions

Graph modeling is often confused with:

- [BFS And DFS](../bfs-dfs/README.md), which come after the graph is modeled
- [Shortest Paths](../shortest-paths/README.md), which only matter once weights and moves are already clear

## Common Mistakes

- carrying too much story detail into the graph
- using weighted machinery on an unweighted graph
- choosing an adjacency matrix for a sparse graph
- missing that the real graph is a state graph rather than an object graph
- solving the wrong graph because edge direction was chosen incorrectly

## Practice Ladder

- [Graphs ladder overview](../../../practice/ladders/graphs/README.md)
- [Graph modeling ladder](../../../practice/ladders/graphs/graph-modeling/README.md)

Suggested order:

1. real-object graphs
2. grids
3. state graphs
4. bipartite modeling

## Go Deeper

- Course: [Stanford CS161](https://cs161-stanford.github.io)
- Reference: [CP-Algorithms](https://cp-algorithms.com/)
- Practice: [ICPC Curriculum](https://curriculum.u.icpc.global/curriculum/)
- Practice: [CSES Graph Algorithms](https://cses.fi/problemset/)

## Related Topics

- [BFS And DFS](../bfs-dfs/README.md)
- [Shortest Paths](../shortest-paths/README.md)
- [Matching](../matching/README.md)
