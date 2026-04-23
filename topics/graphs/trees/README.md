# Trees

Trees are a special graph family where every pair of vertices has exactly one simple path. That unique-path property powers many clean invariants.

## Prerequisites

- [Graph Modeling](../graph-modeling/README.md)
- [BFS And DFS](../bfs-dfs/README.md)

## When To Suspect It

- the graph has `n - 1` edges and is connected
- parent / child / subtree language appears
- unique paths simplify the problem structure

## Core Idea

Start with:

- rooting the tree
- parent / depth
- subtree size
- Euler tour intuition

Then many later ideas become natural:

- LCA
- tree DP
- rerooting

## Theory / Proof Sketch

The crucial fact is unique paths.

Because there is only one simple path between two vertices:

- ancestor relations are well-defined after rooting
- subtree decompositions do not overlap unexpectedly

## Complexity And Tradeoffs

Most basic tree traversals are `O(n)`.

The main tradeoff is representation:

- parent/depth arrays for rooted logic
- Euler-tour order when subtree ranges matter

## Canonical Pattern

Use DFS or BFS once to compute:

- `parent`
- `depth`
- `subtree_size`

## Worked Examples

Example 1: tree diameter

Example 2: subtree aggregation

Example 3: local-to-global reasoning

- [VOSTRIP](../../../practice/ladders/graphs/tree-dp/vostrip.md) is a strong stretch example

## Common Mistakes

- forgetting to avoid revisiting the parent
- mixing rooted and unrooted viewpoints
- not defining what the subtree arrays actually mean

## Practice Ladder

- [Trees ladder](../../../practice/ladders/graphs/trees/README.md)

## Go Deeper

- Reference: [USACO Guide - Trees](https://usaco.guide/)
- Reference: [OI Wiki - Tree DP](https://en.oi-wiki.org/dp/tree/)
- Practice: [CSES Tree Algorithms](https://cses.fi/problemset/)

## Related Topics

- [LCA](../lca/README.md)
- [BFS And DFS](../bfs-dfs/README.md)
