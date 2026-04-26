# B-Trees

This lane is for the moment ordered-search-tree work stops being about:

- one binary tree with rotations
- or one contest-first ordered set under tight implementation pressure

and becomes about:

- **high fanout**
- node splitting instead of local rotations
- and the external-memory mental model where one node stands for one block

The repo's exact first route for this family is:

- starter -> [b-tree-insert-search.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/b-tree-insert-search.cpp)
- flagship note -> [B-Tree Dictionary](../../../practice/ladders/data-structures/b-trees/btreedictionary.md)
- compare point -> [Balanced BSTs For Contests](../balanced-bsts/README.md)
- compare point -> [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md)
- compare point -> [Interval Trees](../interval-trees/README.md)

This lane intentionally teaches the **search + insert + split-full-child route first**.
It does not start from deletion, B+ trees, disk-page buffering, bulk loading, or
database indexing details.

## At A Glance

- **Use when:** you explicitly want the B-tree model itself, or one textbook breadth lane for high-fanout ordered dictionaries
- **Core worldview:** each node stores many keys, many children, and splits only when full
- **Main tools:** minimum degree `t`, sorted key arrays inside each node, child descent by separator keys, and split-full-child insertion
- **Typical complexity:** `O(t log_t n)` CPU time per search/insert in the simple in-memory starter, with external-memory intuition of `O(log_B n)` node visits
- **Main trap:** reaching for B-trees in ordinary CP ordered-set tasks where PBDS, treap, or even plain `set` is much simpler

Strong contest or study signals:

- "I want to cover the classical B-tree family from CLRS / ODS"
- "I want a multiway search tree instead of a binary balanced tree"
- "fanout, pages, and split-on-full are the real lesson"

Strong anti-cues:

- online rank / `k`-th is the real invariant -> [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md)
- split / merge by key or by position is the real invariant -> [Treap / Implicit Treap](../treap-implicit/README.md)
- overlap queries on one live interval set are the real invariant -> [Interval Trees](../interval-trees/README.md)
- the task is simply one contest ordered set with insert / erase / predecessor / successor -> [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md)

## Prerequisites

- [Balanced BSTs For Contests](../balanced-bsts/README.md), because you should already know how the repo thinks about textbook search-tree breadth versus contest-first retrieval
- [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md), at the level of being comfortable with one ordinary ordered dictionary interface

Helpful compare points:

- [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md): use this when one dynamic ordered set in contest code is the actual need
- [Treap / Implicit Treap](../treap-implicit/README.md): use this when self-hosted split/merge is the actual primitive
- [Balanced BSTs For Contests](../balanced-bsts/README.md): use this when the real question is still "which binary balanced tree variant should I study first?"

## Problem Model And Notation

A B-tree of minimum degree `t` keeps:

- each non-root node with between `t - 1` and `2t - 1` keys
- each internal non-root node with between `t` and `2t` children
- all leaves at the same depth
- keys inside a node in sorted order

The root is allowed to have fewer keys.

The canonical task in this lane is:

- insert key `x`
- search whether key `x` exists

with set semantics:

- duplicates are ignored in the repo starter

## From Binary Trees To Multiway Search

### Binary Balanced Trees

Binary search trees keep:

- one key per node
- and small local balancing repairs

That is the right worldview for:

- PBDS
- AVL / Red-Black compare work
- treap
- splay

### What Changes In B-Trees

B-trees keep:

- many keys in one node
- many children in one node
- and rebalance by **splitting full nodes**

The useful state is not:

- height difference
- color
- or subtree `size`

It is:

- node capacity
- separator keys
- and whether the child you want to descend into is already full

### The Split-Full-Child Insight

If you only descend into children that are **not full**, then insertion becomes
clean:

1. when the root is full, split it first
2. before descending into one child, split that child if it is full
3. continue until you reach a leaf with spare room

That top-down discipline avoids backtracking repair logic.

## Core Invariants And Why They Matter

The repo starter keeps four contest-facing invariants.

