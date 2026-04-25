# Virtual Tree / Auxiliary Tree

This lane is for the first time a tree problem says:

```text
the query only touches a small marked subset of nodes,
but the real structure still lives on the union of paths between them.
```

The right move is often:

- keep only the marked nodes
- add the LCAs needed to preserve ancestry
- build the compressed tree induced by those vertices
- run the real DP or counting logic on that much smaller object

That compressed tree is usually called:

- `virtual tree`
- `auxiliary tree`
- or `compressed tree on marked nodes`

This topic sits naturally after [Trees](../trees/README.md) and [LCA](../lca/README.md):

- [Trees](../trees/README.md) gives the rooted-tree worldview
- [LCA](../lca/README.md) gives the path/ancestor primitive
- this page teaches how to shrink one marked-subset query down to only the vertices that still matter

## At A Glance

- **Use when:** one static rooted tree is queried many times, each query marks only `k` vertices, and only the union of paths between those marked vertices matters
- **Core worldview:** marked nodes alone are not enough; you must also keep the LCAs that glue their paths together
- **Main tools:** DFS preorder `tin`, ancestor checks, LCA of consecutive marked nodes in DFS order, monotone stack build
- **Typical complexity:** preprocessing `O(n log n)`; one query build `O(k log n)` or `O(k)` after sorting/LCA costs are accounted for
- **Main trap:** treating the virtual tree as a general replacement for every tree query instead of a marked-subset compression trick

Strong contest signals:

- "each query gives a subset of important/special/colored vertices"
- the answer only depends on paths connecting those marked vertices
- the original tree is large, but the total marked vertices over all queries is manageable
- after you root the tree, the hard part becomes "compress the relevant branch points, then run one small DP"

Strong anti-cues:

- every node is active in every query, so there is nothing to compress
- the query is subtree-only, so [Euler Tour / Subtree Queries](../euler-tour-subtree/README.md) already fits
- the real bottleneck is online path aggregates, so [Heavy-Light Decomposition](../hld/README.md) is a better exact route
- the tree topology changes online, so this page is too static; compare [Link-Cut Tree](../link-cut-tree/README.md)

## Prerequisites

- [Trees](../trees/README.md)
- [LCA](../lca/README.md)

Helpful neighboring topics:

- [Tree DP](../../dp/tree-dp/README.md)
- [Heavy-Light Decomposition](../hld/README.md)
- [DSU On Tree / Small-To-Large](../../data-structures/dsu-on-tree/README.md)

## Problem Model And Notation

Root the tree once at some node `r`.

For each node `u`, we use:

- `tin[u]`: DFS entry time
- `tout[u]`: DFS exit time in the rooted tree
- `depth[u]`
- `lca(u, v)`

For one query, let `S` be the set of marked vertices.

The **virtual tree** of `S` is the smallest rooted tree that:

- contains every vertex in `S`
- contains every LCA needed to preserve the ancestry relations among the marked paths
- keeps the same ancestor-descendant order as the original tree

The virtual-tree edges are compressed edges of the original tree:

- one edge `u -> v` in the virtual tree means `u` is the nearest kept ancestor of `v`
- the original path from `u` to `v` contains no other kept vertex

That is why one compressed edge often stores useful metadata such as:

- `depth[v] - depth[u]`
- distance in the original tree
- minimum edge or vertex cost on the represented path

## From Brute Force To The Right Idea

### Brute Force

Suppose one query marks `k` important vertices.

The naive instinct is often:

- walk every marked-to-marked path directly
- mark all vertices on the whole union of those paths
- then run a DP on that induced subgraph

That can be far too large across many queries.

The original tree might have `n = 2e5` vertices even when:

```text
this query only really cares about 12 marked nodes.
```

### The First Right Observation

Most vertices on those connecting paths are boring.

They only matter if they are:

- originally marked
- or a branch point where marked paths meet

In a rooted tree, those branch points are exactly the relevant LCAs.

### The Second Right Observation

You do **not** need LCAs of all pairs.

A standard fact is:

```text
after sorting marked nodes by DFS preorder,
it is enough to add LCAs of consecutive nodes in that order.
```

That is the key size bound.

### The Third Right Observation

Once the final kept vertices are sorted by `tin`, the compressed parent relation can be built by one stack:

- keep the current ancestor chain
- pop until the top is an ancestor of the next node
- connect that top to the next node

That turns the query from "huge tree again" into:

```text
sort -> add needed LCAs -> sort/unique -> stack-build one tiny rooted tree
```

## Core Invariants And Why They Work

## 1. Consecutive-LCA Invariant

Let the marked vertices be sorted by DFS preorder.

