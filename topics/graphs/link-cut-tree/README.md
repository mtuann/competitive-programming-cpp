# Link-Cut Tree

Link-cut tree is the first tree tool in the repo whose whole point is:

```text
the forest changes online,
but path queries and updates still need to stay logarithmic.
```

It sits directly next to the static-tree trio:

- [Euler Tour / Subtree Queries](../euler-tour-subtree/README.md)
- [Heavy-Light Decomposition](../hld/README.md)
- [Centroid Decomposition](../centroid-decomposition/README.md)

Those lanes all assume the tree topology is fixed.

This lane starts exactly where they stop being enough:

- edges are cut and linked online
- connectivity inside one forest changes during the query stream
- the query still asks about one tree path, not one arbitrary graph path

The repo's first exact route is intentionally narrow:

- **vertex values**
- **point add on one node**
- **path sum**
- **online `link / cut / connected`**

That is enough to teach the dynamic-tree worldview without overpromising subtree aggregates or fully generic monoids too early.

## At A Glance

- **Use when:** one forest changes online by `link` and `cut`, and queries still ask about connectivity or one path aggregate
- **Core worldview:** represent preferred root-to-node paths as auxiliary splay trees, then rewrite dynamic-tree operations into `access`, `makeroot`, `link`, and `cut`
- **Main tools:** auxiliary splay trees, preferred paths, path reversals, `access`, `makeroot`, `find_root`
- **Typical complexity:** amortized `O(log n)` per operation
- **Main trap:** confusing the represented forest with the auxiliary splay trees, or reaching for link-cut when the tree is actually static

Strong contest signals:

- "the tree edges change online"
- "cut one existing edge, then link one new edge"
- "query a path aggregate after topology updates"
- "need `same tree?`, `link`, `cut`, and one path query in the same stream"

Strong anti-cues:

- the tree is static -> [Heavy-Light Decomposition](../hld/README.md) or [Euler Tour / Subtree Queries](../euler-tour-subtree/README.md)
- only offline connectivity under add/remove events matters -> [DSU Rollback / Offline Dynamic Connectivity](../../data-structures/dsu-rollback/README.md)
- the real query is subtree-only on one fixed root -> [Euler Tour / Subtree Queries](../euler-tour-subtree/README.md)
- the task is static path decomposition or centroid ancestors, not dynamic topology -> [Heavy-Light Decomposition](../hld/README.md) or [Centroid Decomposition](../centroid-decomposition/README.md)

## Prerequisites

- [Trees](../trees/README.md)
- [Heavy-Light Decomposition](../hld/README.md)

Helpful neighboring topics:

- [Euler Tour / Subtree Queries](../euler-tour-subtree/README.md)
- [Centroid Decomposition](../centroid-decomposition/README.md)
- [Splay Tree](../../data-structures/splay-tree/README.md) as the direct enabling lane for the `rotate / splay / parent-pointer` machinery used here
- [Treap / Implicit Treap](../../data-structures/treap-implicit/README.md) as the closest repo neighbor for split/merge and BST-rotation instincts
- [PBDS / Order Statistics Tree](../../data-structures/pbds-order-statistics/README.md) as the closest repo neighbor for "one self-adjusting BST is only a helper structure, not the final problem model"

## Problem Model And Notation

We maintain a forest on vertices `0 .. n - 1`.

The exact starter in this repo assumes:

- each vertex `u` stores one numeric value `val[u]`
- queries may:
  - add a delta to one vertex
  - ask the sum on the simple path between `u` and `v`
  - cut one existing tree edge
  - link one new tree edge between two currently different trees

We will use:

- **represented tree / forest**: the real forest the problem talks about
- **auxiliary tree**: one splay tree used internally by the link-cut structure
- `makeroot(u)`: make `u` the represented root of its tree
- `access(u)`: expose the preferred path from the represented root to `u`
- `find_root(u)`: find the represented root of `u`'s current tree

The starter is **vertex-valued**, not edge-valued, and supports:

- `connected(u, v)`
- `link(u, v)`
- `cut(u, v)`
- `add_value(u, delta)`
- `path_sum(u, v)`

## From Brute Force To The Right Idea

### Static-Tree Tools Fail For The Right Reason

Suppose the problem asks for:

- path sums
- point updates
- and online edge replacements

The first instinct is often:

- build one HLD or subtree-flattening structure once
- try to update it after each topology change

That fails because those decompositions depend on a fixed parent/depth/chain or one fixed DFS order.

After one `cut` and one `link`, the old flattening may simply no longer mean anything.

