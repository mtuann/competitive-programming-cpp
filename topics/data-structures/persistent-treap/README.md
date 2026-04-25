# Persistent Treap

Persistent treap is the point where two good ideas finally meet:

- persistence: old roots stay alive
- split/merge treap: whole sequences or ordered sets can be rearranged by structural surgery

This lane starts with the most contest-natural persistent treap route in this repo:

- **implicit split/merge treap**
- **branching list versions**
- `merge`
- split off the **head**
- split off the **tail**
- subtree sum as the one carried aggregate

That niche sits directly between:

- [Persistent Data Structures](../persistent-data-structures/README.md) for versioned fixed-array snapshots
- [Treap / Implicit Treap](../treap-implicit/README.md) for one current split/merge sequence

The repo keeps the first route intentionally narrow:

- one list version is one root
- updates create new roots instead of mutating old ones
- split/merge happens on sequences, not fixed index ranges
- the only starter aggregate is total sum modulo `1e9 + 7`

That is enough to teach the persistent split/merge worldview without pretending the first snippet already covers every lazy-tagged or key-based persistent BST variant.

## At A Glance

- **Use when:** old sequence/list versions stay alive and new operations are really split/merge edits, not fixed-array updates
- **Core worldview:** every list version is one immutable treap root; `merge` and `split` return new roots by cloning only the touched path
- **Main tools:** implicit treap, subtree sizes, subtree sums, path copying on split/merge recursion
- **Typical complexity:** expected `O(log n)` new nodes per `merge`, `head`, or `tail`
- **Main trap:** mutating one shared node during split/merge and silently corrupting older versions

Strong contest signals:

- "many lists exist at once"
- "merge two existing lists into a new list"
- "split one existing list into two new lists"
- "versions branch instead of replacing one current sequence"
- "concatenation and prefix/suffix extraction are first-class operations"

Strong anti-cues:

- the structure is a fixed array and only point updates create new snapshots -> [Persistent Data Structures](../persistent-data-structures/README.md)
- only one current mutable sequence matters -> [Treap / Implicit Treap](../treap-implicit/README.md)
- the query is really one ordered-set-by-key job with no historical versions
- a persistent queue/stack route would be much simpler than full split/merge treap

## Prerequisites

- [Persistent Data Structures](../persistent-data-structures/README.md)
- [Treap / Implicit Treap](../treap-implicit/README.md)

Helpful neighboring topics:

- [Wavelet Tree](../wavelet-tree/README.md) when the real job is static range order statistics, not versioned split/merge
- [Euler Tour Tree](../../graphs/euler-tour-tree/README.md) when split/merge sequence ideas are serving dynamic trees instead of versioned lists
- [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md) when you only need one current ordered set and GNU-only rank/`k`-th support is enough

## Problem Model And Notation

We store many list versions:

```text
root[1], root[2], ..., root[k]
```

Each root is one immutable implicit-treap sequence.

For the first route, every node stores:

- one element value
- subtree size
- subtree sum modulo `1e9 + 7`
- one random priority

The starter supports:

- `singleton(x)` -> new one-element list root
- `merge(a, b)` -> new root for concatenation of two list versions
- `split_prefix(root, k)` -> first `k` elements vs the rest
- `size(root)`
- `total_sum(root)`

That is exactly enough for:

- `merge L R`
- `head L`
- `tail L`

in [Persistent List](../../../practice/ladders/data-structures/persistent-treap/persistentlist.md).

## From Brute Force To The Right Idea

### Brute Force

If every `merge`, `head`, or `tail` copied the whole list, one operation could cost:

$$
O(n)
$$

or worse across many branching versions.

That is too slow once:

- there are up to `1e5` operations
- old lists remain alive
- the same base list may branch many times

### The Structural Observation

Treap already knows how to express sequence surgery by:

- `merge`
- `split`

Persistence already knows how to keep old versions alive by:

- cloning only touched nodes
- sharing untouched subtrees

Put those together and the right question becomes:

```text
how do I make split/merge non-destructive?
```

The answer is:

- never rewrite an existing node in-place
- clone each node only when the recursion path must change one child pointer

### Why This Is Not Just Persistent Segment Tree Again

Persistent segment tree works when:

- the structure shape is fixed
- one point update changes one root-to-leaf path

Persistent treap is different because:

- the structure shape itself is chosen by treap priorities
- the sequence can be cut and glued structurally
- `merge` and `split` are the primary operations, not point updates on a fixed interval tree

So the persistence axis is the same, but the structural edit axis is different.

## Core Invariants And Why They Work

## 1. One Version = One Root

Each list version is represented by one root handle:

```text
root[v]
```

All meaning of that version lives below that root.

## 2. Implicit Position Comes From Subtree Size

The starter stores no explicit index in a node.

As in ordinary implicit treap, the current position of a node is recovered from:

- size of its left subtree
- sizes crossed while descending

So `split_prefix(root, k)` still means:

- left = first `k` elements
- right = the rest

## 3. Persistence Means Path Copying On Split/Merge

During `merge(a, b)` or `split_prefix(root, k)`:

- unchanged subtrees are reused directly
- touched nodes are cloned before one child pointer is changed

That is why old roots remain valid forever.

## 4. Aggregates Still Mean The Same Thing

For every node:

```text
sum[node] = total value of the sequence represented by that subtree
```

Persistence changes how nodes are produced, not what the aggregate means.

## 5. Empty-Tree Base Cases Can Be Shared

If one side of a `merge` is empty, returning the other root directly is correct because:

- no child pointer is changed
- no old node is mutated

Persistence only needs copying when a structural rewrite would otherwise happen.

## Exact First Route In This Repo

The repo's first exact route is:

- branching list versions
- concatenation by `merge`
- prefix split of size `1`
- prefix split of size `size - 1`
- subtree sum as the carried aggregate

Starter:

- [persistent-treap-list-sum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/persistent-treap-list-sum.cpp)

Flagship rep:

- [Persistent List](../../../practice/ladders/data-structures/persistent-treap/persistentlist.md)

## Variant Chooser

### Start Here When

- list versions branch
- concatenation and prefix/suffix extraction are the real operations
- old versions remain queryable
- one carried aggregate such as sum is enough

### Reopen Persistent Segment Tree Instead When

- the structure is a fixed array
- updates are by fixed index or interval
- split/merge of whole sequences is not the story

### Reopen Ordinary Treap Instead When

- there is only one current sequence or ordered set
- no historical version survives after the next update
- persistence is not part of the statement

## Main Traps

- forgetting that `merge` and `split` must be **non-destructive**
- thinking persistence means copying the whole tree
- mixing key-based semantics with implicit-position semantics
- overclaiming that the first route already supports lazy reversal, affine tags, or ordered-set-by-key persistence

## Reopen Path

- Tutorial: [Persistent Treap](README.md)
- Retrieval sheet: [Persistent Treap hot sheet](../../../notebook/persistent-treap-hot-sheet.md)
- Compare tutorials: [Persistent Data Structures](../persistent-data-structures/README.md), [Treap / Implicit Treap](../treap-implicit/README.md)
- Reusable snippet map: [Template Library](../../../template-library.md)
- Retrieval router: [Build Kit](../../../docs/build-kit.md)
