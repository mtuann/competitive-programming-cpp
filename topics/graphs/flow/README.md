# Maximum Flow

Maximum flow is the graph tool you reach for when the statement is really asking:

> How much quantity can move through this network without violating capacities?

That quantity may be:

- traffic
- data
- water
- assignments
- edge-disjoint routes
- vertex-disjoint routes
- or the minimum set of edges you must cut to block all routes

So this topic is not just "learn Dinic." It is a **modeling family** built around one object:

- a feasible flow in a capacitated network

and one theorem:

- **max-flow min-cut**

## At A Glance

Reach for maximum flow when:

- capacities live on edges or can be moved onto edges by reduction
- the question is global throughput, not one shortest route
- disjoint paths or bottlenecks appear naturally
- the statement asks for a cut, a blocking set, or "minimum edges to remove"
- an assignment problem has capacities larger than `1`

Strong contest triggers:

- "send as much as possible"
- "maximum number of disjoint paths"
- "minimum number of streets / edges to remove so no path remains"
- "each worker can take up to `k` jobs"
- "each node / edge can be used only so many times"

Strong anti-cues:

- the objective is additive path cost, not throughput
- the graph has no real capacity structure
- the statement is really bipartite matching without capacities, and matching language is cleaner
- the graph is tiny and the real target is min-cost flow, not plain max flow

What success looks like after studying this page:

- you can model capacities, source, and sink cleanly
- you understand residual graphs as the real working object
- you can explain why reverse edges are logically necessary
- you can extract a min cut from the final residual graph
- you know when Dinic is the right default and when the problem is really matching or min-cost flow instead
- you can tell whether the statement wants a flow value, a cut certificate, or a reduction target such as matching

## Prerequisites

- [Graph Modeling](../graph-modeling/README.md)
- [Matching](../matching/README.md)
- [Shortest Paths](../shortest-paths/README.md)

Helpful neighboring topics:

- [Min-Cost Flow](../min-cost-flow/README.md)
- [Graph Cheatsheet](../../../notebook/graph-cheatsheet.md)

## Problem Model And Notation

A flow network consists of:

- a directed graph $G = (V, E)$
- a source $s$
- a sink $t$
- a capacity function $c(u, v) \ge 0$ on edges

A flow is a function $f(u, v)$ satisfying:

1. **capacity constraints**

$$
0 \le f(u, v) \le c(u, v)
$$

2. **flow conservation** at every internal vertex $v \notin \{s, t\}$

$$
\sum_{(u, v) \in E} f(u, v) = \sum_{(v, w) \in E} f(v, w)
$$

The value of the flow is the net amount leaving the source:

$$
|f| = \sum_{(s, v) \in E} f(s, v) - \sum_{(v, s) \in E} f(v, s)
$$

An $s$-$t$ cut is a partition $(S, T)$ of $V$ such that:

- $s \in S$
- $t \in T$

Its capacity is:

$$
\mathrm{cap}(S, T) = \sum_{u \in S,\ v \in T} c(u, v)
$$

The whole topic turns on the relationship between:

- a feasible flow
- a residual graph
- an $s$-$t$ cut

## From Brute Force To The Right Idea

### Brute Force

The naive story is:

- pick one path from `s` to `t`
- push as much as possible
- pick another path
- keep going

That sounds plausible, but it misses the key difficulty:

- sending flow along one path can block or enable better choices later

So path-by-path greediness is the wrong mental model.

### The Real Compression: Residual Choices

The correct state is not:

- "which paths have I used?"

It is:

- "after the current flow, what additional movement is still possible?"

That is exactly what the **residual graph** encodes.

For each original edge $(u, v)$:

- the forward residual capacity is $c(u, v) - f(u, v)$
- the backward residual capacity is $f(u, v)$

So the residual graph says two things at once:

- how much more flow can still be sent forward
- how much previously sent flow can be undone

That second bullet is the whole reason reverse edges exist.

Without them, you could never repair an earlier bad routing choice.

### Augmenting Paths Are Local Improvements

An augmenting path in the residual graph is an `s -> t` path with positive residual capacity on every edge.

If such a path exists, you can increase the flow value by the bottleneck capacity:

$$
\Delta = \min_{(u, v) \in P} c_f(u, v)
$$

and update the flow along that path.

So the first deep theorem of the topic is:

- if an augmenting path exists, the current flow is not maximum

The surprising converse is also true:

- if no augmenting path exists, the current flow is maximum

That is the augmenting-path theorem, and it is the gateway to max-flow min-cut.

## Core Invariant And Why It Works

