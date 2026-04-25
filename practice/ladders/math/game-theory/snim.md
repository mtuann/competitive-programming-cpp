# S-Nim

- Title: `S-Nim`
- Judge / source: `Kattis`
- Original URL: [https://open.kattis.com/problems/snim](https://open.kattis.com/problems/snim)
- Secondary topics: `Sprague-Grundy`, `Subtraction game`, `Nim sum`
- Difficulty: `medium`
- Subtype: `Precompute Grundy numbers for one move set, then xor heap nimbers`
- Status: `solved`
- Solution file: [snim.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/game-theory/snim.cpp)

## Why Practice This

This is the cleanest in-repo anchor for the `Game Theory / Sprague-Grundy` lane because it forces the exact first route:

- one fixed subtraction move set `S`
- many heaps in one position
- multiple positions to answer

So a plain single-heap win/lose DP is not quite enough.

You want:

1. one Grundy table for heap sizes
2. xor across heaps in each queried position

That is the precise doorway from "subtraction game DP" into "Sprague-Grundy actually matters."

## Recognition Cue

Reach for SG-safe thinking when:

- the game is impartial and normal-play
- every heap follows the same move set `S`
- each move changes exactly one heap
- multiple heaps are present in the final queried position

The strongest smell is:

- "same subtraction rules for each heap, but the answer is on a whole multi-heap position"

That is exactly when xor of Grundy values is the real invariant.

## Problem-Specific Transformation

Let `sg[x]` be the Grundy value of one heap with `x` beads.

Since the legal moves are:

$$
x \to x - s \quad \text{for } s \in S,\ s \le x
$$

the recurrence is:

$$
sg[x] = \operatorname{mex}\{ sg[x-s] \mid s \in S,\ s \le x \}
$$

For one queried position with heap sizes:

$$
h_1, h_2, \dots, h_\ell
$$

compute:

$$
sg[h_1] \oplus sg[h_2] \oplus \dots \oplus sg[h_\ell]
$$

If the xor is `0`, the position is losing. Otherwise it is winning.

So the whole solution becomes:

1. read all positions first
2. find the maximum heap size
3. precompute `sg[0..max_heap]` once
4. xor each position's heap nimbers

## Core Idea

This is a subtraction game on each single heap, and the whole board is the disjoint sum of those heaps.

For one heap:

- terminal heap `0` has `sg[0] = 0`
- every larger heap takes `mex` of the reachable smaller heaps

For one full position:

- xor the heap Grundy values

The invariant is:

```text
the xor after processing the first i heaps already equals the Grundy value
of the sum of those i heaps
```

So the final xor decides the winner directly.

## Complexity

Let:

- `M` = maximum heap size over all positions
- `k` = size of move set `S`
- `H` = total number of heaps across all queried positions

Then:

- SG precompute: `O(M * k)`
- answering all positions: `O(H)`

This is exactly the intended complexity for the Kattis constraints.

## Pitfalls / Judge Notes

- Do not confuse single-heap win/lose with full-position win/lose; the latter uses xor of heap nimbers.
- `mex` is taken over reachable **Grundy values**, not over reachable heap sizes.
- The move set is fixed for all heaps, so precompute once and reuse.
- This is normal play, not misere play.
- If the task were only one heap, a plain winning/losing DP could be enough; the multi-heap sum is why SG is the exact route here.

## Reusable Pattern

- Topic page: [Game Theory / Sprague-Grundy](../../../../topics/math/game-theory/README.md)
- Practice ladder: [Game Theory / Sprague-Grundy ladder](README.md)
- Starter template: [sprague-grundy-subtract-set.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/math/sprague-grundy-subtract-set.cpp)
- Notebook refresher: [Sprague-Grundy hot sheet](../../../../notebook/sprague-grundy-hot-sheet.md)
- Compare points:
  - [CSES Stick Game](https://cses.fi/problemset/task/1729/)
  - [CSES Nim Game II](https://cses.fi/problemset/task/1098/)
  - [Removal Game](../../dp/interval-dp/removalgame.md)
- This note adds: the exact transition from one subtraction-game SG table to xor over many heaps.

## Solutions

- Code: [snim.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/solutions/math/game-theory/snim.cpp)