Then every LCA needed for the virtual tree appears among LCAs of consecutive vertices in that sorted order.

So you do **not** need:

- all `O(k^2)` pair LCAs

You only need:

- `k - 1` consecutive LCAs

This is the size-saving invariant that makes the whole technique practical.

## 2. Ancestor Order Is Preserved

The virtual tree does not invent new ancestry.

If `u` is an ancestor of `v` in the virtual tree, then `u` is also an ancestor of `v` in the original rooted tree.

That is why:

- `tin/tout` ancestor checks still work
- rooted-tree DP logic can be reused on the compressed tree

## 3. The Virtual Tree Has Only O(k) Vertices

If the query marks `k` vertices, then after:

- adding consecutive LCAs
- sorting
- deduplicating

the number of kept vertices is still `O(k)`.

So a linear DP on the virtual tree is really a linear DP in the query size, not in `n`.

## 4. Every Compressed Edge Represents One Clean Original Path Segment

If `u` is the virtual parent of `v`, then the original path from `u` to `v` contains no other kept vertex.

This means you can attach one summary to that edge, such as:

- its length
- whether there is at least one removable internal vertex
- the minimum cost along that path segment

Many query-specific DPs live entirely on that compressed metadata.

## 5. Stack Build Works Because DFS Order Linearizes Ancestors

After sorting the kept vertices by `tin`, ancestors always appear before descendants.

So when processing vertices in that order:

- the active stack is one ancestor chain
- the nearest kept ancestor of the next vertex is found by popping until ancestry holds again

That is why the build step is almost always a monotone-stack routine.

## Exact First Route In This Repo

The repo's first exact route for this family is intentionally narrow:

- preprocess one rooted tree for `tin/tout`, `depth`, and LCA
- for one query set `S`, build the virtual tree
- expose:
  - kept nodes
  - parent relation in the compressed tree
  - children lists
  - `depth[parent -> child]` difference in the original tree

The starter is:

- [virtual-tree.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/virtual-tree.cpp)

The flagship in-repo rep is:

- [Kingdom and its Cities](../../../practice/ladders/graphs/virtual-tree/kingdomanditscities.md)

That rep is deliberately not "just build the tree".

It forces the full workflow:

1. mark important nodes for one query
2. build the virtual tree
3. run a small DP on the compressed tree instead of the original one

## Worked Mental Model

Suppose the marked set is:

```text
S = {a, b, c}
```

and:

- `lca(a, b) = x`
- `lca(b, c) = y`

Then the query does **not** care about every vertex on every path individually.

It only cares about:

- the marked endpoints
- the LCAs that merge those paths
- and some metadata on the compressed edges between them

That is the main habit to build:

```text
first compress the tree-shaped query,
then solve the real combinatorics on the compressed object.
```

## Variant Chooser

### Use Plain LCA When

- you only need ancestor checks, distances, or one meeting point
- there is no marked-subset compression step

### Use Virtual Tree When

- each query marks a relatively small subset of nodes
- only the union of marked paths matters
- a DP or counting pass on `O(k)` vertices is the real target

### Use Tree DP When

- the whole tree participates once
- there is no per-query marked subset to compress

### Use HLD When

- the real operation is repeated path aggregation on the original static tree
- not "compress marked subset, then do one query-local DP"

### Use DSU On Tree When

- each node needs one subtree answer built from merged child containers
- not one query-local compressed tree on arbitrary marked vertices

## Common Pitfalls

- forgetting to sort by DFS preorder before adding consecutive LCAs
- adding LCAs of all pairs and destroying the `O(k)` size bound
- confusing the virtual tree with the original rooted tree
- not deduplicating after adding LCAs
- forgetting that compressed edges often need original-path metadata, not just parent indices
- using recursive DFS on the original tree blindly when the depth can be large and the repo prefers iterative preprocessing where practical

## Practice Archetypes

The strongest virtual-tree archetypes are:

- marked-subset DP
- pairwise-separation or guarding problems
- sum/count over unions of marked paths
- query-local Steiner-tree style reductions
- query-local reroot or merge logic that would be too expensive on the full tree

The strongest smell is:

```text
many queries, each with a small set of special nodes on one static tree
```

## Reopen Paths

- Topic base -> [LCA](../lca/README.md)
- Whole-tree child-merge DP -> [Tree DP](../../dp/tree-dp/README.md)
- Static path aggregates -> [Heavy-Light Decomposition](../hld/README.md)
- Subtree-only route -> [Euler Tour / Subtree Queries](../euler-tour-subtree/README.md)
- Retrieval sheet -> [Virtual Tree hot sheet](../../../notebook/virtual-tree-hot-sheet.md)
- Snippet chooser -> [Template Library](../../../template-library.md)

