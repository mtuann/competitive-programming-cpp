# Dynamic Tree Vertex Add Path Sum

- Title: `Dynamic Tree Vertex Add Path Sum`
- Judge / source: `Library Checker`
- Original URL: [https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum](https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum)
- Secondary topics: `Dynamic forest`, `Preferred paths`, `Splay-based path aggregate`
- Difficulty: `very hard`
- Subtype: `Online link / cut with vertex-add and path-sum queries`
- Status: `solved`
- Solution file: [dynamictreevertexaddpathsum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/link-cut-tree/dynamictreevertexaddpathsum.cpp)

## Why Practice This

This is the cleanest verifier-style rep for the repo's first link-cut tree route.

The problem is narrow in exactly the right way:

- one dynamic forest
- cut one existing edge, then link one new edge
- add to one vertex
- ask the sum on one current tree path

So the lesson is not an arbitrary splay trick collection.

It is learning the exact operational loop:

- `makeroot`
- `access`
- `link`
- `cut`
- read one path aggregate

## Recognition Cue

Reach for link-cut tree when:

- the statement changes the tree edges online
- path queries survive those changes
- static preprocessing like HLD or subtree flattening would need rebuilding
- the operations look like one small dynamic-forest API instead of one-off graph mutations

The strong smell is:

- "`cut` one edge, `link` one edge, then query a tree path"

That is the first exact LCT route.

## Problem-Specific Transformation

The statement sounds like a fully dynamic tree problem, but the reusable rewrite is:

- store vertex values in an LCT node
- maintain the represented forest under `link / cut`
- answer path sum by:
  1. `makeroot(u)`
  2. `access(v)`
  3. read the aggregate at `v`

So the hard part is not the sum itself.

It is maintaining a dynamic forest where the preferred-path decomposition changes online.

## Core Idea

Each represented-tree path that becomes important right now is turned into one auxiliary splay tree by `access`.

For a query on path `u -> v`:

1. reroot the represented tree at `u`
2. expose the path to `v`
3. the whole path now lives in `v`'s auxiliary tree
4. read the stored subtree sum there

For a vertex add on `p`:

- expose `p`
- change its stored `val`
- pull back the auxiliary aggregate

For a topology update:

- `cut(a, b)`
- `link(c, d)`

The reusable invariant is:

```text
after makeroot(u) + access(v),
the represented path u -> v is the auxiliary tree rooted at v
```

## Implementation Notes

The repo solution keeps the first route deliberately narrow:

- vertex values, not edge values
- point add, not assignment
- path sum, not a generic non-commutative fold

The most important correctness details are:

- push lazy reverse flags before rotations
- distinguish auxiliary-root checks from represented-root logic
- in `cut(u, v)`, verify that the exposed path really ends with the single edge `u-v`

## Complexity

- each `link`, `cut`, update, and path query: amortized `O(log N)`
- memory: `O(N)`

That is the intended complexity for the verifier limits.

## Pitfalls / Judge Notes

- Nodes are `0`-indexed.
- The initial graph is already one tree.
- Query type `0` replaces one edge with another:
  - cut `(a, b)`
  - link `(c, d)`
- The starter is vertex-valued, so path sum includes both endpoints.
- This lane is about online path aggregates; do not import subtree-flattening instincts here.

## Reusable Pattern

- Topic page: [Link-Cut Tree](../../../../topics/graphs/link-cut-tree/README.md)
- Practice ladder: [Link-Cut Tree ladder](README.md)
- Starter template: [`link-cut-tree-path-sum.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/graphs/link-cut-tree-path-sum.cpp)
- Notebook refresher: [Link-Cut Tree hot sheet](../../../../notebook/link-cut-tree-hot-sheet.md)
- Compare points: [Heavy-Light Decomposition](../../../../topics/graphs/hld/README.md), [Euler Tour / Subtree Queries](../../../../topics/graphs/euler-tour-subtree/README.md), [DSU Rollback / Offline Dynamic Connectivity](../../../../topics/data-structures/dsu-rollback/README.md)
- This note adds: the first exact route where dynamic topology turns preferred-path exposure into the main primitive.

## Solutions

- Code: [dynamictreevertexaddpathsum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/graphs/link-cut-tree/dynamictreevertexaddpathsum.cpp)
