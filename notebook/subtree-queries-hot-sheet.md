# Subtree Queries Hot Sheet

Use this page when the tree is static, the query touches one whole subtree, and you want to flatten that subtree into one interval before choosing a range structure.

## Do Not Use When

- the query is on an arbitrary path `u -> v`, not one subtree
- the real work is combining child states rather than querying a flattened interval
- you only need ancestor checks, so `tin/tout` alone is enough
- the tree itself changes online

## Choose By Signal

- point update on one node + subtree sum/count -> Euler flattening -> [`euler-tour-subtree.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/euler-tour-subtree.cpp)
- subtree-only query but richer range aggregate -> Euler flattening + [Segment Tree hot sheet](segment-tree-hot-sheet.md)
- arbitrary path aggregate -> [HLD hot sheet](hld-hot-sheet.md)
- child-merge optimization -> [DP cheatsheet](dp-cheatsheet.md) or [Tree DP](../topics/dp/tree-dp/README.md)
- ancestor yes/no -> `tin/tout` or [LCA](../topics/graphs/lca/README.md), usually no Fenwick/segment tree needed

## Core Invariants

- this lane uses a **single-entry DFS order**, not the full Euler tour
- `tin[u]` is the flattened position of node `u`
- the subtree of `u` is exactly the half-open interval `[tin[u], tout[u])`
- `tout[u] - tin[u]` equals the subtree size
- node-value update on `u` becomes one point update at `tin[u]`

## Main Traps

- confusing subtree flattening with the full Euler tour used for some LCA reductions
- mixing inclusive subtree ranges from the statement with the half-open internal interval `[tin[u], tout[u])`
- reaching for HLD when the query is subtree-only
- forgetting that point assignment on the original tree becomes a point **delta** update on Fenwick

## Exact Starters In This Repo

- exact starter -> [`euler-tour-subtree.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/euler-tour-subtree.cpp)
- flagship in-lane rep -> [Subtree Queries](../practice/ladders/graphs/euler-tour-subtree/subtreequeries.md)
- tree worldview refresher -> [Trees](../topics/graphs/trees/README.md)
- lighter range engine refresher -> [Fenwick hot sheet](fenwick-hot-sheet.md)
- richer range engine compare point -> [Segment Tree hot sheet](segment-tree-hot-sheet.md)

## Reopen Paths

- full lesson and path-vs-subtree chooser -> [Euler Tour / Subtree Queries](../topics/graphs/euler-tour-subtree/README.md)
- rooted-tree worldview first -> [Trees](../topics/graphs/trees/README.md)
- richer interval engine -> [Segment Tree](../topics/data-structures/segment-tree/README.md)
- arbitrary path queries -> [Heavy-Light Decomposition](../topics/graphs/hld/README.md)
- family chooser -> [Graph cheatsheet](graph-cheatsheet.md)
- snippet chooser -> [Template Library](../template-library.md)
