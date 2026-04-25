# Splay Tree Hot Sheet

Use this page when one self-adjusting ordered set is the real structure, or you
want the `rotate / splay / parent-pointer` refresher before link-cut tree.

## Do Not Use When

- GNU PBDS already solves the job -> [PBDS / Order Statistics Tree](../topics/data-structures/pbds-order-statistics/README.md)
- split/merge by key or sequence surgery is the real invariant -> [Treap / Implicit Treap](../topics/data-structures/treap-implicit/README.md)
- the real problem is already dynamic-forest path queries -> [Link-Cut Tree](../topics/graphs/link-cut-tree/README.md)

## Choose By Signal

- one dynamic ordered set with rank / `k`-th and GNU allowed -> `PBDS`
- split/merge ordered set or mutable sequence -> `Treap`
- self-adjusting ordered set and you explicitly want the splaying machinery -> `Splay`
- dynamic forest with `link / cut / path` -> `Link-Cut Tree`

## Core Invariants

- BST order on keys
- duplicates are usually stored through one `cnt` field
- subtree `size` includes duplicates
- every important access ends with `splay(x)`
- parent pointers and child pointers must stay consistent through rotations

## Main Traps

- forgetting to update `size` after rotate
- forgetting to maintain parent pointers
- confusing amortized `O(log n)` with worst-case per operation
- using splay because it is "advanced" when PBDS or treap is the cleaner route
- bringing the wrong node to the root after a failed search

## Exact Starter Route

- exact starter -> [`splay-tree-ordered-set.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/splay-tree-ordered-set.cpp)
- flagship rep -> [Ordinary Balanced Tree](../practice/ladders/data-structures/splay-tree/ordinarybalancedtree.md)
- family compare note -> [Balanced BSTs For Contests](../topics/data-structures/balanced-bsts/README.md)
- dynamic-tree follow-up -> [Link-Cut Tree hot sheet](link-cut-tree-hot-sheet.md)

## Reopen Paths

- full lesson -> [Splay Tree](../topics/data-structures/splay-tree/README.md)
- simpler GNU order-statistics route -> [Order Statistics Tree hot sheet](order-statistics-tree-hot-sheet.md)
- split/merge route -> [Treap / Implicit Treap hot sheet](treap-hot-sheet.md)
- dynamic-tree follow-up -> [Link-Cut Tree hot sheet](link-cut-tree-hot-sheet.md)
