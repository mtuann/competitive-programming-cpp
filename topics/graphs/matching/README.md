# Matching

Matching is the graph-theoretic language for:

- pairing things
- with exclusivity
- where each item may be used at most once

That is why it appears so often in contest problems about:

- jobs and workers
- students and projects
- rows and columns
- pairings, covers, and compatibility choices

This page teaches matching in the right order:

1. **bipartite modeling first**
2. **augmenting paths as the core theorem**
3. **Hopcroft-Karp as the serious contest engine**
4. **general matching / blossom only as the boundary, not the starting point**

## At A Glance

Reach for matching when:

- each selected edge consumes both endpoints
- you want as many compatible pairs as possible
- the graph naturally splits into two sides, or you need to check whether it does
- "at most one assignment per object" is the real constraint

Strong contest triggers:

- "assign people to jobs"
- "pair boys and girls / tasks and machines / left objects and right objects"
- "maximum number of non-conflicting assignments"
- "every chosen relationship uses each endpoint at most once"
- "the statement hides a compatibility graph"

Strong anti-cues:

- capacities larger than `1` are essential, not just convenient
- the graph is general and odd cycles matter
- the task is about covering every vertex, not just pairing as many as possible
- the real structure is flow or min-cost flow, not plain cardinality matching

What success looks like after studying this page:

- you check bipartiteness before choosing the algorithm
- you can define alternating path and augmenting path clearly
- you know why "no augmenting path" means the matching is maximum
- you can explain when Kuhn is enough and when Hopcroft-Karp is the right upgrade
- you know that blossom is the next world, not the first one

## Prerequisites

- [Graph Modeling](../graph-modeling/README.md)
- [BFS And DFS](../bfs-dfs/README.md)

Helpful neighboring topics:

- [Maximum Flow](../flow/README.md)
- [Min-Cost Flow](../min-cost-flow/README.md)

## Bipartite-First Modeling Checklist

Before choosing an algorithm, write down four things explicitly:

1. what are the left vertices?
2. what are the right vertices?
3. what does one edge mean?
4. why may each endpoint be used at most once?

If you can answer those four questions cleanly, you probably have a bipartite matching model.

Common anti-cues:

- one left vertex may need multiple assignments
- one right vertex has capacity larger than `1`
- the graph is not naturally split into two parts
- the objective is weighted cost, not just cardinality

Those are signals that the real problem may be:

- flow / min-cost flow
- weighted assignment
- or general matching instead of bipartite matching

## Problem Model And Notation

A **matching** `M` in a graph is a set of edges such that no two edges share an endpoint.

In a bipartite graph:

$$
G = (L \cup R, E),
$$

every edge goes between the left part `L` and the right part `R`.

We call a vertex:

- **matched** if it is incident to an edge in `M`
- **free** or **exposed** otherwise

With respect to a matching `M`:

- an **alternating path** is a path whose edges alternate between edges outside `M` and inside `M`
- an **augmenting path** is an alternating path whose two endpoints are free

The key operation is augmentation:

$$
M' = M \oplus P,
$$

where `P` is an augmenting path and `\oplus` is symmetric difference.

In words:

- edges of `P` that were unmatched become matched
- edges of `P` that were matched become unmatched

The result is a larger matching.

## From Brute Force To The Right Idea

### Brute Force

For a small graph, you could try:

- enumerate subsets of edges
- keep only those that form a matching
- choose the largest one

This is obviously impossible at contest sizes.

### The Structural Observation

A matching is not just "some chosen edges". It has local structure:

- each vertex is touched at most once

So if the current matching is not optimal, the improvement must also have structure.

That structure is an augmenting path.

### Why Augmenting Paths Are The Right Improvement

Suppose we already have a matching `M`.

If we can find a path:

- starting at a free left vertex
- ending at a free right vertex
- alternating unmatched, matched, unmatched, matched, ...

then flipping the matched/unmatched status along that path:

- preserves the matching property
- increases the number of matched edges by exactly one

That turns "how do I improve the matching?" into:

- find augmenting paths repeatedly

This is the backbone of all standard matching algorithms.

### Why Bipartite Comes First

