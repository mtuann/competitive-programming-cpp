# Skiplist Hot Sheet

Use this page when the real lesson is one probabilistically balanced ordered
dictionary with forward-pointer towers.

## Do Not Use When

- contest-first rank / `k`-th retrieval is enough -> [PBDS / Order Statistics Tree](../topics/data-structures/pbds-order-statistics/README.md)
- split/merge is the real primitive -> [Treap / Implicit Treap](../topics/data-structures/treap-implicit/README.md)
- high-fanout node splitting is the real lesson -> [B-Trees](../topics/data-structures/b-trees/README.md)

## Choose By Signal

- probabilistic ordered dictionary with expected balancing -> `Skiplist`
- one dynamic ordered set with rank / `k`-th -> `PBDS`
- self-hosted split/merge route -> `Treap`
- high-fanout external-memory-flavored breadth -> `B-Tree`

## Core Invariants

- every level is sorted
- higher levels are subsequences of lower levels
- each node appears on all levels below its height
- `update[]` stores the last predecessor on every level during one search path

## Main Traps

- confusing expected complexity with deterministic guarantees
- corrupting `update[]` and then splicing the tower at the wrong position
- using skip lists in contest code just because they look simpler than balanced trees
- forgetting that this lane is breadth-first, not the repo's first retrieval choice

## Exact Starter Route

- exact starter -> [`skiplist-ordered-set.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/skiplist-ordered-set.cpp)
- flagship rep -> [Skiplist Dictionary](../practice/ladders/data-structures/skip-lists/skiplistdictionary.md)
- contest-first alternative -> [Order Statistics Tree hot sheet](order-statistics-tree-hot-sheet.md)
- breadth sibling -> [B-Tree hot sheet](b-tree-hot-sheet.md)

## Reopen Paths

- full lesson -> [Skip Lists](../topics/data-structures/skip-lists/README.md)
- contest-first route -> [Order Statistics Tree hot sheet](order-statistics-tree-hot-sheet.md)
- split/merge route -> [Treap / Implicit Treap hot sheet](treap-hot-sheet.md)
- high-fanout breadth sibling -> [B-Tree hot sheet](b-tree-hot-sheet.md)
