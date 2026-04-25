# Range Queries and Copies

- Title: `Range Queries and Copies`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/1737](https://cses.fi/problemset/task/1737)
- Secondary topics: `Persistent segment tree`, `Path copying`, `Versioned queries`
- Difficulty: `hard`
- Subtype: `Point assignments and range sums across many alive versions`
- Status: `solved`
- Solution file: [rangequeriesandcopies.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/persistent-data-structures/rangequeriesandcopies.cpp)

## Why Practice This

This is the cleanest in-repo anchor for the first persistent data-structures lane.

The statement already gives the exact contest signal:

- many array versions exist at the same time
- one operation copies an existing version
- later operations may query or update any chosen version

So the real lesson is not a niche persistent trick.

It is:

- one version is one root
- a point update creates a new root by path copying
- old roots stay valid without rollback

## Recognition Cue

Reach for persistence when:

- old snapshots stay queryable after later updates
- a copy operation produces a new branchable version
- updates are local enough that only one root-to-leaf path changes
- full copying the whole structure would obviously be too slow

The strongest smell here is:

- "copy array `k`, then later modify the copy while the original still matters"

## Problem-Specific Transformation

The statement keeps several arrays alive.

Treat each array version as one persistent segment-tree root:

```text
roots[v] = root node of version v
```

Then:

- query `2 k a b` becomes `range_sum(roots[k], a - 1, b)`
- update `1 k a x` becomes:
  - `roots[k] = point_set(roots[k], a - 1, x)`
- copy `3 k` becomes:
  - `roots.push_back(roots[k])`

So the problem is no longer "store many whole arrays."

It becomes:

- store many roots
- path-copy only the nodes touched by a point assignment

## Core Idea

Build one ordinary segment tree for the initial array.

For a point assignment:

1. clone the current root
2. recurse to the updated leaf
3. clone every node on that path
4. reuse untouched child pointers from the old version
5. pull sums on the copied path only

This creates one new version in `O(log n)` new nodes.

Queries are just ordinary range-sum queries on the chosen version root.

The important invariant is:

```text
no old node is ever mutated after it belongs to a published version root
```

That is why all versions can coexist safely.

## Complexity

For `n` initial elements and `q` operations:

- initial build: `O(n)`
- point assignment: `O(log n)` new nodes
- range sum query: `O(log n)`
- copy version: `O(1)`
- total memory: `O(n + q \log n)`

This comfortably fits CSES.

## Pitfalls / Judge Notes

- Statement versions are one-based; keep your internal `roots` vector indexing consistent.
- Inside the tree, use zero-based half-open intervals `[l, r)`.
- A copy query should not deep-copy nodes.
- Do not mutate a shared node from an old version.
- This first route is `point set + range sum`, not lazy persistence.

## Reusable Pattern

- Topic page: [Persistent Data Structures](../../../../topics/data-structures/persistent-data-structures/README.md)
- Practice ladder: [Persistent Data Structures ladder](README.md)
- Starter template: [persistent-segment-tree-point-set-sum.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/persistent-segment-tree-point-set-sum.cpp)
- Notebook refresher: [Persistent Data Structures hot sheet](../../../../notebook/persistent-data-structures-hot-sheet.md)
- Compare points:
  - [Segment Tree](../../../../topics/data-structures/segment-tree/README.md)
  - [DSU Rollback / Offline Dynamic Connectivity](../../../../topics/data-structures/dsu-rollback/README.md)
- This note adds: the first exact path-copying route where multiple version roots remain alive and queryable.

## Solutions

- Code: [rangequeriesandcopies.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/persistent-data-structures/rangequeriesandcopies.cpp)