### 1. Residual Graph Is The Working Object

The residual graph $G_f$ contains:

- every forward edge with residual capacity $c(u, v) - f(u, v) > 0$
- every backward edge with residual capacity $f(u, v) > 0$

Interpretation:

- a forward residual edge means "you may still send more"
- a backward residual edge means "you may cancel some flow already sent"

That is why every serious implementation stores forward and reverse edges together.

### 2. No Augmenting Path Means Max Flow

Let $A$ be the set of vertices reachable from `s` in the final residual graph.

If `t` is not reachable, then:

- every edge from $A$ to $V \setminus A$ is saturated
- every edge from $V \setminus A$ back to $A$ carries zero flow

So the flow value equals the cut capacity:

$$
|f| = \mathrm{cap}(A, V \setminus A)
$$

By weak duality, no flow can ever exceed any cut capacity. Therefore:

- this flow is maximum
- this cut is minimum

This is the clean contest proof of max-flow min-cut:

1. no residual path to `t`
2. reachable set from `s` defines a cut
3. that cut is tight

### 3. Integrality Is Why Contest Reductions Work So Well

If all capacities are integers, augmenting-path algorithms can keep every flow value integral.

That matters because many reductions want discrete objects:

- number of disjoint paths
- number of assignments
- number of chosen edges

So max flow is not only an optimization tool. It is also a way to force combinatorial structure through integrality.

### 4. Dinic's Invariant

Dinic organizes the residual search into phases.

Each phase does:

1. BFS from `s` to build the **level graph**
2. DFS pushes a **blocking flow** inside that level graph

The level graph keeps only residual edges that move from level `d` to level `d + 1`.

Why this helps:

- every augmenting path in the level graph is currently shortest in edge count
- once the blocking flow is exhausted, every shortest augmenting path has been killed
- so the residual distance from `s` to `t` strictly increases before the next phase

That gives the high-level progress measure behind Dinic.

You do not need the sharpest asymptotic proof for most contests. The mental model to keep is:

- BFS isolates the current shortest augmenting-path layer structure
- DFS drains all useful flow through that structure before rebuilding

## Complexity And Tradeoffs

Typical contest-level view:

| Tool | Best use | Core idea | Main tradeoff |
| --- | --- | --- | --- |
| Ford-Fulkerson | conceptual starting point | augment any residual path | can be too slow or depend badly on path choice |
| Edmonds-Karp | small graphs, proof-friendly baseline | always augment along shortest residual path | simpler analysis, slower in practice |
| Dinic | standard contest default | level graph + blocking flow | more code, but usually the right balance |
| Push-relabel | heavy-duty max-flow engineering | local excess pushing | excellent in practice, but less common as first contest implementation |

Repo default:

- **Dinic**

Why Dinic is the first implementation to internalize:

- it is fast enough for a wide range of contest problems
- the BFS + DFS structure is still teachable
- it works beautifully with modeling patterns like node splitting and cut extraction

## Variant Chooser

| Situation | Best first model | Why it fits | Main danger |
| --- | --- | --- | --- |
| plain throughput from `s` to `t` | max flow | direct network interpretation | forgetting reverse edges |
| edge-disjoint paths | max flow with unit capacities | integrality gives path count | using plain graph search greedily |
| vertex-disjoint paths | node splitting + max flow | vertex capacities become edge capacities | splitting source/sink incorrectly |
| blocking / removal certificate | max flow then residual cut extraction | theorem gives the certificate directly | printing residual edges instead of original edges |
| simple one-to-one bipartite compatibility | matching first | the statement is already a matching model | overbuilding a full flow reduction too early |
| bipartite matching with capacities | flow reduction | source-left-right-sink structure is natural | using plain matching when capacities exceed `1` |
| minimum cost under capacities | min-cost flow | cost matters, not just amount | using plain max flow and losing the objective |
| many pairwise min-cuts | Gomory-Hu on top of max flow | compresses all pair min-cuts into one tree | thinking repeated independent flow is the only route |

Two quick reject rules:

- if the objective is additive path cost, think shortest paths before flow
- if the statement is simple one-to-one bipartite matching, matching language is often cleaner than full flow language

## Worked Examples

### Example 1: Why Reverse Edges Matter

Suppose your first augmenting path sends flow through an edge that later should have been used differently.

Without backward residual edges:

- that choice would be permanent

With backward residual edges:

- a future augmenting path can partially undo the old routing
- then reroute that amount through a better structure

This is the deepest conceptual difference between:

- "greedily pick paths"
- and "maintain a residual network"

