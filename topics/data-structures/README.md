# Data Structures

This area covers the reusable tools that turn repeated work into fast queries, updates, or connectivity checks. It is the bridge between basic implementation patterns and serious contest problem solving.

## Subtopics

- [DSU](dsu/README.md)
- [Fenwick Tree](fenwick-tree/README.md)
- [Segment Tree](segment-tree/README.md)
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
- sparse table
- ordered sets and offline query habits

3. Advanced later
- lazy propagation variants
- coordinate compression patterns
- persistent and rollback-style structures

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

## Go Deeper

- Course: [Princeton COS 226](https://www.cs.princeton.edu/~cos226)
- Course: [MIT 6.1210 / 6.1220](https://student.mit.edu/catalog/archive/fall/m6a.html)
- Reference: [USACO Guide](https://usaco.guide/)
- Reference: [KACTL](https://github.com/kth-competitive-programming/kactl)
