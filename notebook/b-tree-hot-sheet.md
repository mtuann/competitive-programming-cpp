# B-Tree Hot Sheet

Use this page when the real lesson is one high-fanout multiway ordered
dictionary, not one contest-first binary search-tree route.

## Do Not Use When

- ordinary contest ordered-set work is enough -> [PBDS / Order Statistics Tree](../topics/data-structures/pbds-order-statistics/README.md)
- split/merge is the real primitive -> [Treap / Implicit Treap](../topics/data-structures/treap-implicit/README.md)
- overlap queries on one live interval set are the real primitive -> [Interval Trees](../topics/data-structures/interval-trees/README.md)

## Choose By Signal

- high-fanout node splitting and textbook external-memory flavor -> `B-Tree`
- one dynamic ordered set with rank / `k`-th -> `PBDS`
- self-hosted split/merge route -> `Treap`
- binary balanced-tree compare exercise -> `Balanced BST compare note`

## Core Invariants

- keys inside each node stay sorted
- all leaves stay at the same depth
- every non-root node respects the min/max key-capacity bounds
- insert only descends into non-full children
- splitting promotes one median key upward

## Main Traps

- treating B-trees like binary trees with rotations
- descending into a full child during insert
- using this in contest code just because it sounds stronger than PBDS
- forgetting that deletion is intentionally out of the first route

## Exact Starter Route

- exact starter -> [`b-tree-insert-search.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/b-tree-insert-search.cpp)
- flagship rep -> [B-Tree Dictionary](../practice/ladders/data-structures/b-trees/btreedictionary.md)
- compare note -> [Balanced BSTs For Contests](../topics/data-structures/balanced-bsts/README.md)
- contest-first alternative -> [Order Statistics Tree hot sheet](order-statistics-tree-hot-sheet.md)

## Reopen Paths

- full lesson -> [B-Trees](../topics/data-structures/b-trees/README.md)
- binary compare note -> [Balanced BST hot sheet](balanced-bst-hot-sheet.md)
- simpler contest route -> [Order Statistics Tree hot sheet](order-statistics-tree-hot-sheet.md)
- split/merge route -> [Treap / Implicit Treap hot sheet](treap-hot-sheet.md)
