# Topological Sort And SCC

This topic is about how to simplify a directed graph until its structure becomes usable.

There are two core tools:

- **topological sort** when the graph is already a DAG
- **strongly connected components (SCC)** when cycles exist and must be compressed first

That is why this topic should not be learned as "one more DFS trick." The real skill is:

- detect whether the graph is already acyclic
- if not, compress each mutually reachable block into one component
- solve the actual problem on the resulting DAG

So this page is a **family / chooser page**:

- one branch handles DAGs directly
- the other branch turns a general directed graph into a DAG first

## At A Glance

Reach for this topic when:

- edges mean "must come before"
- the graph is directed and cycles matter structurally
- you need to process states in dependency order
- the right answer depends on grouping mutually reachable vertices
- DAG DP feels almost right, but cycles are in the way

Strong contest triggers:

- prerequisites
- scheduling with dependencies
- "if there is a cycle, print impossible"
- "compress cycles first"
- "all vertices in the same cycle-cluster behave together"

Strong anti-cues:

- the graph is undirected
- the question is really about shortest paths or capacities
- the graph is a tree and the structure is path / ancestor based
- you are using SCC only because DFS appears in the implementation

What success looks like after studying this page:

- you can tell whether topological sort alone is enough
- you can explain why SCC condensation is always a DAG
- you know when Kahn is cleaner than DFS finishing-order toposort
- you know when Kosaraju is cleaner than Tarjan for contest implementation
- you naturally switch from "graph with cycles" to "DAG of components"
- you can tell whether the task wants an order on vertices, an SCC partition, or a DAG on components

## Prerequisites

- [BFS And DFS](../bfs-dfs/README.md)
- [Graph Modeling](../graph-modeling/README.md)

Helpful neighboring topics:

- [Shortest Paths](../shortest-paths/README.md)
- [Graph Cheatsheet](../../../notebook/graph-cheatsheet.md)

## Problem Model And Notation

Let:

- $G = (V, E)$ be a directed graph
- an edge $u \to v$ mean "u must happen before v" or "u can transition to v"

A **topological order** is a linear ordering of the vertices such that every directed edge goes forward in the order.

A **strongly connected component** is a maximal set of vertices $C$ such that:

- every vertex in $C$ reaches every other vertex in $C$

The **condensation graph** of $G$ is formed by:

- contracting each SCC into one node
- keeping edges between distinct components

That condensation graph is the canonical simplified form of a directed graph.

## From Brute Force To The Right Idea

### Brute Force

The naive approach is often:

- try to process vertices one by one in some convenient order
- hope dependencies line up

This fails immediately when:

- the chosen order violates an edge direction
- or cycles make "before / after" impossible at the vertex level

### The Real Compression

There are only two structurally meaningful outcomes:

1. the graph is already a DAG
2. it is not, but SCC compression turns it into a DAG

That means the real first question is:

> Can I solve directly on vertices, or must I first solve on components?

This single question prevents a huge number of wrong graph DP attempts.

### Why DAGs Are Easy

If the graph is acyclic, there exists an order where every edge points forward.

Once you have such an order:

- DP becomes natural
- cycle detection becomes trivial
- reachability and counting often simplify dramatically

### Why SCC Compression Is The Right Repair

If vertices lie in the same SCC, then from the perspective of reachability structure:

- they are mutually entangled
- no linear order between them can respect all directions

So the correct compression is:

- treat the whole SCC as one meta-vertex

After that, the remaining structure between components is acyclic.

This is the central mental model of the topic:

- **compress first, solve later**

## Core Invariant And Why It Works

### 1. Topological Sort Exists Exactly For DAGs

If the graph has a directed cycle, no topological order can exist.

Why?

Because along a cycle:

$$
v_0 \prec v_1 \prec \cdots \prec v_k \prec v_0
$$

would force some vertex to come before itself.

Conversely, every DAG has at least one topological order.

That is the theorem behind both major topological-sort implementations.

### 2. Kahn's Invariant

