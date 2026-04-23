# LCA

Lowest Common Ancestor is the standard way to answer ancestor and path-structure queries on rooted trees.

## Prerequisites

- [Trees](../trees/README.md)
- [Sparse Table](../../data-structures/sparse-table/README.md)

## When To Suspect It

- repeated path queries on a tree
- distance or ancestry between two vertices
- “first common ancestor” questions

## Core Idea

The first standard implementation is binary lifting.

Precompute:

- `up[k][v]`: the `2^k`-th ancestor of `v`
- `depth[v]`

Then:

- lift the deeper node up
- lift both nodes together until their ancestors diverge

## Theory / Proof Sketch

Binary lifting works because any upward jump can be decomposed into powers of two.

By equalizing depths first and then jumping from large powers downward, you preserve the invariant that the true LCA is still above both current vertices.

## Complexity And Tradeoffs

- preprocess: `O(n log n)`
- each query: `O(log n)`
- memory: `O(n log n)`

Tradeoffs:

- binary lifting is the easiest first choice
- Euler tour + RMQ gives `O(1)` queries but is heavier conceptually

## Canonical Pattern

Template in this repo:

- [lca-binary-lifting.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/lca-binary-lifting.cpp)

## Worked Examples

Example 1: LCA queries

Example 2: tree distance

```text
dist(u, v) = depth[u] + depth[v] - 2 * depth[lca(u, v)]
```

Example 3: path decomposition into ancestor pieces

## Common Mistakes

- wrong root initialization
- forgetting to guard ancestor table boundaries
- mixing 0-based and 1-based levels

## Practice Ladder

- [LCA ladder](../../../practice/ladders/graphs/lca/README.md)

## Go Deeper

- Reference: [CP-Algorithms - LCA](https://cp-algorithms.com/graph/lca_binary_lifting.html)
- Practice: [CSES Tree Algorithms](https://cses.fi/problemset/)

## Related Topics

- [Trees](../trees/README.md)
- [Sparse Table](../../data-structures/sparse-table/README.md)