In bipartite graphs, augmenting paths behave cleanly:

- they always alternate across the two sides
- BFS layering makes shortest augmenting paths easy to reason about
- no odd cycles interfere with the structure

In general graphs, odd cycles create blossoms, and the clean picture breaks.

So the right teaching order is:

- bipartite matching first
- blossom later

## Core Invariant And Why It Works

### Matching Invariant

At every stage, the chosen edge set `M` must remain a matching:

- no vertex is incident to more than one chosen edge

Any algorithmic step must preserve that invariant.

### Why Augmenting Along A Path Preserves Matching

Let `P` be an augmenting path for `M`.

Because `P` alternates:

- internal vertices of `P` are incident to exactly one matched edge of `P` and exactly one unmatched edge of `P`
- endpoints are free and become matched after augmentation

So after toggling the path:

- internal vertices remain matched exactly once
- endpoints gain one matched edge
- no other vertex changes status

Therefore `M \oplus P` is again a matching.

### Why An Augmenting Path Increases Matching Size By One

An augmenting path starts and ends with unmatched edges, so it contains:

- one more unmatched edge than matched edge

After toggling:

- all unmatched edges on the path are added
- all matched edges on the path are removed

Hence:

$$
|M \oplus P| = |M| + 1.
$$

### The Augmenting Path Theorem

This is the theorem matching algorithms live on. It is usually called **Berge's theorem**:

> A matching is maximum if and only if there is no augmenting path with respect to it.

The forward direction is immediate:

- if an augmenting path exists, we can enlarge the matching by one, so the current matching was not maximum

The reverse direction comes from comparing the current matching with a maximum one via symmetric difference:

- the difference decomposes into alternating paths and cycles
- if the maximum matching is larger, one of those alternating paths must be augmenting for the smaller matching

This theorem is why "search for augmenting paths" is the right algorithmic idea.
It is also the exact stop condition behind Kuhn, Hopcroft-Karp, and related matching algorithms:

- once no augmenting path remains, the matching is maximum

## Complexity And Tradeoffs

For bipartite matching:

- Kuhn / DFS augmenting paths: often `O(VE)` in the worst case, but simple and sometimes enough
- Hopcroft-Karp: `O(E \sqrt{V})`

Practical tradeoffs:

| Tool | Best when | Time | Main tradeoff |
| --- | --- | --- | --- |
| Kuhn / simple DFS augmentation | smaller graphs or first implementation | often fine in practice, worst-case `O(VE)` | slower on dense or larger inputs |
| Hopcroft-Karp | serious unweighted bipartite matching | `O(E \sqrt{V})` | more machinery, but still very contest-friendly |
| flow reduction | capacities or flow framing already exist | depends on flow engine | overkill when plain matching is enough |
| blossom / general matching | graph is not bipartite | much heavier | wrong first tool unless odd cycles truly matter |

Rule of thumb:

- first ask: is the graph bipartite?
- if yes, matching is usually much simpler than general graph matching
- if no, stop and decide whether blossom or a reduction is actually necessary

### Kuhn vs Hopcroft-Karp vs Flow

| Choice | Default use case | Cost | Coding weight | Why choose it |
| --- | --- | --- | --- | --- |
| Kuhn | first implementation, medium limits, concept learning | worst-case `O(VE)` | light | easiest way to learn augmenting paths |
| Hopcroft-Karp | serious unweighted bipartite matching | `O(E \sqrt{V})` | medium | batch shortest augmenting paths per phase |
| max-flow reduction | capacities or surrounding flow logic already exist | depends on flow algorithm | heavier | clean when the whole model is already a flow network |

Use Kuhn to learn the theorem.

Use Hopcroft-Karp when the input scale or contest setting wants a real production bipartite matcher.

Use flow when matching is only one part of a richer capacity model.

## Variant Chooser

