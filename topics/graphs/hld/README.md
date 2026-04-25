# Heavy-Light Decomposition

Heavy-light decomposition is the standard reduction for this kind of tree problem:

- the tree is static
- the values may change
- each query asks about an aggregate on a path `u -> v`

The brute-force instinct is:

- find the path
- walk along every vertex or edge on that path

Heavy-light decomposition replaces that with a much stronger statement:

- every tree path can be broken into only `O(\log n)` contiguous segments of one flattened array

That is the whole reason HLD is useful.

It is not a new query structure by itself.

It is the decomposition that lets a standard range structure such as a segment tree answer tree-path queries.

## At A Glance

- **Use when:** the input is a static tree and you need many path queries or updates on node/edge values
- **Core worldview:** choose one heavy child per node so any root-to-node route crosses only `O(\log n)` light edges
- **Main tools:** subtree sizes, heavy child, chain heads, flattened positions, segment tree or Fenwick tree on the base array
- **Typical complexity:** preprocessing `O(n)`, path query/update usually `O(\log^2 n)` with a segment tree
- **Main trap:** mixing node-valued and edge-valued conventions, or forgetting that non-commutative merges need left/right accumulation order

## Prerequisites

- [Trees](../trees/README.md)
- [LCA](../lca/README.md)
- [Segment Tree](../../data-structures/segment-tree/README.md)

Helpful neighboring topics:

- [Tree DP](../../dp/tree-dp/README.md)
- [Fenwick Tree](../../data-structures/fenwick-tree/README.md)

## Problem Model And Notation

Let the tree be rooted at some vertex, usually `1`.

For each vertex `u`, we keep:

- `parent[u]`
- `depth[u]`
- `size[u]`: subtree size
- `heavy[u]`: the child of `u` with maximum subtree size, or `-1` if none
- `head[u]`: the head of the heavy chain containing `u`
- `pos[u]`: the position of `u` in the flattened base array

The base array is arranged so that each heavy chain occupies a contiguous interval.

If values live on vertices, a common convention is:

$$
\mathrm{base}[\mathrm{pos}[u]] = \mathrm{value}[u].
$$

If values live on edges, the standard shift is:

- store the value of edge `(parent[u], u)` at `pos[u]`
- leave the root position as a dummy or neutral value

This page uses the vertex-valued convention as the default because it matches the repo's first HLD anchor.

## From Brute Force To The Right Idea

### Brute Force: Walk The Whole Path

Suppose a query asks for:

- sum on path `u -> v`
- maximum on path `u -> v`
- point updates, edge updates, or both

The brute-force solution is:

1. recover the path
2. scan every vertex or edge on it
3. merge the answers

That costs:

$$
O(\text{path length})
$$

per query, which is too slow when both:

- `n` is large
- the number of queries is large

### The First Shift: Do Not Fight The Tree One Query At A Time

The right question is not:

- how do I walk this path faster?

It is:

- how do I flatten the tree so path queries become a few range queries?

### The Second Shift: Pick One Heavy Child

For each node `u`, choose one child with largest subtree as the heavy child.

All other child edges are light.

This makes heavy edges represent "the direction where the subtree stays large for as long as possible."

### The Third Shift: Light Edges Are Rare On Any Root Path

If `(u, v)` is a light edge and `v` is a child of `u`, then `v` is not the largest child.

So:

$$
\mathrm{size}[v] \le \frac{\mathrm{size}[u] - 1}{2} < \frac{\mathrm{size}[u]}{2}.
$$

Every time you cross a light edge while going downward, the remaining subtree size at least halves.

That can happen only `O(\log n)` times before the subtree size falls to `1`.

This is the theorem that makes HLD worth learning.

### The Fourth Shift: Turn Chains Into Intervals

Once heavy edges are chosen, each maximal heavy path becomes a chain.

If we assign positions by walking each chain contiguously, then:

- every chain becomes one interval in the base array
- a path query can be answered by climbing chain heads
- each climb consumes one whole chain segment

Now the tree problem has become:

- `O(\log n)` chain segments
- each answered by a normal range query structure

## Core Invariants And Why They Work

## 1. Heavy-Child Invariant

For every non-leaf node `u`, at most one child is designated heavy.

That alone implies:

- heavy paths are vertex-disjoint if viewed as chains of vertices
- every vertex belongs to exactly one heavy chain

So `head[u]` is always well-defined.

## 2. Light-Edge Halving Lemma

If `v` is a light child of `u`, then:

$$
\mathrm{size}[v] < \frac{\mathrm{size}[u]}{2}.
$$

Why?

Because the heavy child is chosen with maximum subtree size, so every light child is no larger than the heavy child. If a light child had size more than half of `size[u]`, there would be no room for the rest of the subtree.

This gives the key consequence:

```text
Any root-to-node path crosses at most O(log n) light edges.
```

## 3. Path-Decomposition Invariant

Consider a query path from `u` to `v`.

While `head[u] != head[v]`, one of the two vertices lies on a deeper chain head.

