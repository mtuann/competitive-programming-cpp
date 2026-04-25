# PBDS / Order Statistics Tree Ladder

This lane is for the first time one dynamic ordered set needs **rank or `k`-th queries online**, not just predecessor or successor.

## Who This Is For

Use this lane if:

- [Heaps And Ordered Sets](../../../../topics/data-structures/heaps-and-ordered-sets/README.md) already feels comfortable
- you can explain why `set` and `multiset` keep one global order
- you now need `how many are smaller than x?` or `what is the k-th alive value?`

This lane is intentionally narrow:

- one exact starter
- one flagship note that is pure order-statistics
- one duplicate-safe compare route
- one `find_by_order` elimination compare route

## Warm-Up

- explain why predecessor is not the same as rank
- explain why `k`-th smallest cannot be retrieved efficiently from plain `std::set`
- hand-simulate `order_of_key(8)` and `find_by_order(1)` on `{2, 7, 10}`

Target skill:

- recognize when the missing operation is subtree-size-aware order statistics, not general ordered-set syntax

Warm-up compare points:

- [Heaps And Ordered Sets](../../../../topics/data-structures/heaps-and-ordered-sets/README.md)
- [Fenwick Tree](../../../../topics/data-structures/fenwick-tree/README.md)

## Core

- online insert / delete under set semantics
- `count smaller than x`
- `k`-th smallest
- exact flagship rep: [ORDERSET - Order Statistic Set](orderset.md)

Target skill:

- use `order_of_key` and `find_by_order` without mixing up one-based and zero-based indexing

## Stretch

- [CSES - Josephus Problem II](https://cses.fi/problemset/task/2163)
- [CSES - Salary Queries](https://cses.fi/problemset/task/1144)
- revisit [Fenwick Tree](../../../../topics/data-structures/fenwick-tree/README.md) and explain exactly when compression gives a simpler route than PBDS

Target skill:

- distinguish unique-key PBDS, duplicate-safe pair wrappers, and compressed-frequency alternatives

## Retrieval Layer

- exact quick sheet -> [Order Statistics Tree hot sheet](../../../../notebook/order-statistics-tree-hot-sheet.md)
- exact starter -> [pbds-ordered-set.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/pbds-ordered-set.cpp)
- compare route -> [Heaps And Ordered Sets](../../../../topics/data-structures/heaps-and-ordered-sets/README.md)
- broader chooser -> [Data structures cheatsheet](../../../../notebook/data-structures-cheatsheet.md)

## Repo Anchors And Compare Points

- topic page -> [PBDS / Order Statistics Tree](../../../../topics/data-structures/pbds-order-statistics/README.md)
- flagship note -> [ORDERSET - Order Statistic Set](orderset.md)
- compare point -> [Heaps And Ordered Sets](../../../../topics/data-structures/heaps-and-ordered-sets/README.md)
- compare point -> [Fenwick Tree](../../../../topics/data-structures/fenwick-tree/README.md)
- broader routing -> [Data Structures ladder](../README.md)

The cleanest in-repo loop here is:

1. reopen [Heaps And Ordered Sets](../../../../topics/data-structures/heaps-and-ordered-sets/README.md) just enough to trust that predecessor is not enough
2. learn the exact rank / `k`-th route in [PBDS / Order Statistics Tree](../../../../topics/data-structures/pbds-order-statistics/README.md)
3. solve [ORDERSET - Order Statistic Set](orderset.md)
4. compare the pure set route against duplicates in `Salary Queries` and against `find_by_order` elimination in `Josephus Problem II`

## Exit Criteria

You are ready to move on when:

- you can state the difference between `order_of_key(x)` and predecessor queries
- you remember that `find_by_order` is zero-based
- you know why duplicates need a pair-key wrapper
- you can tell when PBDS is overkill because Fenwick or multiset already closes the task

## External Practice

- [SPOJ - ORDERSET](https://www.spoj.com/problems/ORDERSET/)
- [CSES - Josephus Problem II](https://cses.fi/problemset/task/2163)
- [CSES - Salary Queries](https://cses.fi/problemset/task/1144)

## Tutorial Link

- [PBDS / Order Statistics Tree](../../../../topics/data-structures/pbds-order-statistics/README.md)