### Example 2: `FFLOW` Is Plain Throughput Modeling

In [FFLOW](../../../practice/ladders/graphs/flow/fflow.md), the statement is really:

- maximize how much quantity can go from `1` to `N`
- every connection has a capacity

That is already the max-flow problem.

The only modeling wrinkle is that the graph is undirected in the statement, so each undirected edge becomes:

- one directed capacity edge each way

After that, nothing conceptually new remains.

This is the right first reminder that:

- flow problems are often solved at modeling time
- Dinic is only the engine

### Example 3: Node Splitting Turns Vertex Limits Into Edge Limits

Suppose every internal vertex may be used at most once.

Flow engines know how to enforce edge capacities, not vertex capacities directly.

So split each original vertex `v` into:

- `vin`
- `vout`

and add the internal edge:

$$
vin \to vout
$$

with capacity equal to the allowed usage of `v`.

Then:

- incoming edges point to `vin`
- outgoing edges leave from `vout`

This is one of the highest-value reductions in the whole topic.

In practice, always pause for one more question:

- are `s` and `t` also capacity-limited, or only the internal vertices?

That small semantic check is where many otherwise-correct reductions go wrong.

### Example 4: `Police Chase` Is Really A Min-Cut Certificate Problem

In [Police Chase](../../../practice/ladders/graphs/flow/policechase.md), the object you finally print is not:

- an augmenting path decomposition

It is:

- a minimum cut certificate

The flow computation gives the value.

Then one DFS/BFS from `s` in the final residual graph gives the reachable side `A`.

Every original edge crossing from `A` to `V \setminus A` is part of a valid minimum cut.

This example is perfect for internalizing:

- max flow gives the number
- the residual graph gives the witness

### Example 5: Matching Is Sometimes Flow In Disguise

For bipartite matching, you can build:

- `s -> left vertices`
- left-to-right compatibility edges
- `right vertices -> t`

with unit capacities.

Then an integral max flow corresponds to a matching.

This is extremely useful conceptually, but in contest practice:

- if the problem is plain bipartite matching, use matching language first
- if capacities or extra supply constraints appear, flow often becomes the cleaner model

That is the right boundary to remember:

- matching is often the cleaner first story
- flow is the more general capacity language sitting behind it

### Example 6: Gomory-Hu Is "Many Cuts" On Top Of Max Flow

[MCQUERY](../../../practice/ladders/graphs/flow/mcquery.md) is not teaching a new base flow engine.

It is teaching a meta-pattern:

- repeated max-flow computations can compress many pairwise min-cut answers into one cut tree

So flow is not only a terminal tool. It can be a subroutine inside a larger structure.

## Algorithm And Pseudocode

Repo starter template:

- [dinic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dinic.cpp)

### Dinic High-Level Skeleton

```text
flow = 0
while BFS builds a level graph from s to t:
    reset current-edge pointers
    while DFS can push positive flow through the level graph:
        add pushed amount to flow
return flow
```

### Level-Graph BFS

```text
level[*] = -1
level[s] = 0
queue q = [s]

while q not empty:
    u = pop front
    for each residual edge (u, v) with cap > 0:
        if level[v] == -1:
            level[v] = level[u] + 1
            push v

return level[t] != -1
```

### Blocking-Flow DFS

```text
dfs(u, pushed):
    if u == t or pushed == 0:
        return pushed

    iterate edges from ptr[u] onward:
        choose residual edge (u, v) with:
            cap > 0
            level[v] = level[u] + 1
        try = dfs(v, min(pushed, cap))
        if try > 0:
            decrease forward residual capacity
            increase reverse residual capacity
            return try

    return 0
```

This `ptr[u]` optimization is the practical difference between:

- re-scanning dead edges constantly
- and treating each phase as near-linear in the level graph size

## Implementation Notes

### 1. Reverse Edges Are Not Optional

Every added edge must know its reverse partner.

The repo template stores:

- `to`
- `rev`
- `cap`

That `rev` index is the mechanical way to update residual capacities in both directions.

### 2. Undirected Capacity Statements Still Become Directed Residual Edges

For an undirected edge with capacity `c`, the common contest model is:

- add directed edge `u -> v` with capacity `c`
- add directed edge `v -> u` with capacity `c`

Each of those directed edges still gets its own reverse residual edge in the implementation.

So "undirected edge" and "reverse residual edge" are different concepts. Mixing them up is one of the easiest flow bugs.

### 3. Node Splitting Usually Excludes Special Vertices

If the source or sink should not be capacity-limited in the same way as internal nodes:

