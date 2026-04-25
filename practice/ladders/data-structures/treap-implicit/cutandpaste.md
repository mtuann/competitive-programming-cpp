# CUTANDPASTE - Cut and Paste

- Title: `Cut and Paste`
- Judge / source: `CSES`
- Original URL: [https://cses.fi/problemset/task/2072](https://cses.fi/problemset/task/2072)
- Secondary topics: `Implicit treap`, `Split/merge sequence surgery`, `Subtree size as position`
- Difficulty: `hard`
- Subtype: `Cut a substring and paste it to the end many times`
- Status: `solved`
- Solution file: [cutandpaste.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/treap-implicit/cutandpaste.cpp)

## Why Practice This

This is the cleanest in-repo anchor for the first implicit-treap lane.

The statement gives exactly the right signal:

- the sequence is mutable
- positions keep changing after every operation
- each operation is structural, not just arithmetic on a fixed index line

So the real lesson is:

- represent the sequence as one treap
- split by position, not by explicit key
- rearrange pieces with merges

## Recognition Cue

Reach for an implicit treap when:

- sequence edits shift many later positions
- you need insert / erase / cut / paste by current position
- storing explicit indices would force too many updates
- the natural operation is "first `k` elements vs the rest"

The strongest smell here is:

- "cut positions `a..b`, then paste that block somewhere else"

## Problem-Specific Transformation

Treat the current string as one implicit treap whose in-order traversal is the current character order.

For one operation `(a, b)` from the statement:

- convert to zero-based half-open interval `[a - 1, b)`
- split into three pieces:
  - prefix `[0, a - 1)`
  - middle `[a - 1, b)`
  - suffix `[b, n)`

Then rebuild in the order:

```text
prefix + suffix + middle
```

So the statement is no longer:

- shift characters inside one array or string

It becomes:

- two splits
- two merges

on one implicit treap.

## Core Idea

Each node stores:

- one character
- one random priority
- subtree size

The subtree size is what gives implicit position.

If `split(root, k)` returns:

- left = first `k` characters
- right = the rest

then `Cut and Paste` is just:

```text
(a, bc) = split(root, l)
(b, c) = split(bc, r - l)
root = merge(merge(a, c), b)
```

The important invariant is:

```text
the in-order traversal of the treap is always the current string
```

So after each split/merge sequence, the structure changes shape but the represented string remains exactly what the operation intends.

## Complexity

Let `n` be the initial string length and `m` the number of operations.

- build: `O(n log n)` in the straightforward starter-style construction
- each cut/paste operation: expected `O(log n)`
- final output traversal: `O(n)`
- memory: `O(n)`

This comfortably fits the CSES limits.

## Pitfalls / Judge Notes

- The statement uses one-based inclusive intervals.
- Keep internal split positions zero-based.
- `split(root, k)` means first `k` elements vs the rest, not "up to index `k` inclusive".
- Do not try to update explicit character indices after every operation.
- The answer is the final in-order traversal after all operations, not intermediate outputs.

## Reusable Pattern

- Topic page: [Treap / Implicit Treap](../../../../topics/data-structures/treap-implicit/README.md)
- Practice ladder: [Treap / Implicit Treap ladder](README.md)
- Starter template: [implicit-treap-sequence.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/implicit-treap-sequence.cpp)
- Notebook refresher: [Treap / Implicit Treap hot sheet](../../../../notebook/treap-hot-sheet.md)
- Compare points:
  - [Heaps And Ordered Sets](../../../../topics/data-structures/heaps-and-ordered-sets/README.md)
  - [Lazy Segment Tree](../../../../topics/data-structures/lazy-segment-tree/README.md)
- This note adds: the first exact sequence-surgery route where position is implicit and split/merge does the whole structural job.

## Solutions

- Code: [cutandpaste.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/treap-implicit/cutandpaste.cpp)
