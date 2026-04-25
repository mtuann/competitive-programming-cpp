# HORRIBLE - Horrible Queries

- Title: `HORRIBLE - Horrible Queries`
- Judge / source: `SPOJ`
- Original URL: [https://www.spoj.com/problems/HORRIBLE/](https://www.spoj.com/problems/HORRIBLE/)
- Secondary topics: `Range add`, `Range sum`, `Lazy propagation`
- Difficulty: `medium`
- Subtype: `Support range additions and online range-sum queries`
- Status: `solved`
- Solution file: [horriblequeries.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/lazy-segment-tree/horriblequeries.cpp)

## Why Practice This

This is the cleanest in-repo anchor for the first lazy segment tree.

The update and query family matches the starter exactly:

- add one delta to every index in a range
- ask the sum on a range

So the real lesson is not custom tag precedence or weird node states.

It is simply:

- what a lazy tag means
- when full cover can stop early
- when `push` is actually necessary

## Recognition Cue

Reach for a lazy segment tree when:

- range updates and range queries are interleaved online
- a point-update tree would have to touch too many leaves per update
- the same delta is applied to every element in a covered interval
- the aggregate over that interval can be repaired in closed form

The strong smell here is:

- "add `v` to every element in `[p, q]`, then later ask sums on ranges"

That is the textbook `range add + range sum` lazy lane.

## Problem-Specific Transformation

The statement is one-based inclusive, but the reusable internal form is:

- update `[p - 1, q)` by `+v`
- query `[p - 1, q)`

Then define for each segment-tree node:

- `sum[node]` = true sum of the covered interval
- `lazy[node]` = pending additive tag still owed to the children

So the problem becomes:

- keep each covered segment sum correct
- defer child work until a later partial overlap actually needs it

## Core Idea

If a node's segment `[L, R)` is fully covered by `+v`, then every element in that segment changes by the same amount.

So the segment sum changes by:

$$
v \cdot (R - L)
$$

and we can repair the node immediately:

$$
sum[node] \leftarrow sum[node] + v \cdot (R-L)
$$

while storing:

$$
lazy[node] \leftarrow lazy[node] + v
$$

for later children.

That is why the update does **not** need to recurse to every leaf.

For partial overlap:

- `push` the pending tag first
- recurse to the children
- `pull` by recomputing the parent sum from its children

The important invariant is:

```text
the node itself is always correct for its whole segment;
the lazy tag only records that the children are still deferred
```

## Complexity

- build per test case: `O(n)`
- each range add: `O(log n)`
- each range sum: `O(log n)`
- memory: `O(n)`

This is fast enough for SPOJ `HORRIBLE`.

## Pitfalls / Judge Notes

- Use `long long` for both sums and deltas.
- The statement is one-based inclusive; the reusable helper is usually zero-based half-open.
- `push` only before partial descent; full-cover updates should stop immediately.
- Clear both `sum` and `lazy` for each test case.
- This is only `range add + range sum`; do not import assign-tag logic unless the statement really needs it.

## Reusable Pattern

- Topic page: [Lazy Segment Tree](../../../../topics/data-structures/lazy-segment-tree/README.md)
- Practice ladder: [Lazy Segment Tree ladder](README.md)
- Starter template: [segment-tree-lazy-range-add-sum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/segment-tree-lazy-range-add-sum.cpp)
- Notebook refresher: [Lazy Segment Tree hot sheet](../../../../notebook/lazy-segment-tree-hot-sheet.md)
- Compare points: [Segment Tree](../../../../topics/data-structures/segment-tree/README.md), [Range Update Queries](../../foundations/difference-arrays/rangeupdatequeries.md)
- This note adds: the first exact lazy route where full-cover updates are compressed instead of exploded into leaf work.

## Solutions

- Code: [horriblequeries.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/lazy-segment-tree/horriblequeries.cpp)
