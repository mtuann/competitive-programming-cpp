# Data Structures

This area covers the reusable tools that turn repeated work into fast queries, updates, or connectivity checks. It is the bridge between basic implementation patterns and serious contest problem solving.

## Subtopics

- [DSU](dsu/README.md)
- [DSU Rollback / Offline Dynamic Connectivity](dsu-rollback/README.md)
- [Fenwick Tree](fenwick-tree/README.md)
- [Binary Trie / XOR Queries](binary-trie-xor/README.md)
- [Persistent Data Structures](persistent-data-structures/README.md)
- [Wavelet Tree](wavelet-tree/README.md)
- [Mo's Algorithm](mos-algorithm/README.md)
- [Segment Tree](segment-tree/README.md)
- [Lazy Segment Tree](lazy-segment-tree/README.md)
- [Segment Tree Beats](segment-tree-beats/README.md)
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

2. Contest core
- segment tree
- lazy segment tree once point-update trees and difference-array contrasts are comfortable
- segment tree beats once `range chmin / chmax` style updates appear and simple lazy tags stop closing cleanly
- sparse table
- ordered sets and offline query habits
- binary trie once xor-max queries over one live set start appearing

3. Advanced later
- ordinary Mo on static arrays once offline right-endpoint sweeps feel natural
- rollback DSU / offline dynamic connectivity
- persistent structures once ordinary segment-tree updates are automatic
- wavelet tree once static range order statistics or value-count queries start appearing
- lazy propagation variants
- coordinate compression patterns

## Recognition Cues

- the problem asks for many updates and queries on the same array or set
- recomputing from scratch is too slow but the operation structure is repetitive
- connectivity or component merging is changing over time

## Common Pitfalls

- choosing a heavy structure when a lighter one is enough
- using a segment tree without first checking whether Fenwick or sparse table is simpler
- mixing 0-based and 1-based indexing inside reusable templates

## Exit Criteria

After this section, you should know which standard structure to reach for in common query/update problems and be able to implement the core ones quickly in contest conditions.

## Solved Examples In This Repo

- [CVP00001 - Ô ăn quan](../../practice/ladders/data-structures/fenwick-tree/cvp00001.md): Fenwick-backed circular simulation with reset/capture logic
- [Dynamic Connectivity](../../practice/ladders/data-structures/dsu-rollback/dynamicconnectivity.md): edge-lifetime intervals plus rollback DSU over a segment tree of time
- [Range Queries and Copies](../../practice/ladders/data-structures/persistent-data-structures/rangequeriesandcopies.md): versioned arrays where each point update creates a new persistent segment-tree root
- [Powerful Array](../../practice/ladders/data-structures/mos-algorithm/powerfularray.md): the first exact in-repo route for current-range maintenance under Mo ordering
- [Vasiliy's Multiset](../../practice/ladders/data-structures/binary-trie-xor/vasiliysmultiset.md): the first exact in-repo route for insert / erase-one / max-xor over one live multiset
- [HORRIBLE - Horrible Queries](../../practice/ladders/data-structures/lazy-segment-tree/horriblequeries.md): the first exact in-repo route for online `range add + range sum`
- [Range Chmin Chmax Add Range Sum](../../practice/ladders/data-structures/segment-tree-beats/rangechminchmaxaddrangesum.md): the exact verifier-style anchor for the canonical Beats lane

## Go Deeper

- Course: [Princeton COS 226](https://www.cs.princeton.edu/~cos226)
- Course: [MIT 6.1210 / 6.1220](https://student.mit.edu/catalog/archive/fall/m6a.html)
- Reference: [USACO Guide](https://usaco.guide/)
- Reference: [KACTL](https://github.com/kth-competitive-programming/kactl)
