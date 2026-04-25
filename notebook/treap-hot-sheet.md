# Treap / Implicit Treap Hot Sheet

Use this page when one mutable sequence needs **split / merge by position** or one ordered set needs **split / merge by key**.

## Do Not Use When

- `std::set` / `multiset` already solves the task with predecessor / successor / erase-one
- the sequence length is fixed and the real task is interval aggregate/update -> [Lazy Segment Tree hot sheet](lazy-segment-tree-hot-sheet.md)
- the array is static
- you still think the node's position should be stored explicitly in an implicit treap

## Choose By Signal

- ordered keys, but split/merge by key is the whole trick -> `key-based treap`
- insert / erase / cut / paste by position in a mutable sequence -> `implicit treap`
- fixed-length array with range aggregate/update -> [Segment Tree hot sheet](segment-tree-hot-sheet.md) or [Lazy Segment Tree hot sheet](lazy-segment-tree-hot-sheet.md)
- simple predecessor / successor / erase-one -> [Heaps and ordered sets topic](../topics/data-structures/heaps-and-ordered-sets/README.md)

## Core Invariants

- ordinary treap keeps BST order on keys and heap order on random priorities
- implicit treap replaces explicit key comparisons with subtree-size counting
- `split(root, k)` in the implicit route means: first `k` elements vs the rest
- every child rewrite must repair subtree size with `pull`

## Main Traps

- storing explicit indices in an implicit treap
- forgetting whether your split convention is `< x` vs `>= x`, or first `k` vs rest
- treating the starter as if it already had range-sum / reverse / lazy-tag support
- using treap when ordered set or segment tree is simpler

## Exact Starter Route

- exact starter -> [implicit-treap-sequence.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/implicit-treap-sequence.cpp)
- flagship in-lane rep -> [Cut and Paste](../practice/ladders/data-structures/treap-implicit/cutandpaste.md)
- compare points -> [Heaps And Ordered Sets](../topics/data-structures/heaps-and-ordered-sets/README.md), [Lazy Segment Tree](../topics/data-structures/lazy-segment-tree/README.md)

## Reopen Paths

- full topic page -> [Treap / Implicit Treap](../topics/data-structures/treap-implicit/README.md)
- sequence-update compare point -> [Lazy Segment Tree hot sheet](lazy-segment-tree-hot-sheet.md)
- reusable snippet map -> [Template Library](../template-library.md)
- retrieval router -> [Build Kit](../docs/build-kit.md)
