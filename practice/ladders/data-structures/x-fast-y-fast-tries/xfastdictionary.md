# X-Fast Dictionary

- Title: `X-Fast Dictionary`
- Judge / source: `Canonical x-fast predecessor benchmark`
- Original URL: [https://opendatastructures.org/newhtml/ods/latex/integers.html](https://opendatastructures.org/newhtml/ods/latex/integers.html)
- Secondary topics: `Prefix hashing`, `Leaf-linked order`, `Predecessor / successor`, `Bounded universe`
- Difficulty: `hard`
- Subtype: `X-fast trie ordered set`
- Status: `solved`
- Solution file: [xfastdictionary.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/x-fast-y-fast-tries/xfastdictionary.cpp)

## Why Practice This

This is the cleanest first in-repo flagship for `X-Fast / Y-Fast Tries`.

The benchmark is intentionally canonical:

- `+ x` inserts
- `- x` erases one key if present
- `? x` tests membership
- `< x` asks for strict predecessor
- `> x` asks for strict successor

So the hard part is exactly the lane itself:

- prefix tables by depth
- leaf linked list
- jump-based predecessor / successor finishing

## Recognition Cue

Reach for the x-fast worldview when:

- the keys are bounded integers from one fixed universe
- predecessor / successor is the real query target
- you want the Willard / ODS family itself, not one ordinary contest ordered set

The strongest smell here is:

- "I want a canonical x-fast insert/search/predecessor/successor benchmark"

That is exactly this lane.

## Problem-Specific Route

This benchmark does **not** want:

- PBDS, because the lesson is not online rank / `k`-th retrieval
- binary xor trie, because xor greediness is not the objective
- skip lists, because probabilistic balancing is not the point

The clean route is:

1. store every existing prefix in one hash table for its depth
2. keep all leaves linked in sorted order
3. binary-search the deepest existing prefix of the query key
4. use the missing next branch plus the jump/leaf order to finish predecessor or successor
5. on updates, add or remove one full prefix chain

That is exactly the first x-fast route.

## Core Idea

The useful monotone fact is:

- if a prefix of length `d` is missing, then no longer prefix below it can exist

That is what makes binary search on depth legal.

Then the leaf list supplies what the prefix search still does not know:

- the nearest stored key immediately before or after the missing gap

That is the whole x-fast lesson.

## Complexity

For fixed bit width `w`:

- membership / predecessor / successor: `O(log w)`
- insert / erase: `O(w)`
- space: `O(nw)`

The point of this benchmark is not that x-fast beats PBDS in everyday contest code.
The point is:

- bounded-universe ordered sets
- prefix hashing
- leaf-order repair

## Input / Output Contract For This Repo

This repo's canonical benchmark uses:

- one integer `q`
- then `q` lines, each either:
  - `+ x` -> insert `x`
  - `- x` -> erase `x` if present
  - `? x` -> print whether `x` exists
  - `< x` -> print the largest stored key strictly smaller than `x`, else `-1`
  - `> x` -> print the smallest stored key strictly larger than `x`, else `-1`

The solution prints:

- one line per query `?`, `<`, or `>`

The starter and solution assume:

- `0 <= x < 2^31`

Duplicate inserts are ignored.

## Pitfalls / Judge Notes

- x-fast only makes sense because the universe width is fixed in advance.
- Prefix tables alone are not enough; the leaf linked order still matters.
- This benchmark is intentionally narrower than a y-fast implementation.
- If your real contest task is only one dynamic ordered set, PBDS is usually the cleaner route.

## Reusable Pattern

- Topic page: [X-Fast / Y-Fast Tries](../../../../topics/data-structures/x-fast-y-fast-tries/README.md)
- Practice ladder: [X-Fast / Y-Fast Tries ladder](README.md)
- Starter template: [x-fast-trie.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/data-structures/x-fast-trie.cpp)
- Notebook refresher: [X-Fast / Y-Fast hot sheet](../../../../notebook/x-fast-y-fast-hot-sheet.md)
- Compare points:
  - [Binary Trie / XOR Queries](../../../../topics/data-structures/binary-trie-xor/README.md)
  - [PBDS / Order Statistics Tree](../../../../topics/data-structures/pbds-order-statistics/README.md)
  - [Skip Lists](../../../../topics/data-structures/skip-lists/README.md)
- This note adds: the canonical bounded-universe predecessor / successor route before y-fast bucket sampling.

## Solutions

- Code: [xfastdictionary.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/data-structures/x-fast-y-fast-tries/xfastdictionary.cpp)
