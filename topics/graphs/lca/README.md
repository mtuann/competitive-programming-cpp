# LCA

Lowest Common Ancestor is the standard way to answer ancestor and path-structure queries on rooted trees. Once you understand LCA, many tree-distance and path-decomposition formulas become almost immediate.

## Summary

Suspect LCA when:

- there are repeated path queries on a rooted tree
- you need ancestry, first common ancestor, or tree distances
- path structure between two nodes matters

What success looks like:

- you can implement binary lifting confidently
- you know why equalizing depths is the first step
- you can derive tree distance and path formulas from LCA naturally

## Prerequisites

- [Trees](../trees/README.md)
- [Sparse Table](../../data-structures/sparse-table/README.md)

## Core Idea

The standard first implementation is binary lifting.

Precompute:

- `up[k][v]`: the `2^k`-th ancestor of `v`
- `depth[v]`

To answer `lca(u, v)`:

1. lift the deeper node up to the same depth
2. lift both nodes together from large powers downward
3. the parent of their final divergence point is the LCA

## Theory / Proof Sketch

Binary lifting works because any upward jump can be decomposed into powers of two.

Correctness logic:

- after equalizing depths, the LCA is an ancestor of both current nodes at the same depth
- lifting both from largest power downward preserves the invariant that the true LCA is still above them
- once no larger jump keeps them distinct, their parents match and that parent is the LCA

## Complexity And Tradeoffs

- preprocess: `O(n log n)`
- each query: `O(log n)`
- memory: `O(n log n)`

Tradeoffs:

- binary lifting is the easiest first choice
- Euler tour + RMQ can give `O(1)` queries, but the overall setup is heavier conceptually

## Canonical C++ Pattern

Template in this repo:

- [lca-binary-lifting.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/lca-binary-lifting.cpp)

Standard preprocessing step:

- DFS or BFS from the root to fill `depth` and `up[0]`
- then build the jump table upward

## Standard Patterns

### 1. Plain LCA Queries

Return the first common ancestor of two nodes.

### 2. Tree Distance

Once LCA is known:

```text
dist(u, v) = depth[u] + depth[v] - 2 * depth[lca(u, v)]
```

### 3. Path Decomposition Through The LCA

Path `u -> v` splits into:

- `u -> lca(u, v)`
- `lca(u, v) -> v`

That split is the basis of many later path-query ideas.

## Worked Examples

### Example 1: plain LCA query

Equalize depths, then jump both upward.

This is the core binary-lifting workflow.

### Example 2: tree distance

The distance formula follows immediately from path decomposition through the LCA.

### Example 3: ancestor checks

Binary lifting also helps with ancestor-related logic, especially when combined with Euler-tour entry/exit times.

## Recognition Cues

Strong clues:

- many pair queries on a rooted tree
- “common ancestor”
- tree distance or path queries
- repeated ancestor lifting

LCA is often confused with:

- [Trees](../trees/README.md), because the setup starts there
- [Sparse Table](../../data-structures/sparse-table/README.md), because Euler-tour RMQ is an alternate LCA route

## Common Mistakes

- wrong root initialization
- forgetting to guard ancestor-table boundaries
- mixing 0-based and 1-based jump levels
- trying to solve repeated path queries from scratch each time without preprocessing

## Practice Ladder

- [LCA ladder](../../../practice/ladders/graphs/lca/README.md)

Suggested order:

1. ancestor table construction
2. plain LCA queries
3. tree distance queries
4. path decomposition reasoning

## Go Deeper

- Reference: [CP-Algorithms - LCA](https://cp-algorithms.com/graph/lca_binary_lifting.html)
- Practice: [CSES Tree Algorithms](https://cses.fi/problemset/)
- Next step: [Trees](../trees/README.md)

## Related Topics

- [Trees](../trees/README.md)
- [Sparse Table](../../data-structures/sparse-table/README.md)
- [Shortest Paths](../shortest-paths/README.md)
