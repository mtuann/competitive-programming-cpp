# Edmonds Blossom / General Matching

This lane is for the moment matching stops being a clean bipartite story and the graph is just:

- undirected
- not guaranteed bipartite
- still unweighted
- still about the **maximum number of disjoint edges**

The repo's exact first route for this family is:

- starter -> [edmonds-blossom.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/edmonds-blossom.cpp)
- flagship note -> [General Matching](../../../practice/ladders/graphs/general-matching/generalmatching.md)
- compare point -> [Matching](../matching/README.md)
- compare point -> [Hungarian / Assignment Problem](../hungarian-assignment/README.md)

This lane intentionally teaches the **unweighted maximum-cardinality route first**. It does not try to start from weighted blossom, Tutte-matrix randomness, or minimum-cost perfect matching in general graphs.

## At A Glance

- **Use when:** the graph is an undirected general graph, odd cycles matter, and the objective is the size of the matching
- **Core worldview:** grow alternating forests from exposed vertices, and when an odd alternating cycle appears, shrink it into one blossom base without changing whether an augmenting path exists
- **Main tools:** alternating trees, blossom bases, LCA inside the alternating forest, contraction by `base[]`, and augmenting-path flips
- **Typical complexity:** `O(n^3)` for the standard contest blossom implementation
- **Main trap:** forcing Hopcroft-Karp or plain bipartite reasoning onto a graph where odd cycles really matter

Strong contest signals:

- "find the maximum matching in a simple undirected graph"
- "the graph is not guaranteed bipartite"
- "pair as many vertices as possible"
- "output one maximum matching, not necessarily perfect"
- "odd cycles are allowed and not removable by a simple coloring step"

Strong anti-cues:

- the graph is bipartite and the real job is still maximum cardinality matching -> [Matching](../matching/README.md)
- the graph is bipartite and the real job is stable pairing under preferences -> [Stable Marriage](../stable-marriage/README.md)
- the graph is bipartite and the objective is weighted one-to-one assignment -> [Hungarian / Assignment Problem](../hungarian-assignment/README.md)
- capacities, costs, or source/sink routing dominate -> [Maximum Flow](../flow/README.md) or [Min-Cost Flow](../min-cost-flow/README.md)
- the graph is weighted -> this lane is too narrow; weighted blossom is a harder sibling not taught here

## Prerequisites

- [Matching](../matching/README.md), because augmenting-path language should already feel natural
- [Graph Modeling](../graph-modeling/README.md)
- [BFS And DFS](../bfs-dfs/README.md)

Helpful compare points:

- [Matching](../matching/README.md): use this first whenever the graph is bipartite
- [Stable Marriage](../stable-marriage/README.md): use this when the graph is bipartite but the objective is stability under preferences rather than cardinality
- [Hungarian / Assignment Problem](../hungarian-assignment/README.md): use this when the graph is bipartite and weighted assignment is the real structure
- [Maximum Flow](../flow/README.md): use this when capacities are the first-class model, not disjoint undirected edge pairs

## Problem Model And Notation

Given a simple undirected graph:

$$
G = (V, E),
$$

we want a matching `M` with maximum size:

$$
|M|.
$$

As in bipartite matching:

- a vertex is **matched** if it is incident to one edge of `M`
- a vertex is **free** or **exposed** otherwise
- an **augmenting path** is an alternating path whose endpoints are free

The new difficulty is that odd cycles can appear inside alternating search trees.

## From Bipartite Matching To Blossoms

### What Breaks

In bipartite graphs, alternating BFS trees behave cleanly because parity already splits the graph into two sides.

In a general graph, you can encounter:

- two outer vertices in the same alternating forest
- connected by one non-matching edge
- which closes an odd alternating cycle

That cycle is exactly the obstruction that kills the naive bipartite picture.

### The Blossom Idea

If such an odd alternating cycle appears, Edmonds' key insight is:

- contract the whole odd cycle into one super-vertex
- keep searching for an augmenting path in the contracted graph
- later, if augmentation goes through that super-vertex, expand it back consistently

So blossom is not "a different objective". It is the structural patch that keeps augmenting-path logic alive in a general graph.

### Why This Is Still The Same World

The algorithm is still driven by the same theorem:

> A matching is maximum if and only if no augmenting path exists.

Blossom only changes **how** we preserve the meaning of augmenting paths when odd cycles appear.

## Core Invariants And Why They Matter

The repo starter keeps four contest-facing invariants.

### 1. `match[v]` Always Describes A Legal Matching

At every step:

- `match[v] = -1` means exposed
- otherwise `match[match[v]] = v`

No augmentation or blossom update may violate this.

### 2. `base[v]` Is The Current Blossom Representative

When odd alternating cycles are shrunk, vertices inside the same contracted blossom share one base.

This is why the implementation can avoid physically rebuilding the graph after each contraction.

### 3. The BFS Forest Is Still Alternating

The search grows from one exposed root.

Inside that forest:

- tree edges alternate unmatched / matched
- `parent[]` records the unmatched-to-matched predecessor structure
- reaching an exposed vertex through that structure gives one augmenting path

### 4. Shrinking A Blossom Preserves Augmenting-Path Existence

This is the theorem that makes the whole method legal:

- if the original graph has an augmenting path, the contracted graph still has one
- if the contracted graph has one, it can be expanded back

So shrinking is not a heuristic. It is a correctness-preserving reduction.

## Complexity And Tradeoffs

The standard contest blossom implementation here runs in:

$$
O(n^3).
$$

Rule of thumb:

- bipartite and unweighted -> [Matching](../matching/README.md)
- bipartite and weighted assignment -> [Hungarian / Assignment Problem](../hungarian-assignment/README.md)
- general undirected and unweighted -> this lane

## Worked Examples

### Example 1: Library Checker - Matching on General Graph

This repo's flagship note:

- [General Matching](../../../practice/ladders/graphs/general-matching/generalmatching.md)

The statement is as direct as possible:

- simple undirected graph
- arbitrary odd cycles allowed
- output one maximum matching

That makes it the cleanest first benchmark for this lane.

### Example 2: QBFLOWER

- [QBFLOWER](../../../practice/ladders/graphs/matching/qbflower.md)

This is a good compare point because the statement is not "find a matching" directly.

Instead:

- transform the story into minimum edge cover on a general graph
- reduce that to `n - maximum_matching`
- then use blossom as the engine

So `QBFLOWER` is not the purest first route, but it is a great reminder that blossom often appears through one extra modeling layer.

## Repo Starter Contract

The starter:

- is for a simple undirected graph
- ignores self-loops
- stores one mate per vertex in `match`
- returns the matching size through `maximum_matching()`

After running:

- `match[v] == -1` means unmatched
- otherwise `match[v]` is the matched partner of `v`

That contract is enough for:

- direct maximum-matching output
- transformations like minimum edge cover
- quick matching-size reuse inside other graph reductions

## Main Traps

- trying to 2-color first and then still using the bipartite implementation after the graph fails the test
- forgetting that this lane is **unweighted** only
- mishandling `0`-based vs `1`-based output when printing matched pairs
- confusing "maximal" with "maximum"

## Reopen Paths

- exact starter -> [edmonds-blossom.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/edmonds-blossom.cpp)
- hot sheet -> [General Matching hot sheet](../../../notebook/general-matching-hot-sheet.md)
- flagship note -> [General Matching](../../../practice/ladders/graphs/general-matching/generalmatching.md)
- bipartite-first compare route -> [Matching](../matching/README.md)
- weighted bipartite compare route -> [Hungarian / Assignment Problem](../hungarian-assignment/README.md)