Kahn's algorithm repeatedly removes vertices of indegree `0`.

Invariant:

- every vertex currently in the queue has no remaining prerequisites in the not-yet-removed subgraph

Why this works:

- in a DAG, some indegree-`0` vertex always exists
- removing it cannot create a new cycle
- the reduced graph is still a DAG

So if Kahn processes fewer than `n` vertices:

- the remaining subgraph has no indegree-`0` vertex
- which implies a directed cycle remains

This makes Kahn both:

- a topological-sort algorithm
- a cycle detector

### 3. DFS Finishing Order For Toposort

If the graph is a DAG, ordering vertices by decreasing DFS finish time also gives a topological order.

Why?

- DFS finishes a vertex only after finishing everything reachable from it
- in a DAG, there is no back edge that would invalidate the ordering

This method is elegant, but in contest practice:

- Kahn is often clearer when the statement itself is phrased in terms of prerequisites or impossibility

### 4. SCC Condensation Is Always A DAG

Suppose the condensation graph had a directed cycle among components:

$$
C_1 \to C_2 \to \cdots \to C_k \to C_1
$$

Then every component on that cycle could reach every other one.

But that means all those vertices were mutually reachable already, so they should have formed one SCC instead of many.

Contradiction.

Therefore:

- the SCC condensation graph is always a DAG

This is the theorem that licenses:

- DAG DP after SCC compression
- topological reasoning on components
- counting / optimization on the condensed graph

### 5. Kosaraju's Key Insight

Kosaraju uses two passes:

1. DFS on the original graph to record finish order
2. DFS on the reversed graph in decreasing finish order

Why the second pass isolates one SCC at a time:

- the finish order makes source components in the condensation DAG finish late
- reversing edges turns those source components into sink components
- DFS from such a vertex in the reversed graph cannot leak into another unassigned SCC

This is one of those algorithms that looks magical until you see the condensation-DAG viewpoint. After that, it becomes very clean.

### 6. Tarjan's Invariant

Tarjan keeps:

- DFS discovery times
- low-link values
- a stack of active vertices

Invariant:

- when a DFS root has `low[u] == tin[u]`, it is the root of one SCC in the current DFS stack

Tarjan is one-pass and elegant, but it carries more invariants at once.

For many contest settings:

- Kosaraju is easier to teach and debug
- Tarjan is a worthy second implementation once SCC logic is comfortable

## Complexity And Tradeoffs

Let `n = |V|` and `m = |E|`.

Typical bounds:

- Kahn topological sort: `O(n + m)`
- DFS finishing-order topological sort: `O(n + m)`
- Kosaraju SCC: `O(n + m)`
- Tarjan SCC: `O(n + m)`

Practical tradeoffs:

| Tool | Best when | Time | Main tradeoff |
| --- | --- | --- | --- |
| Kahn | you want a topological order or a clean cycle test | linear | needs indegree array, only for DAG logic |
| DFS toposort | DFS is already the natural framing | linear | easiest to misuse if cycles are not handled carefully |
| Kosaraju | you want SCCs with a transparent proof idea | linear | needs reverse graph and two passes |
| Tarjan | you want one-pass SCC decomposition | linear | more delicate invariants |

Repo default:

- **Kahn** for toposort
- **Kosaraju** for SCC

Why:

- both are easy to explain from first principles
- both map cleanly onto the templates in this repo

## Variant Chooser

| Situation | Best first tool | Why it fits | Main danger |
| --- | --- | --- | --- |
| DAG order or "print any valid schedule" | Kahn | indegree-`0` means ready now | forgetting cycle check |
| DAG order with lexicographically smallest requirement | Kahn + priority queue | preserves the same invariant with different tie-breaking | using plain queue and missing the ordering requirement |
| detect whether a directed cycle exists | Kahn or DFS cycle logic | failed full order is a cycle witness | assuming queue order itself proves correctness |
| graph has cycles but you want DAG DP after compression | SCC first | condensation DAG is the real object | doing DP on original cyclic graph |
| you need explicit SCC ids and a clean proof story | Kosaraju | two-pass structure is transparent | building reverse graph incorrectly |
| you want one-pass SCC | Tarjan | discovery/low-link stack invariant | harder to debug under pressure |

