# Euler Tour / Subtree Queries

This lane is for the first time a tree problem stops being "walk the whole subtree again" and becomes:

- root the tree once
- flatten each subtree into one interval
- answer subtree queries with an ordinary range structure

The key reduction is:

```text
subtree query on a rooted tree -> interval query on a flattened array
```

That is why this topic sits between [Trees](../trees/README.md) and heavier tree machinery like [Heavy-Light Decomposition](../hld/README.md).

It is also important to separate this lane from two lookalikes:

- the **full Euler tour** used in some LCA reductions
- dynamic **Euler Tour Trees** from advanced data-structure literature

This page is about the contest-standard **single-entry DFS order** that makes every subtree contiguous.

## At A Glance

- **Use when:** the graph is a static rooted tree and each query/update concerns one whole subtree
- **Core worldview:** DFS entry order turns the subtree of node `u` into one contiguous interval `[tin[u], tout[u])`
- **Main tools:** rooting, DFS timer, flattening array, Fenwick tree or segment tree on the flattened order
- **Typical complexity:** `O(n)` flattening, then usually `O(log n)` per update/query
- **Main trap:** mixing the single-entry subtree tour with the full Euler tour used for LCA or dynamic-tree papers

Strong contest signals:

- "sum/count over the subtree of node `u`"
- "change the value of one node, then query one subtree"
- "all descendants of `u` should be handled together"
- "the tree is static, but subtree queries are many"

Strong anti-cues:

- arbitrary path queries `u -> v` -> [Heavy-Light Decomposition](../hld/README.md)
- only ancestor checks -> `tin/tout` alone or [LCA](../lca/README.md), no range structure required
- the real work is merging child states -> [Tree DP](../../dp/tree-dp/README.md)
- the tree itself changes online -> this page is too static; compare [Euler Tour Tree](../euler-tour-tree/README.md) for dynamic subtree-side queries or [Link-Cut Tree](../link-cut-tree/README.md) when the live query is still one path

## Prerequisites

- [Trees](../trees/README.md)
- [Fenwick Tree](../../data-structures/fenwick-tree/README.md)

Helpful neighboring topics:

- [LCA](../lca/README.md)
- [Heavy-Light Decomposition](../hld/README.md)
- [Lazy Segment Tree](../../data-structures/lazy-segment-tree/README.md) once subtree intervals need richer range updates

## Problem Model And Notation

Let the tree be rooted at `r`, usually `1`.

For each node `u`, define:

- `tin[u]`: the time we first enter `u` in DFS
- `tout[u]`: the timer value after finishing the whole subtree of `u`

This page uses the **single-entry** DFS order:

- write `u` once, when DFS first reaches `u`
- do **not** write `u` again on exit

Then:

$$
\text{subtree}(u) \leftrightarrow [tin[u], tout[u])
$$

on the flattened array.

If `flat[tin[u]] = value[u]`, then:

- subtree sum of `u` = range sum on `[tin[u], tout[u])`
- subtree size of `u` = `tout[u] - tin[u]`

This is the reduction the whole topic is built on.

## From Brute Force To The Right Idea

### Brute Force

Suppose each query asks:

- "what is the sum of values in the subtree of `u`?"

and updates say:

- "set the value of node `u` to `x`"

The naive solution is:

- after each query, traverse the whole subtree again

That costs:

$$
O(\text{subtree size})
$$

per query, which is too slow when the subtree can be large many times.

### The First Shift: Root The Tree Once

Subtree language only becomes stable after fixing a root.

Once the tree is rooted, "descendant of `u`" means one exact set, not a vague direction.

### The Second Shift: DFS Entry Order Makes Each Subtree Contiguous

In a DFS that records a node when it is first entered:

- DFS enters `u`
- visits the whole subtree of `u`
- leaves `u`

So all nodes in the subtree of `u` are written consecutively before DFS can return to the parent.

That is the crucial interval invariant:

```text
subtree(u) is one contiguous block in entry order
```

### The Third Shift: Stop Thinking “Tree Query”

Once the subtree is one interval, the problem is no longer primarily about trees.

It becomes:

- point updates on one array position
- interval queries on one range

Now an ordinary [Fenwick Tree](../../data-structures/fenwick-tree/README.md) or segment tree is enough.

## Core Invariants And Why They Work

## 1. Single-Entry Tour Invariant

Every node `u` is written exactly once at entry time.

So `tin[u]` is the unique flattened index representing node `u`.

This is the variant used for subtree queries.

It is **not** the same as the full Euler tour used for some LCA reductions, where nodes appear multiple times.

## 2. Contiguous Subtree Interval Invariant

When DFS first enters `u`, it cannot leave the subtree of `u` before visiting every descendant of `u`.

Therefore all descendants of `u` occupy one consecutive slice:

$$
[tin[u], tout[u])
$$

This is the theorem that turns subtree queries into range queries.

## 3. Subtree Size From Time Difference

Because every node in the subtree is written once:

$$
\text{size}[u] = tout[u] - tin[u].
$$

This is a nice sanity check while debugging:

- subtree interval length must match subtree size

If it does not, the flattening logic is wrong.

## 4. Node Value Lives At One Position

If values are on vertices, the standard convention is:

