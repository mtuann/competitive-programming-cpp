# B-Tree Dictionary

- Title: `B-Tree Dictionary`
- Judge / source: `Canonical B-tree dictionary benchmark`
- Original URL: [https://opendatastructures.org/ods-cpp/14_2_B_Trees.html](https://opendatastructures.org/ods-cpp/14_2_B_Trees.html)
- Secondary topics: `Multiway search tree`, `Split full child`, `High fanout`
- Difficulty: `medium`
- Subtype: `B-tree search and insert`
- Status: `solved`
- Solution file: [btreedictionary.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/b-trees/btreedictionary.cpp)

## Why Practice This

This is the cleanest first in-repo flagship for `B-Trees`.

The benchmark is intentionally canonical instead of judge-idiosyncratic:

- `+ x` inserts one key
- `? x` asks whether `x` exists

So the hard part is exactly the lane itself:

- search inside one multiway node
- split full root
- split full child before descent

## Recognition Cue

Reach for the B-tree worldview when:

- the real lesson is one high-fanout search tree
- page-like nodes and separator keys are the point
- you want a classical ordered dictionary breadth lane from CLRS / ODS

The strongest smell here is:

- "I want a canonical B-tree insert/search benchmark"

That is exactly this lane.

## Problem-Specific Route

This benchmark does **not** want:

- PBDS, because the structure lesson is not rank / `k`-th retrieval
- treap, because split/merge is not the point
- Red-Black or AVL, because the point is not binary local balancing

The clean route is:

1. store sorted keys in each node
2. search by scanning the current node and choosing one child interval
3. on insert, split the root first if full
4. before descending into a child, split it if full
5. finally insert into one non-full leaf

That is exactly the first B-tree route.

## Core Idea

The useful monotone fact is:

- if you never descend into a full child, then insertion never needs to repair upward on the way back

So the whole implementation becomes top-down.

That means the key invariant is not:

- height difference
- color
- or subtree size

It is:

- child capacity before descent

That is the whole B-tree lesson.

## Complexity

For minimum degree `t`:

- search: `O(t log_t n)`
- insert: `O(t log_t n)`
- height: `O(log_t n)`

The in-memory constant factors are not the point here.
The learning signal is:

- high fanout
- fewer levels
- split-based balancing

## Input / Output Contract For This Repo

This repo's canonical benchmark uses:

- one integer `q`
- then `q` lines, each either:
  - `+ x` -> insert `x`
  - `? x` -> print whether `x` exists

The solution prints:

- one line per query `? x`
- `1` if present, else `0`

Duplicate inserts are ignored.

## Pitfalls / Judge Notes

- B-tree insertion is easiest when you split full children **before** descending.
- This repo starter is about the structural lesson, not about disk buffering code.
- This benchmark is intentionally simpler than full database-style B-tree work.
- If your real contest task is only one ordered set, a simpler route like PBDS is usually better.

## Reusable Pattern

- Topic page: [B-Trees](../../../../topics/data-structures/b-trees/README.md)
- Practice ladder: [B-Trees ladder](README.md)
- Starter template: [b-tree-insert-search.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/b-tree-insert-search.cpp)
- Notebook refresher: [B-Tree hot sheet](../../../../notebook/b-tree-hot-sheet.md)
- Compare points:
  - [Balanced BSTs For Contests](../../../../topics/data-structures/balanced-bsts/README.md)
  - [PBDS / Order Statistics Tree](../../../../topics/data-structures/pbds-order-statistics/README.md)
  - [Treap / Implicit Treap](../../../../topics/data-structures/treap-implicit/README.md)
- This note adds: the canonical high-fanout search-tree route before deletion or B+ tree variants.

## Solutions

- Code: [btreedictionary.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/b-trees/btreedictionary.cpp)