### The Real Shift

The right question is not:

```text
how do I patch one static decomposition after every change?
```

It is:

```text
how do I keep only the path I currently care about explicit,
and let the rest of the tree stay implicit?
```

That is exactly what link-cut trees do.

### Preferred Paths Instead Of One Global Decomposition

For the current access pattern, each represented tree is decomposed into **preferred paths**.

Each preferred path is stored as one auxiliary splay tree.

Then:

- `access(u)` rewrites which root-to-node path is currently preferred
- `makeroot(u)` flips one exposed path
- `path_sum(u, v)` becomes "make `u` the root, then expose `v`"

So the structure never commits to one permanent heavy-light or Euler order.

It keeps changing the internal decomposition to fit the current operation.

## Core Invariants And Why They Work

## 1. The Auxiliary Trees Are Not The Forest

This is the first invariant to internalize.

The represented forest is the real tree/forest from the statement.

The auxiliary splay trees only store preferred paths inside that forest.

So:

- auxiliary parent/child pointers are **not** tree-parent pointers in the represented forest
- `is_root(x)` means "root of the current auxiliary splay tree", not "root of the represented tree"

Mixing those two meanings is the classic LCT bug.

## 2. `access(u)` Exposes Exactly One Root-To-`u` Path

After `access(u)`:

- the preferred path from the represented root to `u` becomes one auxiliary tree
- `u` is splayed to the root of that auxiliary tree
- the whole exposed path is stored in `u`'s splay subtree

This is why every path aggregate eventually reduces to:

```text
expose the path you want,
then read the aggregate from one auxiliary root.
```

## 3. `makeroot(u)` Turns Any Path Query Into A Root-To-Node Query

If we first do:

```text
makeroot(u)
```

then `u` becomes the represented root of its tree.

After that:

```text
access(v)
```

exposes exactly the represented path `u -> v`.

So the standard path-query pattern is:

1. `makeroot(u)`
2. `access(v)`
3. read the aggregate from the auxiliary root at `v`

That is the key reusable route in the starter.

## 4. Path Reversal Must Be Lazy

`makeroot(u)` works by exposing one path and reversing its direction.

So the auxiliary tree needs a lazy reverse flag:

- swap left/right children
- push the reverse marker downward only when needed

If reverse flags are not pushed before rotations, the whole structure quietly corrupts.

This is the implementation invariant that matters most.

## 5. `link` And `cut` Are Structural Sanity Checks, Not Just Pointer Changes

For `link(u, v)`:

- first `makeroot(u)`
- then ensure `u` and `v` are currently in different represented trees
- only then attach

For `cut(u, v)`:

- first `makeroot(u)`
- then `access(v)`
- now the exposed path is exactly `u -> v`
- if `u-v` is an edge, `u` becomes the left child of `v` with no right child

That final shape check is what makes `cut` precise.

## Variant Chooser

### Use Euler Flattening Instead When

- the tree is static
- every query is one rooted subtree interval

Route:

- [Euler Tour / Subtree Queries](../euler-tour-subtree/README.md)

### Use HLD Instead When

- the tree is static
- queries are path aggregates or path updates

Route:

- [Heavy-Light Decomposition](../hld/README.md)

### Use DSU Rollback Instead When

- topology changes are known offline
- only connectivity or component-level state matters
- you do not need online path aggregates

Route:

- [DSU Rollback / Offline Dynamic Connectivity](../../data-structures/dsu-rollback/README.md)

### Use Link-Cut Tree When

- the forest changes online
- the query still talks about one tree path or one dynamic root relation
- you need a data structure, not an offline divide-and-conquer pass

### Compare Against Euler Tour Tree When

- the forest still changes online
- but the live query is one rooted-subtree or one edge-oriented subtree side
- the representation wants sequence split/merge more than preferred-path exposure

Route:

- [Euler Tour Tree](../euler-tour-tree/README.md)

## Worked Examples

### Example 1: Dynamic Tree Vertex Add Path Sum

This is the repo's first exact anchor:

- [Dynamic Tree Vertex Add Path Sum](../../../practice/ladders/graphs/link-cut-tree/dynamictreevertexaddpathsum.md)

Operations:

- add `x` to one vertex
- query sum on path `u -> v`
- cut one existing edge and link one new edge

The reusable translation is:

- `type 1`: `access(u)` then mutate that node value
- `type 2`: `makeroot(u)`, `access(v)`, answer from `sum[v]`
- `type 0`: `cut(a, b)` then `link(c, d)`