Two quick reject rules:

- if the graph is guaranteed to be a tree, do not reach for SCC/toposort
- if the graph is weighted and the objective is path cost, think shortest paths first

## Worked Examples

### Example 1: `Course Schedule` Is Pure Kahn

In [Course Schedule](../../../practice/ladders/graphs/scc-toposort/courseschedule.md), each edge means:

- take `a` before `b`

So the graph already is the dependency model.

Kahn works because:

- indegree `0` means "currently no remaining prerequisite"

If the final order contains fewer than `n` vertices:

- some cycle remains
- so the schedule is impossible

This is the cleanest starter problem in the whole topic.

### Example 2: Failed Toposort Is A Structural Statement

Suppose Kahn gets stuck with vertices still unprocessed.

That is not a queue accident.

It means:

- every remaining vertex still has an incoming edge from another remaining vertex

So the remaining subgraph contains a directed cycle.

This is why "answer size < n" is not a heuristic. It is the actual theorem boundary.

### Example 3: SCC Compression Followed By DAG DP

Imagine a directed graph where each vertex has some weight, and you want the maximum score collectable along a path.

If cycles exist, plain DAG DP is invalid on the original graph.

The right move is:

1. compute SCCs
2. sum weights inside each SCC
3. build the condensation DAG
4. run DP on that DAG

This is the core pattern behind problems like `Coin Collector`:

- the true state graph is the DAG of components, not the original graph

That sentence is the whole repair pattern:

- if vertex-level DAG DP fails because cycles are real, move the DP to component level

### Example 4: Why Condensation Helps Even When You Only Care About Reachability

Suppose you only want to know which regions can eventually influence which other regions.

Inside one SCC:

- the vertices are mutually reachable already

So storing reachability at the vertex level is wasting structure.

SCC compression gives the minimal DAG that still preserves the one-way dependency shape between strongly connected regions.

### Example 5: Kosaraju's Second Pass Is Not Arbitrary

The ordering from the first DFS is designed so that in the reversed graph:

- when you start a new second-pass DFS, you peel off exactly one SCC

This feels magical until you think in terms of source/sink components in the condensation DAG.

That viewpoint is the real proof.

## Algorithm And Pseudocode

Repo starter templates:

- [toposort-kahn.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/toposort-kahn.cpp)
- [scc-kosaraju.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/scc-kosaraju.cpp)

### Kahn Topological Sort

```text
compute indegree of every vertex
push all indegree-0 vertices into queue
order = []

while queue not empty:
    u = pop front
    append u to order
    for each edge u -> v:
        indegree[v] -= 1
        if indegree[v] == 0:
            push v

if |order| < n:
    cycle exists
else:
    order is a valid topological ordering
```

### Kosaraju SCC

```text
build reverse graph rg
used[*] = false
order = []

for each vertex u:
    if not used[u]:
        dfs_order(u) on original graph
        append u when dfs finishes

reverse(order)
comp[*] = -1
cid = 0

for u in order:
    if comp[u] == -1:
        dfs_component(u) on reverse graph
        assign all reached vertices to cid
        cid += 1
```

After SCC ids are known:

```text
for each original edge u -> v:
    if comp[u] != comp[v]:
        add edge comp[u] -> comp[v] to condensation DAG
```

## Implementation Notes

### 1. Toposort Is Only Meaningful On DAGs

If the graph may have cycles, a produced DFS order is not automatically a valid topological order.

Always keep the theorem boundary explicit.

In practice, this means:

- use Kahn when the statement naturally asks for "possible or impossible"
- or add explicit DFS cycle detection if you prefer the finishing-order route

### 2. Kahn's Queue Order Is Not Unique

Different queue tie-breaking gives different valid topological orders.

