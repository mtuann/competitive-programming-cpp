# Gomory-Hu Tree

Gomory-Hu tree is the graph lane you reach for when one undirected weighted graph hides:

```text
many pairwise min-cut questions,
and repeating one max-flow from scratch for every pair is clearly too expensive.
```

It sits one layer above plain max flow.

- [Maximum Flow](../flow/README.md) teaches one `s-t` cut.
- this lane teaches how `n - 1` carefully chosen max-flow runs can compress **all-pairs min-cut** information into one weighted tree

The repo's first exact route is intentionally narrow:

- **undirected weighted graph**
- **build one Gomory-Hu tree**
- **no dynamic updates**
- **no directed-graph generalization**
- **query handling layered afterward**

That is enough to teach the core cut-tree worldview without overpromising every later application at once.

## At A Glance

- **Use when:** one undirected graph needs many pairwise min-cut answers or one offline task whose whole compression is "replace all pairwise cuts by one tree"
- **Core worldview:** run `n - 1` max-flow computations and reparent vertices by the reachable side of each min cut
- **Main tools:** max-flow / min-cut, residual reachability, parent array, cut values, tree path minimum
- **Typical complexity:** `n - 1` max-flow runs plus whatever tree-query layer comes afterward
- **Main trap:** using this on directed graphs, or when the task only needs one source-sink cut and plain max flow is already the right endpoint

Strong contest signals:

- "all pairs `(s, t)`"
- "many min-cut queries on the same undirected graph"
- "for every pair of vertices, ask something about their min cut"
- "compress repeated cuts into one tree"

Strong anti-cues:

- the graph is directed
- only one or a few `s-t` cut answers are needed
- the real task is lower-bounded circulation or min-cost flow, not repeated min-cut structure
- the graph changes online

## Prerequisites

- [Maximum Flow](../flow/README.md)
- [Trees](../trees/README.md)

Helpful neighboring topics:

- [Randomized / Global Min-Cut](../global-min-cut/README.md)
- [Flow With Lower Bounds](../flow-lower-bounds/README.md)
- [Min-Cost Flow](../min-cost-flow/README.md)
- [DSU](../../data-structures/dsu/README.md) for the first flagship query-counting rep after the tree is built

## Problem Model And Notation

We work on one **undirected weighted graph**:

$$
G = (V, E), \quad |V| = n
$$

where each edge has nonnegative capacity.

For any two vertices `s` and `t`, define:

```text
minCut(s, t) = minimum capacity of a cut separating s and t
```

A **Gomory-Hu tree** is a weighted tree on the same vertex set such that for every pair `s, t`:

```text
minCut(s, t) = minimum edge weight on the unique tree path from s to t
```

So the cut family of the original graph is compressed into one tree.

The exact starter in this repo assumes:

- vertices are `0 .. n - 1`
- the graph is undirected
- capacities are `long long`
- you want to build the cut tree itself first

## From Brute Force To The Right Idea

### Brute Force

If the statement asks many pairwise min-cut questions, the brute-force instinct is:

- pick one pair `(s, t)`
- run max flow
- repeat for every pair

That is hopeless once the query count becomes quadratic.

### The Real Compression

The key theorem says:

- for an undirected graph, all pairwise min-cuts can be represented by one weighted tree

So the real question becomes:

```text
how do I build that tree without solving all O(n^2) pairs?
```

The answer is:

- only `n - 1` max-flow runs
- one parent array
- and residual reachability after each cut

### Why Residual Reachability Matters

Suppose we run one max flow between vertex `s` and its current parent `p`.

After the flow is maximum:

- the vertices still reachable from `s` in the residual graph are exactly one side of a minimum `s-p` cut

That reachable-side information tells us which later vertices should now live under `s` instead of under `p`.

So the max-flow value gives the cut weight, and the residual graph gives the tree-structure update.

## Core Invariants And Why They Work

## 1. The Tree Lives On The Same Vertex Set

The Gomory-Hu tree has:

- the same vertices as the original graph
- only `n - 1` weighted edges

It is not a condensation graph or a state graph.

It is a compressed certificate for all pairwise min-cuts.

## 2. Each Iteration Solves One Parent Cut

Maintain a parent array.

