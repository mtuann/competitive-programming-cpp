# Data Structures

<div class="badge-row" markdown>
  <span class="route-badge route-badge--core">Core</span>
</div>

This area is for reusable tools that turn repeated work into fast queries, updates, merges, or ordered-set operations.

## The Main Choice In This Area

Most data-structure mistakes come from reaching for something heavier than the invariant actually needs.

- if the state is just connected components, start with `DSU`
- if the state is prefix-style aggregation, start with `Fenwick Tree`
- if the state needs general segment decomposition, move to `Segment Tree`
- if the real invariant is monotone boundaries or sliding extrema, use `Monotonic Stack / Queue`
- if the real state is one ordered set with rank or predecessor logic, move toward `PBDS`, `treap`, or `splay`

## Use This Area When

- recomputing from scratch is clearly too slow
- the real state is one array, set, component partition, or interval family
- you need to choose between lighter and heavier query/update tools on purpose

## Start With One Route

| If your bottleneck is... | Open first | Then |
| --- | --- | --- |
| connectivity and components | [DSU](dsu/README.md) | [Fenwick Tree](fenwick-tree/README.md) or [Segment Tree](segment-tree/README.md) |
| range sums and point updates | [Fenwick Tree](fenwick-tree/README.md) | [Segment Tree](segment-tree/README.md), then [Lazy Segment Tree](lazy-segment-tree/README.md) |
| monotone scans and sliding extrema | [Monotonic Stack / Queue](monotonic-stack-queue/README.md) | the corresponding ladder and one nearest-boundary anchor |
| rank, `k`-th, or ordered-set surgery | [PBDS / Order Statistics Tree](pbds-order-statistics/README.md) | [Treap / Implicit Treap](treap-implicit/README.md), then [Splay Tree](splay-tree/README.md) if needed |

## Core Progression

1. `Core first`
- DSU
- Fenwick Tree
- Segment Tree
- Monotonic Stack / Queue
- Heaps and Ordered Sets

2. `Then add`
- Lazy Segment Tree / Sparse Table
- PBDS / Order Statistics Tree
- Binary Trie / XOR Queries
- Offline Tricks / Mo's Algorithm

3. `Deep later`
- DSU Rollback / DSU On Tree
- Treap / Persistent Treap / Persistent Data Structures
- Wavelet Tree / Segment Tree Beats / ODT
- Interval Trees / Pairing-Leftist Heap / Splay Tree
- B-Trees / Skip Lists / X-Fast / Y-Fast Tries as textbook breadth

## Good First Repo Anchors

- [CVP00001](../../practice/ladders/data-structures/fenwick-tree/cvp00001.md)
- [Nearest Smaller Values](../../practice/ladders/data-structures/monotonic-stack-queue/nearestsmallervalues.md)
- [ORDERSET](../../practice/ladders/data-structures/pbds-order-statistics/orderset.md)
- [Salary Queries](../../practice/ladders/data-structures/treap-implicit/salaryqueries.md)
- [Powerful Array](../../practice/ladders/data-structures/mos-algorithm/powerfularray.md)
- [Willem, Chtholly and Seniorious](../../practice/ladders/data-structures/odt-chtholly/willemchthollyandseniorious.md)

## Browse All Subtopics

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

## Go Deeper

- Course: [Princeton COS 226](https://www.cs.princeton.edu/~cos226)
- Course: [MIT 6.1210 / 6.1220](https://student.mit.edu/catalog/archive/fall/m6a.html)
- Reference: [USACO Guide](https://usaco.guide/)
- Reference: [KACTL](https://github.com/kth-competitive-programming/kactl)