Suppose `head[u]` is deeper.

Then the segment:

$$
[\mathrm{pos}[\mathrm{head}[u]], \mathrm{pos}[u]]
$$

lies entirely on the query path and can be consumed at once.

After consuming it, we jump:

$$
u \leftarrow \mathrm{parent}[\mathrm{head}[u]].
$$

This crosses exactly one light edge.

Since only `O(\log n)` light-edge crossings are possible on either side, the number of chain segments is also `O(\log n)`.

## 4. Why The Final Same-Chain Segment Is One Interval

Eventually, `u` and `v` land on the same chain.

Then the remaining path is just one contiguous chain interval:

$$
[\min(\mathrm{pos}[u], \mathrm{pos}[v]), \max(\mathrm{pos}[u], \mathrm{pos}[v])].
$$

This is the most common missing line in first HLD implementations:

- the loop handles cross-chain parts
- the final same-chain segment is still required

## 5. Node-Valued vs Edge-Valued Convention

This is the most important modeling choice to decide *before* coding.

### Vertex values

Store:

$$
\mathrm{value}[u] \text{ at } \mathrm{pos}[u].
$$

Then a same-chain query includes both endpoints.

### Edge values

Store:

$$
\mathrm{value}(parent[u], u) \text{ at } \mathrm{pos}[u].
$$

Then:

- the root has no incoming edge value
- when querying the path to the LCA, you usually exclude the LCA position itself

Many off-by-one bugs in HLD are not array bugs. They are convention bugs.

## 6. Non-Commutative Aggregates Need Ordered Accumulators

If the merge operation is commutative, like:

- sum
- min
- max
- gcd

then you may merge chain pieces in any order.

But if the aggregate is non-commutative, such as:

- string concatenation
- matrix product
- function composition

then path order matters.

In that case you must usually maintain:

- a left accumulator for pieces collected from `u` upward
- a right accumulator for pieces collected from `v` upward

and combine them in the final path order.

This is a subtle point, but it is exactly what separates "HLD for max/sum" from "HLD as a general path decomposition framework."

## Variant Chooser

### Use HLD When

- the tree is static
- queries are on arbitrary paths `u -> v`
- values may update online
- the aggregate is associative, so a segment tree or similar structure can merge intervals

Canonical examples:

- path sum
- path maximum
- path xor
- point update + path query

### Use Euler Tour Flattening Instead When

- you only need subtree queries
- no arbitrary path queries are required

Then a subtree is already one contiguous interval, so HLD is unnecessary overhead.

### Use Simpler LCA Formulas Instead When

- the path answer can be derived from prefix-like root information
- updates are absent or extremely simple

For example, with static node weights and only path sums, one may sometimes combine:

- root-prefix sums
- LCA

without needing HLD at all.

### Use Tree DP Or Rerooting Instead When

- the problem is about computing one value for every node or subtree
- not about answering many online path queries

HLD is a query/update data-structure reduction, not a replacement for tree DP.

### Use Link-Cut Trees Or Other Dynamic-Tree Tools Instead When

- the tree topology itself changes online
- exact repo route: [Link-Cut Tree](../link-cut-tree/README.md)

HLD assumes the tree is fixed during all queries.

## Worked Examples

### Example 1: Path Maximum With Point Updates

This is the repo's main HLD anchor:

- [Path Queries II](../../../practice/ladders/graphs/hld/pathqueries2.md)

Suppose values live on vertices and queries ask:

- update one vertex value
- query maximum on path `u -> v`

Then:

- update becomes one point update at `pos[u]`
- path query becomes repeated chain climbs plus one final same-chain segment

Because `max` is commutative, the order of consumed chain segments does not matter.

### Example 2: Why The Deeper Head Must Move

Suppose `head[u] != head[v]`.

If you move the shallower chain upward first, you may skip part of the true path or fail to shrink the problem properly.

The correct rule is:

- compare `depth[head[u]]` and `depth[head[v]]`
- always consume the deeper head segment first

That guarantees the consumed interval lies fully inside the query path.

### Example 3: Edge-Valued Path Sum

Suppose edge `(parent[x], x)` stores a weight at `pos[x]`.

If `u` and `v` finally land on the same chain and `w` is the shallower endpoint on that chain, then the final interval is usually:

$$
[\mathrm{pos}[w] + 1, \mathrm{pos}[\text{deeper endpoint}]]
$$

not the inclusive vertex interval.

That `+1` is the classic edge-valued HLD adjustment.

### Example 4: Subtree Query As A Sanity Check

Although HLD is built for arbitrary paths, the flattening order still gives each subtree a contiguous interval:

$$
[\mathrm{pos}[u], \mathrm{pos}[u] + \mathrm{size}[u] - 1].
$$

This is not the main reason to use HLD, but it is a very useful debugging check:

- if subtree intervals are broken, your decomposition order is wrong

## Algorithms And Pseudocode

### Preprocessing

First DFS:

- compute `parent`
- compute `depth`
- compute `size`
- choose `heavy`

Second DFS:

