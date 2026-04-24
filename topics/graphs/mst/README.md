# Minimum Spanning Tree

Minimum spanning tree (MST) is the canonical answer to this question:

- the graph is undirected and weighted
- you must connect all vertices
- the objective is **minimum total connection cost**

This is not a shortest-path problem. It is a **global connection** problem. The target object is one cheapest spanning tree, not one shortest path from a chosen source.

At contest level, MST is one of the cleanest greedy topics because everything rests on one structural theorem:

- the **cut property**

Kruskal and Prim are not two unrelated tricks. They are two ways of repeatedly taking a **safe edge**.

## At A Glance

- **Use when:** undirected weighted graph, connect everything as cheaply as possible
- **Core invariant:** every chosen edge is safe by a cut argument
- **Most common implementation:** Kruskal + DSU
- **Alternative implementation:** Prim + priority queue
- **Typical complexity:** `O(m log m)` for Kruskal, `O(m log n)` for heap Prim
- **Do not use when:** the graph is directed, or the task is really about shortest paths from one source

## Problem Model And Notation

Let

$$
G = (V, E)
$$

be an undirected weighted graph with edge-weight function

$$
w: E \to \mathbb{R}.
$$

A **spanning tree** is a subset of edges

$$
T \subseteq E
$$

such that:

- `(V, T)` is connected
- `(V, T)` has no cycle
- equivalently, `|T| = |V| - 1`

An **MST** is a spanning tree minimizing total weight:

$$
w(T) = \sum_{e \in T} w(e).
$$

If the graph is disconnected, then no spanning tree exists. The natural object then is a **minimum spanning forest**, one MST per connected component.

This distinction matters in code:

- if the statement demands one spanning tree, you must verify connectivity
- if not all vertices become connected, output `IMPOSSIBLE` or the equivalent failure case

## From Brute Force To The Right Idea

### Brute Force Over All Spanning Trees

The brute-force thought experiment is:

- enumerate all spanning trees
- compute the total cost of each
- keep the cheapest

This is hopeless computationally, but it teaches the right shape of the answer:

- we are selecting exactly `n - 1` edges
- every valid answer must stay cycle-free
- every local choice affects global connectivity

So the real question is:

- can we decide some edges greedily without losing optimality?

### Why Greedy Is Not Obviously Safe

If you greedily take the globally smallest unused edge, that can fail in many graph problems.

What makes MST special is that the graph structure gives us an exchange argument:

- for the right kind of edge, if an optimum tree does not already contain it, we can swap it in without making the tree worse

That is what the cut property formalizes.

### The Right Greedy Unit: A Safe Edge

The MST problem becomes easy as soon as you internalize this:

- not every light edge is automatically safe
- but the **lightest edge crossing a cut** is safe

Once that is true:

- Kruskal can reason in terms of current connected components
- Prim can reason in terms of one grown tree vs the outside vertices

Both algorithms are really building an MST by repeatedly exposing a cut and taking a safe edge across it.

## Core Invariant And Why It Works

### The Cut Property

Take any cut

$$
(S, V \setminus S)
$$

of the graph. Among all edges crossing that cut, let `e` be one of minimum weight.

Then:

- `e` belongs to **some** MST

If edge weights are distinct, we can state an even sharper version:

- the unique lightest crossing edge belongs to **every** MST

This is the core theorem behind both Kruskal and Prim.

### Why The Cut Property Is True

Take an MST `T`.

If `T` already contains `e`, we are done.

Otherwise, add `e` to `T`. Since `T` was a tree, adding one extra edge creates exactly one cycle.

That cycle must cross the cut at least one other edge `f`, because `e` crosses from `S` to `V \setminus S` and any closed walk that crosses a cut must come back across it.

Now:

- `f` is also a crossing edge
- `e` was chosen as a minimum-weight crossing edge

So:

$$
w(e) \le w(f).
$$

Remove `f` from the cycle. The graph becomes a spanning tree again, and its total weight is no larger than before.

So replacing `f` by `e` preserves optimality. Therefore there exists an MST containing `e`.

That is the whole greedy miracle.

### The Cycle Property

The dual viewpoint is:

- in any cycle, a strictly heaviest edge cannot belong to every MST

With distinct weights, the unique heaviest edge in a cycle belongs to no MST.

This is the "why skipping a cycle edge is safe" mirror of the cut property.

Kruskal often feels most intuitive through the cycle property:

- edges are processed from light to heavy
- if an edge would create a cycle, then it is the last and therefore heaviest edge seen on that cycle
- so skipping it is safe

### Kruskal's Invariant

Kruskal maintains a forest of chosen edges.

At every step:

- the chosen edges are acyclic
- there exists an MST containing all chosen edges

When Kruskal looks at the next edge `(u, v)` in sorted order:

- if `u` and `v` are already in the same component, adding it creates a cycle, so skip
- otherwise, the current connected components define a cut, and this edge is the cheapest available crossing edge for that component split

