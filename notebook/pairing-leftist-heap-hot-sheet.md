# Pairing / Leftist Heap Hot Sheet

Use this sheet when the missing operation is:

```text
meld two heaps
```

not predecessor, rank, or split-by-key.

## Do Not Use When

- one ordinary global heap is enough -> [Heaps And Ordered Sets](../topics/data-structures/heaps-and-ordered-sets/README.md)
- predecessor / successor is the real need -> [Heaps And Ordered Sets](../topics/data-structures/heaps-and-ordered-sets/README.md)
- online rank / `k`-th matters -> [Order Statistics Tree hot sheet](order-statistics-tree-hot-sheet.md)
- split/merge by key or by position is the real story -> [Treap / Implicit Treap hot sheet](treap-hot-sheet.md)

## Choose By Signal

- every item starts as one heap, then heaps keep unioning -> `Pairing Heap / Leftist Heap`
- one active ordered set with neighbor queries -> `set / multiset`
- one global best candidate only -> plain `priority_queue`
- persistent branching versions -> [Persistent Treap hot sheet](persistent-treap-hot-sheet.md)

## Core Invariants

- **leftist heap:** heap order plus `rank(left) >= rank(right)` so merge only walks one short right spine
- **pairing heap:** heap order plus two-pass pairing of root children after delete-min
- owner lookup is often a separate DSU-style layer, not part of the heap invariant itself
- equal keys should usually be tie-broken by item id if future operations still reference item ids

## Main Traps

- forgetting to reject operations on deleted items
- trying to solve meldable-heap tasks with repeated element moves
- not separating "which heap contains x" from "who is x's parent in the heap tree"
- overclaiming generic decrease-key / arbitrary erase support when the template does not expose them

## Exact Starter Route

- exact starter -> [leftist-heap-meldable-pq.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/leftist-heap-meldable-pq.cpp)
- flagship in-lane rep -> [Mergeable Heap 1](../practice/ladders/data-structures/pairing-leftist-heap/mergeableheap1.md)
- compare points -> [Heaps And Ordered Sets](../topics/data-structures/heaps-and-ordered-sets/README.md), [Treap / Implicit Treap hot sheet](treap-hot-sheet.md)

## Reopen Paths

- full topic page -> [Pairing Heap / Leftist Heap](../topics/data-structures/pairing-leftist-heap/README.md)
- broader chooser -> [Data structures cheatsheet](data-structures-cheatsheet.md)
- reusable snippet map -> [Template Library](../template-library.md)
- retrieval router -> [Build Kit](../docs/build-kit.md)
