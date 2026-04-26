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
- piecewise-constant range partitions where assign keeps collapsing runs and interval walks are acceptable -> [ODT / Chtholly hot sheet](odt-chtholly-hot-sheet.md)
- old versions stay queryable and point updates create new versions -> [Persistent Data Structures hot sheet](persistent-data-structures-hot-sheet.md)
- self-hosted ordered set with split/merge by key, online rank, or `k`-th -> [Treap / Implicit Treap hot sheet](treap-hot-sheet.md)
- mutable sequence with insert / erase / cut / paste by position -> [Treap / Implicit Treap hot sheet](treap-hot-sheet.md)
- static subarray k-th / count `<= x` / count `== x` by value -> [Wavelet Tree hot sheet](wavelet-tree-hot-sheet.md)
- static idempotent range query -> [Sparse Table hot sheet](sparse-table-hot-sheet.md)
- connectivity merges -> [DSU hot sheet](dsu-hot-sheet.md)
- connectivity under offline edge add/remove timeline -> [DSU Rollback hot sheet](dsu-rollback-hot-sheet.md)
- every node needs one subtree answer from merged child containers -> [DSU On Tree hot sheet](dsu-on-tree-hot-sheet.md)
- static range queries where one active interval can be updated by endpoint moves -> [Mo's hot sheet](mos-hot-sheet.md)
- dynamic maximum xor against one live set of integers -> [Binary Trie hot sheet](binary-trie-hot-sheet.md)
- current top / min / max only -> heap
- heaps must meld online and queries name the heap containing `x` -> [Pairing / Leftist Heap hot sheet](pairing-leftist-heap-hot-sheet.md)
- predecessor / successor / erase-one with duplicates -> multiset
- online `k`-th / rank / count smaller in one dynamic ordered set -> [Order Statistics Tree hot sheet](order-statistics-tree-hot-sheet.md)
- high-fanout textbook ordered dictionary / explicit B-tree breadth -> [B-Tree hot sheet](b-tree-hot-sheet.md)
- textbook probabilistic ordered dictionary / forward-pointer towers -> [Skiplist hot sheet](skiplist-hot-sheet.md)
- bounded integer universe with predecessor / successor as the real job -> [X-Fast / Y-Fast hot sheet](x-fast-y-fast-hot-sheet.md)
- one live set of half-open intervals with online overlap queries -> [Interval Tree hot sheet](interval-tree-hot-sheet.md)
- self-adjusting ordered set with rank / `k`-th, or you want the exact rotate/splay bridge into LCT -> [Splay Tree hot sheet](splay-tree-hot-sheet.md)
- you deliberately want a textbook deterministic balanced BST and want to know whether AVL / Red-Black / Scapegoat / SBT is actually worth it -> [Balanced BST hot sheet](balanced-bst-hot-sheet.md)
- first smaller / greater witness or histogram-style blocking boundary in one scan -> [Monotonic Stack / Queue hot sheet](monotonic-stack-queue-hot-sheet.md)
- sliding median -> [sliding-median-two-multisets.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/sliding-median-two-multisets.cpp)
- previous value `< x` in active set -> [multiset-predecessor.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/multiset-predecessor.cpp)
- window minimum / monotone DP -> [Monotonic Stack / Queue hot sheet](monotonic-stack-queue-hot-sheet.md)

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
- "minimum on every sliding window" -> [Monotonic Stack / Queue hot sheet](monotonic-stack-queue-hot-sheet.md), not a segment tree
- "first smaller / greater to the left / right" -> [Monotonic Stack / Queue hot sheet](monotonic-stack-queue-hot-sheet.md)
- "all queries known first" -> [Offline Tricks hot sheet](offline-tricks-hot-sheet.md) before building a heavier online structure
- "merge child subtree maps / sets into one surviving bag" -> [DSU On Tree hot sheet](dsu-on-tree-hot-sheet.md)
- "one current range and symmetric add/remove are the whole story" -> [Mo's hot sheet](mos-hot-sheet.md)
- "insert / erase / maximum xor query" -> [Binary Trie hot sheet](binary-trie-hot-sheet.md)
- "the keys are bounded integers and predecessor / successor is the point, not xor" -> [X-Fast / Y-Fast hot sheet](x-fast-y-fast-hot-sheet.md)
- "merge the heaps containing x and y, then pop the minimum of x's heap" -> [Pairing / Leftist Heap hot sheet](pairing-leftist-heap-hot-sheet.md)
- "range assign keeps turning big slices into one value, and the real state is the current runs" -> [ODT / Chtholly hot sheet](odt-chtholly-hot-sheet.md)
- "I want to hand-code a balanced BST, but I'm not sure whether AVL / Red-Black / Scapegoat / SBT is the right contest choice" -> [Balanced BST hot sheet](balanced-bst-hot-sheet.md)
- "cut / paste / insert / erase by current position" -> [Treap / Implicit Treap hot sheet](treap-hot-sheet.md)
- "rank / k-th is real, PBDS is unavailable or you want self-hosted split/merge by key" -> [Treap / Implicit Treap hot sheet](treap-hot-sheet.md) + [Order Statistics Tree hot sheet](order-statistics-tree-hot-sheet.md)
- "I want a self-adjusting ordered set and I specifically want to understand splaying itself" -> [Splay Tree hot sheet](splay-tree-hot-sheet.md)
- "book this interval if it does not overlap anything already booked" -> [Interval Tree hot sheet](interval-tree-hot-sheet.md)
- "I specifically want the multiway B-tree story with split-full-child, not a contest-first ordered set" -> [B-Tree hot sheet](b-tree-hot-sheet.md)
- "I specifically want the probabilistic skiplist story rather than any BST route" -> [Skiplist hot sheet](skiplist-hot-sheet.md)
- "static subarray k-th smallest or threshold count" -> [Wavelet Tree hot sheet](wavelet-tree-hot-sheet.md)

## Quick Anchors In This Repo

- Fenwick -> [CVP00001](../practice/ladders/data-structures/fenwick-tree/cvp00001.md)
- DSU -> [DSU hot sheet](dsu-hot-sheet.md) + [C11XU](../practice/ladders/data-structures/dsu/c11xu.md)
- rollback connectivity -> [DSU Rollback hot sheet](dsu-rollback-hot-sheet.md) + [Dynamic Connectivity](../practice/ladders/data-structures/dsu-rollback/dynamicconnectivity.md)
- subtree container merging -> [DSU On Tree hot sheet](dsu-on-tree-hot-sheet.md) + [Distinct Colors](../practice/ladders/data-structures/dsu-on-tree/distinctcolors.md)
- persistent range sums -> [Persistent Data Structures hot sheet](persistent-data-structures-hot-sheet.md) + [Range Queries and Copies](../practice/ladders/data-structures/persistent-data-structures/rangequeriesandcopies.md)
- branching list versions with `merge / head / tail` -> [Persistent Treap hot sheet](persistent-treap-hot-sheet.md) + [Persistent List](../practice/ladders/data-structures/persistent-treap/persistentlist.md)
- sequence surgery by position -> [Treap / Implicit Treap hot sheet](treap-hot-sheet.md) + [Cut and Paste](../practice/ladders/data-structures/treap-implicit/cutandpaste.md)
- key-based treap order statistics -> [Treap / Implicit Treap hot sheet](treap-hot-sheet.md) + [Salary Queries](../practice/ladders/data-structures/treap-implicit/salaryqueries.md)
- static range order statistics -> [Wavelet Tree hot sheet](wavelet-tree-hot-sheet.md) + [MKTHNUM - K-th Number](../practice/ladders/data-structures/wavelet-tree/mkthnum.md)
- ordered multiset -> [Concert Tickets](../practice/ladders/data-structures/heaps-and-ordered-sets/concerttickets.md)
- offline sweep -> [Offline Tricks hot sheet](offline-tricks-hot-sheet.md) + [Distinct Values Queries](../practice/ladders/data-structures/offline-tricks/distinctvaluesqueries.md)
- current-range Mo maintenance -> [Mo's hot sheet](mos-hot-sheet.md) + [Powerful Array](../practice/ladders/data-structures/mos-algorithm/powerfularray.md)
- dynamic xor multiset -> [Binary Trie hot sheet](binary-trie-hot-sheet.md) + [Vasiliy's Multiset](../practice/ladders/data-structures/binary-trie-xor/vasiliysmultiset.md)
- dynamic ordered-set rank / `k`-th -> [Order Statistics Tree hot sheet](order-statistics-tree-hot-sheet.md) + [ORDERSET - Order Statistic Set](../practice/ladders/data-structures/pbds-order-statistics/orderset.md)
- high-fanout textbook search tree -> [B-Tree hot sheet](b-tree-hot-sheet.md) + [B-Tree Dictionary](../practice/ladders/data-structures/b-trees/btreedictionary.md)
- probabilistic textbook ordered dictionary -> [Skiplist hot sheet](skiplist-hot-sheet.md) + [Skiplist Dictionary](../practice/ladders/data-structures/skip-lists/skiplistdictionary.md)
- bounded-universe predecessor structure -> [X-Fast / Y-Fast hot sheet](x-fast-y-fast-hot-sheet.md) + [X-Fast Dictionary](../practice/ladders/data-structures/x-fast-y-fast-tries/xfastdictionary.md)
- dynamic interval overlap queries -> [Interval Tree hot sheet](interval-tree-hot-sheet.md) + [Reservation System](../practice/ladders/data-structures/interval-trees/reservationsystem.md)
- textbook balanced-BST compare note -> [Balanced BST hot sheet](balanced-bst-hot-sheet.md) + [Balanced BSTs For Contests](../topics/data-structures/balanced-bsts/README.md)
- self-adjusting ordered multiset with parent-pointer rotations -> [Splay Tree hot sheet](splay-tree-hot-sheet.md) + [Ordinary Balanced Tree](../practice/ladders/data-structures/splay-tree/ordinarybalancedtree.md)
- meldable singleton heaps -> [Pairing / Leftist Heap hot sheet](pairing-leftist-heap-hot-sheet.md) + [Mergeable Heap 1](../practice/ladders/data-structures/pairing-leftist-heap/mergeableheap1.md)
- interval partitions with `split / assign / walk` -> [ODT / Chtholly hot sheet](odt-chtholly-hot-sheet.md) + [Willem, Chtholly and Seniorious](../practice/ladders/data-structures/odt-chtholly/willemchthollyandseniorious.md)
- sparse table -> [Sparse Table hot sheet](sparse-table-hot-sheet.md) + [Static Range Minimum Queries](../practice/ladders/data-structures/sparse-table/staticrangeminimumqueries.md)
- segment tree -> [Segment Tree hot sheet](segment-tree-hot-sheet.md) + [Dynamic Range Sum Queries](../practice/ladders/data-structures/segment-tree/dynamicrangesumqueries.md)
- lazy segment tree -> [Lazy Segment Tree hot sheet](lazy-segment-tree-hot-sheet.md) + [HORRIBLE](../practice/ladders/data-structures/lazy-segment-tree/horriblequeries.md)
- segment tree beats -> [Segment Tree Beats hot sheet](segment-tree-beats-hot-sheet.md) + [Range Chmin Chmax Add Range Sum](../practice/ladders/data-structures/segment-tree-beats/rangechminchmaxaddrangesum.md)
- monotone boundary scan -> [Monotonic Stack / Queue hot sheet](monotonic-stack-queue-hot-sheet.md) + [Nearest Smaller Values](../practice/ladders/data-structures/monotonic-stack-queue/nearestsmallervalues.md)
- monotone window minimum -> [Monotonic Stack / Queue hot sheet](monotonic-stack-queue-hot-sheet.md) + [Sliding Window Minimum](../practice/ladders/dp/sliding-window/slidingwindowminimum.md)

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
- [DSU On Tree hot sheet](dsu-on-tree-hot-sheet.md)
- [Persistent Data Structures hot sheet](persistent-data-structures-hot-sheet.md)
- [Persistent Treap hot sheet](persistent-treap-hot-sheet.md)
- [Pairing / Leftist Heap hot sheet](pairing-leftist-heap-hot-sheet.md)
- [ODT / Chtholly hot sheet](odt-chtholly-hot-sheet.md)
- [Segment Tree hot sheet](segment-tree-hot-sheet.md)
- [Lazy Segment Tree hot sheet](lazy-segment-tree-hot-sheet.md)
- [Segment Tree Beats hot sheet](segment-tree-beats-hot-sheet.md)
- [Sparse Table hot sheet](sparse-table-hot-sheet.md)
- [Offline Tricks hot sheet](offline-tricks-hot-sheet.md)
- [Treap / Implicit Treap hot sheet](treap-hot-sheet.md)
- [Wavelet Tree hot sheet](wavelet-tree-hot-sheet.md)
- [Mo's hot sheet](mos-hot-sheet.md)
- [Monotonic Stack / Queue hot sheet](monotonic-stack-queue-hot-sheet.md)
- [Template library](../template-library.md)
- [Order Statistics Tree hot sheet](order-statistics-tree-hot-sheet.md)
- [B-Tree hot sheet](b-tree-hot-sheet.md)
- [Skiplist hot sheet](skiplist-hot-sheet.md)
- [X-Fast / Y-Fast hot sheet](x-fast-y-fast-hot-sheet.md)
- [Interval Tree hot sheet](interval-tree-hot-sheet.md)
- [Balanced BST hot sheet](balanced-bst-hot-sheet.md)
- [Fenwick Tree topic](../topics/data-structures/fenwick-tree/README.md)
- [PBDS / Order Statistics Tree topic](../topics/data-structures/pbds-order-statistics/README.md)
- [Skip Lists topic](../topics/data-structures/skip-lists/README.md)
- [X-Fast / Y-Fast Tries topic](../topics/data-structures/x-fast-y-fast-tries/README.md)
- [Balanced BSTs For Contests topic](../topics/data-structures/balanced-bsts/README.md)
- [Monotonic Stack / Queue topic](../topics/data-structures/monotonic-stack-queue/README.md)
- [Splay Tree hot sheet](splay-tree-hot-sheet.md)
- [Splay Tree topic](../topics/data-structures/splay-tree/README.md)
- [Segment Tree topic](../topics/data-structures/segment-tree/README.md)
- [Lazy Segment Tree topic](../topics/data-structures/lazy-segment-tree/README.md)
- [Segment Tree Beats topic](../topics/data-structures/segment-tree-beats/README.md)
- [Persistent Data Structures topic](../topics/data-structures/persistent-data-structures/README.md)
- [Persistent Treap topic](../topics/data-structures/persistent-treap/README.md)
- [Pairing Heap / Leftist Heap topic](../topics/data-structures/pairing-leftist-heap/README.md)
- [ODT / Chtholly topic](../topics/data-structures/odt-chtholly/README.md)
- [Treap / Implicit Treap topic](../topics/data-structures/treap-implicit/README.md)
- [Wavelet Tree topic](../topics/data-structures/wavelet-tree/README.md)
- [Mo's Algorithm topic](../topics/data-structures/mos-algorithm/README.md)
- [Binary Trie / XOR Queries topic](../topics/data-structures/binary-trie-xor/README.md)