| Variant | Use it when | Main idea | Main pitfall |
| --- | --- | --- | --- |
| Kuhn algorithm | bipartite graph, small/medium limits, simplest code desired | DFS one augmenting path at a time | can be too slow at scale |
| Hopcroft-Karp | bipartite graph, larger serious limits | BFS layers + many shortest augmenting paths per phase | misunderstanding the BFS/DFS layering contract |
| flow reduction | capacities or extra flow constraints already fit naturally | convert to max flow | heavier than needed for unit-capacity pairing |
| blossom / Edmonds | graph is general, not guaranteed bipartite | shrink odd cycles | much harder than the bipartite world |
| matching-to-edge-cover formulas | the question is actually edge cover or cover size | relate to maximum matching | easy to misuse when isolated vertices or general-graph conditions matter |

## Worked Examples

### Example 1: Jobs To People

Suppose:

- left side = people
- right side = jobs
- edge `(u, v)` means person `u` can do job `v`

Then a matching means:

- each person gets at most one job
- each job gets at most one person

So maximum bipartite matching is exactly the maximum number of valid assignments.

This is the cleanest first modeling example because the exclusivity constraint is visible immediately.

### Example 2: One Augmenting Path

Suppose the current matching is:

```text
L1 - R2
L2 - R3
```

and there is an alternating path:

```text
L3 - R2 - L1 - R1
```

where:

- `L3 - R2` is unmatched
- `R2 - L1` corresponds to matched edge `L1 - R2`
- `L1 - R1` is unmatched

Both endpoints `L3` and `R1` are free, so this is an augmenting path.

After toggling:

- remove `L1 - R2`
- add `L3 - R2`
- add `L1 - R1`

The matching size increases by one.

This is the local picture every matching proof depends on.
It is also the smallest mental model for the symmetric-difference formula:

$$
M' = M \oplus P.
$$

### Example 3: Why Hopcroft-Karp Is Faster

The slow idea is:

- find one augmenting path
- augment
- repeat

Hopcroft-Karp improves this by:

- running BFS from all free left vertices
- building a layered graph of shortest augmenting paths
- using DFS to augment along many vertex-disjoint shortest augmenting paths in one phase

That is why it beats simple DFS augmentation asymptotically.

### Example 4: Edge Cover As A Boundary Example

The VN SPOJ note [QBFLOWER](../../../practice/ladders/graphs/matching/qbflower.md) is a good reminder that some story problems are not "find a matching" directly.

That problem becomes a **minimum edge cover** problem in a general graph, and then uses the relation:

$$
\text{minimum edge cover} = |V| - \text{maximum matching}
$$

under the usual assumptions.

So matching often appears as the hidden primitive behind a different graph quantity.

This is a good boundary example precisely because it is **not** the same problem as maximum matching itself.

## Algorithm And Pseudocode

The repo starter implementation is:

- [hopcroft-karp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hopcroft-karp.cpp)

### Kuhn / DFS Augmenting Paths

This is the lightest first implementation for bipartite matching.

```text
try_kuhn(u):
    if u was visited in this DFS:
        return false
    mark u visited

    for each edge (u, v):
        if v is free:
            match u with v
            return true

        mate = match_right[v]
        if try_kuhn(mate):
            match u with v
            return true

    return false
```

The outer loop is:

```text
for each left vertex u:
    clear visited
    if try_kuhn(u):
        matching_size++
```

This is the cleanest code path for learning the augmenting-path theorem because every successful DFS literally finds one augmenting path and flips it.

### Hopcroft-Karp Overview

Maintain:

- `match_left[u]`
- `match_right[v]`
- `dist[u]` on the left side during BFS layering

Each phase has two parts.

#### BFS Layering

```text
bfs():
    queue all free left vertices
    dist[free_left] = 0
    dist[matched_left] = -1

    while queue not empty:
        pop left vertex u
        for each edge (u, v):
            if v is free:
                found an augmenting path of current shortest length
            else if the matched mate of v is unvisited:
                set its distance and push it
```

The purpose is to identify the shortest augmenting-path length.

#### DFS Augmentation Along Layers

```text
dfs(u):
    for each edge (u, v):
        let mate = match_right[v]
        if v is free
           or (mate is on the next BFS layer and dfs(mate)):
            match u with v
            return true
    mark u as dead for this phase
    return false
```

This DFS only follows edges consistent with the BFS layering, so it augments along shortest augmenting paths.

Repeating BFS + DFS phases yields Hopcroft-Karp.

