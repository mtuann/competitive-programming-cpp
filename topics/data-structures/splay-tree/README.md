# Splay Tree

Splay tree is the repo's first exact lane for:

```text
one self-adjusting BST where every successful access, insert, erase, rank,
or k-th query is allowed to restructure the tree by splaying one touched node
to the root.
```

This lane exists for two reasons:

- it is a real ordered-set route with subtree-size augmentation
- it is the cleanest direct mental bridge into
  [Link-Cut Tree](../../graphs/link-cut-tree/README.md)

It is **not** the repo's default first route for dynamic ordered sets.

If GNU extensions are available, [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md)
is still shorter for rank / `k`-th.

If split/merge is the real invariant, [Treap / Implicit Treap](../treap-implicit/README.md)
is still the cleaner family.

## At A Glance

- **Use when:** you explicitly want a self-adjusting ordered multiset, or you
  want to learn the `rotate / splay / parent-pointer` worldview before link-cut
- **Core worldview:** every important access splays one touched node to the root,
  so the tree shape keeps adapting to recent operations
- **Main tools:** parent pointers, subtree sizes, duplicate counts, `rotate`,
  `splay`, `kth`, `count_less`
- **Typical complexity:** amortized `O(log n)` per operation
- **Main trap:** forgetting that splay is an amortized structure, or using it
  when PBDS or treap already matches the job more directly

Strong contest signals:

- "I want one self-hosted ordered set with rank / `k`-th"
- "I need to understand splaying itself before link-cut tree stops feeling like
  black magic"
- "the statement is ordinary balanced-tree interface, and I explicitly want the
  self-adjusting version"

Strong anti-cues:

- GNU PBDS is allowed and rank / `k`-th is the whole job ->
  [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md)
- split/merge by key or mutable sequence surgery is the real invariant ->
  [Treap / Implicit Treap](../treap-implicit/README.md)
- the real problem is dynamic-forest path queries ->
  [Link-Cut Tree](../../graphs/link-cut-tree/README.md)

## Prerequisites

- [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md)
- [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md)
- [Balanced BSTs For Contests](../balanced-bsts/README.md) as the family map

Helpful compare points:

- [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md)
- [Treap / Implicit Treap](../treap-implicit/README.md)
- [Link-Cut Tree](../../graphs/link-cut-tree/README.md)

## Problem Model And Notation

Maintain one dynamic ordered multiset `S`.

The exact first route in this repo supports:

- `insert(x)`
- `erase_one(x)`
- `count_less(x)`
- `kth(k)` for zero-based `k`
- predecessor / successor

The starter keeps:

- BST order by `key`
- `cnt` for duplicate multiplicity
- `size` for subtree total size including duplicates
- `parent`, `left`, and `right` pointers

The flagship note uses the standard balanced-tree interface:

- insert
- delete one copy
- rank
- `k`-th
- predecessor
- successor

## From Brute Force To The Right Idea

### Brute Force

Keep values in a `vector`, sort after updates, and answer:

- rank by binary search
- `k`-th by indexing

This fails once updates and queries interleave many times.

### The First Shift

The state is not one array. It is one **changing ordered set**.

So the structure itself should preserve sorted order under updates.

### The Second Shift

PBDS and treap both solve parts of that story, but splay asks a different
question:

```text
what if every time I touch a node, I move it to the root and let the tree
adapt to the access pattern?
```

That is the self-adjusting worldview.

## Core Invariants And Why They Work

## 1. BST Order Still Rules Everything

Splay is still a BST.

So every node `v` satisfies:

- all keys in `left(v)` are smaller
- all keys in `right(v)` are larger

If duplicates matter, the clean contest route is:

- store one node per distinct key
- keep multiplicity in `cnt`

## 2. Subtree Size Makes Rank And `k`-th Possible

Maintain:

$$
size(v) = size(left(v)) + size(right(v)) + cnt(v)
$$

Now:

- `count_less(x)` is one BST descent with whole-left-subtree contributions
- `kth(k)` is one descent by left sizes and multiplicities

This is the same order-statistics augmentation idea as PBDS, except now you
maintain it yourself.

## 3. Every Important Access Ends With `splay(x)`

The defining operation is:

```text
move one touched node x to the root through rotations.
```

That touched node may be:

- the found key
- the inserted key
- a predecessor / successor
- the last node reached on a failed search

This is why the tree is **self-adjusting** instead of explicitly height-balanced.

## 4. The Three Rotation Patterns Are The Whole Story

When `x` has parent `p` and grandparent `g`:

- `zig`: `p` is root of the current splay tree
- `zig-zig`: `x` and `p` are on the same side
- `zig-zag`: `x` and `p` are on opposite sides

You only need ordinary BST rotations plus parent pointers.

The important part is not memorizing pictures.
It is remembering:

