# Euler Tour Tree

This lane starts where the repo's static subtree-flattening story stops being enough:

```text
the tree changes online,
but the live query is still one rooted-subtree view, not one path aggregate.
```

That is the exact niche for **Euler tour trees**:

- represent one dynamic tree as one split/merge sequence
- keep one token for every vertex and directed edge visit
- answer subtree-side questions by cutting out one interval of that sequence

This topic sits directly next to two nearby lanes:

- [Euler Tour / Subtree Queries](../euler-tour-subtree/README.md) for the static version of subtree intervals
- [Link-Cut Tree](../link-cut-tree/README.md) for dynamic-tree **path** queries

The repo's first route is intentionally narrow:

- **vertex values**
- **point add on one vertex**
- **online `link / cut`**
- **subtree sum on one designated incident edge `(v, p)`**

That is enough to teach the ETT worldview without overpromising dynamic path monoids or every dynamic-tree variant at once.

## At A Glance

- **Use when:** the forest changes online and the live query asks for one rooted subtree or one component side of one existing edge
- **Core worldview:** keep one Euler-tour sequence of self-loops and directed edge tokens; subtree queries become contiguous intervals after the right reroot
- **Main tools:** split/merge BST or implicit treap, `make_root`, directed edge tokens `(u, v)` / `(v, u)`, interval aggregates
- **Typical complexity:** expected `O(log n)` per operation
- **Main trap:** treating ETT like a path-query structure when its real advantage is subtree-side information under dynamic topology

Strong contest signals:

- "cut one edge and link one new edge online"
- "query the subtree of `v` when `p` is considered the parent on edge `(v, p)`"
- "dynamic rooted subtree sum / size / minimum"
- "the tree changes online, but the answer is still one interval-like subtree side"

Strong anti-cues:

- the tree is static -> [Euler Tour / Subtree Queries](../euler-tour-subtree/README.md)
- the query is really one dynamic path aggregate -> [Link-Cut Tree](../link-cut-tree/README.md)
- only offline connectivity matters -> [DSU Rollback / Offline Dynamic Connectivity](../../data-structures/dsu-rollback/README.md)
- the real task is one sequence surgery problem, not a tree -> [Treap / Implicit Treap](../../data-structures/treap-implicit/README.md)

## Prerequisites

- [Trees](../trees/README.md)
- [Euler Tour / Subtree Queries](../euler-tour-subtree/README.md)
- [Treap / Implicit Treap](../../data-structures/treap-implicit/README.md)

Helpful neighboring topics:

- [Link-Cut Tree](../link-cut-tree/README.md)
- [Heavy-Light Decomposition](../hld/README.md)
- [Persistent Data Structures](../../data-structures/persistent-data-structures/README.md) if the real missing axis is time/versioning instead of topology changes

## Problem Model And Notation

We maintain a forest on vertices `0 .. n - 1`.

The first repo starter assumes:

- each vertex `u` stores one numeric value `val[u]`
- queries may:
  - add a delta to one vertex
  - cut one existing edge
  - link one new edge between two different trees
  - ask for the sum of the subtree of `v` when an adjacent vertex `p` is considered the parent on edge `(v, p)`

The sequence representation uses three token kinds:

- one **self-loop** token `(u, u)` for every vertex `u`
- one directed token `(u, v)` for every undirected edge `{u, v}`
- the reverse token `(v, u)` as well

For one rooted tree, the Euler-tour sequence is:

1. write `(u, u)`
2. for each child `v`:
   - write `(u, v)`
   - recurse into `v`
   - write `(v, u)`

The starter stores:

- `val[u]` only on the self-loop `(u, u)`
- zero on directed edge tokens

So subtree aggregates can be read from one interval sum without double-counting vertices.

## From Brute Force To The Right Idea

### Static Subtree Flattening Almost Fits

If the tree were static, we would:

- root it once
- flatten one subtree into one interval
- use a Fenwick or segment tree

That is exactly [Euler Tour / Subtree Queries](../euler-tour-subtree/README.md).

The trouble is that after one `cut` and one `link`:

- the old parent relation changes
- the old DFS order stops meaning the same subtree

So one fixed flattening is no longer durable.

### The Real Shift

The right question is not:

```text
how do I repair one static DFS order after every topology change?
```

It is:

```text
how do I keep a dynamic sequence whose intervals still correspond to rooted subtrees?
```

That is the Euler-tour-tree viewpoint.

### Why The Sequence Works

Once the tree is represented by:

- self-loop tokens for vertex values
- directed edge tokens for entering and leaving child subtrees

the subtree of `v` under parent `p` becomes:

```text
the contiguous interval from token (p, v) to token (v, p)
```

after rerooting the tree so that `p` is above `v`.