## Implementation Notes

### 1. Bipartite Modeling Comes Before Coding

Before writing any matching code, write down:

- what are the left vertices?
- what are the right vertices?
- what does one edge mean?

If you cannot answer those three questions clearly, the model is not ready.

### 2. Matching Is About Endpoints, Not Edge Count Alone

Two chosen edges conflict if they share **either** endpoint.

That sounds obvious, but many modeling mistakes come from focusing on edges and forgetting the endpoint exclusivity that defines a matching.

### 3. Hopcroft-Karp Needs Left/Right Discipline

The template assumes:

- one explicit left side
- one explicit right side
- adjacency stored from left to right

Do not blur that separation during implementation.

### 4. Kuhn Also Needs Left-Side Discipline

In the simple DFS version, each outer iteration starts from one left vertex and tries to claim or reroute one path through the right side.

That is why the standard teaching form stores:

- adjacency from left to right
- `match_right[v]`
- and often `match_left[u]` as well for reconstruction or clarity

If you mix the roles of the two sides, the recursive augmentation logic becomes much harder to reason about.

### 5. Flow Is A Tool, Not The Default Explanation

Bipartite matching can be reduced to max flow, but that does not mean flow is the best first mental model.

Usually:

- matching is the cleaner abstraction
- flow is the heavier implementation

Use flow when the extra capacities or surrounding constraints truly ask for it.

### 6. Blossom Is A Boundary Marker

If the graph is not bipartite, odd cycles matter.

That is the signal that plain Kuhn or Hopcroft-Karp no longer apply directly.

Do not reach for blossom automatically. First ask:

- is the graph actually bipartite after modeling?
- can the story be reduced to bipartite structure another way?

Only then decide whether general matching is truly required.

### 7. Edge Cover Is Nearby But Not The Same

Matching:

- maximize disjoint chosen edges

Edge cover:

- ensure every vertex is incident to at least one chosen edge

These concepts are closely related, but they are not interchangeable. Keep the objective clear.

### 8. Weighted Assignment Is Another Boundary

If the objective is:

- maximize or minimize total weight
- not just cardinality

then this page is no longer the whole story.

That is the signal to think about:

- Hungarian-style assignment
- or [Min-Cost Flow](../min-cost-flow/README.md)

instead of plain maximum cardinality matching.

## Practice Archetypes

The most common matching-flavored tasks are:

- **maximum bipartite matching**
- **assignment / compatibility modeling**
- **matching as a reduction target**
- **matching versus flow judgment**
- **matching versus edge-cover judgment**

The strongest contest smell is:

- every chosen relationship uses each endpoint at most once

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Course:

- [MIT lecture notes on bipartite matching](https://math.mit.edu/~goemans/18433S11/matching-notes.pdf)
- [Algorithms II: Augmenting Paths](https://web.cs.dal.ca/~nzeh/Teaching/4113/book/matching/bipartite_maximum_matching/augmenting_paths.html)

Reference:

- [CP-Algorithms: Kuhn Maximum Bipartite Matching](https://cp-algorithms.com/graph/kuhn_maximum_bipartite_matching.html)
- [Hopcroft-Karp original paper (hosted mirror)](https://web.eecs.umich.edu/~pettie/matching/Hopcroft-Karp-bipartite-matching.pdf)
- [Princeton Algorithms: HopcroftKarp](https://algs4.cs.princeton.edu/code/javadoc/edu/princeton/cs/algs4/HopcroftKarp.html)

Practice:

- [CSES Problem Set](https://cses.fi/problemset/)

Repo anchors:

- practice ladder: [Matching ladder](../../../practice/ladders/graphs/matching/README.md)
- boundary example: [QBFLOWER](../../../practice/ladders/graphs/matching/qbflower.md)
- starter template: [hopcroft-karp.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hopcroft-karp.cpp)
- notebook refresher: [Graph cheatsheet](../../../notebook/graph-cheatsheet.md)

## Related Topics

- [Maximum Flow](../flow/README.md)
- [Min-Cost Flow](../min-cost-flow/README.md)
- [Graph Modeling](../graph-modeling/README.md)
