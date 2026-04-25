# Eulerian Path / Cycle

This topic is about the graph family where the statement is really asking:

```text
can I use every edge exactly once?
```

That question is different from ordinary reachability or shortest paths.

The right object is not:

- one destination
- one minimum distance
- one subtree interval

It is one **trail that consumes every edge exactly once**.

That is why this lane belongs next to traversal and low-link ideas, but still needs its own page.

The core engine is usually **Hierholzer's algorithm** plus the right degree conditions.

## At A Glance

Use this page when:

- the walk must use every edge exactly once
- the statement asks for one route, ordering, or string that consumes all transitions
- the graph is static and edge-usage, not shortest distance, is the bottleneck

Strong contest signals:

- "use every road / teleporter / domino exactly once"
- "find a route that traverses all edges"
- "reconstruct a sequence from overlaps" via a de Bruijn graph
- the hard part is degree feasibility plus one constructive traversal

Strong anti-cues:

- vertices, not edges, are the objects that must be visited once
- the task is shortest path, not edge exhaustion
- the graph changes online
- the right reduction is subtree flattening, SCC, or matching rather than one all-edge trail

What success looks like after this page:

- you can tell path versus cycle conditions apart in both undirected and directed graphs
- you know why `Hierholzer`, not `Fleury`, is the contest default
- you automatically check path length `m + 1` after construction
- you no longer confuse `Eulerian Path / Cycle` with [Euler Tour / Subtree Queries](../euler-tour-subtree/README.md)

## Prerequisites

- [Graph Modeling](../graph-modeling/README.md)
- [BFS And DFS](../bfs-dfs/README.md)

Helpful neighboring topics:

- [Bridges, Articulation Points, And Biconnected Components](../bridges-articulation/README.md) for the "ignore isolated vertices, look at connectivity structure" habit
- [Euler Tour / Subtree Queries](../euler-tour-subtree/README.md) as the main name-clash compare point
- [Strings overview](../../strings/README.md) once the graph is built from overlaps

## Problem Model And Notation

An **Eulerian trail** is a walk that uses every edge exactly once.

An **Eulerian cycle** is an Eulerian trail whose start and end vertices are the same.

We will use:

- `m` = number of edges
- `deg[v]` for undirected degree
- `in[v]`, `out[v]` for directed indegree/outdegree

For construction, we keep one stack of the current partial walk and one answer list built in reverse.

## From Brute Force To The Right Idea

### Brute Force

The naive instinct is:

- start from one vertex
- try edges one by one
- backtrack whenever the remaining graph gets stuck

That explodes immediately because edge-order choices branch too much.

### The Structural Observation

If an Eulerian trail exists, then locally traversable edges are not random.

What matters first is **feasibility**:

- undirected graph: parity of degrees
- directed graph: balance between indegree and outdegree

Once those conditions are right, the constructive problem becomes:

```text
keep following unused edges until you get stuck,
then splice smaller cycles/trails together
```

That is exactly the viewpoint behind Hierholzer's algorithm.

### Why Hierholzer, Not Fleury

`Fleury` says:

- never take a bridge unless you must

That is mathematically fine, but operationally bad for contests because repeatedly testing "is this edge a bridge right now?" is too expensive.

`Hierholzer` avoids that question entirely:

- take any unused outgoing / incident edge
- when a vertex is exhausted, lock it into the answer

That gives the clean `O(n + m)` route.

## Core Invariants And Why They Work

### 1. Undirected Degree Conditions

For an undirected graph:

- Eulerian **cycle**: every non-isolated vertex has even degree
- Eulerian **path but not cycle**: exactly two vertices have odd degree

Why?

Every time a trail enters a non-endpoint vertex, it must also leave it.

So internal usage pairs incident edges two by two.

Only the start and end of an open trail may have one unmatched edge-use.

### 2. Directed Balance Conditions

For a directed graph:

- Eulerian **cycle**: `in[v] = out[v]` for every vertex with nonzero degree
- Eulerian **path from s to t**:
  - `out[s] = in[s] + 1`
  - `in[t] = out[t] + 1`
  - all other vertices satisfy `in[v] = out[v]`

Why?

Each time a directed trail reaches an internal vertex, one incoming edge-use must be matched by one outgoing edge-use.

Only the start may have one extra outgoing edge, and only the end may have one extra incoming edge.

### 3. Ignore Isolated Vertices, But Not Disconnected Edge Components

Vertices with degree `0` do not matter for Eulerian existence.

But all vertices that touch at least one used edge must belong to one connected edge-support:

- one connected component in the undirected case
- one weakly connected component in the directed case

In contest code, the simplest robust check is often:

- build the trail
- verify the answer uses exactly `m` edges, so the vertex list has length `m + 1`

If not, some edge component was left behind.

### 4. Hierholzer's Stack Invariant

Maintain:

- `stack` = current walk still being explored
- `answer` = vertices already finalized in reverse order

At any step:

- if the top vertex still has one unused edge, take it and continue
- otherwise, that vertex can never contribute another unused edge later, so append it to `answer` and pop it

This is the key invariant:

```text
once a vertex is popped from the current stack,
its local unused-edge work is finished forever
```

Because each edge is marked used exactly once, the total work is linear.

### 5. Why The Answer Is Reversed