So the data-structure job becomes:

- reroot by rotating one sequence
- cut by removing two directed-edge tokens
- link by inserting two directed-edge tokens plus one whole child sequence
- answer one interval sum

## Core Invariants And Why They Work

## 1. Self-Loops Carry The Vertex Weights

Each vertex `u` contributes its value only on token `(u, u)`.

Directed edge tokens have weight `0`.

That is what makes one subtree interval sum equal the sum of vertex weights, not a messy multiple count.

## 2. Rooted Subtree = Directed-Edge Interval

If `p` is treated as the parent of adjacent vertex `v`, then the whole subtree of `v` is exactly the interval:

```text
(p, v) ... (v, p)
```

in the rooted Euler-tour sequence.

That is the one invariant the starter is built around.

## 3. `make_root(u)` Is A Sequence Rotation

In this token model, rerooting at `u` is just:

- split before `(u, u)`
- move the prefix to the end

So `make_root` is conceptually much closer to sequence surgery than to preferred-path exposure.

## 4. `link(child, parent)` Is Local Splice, Not Global Rebuild

After `make_root(child)`, the whole child tree is already one rooted sequence.

To attach it under `parent`, insert:

- `(parent, child)`
- the child sequence
- `(child, parent)`

immediately after `(parent, parent)`.

No whole-tree rebuild is needed.

## 5. `cut(u, v)` Works After One Reroot

After `make_root(u)`, the edge `{u, v}` becomes a parent-child edge with interval:

```text
(u, v) ... (v, u)
```

Removing the first and last token of that interval splits the tree into:

- the subtree sequence rooted at `v`
- the remaining sequence rooted at `u`

That is the cleanest reusable cut route for this first lane.

## Exact First Route In This Repo

The repo's first exact route is:

- online `link / cut`
- point add on vertices
- subtree sum on one existing edge `(v, p)` where `p` is the parent for that query

The starter is:

- [euler-tour-tree-subtree-sum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/euler-tour-tree-subtree-sum.cpp)

The flagship in-repo rep is:

- [Dynamic Tree Vertex Add Subtree Sum](../../../practice/ladders/graphs/euler-tour-tree/dynamictreevertexaddsubtreesum.md)

This route is intentionally **not**:

- generic dynamic path queries
- arbitrary dynamic reroot DP
- subtree add + subtree sum with lazy propagation

Those are later extensions.

## Variant Chooser

### Use Static Euler Flattening Instead When

- the tree topology never changes
- one subtree interval on a fixed root is enough

Route:

- [Euler Tour / Subtree Queries](../euler-tour-subtree/README.md)

### Use Link-Cut Tree Instead When

- the live query is one path aggregate or path update
- connectivity and path exposure matter more than subtree-side intervals

Route:

- [Link-Cut Tree](../link-cut-tree/README.md)

### Use ETT When

- the forest changes online
- the answer is still a rooted-subtree or one edge-oriented component side
- sequence split/merge feels more natural than preferred-path splaying

## Worked Example

### Dynamic Tree Vertex Add Subtree Sum

This is the repo's exact anchor:

- [Dynamic Tree Vertex Add Subtree Sum](../../../practice/ladders/graphs/euler-tour-tree/dynamictreevertexaddsubtreesum.md)

Operations:

- add `x` to one vertex
- cut one edge and link one new edge
- query the subtree of `v` where `p` is considered the parent on edge `(v, p)`

Reusable translation:

- `type 1`: mutate the self-loop `(v, v)`
- `type 2`: `make_root(p)`, then answer the interval between `(p, v)` and `(v, p)`
- `type 0`: `make_root(u)`, delete interval boundary tokens for `{u, v}`, then splice one rerooted child tree under the new parent

The hard part is not tree DP.

It is trusting the token-level sequence invariants.

## Main Traps

- confusing static subtree flattening with dynamic Euler tour trees
- forgetting that the first repo route is **subtree-side** only, not path aggregate
- storing vertex weight on multiple tokens and double-counting every subtree sum
- trying to cut an edge without rerooting one endpoint first
- mixing the meanings of the two directed edge tokens

## Reopen Path

- Practice ladder: [Euler Tour Tree ladder](../../../practice/ladders/graphs/euler-tour-tree/README.md)
- Hot sheet: [Euler Tour Tree hot sheet](../../../notebook/euler-tour-tree-hot-sheet.md)
- Compare points: [Euler Tour / Subtree Queries](../euler-tour-subtree/README.md), [Link-Cut Tree](../link-cut-tree/README.md), [Treap / Implicit Treap](../../data-structures/treap-implicit/README.md)
- Template chooser: [Template Library](../../../template-library.md)
- Retrieval router: [Build Kit](../../../docs/build-kit.md)

