# Euler Tour Tree Hot Sheet

Use this page when the forest changes online and the live question is still one **subtree-side** view, not one dynamic path query.

## Do Not Use When

- the tree is static -> [Subtree Queries hot sheet](subtree-queries-hot-sheet.md)
- the live query is one path aggregate -> [Link-Cut Tree hot sheet](link-cut-tree-hot-sheet.md)
- only offline connectivity under add/remove events matters -> [DSU Rollback hot sheet](dsu-rollback-hot-sheet.md)
- the real problem is sequence surgery, not dynamic trees -> [Treap / Implicit Treap hot sheet](treap-hot-sheet.md)

## Choose By Signal

- dynamic `cut / link`, but query is "subtree of `v` where `p` is the parent" -> Euler tour tree -> [`euler-tour-tree-subtree-sum.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/euler-tour-tree-subtree-sum.cpp)
- static rooted subtree interval -> [Subtree Queries hot sheet](subtree-queries-hot-sheet.md)
- dynamic forest with path sums / path connectivity -> [Link-Cut Tree hot sheet](link-cut-tree-hot-sheet.md)
- split/merge sequence instincts need refreshing first -> [Treap / Implicit Treap hot sheet](treap-hot-sheet.md)

## Core Invariants

- each vertex weight lives only on its self-loop token `(u, u)`
- directed edge tokens `(u, v)` and `(v, u)` carry `0`
- after `make_root(p)`, the subtree of adjacent child `v` is exactly the interval from `(p, v)` to `(v, p)`
- `make_root(u)` is a rotation that makes `(u, u)` the first token
- `link(child, parent)` is one splice after `(parent, parent)`

## Main Traps

- overclaiming path-query support from a subtree-side starter
- forgetting to reroot before `cut` or subtree query
- double-counting by storing one vertex on multiple tokens
- mixing static Euler flattening with dynamic Euler tour trees
- forgetting that the flagship query needs an **existing edge** `(v, p)`, not an arbitrary root parameter

## Exact Starter Route

- exact starter -> [`euler-tour-tree-subtree-sum.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/euler-tour-tree-subtree-sum.cpp)
- flagship rep -> [Dynamic Tree Vertex Add Subtree Sum](../practice/ladders/graphs/euler-tour-tree/dynamictreevertexaddsubtreesum.md)
- static contrast -> [Subtree Queries hot sheet](subtree-queries-hot-sheet.md)
- dynamic path contrast -> [Link-Cut Tree hot sheet](link-cut-tree-hot-sheet.md)

## Reopen Paths

- full lesson -> [Euler Tour Tree](../topics/graphs/euler-tour-tree/README.md)
- family chooser -> [Graph cheatsheet](graph-cheatsheet.md)
- sequence intuition -> [Treap / Implicit Treap hot sheet](treap-hot-sheet.md)
- snippet chooser -> [Template Library](../template-library.md)

