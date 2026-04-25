# Data Structures Cheatsheet

Use this page when you know the operations but have not yet picked the lightest structure.

## Do Not Use When

- the main difficulty is graph or DP modeling rather than operations
- one static formula or prefix array already solves the whole problem
- you still cannot list the required operations cleanly

## Choose By Operations

- static range sums -> prefix sums
- point add + prefix/range sum -> Fenwick
- arbitrary merge with updates -> segment tree -> [Segment Tree hot sheet](segment-tree-hot-sheet.md)
- static idempotent range query -> sparse table
- connectivity merges -> DSU
- current top / min / max only -> heap
- predecessor / successor / erase-one with duplicates -> multiset
- sliding median -> [sliding-median-two-multisets.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/sliding-median-two-multisets.cpp)
- previous value `< x` in active set -> [multiset-predecessor.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/multiset-predecessor.cpp)
- window minimum / monotone DP -> [monotonic-deque-min.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/monotonic-deque-min.cpp)

## First Questions

- static or dynamic?
- prefix-only or arbitrary range?
- online or offline?
- duplicates matter?
- do you need order, rank, or only the current best element?

## Core Invariants

- Fenwick / prefix structures: one stable prefix meaning
- segment tree: every node represents one mergeable segment summary
- DSU: every element belongs to one representative-led component
- ordered-set logic: duplicates and erase policy must be explicit

## Retrieval Cues

- "largest ticket not exceeding x" -> multiset predecessor
- "median of the current window" -> two multisets before reaching for PBDS
- "minimum on every sliding window" -> monotonic deque, not a segment tree
- "all queries known first" -> check whether an offline sweep replaces a heavier online structure

## Quick Anchors In This Repo

- Fenwick -> [CVP00001](../practice/ladders/data-structures/fenwick-tree/cvp00001.md)
- ordered multiset -> [Concert Tickets](../practice/ladders/data-structures/heaps-and-ordered-sets/concerttickets.md)
- offline sweep -> [Distinct Values Queries](../practice/ladders/data-structures/offline-tricks/distinctvaluesqueries.md)
- sparse table -> [Static Range Minimum Queries](../practice/ladders/data-structures/sparse-table/staticrangeminimumqueries.md)
- segment tree -> [Segment Tree hot sheet](segment-tree-hot-sheet.md) + [Dynamic Range Sum Queries](../practice/ladders/data-structures/segment-tree/dynamicrangesumqueries.md)

## Common Mistakes

- using a segment tree when the query is static
- forgetting that `set` drops duplicates
- trying to erase arbitrary heap items without a lazy-delete plan
- missing the original-order bookkeeping in offline processing

## Do Not Overbuild

Under contest pressure, the usual failure is not “too simple.” It is “picked a heavier structure than the operations justify.”

Ask:

- would prefix sums already work?
- would sorting + two pointers already work?
- are all queries known first, so offline processing is enough?

## Next Stops

- [Heaps and ordered sets topic](../topics/data-structures/heaps-and-ordered-sets/README.md)
- [Offline tricks topic](../topics/data-structures/offline-tricks/README.md)
- [Segment Tree hot sheet](segment-tree-hot-sheet.md)
- [Template library](../template-library.md)
- [Fenwick Tree topic](../topics/data-structures/fenwick-tree/README.md)
- [Segment Tree topic](../topics/data-structures/segment-tree/README.md)
