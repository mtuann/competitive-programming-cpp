# Dynamic Range Sum Queries

- Title: `Dynamic Range Sum Queries`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1648](https://cses.fi/problemset/task/1648)
- Main topic: `Data Structures -> Segment Tree`
- Secondary topics: `Point update`, `Range sum`, `Iterative segment tree`
- Difficulty: `medium`
- Subtype: `Support point assignments and online range-sum queries`
- Status: `solved`
- Solution file: [dynamicrangesumqueries.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/segment-tree/dynamicrangesumqueries.cpp)

## Why Practice This

This is one of the best first segment-tree problems because the node state is as simple as possible:

- each node stores a segment sum
- updates change one position
- queries ask for a sum on a range

That makes it a clean place to learn the segment-tree invariant before moving on to minimum queries, descent queries, or lazy propagation.

## Key Idea

Store the sum of each segment in a segment tree.

The invariant is:

```text
tree[node] = sum of the array values covered by that node's interval
```

Then:

- a point update changes one leaf
- every ancestor of that leaf is recomputed from its two children
- a range query is answered by merging the sums of the covered segments

In the iterative version, it is convenient to query on a half-open interval `[l, r)`.

So an input query on one-based inclusive `[a, b]` becomes:

```text
query(a - 1, b)
```

after converting to zero-based indexing.

This problem can also be solved with Fenwick, but as a segment-tree ladder anchor it is perfect because the merge is obvious and the implementation pattern is reusable.

## Complexity

- build: `O(n)`
- each point update: `O(log n)`
- each range query: `O(log n)`
- memory: `O(n)`

## Pitfalls / Judge Notes

- The update sets `a[k] = u`; it is not an add operation.
- Use `long long` for node sums.
- Be consistent about interval style inside the tree. This solution uses zero-based half-open queries `[l, r)`.
- Recompute all ancestors after changing one leaf, or later queries will use stale sums.

## Reusable Pattern

- Topic page: [Segment Tree](../../../../topics/data-structures/segment-tree/README.md)
- Practice ladder: [Segment Tree ladder](README.md)
- Starter template: [segment-tree-iterative.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/segment-tree-iterative.cpp)
- Notebook refresher: [Data structures cheatsheet](../../../../notebook/data-structures-cheatsheet.md)
- Carry forward: write the node meaning, merge rule, and interval convention before touching tree indices.
- This note adds: the problem-specific merge payload and query/update semantics on top of the generic tree.

## Solutions

- Code: [dynamicrangesumqueries.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/segment-tree/dynamicrangesumqueries.cpp)
