# DSU

Disjoint Set Union is the standard structure for maintaining connected components under merges. It is one of the most reusable contest tools because many graph and grouping problems reduce to “are these in the same component?” plus “merge these two components.”

## Summary

Suspect DSU when:

- edges are added over time
- the main question is connectivity or component membership
- groups merge but almost never split
- Kruskal, offline connectivity, or grouping by equivalence is nearby

What success looks like:

- you can implement `find` and `unite` from memory
- you know when DSU is the right abstraction and when it is too weak
- you can attach simple component metadata like size or sum safely

## Prerequisites

- [Foundations](../../foundations/README.md)

## Core Idea

Each component has a representative root.

Two operations matter:

- `find(x)`: return the root of the component containing `x`
- `unite(a, b)`: merge the two components if they differ

The two classic optimizations are:

- path compression
- union by size or rank

Together they make DSU extremely fast in practice.

## Theory / Proof Sketch

The invariant is:

```text
every node points, directly or indirectly, to the root of its component
```

Path compression:

- after calling `find(x)`, make nodes on the path point closer to the root
- this preserves the partition into components

Union by size:

- always attach the smaller tree under the larger one
- this keeps trees shallow over time

These two heuristics lead to amortized running time that is effectively constant for contest purposes.

## Complexity And Tradeoffs

For `m` operations on `n` elements:

- amortized time per operation: effectively `O(1)`
- memory: `O(n)`

Tradeoffs:

- excellent for merges and connectivity
- poor for arbitrary deletions or split operations
- not suitable for path queries or ordered range aggregates by itself

## Canonical C++ Pattern

Template in this repo:

- [dsu-basic.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/dsu-basic.cpp)

Typical fields:

- `parent[x]`
- `size[x]`
- optional metadata on the root only

Standard pattern:

```cpp
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
```

Metadata rule:

- if metadata belongs to the component, store and update it only at the root

## Standard Patterns

### 1. Connectivity Under Edge Additions

Add each edge and use `find(u) == find(v)` to answer connectivity.

### 2. Cycle Detection In An Undirected Graph

If an edge joins two vertices already in the same component, adding it forms a cycle.

### 3. Kruskal's Algorithm

Sort edges by weight and take an edge only if it joins different components.

### 4. Offline Grouping / Compression

Use DSU whenever the statement defines an equivalence relation or repeated merge steps:

- same color group
- same friend group
- same reachable cluster under processed conditions

## Worked Examples

### Example 1: count connected components

Initialize each node as its own parent.

For every edge, `unite(u, v)`.

At the end, count how many indices are their own root.

### Example 2: cycle detection

Before merging an undirected edge `(u, v)`:

```text
if find(u) == find(v), then a cycle already exists
```

This is one of the cleanest DSU applications.

### Example 3: Kruskal

Sort edges by increasing weight.

For each edge:

- if the endpoints are in different components, take the edge and unite them
- otherwise skip it

Why it works:

- DSU answers exactly the question Kruskal needs: would this edge connect two different components?

## Recognition Cues

Strong clues:

- “merge groups”
- “same connected component?”
- edges only get added, not removed
- the problem can be processed offline in sorted order

DSU is often confused with:

- [BFS And DFS](../../graphs/bfs-dfs/README.md), which handle one-shot connectivity on a fixed graph
- [Fenwick Tree](../fenwick-tree/README.md), because both are light and fast structures but solve very different problems

## Common Mistakes

- forgetting to initialize `parent[x] = x`
- updating component metadata on non-root nodes
- mixing node size with root component size
- trying to use DSU for problems with essential deletions
- assuming DSU answers shortest paths or general path properties

## Practice Ladder

- [Data structures ladder](../../../practice/ladders/data-structures/README.md)
- [DSU ladder](../../../practice/ladders/data-structures/dsu/README.md)

Suggested order:

1. connectivity and component counting
2. cycle detection
3. Kruskal
4. DSU with component metadata

## Go Deeper

- Reference: [CP-Algorithms - DSU](https://cp-algorithms.com/data_structures/disjoint_set_union.html)
- Reference: [USACO Guide - DSU](https://usaco.guide/gold/dsu)
- Practice: [CSES Graph Algorithms](https://cses.fi/problemset/)
- Next step: [Minimum Spanning Tree](../../graphs/mst/README.md)

## Related Topics

- [Minimum Spanning Tree](../../graphs/mst/README.md)
- [Graphs](../../graphs/README.md)
- [Fenwick Tree](../fenwick-tree/README.md)
