# Treap / Implicit Treap Hot Sheet

Use this page when one mutable sequence needs **split / merge by position** or one ordered set needs **split / merge by key**.

## Do Not Use When

- `std::set` / `multiset` already solves the task with predecessor / successor / erase-one
- GNU PBDS already solves online rank / `k`-th more simply -> [Order Statistics Tree hot sheet](order-statistics-tree-hot-sheet.md)
- the sequence length is fixed and the real task is interval aggregate/update -> [Lazy Segment Tree hot sheet](lazy-segment-tree-hot-sheet.md)
- the array is static
- you still think the node's position should be stored explicitly in an implicit treap

## Choose By Signal

- ordered keys, but split/merge by key is the whole trick -> `key-based treap`
- one ordered set needs online rank / `k`-th, but you want a self-hosted route instead of GNU PBDS -> `key-based treap`
- insert / erase / cut / paste by position in a mutable sequence -> `implicit treap`
- old list versions stay alive and new edits are still split/merge sequence surgery -> [Persistent Treap hot sheet](persistent-treap-hot-sheet.md)
- fixed-length array with range aggregate/update -> [Segment Tree hot sheet](segment-tree-hot-sheet.md) or [Lazy Segment Tree hot sheet](lazy-segment-tree-hot-sheet.md)
- simple predecessor / successor / erase-one -> [Heaps and ordered sets topic](../topics/data-structures/heaps-and-ordered-sets/README.md)

## Core Invariants

- ordinary treap keeps BST order on keys and heap order on random priorities
- implicit treap replaces explicit key comparisons with subtree-size counting
- `split(root, x)` in the key-based route means keys `< x` vs `>= x`
- `split(root, k)` in the implicit route means first `k` elements vs the rest
- every child rewrite must repair subtree size with `pull`

## Main Traps

- storing explicit indices in an implicit treap
- forgetting whether your split convention is `< x` vs `>= x`, or first `k` vs rest
- treating the starter as if it already had range-sum / reverse / lazy-tag support
- using treap when PBDS, ordered set, or segment tree is simpler

## Exact Starter Routes

- key-based route -> [treap-key-ordered-set.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/treap-key-ordered-set.cpp) -> [Salary Queries](../practice/ladders/data-structures/treap-implicit/salaryqueries.md)
- implicit route -> [implicit-treap-sequence.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/implicit-treap-sequence.cpp) -> [Cut and Paste](../practice/ladders/data-structures/treap-implicit/cutandpaste.md)
- persistent follow-up -> [Persistent Treap hot sheet](persistent-treap-hot-sheet.md) -> [Persistent List](../practice/ladders/data-structures/persistent-treap/persistentlist.md)
- compare points -> [PBDS / Order Statistics Tree](../topics/data-structures/pbds-order-statistics/README.md), [Heaps And Ordered Sets](../topics/data-structures/heaps-and-ordered-sets/README.md), [Lazy Segment Tree](../topics/data-structures/lazy-segment-tree/README.md)

## Reopen Paths

- full topic page -> [Treap / Implicit Treap](../topics/data-structures/treap-implicit/README.md)
- sequence-update compare point -> [Lazy Segment Tree hot sheet](lazy-segment-tree-hot-sheet.md)
- reusable snippet map -> [Template Library](../template-library.md)
- retrieval router -> [Build Kit](../docs/build-kit.md)