So it is safe to add.

### Prim's Invariant

Prim maintains:

- one connected tree on a set `S` of already absorbed vertices

At each step it takes the cheapest edge from `S` to `V \setminus S`.

That edge is safe by the cut property for the cut

$$
(S, V \setminus S).
$$

So Prim is not "like Dijkstra but for trees" because of some vague similarity. It is a cut-property greedy on one evolving cut.

## Kruskal Versus Prim

### Kruskal

Mental model:

- sort edges globally
- keep only those that connect different components

Best when:

- input already comes as an edge list
- the graph is sparse
- DSU is natural and available
- the statement is explicitly about selecting edges

Typical implementation:

1. sort all edges by weight
2. initialize DSU
3. take an edge if its endpoints are in different components
4. stop after `n - 1` chosen edges if connected

### Prim

Mental model:

- grow one tree outward from a seed vertex
- always attach the cheapest outside vertex-edge connection

Best when:

- graph is already stored as adjacency lists
- dense graphs make edge sorting less attractive
- you want a one-tree growth picture instead of a component forest

Typical implementation:

1. start from any root
2. maintain the best known edge connecting each outside vertex to the current tree
3. repeatedly add the outside vertex with smallest such key

On a connected graph, the start vertex does not change the optimal MST cost, though with tied weights it may change which particular MST Prim outputs.

### Which One Should You Default To In Contest?

Use this quick rule:

- **edge list + DSU-friendly statement:** Kruskal
- **dense graph / adjacency-first view / complete graph on points:** Prim

In this repo, Kruskal is the default first implementation because it is usually:

- easier to code cleanly
- easier to prove from the cut property
- easier to connect with DSU practice

## Worked Examples

### Example 1: Kruskal On A Small Graph

Take the weighted graph with edges:

```text
(0,1,1), (2,3,1), (1,2,2), (0,2,5)
```

Sort them:

```text
1, 1, 2, 5
```

Process in order:

1. take `(0,1,1)`
   Components: `{0,1}`, `{2}`, `{3}`

2. take `(2,3,1)`
   Components: `{0,1}`, `{2,3}`

3. take `(1,2,2)`
   Components: `{0,1,2,3}`

4. skip `(0,2,5)` because it now closes a cycle

Total cost is:

$$
1 + 1 + 2 = 4.
$$

This example is tiny, but it shows the whole structure:

- light edges first
- DSU prevents cycles
- the last heavy edge becomes unnecessary

### Example 2: Why Connectivity Check Matters

Suppose `n = 4`, but the edge list is:

```text
(0,1,1), (2,3,2)
```

Kruskal will happily choose both edges. But the result has only:

```text
2 < n - 1 = 3
```

chosen edges, so it is not a spanning tree.

This is the standard contest postcondition:

- if you did not choose exactly `n - 1` edges, the graph was disconnected

For [Road Reparation](../../../practice/ladders/graphs/mst/roadreparation.md), that is exactly why the solution must print `IMPOSSIBLE`.

### Example 3: MST Cost Versus Shortest-Path Tree Cost

Take this graph:

```text
0 --1-- 1
|       |
10      1
|       |
2 --1-- 3
```

An MST takes edges of cost `1, 1, 1`, total `3`.

But the shortest-path tree from source `0` may include the edge `(0,2)` of weight `10`, because it is trying to optimize distances from `0`, not total tree weight.

This is the key distinction:

- MST minimizes total connection cost
- shortest-path tree minimizes root-to-vertex distances

If a statement says "build roads as cheaply as possible so all cities become connected," think MST, not Dijkstra.

### Example 4: Why Clustering Problems Still Smell Like MST

Some statements are really asking for:

- the smallest maximum edge needed to connect everything
- the moment two vertices become connected as edges are added in increasing order
- the cost threshold at which the graph becomes one component

These are still MST-flavored because Kruskal exposes connectivity in sorted edge order.

In many such problems, you do not even need the final tree explicitly. You only need the moment the right components merge.

## Algorithm And Pseudocode

Repo starter template:

- [kruskal.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/kruskal.cpp)

### Kruskal

```text
sort edges by increasing weight
initialize DSU with n singleton components
total = 0
chosen = 0

for edge (u, v, w) in sorted order:
    if DSU says u and v are already connected:
        continue
    unite(u, v)
    total += w
    chosen++
    if chosen == n - 1:
        break

if chosen != n - 1:
    graph is disconnected
else:
    total is the MST cost
```

### Heap Prim

```text
mark all vertices as outside the tree
push (0, start) into a min-heap
total = 0

while heap not empty:
    pop cheapest (w, u)
    if u is already inside:
        continue
    mark u inside
    total += w

    for each edge (u, v, cost):
        if v is outside:
            push (cost, v)

if not all vertices were absorbed:
    graph is disconnected
```

This lazy heap version is usually enough for contest work. The eager-key-update version is more elegant analytically but often unnecessary in implementation.

