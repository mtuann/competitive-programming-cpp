# Link-Cut Tree Hot Sheet

Use this page when the forest changes online and you still need path connectivity or one path aggregate to stay logarithmic.

## Do Not Use When

- the tree is static -> [HLD hot sheet](hld-hot-sheet.md) or [Subtree Queries hot sheet](subtree-queries-hot-sheet.md)
- queries are rooted-subtree only -> [Subtree Queries hot sheet](subtree-queries-hot-sheet.md)
- updates are offline add/remove events with component-only answers -> [DSU Rollback hot sheet](dsu-rollback-hot-sheet.md)
- you are still learning rooted-tree basics or path decomposition from scratch

## Choose By Signal

- static tree, repeated path aggregates -> [HLD hot sheet](hld-hot-sheet.md)
- static rooted subtree interval -> [Subtree Queries hot sheet](subtree-queries-hot-sheet.md)
- static balanced recursive split through one pivot -> [Centroid hot sheet](centroid-hot-sheet.md)
- dynamic forest with `link / cut / connected / path-sum` -> link-cut tree -> [`link-cut-tree-path-sum.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/link-cut-tree-path-sum.cpp)
- offline connectivity under edge add/remove -> [DSU Rollback hot sheet](dsu-rollback-hot-sheet.md)

## Core Invariants

- the represented forest and the auxiliary splay trees are different objects
- `access(u)` exposes one represented root-to-`u` path
- `makeroot(u)` is `access(u)` plus a lazy path reversal
- after `makeroot(u)` then `access(v)`, the whole path `u -> v` sits in `v`'s auxiliary tree
- `is_root(x)` means root of the current auxiliary splay tree, not root of the represented tree

## Main Traps

- rotating before pushing reverse flags
- reading auxiliary parents as represented-tree parents
- using LCT for static trees where HLD or Euler flattening is simpler
- overclaiming subtree support from a path-only starter
- forgetting that the exact repo starter is **vertex-valued point-add + path-sum**

## Exact Starter Route

- exact starter -> [`link-cut-tree-path-sum.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/link-cut-tree-path-sum.cpp)
- flagship rep -> [Dynamic Tree Vertex Add Path Sum](../practice/ladders/graphs/link-cut-tree/dynamictreevertexaddpathsum.md)
- machinery refresher -> [Splay Tree hot sheet](splay-tree-hot-sheet.md)
- static path contrast -> [HLD hot sheet](hld-hot-sheet.md)
- static subtree contrast -> [Subtree Queries hot sheet](subtree-queries-hot-sheet.md)

## Reopen Paths

- full lesson -> [Link-Cut Tree](../topics/graphs/link-cut-tree/README.md)
- underlying rotate/splay lane -> [Splay Tree](../topics/data-structures/splay-tree/README.md)
- static path queries instead -> [Heavy-Light Decomposition](../topics/graphs/hld/README.md)
- subtree-only routing instead -> [Euler Tour / Subtree Queries](../topics/graphs/euler-tour-subtree/README.md)
- graph-family chooser -> [Graph cheatsheet](graph-cheatsheet.md)
- snippet chooser -> [Template Library](../template-library.md)
