# Data Structures Cheatsheet

Use this page when you know the operations but have not yet picked the lightest structure.

## Do Not Use When

- the main difficulty is graph or DP modeling rather than operations
- one static formula or prefix array already solves the whole problem
- you still cannot list the required operations cleanly

## Choose By Operations

- static range sums -> prefix sums
- point add + prefix/range sum -> [Fenwick hot sheet](fenwick-hot-sheet.md)
- arbitrary merge with updates -> segment tree -> [Segment Tree hot sheet](segment-tree-hot-sheet.md)
- online range add + range sum -> [Lazy Segment Tree hot sheet](lazy-segment-tree-hot-sheet.md)
- online range `chmin / chmax / add / sum` where one simple lazy tag no longer closes -> [Segment Tree Beats hot sheet](segment-tree-beats-hot-sheet.md)
- old versions stay queryable and point updates create new versions -> [Persistent Data Structures hot sheet](persistent-data-structures-hot-sheet.md)
- static subarray k-th / count `<= x` / count `== x` by value -> [Wavelet Tree hot sheet](wavelet-tree-hot-sheet.md)
- static idempotent range query -> [Sparse Table hot sheet](sparse-table-hot-sheet.md)
- connectivity merges -> [DSU hot sheet](dsu-hot-sheet.md)
- connectivity under offline edge add/remove timeline -> [DSU Rollback hot sheet](dsu-rollback-hot-sheet.md)
- static range queries where one active interval can be updated by endpoint moves -> [Mo's hot sheet](mos-hot-sheet.md)
- dynamic maximum xor against one live set of integers -> [Binary Trie hot sheet](binary-trie-hot-sheet.md)
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
- persistent segment tree: every version is one root and untouched subtrees are shared
- DSU: every element belongs to one representative-led component
- rollback DSU: the current component forest must be exactly restorable from snapshots
- ordered-set logic: duplicates and erase policy must be explicit

## Retrieval Cues

- "largest ticket not exceeding x" -> multiset predecessor
- "median of the current window" -> two multisets before reaching for PBDS
- "minimum on every sliding window" -> monotonic deque, not a segment tree
- "all queries known first" -> [Offline Tricks hot sheet](offline-tricks-hot-sheet.md) before building a heavier online structure
- "one current range and symmetric add/remove are the whole story" -> [Mo's hot sheet](mos-hot-sheet.md)
- "insert / erase / maximum xor query" -> [Binary Trie hot sheet](binary-trie-hot-sheet.md)
- "static subarray k-th smallest or threshold count" -> [Wavelet Tree hot sheet](wavelet-tree-hot-sheet.md)

## Quick Anchors In This Repo

- Fenwick -> [CVP00001](../practice/ladders/data-structures/fenwick-tree/cvp00001.md)
- DSU -> [DSU hot sheet](dsu-hot-sheet.md) + [C11XU](../practice/ladders/data-structures/dsu/c11xu.md)
- rollback connectivity -> [DSU Rollback hot sheet](dsu-rollback-hot-sheet.md) + [Dynamic Connectivity](../practice/ladders/data-structures/dsu-rollback/dynamicconnectivity.md)
- persistent range sums -> [Persistent Data Structures hot sheet](persistent-data-structures-hot-sheet.md) + [Range Queries and Copies](../practice/ladders/data-structures/persistent-data-structures/rangequeriesandcopies.md)
- static range order statistics -> [Wavelet Tree hot sheet](wavelet-tree-hot-sheet.md) + [MKTHNUM - K-th Number](../practice/ladders/data-structures/wavelet-tree/mkthnum.md)
- ordered multiset -> [Concert Tickets](../practice/ladders/data-structures/heaps-and-ordered-sets/concerttickets.md)
- offline sweep -> [Offline Tricks hot sheet](offline-tricks-hot-sheet.md) + [Distinct Values Queries](../practice/ladders/data-structures/offline-tricks/distinctvaluesqueries.md)
- current-range Mo maintenance -> [Mo's hot sheet](mos-hot-sheet.md) + [Powerful Array](../practice/ladders/data-structures/mos-algorithm/powerfularray.md)
- dynamic xor multiset -> [Binary Trie hot sheet](binary-trie-hot-sheet.md) + [Vasiliy's Multiset](../practice/ladders/data-structures/binary-trie-xor/vasiliysmultiset.md)
- sparse table -> [Sparse Table hot sheet](sparse-table-hot-sheet.md) + [Static Range Minimum Queries](../practice/ladders/data-structures/sparse-table/staticrangeminimumqueries.md)
- segment tree -> [Segment Tree hot sheet](segment-tree-hot-sheet.md) + [Dynamic Range Sum Queries](../practice/ladders/data-structures/segment-tree/dynamicrangesumqueries.md)
- lazy segment tree -> [Lazy Segment Tree hot sheet](lazy-segment-tree-hot-sheet.md) + [HORRIBLE](../practice/ladders/data-structures/lazy-segment-tree/horriblequeries.md)
- segment tree beats -> [Segment Tree Beats hot sheet](segment-tree-beats-hot-sheet.md) + [Range Chmin Chmax Add Range Sum](../practice/ladders/data-structures/segment-tree-beats/rangechminchmaxaddrangesum.md)
- monotone window minimum -> [Sliding Window Minimum](../practice/ladders/dp/sliding-window/slidingwindowminimum.md)

## Common Mistakes

- using a segment tree when the query is static
- mutating a shared node and corrupting an old version
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
- [Fenwick hot sheet](fenwick-hot-sheet.md)
- [DSU hot sheet](dsu-hot-sheet.md)
- [DSU Rollback hot sheet](dsu-rollback-hot-sheet.md)
- [Persistent Data Structures hot sheet](persistent-data-structures-hot-sheet.md)
- [Segment Tree hot sheet](segment-tree-hot-sheet.md)
- [Lazy Segment Tree hot sheet](lazy-segment-tree-hot-sheet.md)
- [Segment Tree Beats hot sheet](segment-tree-beats-hot-sheet.md)
- [Sparse Table hot sheet](sparse-table-hot-sheet.md)
- [Offline Tricks hot sheet](offline-tricks-hot-sheet.md)
- [Wavelet Tree hot sheet](wavelet-tree-hot-sheet.md)
- [Mo's hot sheet](mos-hot-sheet.md)
- [Template library](../template-library.md)
- [Fenwick Tree topic](../topics/data-structures/fenwick-tree/README.md)
- [Segment Tree topic](../topics/data-structures/segment-tree/README.md)
- [Lazy Segment Tree topic](../topics/data-structures/lazy-segment-tree/README.md)
- [Segment Tree Beats topic](../topics/data-structures/segment-tree-beats/README.md)
- [Persistent Data Structures topic](../topics/data-structures/persistent-data-structures/README.md)
- [Wavelet Tree topic](../topics/data-structures/wavelet-tree/README.md)
- [Mo's Algorithm topic](../topics/data-structures/mos-algorithm/README.md)
- [Binary Trie / XOR Queries topic](../topics/data-structures/binary-trie-xor/README.md)
