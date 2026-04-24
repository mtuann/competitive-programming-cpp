# Heavy-Light Decomposition

Heavy-light decomposition is the standard way to answer repeated path queries on a tree by reducing them to range queries on an array. It is the natural next step after trees, LCA, and segment trees already feel comfortable on their own.

## Summary

Suspect HLD when:

- the input is a static tree
- queries ask for a sum, maximum, or another aggregate on the path between two nodes
- updates happen on node or edge values

What success looks like:

- you can choose a heavy child and explain why that keeps the number of chains small
- you can flatten the tree into a base array with `head[u]` and `pos[u]`
- path queries feel like “a few segment-tree intervals” instead of “walk the whole path”

## Prerequisites

- [Trees](../trees/README.md)
- [LCA](../lca/README.md)
- [Segment Tree](../../data-structures/segment-tree/README.md)

## Core Idea

Root the tree first.

For each node, mark one child as **heavy**, usually the child with the largest subtree. The remaining child edges are **light**.

Then:

- heavy edges keep you inside one chain
- each chain has a `head`
- each node gets a position `pos[u]` in a flattened base array

To answer a query on the path between `u` and `v`:

1. while `head[u] != head[v]`, move the deeper chain head upward
2. query the whole chain segment you just consumed
3. once both nodes are on the same chain, query the final interval between them

That turns a tree-path problem into a small number of array-range queries.

## Theory / Proof Sketch

The key fact is that crossing a light edge shrinks the remaining subtree quickly.

If `v` is a light child of `u`, then `v` is not the heaviest child, so:

```text
subtree(v) <= subtree(u) / 2
```

Therefore any root-to-node path can cross at most `O(log n)` light edges.

Every time HLD jumps from one chain to another, it crosses one light edge. So a path between two nodes touches only `O(log n)` chains. If each chain segment is answered with a segment tree in `O(log n)`, the standard HLD query cost is:

```text
O(log n) chain segments * O(log n) per segment = O(log^2 n)
```

## Complexity And Tradeoffs

- preprocessing subtree sizes and heavy child: `O(n)`
- decomposition into chains: `O(n)`
- point update or path query with segment tree: `O(log^2 n)`

Tradeoffs:

- HLD is much more general than plain LCA formulas
- if you only need subtree queries, Euler-tour flattening is usually simpler
- if the path aggregate is especially friendly, there are sometimes lighter special-case tricks

## Canonical C++ Pattern

A standard first implementation has three pieces:

1. DFS for `parent`, `depth`, `subtree_size`, and `heavy_child`
2. DFS for `head[u]` and `pos[u]`
3. segment tree on the flattened base array

The debugging trick is to verify each layer separately:

- subtree sizes are correct
- heavy child is the largest child
- chain heads and positions make sense on a small tree
- same-chain and cross-chain path cases both work

## Standard Patterns

### 1. Path Maximum Or Sum

The classic entry problem. Decompose the path, query each segment, and merge the answers.

### 2. Point Update, Path Query

Very common in contests: the tree shape is fixed, but node values change.

### 3. Edge-Valued Variants

Still HLD, but you must be careful about whether a position stores a node value or the edge to its parent.

## Worked Examples

### Example 1: path maximum

Climb the deeper chain head until both endpoints share a head, then finish with one last range maximum on that chain.

### Example 2: point update

Update the single flattened index `pos[u]`. The chain decomposition itself never changes.

### Example 3: subtree interval

HLD also gives DFS-style positions, so subtree queries can often become one contiguous interval. That is a good sanity check while debugging your flattening.

## Recognition Cues

Strong clues:

- static tree
- many path queries
- many updates on node or edge values
- constraints too large for per-query DFS

HLD is often confused with:

- [LCA](../lca/README.md), which helps describe the path but not arbitrary path aggregates
- Euler-tour flattening, which is perfect for subtree queries but not enough for general `u -> v` path queries

## Common Mistakes

- forgetting the final same-chain segment after the main loop
- climbing the shallower chain instead of the deeper one
- mixing node values and edge values without shifting indices carefully
- not reordering endpoints by depth for the final same-chain query
- reaching for HLD when a plain subtree interval would already solve the problem

## Practice Ladder

- [Heavy-Light Decomposition ladder](../../../practice/ladders/graphs/hld/README.md)

Suggested order:

1. chain decomposition and indexing
2. point update plus path maximum
3. edge-valued or path-update variants

## Go Deeper

- Reference: [CP-Algorithms - Heavy-Light Decomposition](https://cp-algorithms.com/graph/hld.html)
- Reference: [USACO Guide - HLD](https://usaco.guide/plat/hld?lang=cpp)
- Reference: [OI Wiki - HLD](https://en.oi-wiki.org/graph/hld/)
- Practice: [CSES Tree Algorithms](https://cses.fi/problemset/)

## Related Topics

- [Trees](../trees/README.md)
- [LCA](../lca/README.md)
- [Segment Tree](../../data-structures/segment-tree/README.md)