The data structure work is not "tree DP".

It is maintaining one dynamic forest where the current preferred paths keep changing.

### Example 2: Why `path_sum(u, v)` Lives At `v`

After:

1. `makeroot(u)`
2. `access(v)`

the whole represented path `u -> v` becomes the exposed preferred path, and `v` is splayed to the auxiliary root of that path.

So if each node stores:

- its own `val`
- subtree aggregate `sum`

then:

$$
path\_sum(u, v) = sum[v]
$$

in the auxiliary tree after those two operations.

That is the compact invariant behind the whole first starter.

## Algorithm And Pseudocode

### Core Node Fields

Each auxiliary-tree node stores:

- `ch[2]`: left/right child in the splay tree
- `p`: auxiliary parent
- `rev`: lazy reverse flag
- `val`: node value
- `sum`: aggregate of the auxiliary subtree

### Core Operations

```text
access(x):
    last = null
    y = x
    while y != null:
        splay(y)
        right[y] = last
        pull(y)
        last = y
        y = parent[y]
    splay(x)
```

```text
makeroot(x):
    access(x)
    toggle_reverse(x)
```

```text
find_root(x):
    access(x)
    while left[x] exists:
        push(x)
        x = left[x]
    splay(x)
    return x
```

```text
link(u, v):
    makeroot(u)
    if find_root(v) == u:
        fail
    parent[u] = v
```

```text
cut(u, v):
    makeroot(u)
    access(v)
    if left[v] != u or right[u] != null:
        fail
    left[v] = null
    parent[u] = null
    pull(v)
```

```text
path_sum(u, v):
    makeroot(u)
    access(v)
    return sum[v]
```

## Complexity And Tradeoffs

- each operation is amortized `O(log n)`
- memory is `O(n)`

Tradeoffs against nearby lanes:

- compared with [Heavy-Light Decomposition](../hld/README.md):
  - LCT handles online topology changes
  - HLD is simpler and usually preferable when the tree is static
- compared with [Euler Tour / Subtree Queries](../euler-tour-subtree/README.md):
  - LCT handles dynamic paths
  - Euler flattening is dramatically simpler for static rooted subtrees
- compared with [DSU Rollback](../../data-structures/dsu-rollback/README.md):
  - LCT is online and path-aware
  - DSU rollback is offline and component-oriented

## Implementation Notes

- The repo starter is **vertex-valued** and exposes **point add + path sum**.
- It does **not** promise:
  - subtree aggregates
  - generic lazy path updates
  - non-commutative path folds
  - edge-valued conventions
- `is_root(x)` means "root of the current auxiliary splay tree".
- Always push reverse flags down the whole splay path before rotating.
- `cut(u, v)` should fail fast if the edge is not present.
- For contest code, choose one exact route first and keep the contract narrow.

## Practice Archetypes

- dynamic forest connectivity with explicit `link` / `cut`
- path sum / max / xor under topology changes
- reroot one tree, then expose/query one new path
- tasks where static HLD would need a full rebuild after each update

## References And Repo Anchors

- original paper: [Sleator and Tarjan - A Data Structure for Dynamic Trees](https://www.cs.cmu.edu/~sleator/papers/dynamic-trees.pdf)
- trusted guide: [USACO Guide - Link Cut Tree](https://usaco.guide/adv/link-cut-tree?lang=cpp)
- trusted guide: [OI Wiki - Link-Cut Tree](https://en.oi-wiki.org/ds/lct/)
- verifier / flagship problem: [Library Checker - Dynamic Tree Vertex Add Path Sum](https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum)

Repo anchors:

- starter: [link-cut-tree-path-sum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/link-cut-tree-path-sum.cpp)
- hot sheet: [Link-Cut Tree hot sheet](../../../notebook/link-cut-tree-hot-sheet.md)
- flagship note: [Dynamic Tree Vertex Add Path Sum](../../../practice/ladders/graphs/link-cut-tree/dynamictreevertexaddpathsum.md)
- static-path compare point: [Heavy-Light Decomposition](../hld/README.md)
- static-subtree compare point: [Euler Tour / Subtree Queries](../euler-tour-subtree/README.md)

## Related Topics

- [Trees](../trees/README.md)
- [Euler Tour / Subtree Queries](../euler-tour-subtree/README.md)
- [Heavy-Light Decomposition](../hld/README.md)
- [Centroid Decomposition](../centroid-decomposition/README.md)
- [DSU Rollback / Offline Dynamic Connectivity](../../data-structures/dsu-rollback/README.md)