- push structural changes through parent/child pointers consistently
- update subtree sizes after every rotation
- splay all the way to the target root

## 5. The Guarantee Is Amortized

This lane is about:

$$
\text{amortized } O(\log n)
$$

not worst-case `O(log n)` per single operation.

That is the first conceptual split from AVL / Red-Black.

## Exact First Route

The repo's exact starter route is intentionally narrow:

- one ordered multiset
- duplicates via `cnt`
- subtree size for order statistics
- parent pointers
- `rotate` + `splay`

Starter:

- [splay-tree-ordered-set.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/splay-tree-ordered-set.cpp)

Flagship note:

- [Ordinary Balanced Tree](../../../practice/ladders/data-structures/splay-tree/ordinarybalancedtree.md)

This is the right first route because it teaches the machinery without hiding it
behind dynamic-tree modeling yet.

## Why This Lane Exists Even Though PBDS And Treap Already Exist

## 1. PBDS Is Simpler For The Same Interface

If the statement only says:

- rank
- `k`-th
- insert
- erase

then PBDS is still the shorter contest route.

## 2. Treap Is Cleaner For Split / Merge Jobs

If the real primitive is:

- split by key
- merge two trees
- sequence surgery by position

then treap stays more natural.

## 3. Splay Is The Direct Bridge Into Link-Cut Tree

Link-cut tree internally uses:

- parent pointers
- `rotate`
- `splay`
- root-of-auxiliary-tree reasoning

So this lane is the cleanest exact bridge for the moment when you want link-cut
tree to feel like an extension instead of a leap.

## Worked Examples

### Example 1: Ordinary Balanced Tree

This repo's flagship note:

- [Ordinary Balanced Tree](../../../practice/ladders/data-structures/splay-tree/ordinarybalancedtree.md)

is the cleanest first benchmark because the whole statement is the ordered-set
interface itself.

So the lesson is exactly:

- duplicate-safe ordered set
- rank / `k`-th via subtree sizes
- predecessor / successor
- self-adjusting root changes after each access

### Example 2: The Link-Cut Bridge

Once `rotate / splay / parent-pointer` maintenance feels normal, reopen:

- [Link-Cut Tree](../../graphs/link-cut-tree/README.md)

Then the new idea is not "what is splay?"

It is only:

- what is an auxiliary tree?
- what does `access` expose?
- how does `makeroot` use lazy reversal?

That is a much healthier progression.

## Starter Contract

The starter exposes:

- `contains(key)`
- `insert(key)`
- `erase_one(key)`
- `count_less(key)`
- `kth_zero_based(k, out)`
- `predecessor(key, out)`
- `successor(key, out)`
- `size()`

It does **not** promise:

- split/merge-first treap semantics
- sequence operations
- lazy path reversals
- link/cut dynamic-tree logic

Those belong to follow-up lanes.

## Pitfalls

- forgetting that `size` must include `cnt`
- updating child pointers but forgetting parent pointers
- rotating without pulling subtree sizes
- treating amortized `O(log n)` as worst-case per query
- using splay when PBDS already solves the exact contest job in less code
- forgetting that link-cut's `is_root(x)` means root of the current auxiliary
  splay tree, not root of the represented tree

## Use / Avoid Signals

### Reach For Splay When

- you explicitly want the self-adjusting BST route
- you want one ordered-set lane that directly prepares you for link-cut tree
- you want to study parent-pointer rotations carefully

### Avoid Splay When

- PBDS already solves the exact ordered-set interface and GNU is allowed
- treap split/merge is the actual invariant
- dynamic trees are already the real task and you should just open
  [Link-Cut Tree](../../graphs/link-cut-tree/README.md)

## Retrieval Map

- quick recall -> [Splay Tree hot sheet](../../../notebook/splay-tree-hot-sheet.md)
- simpler GNU route -> [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md)
- split/merge route -> [Treap / Implicit Treap](../treap-implicit/README.md)
- family compare note -> [Balanced BSTs For Contests](../balanced-bsts/README.md)
- dynamic-tree follow-up -> [Link-Cut Tree](../../graphs/link-cut-tree/README.md)

## References And Repo Anchors

Reference / practice:

- [OI Wiki - Splay](https://en.oi-wiki.org/ds/splay/)
- [Self-Adjusting Binary Search Trees](https://www.cs.cmu.edu/~sleator/papers/self-adjusting.pdf)
- [Luogu P3369 - 普通平衡树](https://www.luogu.com.cn/problem/P3369)

Repo anchors:

- [Splay Tree hot sheet](../../../notebook/splay-tree-hot-sheet.md)
- [Ordinary Balanced Tree](../../../practice/ladders/data-structures/splay-tree/ordinarybalancedtree.md)
- [Link-Cut Tree](../../graphs/link-cut-tree/README.md)