## Implementation Notes

### 1. Negative Weights Are Fine

MST does not require nonnegative edges.

That condition belongs to Dijkstra, not MST.

If the graph is undirected and weighted, Kruskal and Prim still work with negative weights.

### 2. Distinct Weights Make Proofs Cleaner, Not Algorithms Necessary

Many proofs are first stated with distinct weights because then:

- the lightest crossing edge is unique
- the heaviest cycle edge is unique
- the MST is unique

But the algorithms do not require distinct weights.

With ties:

- there may be multiple MSTs
- Kruskal and Prim may output different valid MSTs

If a statement asks for:

- only the minimum total cost
- or any valid MST

that is fine.

But if it asks for:

- the lexicographically smallest chosen edges
- or a specific deterministic reconstruction under ties

then tie-breaking policy becomes part of the implementation, not just a cosmetic detail.

### 3. DSU Is The Helper, Not The Idea

Kruskal is not "the DSU algorithm."

DSU only answers:

- are these endpoints already in the same component?

The real algorithmic idea is still:

- process edges in increasing order
- use the cut/cycle property to justify each keep/skip decision

### 4. `long long` For Total Cost

Even if each edge weight fits in `int`, the MST sum may not.

The safe default in contest code is:

- store individual weights in at least `int`
- store total cost in `long long`

### 5. Prim On Complete Graphs Can Beat Kruskal In Practice

In complete-graph modeling problems such as "connect all points" with geometric distance, explicit edge generation makes:

$$
m = \Theta(n^2).
$$

In that setting, an `O(n^2)` Prim variant can be the cleanest implementation.

So "Kruskal is easier" is not the same as "Kruskal is always the best."

### 6. Stop Early In Kruskal

Once you have chosen `n - 1` edges, the MST is complete.

Continuing the scan is harmless but unnecessary.

### 7. MST And Bottleneck Questions

Every MST is also a **minimum bottleneck spanning tree**:

- it minimizes the largest edge used among all spanning trees

This is why many "minimize the worst jump/road/cable" problems can be reduced to MST reasoning even when the statement does not literally ask for total sum.

But the converse is false:

- a minimum bottleneck spanning tree need not minimize total weight

So if the statement really asks for the sum, solve MST directly instead of stopping at a bottleneck argument.

### 8. Directed Graphs Are A Different World

If edges are directed, this page does not apply.

Then you are in the territory of:

- shortest paths
- arborescences / Edmonds' algorithm
- flow or reachability modeling

Do not try to force Kruskal or Prim onto a directed graph.

## Beyond Basic MST

The core contest layer is:

- Kruskal
- Prim
- cut property
- cycle property
- connectivity check

Important next-layer directions include:

- Borůvka's algorithm
- dynamic MST updates
- Euclidean MST
- directed minimum arborescence

Those are valuable, but the right study order is:

1. internalize cut/cycle property
2. become fluent with Kruskal + DSU
3. then learn Prim as the "grow one tree" viewpoint

## Practice Archetypes

The most common MST-shaped tasks are:

- **minimum total cost to connect all vertices**
- **print `IMPOSSIBLE` if full connection cannot be achieved**
- **clustering / threshold problems driven by Kruskal order**
- **minimum possible maximum edge in a connected structure**
- **complete-graph point connection problems better suited to Prim**

The strongest contest smell is:

- undirected weighted graph
- one global connection objective
- no root source and no all-pairs distance requirement

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Course:

- [Stanford CS106B: Minimum Spanning Trees](https://web.stanford.edu/class/archive/cs/cs106b/cs106b.1224/lectures/26-msts/)
- [Illinois ECE374: Lecture 18 - Minimum spanning trees](https://ecealgo.com/lectures/Lec18.html)

Reference:

- [Princeton COS226 MST Study Guide](https://www.cs.princeton.edu/courses/archive/spring19/cos226/lectures/study/43MinimumSpanningTrees.html)
- [CP-Algorithms: Kruskal](https://cp-algorithms.com/graph/mst_kruskal.html)
- [CP-Algorithms: Prim](https://cp-algorithms.com/graph/mst_prim.html)

Practice:

- [CSES Graph Algorithms](https://cses.fi/problemset/list/)

Repo anchors:

- practice ladder: [MST ladder](../../../practice/ladders/graphs/mst/README.md)
- practice note: [Road Reparation](../../../practice/ladders/graphs/mst/roadreparation.md)
- starter template: [kruskal.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/kruskal.cpp)
- related topic: [DSU](../../data-structures/dsu/README.md)
- notebook refresher: [Graph cheatsheet](../../../notebook/graph-cheatsheet.md)

## Related Topics

- [DSU](../../data-structures/dsu/README.md)
- [Graph Modeling](../graph-modeling/README.md)
- [Shortest Paths](../shortest-paths/README.md)
- [Trees](../trees/README.md)
