# Euler Tour Tree Ladder

This ladder is for the first dynamic-tree lane where the reusable story is:

- maintain one Euler-tour sequence of a changing forest
- reroot by rotation
- cut and link by split/merge
- answer one subtree-side interval query

It is intentionally a thin lane:

- one exact starter
- one flagship verifier-style rep
- strong compare points back to static subtree flattening, link-cut trees, and split/merge sequence tools

## Who This Is For

Use this lane if:

- [Euler Tour / Subtree Queries](../../../../topics/graphs/euler-tour-subtree/README.md) already feels comfortable
- [Treap / Implicit Treap](../../../../topics/data-structures/treap-implicit/README.md) no longer feels mysterious
- you can already distinguish subtree-side queries from path queries in dynamic trees

## Warm-Up

- why self-loop tokens carry the vertex values
- why an edge-oriented subtree is the interval `(p, v) ... (v, p)` after `make_root(p)`
- why rerooting is one sequence rotation, not a DFS rebuild

Target skill:

- explain why dynamic rooted-subtree queries can still be interval queries if the sequence itself becomes dynamic

Warm-up compare points:

- [Euler Tour / Subtree Queries](../../../../topics/graphs/euler-tour-subtree/README.md)
- [Treap / Implicit Treap](../../../../topics/data-structures/treap-implicit/README.md)

## Core

- represent one tree by self-loops and directed edge tokens
- `make_root(u)` by rotation around `(u, u)`
- `cut(u, v)` after rerooting `u`
- `link(child, parent)` by splicing a whole child sequence after `(parent, parent)`
- flagship rep: [Dynamic Tree Vertex Add Subtree Sum](dynamictreevertexaddsubtreesum.md)

Target skill:

- know when the live query is subtree-side enough for ETT and when it has crossed into link-cut territory

## Stretch

- [Library Checker - Dynamic Tree Subtree Add Subtree Sum](https://judge.yosupo.jp/problem/dynamic_tree_subtree_add_subtree_sum)
- [OI Wiki - Euler Tour Tree](https://en.oi-wiki.org/ds/ett/)
- [USACO Guide Link-Cut Tree](https://usaco.guide/adv/link-cut-tree?lang=cpp)

Target skill:

- separate the representation trick from the extra monoid or lazy layer that a harder dynamic-tree problem adds later

## Retrieval Layer

- exact quick sheet -> [Euler Tour Tree hot sheet](../../../../notebook/euler-tour-tree-hot-sheet.md)
- exact starter -> [euler-tour-tree-subtree-sum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/euler-tour-tree-subtree-sum.cpp)
- static subtree compare point -> [Subtree Queries hot sheet](../../../../notebook/subtree-queries-hot-sheet.md)
- dynamic path compare point -> [Link-Cut Tree hot sheet](../../../../notebook/link-cut-tree-hot-sheet.md)

## Repo Anchors And Compare Points

- topic page -> [Euler Tour Tree](../../../../topics/graphs/euler-tour-tree/README.md)
- flagship note -> [Dynamic Tree Vertex Add Subtree Sum](dynamictreevertexaddsubtreesum.md)
- static subtree compare point -> [Euler Tour / Subtree Queries](../../../../topics/graphs/euler-tour-subtree/README.md)
- dynamic path compare point -> [Link-Cut Tree](../../../../topics/graphs/link-cut-tree/README.md)
- split/merge sequence compare point -> [Treap / Implicit Treap](../../../../topics/data-structures/treap-implicit/README.md)
- broader routing -> [Graphs ladder](../README.md)

The cleanest in-repo loop here is:

1. reopen [Euler Tour / Subtree Queries](../../../../topics/graphs/euler-tour-subtree/README.md) until static subtree intervals feel automatic
2. trust the split/merge instincts from [`euler-tour-tree-subtree-sum.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/euler-tour-tree-subtree-sum.cpp)
3. solve or revisit [Dynamic Tree Vertex Add Subtree Sum](dynamictreevertexaddsubtreesum.md)
4. only then jump to lazy subtree updates or sibling dynamic-tree structures

## Exit Criteria

You are ready to move on when:

- you can explain why subtree-side queries belong here instead of in LCT
- you can derive the subtree interval from the two directed tokens around one edge
- you can describe `make_root`, `link`, and `cut` as sequence operations
- you can say exactly what the first repo starter does **not** support yet

## External Practice

- [Library Checker - Dynamic Tree Vertex Add Subtree Sum](https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum)
- [Library Checker - Dynamic Tree Subtree Add Subtree Sum](https://judge.yosupo.jp/problem/dynamic_tree_subtree_add_subtree_sum)
- [OI Wiki - Euler Tour Tree](https://en.oi-wiki.org/ds/ett/)

## Tutorial Link

- [Euler Tour Tree](../../../../topics/graphs/euler-tour-tree/README.md)

