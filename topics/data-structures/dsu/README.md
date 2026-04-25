# DSU

Disjoint Set Union is the standard contest structure for maintaining a partition of elements under **merges only**.

That last phrase is the real heart of the topic:

- sets can merge
- sets do not split
- connectivity or grouping evolves monotonically

If you keep that model in mind, DSU stops being "that tiny union-find snippet" and becomes a very reliable modeling tool.

This page is designed to make four things automatic:

1. see a component partition instead of a graph traversal problem
2. define the root-representative invariant cleanly
3. understand why path compression and union by size make the structure fast
4. know exactly when plain DSU is enough and when you need a stronger variant

## At A Glance

Reach for DSU when:

- elements start in separate groups and groups only merge
- the main question is "same component?" or "merge these components"
- edges are added over time, but not removed
- Kruskal, connectivity, or equivalence classes are nearby

Strong contest triggers:

- "are `u` and `v` connected after these additions?"
- "merge groups and query component size"
- "if this edge joins two existing connected vertices, it makes a cycle"
- "sort edges and take only those joining different components"
- "the statement defines an equivalence relation or merge process"

Strong anti-cues:

- edges or group relationships must be deleted online
- you need path queries, shortest paths, or subtree aggregates
- the real problem is not component membership but order, range, or geometry

What success looks like after studying this page:

- you can implement `find`, `unite`, `same`, and `component_size` from memory
- you can explain why metadata should live at roots
- you know when DSU beats BFS/DFS and when it does not
- you can recognize parity / rollback / offline dynamic connectivity as variants, not plain DSU

## Prerequisites

- [Foundations](../../foundations/README.md)
- [Graphs](../../graphs/README.md) helps, but DSU is not only a graph tool

Helpful neighboring topics:

- [Minimum Spanning Tree](../../graphs/mst/README.md)
- [BFS And DFS](../../graphs/bfs-dfs/README.md)

## Problem Model And Notation

We maintain a partition of elements:

$$
\{0,1,\dots,n-1\}
$$

into pairwise disjoint components.

The classical DSU interface is:

- `make_set(x)` or initialization: start a singleton set
- `find(x)`: return the representative of the set containing `x`
- `unite(a, b)`: merge the two sets containing `a` and `b`

In contest code, each component is usually stored as a rooted tree.

The key arrays are:

- `parent[x]`: the immediate parent of `x` in the forest
- `size[x]` or `rank[x]`: a heuristic summary stored at roots

If `x` is a root, then usually:

$$
parent[x] = x.
$$

Two elements belong to the same component if and only if:

$$
find(a) = find(b).
$$

## From Brute Force To The Right Idea

### Brute Force

Suppose we repeatedly merge groups and ask whether two vertices are in the same component.

The naive options are:

- rebuild connectivity by BFS/DFS after every merge
- explicitly store each set as a list and scan or relabel too much

These are often too slow when there are many operations.

### The Structural Observation

The only thing we really need is:

- one stable name for each current component

That is what the representative root provides.

If every component has one root, then:

- `find(x)` tells us the name of `x`'s component
- `unite(a, b)` only needs to connect the two roots

So DSU turns set merging into forest maintenance.

### Why Trees Are Enough

Each set is represented by a rooted tree.

Every node points, directly or indirectly, to the root of its component.

Then:

- the root is the representative
- following parent pointers finds the component name
- merging two components is just making one root point to the other

That is the whole data structure before optimizations.

### Why The Optimizations Matter

Without care, DSU trees can become long chains, and then `find(x)` may cost `O(n)`.

The two standard fixes are:

1. **path compression**
   - whenever we run `find(x)`, we make visited nodes point closer to the root
2. **union by size/rank**
   - when merging two roots, attach the smaller/shallower tree under the larger/taller one

These two heuristics are what make DSU feel "constant-time" in practice.

### A Tiny Forest Trace

Start with five singleton sets:

```text
0   1   2   3   4
```

After:

```text
unite(0, 1)
unite(1, 2)
unite(3, 4)
```

one valid DSU forest might look like:

```text
0
├── 1
└── 2

3
└── 4
```

Now `find(2)` returns root `0`.

If the tree had become longer, path compression would rewrite the nodes on the search path so that future finds jump to the root much faster. That is the concrete meaning of "compression": the partition stays the same, but the forest becomes flatter.

## Core Invariant And Why It Works

### Representative Invariant

At every moment, each node belongs to exactly one rooted tree, and the root of that tree is the representative of its component.

So:

$$
x \text{ and } y \text{ are in the same component} \iff find(x) = find(y).
$$

This is the invariant everything else must preserve.

### Why `find` Is Correct

If `parent[x] = x`, then `x` is the root of its component and is therefore the representative.

