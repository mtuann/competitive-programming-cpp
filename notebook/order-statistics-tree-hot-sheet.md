# Order Statistics Tree Hot Sheet

Use this sheet when one dynamic ordered set needs **rank or `k`-th queries online**, not just predecessor or successor.

## Do Not Use When

- predecessor / successor / erase-one is enough -> [Heaps And Ordered Sets](../topics/data-structures/heaps-and-ordered-sets/README.md)
- compressed coordinates plus prefix counts already solve it -> [Fenwick hot sheet](fenwick-hot-sheet.md)
- the array is static and the query lives inside one subarray -> [Wavelet Tree hot sheet](wavelet-tree-hot-sheet.md)
- the real structure is a mutable sequence by position -> [Treap / Implicit Treap hot sheet](treap-hot-sheet.md)

## Choose By Signal

- dynamic set + `k`-th smallest / count smaller than `x` -> `PBDS / Order Statistics Tree`
- predecessor / floor in active multiset -> `multiset`
- compressed frequencies with rank counts -> [Fenwick hot sheet](fenwick-hot-sheet.md)
- static subarray order statistics -> [Wavelet Tree hot sheet](wavelet-tree-hot-sheet.md)

## Core Invariants

- the tree stores all live keys in sorted order
- order statistics come from subtree sizes, surfaced as `order_of_key()` and `find_by_order()`
- raw `ordered_set<T>` is a unique-key set
- duplicates need a pair-key wrapper such as `(value, unique_id)`

## Main Traps

- forgetting PBDS is a GNU extension, not portable ISO C++
- using one-based `k` directly with zero-based `find_by_order()`
- reaching for PBDS when `multiset` or Fenwick is simpler
- trying to store duplicates in raw `ordered_set<T>` and silently losing them

## Exact Starter Route

- exact starter -> [pbds-ordered-set.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/pbds-ordered-set.cpp)
- flagship in-lane rep -> [ORDERSET - Order Statistic Set](../practice/ladders/data-structures/pbds-order-statistics/orderset.md)
- compare points -> [Heaps And Ordered Sets](../topics/data-structures/heaps-and-ordered-sets/README.md), [Fenwick Tree](../topics/data-structures/fenwick-tree/README.md), [Treap / Implicit Treap](../topics/data-structures/treap-implicit/README.md)

## Reopen Paths

- full topic page -> [PBDS / Order Statistics Tree](../topics/data-structures/pbds-order-statistics/README.md)
- broader chooser -> [Data structures cheatsheet](data-structures-cheatsheet.md)
- reusable snippet map -> [Template Library](../template-library.md)
- retrieval router -> [Build Kit](../docs/build-kit.md)
