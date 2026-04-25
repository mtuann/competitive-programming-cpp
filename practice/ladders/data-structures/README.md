# Data Structures Ladders

These ladders connect reusable structures to focused practice.

## Subtopic Ladders

- [DSU](dsu/README.md)
- [DSU Rollback / Offline Dynamic Connectivity](dsu-rollback/README.md)
- [DSU On Tree / Small-To-Large](dsu-on-tree/README.md)
- [Fenwick tree](fenwick-tree/README.md)
- [Binary Trie / XOR Queries](binary-trie-xor/README.md)
- [PBDS / Order Statistics Tree](pbds-order-statistics/README.md)
- [Balanced BSTs For Contests](balanced-bsts/README.md)
- [Splay Tree](splay-tree/README.md)
- [Pairing Heap / Leftist Heap](pairing-leftist-heap/README.md)
- [Persistent data structures](persistent-data-structures/README.md)
- [Persistent Treap](persistent-treap/README.md)
- [Treap / Implicit Treap](treap-implicit/README.md)
- [Wavelet Tree](wavelet-tree/README.md)
- [Mo's algorithm](mos-algorithm/README.md)
- [Segment tree](segment-tree/README.md)
- [Lazy segment tree](lazy-segment-tree/README.md)
- [Segment Tree Beats](segment-tree-beats/README.md)
- [ODT / Chtholly](odt-chtholly/README.md)
- [Sparse table](sparse-table/README.md)
- [Heaps and ordered sets](heaps-and-ordered-sets/README.md)
- [Offline tricks](offline-tricks/README.md)

## Representative Solved Note

- [Dynamic Connectivity](dsu-rollback/dynamicconnectivity.md): exact rollback-DSU route for component counts under add/remove edge events
- [Distinct Colors](dsu-on-tree/distinctcolors.md): exact first small-to-large subtree-container route for one answer per rooted subtree
- [CVP00001](fenwick-tree/cvp00001.md): Fenwick-backed circular simulation with reset/capture logic
- [Range Queries and Copies](persistent-data-structures/rangequeriesandcopies.md): exact first persistent segment-tree route for versioned point updates and old-version range sums
- [Persistent List](persistent-treap/persistentlist.md): exact first persistent split/merge treap route for branching list versions
- [Salary Queries](treap-implicit/salaryqueries.md): exact key-based treap route for duplicate-safe rank differences under online updates
- [Cut and Paste](treap-implicit/cutandpaste.md): exact first sequence-surgery route where split/merge by position replaces explicit index maintenance
- [MKTHNUM - K-th Number](wavelet-tree/mkthnum.md): exact first static order-statistics route where one range is translated through value partitions
- [Powerful Array](mos-algorithm/powerfularray.md): exact first `Mo` route where one current range and one frequency-weighted score are the whole state
- [Vasiliy's Multiset](binary-trie-xor/vasiliysmultiset.md): exact first binary-trie route for live xor-max queries with duplicates
- [ORDERSET - Order Statistic Set](pbds-order-statistics/orderset.md): exact first PBDS route for online rank and `k`-th queries on one changing ordered set
- [Balanced BSTs For Contests](balanced-bsts/README.md): compare-note track for AVL and the other textbook balancing families the repo intentionally does not treat as first-line contest retrieval
- [Ordinary Balanced Tree](splay-tree/ordinarybalancedtree.md): exact first self-adjusting ordered-set route and the direct bridge into link-cut tree machinery
- [Mergeable Heap 1](pairing-leftist-heap/mergeableheap1.md): exact first meldable-heap route where singleton heaps keep unioning and delete-min names one item's current heap
- [HORRIBLE](lazy-segment-tree/horriblequeries.md): exact `range add + range sum` lazy-propagation baseline
- [Range Chmin Chmax Add Range Sum](segment-tree-beats/rangechminchmaxaddrangesum.md): exact canonical verifier for `range chmin / chmax / add / sum`
- [Willem, Chtholly and Seniorious](odt-chtholly/willemchthollyandseniorious.md): exact canonical ODT route where one `std::set` interval partition with `split / assign / walk` matches the whole statement
