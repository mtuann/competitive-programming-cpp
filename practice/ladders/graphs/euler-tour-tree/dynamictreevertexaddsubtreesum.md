# Dynamic Tree Vertex Add Subtree Sum

- Title: `Dynamic Tree Vertex Add Subtree Sum`
- Judge / source: `Library Checker`
- Original URL: [https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum](https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum)
- Secondary topics: `Dynamic trees`, `Treap / split-merge`, `Subtree aggregates`
- Difficulty: `very hard`
- Subtype: `Euler tour tree + point add + edge-oriented subtree sum`
- Status: `solved`
- Solution file: [dynamictreevertexaddsubtreesum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/euler-tour-tree/dynamictreevertexaddsubtreesum.cpp)

## Why Practice This

This is the cleanest verifier-style rep for the repo's first **Euler tour tree** lane.

The statement gives:

- one tree with vertex weights
- online `cut` and `link`
- point add on one vertex
- queries of the form:

```text
on edge (v, p), treat p as the parent and ask for the subtree sum of v
```

That is exactly the first ETT worldview:

- dynamic topology
- subtree-side query
- sequence split/merge

not dynamic path aggregates.

## Recognition Cue

Reach for Euler tour tree when:

- the tree changes online
- the live query is still "one rooted subtree" or "one side of one edge"
- the statement itself tells you the parent for the query edge
- you can almost see a subtree interval, but a fixed DFS order no longer survives the updates

The smell here is:

```text
the query is subtree-shaped, but the tree is no longer static.
```

## Problem-Specific Transformation

Represent the current rooted tree by one sequence of:

- self-loops `(u, u)`
- directed edge tokens `(u, v)` and `(v, u)`

Store `a_u` only on `(u, u)`.

Then:

- after `make_root(p)`, the subtree of adjacent child `v` is exactly the interval from `(p, v)` to `(v, p)`
- `type 1` is just adding to self-loop `(p, p)`
- `type 0` is:
  - reroot one endpoint of the removed edge
  - delete the two boundary tokens for that edge
  - reroot the new child tree
  - splice it under the new parent

So the problem becomes:

```text
maintain one dynamic split/merge sequence with interval sums
```

instead of maintaining parent arrays or rebuilding DFS orders.

## Core Idea

The implementation keeps one implicit-treap-style sequence per tree.

Each sequence node is one token:

- self-loop `(u, u)` with weight `a_u`
- directed edge token with weight `0`

The key invariants are:

1. rerooting at `u` is rotating the sequence so `(u, u)` becomes first
2. if `p` is the parent of adjacent `v`, then the whole subtree of `v` is the contiguous interval `(p, v) ... (v, p)`
3. cutting edge `{u, v}` after `make_root(u)` removes the interval boundary tokens `(u, v)` and `(v, u)`
4. linking child tree `w` under parent `x` means inserting:
   - `(x, w)`
   - the whole rerooted sequence of `w`
   - `(w, x)`
   immediately after `(x, x)`

That is why ETT is the right fit:

```text
dynamic subtree queries are still interval queries, but the interval order itself must be dynamic.
```

## Implementation Plan

1. create one self-loop token `(u, u)` for every vertex
2. build the initial tree by linking edges in any acyclic order
3. keep a pointer to:
   - self-loop token of every vertex
   - both directed-edge tokens of every current edge
4. answer queries by split/merge around those token pointers

The implicit treap only needs:

- subtree size
- subtree sum
- parent pointers for `index(node)` recovery

No lazy propagation is needed for this first route.

## Complexity

- each `make_root`, `link`, `cut`, or subtree query uses a constant number of split/merge/rank operations
- expected complexity per query: `O(log n)`
- memory: `O(n + q)` tokens

This matches the official `2e5` limits.

## Main Traps

- trying to solve it with one static DFS flattening
- treating it like link-cut tree path queries instead of subtree-side interval queries
- storing vertex weight on both entry and exit style tokens
- forgetting that query `2 v p` gives an **edge** `(v, p)` and explicitly says `p` is the parent
- cutting an edge without rerooting one endpoint first

## Reopen Path

- Topic page: [Euler Tour Tree](../../../../topics/graphs/euler-tour-tree/README.md)
- Practice ladder: [Euler Tour Tree ladder](README.md)
- Starter template: [euler-tour-tree-subtree-sum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/euler-tour-tree-subtree-sum.cpp)
- Notebook refresher: [Euler Tour Tree hot sheet](../../../../notebook/euler-tour-tree-hot-sheet.md)
- Compare points: [Euler Tour / Subtree Queries](../../../../topics/graphs/euler-tour-subtree/README.md), [Link-Cut Tree](../../../../topics/graphs/link-cut-tree/README.md), [Treap / Implicit Treap](../../../../topics/data-structures/treap-implicit/README.md)

## Solution

- Code: [dynamictreevertexaddsubtreesum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/euler-tour-tree/dynamictreevertexaddsubtreesum.cpp)