### 1. Keys In Every Node Stay Sorted

Each node stores its keys in increasing order.

That is what makes:

- linear or binary scan inside one node
- and child selection by separators

work at all.

### 2. All Leaves Stay At The Same Depth

This is the height-balancing invariant.

It gives logarithmic height in the number of elements.

### 3. Every Descent Avoids Full Children

The insertion route always ensures:

- before descending into child `c`, if `c` is full, split it first

This is the implementation invariant that keeps insert clean and local.

### 4. Splits Promote One Median Key

When a node with `2t - 1` keys splits:

- the median key moves up
- left and right halves keep `t - 1` keys each

That is what preserves both order and capacity bounds.

## Complexity And Tradeoffs

With the repo's simple in-memory starter:

- search: `O(t log_t n)`
- insert: `O(t log_t n)`
- memory per node: `O(t)`

The external-memory intuition is:

- higher fanout means fewer levels
- so the number of block touches behaves like `O(log_B n)`

Rule of thumb:

- explicit B-tree breadth / high-fanout dictionary study -> this lane
- ordinary contest ordered-set work -> [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md) or [Heaps And Ordered Sets](../heaps-and-ordered-sets/README.md)
- split/merge-first self-hosted work -> [Treap / Implicit Treap](../treap-implicit/README.md)

## Worked Examples

### Example 1: Repo Canonical Benchmark

This repo's flagship note:

- [B-Tree Dictionary](../../../practice/ladders/data-structures/b-trees/btreedictionary.md)

The benchmark is intentionally canonical instead of judge-idiosyncratic:

- `+ x` inserts one key
- `? x` asks whether the key exists

This keeps the whole focus on:

- node search
- root splitting
- child splitting

and not on unrelated query design.

### Example 2: Why This Is Not PBDS First

If the real task is:

- online rank
- `k`-th
- count smaller

then the right route is almost never a hand-coded B-tree in this repo.

That is:

- [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md)

### Example 3: Why This Is Not Treap First

If the real task is:

- split by key
- merge
- mutable sequence edits
- or persistence via path copying

then the right worldview is not "multiway page splits."

That is:

- [Treap / Implicit Treap](../treap-implicit/README.md)
- [Persistent Treap](../persistent-treap/README.md)

## Repo Starter Contract

The starter:

- is an in-memory B-tree with configurable minimum degree `T`
- supports:
  - `contains(x)`
  - `insert(x)`
- treats the structure as a set, so duplicate inserts are ignored
- leaves deletion outside the first route

That contract is enough for:

- textbook B-tree search
- top-down insertion with split-full-child
- one canonical breadth benchmark

## Main Traps

- treating B-trees like binary trees with rotations
- descending into a full child during insert and then needing messy repair logic
- forgetting that the repo's starter is about the data-structure lesson, not about low-level disk buffering
- reaching for B-trees in ordinary CP tasks just because they sound advanced

## Reopen Paths

- quick recall -> [B-Tree hot sheet](../../../notebook/b-tree-hot-sheet.md)
- binary balanced-tree compare note -> [Balanced BSTs For Contests](../balanced-bsts/README.md)
- simpler contest ordered-set route -> [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md)
- self-hosted split/merge route -> [Treap / Implicit Treap](../treap-implicit/README.md)

## References And Repo Anchors

Reference / practice:

- [Open Data Structures - 14.2 B-Trees](https://opendatastructures.org/ods-cpp/14_2_B_Trees.html)
- [Introduction to Algorithms, 4th ed. TOC PDF](https://mitp-content-server.mit.edu/books/content/sectbyfn/books_pres_0/11599/4e_toc.pdf)

Repo anchors:

- [B-Tree hot sheet](../../../notebook/b-tree-hot-sheet.md)
- [B-Tree Dictionary](../../../practice/ladders/data-structures/b-trees/btreedictionary.md)
- [Balanced BSTs For Contests](../balanced-bsts/README.md)
- [PBDS / Order Statistics Tree](../pbds-order-statistics/README.md)
