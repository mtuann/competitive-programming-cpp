# Randomized / Global Min-Cut

This lane is for the moment cut reasoning is clearly the right family, but the statement does **not** give you a source and sink.

Instead, the graph is:

- undirected
- weighted
- and the objective is the cheapest edge cut that disconnects the graph in **any** nontrivial way

The repo's exact first route for this family is:

- starter -> [stoer-wagner-global-mincut.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/stoer-wagner-global-mincut.cpp)
- flagship note -> [Minimum Cut](../../../practice/ladders/graphs/global-min-cut/globalmincut.md)
- compare point -> [Maximum Flow](../flow/README.md)
- compare point -> [Gomory-Hu Tree](../gomory-hu/README.md)

This lane intentionally teaches the **deterministic Stoer-Wagner route first**.

Randomized Karger / Karger-Stein ideas still belong to this family, but they are taught here as sibling worldview and stretch, not as the first starter contract.

## At A Glance

- **Use when:** one undirected weighted graph asks for the minimum cut over all nonempty proper vertex partitions, with no designated `s` or `t`
- **Core worldview:** repeatedly grow one maximum-adjacency order, treat the last vertex as one minimum `s-t` cut of the current contracted graph, and keep the best phase cut across all contractions
- **Main tools:** cut phases, vertex contraction, adjacency-weight accumulation, and one witness side
- **Typical complexity:** `O(n^3)` with the dense contest-friendly Stoer-Wagner implementation
- **Main trap:** defaulting to "run max flow for every pair" even though the statement only wants one global cut and no pairwise query layer

Strong contest signals:

- "remove edges of minimum total weight so the graph becomes disconnected"
- "minimum cut of an undirected weighted graph"
- "there is no source and sink in the statement"
- "the answer is one global partition value, not many pairwise min-cuts"

Strong anti-cues:

- the graph is directed -> this starter is the wrong family boundary
- one particular `s-t` separation matters -> [Maximum Flow](../flow/README.md)
- many pairwise min-cuts on the same graph matter -> [Gomory-Hu Tree](../gomory-hu/README.md)
- costs, lower bounds, or transport dominate more than the cut family itself

## Prerequisites

- [Maximum Flow](../flow/README.md)
- [Graph Modeling](../graph-modeling/README.md)

Helpful neighboring topics:

- [Gomory-Hu Tree](../gomory-hu/README.md)
- [Trees](../trees/README.md) once the cut family escalates into a cut tree

## Problem Model And Notation

We work with one **undirected weighted graph**:

$$
G = (V, E), \quad |V| = n
$$

with nonnegative edge weights.

A cut is a partition:

$$
(S, V \setminus S)
$$

where both sides are nonempty.

Its weight is the total weight of edges crossing the partition:

$$
w(S, V \setminus S).
$$

The **global minimum cut** is:

$$
\lambda(G) = \min_{\varnothing \ne S \subsetneq V} w(S, V \setminus S).
$$

Unlike plain max-flow:

- no source is fixed
- no sink is fixed
- and the optimum may separate any pair of vertices

## From Brute Force To The Right Idea

### The Wrong First Instinct

If cut extraction from max flow is already familiar, the first instinct is often:

- choose one pair `(s, t)`
- run max flow / min cut
- repeat for many pairs

That is the wrong shape here.

This problem does **not** ask for one designated pair, and it does not yet ask for the whole all-pairs cut structure either.

### The Right Compression

Stoer-Wagner says:

- in the current contracted graph, one carefully built phase reveals one minimum cut separating the last two phase vertices
- after recording that phase cut, contract those two vertices
- the global answer is the minimum phase cut seen across all contractions

So the whole problem becomes:

- grow a maximum-adjacency order
- harvest one phase cut
- contract
- repeat

### Where Randomization Fits

Karger and Karger-Stein belong to this same family:

- repeatedly contract random edges
- keep enough trials so the global min-cut survives with high probability

That randomized worldview matters, especially in theory-first treatments.

