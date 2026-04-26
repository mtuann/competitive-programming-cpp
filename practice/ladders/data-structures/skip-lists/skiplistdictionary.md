# Skiplist Dictionary

- Title: `Skiplist Dictionary`
- Judge / source: `Canonical skiplist dictionary benchmark`
- Original URL: [https://opendatastructures.org/ods-cpp/4_Skiplists.html](https://opendatastructures.org/ods-cpp/4_Skiplists.html)
- Secondary topics: `Probabilistic balancing`, `Forward-pointer towers`, `Expected logarithmic search`
- Difficulty: `medium`
- Subtype: `Skiplist ordered-set search / insert / erase`
- Status: `solved`
- Solution file: [skiplistdictionary.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/skip-lists/skiplistdictionary.cpp)

## Why Practice This

This is the cleanest first in-repo flagship for `Skip Lists`.

The benchmark is intentionally canonical:

- `+ x` inserts
- `- x` erases one key if present
- `? x` tests membership

So the hard part is exactly the lane itself:

- tower search
- random height
- splicing through `update[]`

## Recognition Cue

Reach for the skiplist worldview when:

- the real lesson is probabilistic ordered-dictionary balancing
- you want the forward-pointer tower model itself
- you are covering textbook breadth beyond trees

The strongest smell here is:

- "I want a canonical skiplist insert/search/delete benchmark"

That is exactly this lane.

## Problem-Specific Route

This benchmark does **not** want:

- PBDS, because the lesson is not GNU order-statistics retrieval
- treap, because split/merge is not the point
- AVL / Red-Black, because deterministic tree rotations are not the point

The clean route is:

1. search top-down through levels
2. record predecessors in `update[]`
3. choose a random height for the new node
4. splice the tower into each owned level
5. erase by bypassing the matching node on every owned level

That is exactly the first skiplist route.

## Core Idea

The useful monotone fact is:

- the predecessor path found during search is exactly the path you need to splice or bypass one node during insert/delete

So one update does not rebalance one tree.
It only rewires a small tower across several sorted forward lists.

That is the whole skiplist lesson.

## Complexity

- search: expected `O(log n)`
- insert: expected `O(log n)`
- erase-one: expected `O(log n)`
- space: expected `O(n)`

The key word is **expected**.
That is part of what this lane is teaching.

## Input / Output Contract For This Repo

This repo's canonical benchmark uses:

- one integer `q`
- then `q` lines, each either:
  - `+ x` -> insert `x`
  - `- x` -> erase `x` if present
  - `? x` -> print whether `x` exists

The solution prints:

- one line per query `? x`
- `1` if present, else `0`

Duplicate inserts are ignored.

## Pitfalls / Judge Notes

- Skiplist performance is expected-time, not deterministic balancing.
- `update[]` must store the last node before the target on every level.
- This benchmark is intentionally simpler than indexable skiplist variants.
- If your real contest task is only one dynamic ordered set, PBDS is usually the cleaner route.

## Reusable Pattern

- Topic page: [Skip Lists](../../../../topics/data-structures/skip-lists/README.md)
- Practice ladder: [Skip Lists ladder](README.md)
- Starter template: [skiplist-ordered-set.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/skiplist-ordered-set.cpp)
- Notebook refresher: [Skiplist hot sheet](../../../../notebook/skiplist-hot-sheet.md)
- Compare points:
  - [PBDS / Order Statistics Tree](../../../../topics/data-structures/pbds-order-statistics/README.md)
  - [Treap / Implicit Treap](../../../../topics/data-structures/treap-implicit/README.md)
  - [B-Trees](../../../../topics/data-structures/b-trees/README.md)
- This note adds: the canonical probabilistic ordered-dictionary route before indexable skiplist variants.

## Solutions

- Code: [skiplistdictionary.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/skip-lists/skiplistdictionary.cpp)