Otherwise, `parent[x]` lies in the same component as `x`, and recursively following parents must eventually reach the unique root.

That root is exactly the representative of the component containing `x`.

### Why Path Compression Is Safe

Suppose `find(x)` discovers that the true representative is `r`.

If we then set:

$$
parent[x] = r,
$$

or more generally compress the whole traversed path toward `r`, we do **not** change the partition into components.

We only shorten the internal tree shape while preserving:

- every node still points into the same component
- every node still reaches the same representative

So path compression is a pure performance optimization, not a semantic change.

### Why Union By Size/Rank Is Safe

If `a` and `b` are roots of two different components, then making one root point to the other merges the two components correctly no matter which root becomes parent.

Union by size/rank is therefore also a pure performance choice.

Its purpose is to keep trees shallow:

- attach the smaller tree under the larger one
- or attach the lower-rank tree under the higher-rank one

That prevents the forest from degenerating badly.

### Why Metadata Belongs At Roots

Suppose we want component size, sum, minimum, or any other aggregate over the whole set.

The clean rule is:

- store component metadata only at representatives

Then after a merge, only the new root needs an update.

If you try to keep such metadata synchronized at every node, the structure becomes much harder to reason about and easier to corrupt.

This root-only rule is one of the most reusable DSU habits.

### Why The Complexity Is "Almost Constant"

With path compression plus union by size/rank, the amortized complexity per operation is:

$$
O(\alpha(n)),
$$

where `\alpha` is the inverse Ackermann function.

For contest purposes, this behaves like a tiny constant.

The exact proof is deep and not necessary for day-to-day CP use. The practical intuition is enough:

- union by size/rank stops trees from growing tall too quickly
- path compression aggressively flattens whatever depth remains

So repeated finds become cheaper and cheaper.

There is also a very useful intermediate intuition:

- with **union by size alone**, a node's depth can increase only when its component is attached under a strictly larger one
- every time that happens, the size of the component above that node at least doubles

So even before path compression, the depth is already bounded by:

$$
O(\log n).
$$

Then path compression flattens the parts of the forest that are actually touched by queries, which is what brings the amortized bound down to `O(\alpha(n))`.

## Complexity And Tradeoffs

For `m` operations on `n` elements, plain optimized DSU supports:

- `find`: amortized `O(\alpha(n))`
- `unite`: amortized `O(\alpha(n))`
- memory: `O(n)`

Practical tradeoffs:

| Tool | Best when | Time | Main tradeoff |
| --- | --- | --- | --- |
| DSU | merge-only connectivity / grouping | amortized near-constant | cannot support arbitrary splits |
| BFS / DFS | one-shot connectivity in a fixed graph | `O(n + m)` per traversal | inefficient if repeated after every merge |
| rollback DSU | offline dynamic connectivity with undo | usually `O(\log n)`-ish per op depending on framework | cannot use full path compression in the usual way |
| HLD / segment structures | path or subtree aggregates | stronger query power | far more machinery than DSU |

Rule of thumb:

- if components only merge, DSU should be in your shortlist immediately
- if components also split, plain DSU is usually the wrong abstraction

## Variant Chooser

| Variant | Use it when | Extra state | Main pitfall |
| --- | --- | --- | --- |
| plain DSU | connectivity / component size / simple merges | parent + size/rank | trying to answer richer graph queries than connectivity |
| DSU with root metadata | each component tracks size/sum/min/max | metadata at roots | updating metadata on non-roots |
| parity / weighted DSU | relation to root matters, not just membership | parity or distance to representative | forgetting that the stored relation is part of `find` |
| rollback DSU | offline dynamic connectivity with undo | change stack | standard path compression is not directly compatible |
| DSU-on-tree / small-to-large | subtree query merging | multiset/map per subtree | this is a different technique, despite the name similarity |

The main lesson:

- many useful variants exist
- but plain DSU is still specifically a merge-only partition structure

## Worked Examples

### Example 1: Connectivity Under Edge Additions

Start with `n` isolated vertices, so every vertex is its own component.

For each new undirected edge `(u, v)`:

- call `unite(u, v)`

Then a query:

```text
are u and v connected?
```

becomes:

```text
find(u) == find(v)
```

This is the purest DSU application.

### Example 2: Cycle Detection

In an undirected graph, before adding edge `(u, v)`:

- if `find(u) == find(v)`, then `u` and `v` are already connected
- adding the edge creates a cycle

Otherwise:

- unite the two components

This is the core local test inside Kruskal and many incremental graph problems.

### Example 3: Kruskal's Algorithm

This is the cleanest bridge from DSU to a major graph algorithm.

Sort edges by weight, then scan them in order.

For each edge `(u, v, w)`:

- if `find(u) != find(v)`, take it and `unite(u, v)`
- otherwise skip it, because it would create a cycle