But the repo teaches Stoer-Wagner first because it is:

- exact
- deterministic
- easy to smoke-test against brute force
- and cleaner as a first contest retrieval route

## Core Invariants And Why They Work

### 1. A Phase Grows The Set By Maximum Adjacency

Inside one phase, maintain a growing set `A`.

Each step adds the vertex outside `A` with largest total edge weight into `A`.

This is the maximum-adjacency ordering.

### 2. The Last Vertex Of The Phase Gives One Minimum `s-t` Cut

If `s` is the second-last added vertex and `t` is the last added vertex, then the weight accumulated on `t` at the end of the phase equals one minimum `s-t` cut in the current contracted graph.

That phase cut is a legitimate candidate for the global minimum cut.

### 3. Contracting `s` And `t` Preserves The Remaining Search Space

After one phase:

- record the phase-cut value
- merge the last two vertices
- continue on the contracted graph

Any global minimum cut is either:

- exactly the phase cut just found
- or still survives in the contracted graph

That is why keeping the best phase cut across all rounds is sufficient.

### 4. The Starter Can Return One Witness Side

The dense starter keeps track of which original vertices live inside each contracted super-node.

So when a new best phase cut appears, the repo starter can return:

- the cut value
- and one side of one optimal partition

The side is **not unique** in general.

## Variant Chooser

### Use Maximum Flow Instead When

- one designated `s-t` cut matters
- the statement asks for throughput, disjoint paths, or one cut certificate
- the graph is directed

### Use Randomized / Global Min-Cut When

- the graph is undirected
- the task wants one global cut value or one witness partition
- there is no pairwise query layer afterward

### Use Gomory-Hu Instead When

- the graph is undirected
- many pairwise min-cuts matter
- the real goal is to compress those many cuts into one tree

### Use Randomized Karger / Karger-Stein As A Sibling When

- the statement or source explicitly wants randomized global min-cut thinking
- you care about the contraction-survival proof picture
- or the deterministic dense-matrix route is no longer the teaching lens you want

## Exact Starter Route In This Repo

- starter template: [`stoer-wagner-global-mincut.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/stoer-wagner-global-mincut.cpp)
- exact contract:
  - vertices are `0 .. n - 1`
  - the graph is undirected
  - edge weights are nonnegative `long long`
  - parallel edges are accumulated by repeated `add_edge`
  - `solve()` returns the cut value plus one side mask of an optimal partition
  - for `n <= 1`, the repo convention returns cut value `0`
- flagship solved rep: [Minimum Cut](../../../practice/ladders/graphs/global-min-cut/globalmincut.md)

What the starter does **not** try to do yet:

- directed min-cut families
- all-pairs cut compression
- randomized repeated-trial Karger implementations
- dynamic edge updates

## Representative Solved Example

- [Minimum Cut](../../../practice/ladders/graphs/global-min-cut/globalmincut.md): classic undirected weighted global min-cut benchmark where Stoer-Wagner is the clean first route

## Common Pitfalls

- treating a global cut problem like one `s-t` cut with a guessed pair
- forgetting the graph must be undirected
- overwriting parallel edges instead of summing them
- assuming the returned witness side is unique
- overclaiming that the starter already teaches the randomized contraction route

## References And Repo Anchors

Research sweep refreshed on `2026-04-25`.

- paper: [Stoer-Wagner algorithm reference](https://algs4.cs.princeton.edu/code/javadoc/edu/princeton/cs/algs4/GlobalMincut.html)
- randomized-side notes: [MIT Randomized Algorithms - Minimum Cut](https://ocw.mit.edu/courses/6-856j-randomized-algorithms-fall-2002/resources/n16_min_cut/)
- exact quick sheet: [Global Min-Cut hot sheet](../../../notebook/global-min-cut-hot-sheet.md)
- flow-family compare point: [Flow hot sheet](../../../notebook/flow-hot-sheet.md)
- cut-tree follow-up: [Gomory-Hu Tree](../gomory-hu/README.md)