That is fine unless the problem asks for:

- lexicographically smallest order
- some special canonical ordering

Then the queue container may need to change.

### 3. Reverse Graph Construction Is Easy To Get Wrong

For Kosaraju:

- original edge: `u -> v`
- reverse edge: `v -> u`

This sounds trivial, but one mistaken push is enough to destroy the whole decomposition.

### 4. SCC Id Numbers Usually Have No Intrinsic Meaning

Do not assume:

- lower component id means earlier in DAG order
- or higher component id means "more important"

If you need an order on components:

- explicitly build the condensation DAG
- and topologically sort that DAG if needed

This is especially important when component ids come from Kosaraju or Tarjan:

- the ids are labels
- the condensation DAG is the structure

### 5. Condensation DAG Often Needs Deduplication Only For Performance

If multiple original edges connect the same pair of components, the condensation DAG may get parallel edges.

Correctness is usually still fine.

Deduplicate only when:

- indegrees
- DP transitions
- or memory

benefit from it.

### 6. SCC-Then-DP Is A Default Repair Pattern

If you catch yourself trying to run DAG DP on a cyclic directed graph, pause and ask:

- should I compress SCCs first?

This one question saves a large number of contest mistakes.

### 7. Tarjan Is A Second-Step Implementation, Not A Required First One

Tarjan is elegant, but if the proof story or debugging feels slippery:

- use Kosaraju first

The important thing is to own the structural idea, not to memorize the most compact code earliest.

## Beyond The Core Family

This page is intentionally centered on the core contest tools:

- Kahn topological sort
- DFS finishing-order toposort
- Kosaraju SCC
- Tarjan SCC
- condensation DAG reasoning

Important next-layer directions include:

- 2-SAT via implication graph SCCs
- DP and counting on condensation DAGs
- dominator-style directed-graph structure
- dynamic or online SCC variants

The right study order is:

1. master DAG ordering
2. master SCC compression
3. then build specialized reductions on top

## Practice Archetypes

The most common tasks in this family are:

- **print a valid dependency order**
- **detect a directed cycle by failed scheduling**
- **compress SCCs first, then run DAG DP**
- **group mutually reachable vertices**
- **reason about the one-way structure between SCCs**

The strongest smell is:

- a directed graph
- plus a statement where "what can come before what" matters more than numeric path cost

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Primary / course:

- [MIT 6.006 Lecture 14: DFS, Topological Sort](https://live.ocw.mit.edu/courses/6-006-introduction-to-algorithms-fall-2011/resources/lecture-14-depth-first-search-dfs-topological-sort/)
- [Stanford CS161 Lecture 10: Finding Strongly Connected Components](https://web.stanford.edu/class/archive/cs/cs161/cs161.1176/Slides/Lecture10.pdf)
- [Cornell CS312 Lecture 15: Topological Sort](https://www.cs.cornell.edu/courses/cs312/2004fa/lectures/lecture15.htm)

Reference:

- [CP-Algorithms: Topological Sorting](https://cp-algorithms.com/graph/topological-sort.html)
- [CP-Algorithms: Strongly Connected Components and Condensation Graph](https://cp-algorithms.com/graph/strongly-connected-components.html)

Practice:

- [CSES Graph Algorithms](https://cses.fi/problemset/)

Repo anchors:

- practice ladder: [SCC and toposort ladder](../../../practice/ladders/graphs/scc-toposort/README.md)
- practice note: [Course Schedule](../../../practice/ladders/graphs/scc-toposort/courseschedule.md)
- starter template: [toposort-kahn.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/toposort-kahn.cpp)
- starter template: [scc-kosaraju.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/scc-kosaraju.cpp)
- notebook refresher: [Graph cheatsheet](../../../notebook/graph-cheatsheet.md)

## Related Topics

- [BFS And DFS](../bfs-dfs/README.md)
- [Graph Modeling](../graph-modeling/README.md)
- [Shortest Paths](../shortest-paths/README.md)
