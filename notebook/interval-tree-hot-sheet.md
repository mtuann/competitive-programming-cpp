# Interval Tree Hot Sheet

Use this page when one live set of intervals must answer online overlap queries,
and the real invariant is not one fixed coordinate array.

## Do Not Use When

- the intervals stay pairwise disjoint and predecessor/successor already closes the whole query -> [Heaps And Ordered Sets](../topics/data-structures/heaps-and-ordered-sets/README.md)
- all queries are offline -> [Offline Tricks](../topics/data-structures/offline-tricks/README.md)
- the real structure is a piecewise-constant interval partition under range assign -> [ODT / Chtholly](../topics/data-structures/odt-chtholly/README.md)
- the real query is coverage/count/aggregate over a fixed line -> [Segment Tree](../topics/data-structures/segment-tree/README.md)

## Choose By Signal

- one live interval set with insert / erase / any-overlap query -> `Interval Tree`
- already-disjoint intervals and one neighbor check is enough -> ordered set
- piecewise-constant runs under assign -> `ODT`
- aggregate coverage on one fixed coordinate universe -> `Segment Tree`

## Core Invariants

- intervals are usually treated as half-open `[l, r)`
- BST order is by `(l, r)`
- every node stores subtree `max_r`
- left subtree can be skipped when `left.max_r <= ql`
- right subtree can be skipped when `current.l >= qr`

## Main Traps

- mixing closed and half-open overlap semantics
- forgetting to recompute `max_r` after every structural change
- using this when the real task is offline or aggregate-by-coordinate
- pretending interval trees are the default CP route whenever a statement mentions intervals

## Exact Starter Route

- exact starter -> [`interval-tree-overlap-treap.cpp`](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/interval-tree-overlap-treap.cpp)
- flagship rep -> [Reservation System](../practice/ladders/data-structures/interval-trees/reservationsystem.md)
- family compare note -> [Balanced BSTs For Contests](../topics/data-structures/balanced-bsts/README.md)
- interval-partition sibling -> [ODT / Chtholly hot sheet](odt-chtholly-hot-sheet.md)

## Reopen Paths

- full lesson -> [Interval Trees](../topics/data-structures/interval-trees/README.md)
- lighter ordered-set route -> [Heaps And Ordered Sets](../topics/data-structures/heaps-and-ordered-sets/README.md)
- BST-family compare note -> [Balanced BST hot sheet](balanced-bst-hot-sheet.md)
- split/merge-first self-hosted BST route -> [Treap / Implicit Treap hot sheet](treap-hot-sheet.md)
- interval-partition sibling -> [ODT / Chtholly hot sheet](odt-chtholly-hot-sheet.md)