$$
flat[tin[u]] = value[u].
$$

Then:

- point update on `u` -> one point update at `tin[u]`
- subtree query on `u` -> one range query on `[tin[u], tout[u])`

This is why subtree queries are lighter than arbitrary path queries.

## 5. Why Fenwick Often Wins Here

For the flagship family:

- point set / point add on one node
- subtree sum on one interval

the flattened problem is just:

- point update
- range sum

That is a perfect [Fenwick Tree](../../data-structures/fenwick-tree/README.md) lane, usually lighter than a segment tree.

## Variant Chooser

### Use Euler Tour / Subtree Flattening When

- queries touch whole subtrees
- one rooted interval per subtree is enough
- the tree is static

### Use `tin/tout` Alone When

- you only need ancestor checks such as "is `u` inside the subtree of `v`?"

### Use Fenwick On The Flattened Order When

- updates are point add / point set
- queries are subtree sum or count

### Use Segment Tree On The Flattened Order When

- the subtree aggregate is richer than a simple prefix-sum structure can support
- or subtree intervals need a different associative range aggregate

### Move To HLD When

- queries are on arbitrary paths, not only one subtree

### Move To Tree DP When

- each node answer is built by combining child states instead of querying one flattened interval

## Worked Examples

### Example 1: The Interval Picture

Take the rooted tree:

- `1` connected to `2` and `3`
- `3` connected to `4` and `5`

If DFS entry order is:

```text
1, 2, 3, 4, 5
```

then:

- `subtree(3)` is exactly the interval covering `3, 4, 5`
- so one subtree query becomes one range query

Nothing deeper is required.

The whole trick is that descendants of `3` were visited in one uninterrupted block.

### Example 2: CSES Subtree Queries

The statement is:

- update one node value
- ask the sum of one subtree

Flatten the tree so:

$$
flat[tin[u]] = value[u]
$$

Then:

- `set value[u] = x` becomes one point delta update at `tin[u]`
- `sum of subtree(u)` becomes range sum on `[tin[u], tout[u])`

This is the exact flagship route for this lane.

### Example 3: Why This Is Lighter Than HLD

Suppose the query becomes:

- maximum on the path `u -> v`

Now the path is **not** one subtree interval.

A single-entry flattening no longer gives one contiguous block in general.

That is the signal to leave this lane and move to [Heavy-Light Decomposition](../hld/README.md).

So the real decision rule is:

- subtree-only -> Euler flattening
- arbitrary path -> HLD

## Pseudocode

```text
timer = 0
dfs(u, parent):
    tin[u] = timer
    flat[timer] = value[u]
    timer += 1

    for v in adj[u]:
        if v == parent:
            continue
        dfs(v, u)

    tout[u] = timer

subtree_sum(u):
    return range_sum(tin[u], tout[u))

point_set(u, new_value):
    delta = new_value - value[u]
    value[u] = new_value
    point_add(tin[u], delta)
```

The only subtle line is:

```text
tout[u] = timer
```

because it makes the subtree interval half-open.

## Implementation Notes

- Be explicit about whether nodes are `0`-indexed or `1`-indexed.
- Keep subtree intervals half-open: `[tin[u], tout[u])`.
- Distinguish **single-entry subtree flattening** from the **full Euler tour** used in LCA reductions.
- On contest limits around `2e5`, iterative DFS is often safer than recursive DFS in C++.
- For point assignment queries, store current node values so updates can be converted into deltas for Fenwick.
- If the statement is edge-valued instead of node-valued, the flattening convention changes; do not cargo-cult the vertex-valued starter.

## Practice Archetypes

Use this lane when the problem sounds like:

- `subtree sum / count with point updates`
- `subtree interval + offline counting`
- `tree to array reduction before choosing Fenwick or segment tree`
- `subtree-only route that should stay lighter than HLD`

Good internal compare points:

- [Subtree Queries](../../../practice/ladders/graphs/euler-tour-subtree/subtreequeries.md): exact entry route for point update + subtree sum
- [Trees](../trees/README.md): parent/depth/subtree-size worldview before flattening
- [Heavy-Light Decomposition](../hld/README.md): next stop once the query leaves the subtree-only world
- [Fenwick Tree](../../data-structures/fenwick-tree/README.md): the lightest common engine after flattening

Suggested progression:

1. subtree sizes and rooting
2. subtree interval flattening
3. point update + subtree sum
4. subtree intervals plus richer range structures
5. only then path-query techniques like HLD

## References And Repo Anchors

Research sweep refreshed on `2026-04-24`.

Primary / official:

- [CSES - Subtree Queries](https://cses.fi/problemset/task/1137/)

Course / guide:

- [USACO Guide - Euler Tour Technique](https://usaco.guide/gold/tree-euler)

Reference:

- [OI Wiki - Tree Basics](https://en.oi-wiki.org/graph/tree-basic/)

Repo anchors:

- [Trees](../trees/README.md)
- [Fenwick Tree](../../data-structures/fenwick-tree/README.md)
- [Subtree Queries note](../../../practice/ladders/graphs/euler-tour-subtree/subtreequeries.md)
- [Subtree Queries hot sheet](../../../notebook/subtree-queries-hot-sheet.md)