DSU answers exactly the question Kruskal needs:

- do these endpoints currently lie in different components?

That is why [Road Reparation](../../../practice/ladders/graphs/mst/roadreparation.md) is such a strong cross-topic anchor.

### Example 4: Component Metadata

Suppose we want each component's size.

Initialize:

- every singleton has size `1`

When merging roots `a` and `b`, after choosing the new root:

- update only the root's size

For example, under union by size:

```text
parent[b] = a
size[a] += size[b]
```

Then:

```text
component_size(x) = size[find(x)]
```

This pattern generalizes to many other root-only component aggregates.

## Algorithm And Pseudocode

The repo starter implementation is:

- [dsu-basic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/dsu-basic.cpp)

### Initialization

```text
for each x:
    parent[x] = x
    size[x] = 1
```

### Find With Path Compression

```text
find(x):
    if parent[x] == x:
        return x
    parent[x] = find(parent[x])
    return parent[x]
```

### Union By Size

```text
unite(a, b):
    a = find(a)
    b = find(b)
    if a == b:
        return false

    if size[a] < size[b]:
        swap(a, b)

    parent[b] = a
    size[a] += size[b]
    return true
```

This is the contest-default version for most plain DSU tasks.

## Implementation Notes

### 1. Initialize Every Node As Its Own Parent

If you forget:

```text
parent[x] = x
```

the whole representative invariant collapses immediately.

This sounds basic, but it is one of the most common DSU bugs.

### 2. Roots Carry The Meaning

When you write DSU code, mentally separate:

- node-level data
- component-level data

Component-level data belongs to roots.

After every merge, only the new root's metadata is authoritative.

### 3. `find` Should Usually Be The Only Way To Ask Component Questions

Do not compare raw `parent[u]` and `parent[v]`.

Always compare:

```text
find(u) == find(v)
```

because non-root parents can change under path compression.

### 4. Union By Size And Union By Rank Are Both Fine

Union by size is often easier to extend because component size is already useful metadata.

Union by rank is also standard and theoretically clean.

Pick one convention and keep it consistent.

### 5. Path Compression Makes The Forest Opaque

After heavy compression, the parent forest no longer has a meaningful original shape.

That is fine for connectivity, but it means:

- you should not try to interpret the DSU forest as the original graph structure
- if you need reversible changes, plain path compression may stop being the right choice

This is exactly why rollback DSU is treated as a separate variant.

### 6. DSU Is Not A General Dynamic Graph Structure

Plain DSU handles:

- merges
- connectivity
- root-centered metadata

It does **not** handle:

- deletions
- shortest paths
- path aggregates
- arbitrary subtree queries

Knowing this boundary is just as important as knowing the code.

## Practice Archetypes

The most common DSU-flavored problems are:

- **connectivity under additions**
- **cycle detection**
- **Kruskal / MST**
- **component size or component aggregate**
- **offline grouping by equivalence**

More advanced smells:

- **parity constraints**
- **rollback / offline dynamic connectivity**
- **matroid-style or forest-independence modeling** as in [C11XU](../../../practice/ladders/data-structures/dsu/c11xu.md)

The strongest contest smell is:

- the partition evolves by merging, never by splitting

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Course:

- [USACO Guide: DSU](https://usaco.guide/gold/dsu)
- [UW CSE 332: Disjoint Set Union / Find](https://courses.cs.washington.edu/courses/cse332/14wi/slides/lecture24/18-disjoint-union-find_V2.pdf)

Reference:

- [CP-Algorithms: Disjoint Set Union](https://cp-algorithms.com/data_structures/disjoint_set_union.html)
- [UTK Notes: Disjoint Sets](https://web.eecs.utk.edu/~jplank/plank/classes/cs302/Notes/Disjoint/)

Practice:

- [CSES Graph Algorithms](https://cses.fi/problemset/)

Repo anchors:

- practice ladder: [DSU ladder](../../../practice/ladders/data-structures/dsu/README.md)
- advanced note: [C11XU](../../../practice/ladders/data-structures/dsu/c11xu.md)
- rollback compare lane: [DSU Rollback / Offline Dynamic Connectivity](../dsu-rollback/README.md)
- cross-topic note: [Road Reparation](../../../practice/ladders/graphs/mst/roadreparation.md)
- starter template: [dsu-basic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/dsu-basic.cpp)
- notebook refresher: [Data structures cheatsheet](../../../notebook/data-structures-cheatsheet.md)

## Related Topics

- [Minimum Spanning Tree](../../graphs/mst/README.md)
- [BFS And DFS](../../graphs/bfs-dfs/README.md)
- [DSU Rollback / Offline Dynamic Connectivity](../dsu-rollback/README.md)
- [Fenwick Tree](../fenwick-tree/README.md)