- assign `head`
- assign `pos`
- write vertex or edge values into the base array

### Standard Path Query Loop

The skeleton below is the default for:

- node-valued or edge-valued HLD
- **commutative** aggregates such as sum, min, max, xor, gcd

To avoid the most common API confusion, write the range query using one convention explicitly.

Here we use:

- `seg.query_inclusive(l, r)` for a closed interval `[l, r]`

If your segment-tree API uses half-open ranges `[l, r)`, replace every call below by:

- `seg.query(l, r + 1)`

```text
query_path(u, v):
    ans = identity

    while head[u] != head[v]:
        if depth[head[u]] < depth[head[v]]:
            swap(u, v)
        ans = merge(ans, seg.query_inclusive(pos[head[u]], pos[u]))
        u = parent[head[u]]

    if depth[u] > depth[v]:
        swap(u, v)

    ans = merge(ans, seg.query_inclusive(pos[u], pos[v]))
    return ans
```

For edge-valued queries, the final same-chain segment becomes:

```text
seg.query_inclusive(pos[u] + 1, pos[v])
```

if `u` is the LCA-side endpoint on that chain.

### Ordered Path Query Skeleton

If the aggregate is **non-commutative**, the path order matters, so one accumulator is no longer enough.

The standard fix is:

- `left_acc` gathers pieces climbed from the `u` side
- `right_acc` gathers pieces climbed from the `v` side
- the final answer concatenates them in true path order

```text
query_path_ordered(u, v):
    left_acc = identity
    right_acc = identity

    while head[u] != head[v]:
        if depth[head[u]] >= depth[head[v]]:
            left_acc = merge(
                left_acc,
                query_chain_reversed(pos[head[u]], pos[u])
            )
            u = parent[head[u]]
        else:
            right_acc = merge(
                query_chain_forward(pos[head[v]], pos[v]),
                right_acc
            )
            v = parent[head[v]]

    if depth[u] > depth[v]:
        middle = query_chain_reversed(pos[v], pos[u])
    else:
        middle = query_chain_forward(pos[u], pos[v])

    return merge(left_acc, merge(middle, right_acc))
```

The exact `query_chain_forward` / `query_chain_reversed` interface depends on your segment structure, but the path-order idea is always the same.

### Point Update

```text
update_vertex(u, new_value):
    seg.set_value(pos[u], new_value)
```

### Complexity

With an `O(\log n)` segment-tree range query:

- preprocessing: `O(n)`
- point update: `O(\log n)`
- path query: `O(\log^2 n)`

Some special cases can be pushed to `O(\log n)` by storing richer prefix information per chain, but `O(\log^2 n)` is the standard contest baseline.

## Implementation Notes

- Decide node-valued vs edge-valued before writing any query code.
- The root convention must be explicit; edge-valued HLD needs a dummy or neutral value at the root position.
- The repo's first practical path-query implementation is node-valued, which is the best entry point.
- The heavy child is usually chosen by largest subtree size. Ties do not affect correctness.
- The segment tree size does **not** require `n` to be a power of two if your implementation already handles arbitrary `n`.
- State your range-query convention explicitly: either closed `[l, r]` or half-open `[l, r)`. HLD off-by-one bugs are very often API-convention bugs.
- For non-commutative merges, keep two accumulators and combine them in the correct path order.
- If recursion depth is risky, both DFS passes can be made iterative, but a recursive version is usually easier to understand first.

## Practice Archetypes

You should strongly suspect HLD when you see:

- static tree
- many queries on arbitrary paths
- many point updates on nodes or edges
- path sum / max / xor / gcd with constraints too large for per-query DFS

Repo anchors:

- [Path Queries II](../../../practice/ladders/graphs/hld/pathqueries2.md)
- [LCA](../lca/README.md)
- [Segment Tree](../../data-structures/segment-tree/README.md)

Starter pieces in the repo:

- [hld-path-max.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/hld-path-max.cpp)
- [Path Queries II note](../../../practice/ladders/graphs/hld/pathqueries2.md)

Notebook refresher:

- [Graph cheatsheet](../../../notebook/graph-cheatsheet.md)

## References And Repo Anchors

Course / tutorial style:

- [CP-Algorithms: Heavy-Light Decomposition](https://cp-algorithms.com/graph/hld.html)
- [USACO Guide: Heavy-Light Decomposition](https://usaco.guide/plat/hld?lang=cpp)
- [OI Wiki: Heavy-Light Decomposition](https://en.oi-wiki.org/graph/hld/)

Practice / repo anchors:

- [Heavy-Light Decomposition ladder](../../../practice/ladders/graphs/hld/README.md)
- [Path Queries II](../../../practice/ladders/graphs/hld/pathqueries2.md)
- [Segment Tree](../../data-structures/segment-tree/README.md)

## Related Topics

- [Trees](../trees/README.md)
- [LCA](../lca/README.md)
- [Segment Tree](../../data-structures/segment-tree/README.md)
- [Tree DP](../../dp/tree-dp/README.md)
