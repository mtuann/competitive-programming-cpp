# Trees

Trees are a special graph family where every pair of vertices has exactly one simple path. That unique-path property powers many clean invariants and is the reason tree problems often deserve their own toolkit.

## Summary

Suspect tree techniques when:

- the graph is connected with `n - 1` edges
- parent, child, subtree, ancestor, or root language appears
- unique paths simplify the structure

What success looks like:

- you can switch comfortably between rooted and unrooted viewpoints
- you can compute parent, depth, and subtree information quickly
- later topics like LCA and tree DP feel like natural extensions, not separate worlds

## Prerequisites

- [Graph Modeling](../graph-modeling/README.md)
- [BFS And DFS](../bfs-dfs/README.md)

## Core Idea

Start with the standard rooted view:

- choose a root
- compute `parent`
- compute `depth`
- compute subtree sizes

Once rooted, many later ideas become simple:

- LCA
- tree DP
- rerooting
- Euler tour based reductions

## Theory / Proof Sketch

The crucial fact is unique paths.

Because there is only one simple path between any two vertices:

- ancestor relations are well-defined after rooting
- subtree decompositions do not overlap unexpectedly
- path formulas like distance through LCA become clean

That unique-path structure is what makes tree algorithms so much easier than general graph algorithms.

## Complexity And Tradeoffs

Most basic tree traversals are `O(n)`.

Representation choices:

- parent / depth arrays for rooted logic
- Euler-tour order when subtree ranges matter
- adjacency list as the default graph representation

Tradeoffs:

- rooted view is perfect for ancestor and subtree questions
- unrooted view is often better for diameter and symmetry reasoning

## Canonical C++ Pattern

Use one DFS or BFS to compute:

- `parent`
- `depth`
- `subtree_size`

That one traversal often sets up several later algorithms at once.

## Standard Patterns

### 1. Rooting The Tree

The first move for many problems.

Once rooted, “subtree” has a precise meaning.

### 2. Diameter

Classic fact:

- BFS/DFS from any node finds one diameter endpoint
- BFS/DFS from that endpoint finds the diameter length

### 3. Subtree Aggregation

Many tree problems ask for values over descendants of a node.

This is the entry point for tree DP.

### 4. Euler Tour View

A DFS order can flatten subtree questions into contiguous ranges, which later connects trees to Fenwick, segment tree, or RMQ-style tools.

## Worked Examples

### Example 1: tree diameter

Run BFS/DFS twice:

1. from any node to find a farthest endpoint
2. from that endpoint to find the true diameter

### Example 2: subtree sizes

In a rooted DFS:

```text
subtree_size[u] = 1 + sum(subtree_size[child])
```

This is one of the most important first tree invariants.

### Example 3: local-to-global reasoning

Tree problems often aggregate child information upward, then sometimes reroot it later.

A strong stretch example in the repo:

- [MTREECOL](../../../practice/ladders/graphs/trees/mtreecol.md)
- [VOSTRIP](../../../practice/ladders/graphs/tree-dp/vostrip.md)
- [VMWTREE](../../../practice/ladders/graphs/trees/vmwtree.md)

## Recognition Cues

Strong clues:

- connected graph with `n - 1` edges
- unique path between nodes
- parent/child/subtree language
- repeated path or ancestor queries

Trees are often confused with:

- general graph traversal, because they still use DFS/BFS
- [LCA](../lca/README.md), which is a tree subtopic rather than a separate modeling universe

## Common Mistakes

- forgetting to avoid revisiting the parent
- mixing rooted and unrooted viewpoints mid-proof
- not defining what subtree arrays actually mean
- assuming every tree problem needs DP when a simple traversal invariant is enough

## Practice Ladder

- [Trees ladder](../../../practice/ladders/graphs/trees/README.md)

Suggested order:

1. rooting and parent/depth
2. subtree sizes
3. diameter
4. Euler-tour intuition

## Go Deeper

- Reference: [USACO Guide - Trees](https://usaco.guide/)
- Reference: [OI Wiki - Tree DP](https://en.oi-wiki.org/dp/tree/)
- Practice: [CSES Tree Algorithms](https://cses.fi/problemset/)
- Next step: [LCA](../lca/README.md)

## Related Topics

- [LCA](../lca/README.md)
- [Tree DP](../../dp/tree-dp/README.md)
- [BFS And DFS](../bfs-dfs/README.md)
