# Data Structures

This area covers the reusable tools that turn repeated work into fast queries, updates, or connectivity checks. It is the bridge between basic implementation patterns and serious contest problem solving.

## Subtopics

- [DSU](dsu/README.md)
- [DSU Rollback / Offline Dynamic Connectivity](dsu-rollback/README.md)
- [DSU On Tree / Small-To-Large](dsu-on-tree/README.md)
- [Fenwick Tree](fenwick-tree/README.md)
- [Monotonic Stack / Queue](monotonic-stack-queue/README.md)
- [Binary Trie / XOR Queries](binary-trie-xor/README.md)
- [PBDS / Order Statistics Tree](pbds-order-statistics/README.md)
- [Balanced BSTs For Contests](balanced-bsts/README.md)
- [B-Trees](b-trees/README.md)
- [Skip Lists](skip-lists/README.md)
- [X-Fast / Y-Fast Tries](x-fast-y-fast-tries/README.md)
- [Interval Trees](interval-trees/README.md)
- [Splay Tree](splay-tree/README.md)
- [Pairing Heap / Leftist Heap](pairing-leftist-heap/README.md)
- [Persistent Data Structures](persistent-data-structures/README.md)
- [Persistent Treap](persistent-treap/README.md)
- [Treap / Implicit Treap](treap-implicit/README.md)
- [Wavelet Tree](wavelet-tree/README.md)
- [Mo's Algorithm](mos-algorithm/README.md)
- [Segment Tree](segment-tree/README.md)
- [Lazy Segment Tree](lazy-segment-tree/README.md)
- [Segment Tree Beats](segment-tree-beats/README.md)
- [ODT / Chtholly](odt-chtholly/README.md)
- [Sparse Table](sparse-table/README.md)
- [Heaps And Ordered Sets](heaps-and-ordered-sets/README.md)
- [Offline Tricks](offline-tricks/README.md)

## Entry

- Prereqs: [Foundations](../foundations/README.md)
- Defer for later: flow, matching, and advanced tree techniques

## Learn In Order

1. Core now
- heaps and priority queues
- DSU for connectivity and component maintenance
- Fenwick tree for simple prefix/range aggregation
- monotonic stack / queue for nearest-boundary and sliding-window extrema scans

2. Contest core
- segment tree
- lazy segment tree once point-update trees and difference-array contrasts are comfortable
- segment tree beats once `range chmin / chmax` style updates appear and simple lazy tags stop closing cleanly
- sparse table
- ordered sets and offline query habits
- PBDS / order-statistics trees once rank or `k`-th is the real invariant and plain ordered-set logic stops being enough
- balanced BST compare note once you want to understand where AVL / Red-Black / Scapegoat / SBT fit and why the repo still prefers PBDS / treap for most contest jobs
- skip lists once you explicitly want the probabilistic ordered-dictionary breadth story rather than one contest-first route
- x-fast / y-fast tries once the real parameter is one bounded integer universe and predecessor / successor is the whole lesson
- interval trees once the real state is one live set of intervals and overlap, not one aggregate over a fixed line
- splay tree once you explicitly want the self-adjusting ordered-set route or the direct bridge into link-cut tree
- pairing / leftist heaps once ordinary `priority_queue` logic is right except heaps must also meld
- binary trie once xor-max queries over one live set start appearing

3. Advanced later
- ordinary Mo on static arrays once offline right-endpoint sweeps feel natural
- rollback DSU / offline dynamic connectivity
- DSU on tree / small-to-large once subtree containers become the real invariant
- persistent structures once ordinary segment-tree updates are automatic
- treap / implicit treap once mutable sequence edits or split/merge by position start appearing
- persistent treap once both persistence and split/merge sequence surgery have become real signals at the same time
- wavelet tree once static range order statistics or value-count queries start appearing
- B-trees once you explicitly want the textbook high-fanout search-tree story instead of the repo's contest-first ordered-set routes
- skip lists once you want the textbook probabilistic ordered-dictionary route outside BST balancing
- x-fast / y-fast tries once you want bounded-universe predecessor structures and are willing to pay textbook-breadth complexity
- ODT / Chtholly once range assigns keep collapsing equal-value runs and the true state is one interval partition rather than one worst-case range tree
- lazy propagation variants
- coordinate compression patterns

## Recognition Cues

- the problem asks for many updates and queries on the same array or set
- recomputing from scratch is too slow but the operation structure is repetitive
- connectivity or component merging is changing over time
- the real state is one monotone active frontier or one sliding window rather than arbitrary online updates

## Common Pitfalls

- choosing a heavy structure when a lighter one is enough
- using a segment tree without first checking whether Fenwick or sparse table is simpler
- mixing 0-based and 1-based indexing inside reusable templates

## Exit Criteria

After this section, you should know which standard structure to reach for in common query/update problems and be able to implement the core ones quickly in contest conditions.

## Solved Examples In This Repo

- [CVP00001 - Ô ăn quan](../../practice/ladders/data-structures/fenwick-tree/cvp00001.md): Fenwick-backed circular simulation with reset/capture logic
- [Dynamic Connectivity](../../practice/ladders/data-structures/dsu-rollback/dynamicconnectivity.md): edge-lifetime intervals plus rollback DSU over a segment tree of time
- [Distinct Colors](../../practice/ladders/data-structures/dsu-on-tree/distinctcolors.md): exact small-to-large subtree container merging for one answer per node
- [Range Queries and Copies](../../practice/ladders/data-structures/persistent-data-structures/rangequeriesandcopies.md): versioned arrays where each point update creates a new persistent segment-tree root
- [Persistent List](../../practice/ladders/data-structures/persistent-treap/persistentlist.md): persistent split/merge list route where `merge / head / tail` create new treap roots without mutating old ones
- [Salary Queries](../../practice/ladders/data-structures/treap-implicit/salaryqueries.md): key-based treap route where one duplicate-safe ordered set answers dynamic range-count queries
- [Powerful Array](../../practice/ladders/data-structures/mos-algorithm/powerfularray.md): the first exact in-repo route for current-range maintenance under Mo ordering
- [Vasiliy's Multiset](../../practice/ladders/data-structures/binary-trie-xor/vasiliysmultiset.md): the first exact in-repo route for insert / erase-one / max-xor over one live multiset
- [ORDERSET - Order Statistic Set](../../practice/ladders/data-structures/pbds-order-statistics/orderset.md): the first exact in-repo route for online `k`-th and rank queries on one dynamic ordered set
- [B-Tree Dictionary](../../practice/ladders/data-structures/b-trees/btreedictionary.md): the first exact in-repo route for high-fanout ordered-dictionary search and insert through split-full-child
- [Skiplist Dictionary](../../practice/ladders/data-structures/skip-lists/skiplistdictionary.md): the first exact in-repo route for probabilistic ordered-dictionary search / insert / erase through forward-pointer towers
- [X-Fast Dictionary](../../practice/ladders/data-structures/x-fast-y-fast-tries/xfastdictionary.md): the first exact in-repo route for bounded-universe predecessor / successor through prefix hashing and leaf-linked order
- [Reservation System](../../practice/ladders/data-structures/interval-trees/reservationsystem.md): the first exact in-repo route for dynamic half-open interval overlap queries through subtree `max_r` augmentation
- [Ordinary Balanced Tree](../../practice/ladders/data-structures/splay-tree/ordinarybalancedtree.md): the first exact in-repo route for a self-adjusting ordered multiset and the direct bridge into splay-based dynamic trees
- [Mergeable Heap 1](../../practice/ladders/data-structures/pairing-leftist-heap/mergeableheap1.md): the first exact in-repo route for meldable singleton heaps with online delete-min by heap owner
- [HORRIBLE - Horrible Queries](../../practice/ladders/data-structures/lazy-segment-tree/horriblequeries.md): the first exact in-repo route for online `range add + range sum`
- [Range Chmin Chmax Add Range Sum](../../practice/ladders/data-structures/segment-tree-beats/rangechminchmaxaddrangesum.md): the exact verifier-style anchor for the canonical Beats lane
- [Willem, Chtholly and Seniorious](../../practice/ladders/data-structures/odt-chtholly/willemchthollyandseniorious.md): the canonical interval-partition route where `split / assign / walk` survives because assign keeps collapsing runs and the data is soft

## Go Deeper

- Course: [Princeton COS 226](https://www.cs.princeton.edu/~cos226)
- Course: [MIT 6.1210 / 6.1220](https://student.mit.edu/catalog/archive/fall/m6a.html)
- Reference: [USACO Guide](https://usaco.guide/)
- Reference: [KACTL](https://github.com/kth-competitive-programming/kactl)