- do not blindly split them with the same rule

Always read the semantic constraint, not just the syntax of the reduction.

### 4. Long Long Is The Safe Default

Contest capacities often fit in `int`, but total flow may not.

Safe habit:

- store capacities and total flow in `long long`

### 5. Residual Reachability Happens After Max Flow Finishes

For min-cut certificate tasks, the final DFS/BFS is on the residual graph **after** the algorithm has terminated.

Doing that traversal early gives meaningless cut information.

### 6. Parallel Edges Are Usually Fine

Most Dinic implementations handle parallel edges naturally.

Do not over-normalize the graph unless the problem demands it.

### 7. Multi-Source Or Multi-Sink Usually Means Super Nodes

If the statement gives:

- several suppliers
- several consumers
- multiple allowed starts or exits

the usual reduction is:

- add a super source connected to every real source
- add a super sink connected from every real sink

with capacities that match the model.

This is often cleaner than trying to special-case the base engine.

### 8. Cut Extraction Must Be Read On The Original Graph

After max flow finishes:

- run reachability on the **residual graph**
- but interpret the answer on the **original graph**

For a min-cut certificate, the interesting edges are original edges crossing from the reachable side to the unreachable side.

Printing residual edges directly is almost always wrong.

### 9. Max Flow Is Often Only The First Layer

Many contest tasks continue after the base engine:

- read a cut
- reconstruct chosen edges
- build a Gomory-Hu tree
- add costs and move to min-cost flow

So after finding a valid max-flow reduction, always ask:

- is the theorem asking me for the value, the certificate, or a richer structure on top?

This one question often determines whether you should stop at Dinic or keep going into:

- cut extraction
- decomposition
- or min-cost / Gomory-Hu style extensions

## Beyond Plain Max Flow

This page is intentionally centered on the core contest pattern:

- single-source, single-sink maximum flow
- residual graph
- Dinic as the default engine
- min-cut extraction and modeling reductions

Important next-layer topics include:

- [Min-Cost Flow](../min-cost-flow/README.md)
- lower/upper bounds and feasible circulation
- push-relabel implementations
- Gomory-Hu trees for many pairwise cuts

Those are valuable, but the right study order is:

1. internalize residual graphs and max-flow min-cut first
2. make node splitting and cut extraction automatic
3. then move to richer flow families

## Practice Archetypes

The most common max-flow-shaped tasks are:

- **plain throughput**
- **edge-disjoint path count**
- **vertex-disjoint path count**
- **minimum cut certificate**
- **matching with capacities**
- **many cuts on top of one base flow engine**

The strongest smell is:

- global routing under capacities
- plus a statement that sounds more like "how much can pass" or "what minimum barrier blocks everything" than like one optimal path

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Primary / course:

- [Stanford CS161 Lecture 17: Max Flow, Ford-Fulkerson Algorithm](https://web.stanford.edu/class/archive/cs/cs161/cs161.1172/CS161Lecture17.pdf)
- [CMU 15-451 Lecture Notes: Introduction to Max Flow](https://www.cs.cmu.edu/~15451-f20/LectureNotes/flowIntro.pdf)
- [CMU 15-451 Lecture Notes: Dinic's Algorithm](https://www.cs.cmu.edu/afs/cs/academic/class/15451-f14/www/lectures/lec11/dinic.pdf)
- [Princeton / Kleinberg-Tardos Network Flow I](https://www.cs.princeton.edu/~wayne/kleinberg-tardos/pdf/07NetworkFlowI.pdf)

Reference:

- [CP-Algorithms: Dinic](https://cp-algorithms.com/graph/dinic.html)

Practice:

- [CSES Graph Algorithms](https://cses.fi/problemset/)

Repo anchors:

- practice ladder: [Flow ladder](../../../practice/ladders/graphs/flow/README.md)
- practice note: [FFLOW](../../../practice/ladders/graphs/flow/fflow.md)
- practice note: [Police Chase](../../../practice/ladders/graphs/flow/policechase.md)
- practice note: [MCQUERY](../../../practice/ladders/graphs/flow/mcquery.md)
- practice note: [MINCOST](../../../practice/ladders/graphs/flow/mincost.md)
- starter template: [dinic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/dinic.cpp)
- notebook refresher: [Graph cheatsheet](../../../notebook/graph-cheatsheet.md)

## Related Topics

- [Matching](../matching/README.md)
- [Shortest Paths](../shortest-paths/README.md)
- [Min-Cost Flow](../min-cost-flow/README.md)
- [Graph Modeling](../graph-modeling/README.md)