For each vertex `s > 0`:

- let `t = parent[s]`
- compute one minimum `s-t` cut
- store its value as the cut value for `s`

This does **not** yet solve every pair directly.

It builds enough local structure that the final parent edges form the global cut tree.

## 3. Residual Reachability Decides Reparenting

After the `s-t` max flow finishes:

- let `side[v]` mean "`v` is reachable from `s` in the residual graph"

Then every later vertex currently parented by `t` but lying on the `s` side can be reparented to `s`.

That is the structural heart of the algorithm.

## 4. Tree Path Minimum Equals Original Pairwise Min Cut

Once the tree is built, for every pair `u, v`:

```text
minCut(u, v) = minimum edge weight on the unique path in the cut tree
```

That means the expensive graph work is over.

Afterward, many tasks become ordinary tree problems:

- path minimum queries
- offline threshold counting with DSU
- divide-and-conquer or tree DP on the cut tree

## Variant Chooser

### Use Plain Max Flow Instead When

- only one `s-t` cut matters
- the answer is directly one source-sink value or one cut certificate
- the graph is directed

### Use Randomized / Global Min-Cut Instead When

- the graph is undirected
- there is still no pairwise query layer
- you only need one cheapest disconnection cut for the whole graph

### Use Gomory-Hu When

- the graph is undirected
- many pairs matter
- the whole trick is to pay the max-flow cost once per tree edge, not once per query pair

### Layer Another Tree Technique Afterward When

- the cut tree is built, but the actual output wants:
  - path minima
  - threshold counting
  - offline pair aggregation
  - one tree DP over the cut tree

The first repo flagship does exactly that with DSU counting:

- [MCQUERY](../../../practice/ladders/graphs/gomory-hu/mcquery.md)

## Exact Starter Route In This Repo

- starter template: [`gomory-hu-tree.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/gomory-hu-tree.cpp)
- exact contract:
  - build one Gomory-Hu tree for an undirected weighted graph
  - return the parent/cut structure and the final tree edges
  - leave heavy query handling to the caller
- flagship solved rep: [MCQUERY](../../../practice/ladders/graphs/gomory-hu/mcquery.md)

What the starter does **not** try to do yet:

- directed cut trees
- weighted matching reductions
- lower-bound or min-cost variants
- one generic all-in-one query layer

## Representative Solved Example

- [MCQUERY](../../../practice/ladders/graphs/gomory-hu/mcquery.md): build a Gomory-Hu tree once, then count unordered pairs by path-minimum threshold using DSU over tree edges

## Common Pitfalls

- forgetting the graph must be undirected
- rebuilding one flow network but failing to include both directed residual arcs for every undirected edge copy
- reading residual reachability from the wrong source side
- treating the final tree edge weights like additive path sums instead of **path minima**
- overclaiming that the starter already solves fast path-min queries by itself

## References And Repo Anchors

Research sweep refreshed on `2026-04-25`.

Primary / course:

- [Gomory and Hu - Multi-terminal network flows](https://web.mit.edu/tabbott/www/papers/gomory-hu.pdf)
- [UC Davis advanced algorithms notes](https://www.cs.ucdavis.edu/~martel/222b/)

Practice:

- [Library Checker - Gomory-Hu Tree](https://judge.yosupo.jp/problem/gomory_hu_tree)
- [MCQUERY](../../../practice/ladders/graphs/gomory-hu/mcquery.md)
- [Pumping Stations](https://codeforces.com/problemset/problem/343/E)

Repo anchors:

- practice ladder: [Gomory-Hu ladder](../../../practice/ladders/graphs/gomory-hu/README.md)
- starter template: [`gomory-hu-tree.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/gomory-hu-tree.cpp)
- solved rep: [MCQUERY](../../../practice/ladders/graphs/gomory-hu/mcquery.md)
- prerequisite flow engine: [Maximum Flow](../flow/README.md)
- notebook refresher: [Graph cheatsheet](../../../notebook/graph-cheatsheet.md)

## Related Topics

- [Maximum Flow](../flow/README.md)
- [Flow With Lower Bounds](../flow-lower-bounds/README.md)
- [Min-Cost Flow](../min-cost-flow/README.md)
- [Trees](../trees/README.md)
