# Persistent List

- Title: `Persistent List`
- Judge / source: `E-olymp`
- Original URL: [https://eolymp.com/en/problems/2957](https://eolymp.com/en/problems/2957)
- Secondary topics: `Persistent treap`, `Implicit treap`, `Split / merge persistence`, `Branching list versions`
- Difficulty: `hard`
- Subtype: `Versioned split/merge list operations with merge, head, tail, and subtree sums`
- Status: `solved`
- Solution file: [persistentlist.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/persistent-treap/persistentlist.cpp)

## Why Practice This

This is the cleanest first exact benchmark for the repo's **persistent treap** lane.

The statement already gives the whole signal:

- many list versions stay alive
- `merge` creates a new list from two old ones
- `head` and `tail` split one old list into two new ones
- every new list immediately asks for its total sum

So the real lesson is not "persistent data structures in general."

It is:

- one list version is one immutable treap root
- `merge` and `split_prefix` are the real primitives
- persistence means cloning touched nodes during split/merge recursion

## Recognition Cue

Reach for persistent treap when:

- versions are full sequences, not fixed arrays
- split/merge operations are first-class
- old sequences remain queryable or reusable after new ones are created
- concatenation and prefix/suffix extraction are cheaper to express structurally than by copying arrays

The strongest smell here is:

```text
existing lists branch into new lists through merge/head/tail operations.
```

## Problem-Specific Transformation

Treat every existing list id as one treap root:

```text
roots[i] = root of list i
```

Then the three operations become:

- `merge i j`:
  - `roots.push_back(merge(roots[i], roots[j]))`
- `head i`:
  - `(a, b) = split_prefix(roots[i], 1)`
  - push `a`, then push `b`
- `tail i`:
  - `(a, b) = split_prefix(roots[i], size(roots[i]) - 1)`
  - push `a`, then push `b`

The output for every newly created root is just:

```text
total_sum(root)
```

because subtree sums are already maintained inside the treap nodes.

## Core Idea

Use an **implicit** treap because list order is by position, not by explicit key.

Make it **persistent** by never mutating a published node:

- `merge(a, b)` clones only the nodes on the chosen recursion path
- `split_prefix(root, k)` clones only the nodes on the split path
- untouched subtrees are shared between versions

That gives the exact branching-version behavior the statement wants:

- old lists remain valid
- new lists reuse almost all old nodes
- sums are available in `O(1)` from the root aggregate

## Complexity

Let `n` be the size of the involved list in one operation.

- `merge`: expected `O(log n)` new nodes
- `head`: expected `O(log n)` new nodes
- `tail`: expected `O(log n)` new nodes
- total sum of one created list: `O(1)`

This fits the `1e5` scale comfortably.

## Pitfalls / Judge Notes

- `head` and `tail` create **two** new lists, and the left part gets the earlier id.
- The statement guarantees those splits never create an empty list.
- Output asks for sums modulo `1e9 + 7`.
- Returning an old root directly is okay only when no child pointer rewrite happens.
- The first route is persistent **implicit** treap, not key-based persistent ordered set logic.

## Reusable Pattern

- Topic page: [Persistent Treap](../../../../topics/data-structures/persistent-treap/README.md)
- Practice ladder: [Persistent Treap ladder](README.md)
- Starter template: [persistent-treap-list-sum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/persistent-treap-list-sum.cpp)
- Notebook refresher: [Persistent Treap hot sheet](../../../../notebook/persistent-treap-hot-sheet.md)
- Compare points:
  - [Persistent Data Structures](../../../../topics/data-structures/persistent-data-structures/README.md)
  - [Treap / Implicit Treap](../../../../topics/data-structures/treap-implicit/README.md)
- This note adds: the first exact in-repo route where persistence is attached to split/merge sequence surgery rather than to a fixed segment-tree shape.

## Solutions

- Code: [persistentlist.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/persistent-treap/persistentlist.cpp)