Vertices are appended when their forward exploration is finished.

So the finished route appears in reverse closure order.

That is why the standard implementation reverses the answer at the end.

## Variant Chooser

### Use Undirected Eulerian Cycle When

- the route must start and end at the same place
- every edge is undirected
- all non-isolated degrees should be even

Clean anchor:

- [Mail Delivery](../../../practice/ladders/graphs/eulerian-path-cycle/maildelivery.md)

### Use Undirected Eulerian Path When

- the route may start and end at different vertices
- exactly two odd-degree vertices are allowed

Typical statement:

- "find one way to use every undirected edge exactly once"

### Use Directed Eulerian Path / Cycle When

- edges are one-way
- `in/out` balance is the real feasibility test
- the statement may force explicit start and end nodes

Important compare point:

- [CSES - Teleporters Path](https://cses.fi/problemset/task/1693)

### Use de Bruijn Graph Modeling When

- the answer is a string or sequence
- adjacent blocks overlap by `k - 1`
- "use each block once" becomes "use each edge once"

Important compare point:

- [CSES - De Bruijn Sequence](https://cses.fi/problemset/task/1692)

## Worked Examples

### Example 1: Undirected Path Versus Cycle

Suppose the graph has edges:

- `1-2`
- `2-3`
- `3-1`
- `2-4`
- `4-1`

Degrees:

- `deg(1) = 3`
- `deg(2) = 3`
- `deg(3) = 2`
- `deg(4) = 2`

This graph cannot have an Eulerian cycle because two vertices are odd.

But it can have an Eulerian path, starting at one odd vertex and ending at the other.

That parity check should happen before the constructive pass.

### Example 2: Directed Path

Suppose:

- `1 -> 2`
- `2 -> 3`
- `3 -> 1`
- `1 -> 4`

Balances:

- `out(1) = 2`, `in(1) = 1`
- `out(4) = 0`, `in(4) = 1`
- all others balanced

So:

- start must be `1`
- end must be `4`

This is the exact shape of an Eulerian path in a directed graph.

### Example 3: Why `m + 1` Matters

If the graph has one valid Eulerian component and one separate extra edge component, local degree checks may still look harmless.

Hierholzer from one start vertex only consumes one component.

So after construction:

- if `path.size() != m + 1`, reject

That one check prevents many missed connectivity bugs.

## Algorithm And Pseudocode

### Hierholzer (Iterative)

```text
choose a valid start vertex
stack = [start]
answer = []

while stack is not empty:
    v = stack.back()
    if v still has an unused edge e = (v, to):
        mark e used
        stack.push(to)
    else:
        answer.push_back(v)
        stack.pop_back()

reverse(answer)
if answer has length m + 1:
    answer is a valid Eulerian trail
else:
    no valid trail exists from the intended edge-support
```

## Complexity And Tradeoffs

- degree checks: `O(n)`
- Hierholzer traversal: `O(n + m)`
- memory: `O(n + m)`

Tradeoff summary:

- `Hierholzer` is the standard exact constructive route
- `Fleury` is mostly educational, not contest-ready
- directed and undirected versions share the same traversal skeleton, but the feasibility conditions differ

## Implementation Notes

- Use **edge ids**, not just neighbor pointers, so multiedges are safe.
- In undirected graphs, one logical edge appears twice in adjacency lists but should be marked used once.
- In directed graphs, if the statement fixes the start/end vertices, verify those exact balance conditions rather than only generic existence.
- `answer.size() == m + 1` is the easiest final correctness guard.
- When `m = 0`, the statement usually needs its own convention; many tasks never test the degenerate case.
- This lane is **not** [Euler Tour / Subtree Queries](../euler-tour-subtree/README.md). The name overlap is historical, but the invariant is completely different.

## Practice Archetypes

- undirected closed walk through all streets -> [Mail Delivery](../../../practice/ladders/graphs/eulerian-path-cycle/maildelivery.md)
- directed path from source to sink using every edge -> [CSES - Teleporters Path](https://cses.fi/problemset/task/1693)
- overlap graph / de Bruijn reconstruction -> [CSES - De Bruijn Sequence](https://cses.fi/problemset/task/1692)
- lexicographically constrained Euler trail -> fence / postman-style variants

## References

- [CP-Algorithms: Finding the Eulerian path in O(M)](https://cp-algorithms.com/graph/euler_path.html)
- [OI Wiki: Euler graph](https://en.oi-wiki.org/graph/euler/)
- [CSES - Mail Delivery](https://cses.fi/problemset/task/1691)
- [CSES - Teleporters Path](https://cses.fi/problemset/task/1693)

## Repo Anchors

- [Eulerian Path / Cycle ladder](../../../practice/ladders/graphs/eulerian-path-cycle/README.md)
- [Eulerian hot sheet](../../../notebook/eulerian-hot-sheet.md)
- [Exact starter template](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/eulerian-path-cycle.cpp)
- [Mail Delivery note](../../../practice/ladders/graphs/eulerian-path-cycle/maildelivery.md)
- Compare points:
  - [BFS And DFS](../bfs-dfs/README.md)
  - [Euler Tour / Subtree Queries](../euler-tour-subtree/README.md)
  - [Graph Modeling](../graph-modeling/README.md)
