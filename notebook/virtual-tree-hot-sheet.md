# Virtual Tree Hot Sheet

Use this page when one static rooted tree gets many queries, each query marks only a small subset of nodes, and the real answer should be computed on the compressed union of marked paths instead of on the full tree.

## Do Not Use When

- every node is active anyway, so there is nothing to compress
- the query is subtree-only, so Euler flattening already solves it
- the real primitive is online path aggregate on the original tree, so HLD fits better
- the tree topology changes online

## Choose By Signal

- one query gives a small set of marked/special/important nodes -> virtual tree -> [`virtual-tree.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/virtual-tree.cpp)
- only LCA / ancestor / distance is needed -> [LCA](../topics/graphs/lca/README.md)
- whole tree participates once in one child-merge DP -> [Tree DP](../topics/dp/tree-dp/README.md)
- static path aggregate/update queries on original tree -> [HLD hot sheet](hld-hot-sheet.md)

## Core Invariants

- sort marked vertices by DFS preorder `tin`
- it is enough to add LCAs of consecutive marked vertices in that order
- after sorting and deduplicating again, the kept set has `O(k)` size
- parent relation in the compressed tree is built by one ancestor stack
- each virtual edge represents one original path segment with no other kept vertex inside it

## Main Traps

- adding LCAs of all pairs instead of only consecutive-by-`tin` pairs
- forgetting to sort and deduplicate after LCA insertion
- building the compressed tree but forgetting to carry original-path metadata such as depth difference or min cut cost
- mixing "virtual tree" with "auxiliary splay tree" from link-cut tree terminology

## Exact Starters In This Repo

- exact starter -> [`virtual-tree.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/virtual-tree.cpp)
- flagship in-lane rep -> [Kingdom and its Cities](../practice/ladders/graphs/virtual-tree/kingdomanditscities.md)
- prerequisite refresher -> [LCA](../topics/graphs/lca/README.md)
- DP follow-up -> [Tree DP](../topics/dp/tree-dp/README.md)
- path-query contrast -> [HLD hot sheet](hld-hot-sheet.md)

## Reopen Paths

- full lesson -> [Virtual Tree / Auxiliary Tree](../topics/graphs/virtual-tree/README.md)
- family chooser -> [Graph cheatsheet](graph-cheatsheet.md)
- snippet chooser -> [Template Library](../template-library.md)

